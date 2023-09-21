cmake_minimum_required(VERSION 3.24)
project(ProjetFauves)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(ProjetFauves
        include/entitee.h
        include/joueur.h
        include/partieJeu.h
        include/piege.h
        src/entitee.cpp
        src/joueur.cpp
        src/partieJeu.cpp
        src/piege.cpp main.cpp include/terrain.h src/terrain.cpp include/lion.h include/tigre.h src/lion.cpp src/tigre.cpp)
