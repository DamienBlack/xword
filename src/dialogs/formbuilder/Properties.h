///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 16 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __Properties__
#define __Properties__

#include <wx/string.h>
#include <wx/radiobox.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/checkbox.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/panel.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/clrpicker.h>
#include <wx/stattext.h>
#include <wx/fontpicker.h>
#include <wx/notebook.h>
#include <wx/button.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class wxFB_PropertiesDialog
///////////////////////////////////////////////////////////////////////////////
class wxFB_PropertiesDialog : public wxDialog 
{
	private:
	
	protected:
		wxRadioBox* m_afterLetter;
		wxCheckBox* m_blankOnDirection;
		wxCheckBox* m_blankOnNewWord;
		wxRadioBox* m_pauseOnSwitch;
		wxCheckBox* m_moveOnRightClick;
		wxCheckBox* m_checkWhileTyping;
		wxColourPickerCtrl* m_selectedLetterColor;
		wxColourPickerCtrl* m_selectedWordColor;
		wxColourPickerCtrl* m_penColor;
		wxColourPickerCtrl* m_pencilColor;
		wxColourPickerCtrl* m_cluePromptBackground;
		wxColourPickerCtrl* m_cluePromptText;
		wxColourPickerCtrl* m_clueBackground;
		wxColourPickerCtrl* m_clueText;
		wxColourPickerCtrl* m_selectedClueBackground;
		wxColourPickerCtrl* m_selectedClueText;
		wxColourPickerCtrl* m_crossingClueBackground;
		wxColourPickerCtrl* m_crossingClueText;
		wxColourPickerCtrl* m_clueHeadingBackground;
		wxColourPickerCtrl* m_clueHeadingText;
		wxFontPickerCtrl* m_gridFont;
		wxFontPickerCtrl* m_cluePromptFont;
		wxFontPickerCtrl* m_clueFont;
		wxFontPickerCtrl* m_clueHeadingFont;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnAfterLetter( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnBlankOnDirection( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnBlankOnNewWord( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnPauseOnSwitch( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnMoveOnRightClick( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnCheckWhileTyping( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnSelectedLetterColor( wxColourPickerEvent& event ){ event.Skip(); }
		virtual void OnSelectedWordColor( wxColourPickerEvent& event ){ event.Skip(); }
		virtual void OnPenColor( wxColourPickerEvent& event ){ event.Skip(); }
		virtual void OnPencilColor( wxColourPickerEvent& event ){ event.Skip(); }
		virtual void OnPromptBackgroundColor( wxColourPickerEvent& event ){ event.Skip(); }
		virtual void OnPromptTextColor( wxColourPickerEvent& event ){ event.Skip(); }
		virtual void OnClueBackgroundColor( wxColourPickerEvent& event ){ event.Skip(); }
		virtual void OnClueTextColor( wxColourPickerEvent& event ){ event.Skip(); }
		virtual void OnSelectedClueBackgroundColor( wxColourPickerEvent& event ){ event.Skip(); }
		virtual void OnSelectedClueTextColor( wxColourPickerEvent& event ){ event.Skip(); }
		virtual void OnCrossingClueBackgroundColor( wxColourPickerEvent& event ){ event.Skip(); }
		virtual void OnCrossingClueTextColor( wxColourPickerEvent& event ){ event.Skip(); }
		virtual void OnClueHeadingBackgroundColor( wxColourPickerEvent& event ){ event.Skip(); }
		virtual void OnClueHeadingTextColor( wxColourPickerEvent& event ){ event.Skip(); }
		virtual void OnGridFont( wxFontPickerEvent& event ){ event.Skip(); }
		virtual void OnCluePromptFont( wxFontPickerEvent& event ){ event.Skip(); }
		virtual void OnClueFont( wxFontPickerEvent& event ){ event.Skip(); }
		virtual void OnClueHeadingFont( wxFontPickerEvent& event ){ event.Skip(); }
		
	
	public:
		wxFB_PropertiesDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Options"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE );
		~wxFB_PropertiesDialog();
	
};

#endif //__Properties__