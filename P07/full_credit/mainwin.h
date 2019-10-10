#include <gtkmm.h>

class Mainwin : public Gtk::Window {
  public:
    Mainwin();
    virtual ~Mainwin();
  protected:
    void on_button_click(int button);
    void on_spinbutton_value_changed();
  private:
    Gtk::Button* button1;
    Gtk::Button* button2;
    Gtk::Button* button3;
    Gtk::SpinButton* spinbutton;
    Gtk::Label* label;
};
