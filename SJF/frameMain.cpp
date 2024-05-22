#include "frameMain.h"

frameMain::frameMain() : 
	wxFrame(nullptr, wxID_ANY, "SJF Demo", wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX)){

	wxBoxSizer* mainSizer = new wxBoxSizer(wxHORIZONTAL);

	// Controls
	wxBoxSizer* ctrlSizer = new wxBoxSizer(wxVERTICAL);
	// P1
	wxBoxSizer* p1Sizer = new wxBoxSizer(wxHORIZONTAL);
	
	wxStaticText* labelP1 = new wxStaticText(this, wxID_ANY, "P1: ", wxDefaultPosition, wxDefaultSize);
	labelP1->SetFont(defaultFont);
	entryP1Burst = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(100, 30), wxTE_RIGHT);
	entryP1Burst->SetHint("Burst");
	entryP1Burst->SetFont(defaultFont);
	entryP1Arriv = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(100, 30), wxTE_RIGHT);
	entryP1Arriv->SetFont(defaultFont);
	entryP1Arriv->SetHint("Arrival");

	p1Sizer->Add(labelP1, 0, wxALL, FromDIP(5));
	p1Sizer->Add(entryP1Burst, 0, wxALL, FromDIP(5));
	p1Sizer->Add(entryP1Arriv, 0, wxALL, FromDIP(5));

	ctrlSizer->Add(p1Sizer, 0, wxTOP, FromDIP(15));

	// P2
	wxBoxSizer* p2Sizer = new wxBoxSizer(wxHORIZONTAL);

	wxStaticText* labelP2 = new wxStaticText(this, wxID_ANY, "P2: ", wxDefaultPosition, wxDefaultSize);
	labelP2->SetFont(defaultFont);
	entryP2Burst = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(100, 30), wxTE_RIGHT);
	entryP2Burst->SetHint("Burst");
	entryP2Burst->SetFont(defaultFont);
	entryP2Arriv = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(100, 30), wxTE_RIGHT);
	entryP2Arriv->SetFont(defaultFont);
	entryP2Arriv->SetHint("Arrival");

	p2Sizer->Add(labelP2, 0, wxALL, FromDIP(5));
	p2Sizer->Add(entryP2Burst, 0, wxALL, FromDIP(5));
	p2Sizer->Add(entryP2Arriv, 0, wxALL, FromDIP(5));

	ctrlSizer->Add(p2Sizer, 0, wxTOP, FromDIP(15));

	// P3
	wxBoxSizer* p3Sizer = new wxBoxSizer(wxHORIZONTAL);

	wxStaticText* labelP3 = new wxStaticText(this, wxID_ANY, "P3: ", wxDefaultPosition, wxDefaultSize);
	labelP3->SetFont(defaultFont);
	entryP3Burst = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(100, 30), wxTE_RIGHT);
	entryP3Burst->SetHint("Burst");
	entryP3Burst->SetFont(defaultFont);
	entryP3Arriv = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(100, 30), wxTE_RIGHT);
	entryP3Arriv->SetFont(defaultFont);
	entryP3Arriv->SetHint("Arrival");

	p3Sizer->Add(labelP3, 0, wxALL, FromDIP(5));
	p3Sizer->Add(entryP3Burst, 0, wxALL, FromDIP(5));
	p3Sizer->Add(entryP3Arriv, 0, wxALL, FromDIP(5));

	ctrlSizer->Add(p3Sizer, 0, wxTOP, FromDIP(15));

	// P4
	wxBoxSizer* p4Sizer = new wxBoxSizer(wxHORIZONTAL);

	wxStaticText* labelP4 = new wxStaticText(this, wxID_ANY, "P4: ", wxDefaultPosition, wxDefaultSize);
	labelP4->SetFont(defaultFont);
	entryP4Burst = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(100, 30), wxTE_RIGHT);
	entryP4Burst->SetHint("Burst");
	entryP4Burst->SetFont(defaultFont);
	entryP4Arriv = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(100, 30), wxTE_RIGHT);
	entryP4Arriv->SetFont(defaultFont);
	entryP4Arriv->SetHint("Arrival");

	p4Sizer->Add(labelP4, 0, wxALL, FromDIP(5));
	p4Sizer->Add(entryP4Burst, 0, wxALL, FromDIP(5));
	p4Sizer->Add(entryP4Arriv, 0, wxALL, FromDIP(5));

	ctrlSizer->Add(p4Sizer, 0, wxTOP, FromDIP(15));

	checkPreemptive = new wxCheckBox(this, wxID_ANY, "Preemptive Shortest Job First", wxDefaultPosition, wxDefaultSize);
	checkPreemptive->SetFont(defaultFont);
	
	ctrlSizer->Add(checkPreemptive, 0, wxEXPAND | wxALL, FromDIP(5));

	buttonStart = new wxButton(this, wxID_ANY, "Start Scheduler Simulation", wxDefaultPosition, wxSize(1, 50));
	buttonStart->SetFont(defaultFont);
	buttonStart->Bind(wxEVT_BUTTON, &frameMain::startSim, this);

	ctrlSizer->Add(buttonStart, 0, wxEXPAND | wxALL, FromDIP(10));

	buttonViewResult = new wxButton(this, wxID_ANY, "View result", wxDefaultPosition, wxSize(1, 50));
	buttonViewResult->SetFont(defaultFont);
	buttonViewResult->Bind(wxEVT_BUTTON, [this] (wxCommandEvent&){
		(new frameResult(waitTime, turnTime, procRan, this))->Show();
		});

	ctrlSizer->Add(buttonViewResult, 0, wxEXPAND | wxALL, FromDIP(5));

	txQueue = new wxStaticText(this, wxID_ANY, "Processes in queue:\n\n\n\n", wxDefaultPosition, wxDefaultSize);
	txQueue->SetFont(defaultFont);

	ctrlSizer->Add(txQueue, 0, wxEXPAND | wxALL, FromDIP(5));

	mainSizer->Add(ctrlSizer, 0, wxALL, FromDIP(0));
	// End of ctrl

	// Info and Log
	wxBoxSizer* infoSizer = new wxBoxSizer(wxVERTICAL);

	// Time gauge
	labelTElapse = new wxStaticText(this, wxID_ANY, "Press start to start simulation",
		wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
	labelTElapse->SetFont(defaultFont);
	gaugeTime = new wxGauge(this, wxID_ANY, 1000,
		wxDefaultPosition, wxSize(1, 30),
		wxGA_HORIZONTAL | wxGA_SMOOTH);

	// Log
	txLog = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(1, 450),
		wxTE_READONLY | wxTE_MULTILINE | wxTE_RICH2 | wxNO_BORDER | wxTE_NO_VSCROLL);
	txLog->Bind(wxEVT_MOUSEWHEEL, [this](wxMouseEvent& event) {
		txLog->ScrollLines((event.GetWheelRotation() > 0) ? -5 : 5);
		});
	txLog->SetBackgroundColour(*wxBLACK);
	txLog->SetDefaultStyle(wxTextAttr(*wxWHITE, wxNullColour, defaultFont));

	infoSizer->Add(labelTElapse, 0, wxEXPAND | wxALL, FromDIP(5));
	infoSizer->Add(gaugeTime, 0, wxEXPAND | wxALL, FromDIP(5));
	infoSizer->Add(txLog, 0, wxEXPAND | wxALL, FromDIP(5));

	mainSizer->Add(infoSizer, wxALL, FromDIP(5));

	SetBackgroundColour(*wxWHITE);
	SetSizer(mainSizer);

	SetPosition(FromDIP(wxPoint(100, 100)));
	SetSize(FromDIP(wxSize(1000, 500)));

	gaugeTimer.Bind(wxEVT_TIMER, &frameMain::onTimerTick, this);
}
frameMain::~frameMain()
{
}

