#ifndef RS_MENU_BUTTON_H
#define RS_MENU_BUTTON_H

#include <jvisu.h>

class MainMenu;


class MenuButton : public ComponentButtonSimple2D {
public:
	MenuButton(JWindow *win, MainMenu *m);
protected:
	MainMenu *menu;
};


#endif
