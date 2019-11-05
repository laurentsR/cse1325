CXXFLAGS += --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: animals

bonus: CXXFLAGS += -D__SENSITIVITY1 -D__TOOLBAR -D__RICHTEXT
bonus: sweets

xbonus: CXXFLAGS += -D__SENSITIVITY1 -D__TOOLBAR -D__RICHTEXT -D__SWEETSADDDLG -D__STATUSBAR
xbonus: sweets

animals: Main-gui.o Mainwin.o entrydialog.o Animal.o Dog.o Shelter.o *.h
	$(CXX) $(CXXFLAGS) Main-gui.o Mainwin.o Animal.o Dog.o Shelter.o $(GTKFLAGS) -o animals
Main-gui.o: Main-gui.cpp *.h
	$(CXX) $(CXXFLAGS) -c Main-gui.cpp $(GTKFLAGS) -o Main-gui.o
Mainwin.o: Mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) -c Mainwin.cpp $(GTKFLAGS) -o Mainwin.o
entrydialog.o: entrydialog.cpp *.h
	$(CXX) $(CXXFLAGS) -c entrydialog.cpp $(GTKFLAGS) -o entrydialog.o
Animal.o: Animal.cpp *.h
	$(CXX) $(CXXFLAGS) -c Animal.cpp -o Animal.o
Dog.o: Dog.cpp *.h
	$(CXX) $(CXXFLAGS) -c Dog.cpp -o Dog.o
Shelter.o: Shelter.cpp *.h
	$(CXX) $(CXXFLAGS) -c Shelter.cpp -o Shelter.o
clean:
	rm -f *.o *.gch *.ii *.s a.out animals

