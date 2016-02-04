#pragma comment(lib, "comsuppw.lib")

#include <comutil.h>
#include "CActiveXContainer.h"
#include "CEventSink.h"

CActiveXContainer::CActiveXContainer()
{
	m_cRef = 1;
	m_hwnd = NULL;
	m_dwEventCookie = 0;
	m_dwMiscStatus = 0;
	m_pEventSink = NULL;
	m_pOleObject = NULL;
	m_pConnectionPoint = NULL;
	disableFullscreen = "false";
	disableContextMenu = "false";
	src = "";
}

CActiveXContainer::~CActiveXContainer()
{
}

STDMETHODIMP CActiveXContainer::QueryInterface(REFIID riid, void **ppvObject)
{
	*ppvObject = NULL;
	
	if (IsEqualIID(riid, IID_IUnknown) || IsEqualIID(riid, IID_IOleClientSite))
		*ppvObject = static_cast<IOleClientSite *>(this);
	else if (IsEqualIID(riid, IID_IOleWindow) || IsEqualIID(riid, IID_IOleInPlaceSite))
		*ppvObject = static_cast<IOleInPlaceSite *>(this);
	else if (IsEqualIID(riid, IID_IOleControlSite))
		*ppvObject = static_cast<IOleControlSite *>(this);
	else if (IsEqualIID(riid, IID_IDispatch))
		*ppvObject = static_cast<IDispatch *>(this);
	else if (IsEqualIID(riid, IID_IUnknown) || IsEqualIID(riid, IID_IPropertyBag))
		*ppvObject = static_cast<IPropertyBag *>(this);
	else
		return E_NOINTERFACE;

	AddRef();
	
	return S_OK;
}

STDMETHODIMP_(ULONG) CActiveXContainer::AddRef()
{
	return InterlockedIncrement(&m_cRef);
}

STDMETHODIMP_(ULONG) CActiveXContainer::Release()
{
	if (InterlockedDecrement(&m_cRef) == 0) {
		delete this;
		return 0;
	}

	return m_cRef;
}

STDMETHODIMP CActiveXContainer::SaveObject()
{
	return E_NOTIMPL;
}

STDMETHODIMP CActiveXContainer::GetMoniker(DWORD dwAssign, DWORD dwWhichMoniker, IMoniker **ppmk)
{
	return E_NOTIMPL;
}

STDMETHODIMP CActiveXContainer::GetContainer(IOleContainer **ppContainer)
{
	*ppContainer = NULL;

	return E_NOINTERFACE;
}

STDMETHODIMP CActiveXContainer::ShowObject()
{
	return S_OK;
}

STDMETHODIMP CActiveXContainer::OnShowWindow(BOOL fShow)
{
	return S_OK;
}

STDMETHODIMP CActiveXContainer::RequestNewObjectLayout()
{
	return E_NOTIMPL;
}

STDMETHODIMP CActiveXContainer::GetWindow(HWND *phwnd)
{
	*phwnd = m_hwnd;

	return S_OK;
}

STDMETHODIMP CActiveXContainer::ContextSensitiveHelp(BOOL fEnterMode)
{
	return E_NOTIMPL;
}

STDMETHODIMP CActiveXContainer::CanInPlaceActivate()
{
	return S_OK;
}

STDMETHODIMP CActiveXContainer::OnInPlaceActivate()
{
	return S_OK;
}

STDMETHODIMP CActiveXContainer::OnUIActivate()
{
	return S_OK;
}

STDMETHODIMP CActiveXContainer::GetWindowContext(IOleInPlaceFrame **ppFrame, IOleInPlaceUIWindow **ppDoc, LPRECT lprcPosRect, LPRECT lprcClipRect, LPOLEINPLACEFRAMEINFO lpFrameInfo)
{
	*ppFrame = NULL;
	*ppDoc = NULL;
	
	GetClientRect(m_hwnd, lprcPosRect);
	GetClientRect(m_hwnd, lprcClipRect);

	return S_OK;
}

STDMETHODIMP CActiveXContainer::Scroll(SIZE scrollExtant)
{
	return E_NOTIMPL;
}

STDMETHODIMP CActiveXContainer::OnUIDeactivate(BOOL fUndoable)
{
	return E_NOTIMPL;
}

STDMETHODIMP CActiveXContainer::OnInPlaceDeactivate()
{
	return E_NOTIMPL;
}

STDMETHODIMP CActiveXContainer::DiscardUndoState()
{
	return E_NOTIMPL;
}

STDMETHODIMP CActiveXContainer::DeactivateAndUndo()
{
	return E_NOTIMPL;
}

STDMETHODIMP CActiveXContainer::OnPosRectChange(LPCRECT lprcPosRect)
{
	return S_OK;
}

STDMETHODIMP CActiveXContainer::OnControlInfoChanged()
{
	return E_NOTIMPL;
}

STDMETHODIMP CActiveXContainer::LockInPlaceActive(BOOL fLock)
{
	return E_NOTIMPL;
}

