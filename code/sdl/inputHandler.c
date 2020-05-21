#if defined (__cplusplus)
extern "C" {
#endif

#include "inputHandler.h"

#include <stdio.h>
#include <string.h>

#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <libinput.h>
#include <libudev.h>

struct libinput *li;
struct udev* _udev;

static int open_restricted(const char *path, int flags, void *user_data)
{
	int fd = open(path, flags);
	return fd < 0 ? -errno : fd;
}

static void close_restricted(int fd, void *user_data)
{
	close(fd);
}

const static struct libinput_interface interface = {
	.open_restricted = open_restricted,
	.close_restricted = close_restricted,
};

int initInputHandler()
{
	_udev = udev_new();
	udev_ref(_udev);
	li = libinput_udev_create_context(&interface, NULL, _udev); if(!li) return -1;
	uint32_t res = libinput_udev_assign_seat(li, "seat0"); if(res != 0) return -1;

	libinput_dispatch(li);

	struct libinput_event* event = 0;
	while ((event = libinput_get_event(li)) != 0)
	{
		uint32_t type = libinput_event_get_type(event);

		switch(type)
		{
		case LIBINPUT_EVENT_DEVICE_ADDED:
		{
			struct libinput_device* dev = libinput_event_get_device(event);
			break;
		}
		};


		libinput_event_destroy(event);
		libinput_dispatch(li);
	}

	return 1;
}

int handleInput(inputEvent* e)
{
	if(!li) return -1;
	if(!e) return -1;

	e->type = -1;

	libinput_dispatch(li);

	struct libinput_event* event = libinput_get_event(li);

	if(!event)
	{
		return -1;
	}

	e->type = libinput_event_get_type(event);;

	switch(e->type)
	{
	case LIBINPUT_EVENT_KEYBOARD_KEY:
	{
		static uint32_t lastKey = 0;
		lastKey = e->button;
		e->button = libinput_event_keyboard_get_key(libinput_event_get_keyboard_event(event));
		e->buttonState = libinput_event_keyboard_get_key_state(libinput_event_get_keyboard_event(event));
		if(lastKey == e->button)
		{
			e->buttonRepeat = 1;
		}
		else
		{
			e->buttonRepeat = 0;
		}
		break;
	}
	case LIBINPUT_EVENT_POINTER_MOTION:
	{
		e->xCoord = libinput_event_pointer_get_dx(libinput_event_get_pointer_event(event));
		e->yCoord = libinput_event_pointer_get_dy(libinput_event_get_pointer_event(event));
		break;
	}
	case LIBINPUT_EVENT_POINTER_MOTION_ABSOLUTE:
	{
		e->xCoord = libinput_event_pointer_get_absolute_x(libinput_event_get_pointer_event(event));
		e->yCoord = libinput_event_pointer_get_absolute_y(libinput_event_get_pointer_event(event));
		break;
	}
	case LIBINPUT_EVENT_POINTER_BUTTON:
	{
		e->button = libinput_event_pointer_get_button(libinput_event_get_pointer_event(event));
		e->buttonState = libinput_event_pointer_get_button_state(libinput_event_get_pointer_event(event));
		break;
	}
	case LIBINPUT_EVENT_POINTER_AXIS:
	{
		enum libinput_pointer_axis_source axisSource = libinput_event_pointer_get_axis_source(libinput_event_get_pointer_event(event));
		if(axisSource != LIBINPUT_POINTER_AXIS_SOURCE_WHEEL)
		{
			break;
		}

		if(libinput_event_pointer_has_axis(event, LIBINPUT_POINTER_AXIS_SCROLL_HORIZONTAL))
		{
			e->xCoord = libinput_event_pointer_get_axis_value(libinput_event_get_pointer_event(event), LIBINPUT_POINTER_AXIS_SCROLL_HORIZONTAL);
		}

		if(libinput_event_pointer_has_axis(event, LIBINPUT_POINTER_AXIS_SCROLL_VERTICAL))
		{
			e->yCoord = libinput_event_pointer_get_axis_value(libinput_event_get_pointer_event(event), LIBINPUT_POINTER_AXIS_SCROLL_VERTICAL);
		}
		break;
	}
	default:
	{
		break;
	}
	};


	libinput_event_destroy(event);

	return 1;
}

void uninitInputHandler()
{
	libinput_unref(li);
	udev_unref(_udev);
}

#if defined (__cplusplus)
}
#endif
