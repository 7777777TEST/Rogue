#include"../include/Log.h"
#include"../imgui/imgui.h"
namespace{
    std::vector<std::string> buf;
	const int size=10;
}
void Log::draw(){
	{
		ImGui::Begin("Log");
		if (buf.size())
		{
			for (int i = buf.size() - 1; i >= 0; --i)
			{
				ImGui::Text("%s", buf[i].c_str());
			}
		}
		ImGui::SetScrollHereY(1.0);
		ImGui::End();
	}
}
void Log::Post(std::string s){
	std::vector<std::string>::iterator it=buf.begin();
	it=buf.insert(it,s);
	while(buf.size()>size){
		buf.pop_back();
	}
}
void Log::Post(const char* s){
	std::vector<std::string>::iterator it=buf.begin();
	it=buf.insert(it,std::string(s));
	while(buf.size()>size){
		buf.pop_back();
	}
}