#pragma once

#include "wx/wx.h"
#include "frameMain.h"

class App : public wxApp
{
public:
	App();
	~App();

	bool OnInit();
};

wxDECLARE_APP(App);