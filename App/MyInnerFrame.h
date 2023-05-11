#pragma once
#ifndef _MyInnerFrame_H_
#define _MyInnerFrame_H_

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#include <wx/mdi.h>
#endif

class MyInnerFrame : public wxMDIChildFrame
{
public:
	MyInnerFrame(wxMDIParentFrame *parent, const wxString &title, const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxDefaultSize);

protected:

};

#endif //_MyInnerFrame_H_