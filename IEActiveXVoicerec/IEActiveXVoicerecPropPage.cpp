// IEActiveXVoicerecPropPage.cpp : Implementation of the CIEActiveXVoicerecPropPage property page class.

#include "stdafx.h"
#include "IEActiveXVoicerec.h"
#include "IEActiveXVoicerecPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CIEActiveXVoicerecPropPage, COlePropertyPage)

// Message map

BEGIN_MESSAGE_MAP(CIEActiveXVoicerecPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CIEActiveXVoicerecPropPage, "MFCACTIVEXCONT.IEActiveXVoicerecPropPage.1",
	0x920da1df,0xd74d,0x48e1,0x89,0x33,0xbd,0x12,0x55,0x10,0x34,0x5e)

// CIEActiveXVoicerecPropPage::CIEActiveXVoicerecPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CIEActiveXVoicerecPropPage

BOOL CIEActiveXVoicerecPropPage::CIEActiveXVoicerecPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_IEACTIVEXVOICEREC_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, nullptr);
}

// CIEActiveXVoicerecPropPage::CIEActiveXVoicerecPropPage - Constructor

CIEActiveXVoicerecPropPage::CIEActiveXVoicerecPropPage() :
	COlePropertyPage(IDD, IDS_IEACTIVEXVOICEREC_PPG_CAPTION)
{
}

// CIEActiveXVoicerecPropPage::DoDataExchange - Moves data between page and properties

void CIEActiveXVoicerecPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CIEActiveXVoicerecPropPage message handlers
