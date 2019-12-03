#ifndef __MAINWIN_H
#define __MAINWIN_H

#include <gtkmm.h>
#include "shelter.h"

const std::string APP_TITLE{"Pawsome Pals"};
const std::string APP_NAME{"edu.uta.cse1325.mass.v0_1_0"};
const std::string VERSION{"0.1.0"};
const std::string COOKIE{"M⅍S1"};

class Mainwin : public Gtk::Window {
    public:
        Mainwin();
        virtual ~Mainwin();
    protected:
        void on_quit_click();              // Exit the application
        void on_new_dog_click();
        void on_new_cat_click(); 
        void on_new_rabbit_click();         // Create a new animal
        void on_list_animals_click();      // List all animals
        void on_new_client_click();
        void on_list_clients_click();
        void on_adopt_click();
        void on_list_adopted_click();
        void on_refresh_click();
        void on_save_click();
        void on_save_as_click();
        void on_open_click();
        void on_new_click();
        void on_about_click();
		void on_properties_click();

        void status(std::string s);        // Set the status message
    private:
        Shelter *shelter;                  // Current animal shelter
        Gtk::Label *data;                  // Display of sticks on game board
        Gtk::Label *msg;  				   // Status message display
        Gtk::Label *adoptions;
        Gtk::Label *clients;  
        Gtk::Label *clientsList; 
        Gtk::Label *adopted;
        Gtk::Label *adoptedList;         
        
        Gtk::ToolButton* add_dog_button;
        Gtk::ToolButton* add_cat_button;
        Gtk::ToolButton* add_rabbit_button;
        Gtk::ToolButton* add_client_button;
        Gtk::ToolButton* refresh_button;
        Gtk::ToolButton* adoption_button;
        Gtk::ToolButton* save_button;
        Gtk::ToolButton* open_button;
};
#endif 

