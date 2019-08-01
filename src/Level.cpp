#include"../include/Level.h"
Level::Level(const char* data){
	map=new Map(data);
}
Map Level::getMap()const{
	return *map;
}
void Level::draw(Console& console)const{
	map->draw(console);
	for(Item* item:items){
		console.setChar(item->pos,item->getChar());
	}
	for(Actor* actor:actors){
		console.setChar(actor->getPos(),actor->getChar());
	}
}
void Level::updateEnemy(){
	for(Actor* actor:actors){
		if(actor->getHp()<=0)
			continue;
		if(actor->type==Actor::Type::Hero){
		}else{
			Actor* player=getPlayer();
			bool result=false;
			if(::abs(player->getPos().x-actor->getPos().x)>=
				::abs(player->getPos().y-actor->getPos().y)){
				if(player->getPos().x>actor->getPos().x){
					result=Move(actor,Actor::Dir::Right);
				}else if(player->getPos().x<actor->getPos().x){
					result=Move(actor,Actor::Dir::Left);
				}
				if(result)continue;
				if(player->getPos().y>actor->getPos().y){
					Move(actor,Actor::Dir::Down);
				}else if(player->getPos().y<actor->getPos().y){
					Move(actor,Actor::Dir::Up);
				}
			}else{
				if(player->getPos().y>actor->getPos().y){
					result=Move(actor,Actor::Dir::Down);
				}else if(player->getPos().y<actor->getPos().y){
					result=Move(actor,Actor::Dir::Up);
				}
				if(result)continue;
				if(player->getPos().x>actor->getPos().x){
					result=Move(actor,Actor::Dir::Right);
				}else if(player->getPos().x<actor->getPos().x){
					result=Move(actor,Actor::Dir::Left);
				}
			}
		}
	}
	for(Actor* actor:actors){
		if(actor->getHp()<=0){
			if(actor->type!=Actor::Type::Hero)
				actor=detach(*actor);
		}
	}
}
std::vector<Actor*> Level::getActors()const{
	return actors;
}
Actor* Level::getPlayer(){
	for(Actor* actor:actors){
		if(actor->type==Actor::Type::Hero){
			return actor;
		}
	}
}
bool Level::Move(Actor* actor,Actor::Dir dir){
	Point tp=Point(actor->getPos());
	switch(dir){
		case Actor::Dir::Left:
			tp.x--;
			break;
		case Actor::Dir::Right:
			tp.x++;
			break;
		case Actor::Dir::Up:
			tp.y--;
			break;
		case Actor::Dir::Down:
			tp.y++;
			break;
	}
	if(map->isMove(tp.x,tp.y)){
		if(atActor(tp)==nullptr){
			actor->setPos(tp);
			return true;
		}else{
			if(atActor(tp)->type!=actor->type){
				atActor(tp)->damage(actor->getStr());
				if(atActor(tp)->getHp()>0)
					Log::Post(actor->getName()+" attacked "+atActor(tp)->getName());
				else{
					Log::Post(actor->getName()+" killed "+atActor(tp)->getName());
					actor->addExp(atActor(tp)->getExp());	
				}
			}
		}
	}
	return false;
}
void Level::attach(Actor* actor){
	actors.emplace_back(actor);
}
Actor* Level::detach(Actor& target){
	Point pos=target.getPos();
	std::vector<Actor*>::iterator it=actors.begin();
	for(;it!=actors.end();++it){
		if((*it)->getPos()==pos){
			break;
		}
	}
	if(it==actors.end())
		return nullptr;
	actors.erase(it);
	Actor* actor=&target;
	return actor;
}
Actor* Level::atActor(Point pos){
	for (const auto& actor : actors)
	{
		if (actor->getPos() == pos)
			return actor;
	}
	return nullptr;
}
void Level::attach(Item* item){
	items.emplace_back(item);
}
Item* Level::detach(Item& target){
	Point pos=target.pos;
	std::vector<Item*>::iterator it=items.begin();
	for(;it!=items.end();++it){
		if((*it)->pos==pos){
			break;
		}
	}
	if(it==items.end())
		return nullptr;
	items.erase(it);
	Item* item=&target;
	return item;
}
Item* Level::atItem(Point pos){
	for (auto item : items)
	{
		if (item->pos == pos)
			return item;
	}
	return nullptr;
}