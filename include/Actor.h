#ifndef _ACTOR_H
#define _ACTOR_H
#include"Map.h"
#include"Log.h"
#include"Item.h"
class Actor{
	public:
		struct Status{
			std::string name;
			int hp=20,maxhp=20,exp=0,level=1,str=3,maxstr=3,hunger=100,armor=0;
			bool visible=false;
		};
		enum Type{
			Hero,
			Enemy
		};
		enum Dir{
			Up,Down,Left,Right,None
		};
		Actor():pos(0,0){}
		Type type=Enemy;
		std::string getName()const;
		char getChar()const;
		int getHp()const;
		bool dead()const;
		int getMaxHp()const;
		int getExp()const;
		int getLevel()const;
		int getStr()const;
		int getMaxStr()const;
		int getHunger()const;
		int getArmor()const;
		bool isVisible()const;
		Point getPos()const;
		void setName(std::string);
		void addLevel(int);
		void addExp(int);
		void changeHp(int);
		void changeMaxHp(int);
		void changeStr(int);
		void changeHunger(int);
		void changeMaxStr(int);
		void changeArmor(int);
		void setPos(Point);
		void damage(int);
		void setVisible(bool);
		std::vector<Item*> getItems()const;
		void equip(Item*);
		bool rmEquip(Item*);
		bool isItem(Item*);
		bool Use(Item*);
		Item* detach(Item*);
		bool attach(Item*);
	private:
		Status status;
		Point pos;
		std::vector<Item*> items;
		const int maxitems=10;
};
#endif