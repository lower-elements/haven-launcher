#include <wx/wx.h>
#include <wx/preferences.h>

#include <preferences.hpp>

HavenPreferences::HavenPreferences(const wxString &title) : wxPreferencesEditor(title) {
    AddPage(new HavenPreferencesGeneral());
    AddPage(new HavenPreferencesRepository());
    AddPage(new HavenPreferencesDownload());
    Show(nullptr);
};

HavenPreferences::~HavenPreferences() {};



HavenPreferencesGeneral::HavenPreferencesGeneral() : wxPreferencesPage() {};
HavenPreferencesGeneral::~HavenPreferencesGeneral() {};
wxString HavenPreferencesGeneral::GetName() const {
    return "general";
};
wxWindow* HavenPreferencesGeneral::CreateWindow(wxWindow *parent) {
    return new wxPanel(parent);
}

HavenPreferencesRepository::HavenPreferencesRepository() : wxPreferencesPage() {};
HavenPreferencesRepository::~HavenPreferencesRepository() {};
wxString HavenPreferencesRepository::GetName() const {
    return "repository settings";
};
wxWindow* HavenPreferencesRepository::CreateWindow(wxWindow *parent) {
    return new wxPanel(parent);
};

HavenPreferencesDownload::HavenPreferencesDownload() : wxPreferencesPage() {};
HavenPreferencesDownload::~HavenPreferencesDownload() {};
wxString HavenPreferencesDownload::GetName() const {
    return "download settings";
};
wxWindow* HavenPreferencesDownload::CreateWindow(wxWindow *parent) {
    return new wxPanel(parent);
};