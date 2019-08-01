#include"../include/Inventory.h"
#include"../include/ThrowZap.h"
#include<sstream>
Inventory::Inventory(Actor* _actor,World* _World){
	actor=_actor;
	world=_World;
	items=actor->getItems();
}
void Inventory::update(int code){
	if(actor->dead())return;
	items=std::vector<Item*>(actor->getItems());
	if(currentCmd>=0){
		switch(code){
			case '0':
			case 356://left arrow
				currentCmd=-1;
				break;
			case '8':
			case 357://up arrow
				currentCmd=(currentCmd+commands.size()-1)%commands.size();
				break;
			case '2':
			case 359://down arrow
				currentCmd=(currentCmd+1)%commands.size();
				break;
			case '5':
			case '\n':
			case 358://right arrow
				sequence->Pop();
				console->clear();
				switch(currentCmd){
					case 1:
						Drop();
						break;
					case 2:
						Throw();
						break;
					default:
						Use();
						break;
				}
				break;
		}
		return;
	}
	switch(code){
		case '2':
		case 359://down arrow
			if (selected >= 0){
				selected = (selected + 1) % items.size();
			}
			break;
		case '8'://up arrow
		case 357:
			selected=(selected+items.size()-1)%items.size();
			break;
		case '5':
		case '\n':
		case 358://right arrow
			if(items.empty())break;
			commands.clear();
			currentCmd = 0;
			if(!items[selected]->status.equip){
				commands.emplace_back("Use");
			}else{
				commands.emplace_back("Remove");
			}
			commands.emplace_back("Drop");
			commands.emplace_back("Throw");
			break;
		case '0':
		case 356://left arrow
			sequence->Pop();
			console->clear();
			break;
	}
}
void Inventory::draw(){
	if(actor->dead())return;
	console->clear();
	items=std::vector<Item*>(actor->getItems());
	int width = 20;
	int height = items.size() + 2;
	int left = 1;
	int top = 1;

	if (height <= 2)
		height = 3;
	else if (selected < 0)
		selected = 0;

	for(int i=0;i<items.size();++i){
		std::string name="";
		if(i==selected){
			name+="> ";
		}else{
			name+="  ";
		}
		name+=items[i]->status.name;
		int x = left + 2;
		int y = top + 1 + i;
		console->setString(x,y,name);
	}
	if (items.empty()){
		std::string str = "Your bag is empty.";
		console->setString(left, top + 1, str);
	}
	if(currentCmd>=0){
		int x=left+width;
		int y=top;
		for (int i = 0; i < commands.size(); ++i){
			if (i == currentCmd)
				console->setString(x + 2, y + 1 + i, "> " + commands[i]);
			else
				console->setString(x + 2, y + 1 + i, "  " + commands[i]);
		}
	}
	drawRect(left, top, width, height);
}
void Inventory::Drop(){
	if(!world->currentLevel->atItem(actor->getPos())){
		Log::Post(actor->getName()+" put "+items[selected]->status.name);
		world->currentLevel->attach(actor->detach(actor->getItems()[selected]));
	}else{
		Log::Post("You cannot put item on something.");
	}
	world->skipPlayerTurn();
}
void Inventory::Use(){
	actor->Use(items[selected]);
	world->skipPlayerTurn();
}
void Inventory::Throw(){
	sequence->Push(new ThrowState(actor->detach(items[selected]),world));
}