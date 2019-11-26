#include "mainwin.h"
#include "dog.h"
#include "cat.cpp"
#include "rabbit.cpp"
#include "client.cpp"
#include <sstream>
#include <fstream>
#include <cstring>
#include <string>
#include <iostream>

Mainwin::Mainwin() : shelter{new Shelter{"Pawsome Pals"}} {

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(4096, 2160); // Woo! 4k "support" baby!
    set_title(APP_TITLE);

    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox);

    // ///////
    // M E N U
    // Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

    //     F I L E
    // Create a File menu and add to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);
    
    //		S A V E
    //Append save to File
    Gtk::MenuItem *menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save", true));
    menuitem_save->signal_activate().connect([this] {this->on_save_click();});
    filemenu->append(*menuitem_save);
    
    //		L O A D
    //Apppend load to file
    Gtk::MenuItem *menuitem_load = Gtk::manage(new Gtk::MenuItem("_Load", true));
    menuitem_load->signal_activate().connect([this] {this->on_load_click();});
    filemenu->append(*menuitem_load);

    //         Q U I T
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
    filemenu->append(*menuitem_quit);

    //     A N I M A L
    // Create an Animal menu and add to the menu bar
    Gtk::MenuItem *menuitem_animal = Gtk::manage(new Gtk::MenuItem("_Animal", true));
    menubar->append(*menuitem_animal);
    Gtk::Menu *animalmenu = Gtk::manage(new Gtk::Menu());
    menuitem_animal->set_submenu(*animalmenu);

    //           N E W  D O G
    // Append New to the Animal menu
    Gtk::MenuItem *menuitem_newdog = Gtk::manage(new Gtk::MenuItem("New _Dog", true));
    menuitem_newdog->signal_activate().connect([this] {this->on_new_dog_click();});
    animalmenu->append(*menuitem_newdog);
    
    //           N E W  C A T
    // Append New to the Animal menu
    Gtk::MenuItem *menuitem_newcat = Gtk::manage(new Gtk::MenuItem("New _Cat", true));
    menuitem_newcat->signal_activate().connect([this] {this->on_new_cat_click();});
    animalmenu->append(*menuitem_newcat);
    
    //           N E W  R A B B I T
    // Append New to the Animal menu
    Gtk::MenuItem *menuitem_newrabbit = Gtk::manage(new Gtk::MenuItem("New _Rabbit", true));
    menuitem_newrabbit->signal_activate().connect([this] {this->on_new_rabbit_click();});
    animalmenu->append(*menuitem_newrabbit);

    //           L I S T
    // Append List to the Animal menu
    Gtk::MenuItem *menuitem_listanimal = Gtk::manage(new Gtk::MenuItem("_List Animals", true));
    menuitem_listanimal->signal_activate().connect([this] {this->on_list_animals_click();});
    animalmenu->append(*menuitem_listanimal);
    
    //			L I S T  A D O P T E D
    //Append list adopted to both Clients and Animals
    Gtk::MenuItem *menuitem_listAdoptedA = Gtk::manage(new Gtk::MenuItem("_List Adopted", true));
    menuitem_listAdoptedA->signal_activate().connect([this] {this->on_list_adopted_click();});
    animalmenu->append(*menuitem_listAdoptedA);
    
    //     C L I E N T
    // Create a Client menu and add to the menu bar
    Gtk::MenuItem *menuitem_client = Gtk::manage(new Gtk::MenuItem("_Client", true));
    menubar->append(*menuitem_client);
    Gtk::Menu *clientmenu = Gtk::manage(new Gtk::Menu());
    menuitem_client->set_submenu(*clientmenu);
    
    //           N E W  C L I E N T
    // Append New to the Animal menu
    Gtk::MenuItem *menuitem_newclient = Gtk::manage(new Gtk::MenuItem("New _Client", true));
    menuitem_newclient->signal_activate().connect([this] {this->on_new_client_click();});
    clientmenu->append(*menuitem_newclient);
    
    //			L I S T  C L I E N T
    //Append List to Clients menu
	Gtk::MenuItem *menuitem_listclients = Gtk::manage(new Gtk::MenuItem("_List Clients", true));
    menuitem_listclients->signal_activate().connect([this] {this->on_list_clients_click();});
    clientmenu->append(*menuitem_listclients);
    
    //			A D O P T
    //Append Adopt to Clients menu
    Gtk::MenuItem *menuitem_adopt = Gtk::manage(new Gtk::MenuItem("_Adopt Animal", true));
    menuitem_adopt->signal_activate().connect([this] {this->on_adopt_click();});
    clientmenu->append(*menuitem_adopt);
    
    //			L I S T  A D O P T E D
    //Append list adopted to both Clients and Animals
    Gtk::MenuItem *menuitem_listAdopted = Gtk::manage(new Gtk::MenuItem("_List Adopted", true));
    menuitem_listAdopted->signal_activate().connect([this] {this->on_list_adopted_click();});
    clientmenu->append(*menuitem_listAdopted);
    
    
    
    // /////////////
    // T O O L B A R
    // Add a toolbar to the vertical box below the menu
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    toolbar->override_background_color(Gdk::RGBA{"orange"});
    toolbar->set_hexpand(true);
    vbox->pack_start(*toolbar, Gtk::PACK_SHRINK, 0);
    
    // A D D  D O G
    // Icon for add new dog
    Gtk::Image* add_dog_image = Gtk::manage(new Gtk::Image{"dog.png"});
    add_dog_button = Gtk::manage(new Gtk::ToolButton(*add_dog_image));
    add_dog_button->set_tooltip_markup("Add a new dog to the shelter");
    add_dog_button->signal_clicked().connect([this] {this->on_new_dog_click();});
    toolbar->append(*add_dog_button);
    
    // A D D  C A T
    // Icon for add new cat
    Gtk::Image* add_cat_image = Gtk::manage(new Gtk::Image{"cat.png"});
    add_cat_button = Gtk::manage(new Gtk::ToolButton(*add_cat_image));
    add_cat_button->set_tooltip_markup("Add a new cat to the shelter");
    add_cat_button->signal_clicked().connect([this] {this->on_new_cat_click();});
    toolbar->append(*add_cat_button);
    
    // A D D  R A B B I T
    // Icon for add new rabbit
    Gtk::Image* add_rabbit_image = Gtk::manage(new Gtk::Image{"rabbit.png"});
    add_rabbit_button = Gtk::manage(new Gtk::ToolButton(*add_rabbit_image));
    add_rabbit_button->set_tooltip_markup("Add a new rabbit to the shelter");
    add_rabbit_button->signal_clicked().connect([this] {this->on_new_rabbit_click();});
    toolbar->append(*add_rabbit_button);
    
    // A D D  C L I E N T
    // Icon for add new client
    Gtk::Image* add_client_image = Gtk::manage(new Gtk::Image{"add.png"});
    add_client_button = Gtk::manage(new Gtk::ToolButton(*add_client_image));
    add_client_button->set_tooltip_markup("Add a new client");
    add_client_button->signal_clicked().connect([this] {this->on_new_client_click();});
    toolbar->append(*add_client_button);
    
    // A D O P T
    //Icon for adoption
    Gtk::Image* adoption_image = Gtk::manage(new Gtk::Image{"adoption.png"});
    adoption_button = Gtk::manage(new Gtk::ToolButton(*adoption_image));
    adoption_button->set_tooltip_markup("Adopt!");
    adoption_button->signal_clicked().connect([this] {this->on_adopt_click();});
    toolbar->append(*adoption_button);
    
    // R E F R E S H
    //Icon for refreshing lists
    Gtk::Image* refresh_lists = Gtk::manage(new Gtk::Image{"reload.png"});
    refresh_button = Gtk::manage(new Gtk::ToolButton(*refresh_lists));
    refresh_button->set_tooltip_markup("Refresh Lists");
    refresh_button->signal_clicked().connect([this] {this->on_refresh_click();});
    toolbar->append(*refresh_button);
    
    // L O A D
    // Icon for load
    Gtk::Image* load = Gtk::manage(new Gtk::Image{"load.png"});
    load_button = Gtk::manage(new Gtk::ToolButton(*load));
    load_button->set_tooltip_markup("Load Existing Data");
    load_button->signal_clicked().connect([this] {this->on_load_click();});
    
    // S A V E
    // Icon for save
    Gtk::Image* save = Gtk::manage(new Gtk::Image{"save.png"});
    save_button = Gtk::manage(new Gtk::ToolButton(*save));
    save_button->set_tooltip_markup("Save Data");
    save_button->signal_clicked().connect([this] {this->on_save_click();});
    
    // Q U I T
    // Icon for quit
    Gtk::ToolButton *quit_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::QUIT));
    quit_button->set_tooltip_markup("Exit");
    quit_button->signal_clicked().connect([this] {this->on_quit_click();});
    Gtk::SeparatorToolItem *sep = Gtk::manage(new Gtk::SeparatorToolItem());
    sep->set_expand(true);  // The expanding sep forces the Quit button to the right
    toolbar->append(*sep);
    toolbar->append(*load_button);
    toolbar->append(*save_button);
    toolbar->append(*quit_button);
    
    //
    //	ICONS MADE BY FLATICON.COM
    //
    

    // ///////////////////////
    // D A T A   D I S P L A Y
    //Adoption Options
    Gtk::Box *hboxLabels = Gtk::manage(new Gtk::HBox);
    adoptions = Gtk::manage(new Gtk::Label());
    adoptions->set_hexpand(true);
    adoptions->set_text("Adoption Options");
    hboxLabels->pack_start(*adoptions, Gtk::PACK_SHRINK, 0);
    //Clients
    clients = Gtk::manage(new Gtk::Label());
    clients->set_hexpand(true);
    clients->set_text("Clients");
    hboxLabels->pack_start(*clients, Gtk::PACK_SHRINK, 0);
    //Adopted
    adopted = Gtk::manage(new Gtk::Label());
    adopted->set_hexpand(true);
    adopted->set_text("Adopted!");
    hboxLabels->pack_start(*adopted, Gtk::PACK_SHRINK, 0);
    //Add all to vbox
    hboxLabels->override_background_color(Gdk::RGBA{"light grey"});
    vbox->pack_start(*hboxLabels, Gtk::PACK_SHRINK, 0);
    
    // Provide a text entry box to show the remaining data
    Gtk::Box *hboxLists = Gtk::manage(new Gtk::HBox);
    data = Gtk::manage(new Gtk::Label());
    data->set_hexpand(true);
    data->set_vexpand(true);
    Gtk::ScrolledWindow* scroller = Gtk::manage(new Gtk::ScrolledWindow);
    scroller->add(*data);
    hboxLists->pack_start(*scroller, Gtk::PACK_EXPAND_WIDGET, 0);
    //Clients List
    clientsList = Gtk::manage(new Gtk::Label());
    clientsList->set_hexpand(true);
    clientsList->set_vexpand(true);
    Gtk::ScrolledWindow* scroller2 = Gtk::manage(new Gtk::ScrolledWindow);
    scroller2->add(*clientsList);
    hboxLists->pack_start(*scroller2, Gtk::PACK_EXPAND_WIDGET, 0);
    //Adopted List
    adoptedList = Gtk::manage(new Gtk::Label());
    adoptedList->set_hexpand(true);
    adoptedList->set_vexpand(true);
    Gtk::ScrolledWindow* scroller3 = Gtk::manage(new Gtk::ScrolledWindow);
    scroller3->add(*adoptedList);
    hboxLists->pack_start(*scroller3, Gtk::PACK_EXPAND_WIDGET, 0);
    //Add all to vbox
    vbox->pack_start(*hboxLists, Gtk::PACK_EXPAND_WIDGET, 0);

    // ///////////////////////////////////
    // S T A T U S   B A R   D I S P L A Y
    // Provide a status bar for program messages
    msg = Gtk::manage(new Gtk::Label());
    msg->set_hexpand(true);
    msg->override_background_color(Gdk::RGBA{"orange"});
    vbox->pack_start(*msg, Gtk::PACK_SHRINK, 0);

    // Make the box and everything in it visible
    vbox->show_all();
}

