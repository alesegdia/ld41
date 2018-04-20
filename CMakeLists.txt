cmake_minimum_required(VERSION 2.8.11)

project(ld41)

include(module/aether/cmake/Build.cmake)

ADD_AETHER_TARGET(aether-input-example src/main.cpp)

