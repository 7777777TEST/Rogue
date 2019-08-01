#ifndef _POINT_H
#define _POINT_H
struct Point{
	public:
	int x,y;
	Point(int _x,int _y){
		x=_x;
		y=_y;
	}
	bool operator ==(Point p){
		return p.x==x&&p.y==y;
	}
};
#endif