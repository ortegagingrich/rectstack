#include <jvisu.h>
#include "application.h"
#include "game.h"


Game::Game(Application *app):
	gameNode(NULL),
	application(app)
{
	gameNode = new Node2D();
}


Game::~Game(){
	if(gameNode != NULL) delete gameNode;
}



void Game::reset(Difficulty diff){
	difficulty = diff;
}

