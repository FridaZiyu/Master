CXX = g++
CXXOPTS = -Wall -std=c++11 -O3 
INCOPENBLAS= -I./install/include/
INC=$(INCOPENBLAS) -I./
LIBBLAS= -L./install/lib/ -lopenblas -lgfortran

all: main

Matrix.o: Matrix.cpp Matrix.hpp
		$(CXX) $(CXXOPTS) -c Matrix.cpp $(INC)
		
main.o: main.cpp Matrix.hpp
		$(CXX) $(CXXOPTS) -c main.cpp $(INC)
		
main: Matrix.o main.o
		$(CXX) $(CXXOPTS) -o main main.o Matrix.o $(LIBBLAS)
		
clean:
		rm -f *.o
		rm -f main