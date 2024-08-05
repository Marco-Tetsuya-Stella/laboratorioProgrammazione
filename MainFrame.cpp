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
    setRightSizer();

    rightSearchButton->Bind(wxEVT_BUTTON,&MainFrame::onRightSearchButtonCliked,this);

}

void MainFrame::setSplitter() {
    splitter = new wxSplitterWindow(this,wxID_ANY,wxDefaultPosition,wxDefaultSize,wxSP_BORDER | wxSP_LIVE_UPDATE);
    leftPanel = new wxPanel(splitter);
    rightPanel = new wxPanel(splitter);
    leftPanel->SetBackgroundColour(wxColour(50,70,130));
    rightPanel->SetBackgroundColour(wxColour(150,200,15));
    //leftPanel->SetFont(*panelFont);
   // rightPanel->SetFont(*panelFont);
    splitter->SplitVertically(leftPanel,rightPanel);
    splitter->SetMinimumPaneSize(300);
}

void MainFrame::setRightSizer() {
    rightMainSizer = new wxBoxSizer(wxVERTICAL);                // the higest horizontal sizer is 1 the numbers will increase as the height of the sizer decreases
    rightHoriziontalSizer1 = new wxBoxSizer(wxHORIZONTAL);
    rightHorizontalSizer2 = new wxBoxSizer(wxHORIZONTAL);

    yearText = new wxStaticText(rightPanel,wxID_ANY,"Year",wxDefaultPosition,wxDefaultSize,wxALIGN_CENTER_HORIZONTAL);
    yearText->SetFont(*panelFont);
    monthText = new wxStaticText(rightPanel,wxID_ANY,"Month",wxDefaultPosition,wxDefaultSize,wxALIGN_CENTER_HORIZONTAL);
    monthText->SetFont(*panelFont);
    dayText = new wxStaticText(rightPanel,wxID_ANY,"Day",wxDefaultPosition,wxDefaultSize,wxALIGN_CENTER_HORIZONTAL);
    dayText->SetFont(*panelFont);

    rightHoriziontalSizer1->Add(yearText, wxSizerFlags().Proportion(1));
    rightHoriziontalSizer1->Add(monthText, wxSizerFlags().Proportion(1));
    rightHoriziontalSizer1->Add(dayText, wxSizerFlags().Proportion(1));

    controlYearText = new wxTextCtrl(rightPanel, wxID_ANY,"Imput the year",wxDefaultPosition,wxSize(150,25));
    controlMonthText = new wxTextCtrl(rightPanel, wxID_ANY,"Imput the month",wxDefaultPosition,wxSize(150,25));
    controlDayText = new wxTextCtrl(rightPanel, wxID_ANY,"Imput the day",wxDefaultPosition,wxSize(150,25));

    rightHorizontalSizer2->Add(controlYearText,wxSizerFlags().Proportion(1));
    rightHorizontalSizer2->Add(controlMonthText,wxSizerFlags().Proportion(1));
    rightHorizontalSizer2->Add(controlDayText,wxSizerFlags().Proportion(1));

    rightSearchButton = new wxButton(rightPanel,wxID_ANY,"Search");

    rightMainSizer->Add(rightHoriziontalSizer1,wxSizerFlags().Expand());
    rightMainSizer->Add(rightHorizontalSizer2,wxSizerFlags().Expand());
    rightMainSizer->Add(rightSearchButton,wxSizerFlags().Expand());

    rightPanel->SetSizer(rightMainSizer);
    rightMainSizer->SetSizeHints(rightPanel);
}

void MainFrame::onRightSearchButtonCliked(wxCommandEvent(& evt)) {
    int y=0;
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

   std::stringstream stringstream;

   for(auto start=it; start!= std::next(it,countedDayActivities); start++){
       stringstream <<" Name " << start->second.getName() << "\n" << " Description " << start->second.getDescription() << "\n"
                    <<" Start time ";
   }





}




