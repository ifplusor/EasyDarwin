

include_directories(include)

set(OBJECTFILES
		src/lib_json/json_reader.cpp
		src/lib_json/json_value.cpp
		src/lib_json/json_writer.cpp)

add_library(jsoncpp STATIC ${OBJECTFILES})

