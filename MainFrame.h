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

    //FONTS
    wxFont* mainFont;
    wxFont* leftPanelFont;
    wxFont* rightPanelFont;



    //PANELS
    wxPanel* leftPanel;
    wxPanel* rightPanel;
    wxPanel* subLeftPanel1;
    wxPanel* subLeftPanel2 ;
    wxPanel* subRightPanel1;
    wxPanel* subRightPanel2;
    
    
    
    wxSplitterWindow* splitter;

    // LEFT PANEL TEXT
    wxTextCtrl* leftControlYearText;
    wxTextCtrl* leftControlMonthText;
    wxTextCtrl* leftControlDayText;
    wxTextCtrl* leftControlStartHourText;
    wxTextCtrl* leftControlStartMinuteText;
    wxTextCtrl* leftControlStartSecondText;
    wxTextCtrl* leftControlFinishHourText;
    wxTextCtrl* leftControlFinishMinuteText;
    wxTextCtrl* leftControlFinishSecondText;
    wxTextCtrl* leftControlActivityNameText;
    wxTextCtrl* leftControlActivityDescriptionText;

    wxStaticText* leftYearText;
    wxStaticText* leftMonthText;
    wxStaticText* leftDayText;
    wxStaticText* leftStartHourText;
    wxStaticText* leftStartMinuteText;
    wxStaticText* leftStartSecondText;
    wxStaticText* leftFinishHourText;
    wxStaticText* leftFinishMinuteText;
    wxStaticText* leftFinishSecondText;
    wxStaticText* leftActivityNameText;
    wxStaticText* leftActivityDescriptionText;



    // RIGHT PANEL TEXT
    wxTextCtrl* rightControlYearText;
    wxTextCtrl* rightControlMonthText;
    wxTextCtrl* rightControlDayText;

    wxStaticText* rightYearText;
    wxStaticText* rightMonthText;
    wxStaticText* rightDayText;

    wxStaticText* activityText;

    // LEFT PANEL BUTTONS
    wxButton* leftSaveButton;


    // RIGHT PANEL BUTTONS
    wxButton* rightSearchButton;

    // LEFT PANEL SIZERS
    wxBoxSizer* leftPanelSizer;
    wxBoxSizer* subLeftPanel1MainSizer;    // the higest horizontal sizer is 1 the numbers will increase as the height of the sizer decreases
    wxBoxSizer* subLeftPanel1HorizontalSizer1;
    wxBoxSizer* subLeftPanel1HorizontalSizer2;
    wxBoxSizer* subLeftPanel1HorizontalSizer3;
    wxBoxSizer* subLeftPanel1HorizontalSizer4;
    wxBoxSizer* subLeftPanel1HorizontalSizer5;
    wxBoxSizer* subLeftPanel1HorizontalSizer6;
    wxBoxSizer* subLeftPanel1HorizontalSizer7;
    wxBoxSizer* subLeftPanel1HorizontalSizer8;
    wxBoxSizer* subLeftPanel1HorizontalSizer9;
    wxBoxSizer* subLeftPanel1HorizontalSizer10;


    // RIGHT PANEL SIZERS
    wxBoxSizer* rightPanelSizer;
    wxBoxSizer* subRightPanel1MainSizer;    // the higest horizontal sizer is 1 the numbers will increase as the height of the sizer decreases
    wxBoxSizer* subRightPanel1HorizontalSizer1;
    wxBoxSizer* subRightPanel1HorizontalSizer2;




    wxBoxSizer* rightSubPanel2Sizer;
    int i=0;

    Register activities;

};


#endif //ELABORATO_LABORATORIO_DI_PROGRAMMAZIONE_MAINFRAME_H
