//
// Created by marco on 04/08/24.
//

#include "MainFrame.h"
#include <wx/font.h>


MainFrame::MainFrame(const wxString &title) : wxFrame(nullptr,wxID_ANY, title) {
    createControls();
}

void MainFrame::createControls() {

    mainFont = new wxFont(wxFontInfo(30).Bold().Italic());
    leftPanelFont = new wxFont(wxFontInfo(15).Italic());
    rightPanelFont = new wxFont(wxFontInfo(16).Italic());


    setSplitter();
    setLeftPanelSizer();
    setSubLeftPanel1Sizer();
    setRightPanelSizer();
    setSubRightPanel1Sizer();

    leftSaveButton->Bind(wxEVT_BUTTON,&MainFrame::onLeftSaveButtonCliked,this);
    rightSearchButton->Bind(wxEVT_BUTTON,&MainFrame::onRightSearchButtonCliked,this);
}

void MainFrame::setSplitter() {
    splitter = new wxSplitterWindow(this,wxID_ANY,wxDefaultPosition,wxDefaultSize,wxSP_BORDER | wxSP_LIVE_UPDATE);
    leftPanel = new wxPanel(splitter);
    rightPanel = new wxPanel(splitter);
    leftPanel->SetBackgroundColour(wxColour(255,255,255));
    rightPanel->SetBackgroundColour(wxColour(153,153,255));
    splitter->SplitVertically(leftPanel,rightPanel);
    splitter->SetMinimumPaneSize(450);
}

void MainFrame::setLeftPanelSizer() {
    subLeftPanel1 = new wxPanel(leftPanel,wxID_ANY,wxDefaultPosition,wxSize(200,100));
    subLeftPanel2 = new wxPanel(leftPanel,wxID_ANY,wxDefaultPosition,wxSize(200,100));
    subLeftPanel1->SetBackgroundColour(wxColour(255,153,51));
    subLeftPanel2->SetBackgroundColour(wxColour(255,255,255));

    leftPanelSizer = new wxBoxSizer(wxVERTICAL);
    leftPanelSizer->Add(subLeftPanel1,4,wxEXPAND | wxALL,5);
    leftPanelSizer->Add(subLeftPanel2,1,wxEXPAND | wxALL,5);

    leftPanel->SetSizer(leftPanelSizer);
    leftPanelSizer->SetSizeHints(leftPanel);
}

void MainFrame::setRightPanelSizer() {
    subRightPanel1 = new wxPanel(rightPanel,wxID_ANY,wxDefaultPosition,wxSize(200,100));
    subRightPanel2 = new wxPanel(rightPanel,wxID_ANY,wxDefaultPosition,wxSize(200,100));
    subRightPanel1->SetBackgroundColour(wxColour(0,250,0));
    subRightPanel2->SetBackgroundColour(wxColour(255,255,255));

    rightPanelSizer = new wxBoxSizer(wxVERTICAL);
    rightPanelSizer->Add(subRightPanel1,1,wxEXPAND | wxALL,5);
    rightPanelSizer->Add(subRightPanel2,9,wxEXPAND | wxALL,5);

    rightPanel->SetSizer(rightPanelSizer);
    rightPanelSizer->SetSizeHints(rightPanel);
}

