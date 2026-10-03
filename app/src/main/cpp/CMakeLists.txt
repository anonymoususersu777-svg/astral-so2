cmake_minimum_required(VERSION 3.18)
project(astral)

add_library(astral SHARED
    main.cpp overlay.cpp esp.cpp aimbot.cpp rage.cpp)

find_library(log-lib log)
target_link_libraries(astral ${log-lib} android)
