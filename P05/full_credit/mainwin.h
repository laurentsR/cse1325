#ifndef MAINWIN_H
#define MAINWIN_H

#include <gtkmm.h>
#include "store.h"

class Mainwin : public Gtk::Window {
    public:
        Mainwin();
        Mainwin(Store& store);
        virtual ~Mainwin();
        
    protected:
    	void on_label_click();
    	void on_quit_click();
    	void on_new_store_click();
    	void on_add_sweets_click();
    	void on_list_sweets_click();
    	void on_help_click();

    private:
        Store *_store;
        Gtk::Label* label;
        Gtk::MenuBar* menuBar;
        Gtk::Menu* fileMenu;
        Gtk::Menu* sweetsMenu;
        Gtk::Menu* helpMenu;
        Gtk::MenuItem* File;
        Gtk::MenuItem* Quit;
        Gtk::MenuItem* New;
        Gtk::MenuItem* Sweets;
        Gtk::MenuItem* addItem;
        Gtk::Entry* entry;
        Gtk::Entry* entry2;
        Gtk::MenuItem* list;
        Gtk::MenuItem* help;
        Gtk::MenuItem* about;

    // Lots more Mainwin members are needed!
    // (You ARE permitted to change the above as well if you like.)
};
#endif 

