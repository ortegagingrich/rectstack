#include <string>
#include <sstream>
#include <jvisu.h>
#include "application.h"
#include "game.h"
#include "record.h"


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
	
	
	// Score
	ScoreSprite *scoreSprite = new ScoreSprite(application->window, this);
	scoreSprite->width = -1;
	scoreSprite->height = 0.2f;
	scoreSprite->position.set(-application->window->getAspectRatio(), 1.0f);
	gameNode->attachChild(scoreSprite);
	
	
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
 * Score Viewer
 */

ScoreSprite::ScoreSprite(JWindow *win, Game *g):
	ComponentSpriteText2D(win),
	game(g)
{
	text = "";
	fontPath = FONT_PATH;
	fontSize = 64;
}


void ScoreSprite::update(Layer2D *layer, float tpf){
	
	std::stringstream stream;
	
	int score = game->getScore();
	int record = get_record(game->difficulty);
	stream << "Score: " << score << "   Record: " << record;
	text = stream.str();
	
	if(score > record) put_record(score, game->difficulty);
	
	ComponentSpriteText2D::update(layer, tpf);
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

