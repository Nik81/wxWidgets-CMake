#pragma once
#ifndef _MyLogPanel_H_
#define _MyLogPanel_H_

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class MyLogPanel : public wxPanel
{
public:
	MyLogPanel(wxFrame *parent);
	void LogMessage(const wxString &message);

protected:

private:
	wxTextCtrl *m_textCtrl;
};

#endif //_MyLogPanel_H_