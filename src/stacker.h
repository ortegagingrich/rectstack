#ifndef RS_STACKER_H
#define RS_STACKER_H


#include <jvisu.h>


class StackerSprite;


class Stacker {
public:
	
	Node2D *stackerNode;
	StackerSprite *stackerSprite;
	
	
	Stacker(Game *g);
	~Stacker();
	
	void update(float tpf);
	
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
	
	virtual void update(Layer2D *layer, float tpf){
		stacker->update(tpf);
		ComponentSpriteSimple2D::update(layer, tpf);
	}
};



#endif
