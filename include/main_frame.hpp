#ifndef HAVEN_MAIN_FRAME_HPP
#define HAVEN_MAIN_FRAME_HPP

#include <wx/wx.h>

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

#endif
