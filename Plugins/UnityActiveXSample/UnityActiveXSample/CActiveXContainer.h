#pragma once

#include <windows.h>
#include <olectl.h>

const CLSID CLSID_UnityWebPlayerAx		= {0x444785F1, 0xDE89, 0x4295, {0x86, 0x3A, 0xD4, 0x6C, 0x3A, 0x78, 0x13, 0x94}};
const IID IID_IUnityWebPlayerAxEvents	= {0xD10F4BFD, 0xC3ED, 0x44B7, {0xBD, 0x0D, 0x83, 0xF0, 0x5E, 0x4D, 0x52, 0xD5}};

class CActiveXContainer : public IOleClientSite, public IOleInPlaceSite, public IOleControlSite, public IDispatch, public IPropertyBag
{
public:
	STDMETHODIMP QueryInterface(REFIID riid, void **ppvObject);
	STDMETHODIMP_(ULONG) AddRef();
	STDMETHODIMP_(ULONG) Release();
	
	STDMETHODIMP SaveObject();
	STDMETHODIMP GetMoniker(DWORD dwAssign, DWORD dwWhichMoniker, IMoniker **ppmk);
	STDMETHODIMP GetContainer(IOleContainer **ppContainer);
	STDMETHODIMP ShowObject();
	STDMETHODIMP OnShowWindow(BOOL fShow);
	STDMETHODIMP RequestNewObjectLayout();
	
	STDMETHODIMP GetWindow(HWND *phwnd);
	STDMETHODIMP ContextSensitiveHelp(BOOL fEnterMode);
	STDMETHODIMP CanInPlaceActivate();
	STDMETHODIMP OnInPlaceActivate();
	STDMETHODIMP OnUIActivate();
	STDMETHODIMP GetWindowContext(IOleInPlaceFrame **ppFrame, IOleInPlaceUIWindow **ppDoc, LPRECT lprcPosRect, LPRECT lprcClipRect, LPOLEINPLACEFRAMEINFO lpFrameInfo);
	STDMETHODIMP Scroll(SIZE scrollExtant);
	STDMETHODIMP OnUIDeactivate(BOOL fUndoable);
	STDMETHODIMP OnInPlaceDeactivate();
	STDMETHODIMP DiscardUndoState();
	STDMETHODIMP DeactivateAndUndo();
	STDMETHODIMP OnPosRectChange(LPCRECT lprcPosRect);
	
	STDMETHODIMP OnControlInfoChanged();
	STDMETHODIMP LockInPlaceActive(BOOL fLock);
	STDMETHODIMP GetExtendedControl(IDispatch **ppDisp);
	STDMETHODIMP TransformCoords(POINTL *pPtlHimetric, POINTF *pPtfContainer, DWORD dwFlags);
	STDMETHODIMP TranslateAccelerator(MSG *pMsg, DWORD grfModifiers);
	STDMETHODIMP OnFocus(BOOL fGotFocus);
	STDMETHODIMP ShowPropertyFrame();
	
	STDMETHODIMP GetTypeInfoCount(UINT *pctinfo);
	STDMETHODIMP GetTypeInfo(UINT iTInfo, LCID lcid, ITypeInfo **ppTInfo);
	STDMETHODIMP GetIDsOfNames(REFIID riid, LPOLESTR *rgszNames, UINT cNames, LCID lcid, DISPID *rgDispId);
	STDMETHODIMP Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS *pDispParams, VARIANT *pVarResult, EXCEPINFO *pExcepInfo, UINT *puArgErr);

	STDMETHODIMP Read(LPCOLESTR pszPropName, VARIANT *pVar, IErrorLog *pErrorLog);
	STDMETHODIMP Write(LPCOLESTR pszPropName, VARIANT *pVar);

	CActiveXContainer();
	~CActiveXContainer();

	BOOL Create(HWND hwnd);
	void Destroy();
	BOOL InitNew();
	BOOL QuickActivate();
	BOOL SetEventSink();
	HRESULT setSrc(VARIANT *pVar);
	HRESULT Invoke(IDispatch *pDispatch, LPOLESTR lpszName, WORD wFlags, VARIANT *pVarArray, int nArgs, VARIANT *pVarResult);
	char *disableFullscreen;
	char *disableContextMenu;
	char *src;

protected:
	LONG             m_cRef;
	HWND             m_hwnd;
	DWORD            m_dwEventCookie;
	DWORD            m_dwMiscStatus;
	IOleObject       *m_pOleObject;
	IDispatch        *m_pEventSink;
	IConnectionPoint *m_pConnectionPoint;
};