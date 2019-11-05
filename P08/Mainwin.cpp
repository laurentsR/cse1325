#include "Mainwin.h"
#include <sstream>
#include "entrydialog.h"

Mainwin::Mainwin()
{
	// Instance Shelter
	
	// /////////////////
    // G U I   S E T U P
    // /////////////////
	set_default_size(640, 480);
    set_title("Pawsome Pals");
    
    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    add(*vbox);
    
    // ///////
    // M E N U
    // Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
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
    
    //     A N I M A L S
    // Create a Animals menu and add to the menu bar
    Gtk::MenuItem *menuitem_animals = Gtk::manage(new Gtk::MenuItem("_Animals", true));
    menubar->append(*menuitem_animals);
    Gtk::Menu *animalsmenu = Gtk::manage(new Gtk::Menu());
    menuitem_animals->set_submenu(*animalsmenu);
    
    //         A D D   A N I M A L
    // Append Add to the Animal menu
    menuitem_add_animal = Gtk::manage(new Gtk::MenuItem("_Add Animal", true));
    menuitem_add_animal->signal_activate().connect([this] {this->on_new_animal_click();});
    animalsmenu->append(*menuitem_add_animal);
    
    //         L I S T   A N I M A L S
    // Append List to the Sweets menu
    menuitem_list_animals = Gtk::manage(new Gtk::MenuItem("_List", true));
    menuitem_list_animals->signal_activate().connect([this] {this->on_list_animals_click();});
    animalsmenu->append(*menuitem_list_animals);
    
    // D A T A   D I S P L A Y
    // Provide a text entry box to show the remaining sticks
    data = Gtk::manage(new Gtk::Label());
    data->set_hexpand(true);
    data->set_vexpand(true);
    data->set_markup("<span size='large' weight='bold'>No animals have been defined yet</span>");
    vbox->add(*data);
    
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

void Mainwin::on_new_animal_click() {
    std::string name = "";
    int age = -1;
    std::string gender = "";
    Gender _gender;

	Gtk::Dialog *dialog = new Gtk::Dialog{"Add an animal", *this};
	
    // Name
    Gtk::HBox b_name;

    Gtk::Label l_name{"Name:"};
    l_name.set_width_chars(15);
    b_name.pack_start(l_name, Gtk::PACK_SHRINK);

    Gtk::Entry e_name;
    e_name.set_max_length(50);
    b_name.pack_start(e_name, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_name, Gtk::PACK_SHRINK);

    // Age
    Gtk::HBox b_age;

    Gtk::Label l_age{"Age:"};
    l_age.set_width_chars(15);
    b_age.pack_start(l_age, Gtk::PACK_SHRINK);

    Gtk::Entry e_age;
    e_age.set_max_length(50);
    b_age.pack_start(e_age, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_age, Gtk::PACK_SHRINK);
    
    // Gender
    Gtk::HBox b_gender;

    Gtk::Label l_gender{"Gender:"};
    l_gender.set_width_chars(15);
    b_gender.pack_start(l_gender, Gtk::PACK_SHRINK);

    Gtk::Entry e_gender;
    e_gender.set_max_length(50);
    b_gender.pack_start(e_gender, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_gender, Gtk::PACK_SHRINK);

    // Show dialog
    dialog->add_button("Cancel", 0);
    dialog->add_button("Create", 1);
    dialog->show_all();

    int result; // of the dialog (1 = OK)
    bool fail = true;  // set to true if any data is invalid

    while (fail) {
        fail = false;  // optimist!
        result = dialog->run();
        if (result != 1) {
            delete dialog;
            return;}
        try {
            age = std::stod(e_age.get_text());
        } catch(std::exception e) {
            e_age.set_text("### Invalid ###");
            fail = true;
        }
        name = e_name.get_text();
        if (name.size() == 0) {
            e_name.set_text("### Invalid ###");
            fail = true;
        }
        gender = e_gender.get_text();
        if (gender.size() == 0)
        {
        	e_gender.set_text("### Invalid ###");
        	fail = true;
        }
    }
    delete dialog;
    
    if(gender == "Male" || gender == "male")
    {
    	_gender = Male;
    }
    else if(gender == "Female" || gender == "female")
    {
    	_gender = Female;
    }
    else
    {
    	_gender = Invalid;
    }

    Animal animal{name, _gender, age};
    _shelter->add_animal(animal);
    on_list_animals_click();


}

void Mainwin::on_list_animals_click() {
    if (_shelter->num_animals() == 0) {
        data->set_markup("<span size='large' weight='bold'>No animals have been defined yet</span>");
        return;
    }

    // The string manipulation way

    std::string s = "<span size='large' weight='bold'>";
    for(int i=0; i<_shelter->num_animals(); ++i)
    { 
        s += "Name: " + _shelter->animal(i).name() + " || Gender: " + std::to_string(_shelter->animal(i).gender()) + " || Age: " + std::to_string(_shelter->animal(i).age()) + "\n";
    }
    s += "</span>";
    data->set_markup(s);

}


