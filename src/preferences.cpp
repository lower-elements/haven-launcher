// For compilers that support precompilation, includes "wx.h".
#include <wx/wxprec.h>
#include <limits>

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <wx/preferences.h>
#include <wx/config.h>
#include <wx/spinctrl.h>

#include <preferences.hpp>

HavenPreferences::HavenPreferences(const wxString &title, wxConfig& Config)
    : wxPreferencesEditor(title), M_Config(Config) {
  AddPage(new HavenPreferencesGeneral(M_Config));
  AddPage(new HavenPreferencesRepository(M_Config));
  AddPage(new HavenPreferencesDownload(M_Config));
};

HavenPreferences::~HavenPreferences(){};

HavenPreferencesGeneral::HavenPreferencesGeneral(wxConfig& Config) : wxPreferencesPage(), M_Config(Config) {};
HavenPreferencesGeneral::~HavenPreferencesGeneral(){};
wxString HavenPreferencesGeneral::GetName() const { return "general"; };
wxWindow *HavenPreferencesGeneral::CreateWindow(wxWindow *parent) {
  return new GeneralPanel(parent, M_Config);
}

HavenPreferencesRepository::HavenPreferencesRepository(wxConfig& Config)
    : wxPreferencesPage(), M_Config(Config) {};
HavenPreferencesRepository::~HavenPreferencesRepository(){};
wxString HavenPreferencesRepository::GetName() const {
  return "repository settings";
};
wxWindow *HavenPreferencesRepository::CreateWindow(wxWindow *parent) {
  return new RepositoryPanel(parent, M_Config);
};

HavenPreferencesDownload::HavenPreferencesDownload(wxConfig& Config) : wxPreferencesPage(), M_Config(Config) {};
HavenPreferencesDownload::~HavenPreferencesDownload(){};
wxString HavenPreferencesDownload::GetName() const {
  return "download settings";
};
wxWindow *HavenPreferencesDownload::CreateWindow(wxWindow *parent) {
  return new DownloadPanel(parent, M_Config);
};


GeneralPanel::GeneralPanel(wxWindow* Parent, wxConfig& Config) : wxPanel(Parent), M_Config(Config) {
  wxFlexGridSizer *Sizer = new wxFlexGridSizer(2, 5, 5);

  // The language picker
  Sizer->Add(new wxStaticText(this, wxID_ANY, "Language"));
  wxChoice *LanguageChoice = new wxChoice(this, ID_LANG);
  LanguageChoice->SetExtraStyle(wxCB_SORT);
  LanguageChoice->SetName("Language");
  LanguageChoice->Append("English");
  LanguageChoice->Append("Polish");
  LanguageChoice->Append("Japanese");
  wxString data = M_Config.Read("preferences/general/language", "English");
  int ChoiceIndex = LanguageChoice->FindString(data);
  LanguageChoice->SetSelection(ChoiceIndex);

  Sizer->Add(LanguageChoice);

  Sizer->Add(new wxStaticText(this, wxID_ANY, ""));
  wxCheckBox *LauncherUpdates = new wxCheckBox(
      this, ID_LAUNCHER_UPDATES, "Check for updates to the launcher on opening the app");
  LauncherUpdates->SetValue(M_Config.Read("preferences/general/launcher_updates", 1));
  Sizer->Add(LauncherUpdates);
  Sizer->Add(new wxStaticText(this, wxID_ANY, ""));
  wxCheckBox *GameUpdates = new wxCheckBox(
      this, ID_GAME_UPDATES,
      "Check for updates to Installed Games on the opening of the app");
  GameUpdates->SetValue(M_Config.Read("preferences/general/game_updates", 1));
  Sizer->Add(GameUpdates);

  Sizer->Add(new wxStaticText(this, wxID_ANY, "Installation Directory"));
  wxTextCtrl *InstallDir = new wxTextCtrl(this, ID_GAMES_DIR_EDIT, M_Config.Read("preferences/general/games_dir", "./library/games/"));
  Sizer->Add(InstallDir);

  SetSizer(Sizer);
  Layout();

}

