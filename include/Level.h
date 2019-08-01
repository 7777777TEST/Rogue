#ifndef _LEVEL_H
#define _LEVEL_H
#include<vector>
#include<assert.h>
#include<algorithm>
#include"Actor.h"
#include"Console.h"
class Level{
    public:
        Level(const char*);
        Map getMap()const;
        void draw(Console&)const;
        //For Actor
        bool Move(Actor*,Actor::Dir);
        void attach(Actor*);
        Actor* detach(Actor&);
        Actor* getPlayer();
        Actor* atActor(const Point);
        void updateEnemy();
        std::vector<Actor*> getActors()const;
        //For item
        void attach(Item*);
        Item* detach(Item&);
        Item* atItem(const Point);
    private:
        std::vector<Actor*> actors;
        std::vector<Item*> items;
        Map* map;
};
#endif