STDMETHODIMP CActiveXContainer::GetExtendedControl(IDispatch **ppDisp)
{
	*ppDisp = NULL;
	
	return E_NOINTERFACE;
}

STDMETHODIMP CActiveXContainer::TransformCoords(POINTL *pPtlHimetric, POINTF *pPtfContainer, DWORD dwFlags)
{
	return E_NOTIMPL;
}

STDMETHODIMP CActiveXContainer::TranslateAccelerator(MSG *pMsg, DWORD grfModifiers)
{
	return E_NOTIMPL;
}

STDMETHODIMP CActiveXContainer::OnFocus(BOOL fGotFocus)
{
	return S_OK;
}

STDMETHODIMP CActiveXContainer::ShowPropertyFrame()
{
	return E_NOTIMPL;
}

STDMETHODIMP CActiveXContainer::GetTypeInfoCount(UINT *pctinfo)
{
	*pctinfo = 0;
	
	return S_OK;
}

STDMETHODIMP CActiveXContainer::GetTypeInfo(UINT iTInfo, LCID lcid, ITypeInfo **ppTInfo)
{
	return E_NOTIMPL;
}

STDMETHODIMP CActiveXContainer::GetIDsOfNames(REFIID riid, LPOLESTR *rgszNames, UINT cNames, LCID lcid, DISPID *rgDispId)
{
	return E_NOTIMPL;
}

STDMETHODIMP CActiveXContainer::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS *pDispParams, VARIANT *pVarResult, EXCEPINFO *pExcepInfo, UINT *puArgErr)
{
	if (dispIdMember == DISPID_AMBIENT_LOCALEID) {
		pVarResult->vt = VT_I4;
		pVarResult->lVal = (SHORT)GetThreadLocale();
	}
	else if (dispIdMember == DISPID_AMBIENT_USERMODE) {
		pVarResult->vt = VT_BOOL;
		pVarResult->boolVal = VARIANT_TRUE;	
	}
	else if (dispIdMember == DISPID_AMBIENT_DISPLAYASDEFAULT) {
		pVarResult->vt = VT_BOOL;
		pVarResult->boolVal = VARIANT_FALSE;	
	}
	else
		return DISP_E_MEMBERNOTFOUND;

	return S_OK;
}

STDMETHODIMP CActiveXContainer::Read(LPCOLESTR pszPropName, VARIANT *pVar, IErrorLog *pErrorLog)
{
	if (lstrcmpW(pszPropName, L"disableFullscreen") == 0) {
		_variant_t val = _bstr_t(disableFullscreen);
		VariantCopy(pVar, &val);
	}
	else if (lstrcmpW(pszPropName, L"disableContextMenu") == 0) {
		_variant_t val = _bstr_t(disableContextMenu);
		VariantCopy(pVar, &val);
	}
	else if (lstrcmpW(pszPropName, L"src") == 0) {
		_variant_t val = _bstr_t(src);
		VariantCopy(pVar, &val);
		setSrc(pVar);
	}
	else
		return E_FAIL;

	return S_OK;
}

STDMETHODIMP CActiveXContainer::Write(LPCOLESTR pszPropName, VARIANT *pVar)
{
	return E_NOTIMPL;
}

BOOL CActiveXContainer::Create(HWND hwnd)
{
	RECT            rc;
	HRESULT         hr;
	BOOL            bQuickActivate;
	IRunnableObject *pRunnableObject;

	m_hwnd = hwnd;
	hr = CoCreateInstance(CLSID_UnityWebPlayerAx, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&m_pOleObject));
	if (FAILED(hr))
		return FALSE;
	
	m_pEventSink = new CEventSink(IID_IUnityWebPlayerAxEvents);
	
	bQuickActivate = QuickActivate();

	if (!bQuickActivate) {
		m_pOleObject->GetMiscStatus(DVASPECT_CONTENT, &m_dwMiscStatus);
		if (m_dwMiscStatus & OLEMISC_SETCLIENTSITEFIRST)
			m_pOleObject->SetClientSite(static_cast<IOleClientSite *>(this));
	}

	InitNew();

	if (!bQuickActivate) {
		if (!(m_dwMiscStatus & OLEMISC_SETCLIENTSITEFIRST))
			m_pOleObject->SetClientSite(static_cast<IOleClientSite *>(this));
		SetEventSink();
	}
	
	if (m_dwMiscStatus & OLEMISC_ALWAYSRUN) {
		m_pOleObject->QueryInterface(IID_PPV_ARGS(&pRunnableObject));
		if (pRunnableObject != NULL) {
			pRunnableObject->Run(NULL);
			pRunnableObject->Release();
		}
	}

	SetRectEmpty(&rc);
	hr = m_pOleObject->DoVerb(OLEIVERB_INPLACEACTIVATE, NULL, static_cast<IOleClientSite *>(this), 0, m_hwnd, &rc);

	if (FAILED(hr))
		return FALSE;

	return TRUE;
}