void frameMain::startSim(wxCommandEvent& event)
{
	long valP1Burst = 0;
	long valP1Arriv = 0;
	long valP2Burst = 0;
	long valP2Arriv = 0;
	long valP3Burst = 0;
	long valP3Arriv = 0;
	long valP4Burst = 0;
	long valP4Arriv = 0;

	if (entryP1Burst->GetValue().ToLong(&valP1Burst)
		&& entryP1Arriv->GetValue().ToLong(&valP1Arriv)
		&& valP1Arriv >= 0 && valP1Burst >= 0

		&& entryP2Burst->GetValue().ToLong(&valP2Burst)
		&& entryP2Arriv->GetValue().ToLong(&valP2Arriv)
		&& valP2Arriv >= 0 && valP2Burst >= 0

		&& entryP3Burst->GetValue().ToLong(&valP3Burst)
		&& entryP3Arriv->GetValue().ToLong(&valP3Arriv)
		&& valP3Arriv >= 0 && valP3Burst >= 0

		&& entryP4Burst->GetValue().ToLong(&valP4Burst)
		&& entryP4Arriv->GetValue().ToLong(&valP4Arriv)
		&& valP4Arriv >= 0 && valP4Burst >= 0) {

		buttonStart->Enable(false);
		txLog->Clear();

		logAppend("Starting simulation");

		// Calculate
		std::vector<Proc> processes = {
			{1, valP1Arriv, valP1Burst},
			{2, valP2Arriv, valP2Burst},
			{3, valP3Arriv, valP3Burst},
			{4, valP4Arriv, valP4Burst}
		};

		int currentTime = 0;
		Proc* currentProc = nullptr;

		std::vector<Proc*> procQueue;
		std::vector<ProcEvent> procEvent;
		
		int procEnded = 0;
		int procInQueue = 0;
		procRan = 0;

		while (procEnded < 4) {
			for (int i = 0; i < processes.size(); i++) {
				if (currentTime == processes.at(i).start) {
					if (processes.at(i).duration) {
						procQueue.push_back(&processes.at(i));
						processes.at(i).firstArrTime = currentTime;
					}
					else
						procEnded++;
				}
			}
			
			std::sort(procQueue.begin(), procQueue.end(), [](const Proc* p1, const Proc* p2) {
				return p1->duration > p2->duration;
				});

			// End a process
			if (currentProc && (currentProc->start + currentProc->duration) <= currentTime) {
				procEvent.push_back({ 0, currentProc->ID, currentTime});
				waitTime[currentProc->ID - 1] = currentProc->waitTime;
				turnTime[currentProc->ID - 1] = currentTime - currentProc->firstArrTime;
				currentProc = nullptr;
				procEnded++;
				procRan++;
			}
			// If preemptive mode is enabled, try to swap process
			if (checkPreemptive->GetValue() &&
				!procQueue.empty() && currentProc &&
				procQueue.back()->duration <= (currentProc->start + currentProc->duration) - currentTime) {
				Proc* fasterProc = procQueue.back();
				procQueue.pop_back();

				procEvent.push_back({ 2, currentProc->ID, currentTime });
				currentProc->duration = currentProc->start + currentProc->duration - currentTime;
				procQueue.push_back(currentProc);

				currentProc = fasterProc;
				currentProc->start = currentTime;
				procEvent.push_back({ 1, currentProc->ID, currentTime });
			}

			// If possible, start a process
			if (!procQueue.empty() && !currentProc) {
				currentProc = procQueue.back();
				procQueue.pop_back();
				currentProc->start = currentTime;
				
				procEvent.push_back({ 1, currentProc->ID, currentTime});
			}

			// Get processes in queue
			for (Proc* process : procQueue) {
				process->waitTime++;
				procInQueue += pow(2, process->ID - 1);
			}
			procEvent.push_back({ 3, procInQueue, currentTime });
			procInQueue = 0;
			
			currentTime++;
		}

		totalTime = currentTime;
		milisecElapse = 0;
		gaugeTime->SetValue(0);
		gaugeTimer.Start(100);

		const auto fnc = [this, procEvent]() {
			int prevTime = 0;
			for (const ProcEvent& event : procEvent) {
				Sleep(event.time * 1000 - prevTime);
				prevTime = event.time * 1000;
				switch (event.state)
				{
				case 0:
					logAppend("Process " + std::to_string(event.ID) + " stopped.");
					break;
				case 1:
					logAppend("Process " + std::to_string(event.ID) + " started executing.");
					break;
				case 2:
					logAppend("Process " + std::to_string(event.ID) + " got swapped out.");
					break;
				case 3:
					txQueue->SetLabel(std::string("Processes in queue: ") + ((event.ID & 1) ? "\nProcess 1" : "")
																			+ ((event.ID & 2) ? "\nProcess 2" : "")
																			+ ((event.ID & 4) ? "\nProcess 3" : "")
																			+ ((event.ID & 8) ? "\nProcess 4" : ""));
				}
			}
			wxGetApp().CallAfter([this] {
				onCompletion();
				});
			};
		std::thread thread{ fnc };
		thread.detach();

	}
	else {
		wxMessageBox("Please enter only valid positive integers",
			"Invalid Input", wxOK | wxICON_ERROR);
	}

}

