//
// Created by marco on 04/08/24.
//

#include "App.h"

wxIMPLEMENT_APP(App);

bool App::OnInit() {

    MainFrame* mainFrame = new MainFrame("Register");
    mainFrame->SetClientSize(1300,800);
    mainFrame->Center();
    mainFrame->Show();
    return true;

}






