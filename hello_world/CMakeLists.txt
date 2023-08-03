
cmake_minimum_required(VERSION 2.8)
set (CMAKE_CXX_STANDARD 14)

project (hello_world)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

if ( NOT WIN32 OR CYGWIN )
    set(CMAKE_CXX_FLAGS_DEBUG "-g")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3")
endif ( )

execute_process(
    COMMAND node -p "require('puerts').include_dir"
    OUTPUT_VARIABLE PUERTS_INCLUDE
    OUTPUT_STRIP_TRAILING_WHITESPACE
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
string(REPLACE "\\" "/" PUERTS_INCLUDE ${PUERTS_INCLUDE})

execute_process(
    COMMAND node -p "require('puerts').src_dir"
    OUTPUT_VARIABLE PUERTS_SRC
    OUTPUT_STRIP_TRAILING_WHITESPACE
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
string(REPLACE "\\" "/" PUERTS_SRC ${PUERTS_SRC})

file(GLOB SOURCE_FILES "src/hello_world.cc")

include_directories(
    ${PUERTS_INCLUDE}
    "src"
)

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES} ${PUERTS_SRC}/pesapi_adpt.c)

target_compile_definitions (${PROJECT_NAME} PRIVATE BUILDING_PES_EXTENSION) 
set_target_properties(${PROJECT_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

