#ifndef RS_GAME_H
#define RS_GAME_H


#include <jvisu.h>

#include "difficulty.h"
#include "menu_button.h"
#include "stack.h"


class Application;


class Game {
public:
	Node2D *gameNode;
	Application *application;
	
	
	
	Game(Application *app);
	
	void reset(Difficulty diff);
	void end();
	
	int getScore();
	
private:
	Stack stack;
	Difficulty difficulty;
	
	void setup();
};



class GameQuitButton : public MenuButton {
public:
	Game *game;
	
	GameQuitButton(JWindow *win, Game *g);
	
	virtual void onLeftClick(MouseButtonEvent *event, float tpf);
};


#endif
