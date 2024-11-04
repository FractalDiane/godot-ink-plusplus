cmake_minimum_required(VERSION 3.24)

project(ink_cpp_plugin)
set(CMAKE_CXX_STANDARD 23)

include(${CMAKE_SOURCE_DIR}/config.cmake)
string(TOLOWER ${CMAKE_BUILD_TYPE} build_type)

set(SOURCES
	src/ink_plugin.cpp
	src/ink_story.cpp
	src/ink_compiler_gd.cpp
	src/ink_story_compiled.cpp
	src/ink_gd_utils.cpp
)

if(WIN32)
	add_compile_definitions(TYPED_METHOD_BIND NOMINMAX)
endif()

if(CMAKE_BUILD_TYPE EQUAL Debug)
	add_compile_definitions(DEBUG_ENABLED DEBUG_METHODS_ENABLED)
endif()

add_library(ink_cpp SHARED register_types.cpp ${SOURCES})
target_link_libraries(ink_cpp PUBLIC ${INK_CPP_DIR}/build/ink_backend.lib)
target_link_libraries(ink_cpp PUBLIC ${INK_CPP_DIR}/build/ink_compiler.lib)
target_link_libraries(ink_cpp PUBLIC ${GDEXTENSION_DIR}/.build/bin/godot-cpp.windows.${build_type}.64.lib)

include_directories(
	${CMAKE_SOURCE_DIR}/include/
)

include_directories(
	${GDEXTENSION_DIR}/gdextension/
	${GDEXTENSION_DIR}/include/
	${GDEXTENSION_DIR}/gen/include/

	${INK_CPP_DIR}/include/
)

add_custom_command(TARGET ink_cpp POST_BUILD
	COMMAND ${CMAKE_COMMAND} ARGS -E copy $<TARGET_FILE:ink_cpp> ${OUTPUT_LIBRARY_DIR}
)
