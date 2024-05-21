#pragma once

#include "App.h"
#include <chrono>
#include <thread>
#include "frameResult.h"

struct Proc {
	int ID;
	int start;
	int duration;
	int waitTime = 0;
	int firstArrTime = -1;

	Proc(int _id, int _start, int _dur) : ID(_id), start(_start), duration(_dur) {}
};

struct ProcEvent {
	int state; // 0: end, 1: start, 2: swappedout, 3: queue update
	int ID; // 1: 1, 2: 2, 3: 4, 4: 8
	int time;
};

class frameMain : public wxFrame
{
public:
	frameMain();
	~frameMain();
private:
	// Controls
	wxFont defaultFont = wxFont(wxFontInfo(12));

	wxTextCtrl* entryP1Burst;
	wxTextCtrl* entryP1Arriv;
	wxTextCtrl* entryP2Burst;
	wxTextCtrl* entryP2Arriv;
	wxTextCtrl* entryP3Burst;
	wxTextCtrl* entryP3Arriv;
	wxTextCtrl* entryP4Burst;
	wxTextCtrl* entryP4Arriv;

	wxCheckBox* checkPreemptive;

	wxButton* buttonStart;
	wxButton* buttonViewResult;

	wxStaticText* txQueue;

	wxTextCtrl* txLog;

	wxStaticText* labelTElapse;
	wxGauge* gaugeTime;

	// Misc components
	wxTimer gaugeTimer;
	int milisecElapse = 0;
	long totalTime;
	std::vector<int> waitTime = { -1, -1, -1, -1 };
	std::vector<int> turnTime = { -1, -1, -1, -1 };

	// Events
	void startSim(wxCommandEvent& event);
	void onTimerTick(wxTimerEvent & event);
	// Methods
	void logAppend(const char* str);
	void logAppend(std::string str);
	void onCompletion();
	std::string getCurrentTime();
};

