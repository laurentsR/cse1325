CXXFLAGS = --std=c++17

train: main.o train.o coach.cpp locomotive.cpp stock.cpp
	$(CXX) $(CXXFLAGS) main.o train.o -o train
main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o
train.o: train.cpp
	$(CXX) $(CXXFLAGS) -c train.cpp -o train.o
coach.cpp:
	$(CXX) $(CXXFLAGS) -c coach.cpp
locomotive.cpp:
	$(CXX) $(CXXFLAGS) -c locomotive.cpp
stock.cpp:
	$(CXX) $(CXXFLAGS) -c stock.cpp
clean:
	rm -f *.o *.gch ~* a.out train
