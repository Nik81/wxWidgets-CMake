#pragma once
#ifndef _MyDialog_H_
#define _MyDialog_H_

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class MyDialog : public wxDialog
{
public:
	MyDialog(wxWindow *parent, wxWindowID id, const wxString &title,
		const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxDefaultSize,
		long style = wxDEFAULT_DIALOG_STYLE);

protected:

};

#endif //_MyDialog_H_