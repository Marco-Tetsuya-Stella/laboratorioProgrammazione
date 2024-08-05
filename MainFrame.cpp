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
    rightPanelFont = new wxFont(wxFontInfo(16).Italic());

    setSplitter();

    setLeftPanelSizer();
    setSubLeftPanel1Sizer();
    setRightPanelSizer();
    setSubRightPanel1Sizer();

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

    subLeftPanel1MainSizer = new wxBoxSizer(wxVERTICAL);
    subLeftPanel1HorizontalSizer1 = new wxBoxSizer(wxHORIZONTAL);
    subLeftPanel1HorizontalSizer2 = new wxBoxSizer(wxHORIZONTAL);
    subLeftPanel1HorizontalSizer3 = new wxBoxSizer(wxHORIZONTAL);
    subLeftPanel1HorizontalSizer4 = new wxBoxSizer(wxHORIZONTAL);

    // YEAR MOUNTH DAY INPUT
    leftYearText = new wxStaticText(subLeftPanel1,wxID_ANY,"Imput start year : ",wxDefaultPosition,wxDefaultSize,wxALIGN_LEFT);
    leftYearText->SetFont(*rightPanelFont);
    leftMonthText = new wxStaticText(subLeftPanel1,wxID_ANY,"Imput start month : ",wxDefaultPosition,wxDefaultSize,wxALIGN_LEFT);
    leftMonthText->SetFont(*rightPanelFont);
    leftDayText = new wxStaticText(subLeftPanel1,wxID_ANY,"Imput start day : ",wxDefaultPosition,wxDefaultSize,wxALIGN_LEFT);
    leftDayText->SetFont(*rightPanelFont);

    leftControlYearText = new wxTextCtrl(subLeftPanel1,wxID_ANY,"Imput start year",wxDefaultPosition,wxSize(150,25));
    leftControlMonthText = new wxTextCtrl(subLeftPanel1,wxID_ANY,"Imput start month",wxDefaultPosition,wxSize(150,25));
    leftControlDayText = new wxTextCtrl(subLeftPanel1,wxID_ANY,"Imput start day",wxDefaultPosition,wxSize(150,25));

    subLeftPanel1HorizontalSizer1->Add(leftYearText,1,wxALL,2);
    subLeftPanel1HorizontalSizer1->Add(leftControlYearText,1,wxALL,2);
    subLeftPanel1HorizontalSizer1->Add(leftMonthText,1,wxALL,2);
    subLeftPanel1HorizontalSizer1->Add(leftControlMonthText,1,wxALL,2);
    subLeftPanel1HorizontalSizer2->Add(leftDayText,1,wxALL,2);
    subLeftPanel1HorizontalSizer2->Add(leftControlDayText,1,wxALL,2);

    subLeftPanel1MainSizer->Add(subLeftPanel1HorizontalSizer1,1);
    subLeftPanel1MainSizer->Add(subLeftPanel1HorizontalSizer2,1);

    // START FINISH   HOUR MINUTE SECOND INPUT




    subLeftPanel1->SetSizer(subLeftPanel1MainSizer);
    subLeftPanel1MainSizer->SetSizeHints(subLeftPanel1);

}



