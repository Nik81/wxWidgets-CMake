#include "MyFrameManager.h"


//--------------------------------------------------------------------------------
MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size, long style)
	: wxMDIParentFrame((wxFrame *)NULL, -1, title, pos, size, wxDEFAULT_FRAME_STYLE | wxHSCROLL | wxVSCROLL | style) //: wxFrame(NULL, wxID_ANY, title, pos, size)
{
	this->SetMinSize(wxSize(600, 500));

	//SetBackgroundColour(wxColour(255, 255, 255));

	wxIcon icon("C:/DEV_64/myProject/wxWidgets-CMake/Assets/icon.ico", wxBITMAP_TYPE_ICO);
	SetIcon(icon);

	m_PlugMenu = true;
	m_PlugToolbar = true;
	m_PlugStatusBar = true;

	m_PlugControlPanel = false;
	m_PlugTimebar = false;
	m_PlugLogPanel = false;
	m_PlugNotebook = false;

	m_Win = this; 	
	m_Win = this->GetMainWindowOfCompositeControl();
	
	m_ToolBar = NULL;
	m_StatusBar = NULL;
	m_LogPanel = NULL;
	m_Notebook = NULL;
	m_Timebar = NULL;
}
//--------------------------------------------------------------------------------
MyFrame::~MyFrame()
{

}
