//
// Created by marco on 04/08/24.
//

#include "MainFrame.h"
#include <wx/font.h>

MainFrame::MainFrame(const wxString &title) : wxFrame(nullptr,wxID_ANY, title) {
    createControls();

}

void MainFrame::createControls() {

    wxFont mainFont(wxFontInfo(30).Bold().Italic());
    panel= new wxPanel(this);
    panel->SetFont(mainFont);
    date= new wxStaticText(panel,wxID_ANY,"Date", wxPoint(700,22),wxSize(200,50), wxALIGN_LEFT);
    date->SetFont(mainFont);
    date->SetBackgroundColour(*wxGREEN);

}