Mainwin::~Mainwin() { }

// /////////////////
// C A L L B A C K S
// /////////////////

void Mainwin::on_quit_click() {
    close();
}

void Mainwin::on_save_click() 
{
	std::ofstream ofs{"untitled.mass"};
    for(int i=0; i<shelter->num_animals(); ++i)
        ofs << shelter->animal(i) << std::endl; 
    status("Saved");
}

void Mainwin::on_load_click()
{
	std::ifstream ifs{"untitled.mass"};
	std::string line;
	int i = 0;
	while(std::getline(ifs, line))
	{
		int age;
		std::istringstream iline(line);
		char spacedelim = ' ';
		char RPdelim = ')';
		char LPdelim = '(';
		char commadelim = ',';
		std::string nm;
		std::string genderText;
		std::string bType;
		std::string trash;
		std::string agestr;
		
		std::getline(iline, nm, spacedelim);
		std::getline(iline,trash, LPdelim);
		std::getline(iline, genderText, spacedelim);
		std::getline(iline, bType, commadelim);
		std::getline(iline,trash, spacedelim);
		std::getline(iline, agestr, RPdelim);
		std::getline(iline, trash);
		
		std::string split;
		std::istringstream type(bType);
		std::getline(type, split, spacedelim);
		
		std::string gender(genderText);
		std::string name(nm);
		std::string breedType(bType);
		std::string last;
		
		try{
			age = std::stoi(agestr, nullptr, 0);
		}
		catch(std::invalid_argument& e)
		{
			age = 0;
		}
		
		
		
		while(split.length() != 0)
		{
			last = split;
			split = strtok(NULL, " ");
		}
		
		bool female = true;
		if(genderText == "Male")
		{
			female = false;
		}
		
		if(last == "dog")
		{
			int breednum;
			std::string breed = breedType.substr(0, breedType.length() -4);
			
			if(breed == "Beagle") breednum = 0;
			if(breed == "Boxer") breednum = 1;
			if(breed == "Bulldog") breednum = 2;
			if(breed == "Dachshund") breednum = 3;
			if(breed == "Labrador") breednum = 4;
			if(breed == "Mix") breednum = 5;
			if(breed == "Pointer") breednum = 6;
			if(breed == "Poodle") breednum = 7;
			if(breed == "Retriever") breednum = 8;
			if(breed == "Rottweiler") breednum = 9;
			if(breed == "Shepherd") breednum = 10;
			if(breed == "Terrier") breednum = 11;		
			
			if(female)
			{
				Animal* animal = new Dog{dog_breeds[breednum], name, Gender::FEMALE, age};
				shelter->add_animal(*animal);
			}
			if(!female)
			{
				Animal* animal = new Dog{dog_breeds[breednum], name, Gender::MALE, age};
				shelter->add_animal(*animal);
			}
		}
		
		if(last == "cat")
		{
			int breednum;
			std::string breed = breedType.substr(0, breedType.length() -4);
			
			if(breed == "Bengal") breednum = 0;
			if(breed == "Bombay") breednum = 1;
			if(breed == "Burmese") breednum = 2;
			if(breed == "Egyptian") breednum = 3;
			if(breed == "Himalayan") breednum = 4;
			if(breed == "Maine Coon") breednum = 5;
			if(breed == "Manx") breednum = 6;
			if(breed == "Mix") breednum = 7;
			if(breed == "Persian") breednum = 8;
			if(breed == "Scottish Fold") breednum = 9;
			if(breed == "Siamese") breednum = 10;
			if(breed == "Sphynx") breednum = 11;
			if(breed == "Toyger") breednum = 12;
			
    		if(female)
			{
				Animal* animal = new Cat{cat_breeds[breednum], name, Gender::FEMALE, age};
				shelter->add_animal(*animal);
			}
			if(!female)
			{
				Animal* animal = new Cat{cat_breeds[breednum], name, Gender::MALE, age};
				shelter->add_animal(*animal);
			}
			
		}
		
		if(last == "rabbit")
		{
			int breednum;
			std::string breed = breedType.substr(0, breedType.length() -7);
			if(breed == "American") breednum = 0;
			if(breed == "Belgian Hare") breednum = 1;
			if(breed == "Blanc De Hotot") breednum = 2;
			if(breed == "Californian") breednum = 3;
			if(breed == "Checkered Giant") breednum = 4;
			if(breed == "Dutch") breednum = 5;
			if(breed == "English Lop") breednum = 6;
			if(breed == "Mix") breednum = 7;
			if(breed == "Flemish Giant") breednum = 8;
			if(breed == "Netherland Dwarf") breednum = 9;
			if(breed == "Satin Angora") breednum = 10;
			if(breed == "Silver") breednum = 11;
			if(breed == "Tan") breednum = 12;
			
    			
    		if(female)
			{
				Animal* animal = new Rabbit{rabbit_breeds[breednum], name, Gender::FEMALE, age};
				shelter->add_animal(*animal);
			}
			if(!female)
			{
				Animal* animal = new Rabbit{rabbit_breeds[breednum], name, Gender::MALE, age};
				shelter->add_animal(*animal);
			}
    			
		}
		
	}
	Gtk::MessageDialog dialog("Success!");
	dialog.set_message("Your data was successfully loaded.");
	dialog.run();
}

