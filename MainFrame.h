//
// Created by marco on 04/08/24.
//

#ifndef ELABORATO_LABORATORIO_DI_PROGRAMMAZIONE_MAINFRAME_H
#define ELABORATO_LABORATORIO_DI_PROGRAMMAZIONE_MAINFRAME_H
#include <wx/wx.h>
#include <string>
#include <wx/splitter.h>
#include "Register.h"
#include <sstream>
#include <wx/window.h>

class MainFrame : public wxFrame{

public:
    MainFrame(const wxString& title);

private:
    void createControls();
    void setSplitter();
    void setSubRightPanel1Sizer();
    void setRightPanelSizer();

    void onRightSearchButtonCliked(wxCommandEvent& evt);


    wxFont* mainFont;
    wxFont* panelFont;


    wxPanel* leftPanel;
    wxPanel* rightPanel;
    wxPanel* subRightPanel1;
    wxPanel* subRightPanel2;

    wxSplitterWindow* splitter;

    wxTextCtrl* controlYearText;
    wxTextCtrl* controlMonthText;
    wxTextCtrl* controlDayText;

    wxStaticText* yearText;
    wxStaticText* monthText;
    wxStaticText* dayText;

    wxStaticText* activityText;

   // wxStaticText* name;
    wxButton* rightSearchButton;

    wxArrayString choices;

    wxBoxSizer* rightPanelSizer;
    wxBoxSizer* subRightPanel1MainSizer;    // the higest horizontal sizer is 1 the numbers will increase as the height of the sizer decreases
    wxBoxSizer* subRightPanel1HorizontalSizer1;
    wxBoxSizer* subRightPanel2HorizontalSizer2;

    wxBoxSizer* rightSubPanel2Sizer;
    int i=0;

    Register activities;

};


#endif //ELABORATO_LABORATORIO_DI_PROGRAMMAZIONE_MAINFRAME_H
