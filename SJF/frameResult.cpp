#include "frameResult.h"

frameResult::frameResult(std::vector<int> waitTime, std::vector<int> turnTime, int procRan, wxWindow* parent) : wxFrame(parent, wxID_ANY, "Last run result", wxDefaultPosition, wxDefaultSize) {
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	wxStaticText* labelResult = new wxStaticText(this, wxID_ANY, wxEmptyString);
	labelResult->SetFont(wxFont(wxFontInfo(12)));

	if (procRan) {
		labelResult->SetLabel("\tWait Time (seconds): \
								\n P1: " + std::to_string(waitTime.at(0))
			+ "\n P2 : " + std::to_string(waitTime.at(1))
			+ "\n P3 : " + std::to_string(waitTime.at(2))
			+ "\n P4 : " + std::to_string(waitTime.at(3))
			+ "\n Average: " + std::to_string((waitTime.at(0) + waitTime.at(1) + waitTime.at(2) + waitTime.at(3)) / (double)procRan)
			+ "\n\n\tTurnaround Time (seconds): \
								\n P1: " + std::to_string(turnTime.at(0))
			+ "\n P2 : " + std::to_string(turnTime.at(1))
			+ "\n P3 : " + std::to_string(turnTime.at(2))
			+ "\n P4 : " + std::to_string(turnTime.at(3))
			+ "\n Average: " + std::to_string((turnTime.at(0) + turnTime.at(1) + turnTime.at(2) + turnTime.at(3)) / (double)procRan)
			+ "\n\nProcesses ran: " + std::to_string(procRan));
	}
	else {
		labelResult->SetLabel("\n\n\nResult of previous run not available.");
	}

	mainSizer->Add(labelResult, 1, wxEXPAND | wxALL, FromDIP(5));

	SetSizer(mainSizer);
	SetBackgroundColour(*wxWHITE);

	SetSize(FromDIP(wxSize(300, 450)));
}

frameResult::~frameResult()
{
}
