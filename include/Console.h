#ifndef _IM_CONSOLE_H
#define _IM_CONSOLE_H
#include<vector>
#include<string>
#include"Point.h"
class Console{
	public:
		Console(int,int);
		void setChar(int,int,char);
		void setChar(Point,char);
		void setString(int,int,std::string);
		void draw();
		void clear();
		int width()const;
		int height()const;
	private:
		int w;
		int h;
		std::vector<std::string> buf;
};
#endif