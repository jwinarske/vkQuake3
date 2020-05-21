/*
===========================================================================
Copyright (C) 1999-2005 Id Software, Inc.

This file is part of Quake III Arena source code.

Quake III Arena source code is free software; you can redistribute it
and/or modify it under the terms of the GNU General Public License as
published by the Free Software Foundation; either version 2 of the License,
or (at your option) any later version.

Quake III Arena source code is distributed in the hope that it will be
useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Quake III Arena source code; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
===========================================================================
*/

#ifdef USE_LOCAL_HEADERS
#	include "../SDL2/include/SDL.h"
#else
#	include <SDL.h>
#endif

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "../client/client.h"
#include "../sys/sys_local.h"

#include "inputHandler.h"

static cvar_t *in_keyboardDebug     = NULL;

static qboolean mouseAvailable = qfalse;
static qboolean mouseActive = qfalse;

static cvar_t *in_mouse             = NULL;
static cvar_t *in_nograb;

static cvar_t *in_joystick          = NULL;
static cvar_t *in_joystickThreshold = NULL;
static cvar_t *in_joystickNo        = NULL;
static cvar_t *in_joystickUseAnalog = NULL;

static int vidRestartTime = 0;

static int in_eventTime = 0;

#define CTRL(a) ((a)-'a'+1)

/*
===============
IN_PrintKey
===============
*/
static void IN_PrintKey( uint32_t button, keyNum_t key, qboolean down )
{
	if( down )
		Com_Printf( "+ " );
	else
		Com_Printf( "  " );

//	Com_Printf( "Scancode: 0x%02x(%s) Sym: 0x%02x(%s)",
//			keysym->scancode, SDL_GetScancodeName( keysym->scancode ),
//			keysym->sym, SDL_GetKeyName( keysym->sym ) );

//	if( keysym->mod & KMOD_LSHIFT )   Com_Printf( " KMOD_LSHIFT" );
//	if( keysym->mod & KMOD_RSHIFT )   Com_Printf( " KMOD_RSHIFT" );
//	if( keysym->mod & KMOD_LCTRL )    Com_Printf( " KMOD_LCTRL" );
//	if( keysym->mod & KMOD_RCTRL )    Com_Printf( " KMOD_RCTRL" );
//	if( keysym->mod & KMOD_LALT )     Com_Printf( " KMOD_LALT" );
//	if( keysym->mod & KMOD_RALT )     Com_Printf( " KMOD_RALT" );
//	if( keysym->mod & KMOD_LGUI )     Com_Printf( " KMOD_LGUI" );
//	if( keysym->mod & KMOD_RGUI )     Com_Printf( " KMOD_RGUI" );
//	if( keysym->mod & KMOD_NUM )      Com_Printf( " KMOD_NUM" );
//	if( keysym->mod & KMOD_CAPS )     Com_Printf( " KMOD_CAPS" );
//	if( keysym->mod & KMOD_MODE )     Com_Printf( " KMOD_MODE" );
//	if( keysym->mod & KMOD_RESERVED ) Com_Printf( " KMOD_RESERVED" );

	Com_Printf( " Q:0x%02x(%s)\n", key, Key_KeynumToString( key ) );
}

#define MAX_CONSOLE_KEYS 16

/*
===============
IN_IsConsoleKey

TODO: If the SDL_Scancode situation improves, use it instead of
      both of these methods
===============
*/
static qboolean IN_IsConsoleKey( keyNum_t key, int character )
{
	typedef struct consoleKey_s
	{
		enum
		{
			QUAKE_KEY,
			CHARACTER
		} type;

		union
		{
			keyNum_t key;
			int character;
		} u;
	} consoleKey_t;

	static consoleKey_t consoleKeys[ MAX_CONSOLE_KEYS ];
	static int numConsoleKeys = 0;
	int i;

	// Only parse the variable when it changes
	if( cl_consoleKeys->modified )
	{
		char *text_p, *token;

		cl_consoleKeys->modified = qfalse;
		text_p = cl_consoleKeys->string;
		numConsoleKeys = 0;

		while( numConsoleKeys < MAX_CONSOLE_KEYS )
		{
			consoleKey_t *c = &consoleKeys[ numConsoleKeys ];
			int charCode = 0;

			token = COM_Parse( &text_p );
			if( !token[ 0 ] )
				break;

			charCode = Com_HexStrToInt( token );

			if( charCode > 0 )
			{
				c->type = CHARACTER;
				c->u.character = charCode;
			}
			else
			{
				c->type = QUAKE_KEY;
				c->u.key = Key_StringToKeynum( token );

				// 0 isn't a key
				if( c->u.key <= 0 )
					continue;
			}

			numConsoleKeys++;
		}
	}

	// If the character is the same as the key, prefer the character
	if( key == character )
		key = 0;

	for( i = 0; i < numConsoleKeys; i++ )
	{
		consoleKey_t *c = &consoleKeys[ i ];

		switch( c->type )
		{
			case QUAKE_KEY:
				if( key && c->u.key == key )
					return qtrue;
				break;

			case CHARACTER:
				if( c->u.character == character )
					return qtrue;
				break;
		}
	}

	return qfalse;
}

