#include"../include/Item.h"
Item::Item(Item::Status _status,Point _pos):pos(_pos.x,_pos.y){
    status.name=std::string(_status.name.c_str());
    status.help=std::string(_status.help.c_str());
    status.identify=std::string(_status.identify.c_str());
    status.count=_status.count;
    status.id=_status.id;
    status.type=_status.type;
    status.value=_status.value;
    status.equip=_status.equip;
}
char Item::getChar()const{
    switch(status.type){
        case Type::Potion:
            return '!';
        case Type::Armor:
            return '[';
        case Type::Weapon:
            return '(';
    }
}
bool Item::hasFlag(Flags flag) const
{
	return status.flags & flag;
}

void Item::addFlag(Flags flag)
{
	status.flags |= flag;
}

void Item::removeFlag(Flags flag)
{
	status.flags &= ~flag;
}