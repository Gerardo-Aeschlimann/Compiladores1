cmake_minimum_required(VERSION 3.15)
project(Lexer1) # Nombre del Projecto
include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 17) # Decirle a CMAKE que busque un compilador que soporte este estandar
set(CMAKE_CXX_STANDARD_REQUIRED ON) # Enforzar el estandar

add_executable(Lexer1 Main.cpp Lexer.cpp Lexer.hpp PrintTokens.hpp)
