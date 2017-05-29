

include_directories(../jsoncpp/include ../Include)

set(OBJECTFILES
		EasyProtocol.cpp
		EasyProtocolBase.cpp
		EasyUtil.cpp)

add_library(EasyProtocol STATIC ${OBJECTFILES})