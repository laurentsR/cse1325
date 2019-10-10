#include "mainwin.h"
#include <cmath>

Mainwin::Mainwin() 
: spinbutton{Gtk::manage(new Gtk::SpinButton)},
  label{Gtk::manage(new Gtk::Label{"0-100"})},
  button1{Gtk::manage(new Gtk::Button{"Square Root"})},
  button2{Gtk::manage(new Gtk::Button{"Natural Logarithm"})},
  button3{Gtk::manage(new Gtk::Button{"Cosine"})}
{
  set_title("Ryan Laurents 3");
  Gtk::VBox *vbox = Gtk::manage(new Gtk::VBox);
  add(*vbox);
  
  vbox->pack_start(*spinbutton);
    spinbutton->set_range(0.0, 100.0);
    spinbutton->set_increments(1.0, 1.0);
    spinbutton->signal_value_changed().connect([this] {this->on_spinbutton_value_changed();});
    
  vbox->pack_start(*button1);
    button1->set_tooltip_markup("Square Root");
    button1->signal_clicked().connect([this] {this->on_button_click(1);});
    
  vbox->pack_start(*button2);
    button2->set_tooltip_markup("Logarithm");
    button2->signal_clicked().connect([this] {this->on_button_click(2);});
    
  vbox->pack_start(*button3);
    button3->set_tooltip_markup("Cosine");
    button3->signal_clicked().connect([this] {this->on_button_click(3);});
    
  vbox->show_all();
}

Mainwin::~Mainwin() { }

void Mainwin::on_spinbutton_value_changed() {
    int sp = spinbutton->get_value();
    label->set_text(std::to_string(sp));
}
    
void Mainwin::on_button_click(int button) {
	int sp = spinbutton->get_value();
	int answer;
    if(button == 1)
    {
    	answer = sqrt(sp);
    	Gtk::MessageDialog{*this, answer}.run();
    }
    else if(button == 2)
    {
    	answer = log(sp);
    }
    else if(button == 3)
    {
    	answer = cos(sp);
    }
    else
    {
    	Gtk::MessageDialog{*this, "Unknown error. Congratulations!"};
        dialog.run();
    }
}
}