//  N E W  D O G
void Mainwin::on_new_dog_click() {

    Gtk::Dialog dialog{"Dog Info", *this};
	dialog.set_default_size(200,150);
    Gtk::Grid grid;

    Gtk::Label l_name{"Name"};
    Gtk::Entry e_name;
    grid.attach(l_name, 0, 0, 1, 1);
    grid.attach(e_name, 1, 0, 2, 1);

    Gtk::Label l_breed{"Breed"};
    Gtk::ComboBoxText c_breed;
    for(auto b : dog_breeds) c_breed.append(to_string(b));
    c_breed.set_active(0);
    grid.attach(l_breed, 0, 1, 1, 1);
    grid.attach(c_breed, 1, 1, 2, 1);

    Gtk::Label l_gender{"Gender"};
    Gtk::ComboBoxText c_gender;
    c_gender.append("Female");
    c_gender.append("Male");
    c_gender.set_active(0);
    grid.attach(l_gender, 0, 2, 1, 1);
    grid.attach(c_gender, 1, 2, 2, 1);

    Gtk::Label l_age{"Age"};
    Gtk::SpinButton s_age;
    s_age.set_range(0,99);
    s_age.set_increments(1,5);
    s_age.set_value(5);
    grid.attach(l_age, 0, 3, 1, 1);
    grid.attach(s_age, 1, 3, 2, 1);

    dialog.get_content_area()->add(grid);

    dialog.add_button("Add Dog", 1);
    dialog.add_button("Cancel", 0);

    dialog.show_all();

    while(dialog.run()) {
        if(e_name.get_text().size() == 0) {e_name.set_text("*required*"); continue;}
        Animal* animal = new Dog{dog_breeds[c_breed.get_active_row_number()], 
                                 e_name.get_text(),
                                 (c_gender.get_active_row_number() ? Gender::MALE : Gender::FEMALE),
                                 static_cast<int>(s_age.get_value())};
        shelter->add_animal(*animal);
        std::ostringstream oss;
        oss << "Added " << *animal;
        status(oss.str());
        break;
    }
}

