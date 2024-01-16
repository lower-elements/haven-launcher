#ifndef HAVEN_MAIN_FRAME_HPP
#define HAVEN_MAIN_FRAME_HPP

#include <wx/wx.h>
#include <wx/config.h>

class HavenFrame : public wxFrame {
public:
  HavenFrame(const wxString &title, const wxPoint &pos, const wxSize &size);

private:
  wxConfig M_Config;
  void OnPreferences(wxCommandEvent &event);
  void OnExit(wxCommandEvent &event);
  void OnAbout(wxCommandEvent &event);

  wxDECLARE_EVENT_TABLE();
};

enum { ID_Hello = 1 };

#endif
