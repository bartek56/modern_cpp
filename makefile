SOURCE= main.cpp Circle.cpp Rectangle.cpp Shape.cpp Square.cpp 
SOURCEH= Circle.hpp Rectangle.hpp Shape.hpp Square.hpp
FLAGS= --std=c++14 -Wall


all:
	g++ $(SOURCE) $(SOURCEH) -o main $(FLAGS)
   
