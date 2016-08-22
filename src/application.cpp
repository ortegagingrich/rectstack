/*
 * Application Source Code
 */

#include <jvisu.h>
#include "application.h"
#include "game.h"
#include "menu.h"



Application *Application::createApplication(bool useHardwareRendering){
	return new Application(useHardwareRendering);
}


Application::Application(bool useHardwareRendering):
	active(true),
	window(NULL),
	layer(NULL),
	game(NULL),
	menu(NULL),
	rootNode(NULL)
{
	window = new JWindow(1280, 720, useHardwareRendering, "RectStack");
	layer = new Layer2D("Main Layer");
	window->addLayerTop(layer);
	rootNode = layer->getRootNode();
	
	game = new Game(this);
	menu = new MainMenu(this);
	
	startMenu();
}


Application::~Application(){
	if(window != NULL) delete window;
}




void Application::run(){
	
	
	// Main Loop
	while(active && window->isActive()){
		float tpf = window->tick(60);
		window->update(tpf);
	}
	
	
}



void Application::startMenu(){
	rootNode->detachChild(game->gameNode);
	rootNode->attachChild(menu->menuNode);
}



void Application::startGame(Difficulty difficulty){
	rootNode->detachChild(menu->menuNode);
	
	game->reset(difficulty);
	rootNode->attachChild(game->gameNode);
}














