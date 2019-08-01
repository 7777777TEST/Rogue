#ifndef _INVENTORY_H
#define _INVENTORY_H
#include"State.h"
#include"World.h"
#include"Sequence.h"
class Actor;
class Item;
class Inventory:public State{
    public:
        Inventory(Actor*,World*);
        void update(int)override;
        void draw()override;
    private:
        void Use();
        void Drop();
        void Throw();
        Actor* actor;
        World* world;
        std::vector<Item*> items;
        int selected=-1;
        int currentCmd=-1;
        std::vector<std::string> commands;
};
#endif