//  N E W  C A T
void Mainwin::on_new_cat_click() {

    Gtk::Dialog dialog{"Cat Info", *this};
	dialog.set_default_size(200,150);
    Gtk::Grid grid;

    Gtk::Label l_name{"Name"};
    Gtk::Entry e_name;
    grid.attach(l_name, 0, 0, 1, 1);
    grid.attach(e_name, 1, 0, 2, 1);

    Gtk::Label l_breed{"Breed"};
    Gtk::ComboBoxText c_breed;
    for(auto b : cat_breeds) c_breed.append(to_string(b));
    c_breed.set_active(0);
    grid.attach(l_breed, 0, 1, 1, 1);
    grid.attach(c_breed, 1, 1, 2, 1);

    Gtk::Label l_gender{"Gender"};
    Gtk::ComboBoxText c_gender;
    c_gender.append("Female");
    c_gender.append("Male");
    c_gender.set_active(0);
    grid.attach(l_gender, 0, 2, 1, 1);
    grid.attach(c_gender, 1, 2, 2, 1);

    Gtk::Label l_age{"Age"};
    Gtk::SpinButton s_age;
    s_age.set_range(0,99);
    s_age.set_increments(1,5);
    s_age.set_value(5);
    grid.attach(l_age, 0, 3, 1, 1);
    grid.attach(s_age, 1, 3, 2, 1);

    dialog.get_content_area()->add(grid);

    dialog.add_button("Add Cat", 1);
    dialog.add_button("Cancel", 0);

    dialog.show_all();
    dialog.run();

    while(dialog.run()) {
        if(e_name.get_text().size() == 0) {e_name.set_text("*required*"); continue;}
        Animal* animal = new Cat{cat_breeds[c_breed.get_active_row_number()], 
                                 e_name.get_text(),
                                 (c_gender.get_active_row_number() ? Gender::MALE : Gender::FEMALE),
                                 static_cast<int>(s_age.get_value())};
        shelter->add_animal(*animal);
        std::ostringstream oss;
        oss << "Added " << *animal;
        status(oss.str());
        break;
    }
 
}

