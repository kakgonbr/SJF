#include "frameResult.h"

frameResult::frameResult(std::vector<int> waitTime, std::vector<int> turnTime, wxWindow* parent) : wxFrame(parent, wxID_ANY, "Last run result", wxDefaultPosition, wxDefaultSize) {
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	wxStaticText* labelResult = new wxStaticText(this, wxID_ANY, wxEmptyString);
	labelResult->SetFont(wxFont(wxFontInfo(12)));

	if (waitTime.at(0) == -1) {
		labelResult->SetLabel("Result of the previous run not available.");
	}
	else {
		labelResult->SetLabel("\tWait Time (seconds): \
								\n P1: " + std::to_string(waitTime.at(0))
			+ "\n P2 : " + std::to_string(waitTime.at(1))
			+ "\n P3 : " + std::to_string(waitTime.at(2))
			+ "\n P4 : " + std::to_string(waitTime.at(3))
			+ "\n Average: " + std::to_string((waitTime.at(0) + waitTime.at(1) + waitTime.at(2) + waitTime.at(3)) / (double)4)
			+ "\n\n\tTurnaround Time (seconds): \
								\n P1: " + std::to_string(turnTime.at(0))
			+ "\n P2 : " + std::to_string(turnTime.at(1))
			+ "\n P3 : " + std::to_string(turnTime.at(2))
			+ "\n P4 : " + std::to_string(turnTime.at(3))
			+ "\n Average: " + std::to_string((turnTime.at(0) + turnTime.at(1) + turnTime.at(2) + turnTime.at(3)) / (double)4));
	}
	mainSizer->Add(labelResult, 1, wxEXPAND | wxALL, FromDIP(5));

	SetSizer(mainSizer);
	SetBackgroundColour(*wxWHITE);

	SetSize(FromDIP(wxSize(300, 450)));
}

frameResult::~frameResult()
{
}
