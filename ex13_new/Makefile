CXX = g++
CXXOPTS = -Wall -std=c++11 -O3 
INCOPENBLAS= -I./install/include/
INC=$(INCOPENBLAS) -I./include
LIBBLAS= -L./install/lib/ -lopenblas -lgfortran

all: bin/observ  bin/simulate  bin/estimate  bin/verify

obj/Matrix.o: src/Matrix.cpp include/Matrix.hpp
		$(CXX) $(CXXOPTS) -c src/Matrix.cpp $(INC) -o obj/Matrix.o
		
obj/Fourierseries.o: src/Fourierseries.cpp include/Fourierseries.hpp include/Matrix.hpp
		$(CXX) $(CXXOPTS) -c src/Fourierseries.cpp $(INC) -o obj/Fourierseries.o
		
obj/observ.o:src/observ.cpp include/Matrix.hpp
		$(CXX) $(CXXOPTS) -c src/observ.cpp $(INC) -o obj/observ.o
		
obj/simulate.o:	src/simulate.cpp include/Matrix.hpp include/Fourierseries.hpp
		$(CXX) $(CXXOPTS) -c src/simulate.cpp $(INC) -o obj/simulate.o
		
obj/estimate.o: src/estimate.cpp include/Matrix.hpp include/Fourierseries.hpp
		$(CXX) $(CXXOPTS) -c src/estimate.cpp $(INC) -o obj/estimate.o
		
obj/verify.o: src/verify.cpp include/Matrix.hpp
		$(CXX) $(CXXOPTS) -c src/verify.cpp $(INC) -o obj/verify.o

bin/observ: obj/Matrix.o obj/observ.o
		$(CXX) $(CXXOPTS) -o bin/observ obj/observ.o obj/Matrix.o $(LIBBLAS)	

bin/simulate: obj/Matrix.o obj/Fourierseries.o obj/simulate.o
		$(CXX) $(CXXOPTS) -o bin/simulate obj/simulate.o obj/Matrix.o obj/Fourierseries.o $(LIBBLAS)

bin/estimate: obj/Matrix.o obj/Fourierseries.o obj/estimate.o
		$(CXX) $(CXXOPTS) -o bin/estimate obj/estimate.o obj/Matrix.o obj/Fourierseries.o $(LIBBLAS)
		
bin/verify: obj/Matrix.o obj/verify.o
		$(CXX) $(CXXOPTS) -o bin/verify obj/verify.o obj/Matrix.o $(LIBBLAS)
		
clean:
		rm -f obj/*.o bin/* 