CXXFLAGS = --std=c++17

average: main.o average.o
	$(CXX) $(CXXFLAGS) main.o average.o -o average
main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o
average.o: average.cpp
	$(CXX) $(CXXFLAGS) -c average.cpp -o average.o
clean:
	rm -f *.o *.gch ~* a.out average
