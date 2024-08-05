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
    wxBoxSizer* rightMainSizer = new wxBoxSizer(wxVERTICAL);                // the higest horizontal sizer is 1 the numbers will increase as the height of the sizer decreases
    wxBoxSizer* right1Sizer = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* right2Sizer = new wxBoxSizer(wxHORIZONTAL);


    yearText = new wxStaticText(rightPanel,wxID_ANY,"Year",wxDefaultPosition,wxDefaultSize,wxALIGN_CENTER_HORIZONTAL);
    yearText->SetFont(*panelFont);
    monthText = new wxStaticText(rightPanel,wxID_ANY,"Month",wxDefaultPosition,wxDefaultSize,wxALIGN_CENTER_HORIZONTAL);
    monthText->SetFont(*panelFont);
    dayText = new wxStaticText(rightPanel,wxID_ANY,"Day",wxDefaultPosition,wxDefaultSize,wxALIGN_CENTER_HORIZONTAL);
    dayText->SetFont(*panelFont);

    right1Sizer->Add(yearText, wxSizerFlags().Proportion(1));
    right1Sizer->Add(monthText, wxSizerFlags().Proportion(1));
    right1Sizer->Add(dayText, wxSizerFlags().Proportion(1));

    controlYearText = new wxTextCtrl(rightPanel, wxID_ANY,"Imput the year",wxDefaultPosition,wxSize(150,20));
    controlMonthText = new wxTextCtrl(rightPanel, wxID_ANY,"Imput the month",wxDefaultPosition,wxSize(150,20));
    controlDayText = new wxTextCtrl(rightPanel, wxID_ANY,"Imput the day",wxDefaultPosition,wxSize(150,20));

    right2Sizer->Add(controlYearText,wxSizerFlags().Proportion(1));
    right2Sizer->Add(controlMonthText,wxSizerFlags().Proportion(1));
    right2Sizer->Add(controlDayText,wxSizerFlags().Proportion(1));

    rightMainSizer->Add(right1Sizer,wxSizerFlags().Expand());
    rightMainSizer->Add(right2Sizer,wxSizerFlags().Expand());

    rightPanel->SetSizer(rightMainSizer);
    rightMainSizer->SetSizeHints(rightPanel);



}

