#ifndef RS_MENU_H
#define RS_MENU_H


#include <jvisu.h>


class MainMenu {
public:
	Node2D *menuNode;
	
	MainMenu(Application *app);
	~MainMenu();
	
private:
	Application *application;
};



#endif
