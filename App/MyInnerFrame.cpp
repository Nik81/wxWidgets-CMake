#include "MyInnerFrame.h"
#include "wx\generic\laywin.h"

//--------------------------------------------------------------------------------
MyInnerFrame::MyInnerFrame(wxMDIParentFrame *parent, const wxString &title, const wxPoint &pos, const wxSize &size)
	: wxMDIChildFrame(parent, wxID_ANY, title, pos, size, wxFRAME_TOOL_WINDOW | wxFRAME_FLOAT_ON_PARENT) //: wxFrame(parent, wxID_ANY, title, pos, size, wxFRAME_TOOL_WINDOW | wxFRAME_FLOAT_ON_PARENT)
{
	SetBackgroundColour(wxColour(255, 255, 255));

	EnableCloseButton(true);
	EnableMaximizeButton(true);
	EnableMinimizeButton(true);

	//SetSize(100, 100);
	//SetPosition(wxPoint(50, 250));
	Maximize();
	Activate();

	// Personalizza il contenuto del frame interno qui

	wxFrame *frame = new wxFrame(this, NULL, "View");

	//ShowSplashScreen("Splash.bmp", "Splash...");

	//frame->Init();
	frame->Show(true);

	// Panel
	wxPanel *panel = new wxPanel(this, wxID_ANY, wxPoint(0, 0), wxSize(300, 200));
	panel->SetBackgroundColour(*wxBLUE);
	//	delete (panel);

	Init();
}