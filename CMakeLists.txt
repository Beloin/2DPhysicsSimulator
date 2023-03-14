cmake_minimum_required(VERSION 3.24)
project(2d_physics C)

set(CMAKE_C_STANDARD 11)

add_executable(
        2d_physics
        particles/particle.c
        rigid_body.c vector2.h
        interface/interface.c particle_utils.h
        particles/particle.h
        interface/interface.h
        main.c
)

find_library(MATH_LIBRARY m)
if(MATH_LIBRARY)
    target_link_libraries(2d_physics PUBLIC ${MATH_LIBRARY})
endif()