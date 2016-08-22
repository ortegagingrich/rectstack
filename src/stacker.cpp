#include <cstdio>
#include <jvisu.h>
#include "application.h"
#include "difficulty.h"
#include "game.h"
#include "stacker.h"


Stacker::Stacker(Game *g):
	stackerNode(NULL),
	stackerSprite(NULL),
	armed(false),
	game(g)
{
	stackerNode = new Node2D();
	stackerSprite = new StackerSprite(this);
	stackerNode->attachChild(stackerSprite);
	
	new StackerMouseCallback(this);
	new StackerKeyCallback(this);
}

Stacker::~Stacker(){
	delete stackerNode;
}


void Stacker::update(float tpf){
	if(!armed) return;
	
	stackerNode->position += tpf * velocity;
	if(
		stackerNode->position.x < -1 ||
		stackerNode->position.y < -1 ||
		stackerNode->position.x > 1 ||
		stackerNode->position.y > 1
	){
		recomputeVelocity();
	}
}


void Stacker::recomputeVelocity(){
	velocity = -stackerNode->position;
	velocity.normalize();
	velocity *= 0.5f; // Change this based on difficulty
}


void Stacker::cut(){
	// Only cut if active
	if(!armed) return;
	
	// Compute the rectangle with which to intersect the stack
	Rect2f rect;
	rect.xMin = stackerNode->position.x + stackerSprite->position.x;
	rect.yMax = stackerNode->position.y + stackerSprite->position.y;
	rect.xMax = rect.xMin + stackerSprite->width;
	rect.yMin = rect.yMax - stackerSprite->height;
	
	
	if(!game->stack.pushTop(rect, r, g, b)){
		game->end();
	}else{
		disarm();
		arm();
	}
}


void Stacker::arm(){
	armed = true;
	
	//TODO: Add logic for choosing velocity based on difficulty, etc.
	stackerNode->position.set(0, 1);
	recomputeVelocity();
	
	
	// Set correct dimensions for stacker sprite
	Rect2f rect = game->stack.getTopRect();
	stackerSprite->position.set(rect.xMin, rect.yMax);
	stackerSprite->width = rect.getWidth();
	stackerSprite->height = rect.getHeight();
	
	
	// Make new texture for stacker sprite
	r = (Uint8) rand() % 256;
	g = (Uint8) rand() % 256;
	b = (Uint8) rand() % 256;
	Texture *texture = Texture::createSolidColor(
		1,
		1,
		game->application->window,
		r,
		g,
		b,
		0xff
	);
	stackerSprite->setTexture(texture);
	
	
	game->gameNode->attachChild(stackerNode);
}


void Stacker::disarm(){
	armed = false;
	
	stackerNode->detachFromParent();
}


bool Stacker::isArmed(){
	return armed;
}


