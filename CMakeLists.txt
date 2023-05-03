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

include(FetchContent)

add_executable(${PROJECT_NAME})

if(UNIX)
    target_compile_options(${PROJECT_NAME} PRIVATE -W -Wall -Wextra -Werror)
elseif(WIN32)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
endif()

##################### libconfig++ ##########################

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(DBUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(DBUILD_TESTS OFF CACHE BOOL "" FORCE)
set(BUILD_SHARED_LIBS ON CACHE BOOL "" FORCE)
set(BUILD_STATIC_LIBS OFF CACHE BOOL "" FORCE)
set(DBUILD_SHARED_LIBS ON CACHE BOOL "" FORCE)
FetchContent_Declare(
    libconfig++
    GIT_REPOSITORY https://github.com/hyperrealm/libconfig.git
    GIT_TAG v1.7.3
)
FetchContent_MakeAvailable(libconfig++)

include_directories(${libconfig_SOURCE_DIR}/lib)

##################### SFML ################################

if (WIN32)
    set(SFML_BUILD_WINDOW TRUE)
    set(SFML_BUILD_GRAPHICS TRUE)
    set(SFML_BUILD_AUDIO FALSE)
    set(SFML_BUILD_NETWORK FALSE)
    set(SFML_BUILD_EXAMPLES FALSE)
    set(SFML_BUILD_SYSTEM FALSE)
    set(SFML_BUILD_DOC FALSE)
    set(SFML_BUILD_SYSTEM FALSE)
    set(SFML_USE_STATIC_STD_LIBS FALSE)
    FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.5.1
    )
    FetchContent_MakeAvailable(SFML)
endif()

##################### INCLUDE #############################

include_directories(${libconfig_SOURCE_DIR}/lib)

if (WIN32)
    target_link_libraries(
        ${PROJECT_NAME}
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/libconfig++.lib
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/libconfig++.lib
        sfml-graphics
        sfml-window
    )
elseif (UNIX)
    find_package(SFML 2.5 COMPONENTS graphics window REQUIRED)
    target_link_libraries(
        ${PROJECT_NAME}
        PRIVATE
        sfml-graphics
        sfml-window
        config++
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
