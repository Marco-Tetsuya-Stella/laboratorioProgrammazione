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
    void setLeftPanelSizer();
    void setSubLeftPanel1Sizer();

    void setRightPanelSizer();
    void setSubRightPanel1Sizer();
    void onRightSearchButtonCliked(wxCommandEvent& evt);


    wxFont* mainFont;
    wxFont* rightPanelFont;


    wxPanel* leftPanel;
    wxPanel* rightPanel;
    wxPanel* subLeftPanel1;
    wxPanel* subLeftPanel2 ;
    wxPanel* subRightPanel1;
    wxPanel* subRightPanel2;
    
    
    
    wxSplitterWindow* splitter;

    // right panel text
    wxTextCtrl* rightControlYearText;
    wxTextCtrl* rightControlMonthText;
    wxTextCtrl* rightControlDayText;

    wxStaticText* rightYearText;
    wxStaticText* rightMonthText;
    wxStaticText* rightDayText;

    wxStaticText* activityText;

    // left panel text
    wxTextCtrl* leftControlYearText;
    wxTextCtrl* leftControlMonthText;
    wxTextCtrl* leftControlDayText;

    wxStaticText* leftYearText;
    wxStaticText* leftMonthText;
    wxStaticText* leftDayText;


   // wxStaticText* name;
    wxButton* rightSearchButton;

    
    // right panel sizers
    wxBoxSizer* rightPanelSizer;
    wxBoxSizer* subRightPanel1MainSizer;    // the higest horizontal sizer is 1 the numbers will increase as the height of the sizer decreases
    wxBoxSizer* subRightPanel1HorizontalSizer1;
    wxBoxSizer* subRightPanel1HorizontalSizer2;

    // left panel sizers
    wxBoxSizer* leftPanelSizer;
    wxBoxSizer* subLeftPanel1MainSizer;    // the higest horizontal sizer is 1 the numbers will increase as the height of the sizer decreases
    wxBoxSizer* subLeftPanel1HorizontalSizer1;
    wxBoxSizer* subLeftPanel1HorizontalSizer2;
    wxBoxSizer* subLeftPanel1HorizontalSizer3;
    wxBoxSizer* subLeftPanel1HorizontalSizer4;





    wxBoxSizer* rightSubPanel2Sizer;
    int i=0;

    Register activities;

};


#endif //ELABORATO_LABORATORIO_DI_PROGRAMMAZIONE_MAINFRAME_H
