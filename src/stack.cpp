#include <cstdio>
#include <cstdlib>
#include <jvisu.h>
#include "application.h"
#include "game.h"
#include "stack.h"



Stack::Stack(Game *g):
	game(g),
	node(NULL)
{
	node = new Node2D();
}


void Stack::addLayerSprite(Uint8 r, Uint8 g, Uint8 b){
	
	Node2D *lnode = new Node2D();
	lnode->zLevel = 0.0001 * stackHeight - 1;
	node->attachChild(lnode);
	
	
	Texture *texture = Texture::createSolidColor(
		1,
		1,
		game->application->window,
		r,
		g,
		b,
		0xff
	);
	
	ComponentSpriteSimple2D *layer;
	layer = new ComponentSpriteSimple2D(texture);
	layer->width = topRect.getWidth();
	layer->height = topRect.getHeight();
	layer->position.set(topRect.xMin, topRect.yMax);
	
	lnode->attachChild(layer);
	
}


void Stack::reset(){
	node->deleteAllChildren();
	node->detachFromParent();
	game->gameNode->attachChild(node);
	
	topRect.set(-0.2f, 0.2f, -0.2f, 0.2f);
	
	stackHeight = 1;
	
	
	
	Uint8 r, g, b;
	r = (Uint8) rand() % 256;
	g = (Uint8) rand() % 256;
	b = (Uint8) rand() % 256;
	addLayerSprite(r, g, b);
}


bool Stack::pushTop(Rect2f rect, Uint8 r, Uint8 g, Uint8 b){
	/**
	 * Returns true if rect is successfully pushed onto the stack.
	 * If there is no intersection (i.e. the game is over), false is returned.
	 */
	
	Rect2f newTopRect;
	if(!calculate_intersection(rect, topRect, newTopRect)) return false;
	topRect = newTopRect;
	
	stackHeight++;
	addLayerSprite(r, g, b);
	
	return true;
}


int Stack::getHeight(){
	return stackHeight;
}

