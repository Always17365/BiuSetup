#ifndef __SKINENGINE_H__
#define  __SKINENGINE_H__
#pragma  once
#include "StdAfx.h"
#include "UIlib.h"
#include <map>
#include "MsgDef.h"

namespace DuiLib {

class CSkinEngine : public CWindowWnd, public INotifyUI
{
public:
	CSkinEngine(void){
	
		
		
	}
	~CSkinEngine() {}

	LPCTSTR GetWindowClassName() const { return _T("nsTBCIASkinEngine"); }
	UINT GetClassStyle() const { return CS_DBLCLKS; }
	void OnFinalMessage(HWND /*hWnd*/)
	{ 
		m_pm.RemoveNotifier( this );	
		delete this; 
	}

	
	void Notify(TNotifyUI& msg);

	LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
 	LRESULT OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
  	LRESULT OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnNcActivate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnNcCalcSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnNcPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnNcHitTest(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnSysCommand(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnTBCIAMinMSG(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnTBCIACloseMSG(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnTBCIABackMSG(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnTBCIANextMSG(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnTBCIAStartInstallMSG(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnTBCIAStartUninstallMSG(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnTBCIAFinishedInstallMSG(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnDPIChanged(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
	BOOL IsInStaticControl(CControlUI *pControl);
	void       SetSkinXMLPath( LPCTSTR path );
	LPCTSTR GetSkinXMLPath();
	LRESULT OnGetMinMaxInfo(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	CPaintManagerUI& GetPaintManager();
 	void SaveToControlCallbackMap( CDuiString ctlName, int callback );
	


private:
	CPaintManagerUI              m_pm;
	TCHAR                               m_skinXMLPath[MAX_PATH];
	
	
	std::map<CDuiString, int> m_controlCallbackMap;
};

//////////////////////////////////////////////////////////////////////////
/// CTBCIAMessageBox

class CTBCIAMessageBox : public CWindowWnd, public INotifyUI
{
public:
	CTBCIAMessageBox() {}
	~CTBCIAMessageBox() {}

	LPCTSTR GetWindowClassName() const { return _T("nsTBCIASkinEngine"); }
	UINT GetClassStyle() const { return CS_DBLCLKS; }
	void OnFinalMessage(HWND /*hWnd*/) 
	{
		m_pm.RemoveNotifier(this);
		delete this;
	}

	void Notify(TNotifyUI& msg);

	LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnNcActivate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnNcCalcSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnNcPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnNcHitTest(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnSysCommand(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnDPIChanged(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
	BOOL CTBCIAMessageBox::IsInStaticControl(CControlUI *pControl);

	void       SetSkinXMLPath( LPCTSTR path );
	LPCTSTR GetSkinXMLPath();

	CPaintManagerUI& GetPaintManager();
	void SaveToControlCallbackMap( CDuiString ctlName, int callback ) 
	{ 
		m_controlCallbackMap[ctlName] = callback; 
	}
	
private:
	CPaintManagerUI              m_pm;
	TCHAR                               m_skinXMLPath[MAX_PATH];
	std::map<CDuiString, int> m_controlCallbackMap;

};

} // namespace DuiLib
#endif