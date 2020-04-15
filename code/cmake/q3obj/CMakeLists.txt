file(GLOB q3obj
	"../../client/cl_cgame.c"
	"../../client/cl_cin.c"
	"../../client/cl_console.c"
	"../../client/cl_input.c"
	"../../client/cl_keys.c"
	"../../client/cl_main.c"
	"../../client/cl_net_chan.c"
	"../../client/cl_parse.c"
	"../../client/cl_scrn.c"
	"../../client/cl_ui.c"
	"../../client/cl_avi.c"

	"../../qcommon/cm_load.c"
	"../../qcommon/cm_patch.c"
	"../../qcommon/cm_polylib.c"
	"../../qcommon/cm_test.c"
	"../../qcommon/cm_trace.c"

	"../../qcommon/cmd.c"
	"../../qcommon/common.c"
	"../../qcommon/cvar.c"
	"../../qcommon/files.c"
	"../../qcommon/md4.c"
	"../../qcommon/md5.c"
	"../../qcommon/msg.c"
	"../../qcommon/net_chan.c"
	"../../qcommon/net_ip.c"
	"../../qcommon/huffman.c"

	"../../client/snd_altivec.c"
	"../../client/snd_adpcm.c"
	"../../client/snd_dma.c"
	"../../client/snd_mem.c"
	"../../client/snd_mix.c"
	"../../client/snd_wavelet.c"

	"../../client/snd_main.c"
	"../../client/snd_codec.c"
	"../../client/snd_codec_wav.c"
	"../../client/snd_codec_ogg.c"
	"../../client/snd_codec_opus.c"

	"../../client/qal.c"
	"../../client/snd_openal.c"

	"../../client/cl_curl.c"

	"../../server/sv_bot.c"
	"../../server/sv_ccmds.c"
	"../../server/sv_client.c"
	"../../server/sv_game.c"
	"../../server/sv_init.c"
	"../../server/sv_main.c"
	"../../server/sv_net_chan.c"
	"../../server/sv_snapshot.c"
	"../../server/sv_world.c"

	"../../qcommon/q_math.c"
	"../../qcommon/q_shared.c"

	"../../qcommon/unzip.c"
	"../../qcommon/ioapi.c"
	"../../qcommon/puff.c"
	"../../qcommon/vm.c"
	"../../qcommon/vm_interpreted.c"

	"../../botlib/be_aas_bspq3.c"
	"../../botlib/be_aas_cluster.c"
	"../../botlib/be_aas_debug.c"
	"../../botlib/be_aas_entity.c"
	"../../botlib/be_aas_file.c"
	"../../botlib/be_aas_main.c"
	"../../botlib/be_aas_move.c"
	"../../botlib/be_aas_optimize.c"
	"../../botlib/be_aas_reach.c"
	"../../botlib/be_aas_route.c"
	"../../botlib/be_aas_routealt.c"
	"../../botlib/be_aas_sample.c"
	"../../botlib/be_ai_char.c"
	"../../botlib/be_ai_chat.c"
	"../../botlib/be_ai_gen.c"
	"../../botlib/be_ai_goal.c"
	"../../botlib/be_ai_move.c"
	"../../botlib/be_ai_weap.c"
	"../../botlib/be_ai_weight.c"
	"../../botlib/be_ea.c"
	"../../botlib/be_interface.c"
	"../../botlib/l_crc.c"
	"../../botlib/l_libvar.c"
	"../../botlib/l_log.c"
	"../../botlib/l_memory.c"
	"../../botlib/l_precomp.c"
	"../../botlib/l_script.c"
	"../../botlib/l_struct.c"

	"../../sdl/sdl_input.c"
	"../../sdl/sdl_snd.c"

	"../../sys/con_log.c"
	"../../sys/sys_autoupdater.c"
	"../../sys/sys_main.c"

	"../../sys/con_tty.c"

	#OPUS?
	#OGG?
	#VORBIS?
	#ZLIB?

	#ARMv7l
	#"../../client/vm_armv7l.c"

	"../../sys/sys_unix.c"

	#MUMBLE?
)

add_executable(ioquake3 ${q3obj})
target_compile_options(ioquake3 PRIVATE -Wall -Werror=implicit-function-declaration -std=c11)

target_include_directories(ioquake3 PUBLIC ../../SDL2)

target_link_libraries(ioquake3 pthread dl m rt jpeg-8c SDL2 zlib)
