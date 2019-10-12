all : AngleEstimation


AngleEstimation: main.cpp line.hpp
	g++ -o AngleEstimation main.cpp line.hpp
