/*
 * Application Source Code
 */

#include <jvisu.h>
#include "application.h"



Application *Application::createApplication(bool useHardwareRendering){
	return new Application(useHardwareRendering);
}


Application::Application(bool useHardwareRendering):
	window(NULL),
	layer(NULL)
{
	window = new JWindow(1280, 720, useHardwareRendering);
	layer = new Layer2D("Main Layer");
	window->addLayerTop(layer);
}


Application::~Application(){
	if(window != NULL) delete window;
}


void Application::run(){
	
	
	// Main Loop
	while(window->isActive()){
		float tpf = window->tick(60);
		window->update(tpf);
	}
	
	
}


