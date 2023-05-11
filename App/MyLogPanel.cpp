#include "MyLogPanel.h"

//--------------------------------------------------------------------------------
MyLogPanel::MyLogPanel(wxFrame *parent)
	: wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN)
{
	m_textCtrl = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_READONLY);
}

//--------------------------------------------------------------------------------
void MyLogPanel::LogMessage(const wxString &message)
{
	m_textCtrl->AppendText(message + "\n");
}