void GeneralPanel::OnLang(wxCommandEvent &event)
{
  M_Config.Write("preferences/general/language", event.GetString());
}

void GeneralPanel::OnGameUpdates(wxCommandEvent &event)
{
  M_Config.Write("preferences/general/game_updates", event.GetInt());
}

void GeneralPanel::OnLauncherUpdates(wxCommandEvent &event)
{
  M_Config.Write("preferences/general/launcher_updates", event.GetInt());
}

void GeneralPanel::OnGameDir(wxCommandEvent &event)
{
  M_Config.Write("preferences/general/games_dir", event.GetString());
}

RepositoryPanel::RepositoryPanel(wxWindow* parent, wxConfig& Config) 
  : wxPanel(parent), M_Config(Config) 
{
  wxFlexGridSizer *Sizer = new wxFlexGridSizer(4, 5, 5);
  Sizer->Add(new wxStaticText(this, wxID_ANY, "Repositories"));
  wxChoice *RepoList = new wxChoice(this, wxID_ANY);

  Sizer->Add(RepoList);
  Sizer->Add(new wxButton(this, wxID_ANY, "Add"));
  Sizer->Add(new wxButton(this, wxID_ANY, "Edit"));
  Sizer->Add(new wxButton(this, wxID_ANY, "remove"));

  wxCheckBox *TrustedRepos = new wxCheckBox(this, wxID_ANY, "Always load trusted repos");
  TrustedRepos->SetValue(1);
  Sizer->Add(TrustedRepos, wxEXPAND);
  SetSizer(Sizer);
  Layout();
}

DownloadPanel::DownloadPanel(wxWindow* parent, wxConfig& Config) 
  : wxPanel(parent), M_Config(Config)
{
  wxFlexGridSizer *Sizer = new wxFlexGridSizer(2, 5, 5);
  Sizer->Add(new wxStaticText(this, wxID_ANY, "Download Directory"));
  wxTextCtrl *DownloadDir =
      new wxTextCtrl(this, wxID_ANY, "./library/downloads/");
  Sizer->Add(DownloadDir);
  Sizer->Add(new wxStaticText(this, wxID_ANY, "select a directory"));
  Sizer->Add(new wxButton(this, wxID_ANY, "Browse"));

  Sizer->Add(new wxStaticText(this, wxID_ANY, "Download throttle (mb/s)"));
  wxSpinCtrl *DownloadthrottleMB = new wxSpinCtrl(this, wxID_ANY, "0");
  DownloadthrottleMB->SetRange(0, std::numeric_limits<int>::max());
  Sizer->Add(DownloadthrottleMB);
  Sizer->Add(new wxStaticText(this, wxID_ANY, "Download throttle (kb/s)"));
  wxSpinCtrl *DownloadthrottleKB = new wxSpinCtrl(this, wxID_ANY, "0");
  DownloadthrottleKB->SetRange(0, 1023);
  DownloadthrottleKB->SetBase(2);
  Sizer->Add(DownloadthrottleKB);

  SetSizer(Sizer);
  Layout();
}


//clang-format off
wxBEGIN_EVENT_TABLE(GeneralPanel, wxPanel)
  EVT_CHOICE(ID_LANG, GeneralPanel::OnLang)
  EVT_CHECKBOX(ID_LAUNCHER_UPDATES, GeneralPanel::OnLauncherUpdates)
  EVT_CHECKBOX(ID_GAME_UPDATES, GeneralPanel::OnGameUpdates)
  EVT_TEXT(ID_GAMES_DIR_EDIT, GeneralPanel::OnGameDir)
wxEND_EVENT_TABLE()

wxBEGIN_EVENT_TABLE(DownloadPanel, wxPanel)

wxEND_EVENT_TABLE()

wxBEGIN_EVENT_TABLE(RepositoryPanel, wxPanel)

wxEND_EVENT_TABLE()
//clang-format on


