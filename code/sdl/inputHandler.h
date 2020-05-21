#pragma once

#if defined (__cplusplus)
extern "C" {
#endif

#include <stdint.h>

typedef struct inputEvent
{
	uint32_t type;
	uint32_t button;
	uint32_t buttonState;
	uint32_t buttonRepeat;
	double xCoord, yCoord;
} inputEvent;

int initInputHandler();
int handleInput(inputEvent* e);
void uninitInputHandler();

#if defined (__cplusplus)
}
#endif

