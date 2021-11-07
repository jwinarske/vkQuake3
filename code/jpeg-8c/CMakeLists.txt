file(GLOB jpegSrc
	"*.h"
	"*.c"
)

add_library(jpeg-8c STATIC ${jpegSrc})
target_compile_options(jpeg-8c PRIVATE -Wall -Werror=implicit-function-declaration)
