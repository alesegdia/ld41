cmake_minimum_required(VERSION 2.8.11)

project(ld41)

include(module/aether/cmake/Build.cmake)
message(${CMAKE_CXX_FLAGS})

file(GLOB_RECURSE GAMESOURCES "src/*.cpp" "src/*.h")
ADD_AETHER_TARGET(drake "${GAMESOURCES}")

