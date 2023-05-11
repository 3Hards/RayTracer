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
set(LIBDIR ${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/lib)

add_executable(${PROJECT_NAME})

if(UNIX)
    target_compile_options(${PROJECT_NAME} PRIVATE -W -Wall -Wextra -Werror)
elseif(WIN32)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
endif()

##################### lib ##########################

if (WIN32)
    
    include(ExternalProject)

    include("Dependencies/build-libconfig.cmake")
    include("Dependencies/build-SFML.cmake")

    target_include_directories(
        ${PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/lib/include
    )

    target_link_libraries(${PROJECT_NAME} PRIVATE
        ${LIBDIR}/lib/libconfig.lib
        ${LIBDIR}/lib/libconfig++.lib
        ${LIBDIR}/lib/sfml-graphics-d.lib
        ${LIBDIR}/lib/sfml-window-d.lib
        ${LIBDIR}/lib/sfml-system-d.lib
    )

else()

    find_library(SFML_GRAPHICS sfml-graphics)
    find_library(LIBCONFIG++ libconfig++)

    target_link_libraries(${PROJECT_NAME} PRIVATE
        config++
        sfml-graphics
        sfml-window
        sfml-system
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

if (WIN32)

    add_custom_command(
        TARGET ${PROJECT_NAME}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${LIBDIR}/bin ${CMAKE_CURRENT_SOURCE_DIR}
    )

endif()