/*
===============
IN_TranslateSDLToQ3Key
===============
*/
static keyNum_t IN_TranslateSDLToQ3Key( uint32_t button, qboolean down )
{
	keyNum_t key = 0;

	if(button >= 2 && button <= 11)
	{
		if( button == 11 )
			key = '0';
		else
			key = '1' + (button - 2);
	}
	else if( (button >= 16 && button <= 25) ||
			 (button >= 30 && button <= 38) ||
			 (button >= 44 && button <= 50)
			 )
	{
		switch(button)
		{
			case 16: key = 'q'; break;
			case 17: key = 'w'; break;
			case 18: key = 'e'; break;
			case 19: key = 'r'; break;
			case 20: key = 't'; break;
			case 21: key = 'y'; break;
			case 22: key = 'u'; break;
			case 23: key = 'i'; break;
			case 24: key = 'o'; break;
			case 25: key = 'p'; break;

			case 30: key = 'a'; break;
			case 31: key = 's'; break;
			case 32: key = 'd'; break;
			case 33: key = 'f'; break;
			case 34: key = 'g'; break;
			case 35: key = 'h'; break;
			case 36: key = 'j'; break;
			case 37: key = 'k'; break;
			case 38: key = 'l'; break;

			case 44: key = 'z'; break;
			case 45: key = 'x'; break;
			case 46: key = 'c'; break;
			case 47: key = 'v'; break;
			case 48: key = 'b'; break;
			case 49: key = 'n'; break;
			case 50: key = 'm'; break;
		}
	}
	else
	{
		switch(button)
		{
			case 1: key = K_ESCAPE; break;
			case 59: key = K_F1; break;
			case 60: key = K_F2; break;
			case 61: key = K_F3; break;
			case 62: key = K_F4; break;
			case 63: key = K_F5; break;
			case 64: key = K_F6; break;
			case 65: key = K_F7; break;
			case 66: key = K_F8; break;
			case 67: key = K_F9; break;
			case 68: key = K_F10; break;
			case 87: key = K_F11; break;
			case 88: key = K_F12; break;
			case 99: key = K_PRINT; break;
			case 69: key = K_KP_NUMLOCK; break;
			case 119: key = K_BREAK; break;
			case 111: key = K_DEL; break;
			case 41: key = K_CONSOLE; break; //`
			case 12: key = K_KP_MINUS; break;
			case 13: key = K_KP_EQUALS; break;
			case 14: key = K_BACKSPACE; break;
			case 15: key = K_TAB; break;
			//case 26: key = //[
			//case 27: key = //]
			case 58: key = K_CAPSLOCK; break;
			//case 39: key = //;
			//case 40: key = //'
			//case 43: key = //\\
			case 42: key = K_SHIFT; break;
			//case 86: key = //<
			//case 51: key = //,
			//case 52: key = //.
			case 53: key = K_KP_SLASH; break;
			case 54: key = K_SHIFT; break;
			case 28: key = K_ENTER; break;
			case 29: key = K_CTRL; break;
			case 125: key = K_SUPER; break;
			case 56: key = K_ALT; break;
			case 57: key = ' '; break;
			case 100: key = K_ALT; break;
			//case 127: key = K_SHIFT; break; //context menu
			case 97: key = K_CTRL; break;
			case 110: key = K_INS; break;
			case 102: key = K_HOME; break;
			case 104: key = K_PGUP; break;
			case 109: key = K_PGDN; break;
			case 107: key = K_END; break;
			case 103: key = K_UPARROW; break;
			case 108: key = K_DOWNARROW; break;
			case 105: key = K_LEFTARROW; break;
			case 106: key = K_RIGHTARROW; break;
			default:
				if( button <= 95 )
				{
					// Map Unicode characters to 95 world keys using the key's scan code.
					// FIXME: There aren't enough world keys to cover all the scancodes.
					// Maybe create a map of scancode to quake key at start up and on
					// key map change; allocate world key numbers as needed similar
					// to SDL 1.2.
					key = K_WORLD_0 + button;
				}
				break;
		}
	}

	if( in_keyboardDebug->integer )
		IN_PrintKey( button, key, down );

	if( IN_IsConsoleKey( key, 0 ) )
	{
		// Console keys can't be bound or generate characters
		key = K_CONSOLE;
	}

	return key;
}

/*
===============
IN_GobbleMotionEvents
===============
*/
static void IN_GobbleMotionEvents( void )
{
	//SDL_Event dummy[ 1 ];
	int val = 0;

	// Gobble any mouse motion events
//	SDL_PumpEvents( );
//	while( ( val = SDL_PeepEvents( dummy, 1, SDL_GETEVENT,
//		SDL_MOUSEMOTION, SDL_MOUSEMOTION ) ) > 0 ) { }

	if ( val < 0 )
		Com_Printf( "IN_GobbleMotionEvents failed: %s\n", SDL_GetError( ) );
}

/*
===============
IN_ActivateMouse
===============
*/
static void IN_ActivateMouse( qboolean isFullscreen )
{
	//if (!mouseAvailable || !SDL_WasInit( SDL_INIT_VIDEO ) )
//		return;

	if( !mouseActive )
	{
		//SDL_SetRelativeMouseMode( SDL_TRUE );
		//SDL_SetWindowGrab( SDL_window, SDL_TRUE );

		IN_GobbleMotionEvents( );
	}

	// in_nograb makes no sense in fullscreen mode
	if( !isFullscreen )
	{
		if( in_nograb->modified || !mouseActive )
		{
			if( in_nograb->integer ) {
				//SDL_SetRelativeMouseMode( SDL_FALSE );
				//SDL_SetWindowGrab( SDL_window, SDL_FALSE );
			} else {
				//SDL_SetRelativeMouseMode( SDL_TRUE );
				//SDL_SetWindowGrab( SDL_window, SDL_TRUE );
			}

			in_nograb->modified = qfalse;
		}
	}

	mouseActive = qtrue;
}

