cmake_minimum_required(VERSION 3.21)


find_program(CCACHE_PROGRAM ccache)
if(CCACHE_PROGRAM)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_PROGRAM}")
endif()

project(Project_Euler)

set(CMAKE_CXX_STANDARD 23)

find_package(fmt REQUIRED)

add_executable(Project_Euler Runner/ProjectEuler.cpp Solutions/Sol_1.cpp Solutions/Sol_2.cpp Solutions/Sol_5.cpp Solutions/Sol_3.cpp Solutions/Sol_4.cpp)
target_link_libraries(Project_Euler PRIVATE fmt::fmt)