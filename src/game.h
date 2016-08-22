#ifndef RS_GAME_H
#define RS_GAME_H


#include <jvisu.h>

#include "difficulty.h"
#include "menu_button.h"


class Game {
public:
	Node2D *gameNode;
	Application *application;
	
	
	
	Game(Application *app);
	~Game();
	
	void reset(Difficulty diff);
	void end();
	
private:
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
