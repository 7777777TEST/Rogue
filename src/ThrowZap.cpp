#include"../include/ThrowZap.h"
#include"../include/Inventory.h"
void ThrowState::draw(){
}
void ThrowState::update(int code){
	switch(code){
		case '8':
		case 357:
			Log::Post("Up");
			throwUp();
			world->skipPlayerTurn();
			break;
		case '2':
		case 359:
			Log::Post("Down");
			throwDown();
			world->skipPlayerTurn();
			break;
		case '4':
		case 356:
			Log::Post("Left");
			throwLeft();
			world->skipPlayerTurn();
			break;
		case '6':
		case 358:
			Log::Post("Right");
			throwRight();
			world->skipPlayerTurn();
			break;
		default:
			Log::Post("You don't select.");
			break;
	}
	world->currentLevel->attach(item);
	sequence->Pop();
}
ThrowState::ThrowState(Item* _item,World* _world){
	item=_item;
	world=_world;
	Log::Post("In what direction?");
}
void ThrowState::throwUp(){
	Point pos=item->pos;
	while(1){
		pos.y--;
		if(!(*world).currentLevel->getMap().isMove(pos.x,pos.y)
			||(*world).currentLevel->atItem(pos)){
			pos.y++;
			item->pos=pos;
			return;
		}else if((*world).currentLevel->atActor(pos)){
			item->pos=pos;
			(*world).currentLevel->atActor(pos)->damage(10);
			if((*world).currentLevel->atActor(pos)->dead()){
				Log::Post("You kill "+(*world).currentLevel->atActor(pos)->getName());
			}else{
				Log::Post("You attack "+(*world).currentLevel->atActor(pos)->getName());
			}
			return;
		}
	}
}
void ThrowState::throwDown(){
	Point pos=item->pos;
	while(1){
		pos.y++;
		if(!(*world).currentLevel->getMap().isMove(pos.x,pos.y)
			||(*world).currentLevel->atItem(pos)){
			pos.y--;
			item->pos=pos;
			return;
		}else if((*world).currentLevel->atActor(pos)){
			item->pos=pos;
			(*world).currentLevel->atActor(pos)->damage(10);
			if((*world).currentLevel->atActor(pos)->dead()){
				Log::Post("You kill "+(*world).currentLevel->atActor(pos)->getName());
			}else{
				Log::Post("You attack "+(*world).currentLevel->atActor(pos)->getName());
			}
			return;
		}
	}
}
void ThrowState::throwLeft(){
	Point pos=item->pos;
	while(1){
		pos.x--;
		if(!(*world).currentLevel->getMap().isMove(pos.x,pos.y)
			||(*world).currentLevel->atItem(pos)){
			pos.x++;
			item->pos=pos;
			return;
		}else if((*world).currentLevel->atActor(pos)){
			item->pos=pos;
			(*world).currentLevel->atActor(pos)->damage(10);
			if((*world).currentLevel->atActor(pos)->dead()){
				Log::Post("You kill "+(*world).currentLevel->atActor(pos)->getName());
			}else{
				Log::Post("You attack "+(*world).currentLevel->atActor(pos)->getName());
			}
			return;
		}
	}
}
void ThrowState::throwRight(){
	Point pos=item->pos;
	while(1){
		pos.x++;
		if(!(*world).currentLevel->getMap().isMove(pos.x,pos.y)
			||(*world).currentLevel->atItem(pos)){
			pos.x--;
			item->pos=pos;
			return;
		}else if((*world).currentLevel->atActor(pos)){
			item->pos=pos;
			(*world).currentLevel->atActor(pos)->damage(10);
			if((*world).currentLevel->atActor(pos)->dead()){
				Log::Post("You kill "+(*world).currentLevel->atActor(pos)->getName());
			}else{
				Log::Post("You attack "+(*world).currentLevel->atActor(pos)->getName());
			}
			return;
		}
	}
}