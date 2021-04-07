cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_STANDARD 14)

include("cmake/HunterGate.cmake")

HunterGate(
        URL "https://github.com/cpp-pm/hunter/archive/v0.16.15.tar.gz"
        SHA1 "6974c2150fc0d3b09de3ad1efcbf15d360647ffa"
)

project(distribution)

hunter_add_package(Boost COMPONENTS program_options)
find_package(Boost CONFIG REQUIRED program_options)

add_executable(distribution main.cpp)

target_link_libraries(distribution PUBLIC Boost::program_options)