/*
===============
IN_DeactivateMouse
===============
*/
static void IN_DeactivateMouse( qboolean isFullscreen )
{
	//if( !SDL_WasInit( SDL_INIT_VIDEO ) )
	//	return;

	// Always show the cursor when the mouse is disabled,
	// but not when fullscreen
	if( !isFullscreen )
		;//SDL_ShowCursor( SDL_TRUE );

	if( !mouseAvailable )
		return;

	if( mouseActive )
	{
		IN_GobbleMotionEvents( );

		//SDL_SetWindowGrab( SDL_window, SDL_FALSE );
		//SDL_SetRelativeMouseMode( SDL_FALSE );

		// Don't warp the mouse unless the cursor is within the window
		//if( SDL_GetWindowFlags( SDL_window ) & SDL_WINDOW_MOUSE_FOCUS )
		//	SDL_WarpMouseInWindow( SDL_window, cls.glconfig.vidWidth / 2, cls.glconfig.vidHeight / 2 );

		mouseActive = qfalse;
	}
}

// We translate axes movement into keypresses
static int joy_keys[16] = {
	K_LEFTARROW, K_RIGHTARROW,
	K_UPARROW, K_DOWNARROW,
	K_JOY17, K_JOY18,
	K_JOY19, K_JOY20,
	K_JOY21, K_JOY22,
	K_JOY23, K_JOY24,
	K_JOY25, K_JOY26,
	K_JOY27, K_JOY28
};

// translate hat events into keypresses
// the 4 highest buttons are used for the first hat ...
static int hat_keys[16] = {
	K_JOY29, K_JOY30,
	K_JOY31, K_JOY32,
	K_JOY25, K_JOY26,
	K_JOY27, K_JOY28,
	K_JOY21, K_JOY22,
	K_JOY23, K_JOY24,
	K_JOY17, K_JOY18,
	K_JOY19, K_JOY20
};


struct
{
	qboolean buttons[SDL_CONTROLLER_BUTTON_MAX + 1]; // +1 because old max was 16, current SDL_CONTROLLER_BUTTON_MAX is 15
	unsigned int oldaxes;
	int oldaaxes[MAX_JOYSTICK_AXIS];
	unsigned int oldhats;
} stick_state;


/*
===============
IN_InitJoystick
===============
*/
static void IN_InitJoystick( void )
{
	int i = 0;
	int total = 0;
	char buf[16384] = "";

	//if (gamepad)
		;//SDL_GameControllerClose(gamepad);

	//if (stick != NULL)
		;//SDL_JoystickClose(stick);

	//stick = NULL;
	//gamepad = NULL;
	memset(&stick_state, '\0', sizeof (stick_state));

	// SDL 2.0.4 requires SDL_INIT_JOYSTICK to be initialized separately from
	// SDL_INIT_GAMECONTROLLER for SDL_JoystickOpen() to work correctly,
	// despite https://wiki.libsdl.org/SDL_Init (retrieved 2016-08-16)
	// indicating SDL_INIT_JOYSTICK should be initialized automatically.
	//if (!SDL_WasInit(SDL_INIT_JOYSTICK))
	{
		Com_DPrintf("Calling SDL_Init(SDL_INIT_JOYSTICK)...\n");
		//if (SDL_Init(SDL_INIT_JOYSTICK) != 0)
		{
			//Com_DPrintf("SDL_Init(SDL_INIT_JOYSTICK) failed: %s\n", SDL_GetError());
			//return;
		}
		Com_DPrintf("SDL_Init(SDL_INIT_JOYSTICK) passed.\n");
	}

	//if (!SDL_WasInit(SDL_INIT_GAMECONTROLLER))
	{
		Com_DPrintf("Calling SDL_Init(SDL_INIT_GAMECONTROLLER)...\n");
		//if (SDL_Init(SDL_INIT_GAMECONTROLLER) != 0)
		{
			//Com_DPrintf("SDL_Init(SDL_INIT_GAMECONTROLLER) failed: %s\n", SDL_GetError());
			//return;
		}
		Com_DPrintf("SDL_Init(SDL_INIT_GAMECONTROLLER) passed.\n");
	}

	total;// = SDL_NumJoysticks();
	Com_DPrintf("%d possible joysticks\n", total);

	// Print list and build cvar to allow ui to select joystick.
	for (i = 0; i < total; i++)
	{
		//Q_strcat(buf, sizeof(buf), SDL_JoystickNameForIndex(i));
		Q_strcat(buf, sizeof(buf), "\n");
	}

	Cvar_Get( "in_availableJoysticks", buf, CVAR_ROM );

	if( !in_joystick->integer ) {
		Com_DPrintf( "Joystick is not active.\n" );
		//SDL_QuitSubSystem(SDL_INIT_GAMECONTROLLER);
		return;
	}

	in_joystickNo = Cvar_Get( "in_joystickNo", "0", CVAR_ARCHIVE );
	if( in_joystickNo->integer < 0 || in_joystickNo->integer >= total )
		Cvar_Set( "in_joystickNo", "0" );

	in_joystickUseAnalog = Cvar_Get( "in_joystickUseAnalog", "0", CVAR_ARCHIVE );

//	stick ;//= SDL_JoystickOpen( in_joystickNo->integer );

//	if (stick == NULL) {
//		Com_DPrintf( "No joystick opened: %s\n", SDL_GetError() );
//		return;
//	}

	//if (SDL_IsGameController(in_joystickNo->integer))
	//	gamepad = SDL_GameControllerOpen(in_joystickNo->integer);

//	Com_DPrintf( "Joystick %d opened\n", in_joystickNo->integer );
//	Com_DPrintf( "Name:       %s\n", SDL_JoystickNameForIndex(in_joystickNo->integer) );
//	Com_DPrintf( "Axes:       %d\n", SDL_JoystickNumAxes(stick) );
//	Com_DPrintf( "Hats:       %d\n", SDL_JoystickNumHats(stick) );
//	Com_DPrintf( "Buttons:    %d\n", SDL_JoystickNumButtons(stick) );
//	Com_DPrintf( "Balls:      %d\n", SDL_JoystickNumBalls(stick) );
//	Com_DPrintf( "Use Analog: %s\n", in_joystickUseAnalog->integer ? "Yes" : "No" );
//	Com_DPrintf( "Is gamepad: %s\n", gamepad ? "Yes" : "No" );

//	SDL_JoystickEventState(SDL_QUERY);
//	SDL_GameControllerEventState(SDL_QUERY);
}

