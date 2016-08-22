#ifndef RS_GAME_H
#define RS_GAME_H


#include <jvisu.h>

#include "difficulty.h"


class Game {
public:
	Node2D *gameNode;
	
	Game(Application *app);
	~Game();
	
	void reset(Difficulty diff);
	
private:
	Application *application;
	Difficulty difficulty;
};



#endif