void frameMain::onCompletion() {
	buttonStart->Enable(true);
	logAppend("Simulation finished.");
	gaugeTime->SetValue(1000);
}

void frameMain::onTimerTick(wxTimerEvent& event)
{
	milisecElapse += 115; // why.

	int gaugeVal = ((double)milisecElapse / (totalTime * 1000)) * 1000;

	if (gaugeVal > 1000 || gaugeTime->GetValue() >= 1000) {
		gaugeVal = 1000;
		gaugeTimer.Stop();
	}
					
	gaugeTime->SetValue(gaugeVal);
}

std::string frameMain::getCurrentTime() {
	auto now = std::chrono::system_clock::now();
	auto now_time_t = std::chrono::system_clock::to_time_t(now);
	std::tm* local_time = std::localtime(&now_time_t);

	return wxString::Format("%02d:%02d:%02d\n", local_time->tm_hour, local_time->tm_min, local_time->tm_sec).ToStdString();
}

void frameMain::logAppend(const char* str)
{
	txLog->AppendText("----------------------------------------\n" + getCurrentTime());
	txLog->AppendText(str);
	txLog->AppendText("\n");
}

void frameMain::logAppend(std::string str)
{
	txLog->AppendText("----------------------------------------\n" + getCurrentTime());
	txLog->AppendText(str + "\n");
}
