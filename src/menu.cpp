#include <jvisu.h>
#include "application.h"
#include "menu.h"


MainMenu::MainMenu(Application *app):
	menuNode(NULL),
	application(app)
{
	menuNode = new Node2D();
}


MainMenu::~MainMenu(){
	if(menuNode != NULL) delete menuNode;
}

