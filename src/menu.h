#ifndef RS_MENU_H
#define RS_MENU_H


#include <jvisu.h>
#include "difficulty.h"
#include "menu_button.h"


class MainMenu {
public:
	Node2D *menuNode;
	Application *application;
	
	MainMenu(Application *app);
	~MainMenu(){
		delete menuNode;
	};
	
private:
	
	void setup();
};


/*
 * Buttons
 */



class StartButton : public MenuButton {
public:
	StartButton(JWindow *win, MainMenu *m, Difficulty diff);
	
	virtual void onLeftClick(MouseButtonEvent *event, float tpf);
private:
	Difficulty difficulty;
};



class QuitButton : public MenuButton {
public:
	QuitButton(JWindow *win, MainMenu *m);
	
	virtual void onLeftClick(MouseButtonEvent *event, float tpf);
};



#endif
