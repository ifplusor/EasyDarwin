

add_compile_options(-m64)
include_directories(../EasyProtocol/Include)

set(SOURCE_FILES
		EasyRedisClient.cpp
		async.c
		dict.c
		hiredis.c
		net.c
		read.c
		sds.c)

add_library(easyredisclient STATIC ${SOURCE_FILES})

