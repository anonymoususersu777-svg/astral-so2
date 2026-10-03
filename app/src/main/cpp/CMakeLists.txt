cmake_minimum_required(VERSION 3.18)
project(astral CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(astral SHARED
    main.cpp
    overlay.cpp
    esp.cpp
    aimbot.cpp
    rage.cpp)

find_library(log-lib log)
find_library(glesv2-lib GLESv2)
find_library(egl-lib EGL)
find_library(android-lib android)

target_link_libraries(astral
    ${log-lib}
    ${glesv2-lib}
    ${egl-lib}
    ${android-lib})