//  N E W  R A B B I T
void Mainwin::on_new_rabbit_click() {

    Gtk::Dialog dialog{"Rabbit Info", *this};
	dialog.set_default_size(250,150);
    Gtk::Grid grid;

    Gtk::Label l_name{"Name"};
    Gtk::Entry e_name;
    grid.attach(l_name, 0, 0, 1, 1);
    grid.attach(e_name, 1, 0, 2, 1);

    Gtk::Label l_breed{"Breed"};
    Gtk::ComboBoxText c_breed;
    for(auto b : rabbit_breeds) c_breed.append(to_string(b));
    c_breed.set_active(0);
    grid.attach(l_breed, 0, 1, 1, 1);
    grid.attach(c_breed, 1, 1, 2, 1);

    Gtk::Label l_gender{"Gender"};
    Gtk::ComboBoxText c_gender;
    c_gender.append("Female");
    c_gender.append("Male");
    c_gender.set_active(0);
    grid.attach(l_gender, 0, 2, 1, 1);
    grid.attach(c_gender, 1, 2, 2, 1);

    Gtk::Label l_age{"Age"};
    Gtk::SpinButton s_age;
    s_age.set_range(0,99);
    s_age.set_increments(1,5);
    s_age.set_value(5);
    grid.attach(l_age, 0, 3, 1, 1);
    grid.attach(s_age, 1, 3, 2, 1);

    dialog.get_content_area()->add(grid);

    dialog.add_button("Add Rabbit", 1);
    dialog.add_button("Cancel", 0);

    dialog.show_all();

    while(dialog.run()) {
        if(e_name.get_text().size() == 0) {e_name.set_text("*required*"); continue;}
        Animal* animal = new Rabbit{rabbit_breeds[c_breed.get_active_row_number()], 
                                 e_name.get_text(),
                                 (c_gender.get_active_row_number() ? Gender::MALE : Gender::FEMALE),
                                 static_cast<int>(s_age.get_value())};
        shelter->add_animal(*animal);
        std::ostringstream oss;
        oss << "Added " << *animal;
        status(oss.str());
        break;
    }
}

