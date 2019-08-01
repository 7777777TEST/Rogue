#include"../include/Map.h"
Map::Map(const std::string s){
	int x=0,y=0;
	int _w=0,_h=0;
	for(char c:s){
		switch(c){
			case '\n':
				w=x>w?x:w;
				++y;
				x=0;
				break;
			case '#':case '.':case '<':case '>':
				++x;
				break;
		}
	}
	h=y+1;
	w=x>w?x:w;
	for(y=0;y<h+1;++y){
		map.push_back(new std::string("#"));
		visible.push_back(new std::string("F"));
		for(x=0;x<w+1;++x){
			(*map[y]).append("#");
			(*visible[y]).append("F");
		}
	}
	x=y=0;
	for(char c:s){
		switch(c){
			case '#':case '.':case '<':case '>':
				(*map[y])[x]=c;
				++x;
				break;
			case '\n':
				++y;
				x=0;
				break;
		}
	}
}
bool Map::isMove(int x,int y)const{
	if(x<0||x>=w||y<0||y>=h)return false;
	switch((*map[y])[x]){
		case '#':
			return false;
		case '.':
		case '>':
		case '<':
			return true;
	}
}
int Map::width()const{
	return w;
}
int Map::height()const{
	return h;
}
const char Map::Get(int x,int y)const{
	return (*map[y])[x];
}
const char Map::Get(Point pos)const{
	return (*map[pos.y])[pos.x];
}
void Map::draw(Console& console)const{
	for(int y=0;y<h;++y){
		for(int x=0;x<w;++x){
			console.setChar(x,y,(*map[y])[x]);
		}
	}
}
bool Map::isVisible(int x,int y)const{
	return (*visible[y])[x]=='T';
}
bool Map::isVisible(Point pos)const{
	return (*visible[pos.y])[pos.x]=='T';
}
void Map::setVisible(int x,int y){
	(*visible[y])[x]='T';
}
void Map::setVisible(Point pos){
	(*visible[pos.y])[pos.x]='T';
}