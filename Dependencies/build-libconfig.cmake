ExternalProject_Add(libconfig
    GIT_REPOSITORY "https://github.com/hyperrealm/libconfig.git"
    GIT_TAG "v1.7.2"

    LIST_SEPARATOR "|"
    CMAKE_ARGS 
        -DBUILD_TESTS=OFF
        -DBUILD_EXAMPLES=OFF
        -DBUILD_SHARED_LIBS=ON
        -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/lib
)
