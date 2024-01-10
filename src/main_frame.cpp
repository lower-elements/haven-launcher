// For compilers that support precompilation, includes "wx.h".
#include <wx/wxprec.h>

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <preferences.hpp>
#include "main_frame.hpp"

// clang-format off
wxBEGIN_EVENT_TABLE(HavenFrame, wxFrame)
    EVT_MENU(wxID_PREFERENCES, HavenFrame::OnPreferences)
    EVT_MENU(wxID_EXIT, HavenFrame::OnExit)
        EVT_MENU(wxID_ABOUT, HavenFrame::OnAbout)
wxEND_EVENT_TABLE()
    // clang-format on

    HavenFrame::HavenFrame(const wxString &title, const wxPoint &pos,
                           const wxSize &size)
    : wxFrame(NULL, wxID_ANY, title, pos, size) {
  wxMenu *menuFile = new wxMenu;
  menuFile->Append(wxID_PREFERENCES, "&preferences...\tCtrl-,",
                   "Help string shown in status bar for this menu item");
  menuFile->AppendSeparator();
  menuFile->Append(wxID_EXIT, "&Quit...\tCtrl-Shift-Q");

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

void HavenFrame::OnPreferences(wxCommandEvent &event) {
  HavenPreferences HavenPrefs("preferences");
}
