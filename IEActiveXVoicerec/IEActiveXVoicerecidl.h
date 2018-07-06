

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0620 */
/* at Tue Jan 19 06:14:07 2038
 */
/* Compiler settings for IEActiveXVoicerec.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0620 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */


#ifndef __IEActiveXVoicerecidl_h__
#define __IEActiveXVoicerecidl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef ___DIEActiveXVoicerec_FWD_DEFINED__
#define ___DIEActiveXVoicerec_FWD_DEFINED__
typedef interface _DIEActiveXVoicerec _DIEActiveXVoicerec;

#endif 	/* ___DIEActiveXVoicerec_FWD_DEFINED__ */


#ifndef ___DIEActiveXVoicerecEvents_FWD_DEFINED__
#define ___DIEActiveXVoicerecEvents_FWD_DEFINED__
typedef interface _DIEActiveXVoicerecEvents _DIEActiveXVoicerecEvents;

#endif 	/* ___DIEActiveXVoicerecEvents_FWD_DEFINED__ */


#ifndef __IEActiveXVoicerec_FWD_DEFINED__
#define __IEActiveXVoicerec_FWD_DEFINED__

#ifdef __cplusplus
typedef class IEActiveXVoicerec IEActiveXVoicerec;
#else
typedef struct IEActiveXVoicerec IEActiveXVoicerec;
#endif /* __cplusplus */

#endif 	/* __IEActiveXVoicerec_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_IEActiveXVoicerec_0000_0000 */
/* [local] */ 

#pragma warning(push)
#pragma warning(disable:4001) 
#pragma once
#pragma warning(push)
#pragma warning(disable:4001) 
#pragma once
#pragma warning(pop)
#pragma warning(pop)
#pragma region Desktop Family
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_IEActiveXVoicerec_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IEActiveXVoicerec_0000_0000_v0_0_s_ifspec;


#ifndef __IEActiveXVoicerecLib_LIBRARY_DEFINED__
#define __IEActiveXVoicerecLib_LIBRARY_DEFINED__

/* library IEActiveXVoicerecLib */
/* [control][version][uuid] */ 


EXTERN_C const IID LIBID_IEActiveXVoicerecLib;

#ifndef ___DIEActiveXVoicerec_DISPINTERFACE_DEFINED__
#define ___DIEActiveXVoicerec_DISPINTERFACE_DEFINED__

/* dispinterface _DIEActiveXVoicerec */
/* [uuid] */ 


EXTERN_C const IID DIID__DIEActiveXVoicerec;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("4e9894d3-9f1b-481d-83ec-a095ff6848b7")
    _DIEActiveXVoicerec : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DIEActiveXVoicerecVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DIEActiveXVoicerec * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DIEActiveXVoicerec * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DIEActiveXVoicerec * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DIEActiveXVoicerec * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DIEActiveXVoicerec * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DIEActiveXVoicerec * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DIEActiveXVoicerec * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _DIEActiveXVoicerecVtbl;

    interface _DIEActiveXVoicerec
    {
        CONST_VTBL struct _DIEActiveXVoicerecVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DIEActiveXVoicerec_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DIEActiveXVoicerec_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DIEActiveXVoicerec_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DIEActiveXVoicerec_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DIEActiveXVoicerec_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DIEActiveXVoicerec_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DIEActiveXVoicerec_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DIEActiveXVoicerec_DISPINTERFACE_DEFINED__ */


#ifndef ___DIEActiveXVoicerecEvents_DISPINTERFACE_DEFINED__
#define ___DIEActiveXVoicerecEvents_DISPINTERFACE_DEFINED__

/* dispinterface _DIEActiveXVoicerecEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__DIEActiveXVoicerecEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("3bb1bd89-dd24-4a48-928d-67416811fbc5")
    _DIEActiveXVoicerecEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DIEActiveXVoicerecEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DIEActiveXVoicerecEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DIEActiveXVoicerecEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DIEActiveXVoicerecEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DIEActiveXVoicerecEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DIEActiveXVoicerecEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DIEActiveXVoicerecEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DIEActiveXVoicerecEvents * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _DIEActiveXVoicerecEventsVtbl;

    interface _DIEActiveXVoicerecEvents
    {
        CONST_VTBL struct _DIEActiveXVoicerecEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DIEActiveXVoicerecEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DIEActiveXVoicerecEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DIEActiveXVoicerecEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DIEActiveXVoicerecEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DIEActiveXVoicerecEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DIEActiveXVoicerecEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DIEActiveXVoicerecEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DIEActiveXVoicerecEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_IEActiveXVoicerec;

#ifdef __cplusplus

class DECLSPEC_UUID("75943fab-f874-4a9d-a482-654034ae1928")
IEActiveXVoicerec;
#endif
#endif /* __IEActiveXVoicerecLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


