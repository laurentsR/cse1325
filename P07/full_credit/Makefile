CXXFLAGS += -std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: widgets

widgets: main.cpp mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) main.cpp mainwin.cpp $(GTKFLAGS) -o widgets
clean:
	rm -f *.o *.gch widgets
