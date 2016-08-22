#include <cstdio>
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


void Stack::addLayerSprite(){
	
	Uint8 r, g, b;
	r = 0x00;
	g = 0x00;
	b = 0xff;
	
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
	
	node->attachChild(layer);
}


void Stack::reset(){
	node->deleteAllChildren();
	node->detachFromParent();
	game->gameNode->attachChild(node);
	
	topRect.set(-0.5f, 0.5f, -0.5f, 0.5f);
	
	stackHeight = 1;
	addLayerSprite();
}


bool Stack::pushTop(Rect2f rect){
	/**
	 * Returns true if rect is successfully pushed onto the stack.
	 * If there is no intersection (i.e. the game is over), false is returned.
	 */
	
	if(!calculate_intersection(rect, topRect, topRect)) return false;
	
	stackHeight++;
	addLayerSprite();
	
	return true;
}


int Stack::getHeight(){
	return stackHeight;
}

