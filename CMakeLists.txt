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
    include(FetchContent)
endif()

add_executable(${PROJECT_NAME})

##################### LIBCONFIG++ ##########################

if (WIN32)
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
    set(BUILD_SHARED_LIBS OFF)
    set(SFML_BUILD_EXAMPLES OFF)
    set(SFML_BUILD_DOC OFF)
    set(SFML_BUILD_AUDIO OFF)
    set(SFML_BUILD_NETWORK OFF)
    set(SFML_BUILD_WINDOW ON)
    set(SFML_BUILD_GRAPHICS ON)
    set(SFML_BUILD_SYSTEM OFF)
    FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.5.1
    )
    FetchContent_MakeAvailable(SFML)
endif()

##################### INCLUDE #############################

if (linux)
    find_package(SFML 2.5 COMPONENTS graphics REQUIRED)
    target_link_libraries(
        ${PROJECT_NAME}
        PRIVATE
        sfml-graphics
        config++
    )
elseif (WIN32)
    target_link_libraries(
        ${PROJECT_NAME}
        PRIVATE
        libconfig++
        sfml-graphics
    )
endif()

##################### SRC #################################

add_subdirectory(src)

##################### CUSTOM CMD ##########################

add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${PROJECT_NAME}> ${CMAKE_CURRENT_SOURCE_DIR}
)
