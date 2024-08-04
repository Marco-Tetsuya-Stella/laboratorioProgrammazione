//
// Created by marco on 04/08/24.
//

#ifndef ELABORATO_LABORATORIO_DI_PROGRAMMAZIONE_MAINFRAME_H
#define ELABORATO_LABORATORIO_DI_PROGRAMMAZIONE_MAINFRAME_H
#include <wx/wx.h>
#include <string>
#include <wx/splitter.h>

class MainFrame : public wxFrame{

public:
    MainFrame(const wxString& title);

private:
    void createControls();
    void setSplitter();

    wxFont* mainFont;
    wxFont* panelFont;


    wxPanel* leftPanel;
    wxPanel* rightPanel;
    wxSplitterWindow* splitter;


};


#endif //ELABORATO_LABORATORIO_DI_PROGRAMMAZIONE_MAINFRAME_H
