cmake_minimum_required(VERSION 3.25)

target_include_directories(raytracer PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_sources(raytracer PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/APrimitive.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Sphere.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Plane.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Cone.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Cylinder.cpp"
)
