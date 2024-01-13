#include <wx/preferences.h>
#include <wx/wx.h>
#include <wx/spinctrl.h>
#include <preferences.hpp>

HavenPreferences::HavenPreferences(const wxString &title)
    : wxPreferencesEditor(title) {
  AddPage(new HavenPreferencesGeneral());
  AddPage(new HavenPreferencesRepository());
  AddPage(new HavenPreferencesDownload());
};

HavenPreferences::~HavenPreferences(){};



HavenPreferencesGeneral::HavenPreferencesGeneral() : wxPreferencesPage() {};
HavenPreferencesGeneral::~HavenPreferencesGeneral() {};
wxString HavenPreferencesGeneral::GetName() const {
    return "general";
};
wxWindow* HavenPreferencesGeneral::CreateWindow(wxWindow *parent) {
    wxPanel* Panel = new wxPanel(parent);
    wxFlexGridSizer* Sizer = new wxFlexGridSizer(2, 5, 5);

    //The language picker
    Sizer->Add(new wxStaticText(Panel, wxID_ANY, "Language"));
    wxChoice* LanguageChoice = new wxChoice(Panel, wxID_ANY);
    LanguageChoice->SetExtraStyle(wxCB_SORT);
    LanguageChoice->SetName("Language");
    LanguageChoice->Append("English");
    LanguageChoice->SetSelection(0);

    Sizer->Add(LanguageChoice);

    Sizer->Add(new wxStaticText(Panel, wxID_ANY, ""));
    wxCheckBox* LauncherUpdates = new wxCheckBox(Panel, wxID_ANY, "Check for updates to the launcher on opening the app");
    LauncherUpdates->SetValue(1);
    Sizer->Add(LauncherUpdates);
    Sizer->Add(new wxStaticText(Panel, wxID_ANY, ""));
    wxCheckBox* GameUpdates = new wxCheckBox(Panel, wxID_ANY, "Check for updates to Installed Games on the opening of the app");
    GameUpdates->SetValue(1);
    Sizer->Add(GameUpdates);

    Sizer->Add(new wxStaticText(Panel, wxID_ANY, "Installation Directory"));
    wxTextCtrl* InstallDir = new wxTextCtrl(Panel, wxID_ANY, "./library/games/");
    Sizer->Add(InstallDir);


    Panel->SetSizer(Sizer);
    Panel->Layout();

    return Panel;
}

HavenPreferencesRepository::HavenPreferencesRepository()
    : wxPreferencesPage(){};
HavenPreferencesRepository::~HavenPreferencesRepository(){};
wxString HavenPreferencesRepository::GetName() const {
  return "repository settings";
};
wxWindow *HavenPreferencesRepository::CreateWindow(wxWindow *parent) {
  wxPanel* Panel = new wxPanel(parent);
  wxFlexGridSizer* Sizer = new wxFlexGridSizer(4, 5, 5);
  Sizer->Add(new wxStaticText(Panel, wxID_ANY, "Repositories"));
  wxChoice* RepoList = new wxChoice(Panel, wxID_ANY);

  Sizer->Add(RepoList);
  Sizer->Add(new wxButton(Panel, wxID_ANY, "Add"));
  Sizer->Add(new wxButton(Panel, wxID_ANY, "Edit"));
  Sizer->Add(new wxButton(Panel, wxID_ANY, "remove"));

  wxCheckBox* TrustedRepos = new wxCheckBox(Panel, wxID_ANY, "Always load trusted repos");
  TrustedRepos->SetValue(1);
  Sizer->Add(TrustedRepos, wxEXPAND);
  Panel->SetSizer(Sizer);
  Panel->Layout();
  return Panel;
};

HavenPreferencesDownload::HavenPreferencesDownload() : wxPreferencesPage(){};
HavenPreferencesDownload::~HavenPreferencesDownload(){};
wxString HavenPreferencesDownload::GetName() const {
  return "download settings";
};
wxWindow *HavenPreferencesDownload::CreateWindow(wxWindow *parent) {
  wxPanel* Panel = new wxPanel(parent);
  wxFlexGridSizer* Sizer = new wxFlexGridSizer(2, 5, 5);
  Sizer->Add(new wxStaticText(Panel, wxID_ANY, "Download Directory"));
  wxTextCtrl* DownloadDir = new wxTextCtrl(Panel, wxID_ANY, "./library/downloads/");
  Sizer->Add(DownloadDir);

  Sizer->Add(new wxStaticText(Panel, wxID_ANY, "Download throttle (mb/s)"));
  wxSpinCtrl* DownloadthrottleMB = new wxSpinCtrl(Panel, wxID_ANY, "000");
  DownloadthrottleMB->SetRange(0,100);
  Sizer->Add(DownloadthrottleMB);
  Sizer->Add(new wxStaticText(Panel, wxID_ANY, "Download throttle (kb/s)"));
  wxSpinCtrl* DownloadthrottleKB = new wxSpinCtrl(Panel, wxID_ANY, "0000");
  DownloadthrottleKB->SetRange(0,1023);
  DownloadthrottleKB->SetBase(2);
  Sizer->Add(DownloadthrottleKB);



  Panel->SetSizer(Sizer);
  Panel->Layout();
  return Panel;
};
