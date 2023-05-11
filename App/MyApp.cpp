#include "MyApp.h"
#include "Defines.h"
#include "MyFrame.h"

#include <wx/splash.h>

//--------------------------------------------------------------------------------
bool MyApp::OnInit()
{
	m_AppTitle = "Hello World";

	m_FatalExptionOccurred = false;

	//
	MyFrame *frame = new MyFrame(m_AppTitle, wxPoint(50, 50), wxSize(450, 340));

	//ShowSplashScreen("Splash.bmp", "Splash...");

	frame->Init();
	frame->Show(true);
	
	return true;
}
//--------------------------------------------------------------------------------
int MyApp::OnExit()
{
	return 0;
}
//--------------------------------------------------------------------------------
void MyApp::OnFatalException()
{
	if (!m_FatalExptionOccurred)
	{
		m_FatalExptionOccurred = true;

		int answare = wxMessageBox(_("An Excpetion has occurred and this application must be closed.\nYou can make a attempt to save your work.\nDo You want to proceed?"), _("Fatal Exception!"), wxYES_NO | wxCENTER | wxICON_ERROR | wxYES_DEFAULT);
		if (answare == wxID_YES)
		{
			//Try to Save Work
		}
	}
}

//--------------------------------------------------------------------------------
void MyApp::ShowSplashScreen(const wxString& image, const wxString& text)
{
	wxString imageName = wxString::Format("%s%s", ASSETS_PATH, image);

	if (!imageName.empty())
	{
		wxBitmap bitmap;
		bitmap.LoadFile(imageName, wxBITMAP_TYPE_BMP);

		long splashStyle = wxSPLASH_CENTRE_ON_SCREEN | wxSPLASH_TIMEOUT;
		int milliseconds = 2000;
		
		//
		wxSplashScreen *splash = new wxSplashScreen(bitmap, splashStyle, milliseconds, NULL, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER | wxSTAY_ON_TOP);

		if (!text.empty())
		{
			wxColour textColor = *wxBLACK;
			int textPosX = 3;
			int textPosY = 3;

			wxMemoryDC memDC;

			memDC.SelectObject(bitmap);

			memDC.SetBackgroundMode(wxTRANSPARENT);
			memDC.SetTextForeground(textColor);
			memDC.DrawText(text, textPosX, textPosY);

			memDC.SelectObject(wxNullBitmap);

			splash->GetSplashWindow()->SetBitmap(bitmap);
			splash->GetSplashWindow()->Refresh();
			splash->GetSplashWindow()->Update();
		}

		wxMilliSleep(1500);
	}
}