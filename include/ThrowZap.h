#ifndef _THROWZAP_H
#define _THROWZAP_H
#include"State.h"
#include"World.h"
class ThrowState:public State{
	public:
		ThrowState(Item*,World*);
		void draw()override;
		void update(int)override;
		void end();
	protected:
		void throwUp();
		void throwDown();
		void throwLeft();
		void throwRight();
		World* world;
		Item* item;
};
class Zap:public ThrowState{
	public:
		Zap(World*);
};
#endif