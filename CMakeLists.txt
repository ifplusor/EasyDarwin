cmake_minimum_required(VERSION 2.8)
project(EasyDarwin)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CND_PLATFORM GNU-Linux)
set(CND_DLIB_EXT so)
set(CND_CONF x64)
set(CND_DISTDIR dist)
set(CND_BUILDDIR build)

set(OBJECTDIR ${PROJECT_BINARY_DIR}/${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM})
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/${CND_CONF})
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/${CND_CONF})

add_definitions(-D__SOURCE_READER__)

add_compile_options(-O2)

add_subdirectory(CommonUtilitiesLib)
add_subdirectory(EasyRedisClient)
add_subdirectory(EasyProtocol)
add_subdirectory(EasyDarwin)
