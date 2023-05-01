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
target_link_libraries(${PROJECT_NAME} ${CMAKE_DL_LIBS} config++)

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)
target_link_libraries(raytracer sfml-graphics)

##################### CUSTUM CMD ##########################

add_custom_command(
    TARGET raytracer
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:raytracer> ${CMAKE_CURRENT_SOURCE_DIR}
)

add_subdirectory(src)