// N E W  C L I E N T
void Mainwin::on_new_client_click() {

    Gtk::Dialog dialog{"Client Info", *this};
	dialog.set_default_size(250,150);
    Gtk::Grid grid;

    Gtk::Label l_name{"Name"};
    Gtk::Entry e_name;
    grid.attach(l_name, 0, 0, 1, 1);
    grid.attach(e_name, 1, 0, 2, 1);

    Gtk::Label l_phone{"Phone"};
    Gtk::Entry e_phone;
    grid.attach(l_phone, 0, 1, 1, 1);
    grid.attach(e_phone, 1, 1, 2, 1);

    Gtk::Label l_email{"Email"};
    Gtk::Entry e_email;
    grid.attach(l_email, 0, 2, 1, 1);
    grid.attach(e_email, 1, 2, 2, 1);

    dialog.get_content_area()->add(grid);

    dialog.add_button("Add Client", 1);
    dialog.add_button("Cancel", 0);

    dialog.show_all();

    while(dialog.run()) {
   		bool check = true;
    	bool phoneCheck = true;
    	bool emailCheck = false;
    	
        if(e_name.get_text().size() == 0) {e_name.set_text("*Required*"); check = false;}
        if(e_phone.get_text().size() == 0) {e_phone.set_text("*Required*"); check = false;}
        if(e_email.get_text().size() == 0) {e_email.set_text("*Required*"); check = false;}
        if(e_phone.get_text().size() < 10) {e_phone.set_text("*Must be 10 digits*"); check = false;}
        
        if(check)
        {
        	//Error checking for phone number
        	std::string phone = e_phone.get_text();
        	for(int i = 0; i < (phone.length()); i++)
        	{        	
        		if(phone[i] != '0' && phone[i] != '1' && phone[i] != '2' && phone[i] != '3' && phone[i] != '4' && phone[i] != '5' && phone[i] != '6' && phone[i] != '7' && phone[i] != '8' && phone[i] != '9') 
        		{
        			e_phone.set_text("*Must be all integers*"); phoneCheck = false;
        		}
        	}
       	} 
        std::string email = e_email.get_text();
       	for(int j = 0; j < (email.length()); j++)
       	{
       		if(email[j] == '@')
       		{
       			emailCheck = true;
       		}
     	}
        
        
        if(!emailCheck)
        {
        	e_email.set_text("*Invalid Email*");
        }
        	
        
        if(check && phoneCheck && emailCheck)
        {
        	Client* client = new Client(e_name.get_text(), 
                                 e_phone.get_text(),
                                 e_email.get_text());
        	shelter->add_client(*client);
        	break;
        }
    }
}

