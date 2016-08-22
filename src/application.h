/**
 * Definitions and Declarations for the rectstack application
 */

#ifndef RS_APPLICATION_H
#define RS_APPLICATION_H


#include <jvisu.h>



class Application {
public:
	
	static Application *createApplication(bool useHardwareAcceleration);
	
	~Application();
	void run();
	
private:
	
	JWindow *window;
	Layer2D *layer;
	
	
	Application(bool useHardwareAcceleration);
};




#endif

