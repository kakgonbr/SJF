#include "App.h"

wxIMPLEMENT_APP(App);

App::App()
{
}

App::~App()
{
}

bool App::OnInit() {
	frameMain* main_frame = new frameMain();

	main_frame->Show();

	return true;
}
