cmake_minimum_required(VERSION 3.20)
project(Google_tests)

add_subdirectory(movie_tests)

include(FetchContent)
FetchContent_Declare(
        lib
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/master.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(lib)

set(CMAKE_CXX_STANDARD 17)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR}})

