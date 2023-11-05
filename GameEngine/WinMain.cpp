#include "Window.h"

int _stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) 
{
	Window window(1280, 720, "Basic Window");

	while (true)
	{
		if (const auto msgCode = Window::ProcessMessages())
			return *msgCode;
	}
}