#include"../include/Console.h"
#include"../imgui/imgui.h"
Console::Console(int _w,int _h){
    w=_w;
    h=_h;
    for(int y=0;y<_h;++y){
        buf.push_back(std::string(" "));
        for(int x=0;x<_w;++x)
            buf[y].append(" ");
    }
}
void Console::setChar(int x,int y,char c){
    if(x<0||x>=w||y<0||y>=h)
        return;
    buf[y][x]=c;
}
void Console::setChar(Point pos,char c){
    setChar(pos.x,pos.y,c);
}
void Console::setString(int x,int y,std::string s){
    int dx=0,dy=0;
    for(char c:s){
        if(c=='\n'){
            ++dy;
            dx=0;
        }else{
            setChar(x+dx,y+dy,c);
            ++dx;
        }
    }
}
void Console::draw(){
	{
        ImGui::PushStyleColor(ImGuiCol_WindowBg,ImVec4(0.0,0.0,0.0,1.0f));
		ImGui::Begin("Main Window");
		for(std::string str:buf){
			ImGui::Text(str.c_str());
		}
		ImGui::End();
        ImGui::PopStyleColor();
	}
}
void Console::clear(){
    for(int x=0;x<w;++x){
        for(int y=0;y<h;++y){
            buf[y][x]=' ';
        }
    }
}
int Console::width()const{
    return w;
}
int Console::height()const{
    return h;
}