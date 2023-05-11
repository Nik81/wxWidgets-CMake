#pragma once
#ifndef _MyFrameManager_H_
#define _MyFrameManager_H_

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#include <wx/mdi.h>
#endif

class MyFrameManager : public wxFrameManager
{

public:

	/** add pane */
	virtual bool AddPane(wxWindow* window, const wxPaneInfo& pane_info, const wxString &menu = _("&View"), const wxString &subMenu = wxEmptyString);
	/** add pane overload*/
	virtual bool AddPane(wxWindow* window, int direction = wxLEFT, const wxString& caption = wxEmptyString);
	/** update */
	virtual void Update();
protected:

	
};
#endif //_MyFrameManager_H_
