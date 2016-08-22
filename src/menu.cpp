#include <jvisu.h>
#include "application.h"
#include "menu.h"


static std::string FONT_PATH = "assets/font/LiberationSerif-Regular.ttf";



MainMenu::MainMenu(Application *app):
	menuNode(NULL),
	application(app)
{
	setup();
}



void MainMenu::setup(){
	menuNode = new Node2D();
	
	// Title Text
	ComponentSpriteText2D *titleText = new ComponentSpriteText2D(application->window);
	titleText->text = "RectStack";
	titleText->fontPath = FONT_PATH;
	titleText->fontSize = 128;
	titleText->colorRed = 0xff;
	titleText->colorGreen = 0x00;
	titleText->colorBlue = 0x00;
	titleText->position.set(-0.3f, 0.8f);
	titleText->width = 0.6f;
	titleText->height = 0.2f;
	menuNode->attachChild(titleText);
	
	
	// Start Buttons
	ComponentSpriteText2D *startText = new ComponentSpriteText2D(application->window);
	startText->text = "Start Game:";
	startText->fontPath = FONT_PATH;
	startText->fontSize = 128;
	startText->position.set(-1.7f, 0.3f);
	startText->width = -1;
	startText->height = 0.15f;
	menuNode->attachChild(startText);
	
	
	StartButton *easy, *medium, *hard;
	
	easy = new StartButton(application->window, this, Difficulty::EASY);
	easy->width = 0.5f;
	easy->height = 0.2f;
	easy->position.set(-0.85f, 0.3f);
	
	medium = new StartButton(application->window, this, Difficulty::MEDIUM);
	medium->width = 0.5f;
	medium->height = 0.2f;
	medium->position.set(-0.1f, 0.3f);
	
	hard = new StartButton(application->window, this, Difficulty::HARD);
	hard->width = 0.5f;
	hard->height = 0.2f;
	hard->position.set(0.65f, 0.3f);
	
	
	menuNode->attachChild(easy);
	menuNode->attachChild(medium);
	menuNode->attachChild(hard);
	
	
	
	// Quit Button
	QuitButton *quitButton = new QuitButton(application->window, this);
	quitButton->width = 0.5f;
	quitButton->height = 0.2f;
	quitButton->position.set(-0.25f, -0.6f);
	menuNode->attachChild(quitButton);
	
}



/*
 * Buttons
 */


MenuButton::MenuButton(JWindow *win, MainMenu *m):
	ComponentButtonSimple2D(win),
	menu(m)
{
	setFont(FONT_PATH);
	setFontSize(64);
	
	Texture *overlay;
	overlay = Texture::createSolidColor(1, 1, win, 0xff, 0xff, 0xff, 0x55);
	setOverlayTexture(overlay);
}



StartButton::StartButton(JWindow *win, MainMenu *m, Difficulty diff):
	MenuButton(win, m),
	difficulty(diff)
{
	Texture *background;
	
	switch(difficulty){
	case Difficulty::EASY:
		background = Texture::createSolidColor(1, 1, win, 0x22, 0xdd, 0x22, 0xff);
		setText("Easy");
		break;
	case Difficulty::MEDIUM:
		background = Texture::createSolidColor(1, 1, win, 0xcc, 0xcc, 0x22, 0xff);
		setText("Medium");
		break;
	case Difficulty::HARD:
		background = Texture::createSolidColor(1, 1, win, 0xdd, 0x22, 0x22, 0xff);
		setText("Hard");
	}
	
	setTexture(background);
}


void StartButton::onLeftClick(MouseButtonEvent *event, float tpf){
	menu->application->startGame(difficulty);
}



QuitButton::QuitButton(JWindow *win, MainMenu *m):
	MenuButton(win, m)
{
	Texture *background = Texture::createSolidColor(1, 1, win, 0x55, 0x55, 0x55, 0xff);
	setTexture(background);
	setText("Quit");
}


void QuitButton::onLeftClick(MouseButtonEvent *event, float tpf){
	menu->application->end();
}




