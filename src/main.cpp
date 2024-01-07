#include <cstdlib>
#include <wx/wx.h>

class HavenApp : public wxApp {
public:
  virtual bool OnInit();
};

class HavenFrame : public wxFrame {
public:
  HavenFrame(const wxString &title, const wxPoint &pos, const wxSize &size);

private:
  void OnHello(wxCommandEvent &event);
  void OnExit(wxCommandEvent &event);
  void OnAbout(wxCommandEvent &event);

  wxDECLARE_EVENT_TABLE();
};

enum { ID_Hello = 1 };

wxBEGIN_EVENT_TABLE(HavenFrame, wxFrame) EVT_MENU(ID_Hello, HavenFrame::OnHello)
    EVT_MENU(wxID_EXIT, HavenFrame::OnExit)
        EVT_MENU(wxID_ABOUT, HavenFrame::OnAbout) wxEND_EVENT_TABLE()

            wxIMPLEMENT_APP(HavenApp);

bool HavenApp::OnInit() {
  HavenFrame *frame =
      new HavenFrame("Haven Launcher", wxPoint(50, 50), wxSize(800, 600));
  frame->Show(true);
  return true;
}

HavenFrame::HavenFrame(const wxString &title, const wxPoint &pos,
                       const wxSize &size)
    : wxFrame(NULL, wxID_ANY, title, pos, size) {
  wxMenu *menuFile = new wxMenu;
  menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
                   "Help string shown in status bar for this menu item");
  menuFile->AppendSeparator();
  menuFile->Append(wxID_EXIT);

  wxMenu *menuHelp = new wxMenu;
  menuHelp->Append(wxID_ABOUT);

  wxMenuBar *menuBar = new wxMenuBar;
  menuBar->Append(menuFile, "&File");
  menuBar->Append(menuHelp, "&Help");

  SetMenuBar(menuBar);

  CreateStatusBar();
  SetStatusText("Welcome to Haven Launcher");
}

void HavenFrame::OnExit(wxCommandEvent &event) { Close(true); }

void HavenFrame::OnAbout(wxCommandEvent &event) {
  wxMessageBox("This is a wxWidgets' Hello World example", "About Hello World",
               wxOK | wxICON_INFORMATION);
}

void HavenFrame::OnHello(wxCommandEvent &event) {
  wxLogMessage("Hello world from wxWidgets!");
}
