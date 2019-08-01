#ifndef _ARRAY2D_H
#define _ARRAY2D_H
#include"Point.h"
template<class T>class Array2D{
	public:
		Array2D():_array(0){};
		~Array2D(){delete[] _array;}
		void setSize(int w,int h){_w=w;_h=h;_array=new T[w*h];}
		T& operator ()(int x,int y){return _array[_w*y+x];}
		T& operator ()(Point p){return _array[_w*p.y+p.x];}
		const T& operator ()(int x,int y)const{return _array[_w*y+x];}
		const T& operator ()(Point p)const{return _array[_w*p.y+p.x];}
		int width()const{return _w;}
		int height()const{return _h;}
	private:
		T* _array;
		int _w,_h;
};
#endif