cmake_minimum_required(VERSION 3.23)
project(TP6_RFM C)

set(CMAKE_C_STANDARD 99)

add_executable(TP6_RFM main.c fulkerson/fulkerson.h graphe/graphe.h graphe/graphe.c fulkerson/fulkerson.c fifo/fifo.c)