/*
===============
IN_ShutdownJoystick
===============
*/
static void IN_ShutdownJoystick( void )
{
//	if ( !SDL_WasInit( SDL_INIT_GAMECONTROLLER ) )
//		return;

//	if ( !SDL_WasInit( SDL_INIT_JOYSTICK ) )
//		return;

//	if (gamepad)
//	{
//		SDL_GameControllerClose(gamepad);
//		gamepad = NULL;
//	}

//	if (stick)
//	{
//		SDL_JoystickClose(stick);
//		stick = NULL;
//	}

//	SDL_QuitSubSystem(SDL_INIT_GAMECONTROLLER);
//	SDL_QuitSubSystem(SDL_INIT_JOYSTICK);
}


static qboolean KeyToAxisAndSign(int keynum, int *outAxis, int *outSign)
{
	char *bind;

	if (!keynum)
		return qfalse;

	bind = Key_GetBinding(keynum);

	if (!bind || *bind != '+')
		return qfalse;

	*outSign = 0;

	if (Q_stricmp(bind, "+forward") == 0)
	{
		*outAxis = j_forward_axis->integer;
		*outSign = j_forward->value > 0.0f ? 1 : -1;
	}
	else if (Q_stricmp(bind, "+back") == 0)
	{
		*outAxis = j_forward_axis->integer;
		*outSign = j_forward->value > 0.0f ? -1 : 1;
	}
	else if (Q_stricmp(bind, "+moveleft") == 0)
	{
		*outAxis = j_side_axis->integer;
		*outSign = j_side->value > 0.0f ? -1 : 1;
	}
	else if (Q_stricmp(bind, "+moveright") == 0)
	{
		*outAxis = j_side_axis->integer;
		*outSign = j_side->value > 0.0f ? 1 : -1;
	}
	else if (Q_stricmp(bind, "+lookup") == 0)
	{
		*outAxis = j_pitch_axis->integer;
		*outSign = j_pitch->value > 0.0f ? -1 : 1;
	}
	else if (Q_stricmp(bind, "+lookdown") == 0)
	{
		*outAxis = j_pitch_axis->integer;
		*outSign = j_pitch->value > 0.0f ? 1 : -1;
	}
	else if (Q_stricmp(bind, "+left") == 0)
	{
		*outAxis = j_yaw_axis->integer;
		*outSign = j_yaw->value > 0.0f ? 1 : -1;
	}
	else if (Q_stricmp(bind, "+right") == 0)
	{
		*outAxis = j_yaw_axis->integer;
		*outSign = j_yaw->value > 0.0f ? -1 : 1;
	}
	else if (Q_stricmp(bind, "+moveup") == 0)
	{
		*outAxis = j_up_axis->integer;
		*outSign = j_up->value > 0.0f ? 1 : -1;
	}
	else if (Q_stricmp(bind, "+movedown") == 0)
	{
		*outAxis = j_up_axis->integer;
		*outSign = j_up->value > 0.0f ? -1 : 1;
	}

	return *outSign != 0;
}

