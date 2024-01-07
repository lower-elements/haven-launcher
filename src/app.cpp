#include <wx/wx.h>

#include "app.hpp"
#include "main_frame.hpp"

wxIMPLEMENT_APP(HavenApp);

bool HavenApp::OnInit() {
  HavenFrame *frame =
      new HavenFrame("Haven Launcher", wxPoint(50, 50), wxSize(800, 600));
  frame->Show(true);
  return true;
}
