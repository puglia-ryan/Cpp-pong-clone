cmake_minimum_required(VERSION 3.10)
project(CppPongClone)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# automatically pick up all .cpp files under src/
file(GLOB_RECURSE SOURCE_FILES
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

add_executable(game ${SOURCE_FILES})
target_link_libraries(game PRIVATE sfml-graphics sfml-window sfml-system)