/*
===============
IN_GamepadMove
===============
*/
static void IN_GamepadMove( void )
{
	int i;
	int translatedAxes[MAX_JOYSTICK_AXIS];
	qboolean translatedAxesSet[MAX_JOYSTICK_AXIS];

	SDL_GameControllerUpdate();

	// check buttons
	for (i = 0; i < SDL_CONTROLLER_BUTTON_MAX; i++)
	{
		qboolean pressed ;//= SDL_GameControllerGetButton(gamepad, SDL_CONTROLLER_BUTTON_A + i);
		if (pressed != stick_state.buttons[i])
		{
			//Com_QueueEvent(in_eventTime, SE_KEY, K_PAD0_A + i, pressed, 0, NULL);
			stick_state.buttons[i] = pressed;
		}
	}

	// must defer translated axes until all real axes are processed
	// must be done this way to prevent a later mapped axis from zeroing out a previous one
	if (in_joystickUseAnalog->integer)
	{
		for (i = 0; i < MAX_JOYSTICK_AXIS; i++)
		{
			translatedAxes[i] = 0;
			translatedAxesSet[i] = qfalse;
		}
	}

	// check axes
	for (i = 0; i < SDL_CONTROLLER_AXIS_MAX; i++)
	{
		int axis;// = SDL_GameControllerGetAxis(gamepad, SDL_CONTROLLER_AXIS_LEFTX + i);
		int oldAxis = stick_state.oldaaxes[i];

		// Smoothly ramp from dead zone to maximum value
		float f = ((float)abs(axis) / 32767.0f - in_joystickThreshold->value) / (1.0f - in_joystickThreshold->value);

		if (f < 0.0f)
			f = 0.0f;

		axis = (int)(32767 * ((axis < 0) ? -f : f));

		if (axis != oldAxis)
		{
			const int negMap[SDL_CONTROLLER_AXIS_MAX] = { K_PAD0_LEFTSTICK_LEFT,  K_PAD0_LEFTSTICK_UP,   K_PAD0_RIGHTSTICK_LEFT,  K_PAD0_RIGHTSTICK_UP, 0, 0 };
			const int posMap[SDL_CONTROLLER_AXIS_MAX] = { K_PAD0_LEFTSTICK_RIGHT, K_PAD0_LEFTSTICK_DOWN, K_PAD0_RIGHTSTICK_RIGHT, K_PAD0_RIGHTSTICK_DOWN, K_PAD0_LEFTTRIGGER, K_PAD0_RIGHTTRIGGER };

			qboolean posAnalog = qfalse, negAnalog = qfalse;
			int negKey = negMap[i];
			int posKey = posMap[i];

			if (in_joystickUseAnalog->integer)
			{
				int posAxis = 0, posSign = 0, negAxis = 0, negSign = 0;

				// get axes and axes signs for keys if available
				posAnalog = KeyToAxisAndSign(posKey, &posAxis, &posSign);
				negAnalog = KeyToAxisAndSign(negKey, &negAxis, &negSign);

				// positive to negative/neutral -> keyup if axis hasn't yet been set
				if (posAnalog && !translatedAxesSet[posAxis] && oldAxis > 0 && axis <= 0)
				{
					translatedAxes[posAxis] = 0;
					translatedAxesSet[posAxis] = qtrue;
				}

				// negative to positive/neutral -> keyup if axis hasn't yet been set
				if (negAnalog && !translatedAxesSet[negAxis] && oldAxis < 0 && axis >= 0)
				{
					translatedAxes[negAxis] = 0;
					translatedAxesSet[negAxis] = qtrue;
				}

				// negative/neutral to positive -> keydown
				if (posAnalog && axis > 0)
				{
					translatedAxes[posAxis] = axis * posSign;
					translatedAxesSet[posAxis] = qtrue;
				}

				// positive/neutral to negative -> keydown
				if (negAnalog && axis < 0)
				{
					translatedAxes[negAxis] = -axis * negSign;
					translatedAxesSet[negAxis] = qtrue;
				}
			}

			// keyups first so they get overridden by keydowns later

			// positive to negative/neutral -> keyup
			if (!posAnalog && posKey && oldAxis > 0 && axis <= 0)
				Com_QueueEvent(in_eventTime, SE_KEY, posKey, qfalse, 0, NULL);

			// negative to positive/neutral -> keyup
			if (!negAnalog && negKey && oldAxis < 0 && axis >= 0)
				Com_QueueEvent(in_eventTime, SE_KEY, negKey, qfalse, 0, NULL);

			// negative/neutral to positive -> keydown
			if (!posAnalog && posKey && oldAxis <= 0 && axis > 0)
				Com_QueueEvent(in_eventTime, SE_KEY, posKey, qtrue, 0, NULL);

			// positive/neutral to negative -> keydown
			if (!negAnalog && negKey && oldAxis >= 0 && axis < 0)
				Com_QueueEvent(in_eventTime, SE_KEY, negKey, qtrue, 0, NULL);

			stick_state.oldaaxes[i] = axis;
		}
	}

	// set translated axes
	if (in_joystickUseAnalog->integer)
	{
		for (i = 0; i < MAX_JOYSTICK_AXIS; i++)
		{
			if (translatedAxesSet[i])
				Com_QueueEvent(in_eventTime, SE_JOYSTICK_AXIS, i, translatedAxes[i], 0, NULL);
		}
	}
}


