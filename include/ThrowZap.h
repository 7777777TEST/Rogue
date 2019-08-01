#ifndef _THROWZAP_H
#define _THROWZAP_H
#include"State.h"
#include"World.h"
class ThrowState:public State{
	public:
		ThrowState(Item*,World*);
		void draw()override;
		void update(int)override;
	private:
		void throwUp();
		void throwDown();
		void throwLeft();
		void throwRight();
		World* world;
		Item* item;
};
#endif