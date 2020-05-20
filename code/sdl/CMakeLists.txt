file(GLOB sdlSrc
	"*.h"
	"inputHandler.c"
	"sdl_gamma.c"
	"sdl_input.c"
	"sdl_snd.c"
)

add_library(sdl SHARED ${sdlSrc})
target_compile_options(sdl PRIVATE -Wall -Werror=implicit-function-declaration -std=c11  -march=${ARCH_STRING} -fPIC)

target_include_directories(sdl PUBLIC ../SDL2)
target_link_libraries(sdl SDL2 mtdev evdev udev input)
