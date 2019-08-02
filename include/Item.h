#ifndef _ITEM_H
#define _ITEM_H
#include<string>
#include"Point.h"
class Item{
	public:
		enum Type{
			Potion,
			Scroll,
			Food,
			Weapon,
			Armor,
			Ring,
			Gold,
			Amulet,
			Wand,
			MaxType
		};
		enum Flags{
			None		= 0,
			IsCursed	= 1 << 0,
			IsKnow		= 1 << 1,
			IsMissile	= 1 << 2,
			IsMany		= 1 << 3,
			IsProtected	= 1 << 4,
			IsFound		= 1 << 5,
			IsDetected	= 1 << 6,
		};
		struct Status{
			std::string name,help,identify;
			int value=10;
			int type=Potion;
			int id=0;
			int count=1;
			int flags;
			bool equip=false;
		};
		Status status;
		Point pos;
		Item(Item::Status,Point);
		char getChar()const;
		bool hasFlag(Flags flag) const;
		void addFlag(Flags flag);
		void removeFlag(Flags flag);
};
#endif