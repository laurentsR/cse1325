#include "mainwin.h"
#include <string.h>

Mainwin::Mainwin() : Mainwin{*(new Store)} { }
Mainwin::Mainwin(Store& store) 
:   _store{&store} ,
	label{Gtk::manage(new Gtk::Label{""})},
	menuBar{Gtk::manage(new Gtk::MenuBar())},
	fileMenu{Gtk::manage(new Gtk::Menu())},
	sweetsMenu{Gtk::manage(new Gtk::Menu())},
	helpMenu{Gtk::manage(new Gtk::Menu())},
	File{Gtk::manage(new Gtk::MenuItem("File"))},
	Quit{Gtk::manage(new Gtk::MenuItem("Quit"))},
	New{Gtk::manage(new Gtk::MenuItem("New"))},
	Sweets{Gtk::manage(new Gtk::MenuItem("Sweets"))},
	addItem{Gtk::manage(new Gtk::MenuItem("Add Item"))},
	entry{Gtk::manage(new Gtk::Entry())},
	entry2{Gtk::manage(new Gtk::Entry())},
	list{Gtk::manage(new Gtk::MenuItem("List"))},
	help{Gtk::manage(new Gtk::MenuItem("Help"))},
	about{Gtk::manage(new Gtk::MenuItem("About"))}
	
{

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    // Set up a vertical box to hold the main window elements
	set_title("MUSS");
    Gtk::VBox *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox);

    // ///////
    // M E N U
    // Add and configure a menu bar as the top item in the vertical box
    vbox->pack_start(*menuBar);
    menuBar->append(*File);
    File->set_submenu(*fileMenu);
    menuBar->append(*Sweets);
    Sweets->set_submenu(*sweetsMenu);
    menuBar->append(*help);
    help->set_submenu(*helpMenu);
    
    // FILE -> NEW
    fileMenu->append(*New);
    New->signal_activate().connect([this] {this->on_new_store_click();});
    // FILE -> QUIT
    fileMenu->append(*Quit);
    Quit->signal_activate().connect([this] {this->on_quit_click();});
    // SWEETS -> ADD ITEM
    sweetsMenu->append(*addItem);
    addItem->signal_activate().connect([this] {this->on_add_sweets_click();});
    // SWEETS -> LIST
 	sweetsMenu->append(*list);
 	//list->signal_activate().connect([this] {this->on_list_sweets_click();});
 	// HELP -> ABOUT
 	helpMenu->append(*about);
 	about->signal_activate().connect([this] {this->on_help_click();});

    // /////////////
    // T O O L B A R
    // Add a toolbar to the vertical box just below the menu (bonus level)



    // ///////////////////////
    // D A T A   D I S P L A Y
    // Provide a text entry box to show the sweets and orders
	vbox->pack_start(*label);


    // ///////////////////////////////////    
    // S T A T U S   B A R   D I S P L A Y
    // Provide a status bar for transient messages


    // Make the vertical box and everything in it visible
	vbox->show_all();
}

Mainwin::~Mainwin() { }

// /////////////////
// C A L L B A C K S
// /////////////////

void Mainwin::on_quit_click()
{
	this->close();
}

void Mainwin::on_new_store_click()
{
	Store* newStore = new Store();
}

void Mainwin::on_add_sweets_click()
{
    Gtk::MessageDialog getName(*this, "Please enter the Sweet name below");
	entry = Mainwin::entry;
	entry2 = Mainwin::entry;
	std::string name, price;
	double priceNum;
	// NAME
	entry->set_text("");
	entry->show();
	getName.get_vbox()->pack_start(*entry);
	getName.run();
	name = entry->get_text();
	getName.get_vbox()->remove(*entry);
	// PRICE
	Gtk::MessageDialog getPrice(*this, "Please enter the price of one " + name + " below.");
	entry2->set_text("");
	entry2->show();
	getPrice.get_vbox()->add(*entry2);
	getPrice.run();
	price = entry2->get_text();
	priceNum = std::stoi(price);
	
	Sweet* newSweet = new Sweet(name, priceNum);
	Sweet& newSweetRef = *newSweet;
	_store->add (newSweetRef);
	
}
/*
void Mainwin::on_list_sweets_click()
{
	int x;
	int num = Store->num_sweets();
	std::ostream& list = "";
	char* s;
	for(x = 0; x < num; x++)
	{
		s += list<<(list, _sweets[x]) + "\n";
	}
	Mainwin::label->set_text(s);
}
*/

void Mainwin::on_help_click()
{
	Gtk::MessageDialog about(*this, "About");
	about.set_secondary_text("Created by Ryan Laurents for CSE 1325 at UT Arlington - 10/13/2019\n\nCredit to StackOverflow for the countless hours spent contemplating my life choices.\n\nLicense Attributations:\nGNU General Public License\ngtkmm is licensed under the GNU Library General Public License (LGPL)");
	about.run();
}

// /////////////////
// U T I L I T I E S
// /////////////////


