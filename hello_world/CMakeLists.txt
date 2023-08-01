
cmake_minimum_required(VERSION 2.8)
set (CMAKE_CXX_STANDARD 14)

project (hello_world)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(PUERTS_LIB_ROOT ../puerts_libs)
set(PUERTS_INCLUDE ${PUERTS_LIB_ROOT}/include)
set(PUERTS_SRC ${PUERTS_LIB_ROOT}/src)

file(GLOB SOURCE_FILES "src/hello_world.cc")

include_directories(
    ${PUERTS_INCLUDE}
    "src"
)

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES} ${PUERTS_SRC}/pesapi_adpt.c)

target_compile_definitions (${PROJECT_NAME} PRIVATE BUILDING_PES_EXTENSION) 
set_target_properties(${PROJECT_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

