#pragma once
#ifndef _MyNotebook_H_
#define _MyNotebook_H_

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <wx/notebook.h>

class MyNotebook : public wxNotebook
{
public:
	MyNotebook(wxWindow *parent, wxWindowID id, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,	long style = 0);

};

#endif //_MyNotebook_