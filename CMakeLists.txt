cmake_minimum_required(VERSION 3.23)
project(Puissance4)

set(CMAKE_CXX_STANDARD 20)

add_executable(Puissance4 main.cpp affichage.cpp affichage.h moteurJeuPuissance4.cpp moteurJeuPuissance4.h jeuPuissance4.cpp jeuPuissance4.h util.cpp util.h)
