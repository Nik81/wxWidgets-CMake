#pragma once
#ifndef _MyTimebar_H_
#define _MyTimebar_H_

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class MyTimebar : public wxGauge
{
public:
	MyTimebar(wxWindow *parent, wxWindowID id, int range, const wxPoint &pos, const wxSize &size, long style);
	virtual void OnPaint(wxPaintEvent &event);
};

#endif //_MyTimebar_H_