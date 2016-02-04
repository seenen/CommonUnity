#include <windows.h>
#include "CActiveXContainer.h"
#include "CEventSink.h"

CEventSink::CEventSink(IID iid)
{
	m_cRef = 1;
	m_iid = iid;
}

STDMETHODIMP CEventSink::QueryInterface(REFIID riid, void **ppvObject)
{
	*ppvObject = NULL;

	if (IsEqualIID(riid, IID_IUnknown) || IsEqualIID(riid, IID_IDispatch) || IsEqualIID(riid, m_iid))
		*ppvObject = static_cast<IDispatch *>(this);
	else
		return E_NOINTERFACE;

	AddRef();
	
	return S_OK;
}

STDMETHODIMP_(ULONG) CEventSink::AddRef()
{
	return InterlockedIncrement(&m_cRef);
}

STDMETHODIMP_(ULONG) CEventSink::Release()
{
	if (InterlockedDecrement(&m_cRef) == 0) {	
		delete this;
		return 0;
	}

	return m_cRef;
}

STDMETHODIMP CEventSink::GetTypeInfoCount(UINT *pctinfo)
{
	*pctinfo = 0;
	
	return S_OK;
}

STDMETHODIMP CEventSink::GetTypeInfo(UINT iTInfo, LCID lcid, ITypeInfo **ppTInfo)
{
	return E_NOTIMPL;
}

STDMETHODIMP CEventSink::GetIDsOfNames(REFIID riid, LPOLESTR *rgszNames, UINT cNames, LCID lcid, DISPID *rgDispId)
{
	return E_NOTIMPL;
}

STDMETHODIMP CEventSink::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS *pDispParams, VARIANT *pVarResult, EXCEPINFO *pExcepInfo, UINT *puArgErr)
{
	if (dispIdMember == DISPID_READYSTATECHANGE) { // void ReadyStateChange(long readyState);

	}
	else if (dispIdMember == DISPID_ONEXTERNALCALL) { // HRESULT OnExternalCall(BSTR value);

	}
	else {
		/*
		TCHAR szBuf[256];
		wsprintf(szBuf, TEXT("%d"), dispIdMember);
		MessageBox(NULL, szBuf, TEXT("CEventSink::Invoke"), MB_OK);
		*/
	}

	return S_OK;
}