void MainFrame::setSubLeftPanel1Sizer() {
    //SIZERS
    subLeftPanel1MainSizer = new wxBoxSizer(wxVERTICAL);
    subLeftPanel1HorizontalSizer1 = new wxBoxSizer(wxHORIZONTAL);
    subLeftPanel1HorizontalSizer2 = new wxBoxSizer(wxHORIZONTAL);
    subLeftPanel1HorizontalSizer3 = new wxBoxSizer(wxHORIZONTAL);
    subLeftPanel1HorizontalSizer4 = new wxBoxSizer(wxHORIZONTAL);
    subLeftPanel1HorizontalSizer5 = new wxBoxSizer(wxHORIZONTAL);
    subLeftPanel1HorizontalSizer6 = new wxBoxSizer(wxHORIZONTAL);
    subLeftPanel1HorizontalSizer7 = new wxBoxSizer(wxHORIZONTAL);
    subLeftPanel1HorizontalSizer8 = new wxBoxSizer(wxHORIZONTAL);
    subLeftPanel1HorizontalSizer9 = new wxBoxSizer(wxHORIZONTAL);
    subLeftPanel1HorizontalSizer10 = new wxBoxSizer(wxHORIZONTAL);


    // YEAR MOUNTH DAY INPUT
    leftYearText = new wxStaticText(subLeftPanel1,wxID_ANY,"Input start year : ",wxDefaultPosition,wxDefaultSize,wxALIGN_LEFT);
    leftYearText->SetFont(*leftPanelFont);
    leftMonthText = new wxStaticText(subLeftPanel1,wxID_ANY,"Input start month : ",wxDefaultPosition,wxDefaultSize,wxALIGN_LEFT);
    leftMonthText->SetFont(*leftPanelFont);
    leftDayText = new wxStaticText(subLeftPanel1,wxID_ANY,"Input start day : ",wxDefaultPosition,wxDefaultSize,wxALIGN_LEFT);
    leftDayText->SetFont(*leftPanelFont);

    leftControlYearText = new wxTextCtrl(subLeftPanel1,wxID_ANY,"Input start year",wxDefaultPosition,wxSize(150,27));
    leftControlMonthText = new wxTextCtrl(subLeftPanel1,wxID_ANY,"Input start month",wxDefaultPosition,wxSize(150,27));
    leftControlDayText = new wxTextCtrl(subLeftPanel1,wxID_ANY,"Input start day",wxDefaultPosition,wxSize(150,27));

    subLeftPanel1HorizontalSizer1->Add(leftYearText,1,wxALL,2);
    subLeftPanel1HorizontalSizer1->Add(leftControlYearText,1,wxALL,2);
    subLeftPanel1HorizontalSizer1->Add(leftMonthText,1,wxALL,2);
    subLeftPanel1HorizontalSizer1->Add(leftControlMonthText,1,wxALL,2);
    subLeftPanel1HorizontalSizer2->Add(leftDayText,1,wxALL,2);
    subLeftPanel1HorizontalSizer2->Add(leftControlDayText,1,wxALL,2);

    subLeftPanel1MainSizer->Add(subLeftPanel1HorizontalSizer1,1);
    subLeftPanel1MainSizer->Add(subLeftPanel1HorizontalSizer2,1);



    // START HOUR MINUTE SECOND INPUT
    leftStartHourText = new wxStaticText(subLeftPanel1,wxID_ANY,"Input start hour : ",wxDefaultPosition,wxDefaultSize,wxALIGN_LEFT);
    leftStartHourText->SetFont(*leftPanelFont);
    leftStartMinuteText = new wxStaticText(subLeftPanel1,wxID_ANY,"Input start mitute : ",wxDefaultPosition,wxDefaultSize,wxALIGN_LEFT);
    leftStartMinuteText->SetFont(*leftPanelFont);
    leftStartSecondText = new wxStaticText(subLeftPanel1,wxID_ANY,"Input start second : ",wxDefaultPosition,wxDefaultSize,wxALIGN_LEFT);
    leftStartSecondText->SetFont(*leftPanelFont);

    leftControlStartHourText = new wxTextCtrl(subLeftPanel1,wxID_ANY,"Input start hour",wxDefaultPosition,wxSize(150,27));
    leftControlStartMinuteText = new wxTextCtrl(subLeftPanel1,wxID_ANY,"Input start minute",wxDefaultPosition,wxSize(150,27));
    leftControlStartSecondText = new wxTextCtrl(subLeftPanel1,wxID_ANY,"Input start second",wxDefaultPosition,wxSize(150,27));

    subLeftPanel1HorizontalSizer3->Add(leftStartHourText,1,wxALL,2);
    subLeftPanel1HorizontalSizer3->Add(leftControlStartHourText,1,wxALL,2);
    subLeftPanel1HorizontalSizer3->Add(leftStartMinuteText,1,wxALL,2);
    subLeftPanel1HorizontalSizer3->Add(leftControlStartMinuteText,1,wxALL,2);
    subLeftPanel1HorizontalSizer4->Add(leftStartSecondText,1,wxALL,2);
    subLeftPanel1HorizontalSizer4->Add(leftControlStartSecondText,1,wxALL,2);

    subLeftPanel1MainSizer->Add(subLeftPanel1HorizontalSizer3,1);
    subLeftPanel1MainSizer->Add(subLeftPanel1HorizontalSizer4,1);



    // FINISH HOUR MINUTE SECOND INPUT
    leftFinishHourText = new wxStaticText(subLeftPanel1,wxID_ANY,"Input finish hour : ",wxDefaultPosition,wxDefaultSize,wxALIGN_LEFT);
    leftFinishHourText->SetFont(*leftPanelFont);
    leftFinishMinuteText = new wxStaticText(subLeftPanel1,wxID_ANY,"Input finish mitute : ",wxDefaultPosition,wxDefaultSize,wxALIGN_LEFT);
    leftFinishMinuteText->SetFont(*leftPanelFont);
    leftFinishSecondText = new wxStaticText(subLeftPanel1,wxID_ANY,"Input finish second : ",wxDefaultPosition,wxDefaultSize,wxALIGN_LEFT);
    leftFinishSecondText->SetFont(*leftPanelFont);

    leftControlFinishHourText = new wxTextCtrl(subLeftPanel1,wxID_ANY,"Input finish hour",wxDefaultPosition,wxSize(150,27));
    leftControlFinishMinuteText = new wxTextCtrl(subLeftPanel1,wxID_ANY,"Input finish minute",wxDefaultPosition,wxSize(150,27));
    leftControlFinishSecondText = new wxTextCtrl(subLeftPanel1,wxID_ANY,"Input finish second",wxDefaultPosition,wxSize(150,27));

    subLeftPanel1HorizontalSizer5->Add(leftFinishHourText,1,wxALL,2);
    subLeftPanel1HorizontalSizer5->Add(leftControlFinishHourText,1,wxALL,2);
    subLeftPanel1HorizontalSizer5->Add(leftFinishMinuteText,1,wxALL,2);
    subLeftPanel1HorizontalSizer5->Add(leftControlFinishMinuteText,1,wxALL,2);
    subLeftPanel1HorizontalSizer6->Add(leftFinishSecondText,1,wxALL,2);
    subLeftPanel1HorizontalSizer6->Add(leftControlFinishSecondText,1,wxALL,2);

    subLeftPanel1MainSizer->Add(subLeftPanel1HorizontalSizer5,1);
    subLeftPanel1MainSizer->Add(subLeftPanel1HorizontalSizer6,1);



    // ACTIVITY NAME AND DESCRIPTION INPUT
    leftActivityNameText = new wxStaticText(subLeftPanel1,wxID_ANY,"Input activity name : ",wxDefaultPosition,wxDefaultSize,wxALIGN_LEFT);
    leftActivityNameText->SetFont(*leftPanelFont);
    leftActivityDescriptionText = new wxStaticText(subLeftPanel1,wxID_ANY,"Write activity description",wxDefaultPosition,wxDefaultSize,wxALIGN_CENTER_VERTICAL);
    leftActivityDescriptionText->SetFont(*leftPanelFont);

    leftControlActivityNameText = new wxTextCtrl(subLeftPanel1,wxID_ANY,"Input activity name",wxDefaultPosition,wxSize(150,27));
    leftControlActivityDescriptionText = new wxTextCtrl(subLeftPanel1,wxID_ANY,"Write activity description",wxDefaultPosition,wxSize(150,100));

    subLeftPanel1HorizontalSizer7->Add(leftActivityNameText,1,wxALL,2);
    subLeftPanel1HorizontalSizer7->Add(leftControlActivityNameText,1, wxALL,2);
    subLeftPanel1HorizontalSizer8->Add(leftActivityDescriptionText,1,wxALL,2);
    subLeftPanel1HorizontalSizer9->Add(leftControlActivityDescriptionText,1,wxALL,2);

    subLeftPanel1MainSizer->Add(subLeftPanel1HorizontalSizer7,1);
    subLeftPanel1MainSizer->Add(subLeftPanel1HorizontalSizer8,1,wxALIGN_CENTER_HORIZONTAL);
    subLeftPanel1MainSizer->Add(subLeftPanel1HorizontalSizer9,2,wxEXPAND);



    // CREATE SAVE BUTTON
    leftSaveButton = new wxButton(subLeftPanel1,wxID_ANY,"Save");
    subLeftPanel1MainSizer->Add(leftSaveButton,1,wxEXPAND|wxALL,10);

    // SET THE SIZER
    subLeftPanel1->SetSizer(subLeftPanel1MainSizer);
    subLeftPanel1MainSizer->SetSizeHints(subLeftPanel1);
}





