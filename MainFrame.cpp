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

    wxBoxSizer* rightMainSizer = new wxBoxSizer(wxVERTICAL);





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



