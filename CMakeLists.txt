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

##################### PLUGINS #################################

add_library(primiZizi SHARED
    ${CMAKE_CURRENT_SOURCE_DIR}/plugins/primiZIZI/PrimiZizi.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/plugins/primiZIZI/api.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Material/AMaterial.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Material/FlatColor.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Raytracer/Vector.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Transformable/ATransformable.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Transformable/Camera/Camera.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Transformable/Camera/Matrix3D.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Transformable/Light/ALight.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Transformable/Light/Ambient.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Transformable/Light/Directional.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Transformable/Primitive/APrimitive.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Transformable/Primitive/Plane.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Transformable/Primitive/Sphere.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Transformation/Rotation.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Transformation/Translation.cpp
)

target_include_directories(primiZizi PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/plugins/primiZIZI
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Display
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Material
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Raytracer
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Transformable
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Transformable/Camera
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Transformable/Light
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Transformable/Primitive
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Transformation
)

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

add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:primiZizi> ${CMAKE_CURRENT_SOURCE_DIR}/plugins
)

if (WIN32)

    add_custom_command(
        TARGET ${PROJECT_NAME}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${LIBDIR}/bin ${CMAKE_CURRENT_SOURCE_DIR}
    )

endif()
