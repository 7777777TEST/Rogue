#include"../include/Sequence.h"
void Sequence::Push(State* state){
    actionStack.emplace_back(Ctrl::push,state);
}
void Sequence::Pop(){
    actionStack.emplace_back(Ctrl::pop,nullptr);
}
void Sequence::Clear(){
    actionStack.emplace_back(Ctrl::clear,nullptr);
}
bool Sequence::isEmpty()const{
    return stack.empty();
}
void Sequence::apply(){
    for(auto& change:actionStack){
        switch(change.first){
            case Ctrl::push:
                stack.emplace_back(change.second);
                break;
            case Ctrl::pop:
                stack.pop_back();
                break;
            case Ctrl::clear:
                stack.clear();
                break;
        }
    }
    actionStack.clear();
}
void Sequence::update(int code){
    if(!isEmpty()){
        stack.back()->update(code);
    }
    apply();
}
void Sequence::draw(){
    for(auto& state:stack){
        state->draw();
    }
}