/*
===============
IN_JoyMove
===============
*/
static void IN_JoyMove( void )
{
	unsigned int axes = 0;
	unsigned int hats = 0;
	int total = 0;
	int i = 0;

//	if (gamepad)
	{
		IN_GamepadMove();
		return;
	}

//	if (!stick)
//		return;

	SDL_JoystickUpdate();

	// update the ball state.
	total;// = SDL_JoystickNumBalls(stick);
	if (total > 0)
	{
		int balldx = 0;
		int balldy = 0;
		for (i = 0; i < total; i++)
		{
			int dx = 0;
			int dy = 0;
//			SDL_JoystickGetBall(stick, i, &dx, &dy);
			balldx += dx;
			balldy += dy;
		}
		if (balldx || balldy)
		{
			// !!! FIXME: is this good for stick balls, or just mice?
			// Scale like the mouse input...
			if (abs(balldx) > 1)
				balldx *= 2;
			if (abs(balldy) > 1)
				balldy *= 2;
			Com_QueueEvent( in_eventTime, SE_MOUSE, balldx, balldy, 0, NULL );
		}
	}

	// now query the stick buttons...
	total;// = SDL_JoystickNumButtons(stick);
	if (total > 0)
	{
		if (total > ARRAY_LEN(stick_state.buttons))
			total = ARRAY_LEN(stick_state.buttons);
		for (i = 0; i < total; i++)
		{
			qboolean pressed;// = (SDL_JoystickGetButton(stick, i) != 0);
			if (pressed != stick_state.buttons[i])
			{
				Com_QueueEvent( in_eventTime, SE_KEY, K_JOY1 + i, pressed, 0, NULL );
				stick_state.buttons[i] = pressed;
			}
		}
	}

	// look at the hats...
	total;// = SDL_JoystickNumHats(stick);
	if (total > 0)
	{
		if (total > 4) total = 4;
		for (i = 0; i < total; i++)
		{
			((Uint8 *)&hats)[i] ;//= SDL_JoystickGetHat(stick, i);
		}
	}

	// update hat state
	if (hats != stick_state.oldhats)
	{
		for( i = 0; i < 4; i++ ) {
			if( ((Uint8 *)&hats)[i] != ((Uint8 *)&stick_state.oldhats)[i] ) {
				// release event
				switch( ((Uint8 *)&stick_state.oldhats)[i] ) {
					case SDL_HAT_UP:
						Com_QueueEvent( in_eventTime, SE_KEY, hat_keys[4*i + 0], qfalse, 0, NULL );
						break;
					case SDL_HAT_RIGHT:
						Com_QueueEvent( in_eventTime, SE_KEY, hat_keys[4*i + 1], qfalse, 0, NULL );
						break;
					case SDL_HAT_DOWN:
						Com_QueueEvent( in_eventTime, SE_KEY, hat_keys[4*i + 2], qfalse, 0, NULL );
						break;
					case SDL_HAT_LEFT:
						Com_QueueEvent( in_eventTime, SE_KEY, hat_keys[4*i + 3], qfalse, 0, NULL );
						break;
					case SDL_HAT_RIGHTUP:
						Com_QueueEvent( in_eventTime, SE_KEY, hat_keys[4*i + 0], qfalse, 0, NULL );
						Com_QueueEvent( in_eventTime, SE_KEY, hat_keys[4*i + 1], qfalse, 0, NULL );
						break;
					case SDL_HAT_RIGHTDOWN:
						Com_QueueEvent( in_eventTime, SE_KEY, hat_keys[4*i + 2], qfalse, 0, NULL );
						Com_QueueEvent( in_eventTime, SE_KEY, hat_keys[4*i + 1], qfalse, 0, NULL );
						break;
					case SDL_HAT_LEFTUP:
						Com_QueueEvent( in_eventTime, SE_KEY, hat_keys[4*i + 0], qfalse, 0, NULL );
						Com_QueueEvent( in_eventTime, SE_KEY, hat_keys[4*i + 3], qfalse, 0, NULL );
						break;
					case SDL_HAT_LEFTDOWN:
						Com_QueueEvent( in_eventTime, SE_KEY, hat_keys[4*i + 2], qfalse, 0, NULL );
						Com_QueueEvent( in_eventTime, SE_KEY, hat_keys[4*i + 3], qfalse, 0, NULL );
						break;
					default:
						break;
				}
				// press event
				switch( ((Uint8 *)&hats)[i] ) {
					case SDL_HAT_UP:
						Com_QueueEvent( in_eventTime, SE_KEY, hat_keys[4*i + 0], qtrue, 0, NULL );
						break;
					case SDL_HAT_RIGHT:
						Com_QueueEvent( in_eventTime, SE_KEY, hat_keys[4*i + 1], qtrue, 0, NULL );
						break;
					case SDL_HAT_DOWN:
						Com_QueueEvent( in_eventTime, SE_KEY, hat_keys[4*i + 2], qtrue, 0, NULL );
						break;
					case SDL_HAT_LEFT:
						Com_QueueEvent( in_eventTime, SE_KEY, hat_keys[4*i + 3], qtrue, 0, NULL );
						break;
					case SDL_HAT_RIGHTUP:
						Com_QueueEvent( in_eventTime, SE_KEY, hat_keys[4*i + 0], qtrue, 0, NULL );
						Com_QueueEvent( in_eventTime, SE_KEY, hat_keys[4*i + 1], qtrue, 0, NULL );
						break;
					case SDL_HAT_RIGHTDOWN:
						Com_QueueEvent( in_eventTime, SE_KEY, hat_keys[4*i + 2], qtrue, 0, NULL );
						Com_QueueEvent( in_eventTime, SE_KEY, hat_keys[4*i + 1], qtrue, 0, NULL );
						break;
					case SDL_HAT_LEFTUP:
						Com_QueueEvent( in_eventTime, SE_KEY, hat_keys[4*i + 0], qtrue, 0, NULL );
						Com_QueueEvent( in_eventTime, SE_KEY, hat_keys[4*i + 3], qtrue, 0, NULL );
						break;
					case SDL_HAT_LEFTDOWN:
						Com_QueueEvent( in_eventTime, SE_KEY, hat_keys[4*i + 2], qtrue, 0, NULL );
						Com_QueueEvent( in_eventTime, SE_KEY, hat_keys[4*i + 3], qtrue, 0, NULL );
						break;
					default:
						break;
				}
			}
		}
	}

	// save hat state
	stick_state.oldhats = hats;

	// finally, look at the axes...
	total;// = SDL_JoystickNumAxes(stick);
	if (total > 0)
	{
		if (in_joystickUseAnalog->integer)
		{
			if (total > MAX_JOYSTICK_AXIS) total = MAX_JOYSTICK_AXIS;
			for (i = 0; i < total; i++)
			{
				Sint16 axis ;//= SDL_JoystickGetAxis(stick, i);
				float f = ( (float) abs(axis) ) / 32767.0f;
				
				if( f < in_joystickThreshold->value ) axis = 0;

				if ( axis != stick_state.oldaaxes[i] )
				{
					Com_QueueEvent( in_eventTime, SE_JOYSTICK_AXIS, i, axis, 0, NULL );
					stick_state.oldaaxes[i] = axis;
				}
			}
		}
		else
		{
			if (total > 16) total = 16;
			for (i = 0; i < total; i++)
			{
				Sint16 axis ;//= SDL_JoystickGetAxis(stick, i);
				float f = ( (float) axis ) / 32767.0f;
				if( f < -in_joystickThreshold->value ) {
					axes |= ( 1 << ( i * 2 ) );
				} else if( f > in_joystickThreshold->value ) {
					axes |= ( 1 << ( ( i * 2 ) + 1 ) );
				}
			}
		}
	}

	/* Time to update axes state based on old vs. new. */
	if (axes != stick_state.oldaxes)
	{
		for( i = 0; i < 16; i++ ) {
			if( ( axes & ( 1 << i ) ) && !( stick_state.oldaxes & ( 1 << i ) ) ) {
				Com_QueueEvent( in_eventTime, SE_KEY, joy_keys[i], qtrue, 0, NULL );
			}

			if( !( axes & ( 1 << i ) ) && ( stick_state.oldaxes & ( 1 << i ) ) ) {
				Com_QueueEvent( in_eventTime, SE_KEY, joy_keys[i], qfalse, 0, NULL );
			}
		}
	}

	/* Save for future generations. */
	stick_state.oldaxes = axes;
}

