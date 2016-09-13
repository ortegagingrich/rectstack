/**
 * Definitions and Declarations for the rectstack application
 */

#ifndef RS_APPLICATION_H
#define RS_APPLICATION_H


#include <string>
#include <ssg.h>
#include "difficulty.h"

using namespace ssg;


class Game;
class MainMenu;


class Application {
public:
	
	
	Window *window;
	
	
	static Application *createApplication(bool useHardwareAcceleration);
	
	~Application();
	void run();
	void end();
	
	
	void startMenu();
	void startGame(Difficulty difficulty);
	
	
private:
	
	bool active;
	
	Layer2D *layer;
	
	Game *game;
	MainMenu *menu;
	
	Node2D *rootNode;
	
	
	Application(bool useHardwareAcceleration);
};




#endif

