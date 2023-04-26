cmake_minimum_required(VERSION 3.25)

target_include_directories(raytracer PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_sources(raytracer PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/ATransformable.cpp"
)

add_subdirectory(Camera)
add_subdirectory(Light)
add_subdirectory(Primitive)
