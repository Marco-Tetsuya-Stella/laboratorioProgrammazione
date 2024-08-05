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
    panelFont = new wxFont(wxFontInfo(16).Italic());

    setSplitter();
    setSubRightPanelSizer();
    setRightSizer();

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

void MainFrame::setSubRightPanelSizer() {
    subRightPanel1 = new wxPanel(rightPanel,wxID_ANY,wxDefaultPosition,wxSize(200,100));
    subRightPanel2 = new wxPanel(rightPanel,wxID_ANY,wxDefaultPosition,wxSize(200,100));
    subRightPanel1->SetBackgroundColour(wxColour(0,250,0));
    subRightPanel2->SetBackgroundColour(wxColour(255,255,255));

    rightPanelSizer = new wxBoxSizer(wxVERTICAL);
    rightPanelSizer->Add(subRightPanel1,1,wxEXPAND | wxALL ,5);
    rightPanelSizer->Add(subRightPanel2,9,wxEXPAND | wxALL,5);

    rightPanel->SetSizer(rightPanelSizer);
    rightPanelSizer->SetSizeHints(rightPanel);
}




void MainFrame::setRightSizer() {
    rightMainSizer = new wxBoxSizer(wxVERTICAL);                // the higest horizontal sizer is 1 the numbers will increase as the height of the sizer decreases
    rightHoriziontalSizer1 = new wxBoxSizer(wxHORIZONTAL);
    rightHorizontalSizer2 = new wxBoxSizer(wxHORIZONTAL);

    yearText = new wxStaticText(subRightPanel1,wxID_ANY,"Year",wxDefaultPosition,wxDefaultSize,wxALIGN_CENTER_HORIZONTAL);
    yearText->SetFont(*panelFont);
    monthText = new wxStaticText(subRightPanel1,wxID_ANY,"Month",wxDefaultPosition,wxDefaultSize,wxALIGN_CENTER_HORIZONTAL);
    monthText->SetFont(*panelFont);
    dayText = new wxStaticText(subRightPanel1,wxID_ANY,"Day",wxDefaultPosition,wxDefaultSize,wxALIGN_CENTER_HORIZONTAL);
    dayText->SetFont(*panelFont);

    rightHoriziontalSizer1->Add(yearText, wxSizerFlags().Proportion(1));
    rightHoriziontalSizer1->Add(monthText, wxSizerFlags().Proportion(1));
    rightHoriziontalSizer1->Add(dayText, wxSizerFlags().Proportion(1));

    controlYearText = new wxTextCtrl(subRightPanel1, wxID_ANY,"Imput the year",wxDefaultPosition,wxSize(150,25));
    controlMonthText = new wxTextCtrl(subRightPanel1, wxID_ANY,"Imput the month",wxDefaultPosition,wxSize(150,25));
    controlDayText = new wxTextCtrl(subRightPanel1, wxID_ANY,"Imput the day",wxDefaultPosition,wxSize(150,25));

    rightHorizontalSizer2->Add(controlYearText,wxSizerFlags().Proportion(1));
    rightHorizontalSizer2->Add(controlMonthText,wxSizerFlags().Proportion(1));
    rightHorizontalSizer2->Add(controlDayText,wxSizerFlags().Proportion(1));

    rightSearchButton = new wxButton(subRightPanel1,wxID_ANY,"Search");

    rightMainSizer->Add(rightHoriziontalSizer1,wxSizerFlags().Expand());
    rightMainSizer->Add(rightHorizontalSizer2,wxSizerFlags().Expand());
    rightMainSizer->Add(rightSearchButton,wxSizerFlags().Expand());

    subRightPanel1->SetSizer(rightMainSizer);
    rightMainSizer->SetSizeHints(subRightPanel1);

}

void MainFrame::onRightSearchButtonCliked(wxCommandEvent(& evt)) {
   /* int y=0;
    int m=0;
    int d=0;

    y = atoi(controlYearText->GetValue());
    m = atoi(controlMonthText->GetValue());
    d = atoi(controlDayText->GetValue());
    Date date(y,m,d);
    std::multimap<Date,Activity>::iterator it = activities.returnDay(date);
    int countedDayActivities = activities.showQuantity(date);

    /*wxMessageBox(" "+std::to_string(y)+" "+std::to_string(m),
                 "About Hello World", wxOK | wxICON_INFORMATION);*/

    //std::stringstream stringstream;

    /*for(auto start=it; start!= std::next(it,countedDayActivities); start++){
        stringstream <<" Name " << start->second.getName() << "\n" << " Description " << start->second.getDescription() << "\n"
                    <<" Start time " << start->second.getStartTime().getHour() <<  " : " << start->second.getStartTime().getMinute()
                    << " : " << start->second.getStartTime().getSecond() << "\n";
    }*/

    std::stringstream stringstream;
    stringstream << " ciao ";

    wxString t;
    t = stringstream.str();
    activityText = new wxStaticText(subRightPanel2,wxID_ANY,t);



}




