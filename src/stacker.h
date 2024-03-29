#ifndef RS_STACKER_H
#define RS_STACKER_H


#include <ssg.h>

using namespace ssg;


class StackerSprite;


class Stacker {
public:
	
	Node2D *stackerNode;
	StackerSprite *stackerSprite;
	
	
	Stacker(Game *g);
	~Stacker();
	
	void update(float tpf);
	
	void cut();
	
	void arm();
	void disarm();
	bool isArmed();
	
private:
	bool armed;
	Game *game;
	
	Vector2f velocity;
	Uint8 r, g, b;
	
	void recomputeVelocity();
};



class StackerSprite : public ComponentSpriteSimple2D {
public:
	Stacker *stacker;
	
	StackerSprite(Stacker *s): stacker(s) {};
	
	virtual void onUpdate(Layer2D *layer, float tpf){
		stacker->update(tpf);
	}
};


class StackerMouseCallback : public MouseButtonCallback {
public:
	Stacker *stacker;
	
	StackerMouseCallback(Stacker *s):
		MouseButtonCallback(s->stackerNode),
		stacker(s)
	{};
	
	virtual void callback(MouseButtonEvent *event, float tpf){
		if(event->isPressed()) stacker->cut();
	};
};


class StackerKeyCallback : public KeyButtonCallback {
public:
	Stacker *stacker;
	
	StackerKeyCallback(Stacker *s):
		KeyButtonCallback(s->stackerNode),
		stacker(s)
	{};
	
	virtual void callback(KeyButtonEvent *event, float tpf){
		if(event->isPressed()) stacker->cut();
	}
};



#endif