/*
===============
IN_ProcessEvents
===============
*/
static void IN_ProcessEvents( void )
{
	keyNum_t key = 0;
	static keyNum_t lastKeyDown = 0;

	inputEvent e;

	while(handleInput(&e) > 0)
	{
		switch( e.type )
		{
			case 300:
			{
				if(e.buttonState)
				{
					if ( e.buttonRepeat && Key_GetCatcher( ) == 0 )
						break;

					if( ( key = IN_TranslateSDLToQ3Key( e.button, qtrue ) ) )
						Com_QueueEvent( in_eventTime, SE_KEY, key, qtrue, 0, NULL );

					if( key == K_BACKSPACE )
						Com_QueueEvent( in_eventTime, SE_CHAR, CTRL('h'), 0, 0, NULL );
					else if( keys[K_CTRL].down && key >= 'a' && key <= 'z' )
						Com_QueueEvent( in_eventTime, SE_CHAR, CTRL(key), 0, 0, NULL );

					lastKeyDown = key;
					break;
				}
				else
				{
					if( ( key = IN_TranslateSDLToQ3Key( e.button, qfalse ) ) )
						Com_QueueEvent( in_eventTime, SE_KEY, key, qfalse, 0, NULL );

					lastKeyDown = 0;
					break;
				}
			}
			case 400:
				if( mouseActive )
				{
					Com_QueueEvent( in_eventTime, SE_MOUSE, e.xCoord, e.yCoord, 0, NULL );
				}
				break;

			case 402:
				{
					int b;
					switch( e.button )
					{
						case 272:	b = K_MOUSE1;     break;
						case 274:	b = K_MOUSE3;     break;
						case 273:	b = K_MOUSE2;     break;
						//case SDL_BUTTON_X1:     b = K_MOUSE4;     break;
						//case SDL_BUTTON_X2:     b = K_MOUSE5;     break;
						//default:                b = K_AUX1 + ( e.button.button - SDL_BUTTON_X2 + 1 ) % 16; break;
					}
					Com_QueueEvent( in_eventTime, SE_KEY, b, e.buttonState, 0, NULL );
				}
				break;

			case 403:
				if( e.yCoord > 0.0 )
				{
					Com_QueueEvent( in_eventTime, SE_KEY, K_MWHEELUP, qtrue, 0, NULL );
					Com_QueueEvent( in_eventTime, SE_KEY, K_MWHEELUP, qfalse, 0, NULL );
				}
				else if( e.yCoord < 0 )
				{
					Com_QueueEvent( in_eventTime, SE_KEY, K_MWHEELDOWN, qtrue, 0, NULL );
					Com_QueueEvent( in_eventTime, SE_KEY, K_MWHEELDOWN, qfalse, 0, NULL );
				}
				break;

			//case SDL_CONTROLLERDEVICEADDED:
			//case SDL_CONTROLLERDEVICEREMOVED:
//				if (in_joystick->integer)
//					IN_InitJoystick();
//				break;

//			case SDL_QUIT:
//				Cbuf_ExecuteText(EXEC_NOW, "quit Closed window\n");
//				break;

//			case SDL_WINDOWEVENT:
//				switch( e.window.event )
//				{
//					case SDL_WINDOWEVENT_RESIZED:
//						{
//							int width, height;

//							width = e.window.data1;
//							height = e.window.data2;

//							// ignore this event on fullscreen
//							if( cls.glconfig.isFullscreen )
//							{
//								break;
//							}

//							// check if size actually changed
//							if( cls.glconfig.vidWidth == width && cls.glconfig.vidHeight == height )
//							{
//								break;
//							}

//							Cvar_SetValue( "r_customwidth", width );
//							Cvar_SetValue( "r_customheight", height );
//							Cvar_Set( "r_mode", "-1" );

//							// Wait until user stops dragging for 1 second, so
//							// we aren't constantly recreating the GL context while
//							// he tries to drag...
//							vidRestartTime = Sys_Milliseconds( ) + 1000;
//						}
//						break;

//					case SDL_WINDOWEVENT_MINIMIZED:    Cvar_SetValue( "com_minimized", 1 ); break;
//					case SDL_WINDOWEVENT_RESTORED:
//					case SDL_WINDOWEVENT_MAXIMIZED:    Cvar_SetValue( "com_minimized", 0 ); break;
//					case SDL_WINDOWEVENT_FOCUS_LOST:   Cvar_SetValue( "com_unfocused", 1 ); break;
//					case SDL_WINDOWEVENT_FOCUS_GAINED: Cvar_SetValue( "com_unfocused", 0 ); break;
//				}
//				break;

			default:
				break;
		}
	}
}

