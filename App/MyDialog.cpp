#include "MyDialog.h"

//--------------------------------------------------------------------------------
MyDialog::MyDialog(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos, const wxSize &size, long style)
	: wxDialog(parent, id, title, pos, size, style)
{
    wxButton *okButton = new wxButton(this, wxID_OK, wxT("OK"), wxPoint(10, 10), wxSize(70, 30));
}