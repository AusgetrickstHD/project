#include "App.h"
#include <sstream>
#include <iomanip>
#include <iostream>

App::App() 
	:
	wnd(600,800,L"lulll")
{}

int App::Go() {

	while (true) {
		if ( const auto error = Window::ProcessMessages() ) {
			return *error;
		}

		wnd.Gfx().EndFrame();
	}
}

void App::UpdateDelta() noexcept  {
	
}