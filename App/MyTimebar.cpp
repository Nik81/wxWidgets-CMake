#include "MyTimebar.h"

//--------------------------------------------------------------------------------
MyTimebar::MyTimebar(wxWindow *parent, wxWindowID id, int range, const wxPoint &pos, const wxSize &size, long style)
	: wxGauge(parent, id, range, pos, size, style)
{
}

//--------------------------------------------------------------------------------
void MyTimebar::OnPaint(wxPaintEvent &event)
{
	wxPaintDC dc(this);
	dc.SetBrush(wxBrush(wxColour(255, 0, 0)));
	dc.DrawRectangle(wxRect(wxPoint(0, 0), GetSize()));

	int val = GetValue();
	int width = (val * GetSize().GetWidth()) / GetRange();

	dc.SetBrush(wxBrush(wxColour(0, 255, 0)));
	dc.DrawRectangle(wxRect(wxPoint(0, 0), wxSize(width, GetSize().GetHeight())));
}