void CActiveXContainer::Destroy()
{
	if (m_pConnectionPoint != NULL) {
		m_pConnectionPoint->Unadvise(m_dwEventCookie);
		m_pConnectionPoint->Release();
	}
		
	if (m_pEventSink != NULL) {
		m_pEventSink->Release();
	}
		
	if (m_pOleObject != NULL) {
		RECT rc;
		SetRectEmpty(&rc);
		m_pOleObject->DoVerb(OLEIVERB_HIDE, NULL, NULL, 0, m_hwnd, &rc);
		m_pOleObject->Close(OLECLOSE_NOSAVE);
		m_pOleObject->SetClientSite(NULL);
		m_pOleObject->Release();
	}
}

BOOL CActiveXContainer::InitNew()
{
	BOOL                bResult = TRUE;
	IPersistStreamInit  *pPersistStreamInit;
	IPersistStorage     *pPersistStorage;
	IPersistMemory      *pPersistMemory;
	IPersistPropertyBag* pPPBag;

	if (m_pOleObject->QueryInterface(IID_PPV_ARGS(&pPersistStreamInit)) == S_OK) {
		pPersistStreamInit->InitNew();
		pPersistStreamInit->Release();
	}
	if (m_pOleObject->QueryInterface(IID_PPV_ARGS(&pPersistStorage)) == S_OK) {
		pPersistStorage->InitNew(NULL);
		pPersistStorage->Release();
	}
	if (m_pOleObject->QueryInterface(IID_PPV_ARGS(&pPersistMemory)) == S_OK) {
		pPersistMemory->InitNew();
		pPersistMemory->Release();
	}
	if (m_pOleObject->QueryInterface(IID_IPersistPropertyBag, (void**)&pPPBag) == S_OK) {
		pPPBag->Load(this, NULL);
		pPPBag->Release();
	}

	return bResult;
}

BOOL CActiveXContainer::QuickActivate()
{
	HRESULT        hr;
	QACONTAINER    qaContainer;
	QACONTROL      qaControl;
	IQuickActivate *pQuickActivate;

	hr = m_pOleObject->QueryInterface(IID_PPV_ARGS(&pQuickActivate));
	if (FAILED(hr))
		return FALSE;

	ZeroMemory(&qaContainer, sizeof(QACONTAINER));
	qaContainer.cbSize        = sizeof(QACONTAINER);
	qaContainer.pClientSite   = static_cast<IOleClientSite *>(this);
	qaContainer.pUnkEventSink = m_pEventSink;
	
	qaControl.cbSize = sizeof(QACONTROL);

	hr = pQuickActivate->QuickActivate(&qaContainer, &qaControl);
	if (FAILED(hr)) {
		pQuickActivate->Release();
		return FALSE;
	}
	
	m_dwMiscStatus = qaControl.dwMiscStatus;
	m_dwEventCookie = qaControl.dwEventCookie;

	pQuickActivate->Release();

	return TRUE;
}

BOOL CActiveXContainer::SetEventSink()
{
	IConnectionPointContainer *pConnectionPointContainer;
	IConnectionPoint          *pConnectionPoint;
	HRESULT                   hr;
	
	hr = m_pOleObject->QueryInterface(IID_PPV_ARGS(&pConnectionPointContainer));
	if (FAILED(hr))	
		return FALSE;

	hr = pConnectionPointContainer->FindConnectionPoint(IID_IUnityWebPlayerAxEvents, &pConnectionPoint);
	pConnectionPointContainer->Release();
	if (FAILED(hr))	
		return FALSE;

	hr = pConnectionPoint->Advise(m_pEventSink, &m_dwEventCookie);
	m_pConnectionPoint = pConnectionPoint;
	
	return TRUE;
}

HRESULT CActiveXContainer::setSrc(VARIANT *pVar)
{
	HRESULT   hr;
	IDispatch *pDispatch;
	
	m_pOleObject->QueryInterface(IID_PPV_ARGS(&pDispatch));

	hr = Invoke(pDispatch, L"src", DISPATCH_PROPERTYPUT, pVar, 1, NULL);
	pDispatch->Release();

	return hr;
}

HRESULT CActiveXContainer::Invoke(IDispatch *pDispatch, LPOLESTR lpszName, WORD wFlags, VARIANT *pVarArray, int nArgs, VARIANT *pVarResult)
{
	DISPPARAMS dispParams;
	DISPID     dispid;
	DISPID     dispidName = DISPID_PROPERTYPUT;
	HRESULT    hr;
	
	hr = pDispatch->GetIDsOfNames(IID_NULL, &lpszName, 1, LOCALE_USER_DEFAULT, &dispid);
	if (FAILED(hr))
		return hr;
	
	dispParams.cArgs = nArgs;
	dispParams.rgvarg = pVarArray;
	if (wFlags & DISPATCH_PROPERTYPUT) {
		dispParams.cNamedArgs = 1;
		dispParams.rgdispidNamedArgs = &dispidName;
	}
	else {
		dispParams.cNamedArgs = 0;
		dispParams.rgdispidNamedArgs = NULL;
	}

	hr = pDispatch->Invoke(dispid, IID_NULL, LOCALE_SYSTEM_DEFAULT, wFlags, &dispParams, pVarResult, NULL, NULL);

	return hr;
}
