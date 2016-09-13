#ifndef RS_GAME_H
#define RS_GAME_H


#include <ssg.h>

#include "difficulty.h"
#include "menu_button.h"
#include "stack.h"
#include "stacker.h"

using namespace ssg;


class Application;


class Game {
public:
	Node2D *gameNode;
	Application *application;
	Stack stack;
	Stacker stacker;
	Difficulty difficulty;
	
	
	Game(Application *app);
	~Game(){ delete gameNode; };
	
	void reset(Difficulty diff);
	void end();
	
	int getScore();
	
private:
	
	void setup();
};


class ScoreSprite : public ComponentSpriteText2D {
public:
	Game *game;
	
	ScoreSprite(Window *win, Game *g);
	
	virtual void onUpdate(Layer2D *layer, float tpf);
};


class GameQuitButton : public MenuButton {
public:
	Game *game;
	
	GameQuitButton(Window *win, Game *g);
	
	virtual void onLeftClick(MouseButtonEvent *event, float tpf);
};


#endif
