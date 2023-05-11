cmake_minimum_required(VERSION 3.25)

target_include_directories(raytracer PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_sources(raytracer PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/App.cpp"
)

add_subdirectory(App)
add_subdirectory(Transformable)
add_subdirectory(Scene)
add_subdirectory(Raytracer)
add_subdirectory(Display)
add_subdirectory(Material)
add_subdirectory(Transformation)
