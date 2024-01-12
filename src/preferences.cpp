#include <wx/preferences.h>
#include <wx/wx.h>
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
    wxChoice* LanguageChoice = new wxChoice(Panel, wxID_ANY);
    LanguageChoice->SetExtraStyle(wxCB_SORT);
    LanguageChoice->SetName("Language");
    LanguageChoice->Append("English");
    LanguageChoice->SetSelection(0);

    Sizer->Add(new wxStaticText(Panel, wxID_ANY, "Language"));
    Sizer->Add(LanguageChoice);

    wxCheckBox* LauncherUpdates = new wxCheckBox(Panel, wxID_ANY, "Check for updates to the launcher on opening the app");
    LauncherUpdates->SetValue(1);
    Sizer->Add(new wxStaticText(Panel, wxID_ANY, ""));
    Sizer->Add(LauncherUpdates);
    wxCheckBox* GameUpdates = new wxCheckBox(Panel, wxID_ANY, "Check for updates to Installed Games on the opening of the app");
    GameUpdates->SetValue(1);
    Sizer->Add(new wxStaticText(Panel, wxID_ANY, ""));
    Sizer->Add(GameUpdates);


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
  return new wxPanel(parent);
};

HavenPreferencesDownload::HavenPreferencesDownload() : wxPreferencesPage(){};
HavenPreferencesDownload::~HavenPreferencesDownload(){};
wxString HavenPreferencesDownload::GetName() const {
  return "download settings";
};
wxWindow *HavenPreferencesDownload::CreateWindow(wxWindow *parent) {
  return new wxPanel(parent);
};
