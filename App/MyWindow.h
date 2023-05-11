#pragma once
#ifndef _MyWindow_H_
#define _MyWindow_H_

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <wx/notebook.h>

class MyWindow : public wxWindow
{
public:

	MyWindow(wxWindow *parent, wxWindowID id, const wxPoint &pos = wxDefaultPosition,
		const wxSize &size = wxDefaultSize, long style = wxWANTS_CHARS, const wxString &name = wxPanelNameStr);

	~MyWindow();
};

#endif //_MyWindow_