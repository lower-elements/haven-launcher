#ifndef HAVEN_PREFERENCES_HPP
#define HAVEN_PREFERENCES_HPP

#include <wx/preferences.h>
#include <wx/config.h>
#include <wx/wx.h>


class HavenPreferencesGeneral;
class GeneralPanel;

class HavenPreferencesRepository;
class RepositoryPanel;

class HavenPreferencesDownload;
class DownloadPanel;


class HavenPreferences : public wxPreferencesEditor {
public:
  HavenPreferences(const wxString &title, wxConfig& Config);
  virtual ~HavenPreferences() override;

private:
  wxConfig& M_Config;
};



class HavenPreferencesGeneral : public wxPreferencesPage {
public:
  HavenPreferencesGeneral(wxConfig& Config);
  virtual ~HavenPreferencesGeneral() override;

  virtual wxString GetName() const override;
  virtual wxWindow* CreateWindow(wxWindow *parent) override;
  
private:
  wxConfig& M_Config;
};

class HavenPreferencesRepository : public wxPreferencesPage {
public:
  HavenPreferencesRepository(wxConfig& Config);
  virtual ~HavenPreferencesRepository();

  virtual wxString GetName() const override;
  virtual wxWindow* CreateWindow(wxWindow *parent) override;

private:
  wxConfig& M_Config;
};

class HavenPreferencesDownload : public wxPreferencesPage {
public:
  HavenPreferencesDownload(wxConfig& Config);
  virtual ~HavenPreferencesDownload();

  virtual wxString GetName() const override;
  virtual wxWindow* CreateWindow(wxWindow *parent) override;

private:
  wxConfig& M_Config;
};



class GeneralPanel : public wxPanel {
public:
  GeneralPanel(wxWindow* Parent, wxConfig& Config);
  void OnLang(wxCommandEvent &event);
  void OnGameUpdates(wxCommandEvent &event);
  void OnLauncherUpdates(wxCommandEvent &event);
  void OnGameDir(wxCommandEvent &event);
private:
  wxConfig& M_Config;

  wxDECLARE_EVENT_TABLE();
};

class RepositoryPanel : public wxPanel {
public:
  RepositoryPanel(wxWindow* Parent, wxConfig& Config);
private:
  wxConfig& M_Config;

  wxDECLARE_EVENT_TABLE();
};

class DownloadPanel : public wxPanel {
public:
  DownloadPanel(wxWindow* Parent, wxConfig& Config);
private:
  wxConfig& M_Config;

  wxDECLARE_EVENT_TABLE();
};




enum {
  ID_LANG,
  ID_LAUNCHER_UPDATES,
  ID_GAME_UPDATES,
  ID_GAMES_DIR_EDIT,
  ID_GAMES_DIR_BROWSE,
  ID_DOWNLOAD_DIR__EDIT,
  ID_DOWNLOAD_DIR_BROWSE,
  ID_DOWNLOAD_THROTTLE_MB,
  ID_DOWNLOAD_THROTTLE_KB
};

#endif