void Mainwin::on_list_animals_click() {
    std::ostringstream oss;
    for(int i=0; i<shelter->num_animals(); ++i)
        oss << shelter->animal(i) << '\n'; 
    data->set_text(oss.str());
    status("");
}      // List all animals

void Mainwin::on_list_clients_click() {
    std::ostringstream oss;
    for(int i=0; i<shelter->num_clients(); ++i)
        oss << shelter->client(i) << '\n'; 
    clientsList->set_text(oss.str());
    status("");
}

void Mainwin::on_list_adopted_click() {
    std::ostringstream oss;
    for(int i=0; i<shelter->num_clients(); ++i)
    	if(shelter->client(i).num_adopted() > 0)
    		{
    			for(int j = 0; j < shelter->client(i).num_adopted(); ++j)
    				oss << shelter->client(i) << "   ::ADOPTED::   " << shelter->client(i).adopted(j)  << '\n';
    		}
         
    adoptedList->set_text(oss.str());
    status("");
}

void Mainwin::on_refresh_click()
{
	on_list_animals_click();
	on_list_clients_click();
	on_list_adopted_click();
}

void Mainwin::on_adopt_click() {
	Gtk::Dialog dialog{"Adoption", *this};
	dialog.set_default_size(250,150);
    Gtk::Grid grid;

    Gtk::Label l_name{"Select Client"};
    Gtk::ComboBoxText c_client;
    
    for(int i=0; i<shelter->num_clients(); ++i)
        {
        	std::ostringstream ossC;
        	ossC << shelter->client(i) << '\n';
        	c_client.append(ossC.str());
        }
    c_client.set_active(0);
    grid.attach(l_name, 0, 0, 1, 1);
    grid.attach(c_client, 1, 0, 2, 1);

    Gtk::Label l_breed{"Select Animal"};
    Gtk::ComboBoxText c_animal;
    
    for(int i=0; i<shelter->num_animals(); ++i)
        {
        	std::ostringstream ossA;
        	ossA << shelter->animal(i) << '\n';
        	c_animal.append(ossA.str());
        }
    c_animal.set_active(0);
    grid.attach(l_breed, 0, 1, 1, 1);
    grid.attach(c_animal, 1, 1, 2, 1);

    dialog.get_content_area()->add(grid);

    dialog.add_button("Adopt!", 1);
    dialog.add_button("Cancel", 0);

    dialog.show_all();
    dialog.run();

    while(dialog.run()) {
        int clientID = c_client.get_active_row_number();
        int animalID = c_animal.get_active_row_number();
        shelter->client(clientID).adopt_animal(shelter->animal(animalID));
        shelter->remove_animal(animalID);
        break;
    }
}


// /////////////////
// U T I L I T I E S
// /////////////////

void Mainwin::status(std::string s) {
    msg->set_text(s);
}
