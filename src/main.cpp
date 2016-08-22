#include <cstdio>

#include "application.h"


const bool USE_HARDWARE_ACCELERATION = true;


int main(){
	printf("\nStarting RectStack.\n");
	
	Application *application = NULL;
	application = Application::createApplication(USE_HARDWARE_ACCELERATION);
	
	if(application != NULL){
		application->run();
		delete application;
	}
	
	printf("\nExiting RectStack.\n");
	return 0;
}
