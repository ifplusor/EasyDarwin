

add_compile_options(-include ../Include/PlatformHeader.h)
add_definitions(-DDSS_USE_API_CALLBACKS -D_REENTRANT -D__USE_POSIX -D__linux__)
include_directories(../HTTPUtilitiesLib ../CommonUtilitiesLib Server.tproj
        QTFileLib/ RTPMetaInfoLib/ PrefsSourceLib/ APIStubLib/ APICommonCode/
        RTCPUtilitiesLib/ RTSPClientLib/ APIModules/QTSSFileModule/
        APIModules/QTSSHttpFileModule/ APIModules/QTSSAccessModule/
        APIModules/QTSSAccessLogModule/ APIModules/QTSSPOSIXFileSysModule
        APIModules/QTSSAdminModule/ APIModules/QTSSReflectorModule/
        APIModules/QTSSWebStatsModule/ APIModules/QTSSWebDebugModule/
        APIModules/QTSSFlowControlModule/ APIModules/QTSSMP3StreamingModule/
        APIModules/EasyHLSModule APIModules/EasyRelayModule Include .
        ../Include ../EasyProtocol/Include ../EasyProtocol/jsoncpp/include
        APIModules/EasyCMSModule APIModules/EasyRedisModule ../EasyRedisClient
        ../RTSPUtilitiesLib)

set(SOURCE_FILES
        ../HTTPUtilitiesLib/HTTPClientRequestStream.cpp
        ../HTTPUtilitiesLib/HTTPClientResponseStream.cpp
        ../HTTPUtilitiesLib/HTTPProtocol.cpp
        ../HTTPUtilitiesLib/HTTPRequest.cpp
        ../RTSPUtilitiesLib/RTSPProtocol.cpp
        APICommonCode/QTAccessFile.cpp
        APICommonCode/QTSSModuleUtils.cpp
        APICommonCode/QTSSRollingLog.cpp
        APICommonCode/SDPSourceInfo.cpp
        APICommonCode/SourceInfo.cpp
        APIModules/EasyCMSModule/EasyCMSModule.cpp
        APIModules/EasyCMSModule/EasyCMSSession.cpp
        APIModules/EasyRedisModule/EasyRedisModule.cpp
        APIModules/QTSSAccessLogModule/QTSSAccessLogModule.cpp
        APIModules/QTSSAccessModule/AccessChecker.cpp
        APIModules/QTSSAccessModule/QTSSAccessModule.cpp
        APIModules/QTSSAdminModule/AdminElementNode.cpp
        APIModules/QTSSAdminModule/AdminQuery.cpp
        APIModules/QTSSAdminModule/QTSSAdminModule.cpp
        APIModules/QTSSAdminModule/frozen.c
        APIModules/QTSSAdminModule/mongoose.c
        APIModules/QTSSFlowControlModule/QTSSFlowControlModule.cpp
        APIModules/QTSSPOSIXFileSysModule/QTSSPosixFileSysModule.cpp
        APIModules/QTSSReflectorModule/QTSSReflectorModule.cpp
        APIModules/QTSSReflectorModule/RCFSourceInfo.cpp
        APIModules/QTSSReflectorModule/RTPSessionOutput.cpp
        APIModules/QTSSReflectorModule/ReflectorSession.cpp
        APIModules/QTSSReflectorModule/ReflectorStream.cpp
        APIModules/QTSSReflectorModule/SequenceNumberMap.cpp
        APIModules/QTSSWebDebugModule/QTSSWebDebugModule.cpp
        #APIModules/QTSSWebStatsModule/QTSSWebStatsModule.cpp
        APIStubLib/QTSS_Private.cpp
        PrefsSourceLib/FilePrefsSource.cpp
        PrefsSourceLib/XMLParser.cpp
        PrefsSourceLib/XMLPrefsParser.cpp
        QTFileLib/QTAtom.cpp
        QTFileLib/QTAtom_dref.cpp
        QTFileLib/QTAtom_elst.cpp
        QTFileLib/QTAtom_hinf.cpp
        QTFileLib/QTAtom_mdhd.cpp
        QTFileLib/QTAtom_mvhd.cpp
        QTFileLib/QTAtom_stco.cpp
        QTFileLib/QTAtom_stsc.cpp
        QTFileLib/QTAtom_stsd.cpp
        QTFileLib/QTAtom_stss.cpp
        QTFileLib/QTAtom_stsz.cpp
        QTFileLib/QTAtom_stts.cpp
        QTFileLib/QTAtom_tkhd.cpp
        QTFileLib/QTAtom_tref.cpp
        QTFileLib/QTFile.cpp
        QTFileLib/QTFile_FileControlBlock.cpp
        QTFileLib/QTHintTrack.cpp
        QTFileLib/QTRTPFile.cpp
        QTFileLib/QTTrack.cpp
        RTCPUtilitiesLib/RTCPAPPNADUPacket.cpp
        RTCPUtilitiesLib/RTCPAPPPacket.cpp
        RTCPUtilitiesLib/RTCPAPPQTSSPacket.cpp
        RTCPUtilitiesLib/RTCPAckPacket.cpp
        RTCPUtilitiesLib/RTCPPacket.cpp
        RTCPUtilitiesLib/RTCPSRPacket.cpp
        RTPMetaInfoLib/RTPMetaInfoPacket.cpp
        Server.tproj/GenerateXMLPrefs.cpp
        Server.tproj/HTTPSession.cpp
        Server.tproj/HTTPSessionInterface.cpp
        Server.tproj/QTSSCallbacks.cpp
        Server.tproj/QTSSDataConverter.cpp
        Server.tproj/QTSSDictionary.cpp
        Server.tproj/QTSSErrorLogModule.cpp
        Server.tproj/QTSSExpirationDate.cpp
        Server.tproj/QTSSFile.cpp
        Server.tproj/QTSSMessages.cpp
        Server.tproj/QTSSModule.cpp
        Server.tproj/QTSSPrefs.cpp
        Server.tproj/QTSSSocket.cpp
        Server.tproj/QTSSUserProfile.cpp
        Server.tproj/QTSServer.cpp
        Server.tproj/QTSServerInterface.cpp
        Server.tproj/QTSServerPrefs.cpp
        Server.tproj/RTCPTask.cpp
        Server.tproj/RTPBandwidthTracker.cpp
        Server.tproj/RTPOverbufferWindow.cpp
        Server.tproj/RTPPacketResender.cpp
        Server.tproj/RTPSession.cpp
        Server.tproj/RTPSessionInterface.cpp
        Server.tproj/RTPStream.cpp
        Server.tproj/RTSPRequest.cpp
        Server.tproj/RTSPRequestInterface.cpp
        Server.tproj/RTSPRequestStream.cpp
        Server.tproj/RTSPResponseStream.cpp
        Server.tproj/RTSPSession.cpp
        Server.tproj/RTSPSessionInterface.cpp
        Server.tproj/RunServer.cpp
        Server.tproj/main.cpp)

add_executable(easydarwin ${SOURCE_FILES})
target_link_libraries(easydarwin
        PRIVATE CommonUtilitiesLib
		PRIVATE EasyProtocol
		PRIVATE jsoncpp
		PRIVATE easyredisclient
		PRIVATE pthread
		PRIVATE dl
		PRIVATE stdc++
		PRIVATE m
		PRIVATE crypt)



