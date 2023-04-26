cmake_minimum_required(VERSION 3.25)

set(PROJECT_NAME raytracer)

project(
    ${PROJECT_NAME}
    VERSION 1.0
    DESCRIPTION "Tek2 | OOP | Raytracer"
    LANGUAGES CXX
)

##################### CMAKE OPTIONS #######################

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

if(UNIX)
    add_compile_options(-Wall -Wextra -Werror)
elseif(WIN32)
    add_compile_options(/W4)
endif()

add_executable(${PROJECT_NAME})

##################### LIBCONFIG++ ##########################

if (UNIX)
    add_executable(${PROJECT_NAME})
    target_link_libraries(${PROJECT_NAME} ${CMAKE_DL_LIBS} config++)
elseif (WIN32)
    include(FetchContent)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    set(BUILD_TESTS OFF CACHE BOOL "" FORCE)
    set(DBUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    set(DBUILD_TESTS OFF CACHE BOOL "" FORCE)
    FetchContent_Declare(
      libconfig
      URL https://github.com/hyperrealm/libconfig/archive/v1.7.3.tar.gz
      CMAKE_ARGS
        -DCMAKE_BUILD_TYPE=Release
        -DCMAKE_GENERATOR_PLATFORM=x64
        -DCMAKE_CXX_STANDARD=20
    )
    FetchContent_GetProperties(libconfig)
    if(NOT libconfig_POPULATED)
      FetchContent_Populate(libconfig)
      add_subdirectory(${libconfig_SOURCE_DIR} ${libconfig_BINARY_DIR})
    endif()
endif()

##################### SFML ################################

if (WIN32)
    set(SFML_STATIC_LIBRARIES FALSE)
    set(SFML_DIR "${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.5.1/lib/cmake/SFML/")
    
    include(FetchContent)
    FetchContent_Declare(
        sfml
        URL "https://www.sfml-dev.org/files/SFML-2.5.1-windows-vc15-64-bit.zip"
        SOURCE_DIR "${CMAKE_CURRENT_BINARY_DIR}/sfml-src"
    )
    FetchContent_GetProperties(sfml)
    if(NOT sfml_POPULATED)
        FetchContent_Populate(sfml)
    endif()
endif()

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

##################### INCLUDE #############################

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics libconfig++)
target_include_directories(${PROJECT_NAME} PRIVATE ${libconfig_SOURCE_DIR}/lib)

##################### SRC #################################

add_subdirectory(src)

##################### CUSTOM CMD ##########################

add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${PROJECT_NAME}> ${CMAKE_CURRENT_SOURCE_DIR}
)
