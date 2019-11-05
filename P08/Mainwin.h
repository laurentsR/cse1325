#ifndef MAINWIN_H
#define MAINWIN_H

#include <gtkmm.h>
#include "Shelter.h"

const std::string APP_NAME{"edu.uta.cse1325.animals.v0_1_0"};

class Mainwin : public Gtk::Window
{
    public:
        Mainwin();
        virtual ~Mainwin();
        
    protected:
    	void on_quit_click();
    	void on_new_animal_click();
    	void on_list_animals_click();
    	
    private:
    	Shelter *_shelter;
    	Gtk::Label* data;
    	Gtk::Label* msg;
    	
    	
    	// Menu items
        Gtk::MenuItem *menuitem_add_animal;    // Animal > Add
        Gtk::MenuItem *menuitem_list_animals;
    	
};

#endif

