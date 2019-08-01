#include"../include/State.h"
#include"../include/Console.h"
Sequence* State::sequence=nullptr;
Console* State::console=nullptr;
void State::init(Sequence& seq,Console& _console){
    sequence=&seq;
    console=&_console;
}
void State::drawRect(int top,int left,int width,int height){
	int right = left + width;
	int bottom = top + height;
	for (int x = left + 1; x < right - 1; ++x)
	{
		console->setChar(x, top, '-');
		console->setChar(x, bottom - 1, '-');
	}

	for (int y = top + 1; y < bottom - 1; ++y)
	{
		console->setChar(left, y, '|');
		console->setChar(right - 1, y, '|');
	}

	console->setChar(left, top, '+');
	console->setChar(right - 1, top, '+');
	console->setChar(left, bottom - 1, '+');
	console->setChar(right - 1, bottom - 1, '+');
}
