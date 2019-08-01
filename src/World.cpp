#include"../include/World.h"
#include<sstream>
World::World(){
	player=new Actor();
	player->setName("Player");
	player->type=Actor::Type::Hero;
	Level *level=new Level("......\n......\n......\n......");
	levels.emplace_back(level);
	currentLevel=level;
	currentLevel->attach(player);
	Item::Status s;
	s.id=1;
	s.name="armor";
	s.type=Item::Type::Armor;
	currentLevel->attach(new Item(s,Point(2,0)));
	s.id=2;
	Actor* a=new Actor();
	a->setName("Fox");
	a->addExp(10);
	a->setPos(Point(3,3));
	currentLevel->attach(a);
	currentLevel->attach(new Item(s,Point(2,2)));
	Log::Post("Rogue is a traditional RPG.");
}
void World::update(int code){
	switch(code){
		case '2':
		case '4':
		case '6':
		case '8':
		case 356:
		case 357:
		case 358:
		case 359:
			movePlayer(code);
			break;
		case '5':
			if(currentLevel->getMap().Get(player->getPos())=='>'){
			}else if(currentLevel->getMap().Get(player->getPos())=='<'){
			}
			break;
	}
	currentLevel->updateEnemy();
}
void World::draw(Console& console){
	currentLevel->draw(console);
}
void World::skipPlayerTurn(){
	currentLevel->updateEnemy();
}
void World::movePlayer(int code){
	Actor::Dir dir=Actor::Dir::None;
	switch(code){
		case '8':
		case 357://up arrow
			dir=Actor::Dir::Up;
			break;
		case '2':
		case 359://down arrow
			dir=Actor::Dir::Down;
			break;
		case '4':
		case 356://left arrow
			dir=Actor::Dir::Left;
			break;
		case '6':
		case 358://right arrow
			dir=Actor::Dir::Right;
			break;
	}
	currentLevel->Move(player,dir);
	if(currentLevel->atItem(player->getPos())){
		//pick up
		Log::Post(player->getName()+" picked "+currentLevel->atItem(player->getPos())->status.name);
		player->attach(currentLevel->detach(*(currentLevel->atItem(player->getPos()))));
	}
}
void World::descend(){
	currentLevel->detach(*player);
}
void World::climb(){
	currentLevel->detach(*player);
}