#ifndef _SEQUENCE_H
#define _SEQUENCE_H
#include "Console.h"
#include "World.h"
#include"State.h"
class Sequence{
		enum Ctrl{
			push,pop,clear
		};
	public:
		Sequence()=default;
		void Push(State*);
		void Pop();
		void Clear();
		bool isEmpty()const;
		void update(int);
		void draw();
	private:
		void apply();
		std::vector<State*> stack;
		std::vector<std::pair<Ctrl,State*>> actionStack;
};
#endif