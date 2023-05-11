#pragma once
#ifndef _MyApp_H_
#define _MyApp_H_

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class MyApp : public wxApp
{
public:
	virtual bool OnInit();
	virtual int OnExit();

protected:
	virtual void OnFatalException();

	void ShowSplashScreen(const wxString& image, const wxString& text = "");

	wxString m_AppTitle;

	bool m_FatalExptionOccurred;
};
wxIMPLEMENT_APP(MyApp);
#endif //_MyApp_H_