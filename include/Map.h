#ifndef _MAP_H
#define _MAP_H
#include"Point.h"
#include"Console.h"
class Map{
	public:
		Map(const std::string);
		const char Get(Point)const;
        const char Get(int x,int y)const;
		bool isMove(int,int)const;
		bool isVisible(Point)const;
		bool isVisible(int,int)const;
		void setVisible(Point);
		void setVisible(int,int);
		int width()const;
		int height()const;
		void draw(Console&)const;
	private:
		int w=0,h=0;
		std::vector<std::string*> map;
		std::vector<std::string*> visible;
};
#endif