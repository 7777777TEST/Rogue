#include"../include/Play.h"
#include"../include/Inventory.h"
Play::Play():world(){
}
void Play::update(int code){
	if(world.player->dead())return;
    if(code=='0'){
        sequence->Push(new Inventory(world.player,&world));
        return;
    }
    world.update(code);
    if(world.player->dead()){
        Log::Post("You died...");
    }
}
void Play::draw(){
    world.draw(*console);
}
