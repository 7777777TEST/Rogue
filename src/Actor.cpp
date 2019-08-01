#include"../include/Actor.h"
#include"../include/Point.h"
int Actor::getExp()const{
	return status.exp;
}
int Actor::getHp()const{
	return status.hp;
}
bool Actor::dead()const{
	return status.hp<=0;
}
int Actor::getMaxHp()const{
	return status.maxhp;
}
int Actor::getStr()const{
	return status.str;
}
int Actor::getMaxStr()const{
	return status.maxstr;
}
int Actor::getLevel()const{
	return status.level;
}
std::string Actor::getName()const{
	return status.name;
}
char Actor::getChar()const{
	if(type==Actor::Type::Hero)
		return '@';
	if(getName().length()>1){
		return getName()[0];
	}
	return 'F';
}
int Actor::getHunger()const{
	return status.hunger;
}
int Actor::getArmor()const{
	return status.armor;
}
Point Actor::getPos()const{
	return pos;
}
bool Actor::isVisible()const{
	return status.visible;
}
void Actor::setVisible(bool value){
	status.visible=value;
}
void Actor::setName(std::string _name){
	status.name=_name;
}
void Actor::addExp(int value){
	status.exp+=value;
}
void Actor::addLevel(int value){
	status.level+=value;
}
void Actor::changeHp(int value){
	status.hp+=value;
	if(status.hp>status.maxhp)
		status.hp=status.maxhp;
}
void Actor::changeMaxHp(int value){
	status.maxhp+=value;
}
void Actor::changeStr(int value){
	status.str+=value;
	if(status.str>status.maxstr)
		status.str=status.maxstr;
}
void Actor::changeMaxStr(int value){
	status.maxstr+=value;
}
void Actor::setPos(Point _pos){
	pos.x=_pos.x;
	pos.y=_pos.y;
}
void Actor::damage(int value){
	if(value>getArmor())
		status.hp-=(value-getArmor());
	else{}
	if(status.hp<0){
		status.hp=0;
	}
}
std::vector<Item*> Actor::getItems()const{
	return items;
}
void Actor::changeHunger(int value){
	status.hunger+=value;
}
void Actor::changeArmor(int value){
	status.armor+=value;
}
bool Actor::attach(Item* target){
	for(Item* item:items){
		if(target->status.id==item->status.id&&
			target->status.type==item->status.type){
				item->status.count+=target->status.count;
				return true;
		}
	}
	if(items.size()>=maxitems-1)
		return false;//failed
	items.emplace_back(target);
	return true;
}
Item* Actor::detach(Item* target){
	std::vector<Item*>::iterator it=items.begin();
	for(;it!=items.end();++it){
		if(target->status.id==(*it)->status.id&&
			target->status.type==(*it)->status.type)
				break;
	}
	if(it==items.end())
		return nullptr;
	Item::Status ts=(*it)->status;
	ts.count--;
	if(ts.count<=0)
		items.erase(it);
	(*it)->status.count--;
	ts.count=1;
	return (new Item(ts,pos));
}
bool Actor::isItem(Item* target){
	for(Item* item:items){
		if(target->status.id==item->status.id&&
			target->status.type==item->status.type){
					return true;
		}
	}
	return false;
}
bool Actor::Use(Item* item){
	if(!isItem(item))return false;//failed
	switch(item->status.type){
		case Item::Type::Potion:
			changeHp(item->status.value);
			if(item->status.value>0){
				Log::Post("You feel better");
			}else{
				Log::Post("You feel worse");
			}
			delete detach(item);
			break;
		case Item::Type::Food:
			changeHunger(item->status.value);
			if(item->status.value>20){
				Log::Post("It's very delicious!");
				changeHp(5);
				Log::Post("You feel better.");
			}else{
				Log::Post("It's delicious.");
			}
			break;
		case Item::Type::Armor:
			if(item->status.equip){
				rmEquip(item);
				Log::Post("You have removed "+item->status.name);
			}else{
				equip(item);
				Log::Post("You have worn "+item->status.name);
			}
			break;
	}
	return true;
}
void Actor::equip(Item* target){
	for(auto& item:items){
		if(item->status.id==target->status.id&&
			item->status.type==target->status.type){
				switch(item->status.type){
					case Item::Type::Armor:
						changeArmor(item->status.value);
						break;
					case Item::Type::Weapon:
						changeStr(item->status.value);
						break;
				}
				item->status.equip=true;
		}else if(item->status.equip&&
			item->status.type==item->status.type){
				switch(item->status.type){
					case Item::Type::Armor:
						changeArmor(item->status.value);
						break;
					case Item::Type::Weapon:
						changeStr(item->status.value);
						break;
				}
				item->status.equip=false;
		}
	}
}
bool Actor::rmEquip(Item* target){
	for(auto& item:items){
		if(item->status.id==target->status.id&&
			item->status.type==target->status.type){
				item->status.equip=false;
				switch(item->status.type){
					case Item::Type::Armor:
						changeArmor(-item->status.value);
						break;
					case Item::Type::Weapon:
						changeStr(-item->status.value);
						break;
				}
		}
	}
}