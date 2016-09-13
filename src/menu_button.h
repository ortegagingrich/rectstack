#ifndef RS_MENU_BUTTON_H
#define RS_MENU_BUTTON_H

#include <ssg.h>

using namespace ssg;


class MainMenu;


class MenuButton : public ComponentButtonSimple2D {
public:
	MenuButton(Window *win, MainMenu *m);
protected:
	MainMenu *menu;
};


#endif
