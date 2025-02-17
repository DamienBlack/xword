///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include "../widgets/ScaledSpinCtrl.h"
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/checkbox.h>
#include <wx/sizer.h>
#include <wx/radiobut.h>
#include <wx/spinctrl.h>
#include <wx/panel.h>
#include <wx/choice.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include "fontpicker.hpp"
#include <wx/slider.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class wxFB_SolvePanel
///////////////////////////////////////////////////////////////////////////////
class wxFB_SolvePanel : public wxPanel
{
	private:

	protected:
		wxCheckBox* m_startTimer;
		wxCheckBox* m_checkWhileTyping;
		wxCheckBox* m_strictRebus;
		wxCheckBox* m_showCompletionStatus;
		wxCheckBox* m_moveAfterLetter;
		wxRadioButton* m_nextSquare;
		wxRadioButton* m_nextBlank;
		wxStaticText* m_staticText16;
		wxRadioButton* m_insertBlankOnSpace;
		wxRadioButton* m_switchDirectionsOnSpace;
		wxCheckBox* m_blankOnDirection;
		wxCheckBox* m_blankOnNewWord;
		wxCheckBox* m_pauseOnSwitch;
		wxCheckBox* m_moveOnRightClick;
		wxCheckBox* m_swapOnDClick;
		wxCheckBox* m_useAutoSave;
		wxStaticText* m_stAfter;
		ScaledSpinCtrl* m_autoSave;
		wxStaticText* m_stSeconds;
		wxCheckBox* m_saveFileHistory;
		wxCheckBox* m_reopenLastPuzzle;

		// Virtual event handlers, overide them in your derived class
		virtual void OnMoveAfterLetter( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUseAutoSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSaveFileHistory( wxCommandEvent& event ) { event.Skip(); }


	public:

		wxFB_SolvePanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );
		~wxFB_SolvePanel();

};

///////////////////////////////////////////////////////////////////////////////
/// Class wxFB_AppearancePanel
///////////////////////////////////////////////////////////////////////////////
class wxFB_AppearancePanel : public wxPanel
{
	private:

	protected:
		wxChoice* m_advancedChoice;
		wxButton* m_defaultsBtn;

		// Virtual event handlers, overide them in your derived class
		virtual void OnAdvancedChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnResetDefaults( wxCommandEvent& event ) { event.Skip(); }


	public:

		wxFB_AppearancePanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );
		~wxFB_AppearancePanel();

};

///////////////////////////////////////////////////////////////////////////////
/// Class wxFB_PrintPanel
///////////////////////////////////////////////////////////////////////////////
class wxFB_PrintPanel : public wxPanel
{
	private:

	protected:
		wxCheckBox* m_printCustomFonts;
		FontPickerPanel * m_printGridLetterFont;
		FontPickerPanel * m_printGridNumberFont;
		FontPickerPanel * m_printClueFont;
		wxRadioButton* m_alignTL;
		wxRadioButton* m_alignTR;
		wxRadioButton* m_alignBL;
		wxRadioButton* m_alignBR;
		wxStaticText* m_staticText13;
		wxSlider* m_printBlackSquareBrightness;
		wxStaticText* m_staticText14;
		wxPanel* m_panel8;
		wxPanel* m_printBlackSquarePreview;

		// Virtual event handlers, overide them in your derived class
		virtual void OnPrintCustomFonts( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnBlackSquareBrightness( wxScrollEvent& event ) { event.Skip(); }


	public:

		wxFB_PrintPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );
		~wxFB_PrintPanel();

};

