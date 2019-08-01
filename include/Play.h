#ifndef _PLAY_H
#define _PLAY_H
#include"State.h"
#include"World.h"
class Play:public State{
    public:
        Play();
        void update(int)override;
        void draw()override;
    private:
        World world;
};
#endif