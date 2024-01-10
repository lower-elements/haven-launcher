#ifndef HAVEN_PREFERENCES_HPP
#define HAVEN_PREFERENCES_HPP

#include <wx/preferences.h>

class HavenPreferencesGeneral;
class HavenPreferencesRepository;
class HavenPreferencesDownload;


class HavenPreferences : public wxPreferencesEditor {
public:
  HavenPreferences(const wxString &title);
  virtual ~HavenPreferences() override;

private:
  // event definitions


  // event table
};

// event IDs go here


class HavenPreferencesGeneral : public wxPreferencesPage {
public:
  HavenPreferencesGeneral();
  virtual ~HavenPreferencesGeneral() override;

  virtual wxString GetName() const override;
  virtual wxWindow* CreateWindow(wxWindow *parent) override;
};

class HavenPreferencesRepository : public wxPreferencesPage {
public:
  HavenPreferencesRepository();
  virtual ~HavenPreferencesRepository();

  virtual wxString GetName() const override;
  virtual wxWindow* CreateWindow(wxWindow *parent) override;
};

class HavenPreferencesDownload : public wxPreferencesPage {
public:
  HavenPreferencesDownload();
  virtual ~HavenPreferencesDownload();

  virtual wxString GetName() const override;
  virtual wxWindow* CreateWindow(wxWindow *parent) override;
};

#endif