void MainFrame::setSubRightPanel1Sizer() {
    subRightPanel1MainSizer = new wxBoxSizer(wxVERTICAL);                // the higest horizontal sizer is 1 the numbers will increase as the height of the sizer decreases
    subRightPanel1HorizontalSizer1 = new wxBoxSizer(wxHORIZONTAL);
    subRightPanel1HorizontalSizer2 = new wxBoxSizer(wxHORIZONTAL);

    rightYearText = new wxStaticText(subRightPanel1, wxID_ANY, "Year", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
    rightYearText->SetFont(*rightPanelFont);
    rightMonthText = new wxStaticText(subRightPanel1, wxID_ANY, "Month", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
    rightMonthText->SetFont(*rightPanelFont);
    rightDayText = new wxStaticText(subRightPanel1, wxID_ANY, "Day", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);
    rightDayText->SetFont(*rightPanelFont);

    subRightPanel1HorizontalSizer1->Add(rightYearText, wxSizerFlags().Proportion(1));
    subRightPanel1HorizontalSizer1->Add(rightMonthText, wxSizerFlags().Proportion(1));
    subRightPanel1HorizontalSizer1->Add(rightDayText, wxSizerFlags().Proportion(1));

    rightControlYearText = new wxTextCtrl(subRightPanel1, wxID_ANY,"Imput the year",wxDefaultPosition,wxSize(150,25));
    rightControlMonthText = new wxTextCtrl(subRightPanel1, wxID_ANY,"Imput the month",wxDefaultPosition,wxSize(150,25));
    rightControlDayText = new wxTextCtrl(subRightPanel1, wxID_ANY, "Imput the day", wxDefaultPosition, wxSize(150, 25));


    subRightPanel1HorizontalSizer2->Add(rightControlYearText, wxSizerFlags().Proportion(1));
    subRightPanel1HorizontalSizer2->Add(rightControlMonthText, wxSizerFlags().Proportion(1));
    subRightPanel1HorizontalSizer2->Add(rightControlDayText, wxSizerFlags().Proportion(1));

    rightSearchButton = new wxButton(subRightPanel1,wxID_ANY,"Search");

    subRightPanel1MainSizer->Add(subRightPanel1HorizontalSizer1, wxSizerFlags().Expand());
    subRightPanel1MainSizer->Add(subRightPanel1HorizontalSizer2, wxSizerFlags().Expand());
    subRightPanel1MainSizer->Add(rightSearchButton, wxSizerFlags().Expand());

    subRightPanel1->SetSizer(subRightPanel1MainSizer);
    subRightPanel1MainSizer->SetSizeHints(subRightPanel1);

}

void MainFrame::onRightSearchButtonCliked(wxCommandEvent(& evt)) {
   /* int y=0;
    int m=0;
    int d=0;

    y = atoi(rightControlYearText->GetValue());
    m = atoi(controlMonthText->GetValue());
    d = atoi(rightControlDayText->GetValue());
    Date date(y,m,d);
    std::multimap<Date,Activity>::iterator it = activities.returnDay(date);
    int countedDayActivities = activities.showQuantity(date);

    /*wxMessageBox(" "+std::to_string(y)+" "+std::to_string(m),
                 "About Hello World", wxOK | wxICON_INFORMATION);*/


    std::stringstream stringstream;
    stringstream.clear();
    stringstream <<"Activities : \n \n";

   /* for(auto start=it; start!= std::next(it,countedDayActivities); start++){
        stringstream <<" Name " << start->second.getName() << "\n"
                    <<" Start time " << start->second.getStartTime().getHour() <<  " : " << start->second.getStartTime().getMinute()
                    << " : " << start->second.getStartTime().getSecond() << "\n"
                    << " Description " << start->second.getDescription() << "\n \n";
    }*/

    //Updte system. The activities are updated with each click
    subRightPanel2->DestroyChildren();
    auto panel = new wxScrolled<wxPanel>(subRightPanel2,wxID_ANY,wxDefaultPosition,wxSize(subRightPanel2->GetSize()));
    panel->SetScrollRate(0,10);

    auto scrollablePanelSizer = new wxBoxSizer(wxVERTICAL);

    scrollablePanelSizer->Add(panel,1,wxEXPAND);

    rightSubPanel2Sizer = new wxBoxSizer(wxVERTICAL);
    //rightSubPanel2Sizer->Clear();
    stringstream <<" Name " << "*******" << std::to_string(i) + " \n"
                 <<" Start time " << "--------" <<  " : " << "----------------"
                 << " : " << "---------------" << "\n"
                 << " Description " << "**********" << "\n \n";

    for(int i=0; i<15; i++) {
        wxString t;
        t = stringstream.str();
        activityText = new wxStaticText(panel, wxID_ANY, t);
        rightSubPanel2Sizer->Add(activityText, 0,wxALL,5);
    }

    panel->SetSizer(rightSubPanel2Sizer);

    subRightPanel2->SetSizer(scrollablePanelSizer);
    i++;

}




