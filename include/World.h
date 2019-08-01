#ifndef _WORLD_H
#define _WORLD_H
#include"Level.h"
class World{
    public:
        World();
        void update(int);
        void draw(Console&);
        void skipPlayerTurn();
        Level& getLevel();
        void descend();
        void climb();
        int getDepth();
        Level* currentLevel;
        Actor* player;
    private:
        void movePlayer(int);
        int depth=1;
        const int maxDepth=100;
        std::vector<Level*> levels;
};
#endif