void MainFrame::setSubRightPanel1Sizer() {
    //SIZERS
    subRightPanel1MainSizer = new wxBoxSizer(wxVERTICAL);                // the higest horizontal sizer is 1 the numbers will increase as the height of the sizer decreases
    subRightPanel1HorizontalSizer1 = new wxBoxSizer(wxHORIZONTAL);
    subRightPanel1HorizontalSizer2 = new wxBoxSizer(wxHORIZONTAL);



    //SEARCHED YEAR MOUNTH DAY IMPUT
    rightYearText = new wxStaticText(subRightPanel1, wxID_ANY, "Year", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
    rightYearText->SetFont(*rightPanelFont);
    rightMonthText = new wxStaticText(subRightPanel1, wxID_ANY, "Month", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
    rightMonthText->SetFont(*rightPanelFont);
    rightDayText = new wxStaticText(subRightPanel1, wxID_ANY, "Day", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
    rightDayText->SetFont(*rightPanelFont);

    rightControlYearText = new wxTextCtrl(subRightPanel1, wxID_ANY,"Input the year",wxDefaultPosition,wxSize(150,25));
    rightControlMonthText = new wxTextCtrl(subRightPanel1, wxID_ANY,"Input the month",wxDefaultPosition,wxSize(150,25));
    rightControlDayText = new wxTextCtrl(subRightPanel1, wxID_ANY, "Input the day", wxDefaultPosition, wxSize(150, 25));

    subRightPanel1HorizontalSizer1->Add(rightYearText, wxSizerFlags().Proportion(1));
    subRightPanel1HorizontalSizer1->Add(rightMonthText, wxSizerFlags().Proportion(1));
    subRightPanel1HorizontalSizer1->Add(rightDayText, wxSizerFlags().Proportion(1));
    subRightPanel1HorizontalSizer2->Add(rightControlYearText, wxSizerFlags().Proportion(1));
    subRightPanel1HorizontalSizer2->Add(rightControlMonthText, wxSizerFlags().Proportion(1));
    subRightPanel1HorizontalSizer2->Add(rightControlDayText, wxSizerFlags().Proportion(1));

    subRightPanel1MainSizer->Add(subRightPanel1HorizontalSizer1, wxSizerFlags().Expand());
    subRightPanel1MainSizer->Add(subRightPanel1HorizontalSizer2, wxSizerFlags().Expand());



    //CREATE SEARCH BUTTON
    rightSearchButton = new wxButton(subRightPanel1,wxID_ANY,"Search");
    subRightPanel1MainSizer->Add(rightSearchButton, wxSizerFlags().Expand());

    subRightPanel1->SetSizer(subRightPanel1MainSizer);
    subRightPanel1MainSizer->SetSizeHints(subRightPanel1);
}

void MainFrame::onLeftSaveButtonCliked(wxCommandEvent &evt) {

    std::string name = fromWxStringToString(leftControlActivityNameText);
    std::string description = fromWxStringToString(leftControlActivityDescriptionText);

    int year = atoi(leftControlYearText->GetValue());
    int month = atoi(leftControlMonthText->GetValue());
    int day = atoi(leftControlDayText->GetValue());
    int startHour = atoi(leftControlStartHourText->GetValue());
    int startMinute = atoi(leftControlStartMinuteText->GetValue());
    int startSecond = atoi(leftControlStartSecondText->GetValue());
    int finishHour = atoi(leftControlFinishHourText->GetValue());
    int finishMinute = atoi(leftControlFinishMinuteText->GetValue());
    int finishSecond = atoi(leftControlFinishSecondText->GetValue());

    Date date(year,month,day);
    Time startTime(startHour,startMinute,startSecond);
    Time finishTime(finishHour,finishMinute,finishSecond);

    Activity activity(name,description,date,startTime,finishTime);

    activities.insert(activity);

    wxMessageBox("Activity saved",
                 "About Hello World", wxOK | wxICON_INFORMATION);
}


void MainFrame::onRightSearchButtonCliked(wxCommandEvent(& evt)) {
    int y=0;
    int m=0;
    int d=0;

    y = atoi(rightControlYearText->GetValue());
    m = atoi(rightControlMonthText->GetValue());
    d = atoi(rightControlDayText->GetValue());
    Date date(y,m,d);
    std::multimap<Date,Activity>::iterator it = activities.returnDay(date);
    int countedDayActivities = activities.showQuantity(date);

    wxMessageBox("Finded activities : "+std::to_string(countedDayActivities),
               "Information", wxOK | wxICON_INFORMATION);


    //   STRINGSTREAM

    stringstream.str("");
    subRightPanel2->DestroyChildren();
    auto panel = new wxScrolled<wxPanel>(subRightPanel2,wxID_ANY,wxDefaultPosition,wxSize(subRightPanel2->GetSize()));
    panel->SetScrollRate(0,10);


    //     SIZERS
    subRightPanel2Sizer = new wxBoxSizer(wxVERTICAL);
    auto scrollablePanelSizer = new wxBoxSizer(wxVERTICAL);

    subRightPanel2Sizer->Add(panel,1,wxEXPAND);

    // HEADER TEXT
    auto activityHeadrText = new wxStaticText(panel, wxID_ANY, "Activities : ");
    scrollablePanelSizer->Add(activityHeadrText,0,wxALL,5);


    // WRITE ACTIVITIES LIST
    for(auto start=it; start!= std::next(it,countedDayActivities); start++){
        stringstream.str("");
        stringstream <<" Name : " << start->second.getName() << "\n"
                     <<" Start time : " << start->second.getStartTime().getHour() <<  " / " << start->second.getStartTime().getMinute()
                     << " / " << start->second.getStartTime().getSecond() << "\n"
                     <<" Finish time : " << start->second.getFinishTime().getHour() <<  " / " << start->second.getFinishTime().getMinute()
                     << " / " << start->second.getFinishTime().getSecond() << "\n"
                     << " Description : " << start->second.getDescription() << "\n \n";

        wxString t;
        t = stringstream.str();
        activityText = new wxStaticText(panel, wxID_ANY, t);
        scrollablePanelSizer->Add(activityText, 0,wxALL,5);
    }


    // SET SIZERS
    panel->SetSizer(scrollablePanelSizer);
    subRightPanel2->SetSizer(subRightPanel2Sizer);
}

const std::string MainFrame::fromWxStringToString(wxTextCtrl* textCrtl) {

    wxString wstr = textCrtl->GetValue();

    // Calculating the length of the multibyte string
    size_t len = wcstombs(nullptr, wstr.c_str(), 0) + 1;

    // Creating a buffer to hold the multibyte string
    char* buffer = new char[len];

    // Converting wstring to string
    wcstombs(buffer, wstr.c_str(), len);

    // Creating std::string from char buffer
    std::string str(buffer);

    // Cleaning up the buffer
    delete[] buffer;

    // Returning the converted string
    return str;
}