/*
===============
IN_Frame
===============
*/
void IN_Frame( void )
{
	qboolean loading;

	IN_ProcessEvents( );

	//IN_JoyMove( );

	// If not DISCONNECTED (main menu) or ACTIVE (in game), we're loading
	loading = ( clc.state != CA_DISCONNECTED && clc.state != CA_ACTIVE );

	// update isFullscreen since it might of changed since the last vid_restart
	cls.glconfig.isFullscreen = Cvar_VariableIntegerValue( "r_fullscreen" ) != 0;

	if( !cls.glconfig.isFullscreen && ( Key_GetCatcher( ) & KEYCATCH_CONSOLE ) )
	{
		// Console is down in windowed mode
		IN_DeactivateMouse( cls.glconfig.isFullscreen );
	}
	else if( !cls.glconfig.isFullscreen && loading )
	{
		// Loading in windowed mode
		IN_DeactivateMouse( cls.glconfig.isFullscreen );
	}
//	else if( !( SDL_GetWindowFlags( SDL_window ) & SDL_WINDOW_INPUT_FOCUS ) )
//	{
//		// Window not got focus
//		IN_DeactivateMouse( cls.glconfig.isFullscreen );
//	}
	else
		IN_ActivateMouse( cls.glconfig.isFullscreen );

	// Set event time for next frame to earliest possible time an event could happen
	in_eventTime = Sys_Milliseconds( );

	// In case we had to delay actual restart of video system
	if( ( vidRestartTime != 0 ) && ( vidRestartTime < Sys_Milliseconds( ) ) )
	{
		vidRestartTime = 0;
		Cbuf_AddText( "vid_restart\n" );
	}
}

/*
===============
IN_Init
===============
*/
void IN_Init( void *windowData )
{
	int appState;

	Com_DPrintf( "\n------- Input Initialization -------\n" );

	initInputHandler();

	in_keyboardDebug = Cvar_Get( "in_keyboardDebug", "0", CVAR_ARCHIVE );

	// mouse variables
	in_mouse = Cvar_Get( "in_mouse", "1", CVAR_ARCHIVE );
	in_nograb = Cvar_Get( "in_nograb", "0", CVAR_ARCHIVE );

	in_joystick = Cvar_Get( "in_joystick", "0", CVAR_ARCHIVE|CVAR_LATCH );
	in_joystickThreshold = Cvar_Get( "joy_threshold", "0.15", CVAR_ARCHIVE );

	mouseAvailable = ( in_mouse->value != 0 );
	IN_DeactivateMouse( Cvar_VariableIntegerValue( "r_fullscreen" ) != 0 );

	//appState = SDL_GetWindowFlags( SDL_window );
	Cvar_SetValue( "com_unfocused",	0 ); // !( appState & SDL_WINDOW_INPUT_FOCUS ) );
	Cvar_SetValue( "com_minimized", 0 ); //appState & SDL_WINDOW_MINIMIZED );

	//IN_InitJoystick( );
	Com_DPrintf( "------------------------------------\n" );
}

/*
===============
IN_Shutdown
===============
*/
void IN_Shutdown( void )
{
	//SDL_StopTextInput( );

	IN_DeactivateMouse( Cvar_VariableIntegerValue( "r_fullscreen" ) != 0 );
	mouseAvailable = qfalse;

	IN_ShutdownJoystick( );

	uninitInputHandler();
}

/*
===============
IN_Restart
===============
*/
void IN_Restart( void )
{
	IN_ShutdownJoystick( );
	IN_Init( 0 );
}
