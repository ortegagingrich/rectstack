#include <jvisu.h>
#include "application.h"
#include "game.h"


static std::string FONT_PATH = "assets/font/LiberationSerif-Regular.ttf";



Game::Game(Application *app):
	gameNode(NULL),
	application(app),
	stack(this),
	stacker(this)
{
	setup();
}




void Game::setup(){
	gameNode = new Node2D();
	
	// Quit Button
	GameQuitButton *quitButton = new GameQuitButton(application->window, this);
	quitButton->width = 0.7f;
	quitButton->height = 0.2f;
	quitButton->position.set(application->window->getAspectRatio() - 0.7f, 1.0f);
	gameNode->attachChild(quitButton);
	
}



void Game::reset(Difficulty diff){
	difficulty = diff;
	stack.reset();
	
	stacker.disarm();
	//TODO: Instead of immediately arming the stacker, have a countdown
	stacker.arm();
}



void Game::end(){
	stacker.disarm();
	//TODO: Open Score Report; for now, just end immediately
	application->startMenu();
}


int Game::getScore(){
	return stack.getHeight();
}



/*
 * Quit Button
 */

GameQuitButton::GameQuitButton(JWindow *win, Game *g):
	MenuButton(win, NULL),
	game(g)
{
	Texture *background = Texture::createSolidColor(1, 1, win, 0x55, 0x55, 0x55, 0xff);
	setTexture(background);
	setText("Quit Game");
}


void GameQuitButton::onLeftClick(MouseButtonEvent *event, float tpf){
	game->end();
}

