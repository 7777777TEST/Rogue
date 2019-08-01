#include"../include/Rogue.h"
#include"../include/Play.h"
namespace{
	Console MainConsole=Console(30,20);
	World world=World();
	Sequence sequence=Sequence();
}
void Rogue::Init(int argc,char* argv[]){
    glutInit(&argc,argv);
	glutCreateWindow("Rogue");
	ImGui::CreateContext();
	State::init(sequence,MainConsole);
	sequence.Push(new Play());
	// Setup Platform/Renderer bindings
	ImGui_ImplGLUT_Init();
	ImGui_ImplGLUT_InstallFuncs();
	ImGui_ImplOpenGL2_Init();
	setStyle();
	sequence.draw();
	glutDisplayFunc(Rogue::Render);
	glutMainLoop();
    // Cleanup
    ImGui_ImplOpenGL2_Shutdown();
    ImGui_ImplGLUT_Shutdown();
    ImGui::DestroyContext();
}
void Rogue::Render(){
	ImGui_ImplOpenGL2_NewFrame();
	ImGui_ImplGLUT_NewFrame();
	ImGuiIO &io = ImGui::GetIO();
	//Process Input
	for (int i = 0; i < IM_ARRAYSIZE(io.KeysDown); i++)
		if (ImGui::IsKeyReleased(i))
		{
			Rogue::handleKey(i);
		}
	sequence.draw();
	Log::draw();
	MainConsole.draw();
	ImGui::Render();
	glViewport(0, 0, (GLsizei)io.DisplaySize.x, (GLsizei)io.DisplaySize.y);
	glClear(GL_COLOR_BUFFER_BIT);
	ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());

	glutSwapBuffers();
	glutPostRedisplay();
}
void Rogue::handleKey(int code){
	sequence.update(code);
}
void Rogue::setStyle(){
	ImGuiStyle style;
	style.Alpha = 1.0;
	style.FrameRounding = 0.0;
	style.PopupRounding = 0.0;
	style.TabRounding = 0.0;
	style.WindowRounding = 0.0;
	style.ChildRounding = 0.0;
	style.GrabRounding = 0.0;
	style.ScrollbarRounding = 0.0;

	style.Colors[ImGuiCol_FrameBg] = ImVec4(0.0f, 0.5f, 0.0f, 0.0f);
	style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.3f, 0.3f, 0.3f, 256);
	style.Colors[ImGuiCol_TitleBg] = ImVec4(0.8f, 0.8f, 0.8f, 256);
	style.Colors[ImGuiCol_Border] = ImVec4(0.0f, 0.5f, 0.8f, 118.0f);
	style.Colors[ImGuiCol_TitleBg] = ImVec4(0.0f, 0.5f, 0.8f, 256);
	style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.0f, 0.5f, 0.8f, 118.0f);
	style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.0f, 0.5f, 0.8f, 118.0f);
	style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.0f, 0.5f, 0.8f, 118.0f);
	ImGui::GetStyle() = style;
}