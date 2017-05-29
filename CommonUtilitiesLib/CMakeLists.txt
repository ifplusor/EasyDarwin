
add_definitions(-D_REENTRANT -D__USE_POSIX -D__linux__)
add_compile_options(-include ../Include/PlatformHeader.h)
include_directories(
		.
		../Include
		../EasyDarwin/APICommonCode
		../EasyDarwin/APIStubLib
        ../EasyDarwin/RTPMetaInfoLib
		../EasyProtocol/Include
		../RTSPUtilitiesLib
		../HTTPUtilitiesLib)

set(OBJECTFILES
		#../OSMemoryLib/OSMemory.cpp
		../SafeStdLib/InternalStdLib.cpp
        ClientSocket.cpp
		ConfParser.cpp
		DateTranslator.cpp
		EventContext.cpp
        Format.cpp
		GetWord.c
		IdleTask.cpp
		MyAssert.cpp
		OS.cpp
		OSBufferPool.cpp
        OSCodeFragment.cpp
		OSCond.cpp
		OSFileSource.cpp
		OSHeap.cpp
		OSMapEx.cpp
        OSMutex.cpp
		OSMutexRW.cpp
		OSQueue.cpp
		OSRef.cpp
		OSRefTableEx.cpp
		OSThread.cpp
        QueryParamList.cpp
		ResizeableStringFormatter.cpp
		SDPUtils.cpp
		Socket.cpp
        SocketUtils.cpp
		StrPtrLen.cpp
		StringFormatter.cpp
		StringParser.cpp
        StringTranslator.cpp
		TCPListenerSocket.cpp
		TCPSocket.cpp Task.cpp
        TimeoutTask.cpp
		Trim.c
		UDPDemuxer.cpp
		UDPSocket.cpp
		UDPSocketPool.cpp
        UserAgentParser.cpp
		atomic.cpp
		base64.c
		easy_gettimeofday.cpp
		epollEvent.cpp
        ev.cpp
		getopt.c
		keyframecache.cpp
		md5.c
		md5digest.cpp
		sdpCache.cpp)

add_library(CommonUtilitiesLib STATIC ${OBJECTFILES})



