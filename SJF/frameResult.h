#pragma once
#include "wx/wx.h"

class frameResult : public wxFrame
{
public:
	frameResult(std::vector<int> waitTime, std::vector<int> turnTime, int procRan, wxWindow* parent);
	~frameResult();
};

