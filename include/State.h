#ifndef _STATE_H
#define _STATE_H
class Sequence;
class Console;
class State{
    public:
        virtual ~State()=default;
        virtual void update(int)=0;
        virtual void draw()=0;
        static void init(Sequence&,Console&);
    protected:
        void drawRect(int,int,int,int);
        static Sequence* sequence;
        static Console* console;
};
#endif