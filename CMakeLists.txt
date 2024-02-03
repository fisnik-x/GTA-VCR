# Top Level CMakeLists.txt
cmake_minimum_required(VERSION 3.27)
project(GTAVCR VERSION 0.0 DESCRIPTION "GTA Vice City Radio" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

if(MSVC)
    add_compile_options(/EHsc /Za /Wall /WX)
else()
    add_compile_options(
        -std=c++17 
        -D_GLIBCXX_USE_CXX11_ABI=0 
        )
endif()

if(WIN32)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
endif()

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/third-party/SDL/")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/third-party/SDL/include")

#find_package(FMOD MODULE REQUIRED)
find_package(SDL3 REQUIRED)

set(SOURCES src/main.cpp src/ViceCityRadio.cpp)
add_executable(VCR ${SOURCES})
#target_include_directories(VCR PUBLIC ${FMOD_INCLUDE_DIR} include)
#target_link_libraries(VCR ${FMOD_LIBRARY_LIB})
target_include_directories(VCR 
    PUBLIC ${SDL3_INCLUDE_DIRS}
)

target_link_libraries(
    VCR 
    PUBLIC 
    ${SDL3_LIBRARIES} SDL3::SDL3 mingw32)