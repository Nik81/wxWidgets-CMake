#include "MyFrame.h"
#include "Defines.h"

#include <algorithm>
#include <fstream>
#include <iosfwd>
#include <iterator>
#include <locale>
#include <sstream>
#include <string>

#include <wx/colourdata.h>
#include <wx/colordlg.h>
#include <wx/fontdata.h>
#include <wx/fontdlg.h>


wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
EVT_MENU(ID_New, MyFrame::OnNew)
EVT_MENU(ID_Load, MyFrame::OnLoad)
EVT_MENU(ID_Save, MyFrame::OnSave)
EVT_MENU(ID_Hello, MyFrame::OnHello)
EVT_MENU(ID_View, MyFrame::OnView)
// EVT_MENU(ID_ShowToolbar, MyFrame::OnShowWidget)
// EVT_MENU(ID_ShowStatusBar, MyFrame::OnShowWidget)
EVT_MENU_RANGE(ID_ShowWidget_First, ID_ShowWidget_Last, MyFrame::OnShowWidget)
EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
EVT_MENU(wxID_EXIT, MyFrame::OnExit)
EVT_CLOSE(MyFrame::OnClose)
wxEND_EVENT_TABLE()

//--------------------------------------------------------------------------------
MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size, long style)
	: wxMDIParentFrame(NULL, wxID_ANY, title, pos, size/*, wxDEFAULT_FRAME_STYLE | wxHSCROLL | wxVSCROLL | style*/)
{
	m_Win = this;

	this->SetMinSize(wxSize(600, 500));

	//this->SetBackgroundColour(wxColour(255, 255, 255));

	wxString imageName = wxString::Format("%s%s", ASSETS_PATH, "icon.ico");

	wxIcon icon(imageName, wxBITMAP_TYPE_ICO);
	this->SetIcon(icon);

	m_PlugMenu = true;
	m_PlugToolbar = true;
	m_PlugStatusBar = true;
	m_PlugControlPanel = false;
	m_PlugTimebar = false;
	m_PlugLogPanel = false;
	m_PlugNotebook = false;
	
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

//--------------------------------------------------------------------------------
void MyFrame::Init()
{
	if (m_PlugNotebook)
		CreateNotebook();

	if (m_PlugMenu)
		CreateMenu();

	if (m_PlugToolbar)
		CreateToolbar();

	if (m_PlugStatusBar)
		CreateStatusBar();

	if (m_PlugLogPanel)
		CreateLogPanel();

	if (m_PlugTimebar)
		CreateTimebar();

}

//--------------------------------------------------------------------------------
void MyFrame::CreateMenu()
{
	wxMenu *menuFile = new wxMenu;
	menuFile->Append(ID_New, "&New\tCtrl-N", "New File");
	menuFile->Append(ID_Load, "&Open...\tCtrl-O", "Load File");
	menuFile->Append(ID_Save, "&Save\tCtrl-S", "Save File");
	menuFile->AppendSeparator();
	menuFile->Append(ID_Hello, "&Hello...\tCtrl-H", "Help string shown in status bar for this menu item");
	menuFile->AppendSeparator();
	menuFile->Append(wxID_EXIT);

	wxMenu *menuView = new wxMenu;
	menuView->Append(ID_View, "&View...\tCtrl-W");
	menuView->AppendSeparator();
	if (m_PlugToolbar) menuView->AppendCheckItem(ID_ShowToolbar, "Toolbar")->Check(true);
	if (m_PlugNotebook) menuView->AppendCheckItem(ID_ShowNotebook, "Notebook")->Check(true);
	if (m_PlugStatusBar) menuView->AppendCheckItem(ID_ShowStatusBar, "Status Bar")->Check(true);

	wxMenu *menuHelp = new wxMenu;
	menuHelp->Append(wxID_ABOUT);

	wxMenuBar *menuBar = new wxMenuBar;
	menuBar->Append(menuFile, "&File");
	menuBar->Append(menuView, "&View");
	menuBar->Append(menuHelp, "&Help");
	SetMenuBar(menuBar);
}
//--------------------------------------------------------------------------------
void MyFrame::CreateToolbar()
{
	m_ToolBar = wxFrame::CreateToolBar();

	m_ToolBar->SetMargins(0, 0);
	m_ToolBar->SetToolSeparation(2);
	m_ToolBar->SetToolBitmapSize(wxSize(20, 20));

	wxImage::AddHandler(new wxPNGHandler);

	wxString imagePath = ASSETS_PATH;

	wxBitmap exitBitmap(wxString::Format("%s%s", ASSETS_PATH, "exit.png").c_str(), wxBITMAP_TYPE_PNG);
	wxBitmap newBitmap(wxString::Format("%s%s", ASSETS_PATH, "new.png").c_str(), wxBITMAP_TYPE_PNG);
	wxBitmap openBitmap(wxString::Format("%s%s", ASSETS_PATH, "open.png").c_str(), wxBITMAP_TYPE_PNG);
	wxBitmap saveBitmap(wxString::Format("%s%s", ASSETS_PATH, "save.png").c_str(), wxBITMAP_TYPE_PNG);
	wxBitmap viewBitmap(wxString::Format("%s%s", ASSETS_PATH, "view.png").c_str(), wxBITMAP_TYPE_PNG);

	m_ToolBar->AddTool(ID_Hello, wxT("Hello"), newBitmap, "Hello");
	m_ToolBar->AddTool(ID_View, wxT("View"), viewBitmap, "Open");
	//m_ToolBar->AddTool(wxID_ANY, wxT(""), saveBitmap, "Save");
	m_ToolBar->AddTool(wxID_EXIT, wxT("Exit application"), exitBitmap, "Quit");
	m_ToolBar->AddSeparator();

	m_ToolBar->Realize();
}
//--------------------------------------------------------------------------------
void MyFrame::CreateStatusBar()
{
	m_StatusBar = wxFrame::CreateStatusBar();
	SetStatusText("Welcome to wxWidgets!");
}
//--------------------------------------------------------------------------------
void MyFrame::CreateLogPanel()
{
	m_LogPanel = new MyLogPanel(this);
	m_LogPanel->SetBackgroundColour(*wxWHITE);
	m_LogPanel->SetForegroundColour(*wxBLACK);
	m_LogPanel->SetPosition(wxPoint(0, 0));
}
//--------------------------------------------------------------------------------
void MyFrame::CreateNotebook()
{
	m_Notebook = new MyNotebook(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNB_DEFAULT);
	//m_notebook->SetSize(200, 600);

	wxPanel *panel1 = new wxPanel(m_Notebook, wxID_ANY);
	wxStaticText *staticText1 = new wxStaticText(panel1, wxID_ANY, "Scheda 1", wxPoint(20, 20));
	m_Notebook->AddPage(panel1, "Scheda 1");

	wxPanel *panel2 = new wxPanel(m_Notebook, wxID_ANY);
	wxStaticText *staticText2 = new wxStaticText(panel2, wxID_ANY, "Scheda 2", wxPoint(20, 20));
	m_Notebook->AddPage(panel2, "Scheda 2");
}
//--------------------------------------------------------------------------------
void MyFrame::CreateTimebar()
{
	m_Timebar = new MyTimebar(this, wxID_ANY, 100, wxPoint(10, 100), wxSize(280, 20), wxGA_HORIZONTAL);
	m_Timebar->SetValue(50);
}
//--------------------------------------------------------------------------------
void MyFrame::CreateDialog()
{
	//FontDialog();
	//ColorDialog();

	// Dialog
	MyDialog *dialog = new MyDialog(NULL, wxID_ANY, wxT("My dialog"), wxPoint(50, 50), wxSize(150, 150));
	dialog->ShowModal();
	delete (dialog);
}

/// EVENTS
//--------------------------------------------------------------------------------
void MyFrame::OnHello(wxCommandEvent& event)
{
	wxLogMessage("Hello world from wxWidgets!");

	if (m_LogPanel)
		m_LogPanel->LogMessage("Hello world from wxWidgets!");
}
//--------------------------------------------------------------------------------
void MyFrame::OnNew(wxCommandEvent& event)
{

}
//--------------------------------------------------------------------------------
void MyFrame::OnView(wxCommandEvent& event)
{
	//wxFrame *frame = new wxFrame(this, NULL, "View");
	//wxMDIChildFrame *frame = new wxMDIChildFrame(this, NULL, "View");
	//frame->Show();

	wxBoxSizer* mySizer;
	mySizer = new wxBoxSizer(wxHORIZONTAL);

	wxScrolledWindow *m_ScrolledWindow = new wxScrolledWindow(this, NULL, wxDefaultPosition, wxDefaultSize, wxHSCROLL | wxVSCROLL);
	m_ScrolledWindow->SetScrollRate(5, 5);
	mySizer->Add(m_ScrolledWindow, 1, wxEXPAND | wxALL, 5);

	this->SetSizer(mySizer);
	this->Layout();

	m_ScrolledWindow->SetVirtualSize(wxSize(2000, 2000));

	wxFrame *m_designframe = new wxFrame(m_ScrolledWindow, -1, "sample child");
	m_designframe->SetSize(wxSize(300, 200));
	m_designframe->Move(0, 0);
	m_designframe->Show();

	Show();	
}
//--------------------------------------------------------------------------------
void MyFrame::OnShowWidget(wxCommandEvent& event)
{
	int eventInt = event.GetInt();

	switch (event.GetId())
	{
	case ID_ShowToolbar:
		m_ToolBar->Show(eventInt);
	break;

	case ID_ShowStatusBar:
		m_StatusBar->Show(eventInt);
	break;

	case ID_ShowNotebook:
		m_Notebook->Show(eventInt);
		break;
	}
}
//--------------------------------------------------------------------------------
void MyFrame::OnLoad(wxCommandEvent& event)
{
	Load();
}
//--------------------------------------------------------------------------------
void MyFrame::OnSave(wxCommandEvent& event)
{
	Save();
}
//--------------------------------------------------------------------------------
void MyFrame::OnAbout(wxCommandEvent& event)
{
	wxMessageBox("This is a wxWidgets' Hello world sample",
		"About Hello World", wxOK | wxICON_INFORMATION);
}
//--------------------------------------------------------------------------------
void MyFrame::OnExit(wxCommandEvent& event)
{
	Close(true);
}
//--------------------------------------------------------------------------------
void MyFrame::OnClose(wxCloseEvent & event)
{
	wxMessageDialog dial(NULL, _("Do you really want to quit?"), _("Exit"), wxYES_NO | wxNO_DEFAULT | wxICON_QUESTION);

	if (dial.ShowModal() == wxID_YES)
		Destroy();
}

//--------------------------------------------------------------------------------
void MyFrame::Load()
{
	int m_playerHealth = 0;
	int m_playerScore = 0;
	int m_playerLevel = 0;
	std::string m_PlayerName = "";

	const std::string fileName = "filename.sav";
	const std::string fileName2 = "filename2.sav";

	std::ifstream inFile(fileName);
	if (inFile.is_open())
	{
		for (int i = 0; i < 500; i++)
		{
			inFile >> m_playerHealth;
			inFile >> m_playerScore;
			inFile >> m_playerLevel;
			inFile >> m_PlayerName;

			//std::getline(inFile, m_PlayerName);

			// 			std::stringstream ss;
			// 			ss << inFile.rdbuf();
			// 			m_PlayerName = ss.str();
		}
		inFile.close();
	}
	else
	{
		// handle file opening error
	}

	//
	std::ifstream inFile2(fileName2, std::ios::binary);
	if (inFile2.is_open())
	{
		for (int i = 0; i < 500; i++)
		{
			inFile2.read(reinterpret_cast<char*>(&m_playerHealth), sizeof(int));
			inFile2.read(reinterpret_cast<char*>(&m_playerScore), sizeof(int));
			inFile2.read(reinterpret_cast<char*>(&m_playerLevel), sizeof(int));
			inFile2.read(reinterpret_cast<char*>(&m_PlayerName), sizeof(char));
		}
		inFile2.close();
	}
	else
	{
		// handle file opening error
	}
}
//--------------------------------------------------------------------------------
void MyFrame::Save()
{
	int m_playerHealth = 100;
	int m_playerScore = 2345;
	int m_playerLevel = 42;
	std::string m_PlayerName = "Hello world from wxWidgets!";


	const std::string fileName = "filename.sav";
	const std::string fileName2 = "filename2.sav";

	std::ofstream outFile(fileName);
	if (outFile.is_open())
	{
		for (int i = 0; i < 500; i++)
		{
			outFile << m_playerHealth << std::endl;
			outFile << m_playerScore << std::endl;
			outFile << m_playerLevel << std::endl;
			outFile << m_PlayerName << std::endl;

			// 			std::stringstream ss;
			// 			ss << m_PlayerName;
			// 			outFile << ss.str();
		}
		outFile.close();
	}
	else
	{
		// handle file opening error
	}

	//
	std::ofstream outFile2(fileName2, std::ios::binary);
	if (outFile2.is_open())
	{
		for (int i = 0; i < 500; i++)
		{
			outFile2.write(reinterpret_cast<char*>(&m_playerHealth), sizeof(int));
			outFile2.write(reinterpret_cast<char*>(&m_playerScore), sizeof(int));
			outFile2.write(reinterpret_cast<char*>(&m_playerLevel), sizeof(int));
			outFile2.write(reinterpret_cast<char*>(&m_PlayerName), sizeof(char));
		}
		outFile2.close();
	}
	else
	{
		// handle file opening error
	}
}

//--------------------------------------------------------------------------------
void MyFrame::FontDialog()
{
	wxFont canvasFont;
	wxColour canvasTextColour;

	wxFontData data;
	data.SetInitialFont(canvasFont);
	data.SetColour(canvasTextColour);

	wxFontDialog dialog(this/*, &data*/);
	if (dialog.ShowModal() == wxID_OK)
	{
		wxFontData retData = dialog.GetFontData();
		canvasFont = retData.GetChosenFont();
		canvasTextColour = retData.GetColour();
		//myWindow->Refresh();
	}
}
//--------------------------------------------------------------------------------
void MyFrame::ColorDialog()
{
	wxColourData data;
	data.SetChooseFull(true);
	for (int i = 0; i < 16; i++)
	{
		wxColour colour(i * 16, i * 16, i * 16);
		data.SetCustomColour(i, colour);
	}

	wxColourDialog dialog(this, &data);
	if (dialog.ShowModal() == wxID_OK)
	{
		wxColourData retData = dialog.GetColourData();
		wxColour col = retData.GetColour();
		wxBrush brush(col, wxBRUSHSTYLE_SOLID);
		// 		myWindow->SetBackground(brush);
		// 		myWindow->Clear();
		// 		myWindow->Refresh();
	}
}