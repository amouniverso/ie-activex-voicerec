#pragma once

// IEActiveXVoicerecCtrl.h : Declaration of the CIEActiveXVoicerecCtrl ActiveX Control class.


// CIEActiveXVoicerecCtrl : See IEActiveXVoicerecCtrl.cpp for implementation.

class CIEActiveXVoicerecCtrl : public COleControl
{
	DECLARE_DYNCREATE(CIEActiveXVoicerecCtrl)

// Constructor
public:
	CIEActiveXVoicerecCtrl();

// Overrides
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	virtual DWORD GetControlFlags();

// Implementation
protected:
	~CIEActiveXVoicerecCtrl();

	DECLARE_OLECREATE_EX(CIEActiveXVoicerecCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CIEActiveXVoicerecCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CIEActiveXVoicerecCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CIEActiveXVoicerecCtrl)		// Type name and misc status

	// Subclassed control support
	BOOL IsSubclassedControl();
	LRESULT OnOcmCommand(WPARAM wParam, LPARAM lParam);

// Message maps
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	DECLARE_DISPATCH_MAP()

// Event maps
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
		dispidstartRecording = 1L,
		dispidstopRecording = 2L,
	};
protected:
	void startRecording();
	BSTR stopRecording();
};

