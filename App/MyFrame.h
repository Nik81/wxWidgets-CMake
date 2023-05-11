#pragma once
#ifndef _MyFrame_H_
#define _MyFrame_H_

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#include <wx/mdi.h>
#endif

#include "MyLogPanel.h"
#include "MyTimebar.h"
#include "MyDialog.h"
#include "MyInnerFrame.h"
#include "MyNotebook.h"
#include "MyWindow.h"

class MyFrame : public wxMDIParentFrame//wxFrame
{
public:
	MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size, long style = 0L);
	~MyFrame();

	enum
	{
		ID_Hello = 1,
		ID_New,
		ID_Load,
		ID_Save,
		ID_View,
		ID_ShowWidget_First,
		ID_ShowToolbar,
		ID_ShowStatusBar,
		ID_ShowNotebook,
		ID_ShowWidget_Last,
	};

	void Init();

private:
	void OnHello(wxCommandEvent& event);
	void OnNew(wxCommandEvent& event);
	void OnView(wxCommandEvent& event);
	void OnShowWidget(wxCommandEvent& event);
	void OnLoad(wxCommandEvent& event);
	void OnSave(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	void OnExit(wxCommandEvent& event);
	void OnClose(wxCloseEvent & event);

	void CreateMenu();
	void CreateToolbar();
	void CreateStatusBar();
	void CreateLogPanel();
	void CreateNotebook();
	void CreateTimebar();
	void CreateDialog();

	void Load();
	void Save();

	void FontDialog();
	void ColorDialog();


	bool m_PlugMenu;
	bool m_PlugToolbar;
	bool m_PlugControlPanel;
	bool m_PlugStatusBar;
	bool m_PlugTimebar;
	bool m_PlugLogPanel;
	bool m_PlugNotebook;

	wxWindow *m_Win;

	wxToolBar   *m_ToolBar;
	wxStatusBar *m_StatusBar;
	MyLogPanel  *m_LogPanel;
	MyNotebook  *m_Notebook;
	MyTimebar   *m_Timebar;

	wxDECLARE_EVENT_TABLE();
};
#endif //_MyFrame_H_
