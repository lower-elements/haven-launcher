// For compilers that support precompilation, includes "wx.h".
#include <wx/wxprec.h>

#ifdef __BORLANDC__
#   pragma hdrstop
#endif

#ifndef WX_PRECOMP
#   include <wx/wx.h>
#endif

#include "app.hpp"
#include "main_frame.hpp"

wxIMPLEMENT_APP(HavenApp);

bool HavenApp::OnInit() {
  HavenFrame *frame =
      new HavenFrame("Haven Launcher", wxPoint(50, 50), wxSize(800, 600));
  frame->Show(true);
  return true;
}
