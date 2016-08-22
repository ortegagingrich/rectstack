#ifndef RS_STACK_H
#define RS_STACK_H


#include <jvisu.h>


class Game;


class Stack {
public:
	
	Stack(Game *g);
	
	void reset();
	bool pushTop(Rect2f rect);
	int getHeight();
	
private:
	Game *game;
	Node2D *node;
	Rect2f topRect;
	
	int stackHeight;
	
	void addLayerSprite();
};



#endif
