#include "mainwin.h"
#include "dog.h"
#include "cat.cpp"
#include "rabbit.cpp"
#include "client.cpp"
#include <sstream>

Mainwin::Mainwin() : shelter{new Shelter{"Pawsome Pals"}} {

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(800, 600);
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
    Gtk::MenuItem *menuitem_listanimal = Gtk::manage(new Gtk::MenuItem("_List", true));
    menuitem_listanimal->signal_activate().connect([this] {this->on_list_animals_click();});
    animalmenu->append(*menuitem_listanimal);
    
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

    // /////////////
    // T O O L B A R
    // Add a toolbar to the vertical box below the menu
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    toolbar->override_background_color(Gdk::RGBA{"gray"});
    vbox->pack_start(*toolbar, Gtk::PACK_SHRINK, 0);
    
    // A D D  D O G
    // Icon for add new dog
    Gtk::Image* add_dog_image = Gtk::manage(new Gtk::Image{"dog.png"});
    add_dog_button = Gtk::manage(new Gtk::ToolButton(*add_dog_image));
    add_dog_button->set_tooltip_markup("Add a new dog to the shelter!");
    add_dog_button->signal_clicked().connect([this] {this->on_new_dog_click();});
    toolbar->append(*add_dog_button);
    
    // A D D  C A T
    // Icon for add new cat
    Gtk::Image* add_cat_image = Gtk::manage(new Gtk::Image{"cat.png"});
    add_cat_button = Gtk::manage(new Gtk::ToolButton(*add_cat_image));
    add_cat_button->set_tooltip_markup("Add a new cat to the shelter!");
    add_cat_button->signal_clicked().connect([this] {this->on_new_cat_click();});
    toolbar->append(*add_cat_button);
    
    // A D D  R A B B I T
    // Icon for add new rabbit
    Gtk::Image* add_rabbit_image = Gtk::manage(new Gtk::Image{"rabbit.png"});
    add_rabbit_button = Gtk::manage(new Gtk::ToolButton(*add_rabbit_image));
    add_rabbit_button->set_tooltip_markup("Add a new rabbit to the shelter!");
    add_rabbit_button->signal_clicked().connect([this] {this->on_new_rabbit_click();});
    toolbar->append(*add_rabbit_button);
    
    // A D D  C L I E N T
    // Icon for add new client
    Gtk::Image* add_client_image = Gtk::manage(new Gtk::Image{"volunteer.png"});
    add_client_button = Gtk::manage(new Gtk::ToolButton(*add_client_image));
    add_client_button->set_tooltip_markup("Add a new client!");
    add_client_button->signal_clicked().connect([this] {this->on_new_client_click();});
    toolbar->append(*add_client_button);
    
    
    //
    //	ICONS MADE BY FLATICON.COM
    //
    
    
    // Q U I T
    // Icon for quit
    Gtk::ToolButton *quit_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::QUIT));
    quit_button->set_tooltip_markup("Exit");
    quit_button->signal_clicked().connect([this] {this->on_quit_click();});
    Gtk::SeparatorToolItem *sep = Gtk::manage(new Gtk::SeparatorToolItem());
    sep->set_expand(true);  // The expanding sep forces the Quit button to the right
    toolbar->append(*sep);
    toolbar->append(*quit_button);
    

    // ///////////////////////
    // D A T A   D I S P L A Y
    // Provide a text entry box to show the remaining data
    data = Gtk::manage(new Gtk::Label());
    data->set_hexpand(true);
    data->set_vexpand(true);
    Gtk::ScrolledWindow* scroller = Gtk::manage(new Gtk::ScrolledWindow);
    scroller->add(*data);
    vbox->pack_start(*scroller, Gtk::PACK_EXPAND_WIDGET, 0);

    // ///////////////////////////////////
    // S T A T U S   B A R   D I S P L A Y
    // Provide a status bar for program messages
    msg = Gtk::manage(new Gtk::Label());
    msg->set_hexpand(true);
    msg->override_background_color(Gdk::RGBA{"gray"});
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

//  N E W  D O G
void Mainwin::on_new_dog_click() {

    Gtk::Dialog dialog{"Dog Info", *this};

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

// /////////////////
// U T I L I T I E S
// /////////////////

void Mainwin::status(std::string s) {
    msg->set_text(s);
}
