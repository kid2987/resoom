#include "msdxm.h"

static void CVIFUNC _MediaPlayerEventsRegOnDVDNotify_EventVTableFunc (void *thisPtr,
                                                                      long eventCode,
                                                                      long eventParam1,
                                                                      long eventParam2);

static void CVIFUNC _MediaPlayerEventsRegOnEndOfStream_EventVTableFunc (void *thisPtr,
                                                                        long result);

static void CVIFUNC _MediaPlayerEventsRegOnKeyDown_EventVTableFunc (void *thisPtr,
                                                                    short keyCode,
                                                                    short shiftState);

static void CVIFUNC _MediaPlayerEventsRegOnKeyUp_EventVTableFunc (void *thisPtr,
                                                                  short keyCode,
                                                                  short shiftState);

static void CVIFUNC _MediaPlayerEventsRegOnKeyPress_EventVTableFunc (void *thisPtr,
                                                                     short characterCode);

static void CVIFUNC _MediaPlayerEventsRegOnMouseMove_EventVTableFunc (void *thisPtr,
                                                                      short button,
                                                                      short shiftState,
                                                                      long x,
                                                                      long y);

static void CVIFUNC _MediaPlayerEventsRegOnMouseDown_EventVTableFunc (void *thisPtr,
                                                                      short button,
                                                                      short shiftState,
                                                                      long x,
                                                                      long y);

static void CVIFUNC _MediaPlayerEventsRegOnMouseUp_EventVTableFunc (void *thisPtr,
                                                                    short button,
                                                                    short shiftState,
                                                                    long x,
                                                                    long y);

static void CVIFUNC _MediaPlayerEventsRegOnClick_EventVTableFunc (void *thisPtr,
                                                                  short button,
                                                                  short shiftState,
                                                                  long x, long y);

static void CVIFUNC _MediaPlayerEventsRegOnDblClick_EventVTableFunc (void *thisPtr,
                                                                     short button,
                                                                     short shiftState,
                                                                     long x,
                                                                     long y);

static void CVIFUNC _MediaPlayerEventsRegOnOpenStateChange_EventVTableFunc (void *thisPtr,
                                                                            long oldState,
                                                                            long newState);

static void CVIFUNC _MediaPlayerEventsRegOnPlayStateChange_EventVTableFunc (void *thisPtr,
                                                                            long oldState,
                                                                            long newState);

static void CVIFUNC _MediaPlayerEventsRegOnScriptCommand_EventVTableFunc (void *thisPtr,
                                                                          BSTR scType,
                                                                          BSTR param);

static void CVIFUNC _MediaPlayerEventsRegOnBuffering_EventVTableFunc (void *thisPtr,
                                                                      VBOOL start);

static void CVIFUNC _MediaPlayerEventsRegOnError_EventVTableFunc (void *thisPtr);

static void CVIFUNC _MediaPlayerEventsRegOnMarkerHit_EventVTableFunc (void *thisPtr,
                                                                      long markerNum);

static void CVIFUNC _MediaPlayerEventsRegOnWarning_EventVTableFunc (void *thisPtr,
                                                                    long warningType,
                                                                    long param,
                                                                    BSTR description);

static void CVIFUNC _MediaPlayerEventsRegOnNewStream_EventVTableFunc (void *thisPtr);

static void CVIFUNC _MediaPlayerEventsRegOnDisconnect_EventVTableFunc (void *thisPtr,
                                                                       long result);

static void CVIFUNC _MediaPlayerEventsRegOnPositionChange_EventVTableFunc (void *thisPtr,
                                                                           double oldPosition,
                                                                           double newPosition);

static void CVIFUNC _MediaPlayerEventsRegOnDisplayModeChange_EventVTableFunc (void *thisPtr);

static void CVIFUNC _MediaPlayerEventsRegOnReadyStateChange_EventVTableFunc (void *thisPtr,
                                                                             long readyState);

static long CVIFUNC _IRadioPlayerEventsRegOnStateChange_EventVTableFunc (void *thisPtr,
                                                                         BSTR bszUrl,
                                                                         VBOOL fPlay,
                                                                         long lVolume,
                                                                         VBOOL fMute);

typedef interface tagMediaPlayer_IDirectControl_Interface MediaPlayer_IDirectControl_Interface;

typedef struct tagMediaPlayer_IDirectControl_VTable
{
	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( MediaPlayer_IDirectControl_Interface __RPC_FAR * This, 
	                                                         REFIID riid, 
	                                                         void __RPC_FAR *__RPC_FAR *ppvObject);

	ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( MediaPlayer_IDirectControl_Interface __RPC_FAR * This);

	ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( MediaPlayer_IDirectControl_Interface __RPC_FAR * This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( MediaPlayer_IDirectControl_Interface __RPC_FAR * This, 
	                                                           UINT __RPC_FAR *pctinfo);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( MediaPlayer_IDirectControl_Interface __RPC_FAR * This, 
	                                                      UINT iTInfo, 
	                                                      LCID lcid, 
	                                                      ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( MediaPlayer_IDirectControl_Interface __RPC_FAR * This, 
	                                                        REFIID riid, 
	                                                        LPOLESTR __RPC_FAR *rgszNames, 
	                                                        UINT cNames, 
	                                                        LCID lcid, 
	                                                        DISPID __RPC_FAR *rgDispId);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( MediaPlayer_IDirectControl_Interface __RPC_FAR * This, 
	                                                 DISPID dispIdMember, 
	                                                 REFIID riid, 
	                                                 LCID lcid, 
	                                                 WORD wFlags, 
	                                                 DISPPARAMS __RPC_FAR *pDispParams, 
	                                                 VARIANT __RPC_FAR *pVarResult, 
	                                                 EXCEPINFO __RPC_FAR *pExcepInfo, 
	                                                 UINT __RPC_FAR *puArgErr);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateView_) (MediaPlayer_IDirectControl_Interface __RPC_FAR *This, 
	                                                     BSTR bszClsid);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DestroyAllViews_) (MediaPlayer_IDirectControl_Interface __RPC_FAR *This);

} MediaPlayer_IDirectControl_VTable;

typedef interface tagMediaPlayer_IDirectControl_Interface
{
	CONST_VTBL MediaPlayer_IDirectControl_VTable __RPC_FAR *lpVtbl;
} MediaPlayer_IDirectControl_Interface;

typedef interface tagMediaPlayer_IDirectContainer_Interface MediaPlayer_IDirectContainer_Interface;

typedef struct tagMediaPlayer_IDirectContainer_VTable
{
	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( MediaPlayer_IDirectContainer_Interface __RPC_FAR * This, 
	                                                         REFIID riid, 
	                                                         void __RPC_FAR *__RPC_FAR *ppvObject);

	ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( MediaPlayer_IDirectContainer_Interface __RPC_FAR * This);

	ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( MediaPlayer_IDirectContainer_Interface __RPC_FAR * This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateControl_) (MediaPlayer_IDirectContainer_Interface __RPC_FAR *This, 
	                                                        BSTR bszClsid, 
	                                                        unsigned long dwClsContext, 
	                                                        LPUNKNOWN *ppunk, 
	                                                        unsigned long dwWindowStyle);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetServiceProvider_) (MediaPlayer_IDirectContainer_Interface __RPC_FAR *This, 
	                                                             LPUNKNOWN pspSet);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetIInputObjectSite_) (MediaPlayer_IDirectContainer_Interface __RPC_FAR *This, 
	                                                              LPUNKNOWN pios);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ShowControl_) (MediaPlayer_IDirectContainer_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *HideControl_) (MediaPlayer_IDirectContainer_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *IsControlCreated_) (MediaPlayer_IDirectContainer_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DestroyControl_) (MediaPlayer_IDirectContainer_Interface __RPC_FAR *This);

} MediaPlayer_IDirectContainer_VTable;

typedef interface tagMediaPlayer_IDirectContainer_Interface
{
	CONST_VTBL MediaPlayer_IDirectContainer_VTable __RPC_FAR *lpVtbl;
} MediaPlayer_IDirectContainer_Interface;

typedef interface tagMediaPlayer_IMediaPlayer2_Interface MediaPlayer_IMediaPlayer2_Interface;

typedef struct tagMediaPlayer_IMediaPlayer2_VTable
{
	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( MediaPlayer_IMediaPlayer2_Interface __RPC_FAR * This, 
	                                                         REFIID riid, 
	                                                         void __RPC_FAR *__RPC_FAR *ppvObject);

	ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( MediaPlayer_IMediaPlayer2_Interface __RPC_FAR * This);

	ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( MediaPlayer_IMediaPlayer2_Interface __RPC_FAR * This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( MediaPlayer_IMediaPlayer2_Interface __RPC_FAR * This, 
	                                                           UINT __RPC_FAR *pctinfo);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( MediaPlayer_IMediaPlayer2_Interface __RPC_FAR * This, 
	                                                      UINT iTInfo, 
	                                                      LCID lcid, 
	                                                      ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( MediaPlayer_IMediaPlayer2_Interface __RPC_FAR * This, 
	                                                        REFIID riid, 
	                                                        LPOLESTR __RPC_FAR *rgszNames, 
	                                                        UINT cNames, 
	                                                        LCID lcid, 
	                                                        DISPID __RPC_FAR *rgDispId);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( MediaPlayer_IMediaPlayer2_Interface __RPC_FAR * This, 
	                                                 DISPID dispIdMember, 
	                                                 REFIID riid, 
	                                                 LCID lcid, 
	                                                 WORD wFlags, 
	                                                 DISPPARAMS __RPC_FAR *pDispParams, 
	                                                 VARIANT __RPC_FAR *pVarResult, 
	                                                 EXCEPINFO __RPC_FAR *pExcepInfo, 
	                                                 UINT __RPC_FAR *puArgErr);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCurrentPosition_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                             double *pCurrentPosition);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCurrentPosition_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                             double pCurrentPosition);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDuration_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                      double *pDuration);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetImageSourceWidth_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                              long *pWidth);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetImageSourceHeight_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                               long *pHeight);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMarkerCount_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                         long *pMarkerCount);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCanScan_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                     VBOOL *pCanScan);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCanSeek_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                     VBOOL *pCanSeek);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCanSeekToMarkers_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                              VBOOL *pCanSeekToMarkers);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCurrentMarker_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                           long *pCurrentMarker);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCurrentMarker_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                           long pCurrentMarker);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFileName_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                      BSTR *pbstrFileName);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFileName_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                      BSTR pbstrFileName);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSourceLink_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                        BSTR *pbstrSourceLink);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCreationDate_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                          DATE *pCreationDate);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetErrorCorrection_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                             BSTR *pbstrErrorCorrection);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetBandwidth_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                       long *pBandwidth);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSourceProtocol_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                            long *pSourceProtocol);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetReceivedPackets_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                             long *pReceivedPackets);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRecoveredPackets_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                              long *pRecoveredPackets);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLostPackets_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                         long *pLostPackets);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetReceptionQuality_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                              long *pReceptionQuality);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetBufferingCount_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                            long *pBufferingCount);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIsBroadcast_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                         VBOOL *pIsBroadcast);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetBufferingProgress_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                               long *pBufferingProgress);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetChannelName_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                         BSTR *pbstrChannelName);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetChannelDescription_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                                BSTR *pbstrChannelDescription);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetChannelURL_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                        BSTR *pbstrChannelURL);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetContactAddress_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                            BSTR *pbstrContactAddress);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetContactPhone_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                          BSTR *pbstrContactPhone);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetContactEmail_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                          BSTR *pbstrContactEmail);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetBufferingTime_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                           double *pBufferingTime);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetBufferingTime_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                           double pBufferingTime);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAutoStart_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                       VBOOL *pAutoStart);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAutoStart_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                       VBOOL pAutoStart);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAutoRewind_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                        VBOOL *pAutoRewind);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAutoRewind_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                        VBOOL pAutoRewind);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRate_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                  double *pRate);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetRate_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                  double pRate);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSendKeyboardEvents_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                                VBOOL *pSendKeyboardEvents);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSendKeyboardEvents_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                                VBOOL pSendKeyboardEvents);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSendMouseClickEvents_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                                  VBOOL *pSendMouseClickEvents);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSendMouseClickEvents_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                                  VBOOL pSendMouseClickEvents);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSendMouseMoveEvents_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                                 VBOOL *pSendMouseMoveEvents);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSendMouseMoveEvents_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                                 VBOOL pSendMouseMoveEvents);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPlayCount_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                       long *pPlayCount);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPlayCount_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                       long pPlayCount);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClickToPlay_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                         VBOOL *pClickToPlay);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClickToPlay_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                         VBOOL pClickToPlay);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAllowScan_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                       VBOOL *pAllowScan);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAllowScan_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                       VBOOL pAllowScan);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnableContextMenu_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                               VBOOL *pEnableContextMenu);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetEnableContextMenu_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                               VBOOL pEnableContextMenu);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCursorType_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                        long *pCursorType);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCursorType_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                        long pCursorType);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCodecCount_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                        long *pCodecCount);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAllowChangeDisplaySize_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                                    VBOOL *pAllowChangeDisplaySize);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAllowChangeDisplaySize_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                                    VBOOL pAllowChangeDisplaySize);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIsDurationValid_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                             VBOOL *pIsDurationValid);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetOpenState_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                       long *pOpenState);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSendOpenStateChangeEvents_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                                       VBOOL *pSendOpenStateChangeEvents);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSendOpenStateChangeEvents_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                                       VBOOL pSendOpenStateChangeEvents);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSendWarningEvents_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                               VBOOL *pSendWarningEvents);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSendWarningEvents_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                               VBOOL pSendWarningEvents);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSendErrorEvents_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                             VBOOL *pSendErrorEvents);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSendErrorEvents_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                             VBOOL pSendErrorEvents);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPlayState_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                       long *pPlayState);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSendPlayStateChangeEvents_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                                       VBOOL *pSendPlayStateChangeEvents);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSendPlayStateChangeEvents_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                                       VBOOL pSendPlayStateChangeEvents);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDisplaySize_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                         long *pDisplaySize);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDisplaySize_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                         long pDisplaySize);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetInvokeURLs_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                        VBOOL *pInvokeURLs);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetInvokeURLs_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                        VBOOL pInvokeURLs);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetBaseURL_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                     BSTR *pbstrBaseURL);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetBaseURL_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                     BSTR pbstrBaseURL);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDefaultFrame_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                          BSTR *pbstrDefaultFrame);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDefaultFrame_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                          BSTR pbstrDefaultFrame);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetHasError_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                      VBOOL *pHasError);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetErrorDescription_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                              BSTR *pbstrErrorDescription);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetErrorCode_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                       long *pErrorCode);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAnimationAtStart_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                              VBOOL *pAnimationAtStart);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAnimationAtStart_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                              VBOOL pAnimationAtStart);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTransparentAtStart_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                                VBOOL *pTransparentAtStart);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetTransparentAtStart_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                                VBOOL pTransparentAtStart);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVolume_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                    long *pVolume);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetVolume_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                    long pVolume);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetBalance_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                     long *pBalance);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetBalance_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                     long pBalance);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetReadyState_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                        long *pValue);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSelectionStart_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                            double *pValue);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSelectionStart_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                            double pValue);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSelectionEnd_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                          double *pValue);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSelectionEnd_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                          double pValue);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetShowDisplay_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                         VBOOL *show);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetShowDisplay_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                         VBOOL show);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetShowControls_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                          VBOOL *show);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetShowControls_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                          VBOOL show);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetShowPositionControls_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                                  VBOOL *show);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetShowPositionControls_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                                  VBOOL show);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetShowTracker_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                         VBOOL *show);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetShowTracker_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                         VBOOL show);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnablePositionControls_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                                    VBOOL *enable);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetEnablePositionControls_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                                    VBOOL enable);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnableTracker_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                           VBOOL *enable);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetEnableTracker_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                           VBOOL enable);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnabled_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                     VBOOL *pEnabled);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetEnabled_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                     VBOOL pEnabled);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDisplayForeColor_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                              unsigned long *foreColor);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDisplayForeColor_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                              unsigned long foreColor);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDisplayBackColor_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                              unsigned long *backColor);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDisplayBackColor_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                              unsigned long backColor);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDisplayMode_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                         long *pValue);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDisplayMode_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                         long pValue);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVideoBorder3D_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                           VBOOL *pVideoBorderWidth);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetVideoBorder3D_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                           VBOOL pVideoBorderWidth);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVideoBorderWidth_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                              long *pVideoBorderWidth);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetVideoBorderWidth_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                              long pVideoBorderWidth);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVideoBorderColor_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                              unsigned long *pVideoBorderWidth);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetVideoBorderColor_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                              unsigned long pVideoBorderWidth);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetShowGotoBar_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                         VBOOL *pbool);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetShowGotoBar_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                         VBOOL pbool);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetShowStatusBar_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                           VBOOL *pbool);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetShowStatusBar_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                           VBOOL pbool);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetShowCaptioning_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                            VBOOL *pbool);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetShowCaptioning_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                            VBOOL pbool);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetShowAudioControls_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                               VBOOL *pbool);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetShowAudioControls_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                               VBOOL pbool);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCaptioningID_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                          BSTR *pstrText);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCaptioningID_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                          BSTR pstrText);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMute_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                  VBOOL *vbool);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMute_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                  VBOOL vbool);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCanPreview_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                        VBOOL *pCanPreview);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPreviewMode_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                         VBOOL *pPreviewMode);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPreviewMode_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                         VBOOL pPreviewMode);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetHasMultipleItems_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                              VBOOL *pHasMuliItems);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLanguage_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                      long *pLanguage);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLanguage_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                      long pLanguage);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAudioStream_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                         long *pStream);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAudioStream_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                         long pStream);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSAMIStyle_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                       BSTR *pbstrStyle);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSAMIStyle_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                       BSTR pbstrStyle);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSAMILang_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                      BSTR *pbstrLang);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSAMILang_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                      BSTR pbstrLang);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSAMIFileName_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                          BSTR *pbstrFileName);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSAMIFileName_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                          BSTR pbstrFileName);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetStreamCount_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                         long *pStreamCount);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClientId_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                      BSTR *pbstrClientId);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetConnectionSpeed_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                             long *plConnectionSpeed);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAutoSize_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                      VBOOL *pbool);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAutoSize_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                      VBOOL pbool);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnableFullScreenControls_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                                      VBOOL *pbVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetEnableFullScreenControls_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                                      VBOOL pbVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetActiveMovie_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                         LPDISPATCH *ppdispatch);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNSPlay_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                    LPDISPATCH *ppdispatch);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetWindowlessVideo_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                             VBOOL *pbool);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetWindowlessVideo_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                             VBOOL pbool);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Play_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Stop_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Pause_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMarkerTime_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                        long markerNum, 
	                                                        double *pMarkerTime);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMarkerName_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                        long markerNum, 
	                                                        BSTR *pbstrMarkerName);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AboutBox_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCodecInstalled_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                            long codecNum, 
	                                                            VBOOL *pCodecInstalled);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCodecDescription_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                              long codecNum, 
	                                                              BSTR *pbstrCodecDescription);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCodecURL_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                      long codecNum, 
	                                                      BSTR *pbstrCodecURL);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMoreInfoURL_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                         long moreInfoType, 
	                                                         BSTR *pbstrMoreInfoURL);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMediaInfoString_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                             long mediaInfoType, 
	                                                             BSTR *pbstrMediaInfo);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Cancel_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                               BSTR bstrFileName);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *IsSoundCardEnabled_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                             VBOOL *pbSoundCard);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Next_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Previous_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *StreamSelect_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                       long streamNum);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FastForward_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FastReverse_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetStreamName_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                        long streamNum, 
	                                                        BSTR *pbstrStreamName);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetStreamGroup_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                         long streamNum, 
	                                                         long *pStreamGroup);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetStreamSelected_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                            long streamNum, 
	                                                            VBOOL *pStreamSelected);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDVD_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                 LPDISPATCH *ppdispatch);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMediaParameter_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                            long entryNum, 
	                                                            BSTR bstrParameterName, 
	                                                            BSTR *pbstrParameterValue);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMediaParameterName_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                                long entryNum, 
	                                                                long index, 
	                                                                BSTR *pbstrParameterName);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEntryCount_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                        long *pNumberEntries);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCurrentEntry_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                          long *pEntryNumber);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCurrentEntry_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                          long entryNumber);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ShowDialog_) (MediaPlayer_IMediaPlayer2_Interface __RPC_FAR *This, 
	                                                     long mpDialogIndex);

} MediaPlayer_IMediaPlayer2_VTable;

typedef interface tagMediaPlayer_IMediaPlayer2_Interface
{
	CONST_VTBL MediaPlayer_IMediaPlayer2_VTable __RPC_FAR *lpVtbl;
} MediaPlayer_IMediaPlayer2_Interface;

typedef interface tagMediaPlayer_IMediaBindStream_Interface MediaPlayer_IMediaBindStream_Interface;

typedef struct tagMediaPlayer_IMediaBindStream_VTable
{
	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( MediaPlayer_IMediaBindStream_Interface __RPC_FAR * This, 
	                                                         REFIID riid, 
	                                                         void __RPC_FAR *__RPC_FAR *ppvObject);

	ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( MediaPlayer_IMediaBindStream_Interface __RPC_FAR * This);

	ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( MediaPlayer_IMediaBindStream_Interface __RPC_FAR * This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( MediaPlayer_IMediaBindStream_Interface __RPC_FAR * This, 
	                                                           UINT __RPC_FAR *pctinfo);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( MediaPlayer_IMediaBindStream_Interface __RPC_FAR * This, 
	                                                      UINT iTInfo, 
	                                                      LCID lcid, 
	                                                      ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( MediaPlayer_IMediaBindStream_Interface __RPC_FAR * This, 
	                                                        REFIID riid, 
	                                                        LPOLESTR __RPC_FAR *rgszNames, 
	                                                        UINT cNames, 
	                                                        LCID lcid, 
	                                                        DISPID __RPC_FAR *rgDispId);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( MediaPlayer_IMediaBindStream_Interface __RPC_FAR * This, 
	                                                 DISPID dispIdMember, 
	                                                 REFIID riid, 
	                                                 LCID lcid, 
	                                                 WORD wFlags, 
	                                                 DISPPARAMS __RPC_FAR *pDispParams, 
	                                                 VARIANT __RPC_FAR *pVarResult, 
	                                                 EXCEPINFO __RPC_FAR *pExcepInfo, 
	                                                 UINT __RPC_FAR *puArgErr);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadMoniker_) (MediaPlayer_IMediaBindStream_Interface __RPC_FAR *This, 
	                                                      BSTR bszTransferContext, 
	                                                      BSTR bszUrl);

} MediaPlayer_IMediaBindStream_VTable;

typedef interface tagMediaPlayer_IMediaBindStream_Interface
{
	CONST_VTBL MediaPlayer_IMediaBindStream_VTable __RPC_FAR *lpVtbl;
} MediaPlayer_IMediaBindStream_Interface;

typedef interface tagMediaPlayer_IRadioPlayer_Interface MediaPlayer_IRadioPlayer_Interface;

typedef struct tagMediaPlayer_IRadioPlayer_VTable
{
	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( MediaPlayer_IRadioPlayer_Interface __RPC_FAR * This, 
	                                                         REFIID riid, 
	                                                         void __RPC_FAR *__RPC_FAR *ppvObject);

	ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( MediaPlayer_IRadioPlayer_Interface __RPC_FAR * This);

	ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( MediaPlayer_IRadioPlayer_Interface __RPC_FAR * This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( MediaPlayer_IRadioPlayer_Interface __RPC_FAR * This, 
	                                                           UINT __RPC_FAR *pctinfo);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( MediaPlayer_IRadioPlayer_Interface __RPC_FAR * This, 
	                                                      UINT iTInfo, 
	                                                      LCID lcid, 
	                                                      ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( MediaPlayer_IRadioPlayer_Interface __RPC_FAR * This, 
	                                                        REFIID riid, 
	                                                        LPOLESTR __RPC_FAR *rgszNames, 
	                                                        UINT cNames, 
	                                                        LCID lcid, 
	                                                        DISPID __RPC_FAR *rgDispId);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( MediaPlayer_IRadioPlayer_Interface __RPC_FAR * This, 
	                                                 DISPID dispIdMember, 
	                                                 REFIID riid, 
	                                                 LCID lcid, 
	                                                 WORD wFlags, 
	                                                 DISPPARAMS __RPC_FAR *pDispParams, 
	                                                 VARIANT __RPC_FAR *pVarResult, 
	                                                 EXCEPINFO __RPC_FAR *pExcepInfo, 
	                                                 UINT __RPC_FAR *puArgErr);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BindRadioMemory_) (MediaPlayer_IRadioPlayer_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReleaseRadio_) (MediaPlayer_IRadioPlayer_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RegisterEvent_) (MediaPlayer_IRadioPlayer_Interface __RPC_FAR *This, 
	                                                        BSTR bszEvent, 
	                                                        long *plRegister);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RegisterWindow_) (MediaPlayer_IRadioPlayer_Interface __RPC_FAR *This, 
	                                                         long __MIDL_0012, 
	                                                         unsigned long dwMessage, 
	                                                         unsigned long dwCodeSet, 
	                                                         long *plRegister);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSection_) (MediaPlayer_IRadioPlayer_Interface __RPC_FAR *This, 
	                                                     BSTR *bszSection);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Unregister_) (MediaPlayer_IRadioPlayer_Interface __RPC_FAR *This, 
	                                                     long lRegister);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetInstanceCount_) (MediaPlayer_IRadioPlayer_Interface __RPC_FAR *This, 
	                                                           long *plInstances);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Play_) (MediaPlayer_IRadioPlayer_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Stop_) (MediaPlayer_IRadioPlayer_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetUrl_) (MediaPlayer_IRadioPlayer_Interface __RPC_FAR *This, 
	                                                 BSTR newValue);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetVolume_) (MediaPlayer_IRadioPlayer_Interface __RPC_FAR *This, 
	                                                    long newValue);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMute_) (MediaPlayer_IRadioPlayer_Interface __RPC_FAR *This, 
	                                                  VBOOL newValue);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetStatus_) (MediaPlayer_IRadioPlayer_Interface __RPC_FAR *This, 
	                                                    long *plVolume, 
	                                                    long *pfMute, 
	                                                    long *pfPlay, 
	                                                    BSTR *__MIDL_0013, 
	                                                    BSTR *__MIDL_0014, 
	                                                    BSTR *__MIDL_0015, 
	                                                    BSTR *__MIDL_0016, 
	                                                    BSTR *__MIDL_0017, 
	                                                    BSTR *__MIDL_0018, 
	                                                    BSTR *__MIDL_0019);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetState_) (MediaPlayer_IRadioPlayer_Interface __RPC_FAR *This, 
	                                                   long *plOpenState, 
	                                                   long *pfBuffering, 
	                                                   long *plBufferingPercent, 
	                                                   long *plQuality);

} MediaPlayer_IRadioPlayer_VTable;

typedef interface tagMediaPlayer_IRadioPlayer_Interface
{
	CONST_VTBL MediaPlayer_IRadioPlayer_VTable __RPC_FAR *lpVtbl;
} MediaPlayer_IRadioPlayer_Interface;

typedef interface tagMediaPlayer_IRadioServer_Interface MediaPlayer_IRadioServer_Interface;

typedef struct tagMediaPlayer_IRadioServer_VTable
{
	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( MediaPlayer_IRadioServer_Interface __RPC_FAR * This, 
	                                                         REFIID riid, 
	                                                         void __RPC_FAR *__RPC_FAR *ppvObject);

	ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( MediaPlayer_IRadioServer_Interface __RPC_FAR * This);

	ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( MediaPlayer_IRadioServer_Interface __RPC_FAR * This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( MediaPlayer_IRadioServer_Interface __RPC_FAR * This, 
	                                                           UINT __RPC_FAR *pctinfo);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( MediaPlayer_IRadioServer_Interface __RPC_FAR * This, 
	                                                      UINT iTInfo, 
	                                                      LCID lcid, 
	                                                      ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( MediaPlayer_IRadioServer_Interface __RPC_FAR * This, 
	                                                        REFIID riid, 
	                                                        LPOLESTR __RPC_FAR *rgszNames, 
	                                                        UINT cNames, 
	                                                        LCID lcid, 
	                                                        DISPID __RPC_FAR *rgDispId);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( MediaPlayer_IRadioServer_Interface __RPC_FAR * This, 
	                                                 DISPID dispIdMember, 
	                                                 REFIID riid, 
	                                                 LCID lcid, 
	                                                 WORD wFlags, 
	                                                 DISPPARAMS __RPC_FAR *pDispParams, 
	                                                 VARIANT __RPC_FAR *pVarResult, 
	                                                 EXCEPINFO __RPC_FAR *pExcepInfo, 
	                                                 UINT __RPC_FAR *puArgErr);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BindToRadio_) (MediaPlayer_IRadioServer_Interface __RPC_FAR *This, 
	                                                      BSTR wszRadio, 
	                                                      LPDISPATCH *ppServer);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *IsRadioExists_) (MediaPlayer_IRadioServer_Interface __RPC_FAR *This, 
	                                                        BSTR wszRadio);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LaunchStandardUrl_) (MediaPlayer_IRadioServer_Interface __RPC_FAR *This, 
	                                                            BSTR bszUrl, 
	                                                            LPUNKNOWN pBrowser);

} MediaPlayer_IRadioServer_VTable;

typedef interface tagMediaPlayer_IRadioServer_Interface
{
	CONST_VTBL MediaPlayer_IRadioServer_VTable __RPC_FAR *lpVtbl;
} MediaPlayer_IRadioServer_Interface;

typedef interface tagMediaPlayer_IMediaPlayerListener_Interface MediaPlayer_IMediaPlayerListener_Interface;

typedef struct tagMediaPlayer_IMediaPlayerListener_VTable
{
	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( MediaPlayer_IMediaPlayerListener_Interface __RPC_FAR * This, 
	                                                         REFIID riid, 
	                                                         void __RPC_FAR *__RPC_FAR *ppvObject);

	ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( MediaPlayer_IMediaPlayerListener_Interface __RPC_FAR * This);

	ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( MediaPlayer_IMediaPlayerListener_Interface __RPC_FAR * This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PlayStateChanged_) (MediaPlayer_IMediaPlayerListener_Interface __RPC_FAR *This, 
	                                                           long lNewState);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Buffering_) (MediaPlayer_IMediaPlayerListener_Interface __RPC_FAR *This, 
	                                                    VBOOL fStart);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BufferPercent_) (MediaPlayer_IMediaPlayerListener_Interface __RPC_FAR *This, 
	                                                        long lBufferPercent);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OpenStateChanged_) (MediaPlayer_IMediaPlayerListener_Interface __RPC_FAR *This, 
	                                                           long lOpenState);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MediaInfoChanged_) (MediaPlayer_IMediaPlayerListener_Interface __RPC_FAR *This, 
	                                                           BSTR bstrShowTitle, 
	                                                           BSTR bstrClipTitle, 
	                                                           BSTR bstrClipAuthor, 
	                                                           BSTR bstrClipCopyright, 
	                                                           BSTR bstrStationURL);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QualityChanged_) (MediaPlayer_IMediaPlayerListener_Interface __RPC_FAR *This, 
	                                                         long lQuality);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Error_) (MediaPlayer_IMediaPlayerListener_Interface __RPC_FAR *This, 
	                                                BSTR bstrError);

} MediaPlayer_IMediaPlayerListener_VTable;

typedef interface tagMediaPlayer_IMediaPlayerListener_Interface
{
	CONST_VTBL MediaPlayer_IMediaPlayerListener_VTable __RPC_FAR *lpVtbl;
} MediaPlayer_IMediaPlayerListener_Interface;

typedef interface tagMediaPlayer_IRadioBand_Interface MediaPlayer_IRadioBand_Interface;

typedef struct tagMediaPlayer_IRadioBand_VTable
{
	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( MediaPlayer_IRadioBand_Interface __RPC_FAR * This, 
	                                                         REFIID riid, 
	                                                         void __RPC_FAR *__RPC_FAR *ppvObject);

	ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( MediaPlayer_IRadioBand_Interface __RPC_FAR * This);

	ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( MediaPlayer_IRadioBand_Interface __RPC_FAR * This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( MediaPlayer_IRadioBand_Interface __RPC_FAR * This, 
	                                                           UINT __RPC_FAR *pctinfo);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( MediaPlayer_IRadioBand_Interface __RPC_FAR * This, 
	                                                      UINT iTInfo, 
	                                                      LCID lcid, 
	                                                      ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( MediaPlayer_IRadioBand_Interface __RPC_FAR * This, 
	                                                        REFIID riid, 
	                                                        LPOLESTR __RPC_FAR *rgszNames, 
	                                                        UINT cNames, 
	                                                        LCID lcid, 
	                                                        DISPID __RPC_FAR *rgDispId);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( MediaPlayer_IRadioBand_Interface __RPC_FAR * This, 
	                                                 DISPID dispIdMember, 
	                                                 REFIID riid, 
	                                                 LCID lcid, 
	                                                 WORD wFlags, 
	                                                 DISPPARAMS __RPC_FAR *pDispParams, 
	                                                 VARIANT __RPC_FAR *pVarResult, 
	                                                 EXCEPINFO __RPC_FAR *pExcepInfo, 
	                                                 UINT __RPC_FAR *puArgErr);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Create_) (MediaPlayer_IRadioBand_Interface __RPC_FAR *This, 
	                                                 long *phwnd, 
	                                                 long hwndParent);

} MediaPlayer_IRadioBand_VTable;

typedef interface tagMediaPlayer_IRadioBand_Interface
{
	CONST_VTBL MediaPlayer_IRadioBand_VTable __RPC_FAR *lpVtbl;
} MediaPlayer_IRadioBand_Interface;

typedef interface tagMediaPlayer_IMediaPlayer_Interface MediaPlayer_IMediaPlayer_Interface;

typedef struct tagMediaPlayer_IMediaPlayer_VTable
{
	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( MediaPlayer_IMediaPlayer_Interface __RPC_FAR * This, 
	                                                         REFIID riid, 
	                                                         void __RPC_FAR *__RPC_FAR *ppvObject);

	ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( MediaPlayer_IMediaPlayer_Interface __RPC_FAR * This);

	ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( MediaPlayer_IMediaPlayer_Interface __RPC_FAR * This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( MediaPlayer_IMediaPlayer_Interface __RPC_FAR * This, 
	                                                           UINT __RPC_FAR *pctinfo);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( MediaPlayer_IMediaPlayer_Interface __RPC_FAR * This, 
	                                                      UINT iTInfo, 
	                                                      LCID lcid, 
	                                                      ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( MediaPlayer_IMediaPlayer_Interface __RPC_FAR * This, 
	                                                        REFIID riid, 
	                                                        LPOLESTR __RPC_FAR *rgszNames, 
	                                                        UINT cNames, 
	                                                        LCID lcid, 
	                                                        DISPID __RPC_FAR *rgDispId);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( MediaPlayer_IMediaPlayer_Interface __RPC_FAR * This, 
	                                                 DISPID dispIdMember, 
	                                                 REFIID riid, 
	                                                 LCID lcid, 
	                                                 WORD wFlags, 
	                                                 DISPPARAMS __RPC_FAR *pDispParams, 
	                                                 VARIANT __RPC_FAR *pVarResult, 
	                                                 EXCEPINFO __RPC_FAR *pExcepInfo, 
	                                                 UINT __RPC_FAR *puArgErr);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCurrentPosition_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                             double *pCurrentPosition);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCurrentPosition_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                             double pCurrentPosition);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDuration_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                      double *pDuration);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetImageSourceWidth_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                              long *pWidth);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetImageSourceHeight_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                               long *pHeight);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMarkerCount_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                         long *pMarkerCount);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCanScan_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                     VBOOL *pCanScan);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCanSeek_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                     VBOOL *pCanSeek);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCanSeekToMarkers_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                              VBOOL *pCanSeekToMarkers);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCurrentMarker_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                           long *pCurrentMarker);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCurrentMarker_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                           long pCurrentMarker);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFileName_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                      BSTR *pbstrFileName);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFileName_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                      BSTR pbstrFileName);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSourceLink_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                        BSTR *pbstrSourceLink);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCreationDate_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                          DATE *pCreationDate);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetErrorCorrection_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                             BSTR *pbstrErrorCorrection);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetBandwidth_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                       long *pBandwidth);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSourceProtocol_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                            long *pSourceProtocol);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetReceivedPackets_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                             long *pReceivedPackets);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRecoveredPackets_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                              long *pRecoveredPackets);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLostPackets_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                         long *pLostPackets);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetReceptionQuality_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                              long *pReceptionQuality);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetBufferingCount_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                            long *pBufferingCount);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIsBroadcast_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                         VBOOL *pIsBroadcast);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetBufferingProgress_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                               long *pBufferingProgress);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetChannelName_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                         BSTR *pbstrChannelName);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetChannelDescription_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                                BSTR *pbstrChannelDescription);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetChannelURL_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                        BSTR *pbstrChannelURL);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetContactAddress_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                            BSTR *pbstrContactAddress);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetContactPhone_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                          BSTR *pbstrContactPhone);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetContactEmail_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                          BSTR *pbstrContactEmail);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetBufferingTime_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                           double *pBufferingTime);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetBufferingTime_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                           double pBufferingTime);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAutoStart_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                       VBOOL *pAutoStart);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAutoStart_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                       VBOOL pAutoStart);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAutoRewind_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                        VBOOL *pAutoRewind);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAutoRewind_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                        VBOOL pAutoRewind);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRate_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                  double *pRate);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetRate_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                  double pRate);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSendKeyboardEvents_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                                VBOOL *pSendKeyboardEvents);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSendKeyboardEvents_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                                VBOOL pSendKeyboardEvents);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSendMouseClickEvents_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                                  VBOOL *pSendMouseClickEvents);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSendMouseClickEvents_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                                  VBOOL pSendMouseClickEvents);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSendMouseMoveEvents_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                                 VBOOL *pSendMouseMoveEvents);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSendMouseMoveEvents_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                                 VBOOL pSendMouseMoveEvents);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPlayCount_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                       long *pPlayCount);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPlayCount_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                       long pPlayCount);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClickToPlay_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                         VBOOL *pClickToPlay);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClickToPlay_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                         VBOOL pClickToPlay);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAllowScan_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                       VBOOL *pAllowScan);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAllowScan_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                       VBOOL pAllowScan);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnableContextMenu_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                               VBOOL *pEnableContextMenu);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetEnableContextMenu_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                               VBOOL pEnableContextMenu);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCursorType_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                        long *pCursorType);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCursorType_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                        long pCursorType);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCodecCount_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                        long *pCodecCount);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAllowChangeDisplaySize_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                                    VBOOL *pAllowChangeDisplaySize);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAllowChangeDisplaySize_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                                    VBOOL pAllowChangeDisplaySize);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIsDurationValid_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                             VBOOL *pIsDurationValid);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetOpenState_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                       long *pOpenState);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSendOpenStateChangeEvents_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                                       VBOOL *pSendOpenStateChangeEvents);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSendOpenStateChangeEvents_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                                       VBOOL pSendOpenStateChangeEvents);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSendWarningEvents_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                               VBOOL *pSendWarningEvents);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSendWarningEvents_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                               VBOOL pSendWarningEvents);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSendErrorEvents_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                             VBOOL *pSendErrorEvents);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSendErrorEvents_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                             VBOOL pSendErrorEvents);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPlayState_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                       long *pPlayState);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSendPlayStateChangeEvents_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                                       VBOOL *pSendPlayStateChangeEvents);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSendPlayStateChangeEvents_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                                       VBOOL pSendPlayStateChangeEvents);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDisplaySize_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                         long *pDisplaySize);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDisplaySize_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                         long pDisplaySize);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetInvokeURLs_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                        VBOOL *pInvokeURLs);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetInvokeURLs_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                        VBOOL pInvokeURLs);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetBaseURL_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                     BSTR *pbstrBaseURL);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetBaseURL_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                     BSTR pbstrBaseURL);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDefaultFrame_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                          BSTR *pbstrDefaultFrame);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDefaultFrame_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                          BSTR pbstrDefaultFrame);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetHasError_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                      VBOOL *pHasError);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetErrorDescription_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                              BSTR *pbstrErrorDescription);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetErrorCode_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                       long *pErrorCode);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAnimationAtStart_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                              VBOOL *pAnimationAtStart);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAnimationAtStart_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                              VBOOL pAnimationAtStart);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTransparentAtStart_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                                VBOOL *pTransparentAtStart);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetTransparentAtStart_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                                VBOOL pTransparentAtStart);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVolume_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                    long *pVolume);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetVolume_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                    long pVolume);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetBalance_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                     long *pBalance);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetBalance_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                     long pBalance);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetReadyState_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                        long *pValue);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSelectionStart_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                            double *pValue);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSelectionStart_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                            double pValue);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSelectionEnd_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                          double *pValue);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSelectionEnd_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                          double pValue);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetShowDisplay_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                         VBOOL *show);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetShowDisplay_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                         VBOOL show);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetShowControls_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                          VBOOL *show);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetShowControls_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                          VBOOL show);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetShowPositionControls_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                                  VBOOL *show);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetShowPositionControls_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                                  VBOOL show);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetShowTracker_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                         VBOOL *show);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetShowTracker_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                         VBOOL show);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnablePositionControls_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                                    VBOOL *enable);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetEnablePositionControls_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                                    VBOOL enable);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnableTracker_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                           VBOOL *enable);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetEnableTracker_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                           VBOOL enable);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnabled_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                     VBOOL *pEnabled);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetEnabled_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                     VBOOL pEnabled);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDisplayForeColor_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                              unsigned long *foreColor);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDisplayForeColor_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                              unsigned long foreColor);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDisplayBackColor_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                              unsigned long *backColor);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDisplayBackColor_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                              unsigned long backColor);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDisplayMode_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                         long *pValue);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDisplayMode_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                         long pValue);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVideoBorder3D_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                           VBOOL *pVideoBorderWidth);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetVideoBorder3D_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                           VBOOL pVideoBorderWidth);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVideoBorderWidth_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                              long *pVideoBorderWidth);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetVideoBorderWidth_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                              long pVideoBorderWidth);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVideoBorderColor_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                              unsigned long *pVideoBorderWidth);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetVideoBorderColor_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                              unsigned long pVideoBorderWidth);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetShowGotoBar_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                         VBOOL *pbool);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetShowGotoBar_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                         VBOOL pbool);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetShowStatusBar_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                           VBOOL *pbool);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetShowStatusBar_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                           VBOOL pbool);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetShowCaptioning_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                            VBOOL *pbool);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetShowCaptioning_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                            VBOOL pbool);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetShowAudioControls_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                               VBOOL *pbool);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetShowAudioControls_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                               VBOOL pbool);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCaptioningID_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                          BSTR *pstrText);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCaptioningID_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                          BSTR pstrText);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMute_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                  VBOOL *vbool);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMute_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                  VBOOL vbool);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCanPreview_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                        VBOOL *pCanPreview);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPreviewMode_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                         VBOOL *pPreviewMode);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPreviewMode_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                         VBOOL pPreviewMode);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetHasMultipleItems_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                              VBOOL *pHasMuliItems);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLanguage_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                      long *pLanguage);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLanguage_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                      long pLanguage);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAudioStream_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                         long *pStream);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAudioStream_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                         long pStream);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSAMIStyle_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                       BSTR *pbstrStyle);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSAMIStyle_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                       BSTR pbstrStyle);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSAMILang_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                      BSTR *pbstrLang);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSAMILang_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                      BSTR pbstrLang);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSAMIFileName_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                          BSTR *pbstrFileName);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSAMIFileName_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                          BSTR pbstrFileName);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetStreamCount_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                         long *pStreamCount);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClientId_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                      BSTR *pbstrClientId);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetConnectionSpeed_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                             long *plConnectionSpeed);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAutoSize_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                      VBOOL *pbool);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAutoSize_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                      VBOOL pbool);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnableFullScreenControls_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                                      VBOOL *pbVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetEnableFullScreenControls_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                                      VBOOL pbVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetActiveMovie_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                         LPDISPATCH *ppdispatch);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNSPlay_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                    LPDISPATCH *ppdispatch);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetWindowlessVideo_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                             VBOOL *pbool);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetWindowlessVideo_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                             VBOOL pbool);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Play_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Stop_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Pause_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMarkerTime_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                        long markerNum, 
	                                                        double *pMarkerTime);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMarkerName_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                        long markerNum, 
	                                                        BSTR *pbstrMarkerName);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AboutBox_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCodecInstalled_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                            long codecNum, 
	                                                            VBOOL *pCodecInstalled);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCodecDescription_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                              long codecNum, 
	                                                              BSTR *pbstrCodecDescription);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCodecURL_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                      long codecNum, 
	                                                      BSTR *pbstrCodecURL);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMoreInfoURL_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                         long moreInfoType, 
	                                                         BSTR *pbstrMoreInfoURL);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMediaInfoString_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                             long mediaInfoType, 
	                                                             BSTR *pbstrMediaInfo);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Cancel_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                               BSTR bstrFileName);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *IsSoundCardEnabled_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                             VBOOL *pbSoundCard);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Next_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Previous_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *StreamSelect_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                       long streamNum);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FastForward_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FastReverse_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetStreamName_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                        long streamNum, 
	                                                        BSTR *pbstrStreamName);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetStreamGroup_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                         long streamNum, 
	                                                         long *pStreamGroup);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetStreamSelected_) (MediaPlayer_IMediaPlayer_Interface __RPC_FAR *This, 
	                                                            long streamNum, 
	                                                            VBOOL *pStreamSelected);

} MediaPlayer_IMediaPlayer_VTable;

typedef interface tagMediaPlayer_IMediaPlayer_Interface
{
	CONST_VTBL MediaPlayer_IMediaPlayer_VTable __RPC_FAR *lpVtbl;
} MediaPlayer_IMediaPlayer_Interface;

typedef interface tagMediaPlayer_IMediaPlayerDvd_Interface MediaPlayer_IMediaPlayerDvd_Interface;

typedef struct tagMediaPlayer_IMediaPlayerDvd_VTable
{
	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR * This, 
	                                                         REFIID riid, 
	                                                         void __RPC_FAR *__RPC_FAR *ppvObject);

	ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR * This);

	ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR * This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR * This, 
	                                                           UINT __RPC_FAR *pctinfo);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR * This, 
	                                                      UINT iTInfo, 
	                                                      LCID lcid, 
	                                                      ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR * This, 
	                                                        REFIID riid, 
	                                                        LPOLESTR __RPC_FAR *rgszNames, 
	                                                        UINT cNames, 
	                                                        LCID lcid, 
	                                                        DISPID __RPC_FAR *rgDispId);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR * This, 
	                                                 DISPID dispIdMember, 
	                                                 REFIID riid, 
	                                                 LCID lcid, 
	                                                 WORD wFlags, 
	                                                 DISPPARAMS __RPC_FAR *pDispParams, 
	                                                 VARIANT __RPC_FAR *pVarResult, 
	                                                 EXCEPINFO __RPC_FAR *pExcepInfo, 
	                                                 UINT __RPC_FAR *puArgErr);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ButtonSelectAndActivate_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This, 
	                                                                  unsigned long uiButton);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UpperButtonSelect_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LowerButtonSelect_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LeftButtonSelect_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RightButtonSelect_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ButtonActivate_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ForwardScan_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This, 
	                                                      double dwSpeed);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BackwardScan_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This, 
	                                                       double dwSpeed);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PrevPGSearch_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *TopPGSearch_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *NextPGSearch_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *TitlePlay_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This, 
	                                                    unsigned long uiTitle);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ChapterPlay_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This, 
	                                                      unsigned long uiTitle, 
	                                                      unsigned long uiChapter);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ChapterSearch_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This, 
	                                                        unsigned long chapter);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MenuCall_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This, 
	                                                   long menuID);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ResumeFromMenu_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *TimePlay_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This, 
	                                                   unsigned long uiTitle, 
	                                                   BSTR bstrTime);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *TimeSearch_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This, 
	                                                     BSTR bstrTime);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ChapterPlayAutoStop_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This, 
	                                                              unsigned long ulTitle, 
	                                                              unsigned long ulChapter, 
	                                                              unsigned long ulChaptersToPlay);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *StillOff_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GoUp_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTotalTitleTime_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This, 
	                                                            BSTR *bstrTime);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNumberOfChapters_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This, 
	                                                              unsigned long ulTitle, 
	                                                              unsigned long *ulNumChapters);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAudioLanguage_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This, 
	                                                           unsigned long ulStream, 
	                                                           BSTR *bstrAudioLang);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSubpictureLanguage_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This, 
	                                                                unsigned long ulStream, 
	                                                                BSTR *bstrSubpictureLang);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAllGPRMs_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This, 
	                                                      VARIANT *vtGPRM);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAllSPRMs_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This, 
	                                                      VARIANT *vtSPRM);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UOPValid_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This, 
	                                                   unsigned long ulUOP, 
	                                                   VBOOL *bValid);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetButtonsAvailable_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This, 
	                                                              unsigned long *ulButtonsAvailable);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCurrentButton_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This, 
	                                                           unsigned long *ulCurrentButton);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAudioStreamsAvailable_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This, 
	                                                                   unsigned long *ulAudioStreamsAvailable);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCurrentAudioStream_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This, 
	                                                                unsigned long *ulAudioStream);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCurrentAudioStream_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This, 
	                                                                unsigned long ulAudioStream);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCurrentSubpictureStream_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This, 
	                                                                     unsigned long *ulSubpictureStream);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCurrentSubpictureStream_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This, 
	                                                                     unsigned long ulSubpictureStream);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSubpictureStreamsAvailable_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This, 
	                                                                        unsigned long *ulNumSubpictureStreams);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSubpictureOn_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This, 
	                                                          VBOOL *bSubpictureON);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSubpictureOn_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This, 
	                                                          VBOOL bSubpictureON);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAnglesAvailable_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This, 
	                                                             unsigned long *ulAnglesAvailable);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCurrentAngle_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This, 
	                                                          unsigned long *ulAngle);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCurrentAngle_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This, 
	                                                          unsigned long ulAngle);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCurrentTitle_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This, 
	                                                          unsigned long *ulTitle);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCurrentChapter_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This, 
	                                                            unsigned long *ulChapter);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCurrentTime_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This, 
	                                                         BSTR *bstrTime);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetRoot_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This, 
	                                                  BSTR pbstrPath);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRoot_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This, 
	                                                  BSTR *pbstrPath);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFramesPerSecond_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This, 
	                                                             unsigned long *ulFps);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCurrentDomain_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This, 
	                                                           unsigned long *ulDomain);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTitlesAvailable_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This, 
	                                                             unsigned long *ulTitles);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVolumesAvailable_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This, 
	                                                              unsigned long *pulVolumes);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCurrentVolume_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This, 
	                                                           unsigned long *pulVolume);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCurrentDiscSide_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This, 
	                                                             unsigned long *pulDiscSide);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCCActive_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This, 
	                                                      VBOOL *bCCActive);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCCActive_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This, 
	                                                      VBOOL bCCActive);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCurrentCCService_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This, 
	                                                              unsigned long *pulService);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCurrentCCService_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This, 
	                                                              unsigned long pulService);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetUniqueID_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This, 
	                                                      BSTR *pvtUniqueID);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetColorKey_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This, 
	                                                      unsigned long *pClr);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetColorKey_) (MediaPlayer_IMediaPlayerDvd_Interface __RPC_FAR *This, 
	                                                      unsigned long pClr);

} MediaPlayer_IMediaPlayerDvd_VTable;

typedef interface tagMediaPlayer_IMediaPlayerDvd_Interface
{
	CONST_VTBL MediaPlayer_IMediaPlayerDvd_VTable __RPC_FAR *lpVtbl;
} MediaPlayer_IMediaPlayerDvd_Interface;

static CA_PARAMDATA __MediaPlayerEvents_RegOnDVDNotify_CA_PARAMDATA[] =
	{
		{"eventCode", VT_I4},
        {"eventParam1", VT_I4},
        {"eventParam2", VT_I4}
	};

static CA_PARAMDATA __MediaPlayerEvents_RegOnEndOfStream_CA_PARAMDATA[] =
	{
		{"result", VT_I4}
	};

static CA_PARAMDATA __MediaPlayerEvents_RegOnKeyDown_CA_PARAMDATA[] =
	{
		{"keyCode", VT_I2},
        {"shiftState", VT_I2}
	};

static CA_PARAMDATA __MediaPlayerEvents_RegOnKeyUp_CA_PARAMDATA[] =
	{
		{"keyCode", VT_I2},
        {"shiftState", VT_I2}
	};

static CA_PARAMDATA __MediaPlayerEvents_RegOnKeyPress_CA_PARAMDATA[] =
	{
		{"characterCode", VT_I2}
	};

static CA_PARAMDATA __MediaPlayerEvents_RegOnMouseMove_CA_PARAMDATA[] =
	{
		{"button", VT_I2},
        {"shiftState", VT_I2},
        {"x", VT_I4},
        {"y", VT_I4}
	};

static CA_PARAMDATA __MediaPlayerEvents_RegOnMouseDown_CA_PARAMDATA[] =
	{
		{"button", VT_I2},
        {"shiftState", VT_I2},
        {"x", VT_I4},
        {"y", VT_I4}
	};

static CA_PARAMDATA __MediaPlayerEvents_RegOnMouseUp_CA_PARAMDATA[] =
	{
		{"button", VT_I2},
        {"shiftState", VT_I2},
        {"x", VT_I4},
        {"y", VT_I4}
	};

static CA_PARAMDATA __MediaPlayerEvents_RegOnClick_CA_PARAMDATA[] =
	{
		{"button", VT_I2},
        {"shiftState", VT_I2},
        {"x", VT_I4},
        {"y", VT_I4}
	};

static CA_PARAMDATA __MediaPlayerEvents_RegOnDblClick_CA_PARAMDATA[] =
	{
		{"button", VT_I2},
        {"shiftState", VT_I2},
        {"x", VT_I4},
        {"y", VT_I4}
	};

static CA_PARAMDATA __MediaPlayerEvents_RegOnOpenStateChange_CA_PARAMDATA[] =
	{
		{"oldState", VT_I4},
        {"newState", VT_I4}
	};

static CA_PARAMDATA __MediaPlayerEvents_RegOnPlayStateChange_CA_PARAMDATA[] =
	{
		{"oldState", VT_I4},
        {"newState", VT_I4}
	};

static CA_PARAMDATA __MediaPlayerEvents_RegOnScriptCommand_CA_PARAMDATA[] =
	{
		{"scType", VT_BSTR},
        {"param", VT_BSTR}
	};

static CA_PARAMDATA __MediaPlayerEvents_RegOnBuffering_CA_PARAMDATA[] =
	{
		{"start", VT_BOOL}
	};

static CA_PARAMDATA __MediaPlayerEvents_RegOnMarkerHit_CA_PARAMDATA[] =
	{
		{"markerNum", VT_I4}
	};

static CA_PARAMDATA __MediaPlayerEvents_RegOnWarning_CA_PARAMDATA[] =
	{
		{"warningType", VT_I4},
        {"param", VT_I4},
        {"description", VT_BSTR}
	};

static CA_PARAMDATA __MediaPlayerEvents_RegOnDisconnect_CA_PARAMDATA[] =
	{
		{"result", VT_I4}
	};

static CA_PARAMDATA __MediaPlayerEvents_RegOnPositionChange_CA_PARAMDATA[] =
	{
		{"oldPosition", VT_R8},
        {"newPosition", VT_R8}
	};

static CA_PARAMDATA __MediaPlayerEvents_RegOnReadyStateChange_CA_PARAMDATA[] =
	{
		{"readyState", VT_I4}
	};

static CA_METHODDATA __MediaPlayerEvents_CA_METHODDATA[] =
	{
		{"DVDNotify", __MediaPlayerEvents_RegOnDVDNotify_CA_PARAMDATA, 1505, 0, CC_STDCALL, 3, DISPATCH_METHOD, VT_EMPTY},
        {"EndOfStream", __MediaPlayerEvents_RegOnEndOfStream_CA_PARAMDATA, 3002, 1, CC_STDCALL, 1, DISPATCH_METHOD, VT_EMPTY},
        {"KeyDown", __MediaPlayerEvents_RegOnKeyDown_CA_PARAMDATA, -602, 2, CC_STDCALL, 2, DISPATCH_METHOD, VT_EMPTY},
        {"KeyUp", __MediaPlayerEvents_RegOnKeyUp_CA_PARAMDATA, -604, 3, CC_STDCALL, 2, DISPATCH_METHOD, VT_EMPTY},
        {"KeyPress", __MediaPlayerEvents_RegOnKeyPress_CA_PARAMDATA, -603, 4, CC_STDCALL, 1, DISPATCH_METHOD, VT_EMPTY},
        {"MouseMove", __MediaPlayerEvents_RegOnMouseMove_CA_PARAMDATA, -606, 5, CC_STDCALL, 4, DISPATCH_METHOD, VT_EMPTY},
        {"MouseDown", __MediaPlayerEvents_RegOnMouseDown_CA_PARAMDATA, -605, 6, CC_STDCALL, 4, DISPATCH_METHOD, VT_EMPTY},
        {"MouseUp", __MediaPlayerEvents_RegOnMouseUp_CA_PARAMDATA, -607, 7, CC_STDCALL, 4, DISPATCH_METHOD, VT_EMPTY},
        {"Click", __MediaPlayerEvents_RegOnClick_CA_PARAMDATA, -600, 8, CC_STDCALL, 4, DISPATCH_METHOD, VT_EMPTY},
        {"DblClick", __MediaPlayerEvents_RegOnDblClick_CA_PARAMDATA, -601, 9, CC_STDCALL, 4, DISPATCH_METHOD, VT_EMPTY},
        {"OpenStateChange", __MediaPlayerEvents_RegOnOpenStateChange_CA_PARAMDATA, 3011, 10, CC_STDCALL, 2, DISPATCH_METHOD, VT_EMPTY},
        {"PlayStateChange", __MediaPlayerEvents_RegOnPlayStateChange_CA_PARAMDATA, 3012, 11, CC_STDCALL, 2, DISPATCH_METHOD, VT_EMPTY},
        {"ScriptCommand", __MediaPlayerEvents_RegOnScriptCommand_CA_PARAMDATA, 3001, 12, CC_STDCALL, 2, DISPATCH_METHOD, VT_EMPTY},
        {"Buffering", __MediaPlayerEvents_RegOnBuffering_CA_PARAMDATA, 3003, 13, CC_STDCALL, 1, DISPATCH_METHOD, VT_EMPTY},
        {"Error", NULL, 3010, 14, CC_STDCALL, 0, DISPATCH_METHOD, VT_EMPTY},
        {"MarkerHit", __MediaPlayerEvents_RegOnMarkerHit_CA_PARAMDATA, 3006, 15, CC_STDCALL, 1, DISPATCH_METHOD, VT_EMPTY},
        {"Warning", __MediaPlayerEvents_RegOnWarning_CA_PARAMDATA, 3009, 16, CC_STDCALL, 3, DISPATCH_METHOD, VT_EMPTY},
        {"NewStream", NULL, 3008, 17, CC_STDCALL, 0, DISPATCH_METHOD, VT_EMPTY},
        {"Disconnect", __MediaPlayerEvents_RegOnDisconnect_CA_PARAMDATA, 3004, 18, CC_STDCALL, 1, DISPATCH_METHOD, VT_EMPTY},
        {"PositionChange", __MediaPlayerEvents_RegOnPositionChange_CA_PARAMDATA, 2, 19, CC_STDCALL, 2, DISPATCH_METHOD, VT_EMPTY},
        {"DisplayModeChange", NULL, 51, 20, CC_STDCALL, 0, DISPATCH_METHOD, VT_EMPTY},
        {"ReadyStateChange", __MediaPlayerEvents_RegOnReadyStateChange_CA_PARAMDATA, -609, 21, CC_STDCALL, 1, DISPATCH_METHOD, VT_EMPTY}
	};

static CA_INTERFACEDATA __MediaPlayerEvents_CA_INTERFACEDATA =
	{
		__MediaPlayerEvents_CA_METHODDATA,
        sizeof (__MediaPlayerEvents_CA_METHODDATA) / sizeof (*__MediaPlayerEvents_CA_METHODDATA)
	};

static void * __MediaPlayerEvents_EventVTable[] =
	{
		_MediaPlayerEventsRegOnDVDNotify_EventVTableFunc,
        _MediaPlayerEventsRegOnEndOfStream_EventVTableFunc,
        _MediaPlayerEventsRegOnKeyDown_EventVTableFunc,
        _MediaPlayerEventsRegOnKeyUp_EventVTableFunc,
        _MediaPlayerEventsRegOnKeyPress_EventVTableFunc,
        _MediaPlayerEventsRegOnMouseMove_EventVTableFunc,
        _MediaPlayerEventsRegOnMouseDown_EventVTableFunc,
        _MediaPlayerEventsRegOnMouseUp_EventVTableFunc,
        _MediaPlayerEventsRegOnClick_EventVTableFunc,
        _MediaPlayerEventsRegOnDblClick_EventVTableFunc,
        _MediaPlayerEventsRegOnOpenStateChange_EventVTableFunc,
        _MediaPlayerEventsRegOnPlayStateChange_EventVTableFunc,
        _MediaPlayerEventsRegOnScriptCommand_EventVTableFunc,
        _MediaPlayerEventsRegOnBuffering_EventVTableFunc,
        _MediaPlayerEventsRegOnError_EventVTableFunc,
        _MediaPlayerEventsRegOnMarkerHit_EventVTableFunc,
        _MediaPlayerEventsRegOnWarning_EventVTableFunc,
        _MediaPlayerEventsRegOnNewStream_EventVTableFunc,
        _MediaPlayerEventsRegOnDisconnect_EventVTableFunc,
        _MediaPlayerEventsRegOnPositionChange_EventVTableFunc,
        _MediaPlayerEventsRegOnDisplayModeChange_EventVTableFunc,
        _MediaPlayerEventsRegOnReadyStateChange_EventVTableFunc
	};

static CAEventClassDefn __MediaPlayerEvents_CAEventClassDefn =
	{
		20,
        &MediaPlayer_IID__MediaPlayerEvents,
        __MediaPlayerEvents_EventVTable,
        &__MediaPlayerEvents_CA_INTERFACEDATA,
        0
	};

static CA_PARAMDATA __IRadioPlayerEvents_RegOnStateChange_CA_PARAMDATA[] =
	{
		{"bszUrl", VT_BSTR},
        {"fPlay", VT_BOOL},
        {"lVolume", VT_I4},
        {"fMute", VT_BOOL}
	};

static CA_METHODDATA __IRadioPlayerEvents_CA_METHODDATA[] =
	{
		{"StateChange", __IRadioPlayerEvents_RegOnStateChange_CA_PARAMDATA, 12, 0, CC_STDCALL, 4, DISPATCH_METHOD, VT_I4}
	};

static CA_INTERFACEDATA __IRadioPlayerEvents_CA_INTERFACEDATA =
	{
		__IRadioPlayerEvents_CA_METHODDATA,
        sizeof (__IRadioPlayerEvents_CA_METHODDATA) / sizeof (*__IRadioPlayerEvents_CA_METHODDATA)
	};

static void * __IRadioPlayerEvents_EventVTable[] =
	{
		_IRadioPlayerEventsRegOnStateChange_EventVTableFunc
	};

static CAEventClassDefn __IRadioPlayerEvents_CAEventClassDefn =
	{
		20,
        &MediaPlayer_IID__IRadioPlayerEvents,
        __IRadioPlayerEvents_EventVTable,
        &__IRadioPlayerEvents_CA_INTERFACEDATA,
        0
	};

const IID MediaPlayer_IID_IDirectControl =
	{
		0x39A2C2A5, 0x4778, 0x11D2, 0x9B, 0xDB, 0x20, 0x4C, 0x4F, 0x4F, 0x50, 0x20
	};

const IID MediaPlayer_IID_IDirectContainer =
	{
		0x39A2C2A8, 0x4778, 0x11D2, 0x9B, 0xDB, 0x20, 0x4C, 0x4F, 0x4F, 0x50, 0x20
	};

const IID MediaPlayer_IID_IMediaPlayer2 =
	{
		0x20D4F5E0, 0x5475, 0x11D2, 0x97, 0x74, 0x0, 0x0, 0xF8, 0x8, 0x55, 0xE6
	};

const IID MediaPlayer_IID_IMediaBindStream =
	{
		0x920F0DE3, 0x91C5, 0x11D2, 0x82, 0x8F, 0x0, 0xC0, 0x4F, 0xC9, 0x9D, 0x4E
	};

const IID MediaPlayer_IID_IRadioPlayer =
	{
		0x9C2263AF, 0x3E3C, 0x11D2, 0x9B, 0xD3, 0x20, 0x4C, 0x4F, 0x4F, 0x50, 0x20
	};

const IID MediaPlayer_IID_IRadioServer =
	{
		0x9C2263A0, 0x3E3C, 0x11D2, 0x9B, 0xD3, 0x20, 0x4C, 0x4F, 0x4F, 0x50, 0x20
	};

const IID MediaPlayer_IID_IMediaPlayerListener =
	{
		0x33222211, 0x5E5E, 0x11D2, 0x9E, 0x8E, 0x0, 0x0, 0xF8, 0x8, 0x59, 0x81
	};

const IID MediaPlayer_IID_IRadioBand =
	{
		0x8E718881, 0x423F, 0x11D2, 0x87, 0x6E, 0x0, 0xA0, 0xC9, 0x8, 0x24, 0x67
	};

const IID MediaPlayer_IID__MediaPlayerEvents =
	{
		0x2D3A4C40, 0xE711, 0x11D0, 0x94, 0xAB, 0x0, 0x80, 0xC7, 0x4C, 0x7E, 0x95
	};

const IID MediaPlayer_IID__IRadioPlayerEvents =
	{
		0x9C2263B1, 0x3E3C, 0x11D2, 0x9B, 0xD3, 0x20, 0x4C, 0x4F, 0x4F, 0x50, 0x20
	};

const IID MediaPlayer_IID_IMediaPlayer =
	{
		0x22D6F311, 0xB0F6, 0x11D0, 0x94, 0xAB, 0x0, 0x80, 0xC7, 0x4C, 0x7E, 0x95
	};

const IID MediaPlayer_IID_IMediaPlayerDvd =
	{
		0x746EB440, 0x3835, 0x11D2, 0x97, 0x74, 0x0, 0x0, 0xF8, 0x8, 0x55, 0xE6
	};

const IID MediaPlayer_IID__IDirectControlEvents =
	{
		0x39A2C2A7, 0x4778, 0x11D2, 0x9B, 0xDB, 0x20, 0x4C, 0x4F, 0x4F, 0x50, 0x20
	};

const IID MediaPlayer_IID__IDirectContainerEvents =
	{
		0x39A2C2AA, 0x4778, 0x11D2, 0x9B, 0xDB, 0x20, 0x4C, 0x4F, 0x4F, 0x50, 0x20
	};

const IID MediaPlayer_IID__IRadioViewEvents =
	{
		0x847B4DF6, 0x4B61, 0x11D2, 0x9B, 0xDB, 0x20, 0x4C, 0x4F, 0x4F, 0x50, 0x20
	};

const IID MediaPlayer_IID__IAsyncPProtEvents =
	{
		0x3DA2AA3C, 0x3D96, 0x11D2, 0x9B, 0xD2, 0x20, 0x4C, 0x4F, 0x4F, 0x50, 0x20
	};

const IID MediaPlayer_IID_IRadioView =
	{
		0x847B4DF4, 0x4B61, 0x11D2, 0x9B, 0xDB, 0x20, 0x4C, 0x4F, 0x4F, 0x50, 0x20
	};

const IID MediaPlayer_IID_IUnknown =
	{
		0x0, 0x0, 0x0, 0xC0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x46
	};

const IID MediaPlayer_IID_IAsyncPProt =
	{
		0x3DA2AA3A, 0x3D96, 0x11D2, 0x9B, 0xD2, 0x20, 0x4C, 0x4F, 0x4F, 0x50, 0x20
	};

const IID MediaPlayer_IID_IAsyncMHandler =
	{
		0x3DA2AA3D, 0x3D96, 0x11D2, 0x9B, 0xD2, 0x20, 0x4C, 0x4F, 0x4F, 0x50, 0x20
	};

const IID MediaPlayer_IID_IRadioServerControl =
	{
		0x8E718889, 0x423F, 0x11D2, 0x87, 0x6E, 0x0, 0xA0, 0xC9, 0x8, 0x24, 0x67
	};

const IID MediaPlayer_IID_IServiceProvider =
	{
		0x6D5140C1, 0x7436, 0x11CE, 0x80, 0x34, 0x0, 0xAA, 0x0, 0x60, 0x9, 0xFA
	};

HRESULT CVIFUNC MediaPlayer_NewIDirectControl (const char *server,
                                               int supportMultithreading,
                                               LCID locale, int reserved,
                                               CAObjHandle *objectHandle)
{
	HRESULT __result = S_OK;
	GUID clsid = {0x39A2C2A6, 0x4778, 0x11D2, 0x9B, 0xDB, 0x20, 0x4C, 0x4F,
	              0x4F, 0x50, 0x20};

	__result = CA_CreateObjectByClassIdEx (&clsid, server,
	                                       &MediaPlayer_IID_IDirectControl,
	                                       supportMultithreading, locale,
	                                       reserved, objectHandle);

	return __result;
}

HRESULT CVIFUNC MediaPlayer_OpenIDirectControl (const char *fileName,
                                                const char *server,
                                                int supportMultithreading,
                                                LCID locale, int reserved,
                                                CAObjHandle *objectHandle)
{
	HRESULT __result = S_OK;
	GUID clsid = {0x39A2C2A6, 0x4778, 0x11D2, 0x9B, 0xDB, 0x20, 0x4C, 0x4F,
	              0x4F, 0x50, 0x20};

	__result = CA_LoadObjectFromFileByClassIdEx (fileName, &clsid, server,
	                                             &MediaPlayer_IID_IDirectControl,
	                                             supportMultithreading, locale,
	                                             reserved, objectHandle);

	return __result;
}

HRESULT CVIFUNC MediaPlayer_ActiveIDirectControl (const char *server,
                                                  int supportMultithreading,
                                                  LCID locale, int reserved,
                                                  CAObjHandle *objectHandle)
{
	HRESULT __result = S_OK;
	GUID clsid = {0x39A2C2A6, 0x4778, 0x11D2, 0x9B, 0xDB, 0x20, 0x4C, 0x4F,
	              0x4F, 0x50, 0x20};

	__result = CA_GetActiveObjectByClassIdEx (&clsid, server,
	                                          &MediaPlayer_IID_IDirectControl,
	                                          supportMultithreading, locale,
	                                          reserved, objectHandle);

	return __result;
}

HRESULT CVIFUNC MediaPlayer_IDirectControlCreateView (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      const char *bszClsid)
{
	HRESULT __result = S_OK;
	MediaPlayer_IDirectControl_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR bszClsid__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (bszClsid, &bszClsid__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IDirectControl,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->CreateView_ (__vtblIFacePtr,
	                                                 bszClsid__AutoType));

Error:
	CA_FreeBSTR (bszClsid__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IDirectControl,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IDirectControlDestroyAllViews (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	MediaPlayer_IDirectControl_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IDirectControl,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->DestroyAllViews_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IDirectControl,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_NewIDirectContainer (const char *server,
                                                 int supportMultithreading,
                                                 LCID locale, int reserved,
                                                 CAObjHandle *objectHandle)
{
	HRESULT __result = S_OK;
	GUID clsid = {0x39A2C2A9, 0x4778, 0x11D2, 0x9B, 0xDB, 0x20, 0x4C, 0x4F,
	              0x4F, 0x50, 0x20};

	__result = CA_CreateObjectByClassIdEx (&clsid, server,
	                                       &MediaPlayer_IID_IDirectContainer,
	                                       supportMultithreading, locale,
	                                       reserved, objectHandle);

	return __result;
}

HRESULT CVIFUNC MediaPlayer_OpenIDirectContainer (const char *fileName,
                                                  const char *server,
                                                  int supportMultithreading,
                                                  LCID locale, int reserved,
                                                  CAObjHandle *objectHandle)
{
	HRESULT __result = S_OK;
	GUID clsid = {0x39A2C2A9, 0x4778, 0x11D2, 0x9B, 0xDB, 0x20, 0x4C, 0x4F,
	              0x4F, 0x50, 0x20};

	__result = CA_LoadObjectFromFileByClassIdEx (fileName, &clsid, server,
	                                             &MediaPlayer_IID_IDirectContainer,
	                                             supportMultithreading, locale,
	                                             reserved, objectHandle);

	return __result;
}

HRESULT CVIFUNC MediaPlayer_ActiveIDirectContainer (const char *server,
                                                    int supportMultithreading,
                                                    LCID locale, int reserved,
                                                    CAObjHandle *objectHandle)
{
	HRESULT __result = S_OK;
	GUID clsid = {0x39A2C2A9, 0x4778, 0x11D2, 0x9B, 0xDB, 0x20, 0x4C, 0x4F,
	              0x4F, 0x50, 0x20};

	__result = CA_GetActiveObjectByClassIdEx (&clsid, server,
	                                          &MediaPlayer_IID_IDirectContainer,
	                                          supportMultithreading, locale,
	                                          reserved, objectHandle);

	return __result;
}

HRESULT CVIFUNC MediaPlayer_IDirectContainerCreateControl (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           const char *bszClsid,
                                                           unsigned long dwClsContext,
                                                           CAObjHandle *ppunk,
                                                           unsigned long dwWindowStyle)
{
	HRESULT __result = S_OK;
	MediaPlayer_IDirectContainer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR bszClsid__AutoType = 0;
	LPUNKNOWN  ppunk__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (bszClsid, &bszClsid__AutoType));
	if (ppunk)
		{
		__caErrChk (CA_GetInterfaceFromObjHandle (*ppunk, &IID_IUnknown, 1,
	                                          &ppunk__AutoType, NULL));
		}

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IDirectContainer,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->CreateControl_ (__vtblIFacePtr,
	                                                    bszClsid__AutoType,
	                                                    dwClsContext,
	                                                    &ppunk__AutoType,
	                                                    dwWindowStyle));

Error:
	CA_FreeBSTR (bszClsid__AutoType);
	if (ppunk__AutoType)
		ppunk__AutoType->lpVtbl->Release (ppunk__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IDirectContainer,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IDirectContainerSetServiceProvider (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                MediaPlayerObj_IServiceProvider pspSet)
{
	HRESULT __result = S_OK;
	MediaPlayer_IDirectContainer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	LPUNKNOWN pspSet__AutoType = 0;

	if (pspSet)
		{
		__caErrChk (CA_GetInterfaceFromObjHandle (pspSet,
	                                          &MediaPlayer_IID_IServiceProvider,
	                                          1, &pspSet__AutoType, NULL));
		}

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IDirectContainer,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetServiceProvider_ (__vtblIFacePtr,
	                                                         pspSet__AutoType));

Error:
	if (pspSet__AutoType)
		pspSet__AutoType->lpVtbl->Release (pspSet__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IDirectContainer,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IDirectContainerSetIInputObjectSite (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 CAObjHandle pios)
{
	HRESULT __result = S_OK;
	MediaPlayer_IDirectContainer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	LPUNKNOWN pios__AutoType = 0;

	if (pios)
		{
		__caErrChk (CA_GetInterfaceFromObjHandle (pios, &IID_IUnknown, 1,
	                                          &pios__AutoType, NULL));
		}

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IDirectContainer,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetIInputObjectSite_ (__vtblIFacePtr,
	                                                          pios__AutoType));

Error:
	if (pios__AutoType)
		pios__AutoType->lpVtbl->Release (pios__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IDirectContainer,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IDirectContainerShowControl (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	MediaPlayer_IDirectContainer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IDirectContainer,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->ShowControl_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IDirectContainer,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IDirectContainerHideControl (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	MediaPlayer_IDirectContainer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IDirectContainer,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->HideControl_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IDirectContainer,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IDirectContainerIsControlCreated (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	MediaPlayer_IDirectContainer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IDirectContainer,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->IsControlCreated_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IDirectContainer,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IDirectContainerDestroyControl (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	MediaPlayer_IDirectContainer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IDirectContainer,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->DestroyControl_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IDirectContainer,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_NewIMediaPlayer2 (const char *server,
                                              int supportMultithreading,
                                              LCID locale, int reserved,
                                              CAObjHandle *objectHandle)
{
	HRESULT __result = S_OK;
	GUID clsid = {0x22D6F312, 0xB0F6, 0x11D0, 0x94, 0xAB, 0x0, 0x80, 0xC7,
	              0x4C, 0x7E, 0x95};

	__result = CA_CreateObjectByClassIdEx (&clsid, server,
	                                       &MediaPlayer_IID_IMediaPlayer2,
	                                       supportMultithreading, locale,
	                                       reserved, objectHandle);

	return __result;
}

HRESULT CVIFUNC MediaPlayer_OpenIMediaPlayer2 (const char *fileName,
                                               const char *server,
                                               int supportMultithreading,
                                               LCID locale, int reserved,
                                               CAObjHandle *objectHandle)
{
	HRESULT __result = S_OK;
	GUID clsid = {0x22D6F312, 0xB0F6, 0x11D0, 0x94, 0xAB, 0x0, 0x80, 0xC7,
	              0x4C, 0x7E, 0x95};

	__result = CA_LoadObjectFromFileByClassIdEx (fileName, &clsid, server,
	                                             &MediaPlayer_IID_IMediaPlayer2,
	                                             supportMultithreading, locale,
	                                             reserved, objectHandle);

	return __result;
}

HRESULT CVIFUNC MediaPlayer_ActiveIMediaPlayer2 (const char *server,
                                                 int supportMultithreading,
                                                 LCID locale, int reserved,
                                                 CAObjHandle *objectHandle)
{
	HRESULT __result = S_OK;
	GUID clsid = {0x22D6F312, 0xB0F6, 0x11D0, 0x94, 0xAB, 0x0, 0x80, 0xC7,
	              0x4C, 0x7E, 0x95};

	__result = CA_GetActiveObjectByClassIdEx (&clsid, server,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          supportMultithreading, locale,
	                                          reserved, objectHandle);

	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetCurrentPosition (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             double *pCurrentPosition)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	double pCurrentPosition__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCurrentPosition_ (__vtblIFacePtr,
	                                                         &pCurrentPosition__Temp));

	if (pCurrentPosition)
		{
		*pCurrentPosition = pCurrentPosition__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetCurrentPosition (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             double pCurrentPosition)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCurrentPosition_ (__vtblIFacePtr,
	                                                         pCurrentPosition));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetDuration (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      double *pDuration)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	double pDuration__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetDuration_ (__vtblIFacePtr,
	                                                  &pDuration__Temp));

	if (pDuration)
		{
		*pDuration = pDuration__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetImageSourceWidth (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              long *pWidth)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pWidth__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetImageSourceWidth_ (__vtblIFacePtr,
	                                                          &pWidth__Temp));

	if (pWidth)
		{
		*pWidth = pWidth__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetImageSourceHeight (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               long *pHeight)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pHeight__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetImageSourceHeight_ (__vtblIFacePtr,
	                                                           &pHeight__Temp));

	if (pHeight)
		{
		*pHeight = pHeight__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetMarkerCount (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         long *pMarkerCount)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pMarkerCount__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetMarkerCount_ (__vtblIFacePtr,
	                                                     &pMarkerCount__Temp));

	if (pMarkerCount)
		{
		*pMarkerCount = pMarkerCount__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetCanScan (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL *pCanScan)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pCanScan__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCanScan_ (__vtblIFacePtr,
	                                                 &pCanScan__Temp));

	if (pCanScan)
		{
		*pCanScan = pCanScan__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetCanSeek (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL *pCanSeek)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pCanSeek__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCanSeek_ (__vtblIFacePtr,
	                                                 &pCanSeek__Temp));

	if (pCanSeek)
		{
		*pCanSeek = pCanSeek__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetCanSeekToMarkers (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              VBOOL *pCanSeekToMarkers)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pCanSeekToMarkers__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCanSeekToMarkers_ (__vtblIFacePtr,
	                                                          &pCanSeekToMarkers__Temp));

	if (pCanSeekToMarkers)
		{
		*pCanSeekToMarkers = pCanSeekToMarkers__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetCurrentMarker (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           long *pCurrentMarker)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pCurrentMarker__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCurrentMarker_ (__vtblIFacePtr,
	                                                       &pCurrentMarker__Temp));

	if (pCurrentMarker)
		{
		*pCurrentMarker = pCurrentMarker__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetCurrentMarker (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           long pCurrentMarker)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCurrentMarker_ (__vtblIFacePtr,
	                                                       pCurrentMarker));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetFileName (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      char **pbstrFileName)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrFileName__AutoType = 0;

	if (pbstrFileName)
		*pbstrFileName = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetFileName_ (__vtblIFacePtr,
	                                                  &pbstrFileName__AutoType));

	if (pbstrFileName)
		__caErrChk (CA_BSTRGetCString (pbstrFileName__AutoType, pbstrFileName));

Error:
	CA_FreeBSTR (pbstrFileName__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pbstrFileName)
			{
			CA_FreeMemory (*pbstrFileName);
			*pbstrFileName = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetFileName (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      const char *pbstrFileName)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrFileName__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (pbstrFileName, &pbstrFileName__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetFileName_ (__vtblIFacePtr,
	                                                  pbstrFileName__AutoType));

Error:
	CA_FreeBSTR (pbstrFileName__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetSourceLink (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        char **pbstrSourceLink)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrSourceLink__AutoType = 0;

	if (pbstrSourceLink)
		*pbstrSourceLink = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetSourceLink_ (__vtblIFacePtr,
	                                                    &pbstrSourceLink__AutoType));

	if (pbstrSourceLink)
		__caErrChk (CA_BSTRGetCString (pbstrSourceLink__AutoType, pbstrSourceLink));

Error:
	CA_FreeBSTR (pbstrSourceLink__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pbstrSourceLink)
			{
			CA_FreeMemory (*pbstrSourceLink);
			*pbstrSourceLink = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetCreationDate (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          DATE *pCreationDate)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	DATE pCreationDate__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCreationDate_ (__vtblIFacePtr,
	                                                      &pCreationDate__Temp));

	if (pCreationDate)
		{
		*pCreationDate = pCreationDate__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetErrorCorrection (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             char **pbstrErrorCorrection)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrErrorCorrection__AutoType = 0;

	if (pbstrErrorCorrection)
		*pbstrErrorCorrection = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetErrorCorrection_ (__vtblIFacePtr,
	                                                         &pbstrErrorCorrection__AutoType));

	if (pbstrErrorCorrection)
		__caErrChk (CA_BSTRGetCString (pbstrErrorCorrection__AutoType,
	                               pbstrErrorCorrection));

Error:
	CA_FreeBSTR (pbstrErrorCorrection__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pbstrErrorCorrection)
			{
			CA_FreeMemory (*pbstrErrorCorrection);
			*pbstrErrorCorrection = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetBandwidth (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long *pBandwidth)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pBandwidth__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetBandwidth_ (__vtblIFacePtr,
	                                                   &pBandwidth__Temp));

	if (pBandwidth)
		{
		*pBandwidth = pBandwidth__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetSourceProtocol (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            long *pSourceProtocol)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pSourceProtocol__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetSourceProtocol_ (__vtblIFacePtr,
	                                                        &pSourceProtocol__Temp));

	if (pSourceProtocol)
		{
		*pSourceProtocol = pSourceProtocol__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetReceivedPackets (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             long *pReceivedPackets)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pReceivedPackets__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetReceivedPackets_ (__vtblIFacePtr,
	                                                         &pReceivedPackets__Temp));

	if (pReceivedPackets)
		{
		*pReceivedPackets = pReceivedPackets__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetRecoveredPackets (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              long *pRecoveredPackets)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pRecoveredPackets__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetRecoveredPackets_ (__vtblIFacePtr,
	                                                          &pRecoveredPackets__Temp));

	if (pRecoveredPackets)
		{
		*pRecoveredPackets = pRecoveredPackets__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetLostPackets (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         long *pLostPackets)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pLostPackets__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetLostPackets_ (__vtblIFacePtr,
	                                                     &pLostPackets__Temp));

	if (pLostPackets)
		{
		*pLostPackets = pLostPackets__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetReceptionQuality (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              long *pReceptionQuality)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pReceptionQuality__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetReceptionQuality_ (__vtblIFacePtr,
	                                                          &pReceptionQuality__Temp));

	if (pReceptionQuality)
		{
		*pReceptionQuality = pReceptionQuality__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetBufferingCount (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            long *pBufferingCount)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pBufferingCount__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetBufferingCount_ (__vtblIFacePtr,
	                                                        &pBufferingCount__Temp));

	if (pBufferingCount)
		{
		*pBufferingCount = pBufferingCount__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetIsBroadcast (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL *pIsBroadcast)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pIsBroadcast__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetIsBroadcast_ (__vtblIFacePtr,
	                                                     &pIsBroadcast__Temp));

	if (pIsBroadcast)
		{
		*pIsBroadcast = pIsBroadcast__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetBufferingProgress (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               long *pBufferingProgress)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pBufferingProgress__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetBufferingProgress_ (__vtblIFacePtr,
	                                                           &pBufferingProgress__Temp));

	if (pBufferingProgress)
		{
		*pBufferingProgress = pBufferingProgress__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetChannelName (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         char **pbstrChannelName)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrChannelName__AutoType = 0;

	if (pbstrChannelName)
		*pbstrChannelName = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetChannelName_ (__vtblIFacePtr,
	                                                     &pbstrChannelName__AutoType));

	if (pbstrChannelName)
		__caErrChk (CA_BSTRGetCString (pbstrChannelName__AutoType,
	                               pbstrChannelName));

Error:
	CA_FreeBSTR (pbstrChannelName__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pbstrChannelName)
			{
			CA_FreeMemory (*pbstrChannelName);
			*pbstrChannelName = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetChannelDescription (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                char **pbstrChannelDescription)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrChannelDescription__AutoType = 0;

	if (pbstrChannelDescription)
		*pbstrChannelDescription = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetChannelDescription_ (__vtblIFacePtr,
	                                                            &pbstrChannelDescription__AutoType));

	if (pbstrChannelDescription)
		__caErrChk (CA_BSTRGetCString (pbstrChannelDescription__AutoType,
	                               pbstrChannelDescription));

Error:
	CA_FreeBSTR (pbstrChannelDescription__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pbstrChannelDescription)
			{
			CA_FreeMemory (*pbstrChannelDescription);
			*pbstrChannelDescription = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetChannelURL (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        char **pbstrChannelURL)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrChannelURL__AutoType = 0;

	if (pbstrChannelURL)
		*pbstrChannelURL = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetChannelURL_ (__vtblIFacePtr,
	                                                    &pbstrChannelURL__AutoType));

	if (pbstrChannelURL)
		__caErrChk (CA_BSTRGetCString (pbstrChannelURL__AutoType, pbstrChannelURL));

Error:
	CA_FreeBSTR (pbstrChannelURL__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pbstrChannelURL)
			{
			CA_FreeMemory (*pbstrChannelURL);
			*pbstrChannelURL = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetContactAddress (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            char **pbstrContactAddress)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrContactAddress__AutoType = 0;

	if (pbstrContactAddress)
		*pbstrContactAddress = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetContactAddress_ (__vtblIFacePtr,
	                                                        &pbstrContactAddress__AutoType));

	if (pbstrContactAddress)
		__caErrChk (CA_BSTRGetCString (pbstrContactAddress__AutoType,
	                               pbstrContactAddress));

Error:
	CA_FreeBSTR (pbstrContactAddress__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pbstrContactAddress)
			{
			CA_FreeMemory (*pbstrContactAddress);
			*pbstrContactAddress = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetContactPhone (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          char **pbstrContactPhone)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrContactPhone__AutoType = 0;

	if (pbstrContactPhone)
		*pbstrContactPhone = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetContactPhone_ (__vtblIFacePtr,
	                                                      &pbstrContactPhone__AutoType));

	if (pbstrContactPhone)
		__caErrChk (CA_BSTRGetCString (pbstrContactPhone__AutoType,
	                               pbstrContactPhone));

Error:
	CA_FreeBSTR (pbstrContactPhone__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pbstrContactPhone)
			{
			CA_FreeMemory (*pbstrContactPhone);
			*pbstrContactPhone = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetContactEmail (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          char **pbstrContactEmail)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrContactEmail__AutoType = 0;

	if (pbstrContactEmail)
		*pbstrContactEmail = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetContactEmail_ (__vtblIFacePtr,
	                                                      &pbstrContactEmail__AutoType));

	if (pbstrContactEmail)
		__caErrChk (CA_BSTRGetCString (pbstrContactEmail__AutoType,
	                               pbstrContactEmail));

Error:
	CA_FreeBSTR (pbstrContactEmail__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pbstrContactEmail)
			{
			CA_FreeMemory (*pbstrContactEmail);
			*pbstrContactEmail = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetBufferingTime (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           double *pBufferingTime)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	double pBufferingTime__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetBufferingTime_ (__vtblIFacePtr,
	                                                       &pBufferingTime__Temp));

	if (pBufferingTime)
		{
		*pBufferingTime = pBufferingTime__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetBufferingTime (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           double pBufferingTime)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetBufferingTime_ (__vtblIFacePtr,
	                                                       pBufferingTime));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetAutoStart (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL *pAutoStart)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pAutoStart__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetAutoStart_ (__vtblIFacePtr,
	                                                   &pAutoStart__Temp));

	if (pAutoStart)
		{
		*pAutoStart = pAutoStart__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetAutoStart (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL pAutoStart)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetAutoStart_ (__vtblIFacePtr,
	                                                   pAutoStart));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetAutoRewind (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *pAutoRewind)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pAutoRewind__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetAutoRewind_ (__vtblIFacePtr,
	                                                    &pAutoRewind__Temp));

	if (pAutoRewind)
		{
		*pAutoRewind = pAutoRewind__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetAutoRewind (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL pAutoRewind)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetAutoRewind_ (__vtblIFacePtr,
	                                                    pAutoRewind));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetRate (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  double *pRate)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	double pRate__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetRate_ (__vtblIFacePtr, &pRate__Temp));

	if (pRate)
		{
		*pRate = pRate__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetRate (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  double pRate)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetRate_ (__vtblIFacePtr, pRate));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetSendKeyboardEvents (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                VBOOL *pSendKeyboardEvents)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pSendKeyboardEvents__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetSendKeyboardEvents_ (__vtblIFacePtr,
	                                                            &pSendKeyboardEvents__Temp));

	if (pSendKeyboardEvents)
		{
		*pSendKeyboardEvents = pSendKeyboardEvents__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetSendKeyboardEvents (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                VBOOL pSendKeyboardEvents)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetSendKeyboardEvents_ (__vtblIFacePtr,
	                                                            pSendKeyboardEvents));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetSendMouseClickEvents (CAObjHandle objectHandle,
                                                                  ERRORINFO *errorInfo,
                                                                  VBOOL *pSendMouseClickEvents)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pSendMouseClickEvents__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetSendMouseClickEvents_ (__vtblIFacePtr,
	                                                              &pSendMouseClickEvents__Temp));

	if (pSendMouseClickEvents)
		{
		*pSendMouseClickEvents = pSendMouseClickEvents__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetSendMouseClickEvents (CAObjHandle objectHandle,
                                                                  ERRORINFO *errorInfo,
                                                                  VBOOL pSendMouseClickEvents)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetSendMouseClickEvents_ (__vtblIFacePtr,
	                                                              pSendMouseClickEvents));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetSendMouseMoveEvents (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 VBOOL *pSendMouseMoveEvents)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pSendMouseMoveEvents__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetSendMouseMoveEvents_ (__vtblIFacePtr,
	                                                             &pSendMouseMoveEvents__Temp));

	if (pSendMouseMoveEvents)
		{
		*pSendMouseMoveEvents = pSendMouseMoveEvents__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetSendMouseMoveEvents (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 VBOOL pSendMouseMoveEvents)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetSendMouseMoveEvents_ (__vtblIFacePtr,
	                                                             pSendMouseMoveEvents));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetPlayCount (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long *pPlayCount)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pPlayCount__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPlayCount_ (__vtblIFacePtr,
	                                                   &pPlayCount__Temp));

	if (pPlayCount)
		{
		*pPlayCount = pPlayCount__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetPlayCount (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long pPlayCount)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetPlayCount_ (__vtblIFacePtr,
	                                                   pPlayCount));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetClickToPlay (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL *pClickToPlay)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pClickToPlay__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetClickToPlay_ (__vtblIFacePtr,
	                                                     &pClickToPlay__Temp));

	if (pClickToPlay)
		{
		*pClickToPlay = pClickToPlay__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetClickToPlay (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL pClickToPlay)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetClickToPlay_ (__vtblIFacePtr,
	                                                     pClickToPlay));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetAllowScan (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL *pAllowScan)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pAllowScan__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetAllowScan_ (__vtblIFacePtr,
	                                                   &pAllowScan__Temp));

	if (pAllowScan)
		{
		*pAllowScan = pAllowScan__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetAllowScan (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL pAllowScan)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetAllowScan_ (__vtblIFacePtr,
	                                                   pAllowScan));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetEnableContextMenu (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               VBOOL *pEnableContextMenu)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pEnableContextMenu__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetEnableContextMenu_ (__vtblIFacePtr,
	                                                           &pEnableContextMenu__Temp));

	if (pEnableContextMenu)
		{
		*pEnableContextMenu = pEnableContextMenu__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetEnableContextMenu (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               VBOOL pEnableContextMenu)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetEnableContextMenu_ (__vtblIFacePtr,
	                                                           pEnableContextMenu));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetCursorType (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        long *pCursorType)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pCursorType__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCursorType_ (__vtblIFacePtr,
	                                                    &pCursorType__Temp));

	if (pCursorType)
		{
		*pCursorType = pCursorType__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetCursorType (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        long pCursorType)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCursorType_ (__vtblIFacePtr,
	                                                    pCursorType));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetCodecCount (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        long *pCodecCount)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pCodecCount__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCodecCount_ (__vtblIFacePtr,
	                                                    &pCodecCount__Temp));

	if (pCodecCount)
		{
		*pCodecCount = pCodecCount__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetAllowChangeDisplaySize (CAObjHandle objectHandle,
                                                                    ERRORINFO *errorInfo,
                                                                    VBOOL *pAllowChangeDisplaySize)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pAllowChangeDisplaySize__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetAllowChangeDisplaySize_ (__vtblIFacePtr,
	                                                                &pAllowChangeDisplaySize__Temp));

	if (pAllowChangeDisplaySize)
		{
		*pAllowChangeDisplaySize = pAllowChangeDisplaySize__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetAllowChangeDisplaySize (CAObjHandle objectHandle,
                                                                    ERRORINFO *errorInfo,
                                                                    VBOOL pAllowChangeDisplaySize)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetAllowChangeDisplaySize_ (__vtblIFacePtr,
	                                                                pAllowChangeDisplaySize));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetIsDurationValid (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL *pIsDurationValid)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pIsDurationValid__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetIsDurationValid_ (__vtblIFacePtr,
	                                                         &pIsDurationValid__Temp));

	if (pIsDurationValid)
		{
		*pIsDurationValid = pIsDurationValid__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetOpenState (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long *pOpenState)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pOpenState__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetOpenState_ (__vtblIFacePtr,
	                                                   &pOpenState__Temp));

	if (pOpenState)
		{
		*pOpenState = pOpenState__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetSendOpenStateChangeEvents (CAObjHandle objectHandle,
                                                                       ERRORINFO *errorInfo,
                                                                       VBOOL *pSendOpenStateChangeEvents)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pSendOpenStateChangeEvents__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetSendOpenStateChangeEvents_ (__vtblIFacePtr,
	                                                                   &pSendOpenStateChangeEvents__Temp));

	if (pSendOpenStateChangeEvents)
		{
		*pSendOpenStateChangeEvents = pSendOpenStateChangeEvents__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetSendOpenStateChangeEvents (CAObjHandle objectHandle,
                                                                       ERRORINFO *errorInfo,
                                                                       VBOOL pSendOpenStateChangeEvents)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetSendOpenStateChangeEvents_ (__vtblIFacePtr,
	                                                                   pSendOpenStateChangeEvents));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetSendWarningEvents (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               VBOOL *pSendWarningEvents)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pSendWarningEvents__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetSendWarningEvents_ (__vtblIFacePtr,
	                                                           &pSendWarningEvents__Temp));

	if (pSendWarningEvents)
		{
		*pSendWarningEvents = pSendWarningEvents__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetSendWarningEvents (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               VBOOL pSendWarningEvents)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetSendWarningEvents_ (__vtblIFacePtr,
	                                                           pSendWarningEvents));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetSendErrorEvents (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL *pSendErrorEvents)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pSendErrorEvents__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetSendErrorEvents_ (__vtblIFacePtr,
	                                                         &pSendErrorEvents__Temp));

	if (pSendErrorEvents)
		{
		*pSendErrorEvents = pSendErrorEvents__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetSendErrorEvents (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL pSendErrorEvents)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetSendErrorEvents_ (__vtblIFacePtr,
	                                                         pSendErrorEvents));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetPlayState (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       enum MediaPlayerEnum_MPPlayStateConstants *pPlayState)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pPlayState__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPlayState_ (__vtblIFacePtr,
	                                                   (long *)&pPlayState__Temp));

	if (pPlayState)
		{
		*pPlayState = pPlayState__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetSendPlayStateChangeEvents (CAObjHandle objectHandle,
                                                                       ERRORINFO *errorInfo,
                                                                       VBOOL *pSendPlayStateChangeEvents)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pSendPlayStateChangeEvents__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetSendPlayStateChangeEvents_ (__vtblIFacePtr,
	                                                                   &pSendPlayStateChangeEvents__Temp));

	if (pSendPlayStateChangeEvents)
		{
		*pSendPlayStateChangeEvents = pSendPlayStateChangeEvents__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetSendPlayStateChangeEvents (CAObjHandle objectHandle,
                                                                       ERRORINFO *errorInfo,
                                                                       VBOOL pSendPlayStateChangeEvents)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetSendPlayStateChangeEvents_ (__vtblIFacePtr,
	                                                                   pSendPlayStateChangeEvents));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetDisplaySize (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         enum MediaPlayerEnum_MPDisplaySizeConstants *pDisplaySize)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pDisplaySize__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetDisplaySize_ (__vtblIFacePtr,
	                                                     (long *)&pDisplaySize__Temp));

	if (pDisplaySize)
		{
		*pDisplaySize = pDisplaySize__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetDisplaySize (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         enum MediaPlayerEnum_MPDisplaySizeConstants pDisplaySize)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetDisplaySize_ (__vtblIFacePtr,
	                                                     pDisplaySize));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetInvokeURLs (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *pInvokeURLs)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pInvokeURLs__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetInvokeURLs_ (__vtblIFacePtr,
	                                                    &pInvokeURLs__Temp));

	if (pInvokeURLs)
		{
		*pInvokeURLs = pInvokeURLs__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetInvokeURLs (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL pInvokeURLs)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetInvokeURLs_ (__vtblIFacePtr,
	                                                    pInvokeURLs));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetBaseURL (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     char **pbstrBaseURL)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrBaseURL__AutoType = 0;

	if (pbstrBaseURL)
		*pbstrBaseURL = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetBaseURL_ (__vtblIFacePtr,
	                                                 &pbstrBaseURL__AutoType));

	if (pbstrBaseURL)
		__caErrChk (CA_BSTRGetCString (pbstrBaseURL__AutoType, pbstrBaseURL));

Error:
	CA_FreeBSTR (pbstrBaseURL__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pbstrBaseURL)
			{
			CA_FreeMemory (*pbstrBaseURL);
			*pbstrBaseURL = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetBaseURL (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     const char *pbstrBaseURL)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrBaseURL__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (pbstrBaseURL, &pbstrBaseURL__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetBaseURL_ (__vtblIFacePtr,
	                                                 pbstrBaseURL__AutoType));

Error:
	CA_FreeBSTR (pbstrBaseURL__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetDefaultFrame (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          char **pbstrDefaultFrame)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrDefaultFrame__AutoType = 0;

	if (pbstrDefaultFrame)
		*pbstrDefaultFrame = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetDefaultFrame_ (__vtblIFacePtr,
	                                                      &pbstrDefaultFrame__AutoType));

	if (pbstrDefaultFrame)
		__caErrChk (CA_BSTRGetCString (pbstrDefaultFrame__AutoType,
	                               pbstrDefaultFrame));

Error:
	CA_FreeBSTR (pbstrDefaultFrame__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pbstrDefaultFrame)
			{
			CA_FreeMemory (*pbstrDefaultFrame);
			*pbstrDefaultFrame = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetDefaultFrame (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          const char *pbstrDefaultFrame)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrDefaultFrame__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (pbstrDefaultFrame,
	                              &pbstrDefaultFrame__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetDefaultFrame_ (__vtblIFacePtr,
	                                                      pbstrDefaultFrame__AutoType));

Error:
	CA_FreeBSTR (pbstrDefaultFrame__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetHasError (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *pHasError)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pHasError__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetHasError_ (__vtblIFacePtr,
	                                                  &pHasError__Temp));

	if (pHasError)
		{
		*pHasError = pHasError__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetErrorDescription (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              char **pbstrErrorDescription)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrErrorDescription__AutoType = 0;

	if (pbstrErrorDescription)
		*pbstrErrorDescription = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetErrorDescription_ (__vtblIFacePtr,
	                                                          &pbstrErrorDescription__AutoType));

	if (pbstrErrorDescription)
		__caErrChk (CA_BSTRGetCString (pbstrErrorDescription__AutoType,
	                               pbstrErrorDescription));

Error:
	CA_FreeBSTR (pbstrErrorDescription__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pbstrErrorDescription)
			{
			CA_FreeMemory (*pbstrErrorDescription);
			*pbstrErrorDescription = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetErrorCode (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long *pErrorCode)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pErrorCode__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetErrorCode_ (__vtblIFacePtr,
	                                                   &pErrorCode__Temp));

	if (pErrorCode)
		{
		*pErrorCode = pErrorCode__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetAnimationAtStart (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              VBOOL *pAnimationAtStart)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pAnimationAtStart__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetAnimationAtStart_ (__vtblIFacePtr,
	                                                          &pAnimationAtStart__Temp));

	if (pAnimationAtStart)
		{
		*pAnimationAtStart = pAnimationAtStart__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetAnimationAtStart (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              VBOOL pAnimationAtStart)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetAnimationAtStart_ (__vtblIFacePtr,
	                                                          pAnimationAtStart));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetTransparentAtStart (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                VBOOL *pTransparentAtStart)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pTransparentAtStart__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetTransparentAtStart_ (__vtblIFacePtr,
	                                                            &pTransparentAtStart__Temp));

	if (pTransparentAtStart)
		{
		*pTransparentAtStart = pTransparentAtStart__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetTransparentAtStart (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                VBOOL pTransparentAtStart)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetTransparentAtStart_ (__vtblIFacePtr,
	                                                            pTransparentAtStart));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetVolume (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long *pVolume)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pVolume__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetVolume_ (__vtblIFacePtr,
	                                                &pVolume__Temp));

	if (pVolume)
		{
		*pVolume = pVolume__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetVolume (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long pVolume)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetVolume_ (__vtblIFacePtr, pVolume));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetBalance (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long *pBalance)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pBalance__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetBalance_ (__vtblIFacePtr,
	                                                 &pBalance__Temp));

	if (pBalance)
		{
		*pBalance = pBalance__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetBalance (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long pBalance)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetBalance_ (__vtblIFacePtr, pBalance));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetReadyState (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        enum MediaPlayerEnum_MPReadyStateConstants *pValue)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pValue__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetReadyState_ (__vtblIFacePtr,
	                                                    (long *)&pValue__Temp));

	if (pValue)
		{
		*pValue = pValue__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetSelectionStart (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            double *pValue)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	double pValue__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetSelectionStart_ (__vtblIFacePtr,
	                                                        &pValue__Temp));

	if (pValue)
		{
		*pValue = pValue__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetSelectionStart (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            double pValue)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetSelectionStart_ (__vtblIFacePtr,
	                                                        pValue));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetSelectionEnd (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          double *pValue)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	double pValue__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetSelectionEnd_ (__vtblIFacePtr,
	                                                      &pValue__Temp));

	if (pValue)
		{
		*pValue = pValue__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetSelectionEnd (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          double pValue)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetSelectionEnd_ (__vtblIFacePtr,
	                                                      pValue));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetShowDisplay (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL *show)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL show__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetShowDisplay_ (__vtblIFacePtr,
	                                                     &show__Temp));

	if (show)
		{
		*show = show__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetShowDisplay (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL show)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetShowDisplay_ (__vtblIFacePtr, show));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetShowControls (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL *show)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL show__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetShowControls_ (__vtblIFacePtr,
	                                                      &show__Temp));

	if (show)
		{
		*show = show__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetShowControls (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL show)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetShowControls_ (__vtblIFacePtr, show));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetShowPositionControls (CAObjHandle objectHandle,
                                                                  ERRORINFO *errorInfo,
                                                                  VBOOL *show)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL show__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetShowPositionControls_ (__vtblIFacePtr,
	                                                              &show__Temp));

	if (show)
		{
		*show = show__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetShowPositionControls (CAObjHandle objectHandle,
                                                                  ERRORINFO *errorInfo,
                                                                  VBOOL show)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetShowPositionControls_ (__vtblIFacePtr,
	                                                              show));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetShowTracker (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL *show)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL show__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetShowTracker_ (__vtblIFacePtr,
	                                                     &show__Temp));

	if (show)
		{
		*show = show__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetShowTracker (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL show)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetShowTracker_ (__vtblIFacePtr, show));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetEnablePositionControls (CAObjHandle objectHandle,
                                                                    ERRORINFO *errorInfo,
                                                                    VBOOL *enable)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL enable__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetEnablePositionControls_ (__vtblIFacePtr,
	                                                                &enable__Temp));

	if (enable)
		{
		*enable = enable__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetEnablePositionControls (CAObjHandle objectHandle,
                                                                    ERRORINFO *errorInfo,
                                                                    VBOOL enable)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetEnablePositionControls_ (__vtblIFacePtr,
	                                                                enable));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetEnableTracker (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           VBOOL *enable)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL enable__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetEnableTracker_ (__vtblIFacePtr,
	                                                       &enable__Temp));

	if (enable)
		{
		*enable = enable__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetEnableTracker (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           VBOOL enable)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetEnableTracker_ (__vtblIFacePtr,
	                                                       enable));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetEnabled (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL *pEnabled)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pEnabled__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetEnabled_ (__vtblIFacePtr,
	                                                 &pEnabled__Temp));

	if (pEnabled)
		{
		*pEnabled = pEnabled__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetEnabled (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL pEnabled)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetEnabled_ (__vtblIFacePtr, pEnabled));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetDisplayForeColor (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              MediaPlayerType_VB_OLE_COLOR *foreColor)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	unsigned long foreColor__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetDisplayForeColor_ (__vtblIFacePtr,
	                                                          &foreColor__Temp));

	if (foreColor)
		{
		*foreColor = foreColor__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetDisplayForeColor (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              MediaPlayerType_VB_OLE_COLOR foreColor)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetDisplayForeColor_ (__vtblIFacePtr,
	                                                          foreColor));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetDisplayBackColor (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              MediaPlayerType_VB_OLE_COLOR *backColor)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	unsigned long backColor__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetDisplayBackColor_ (__vtblIFacePtr,
	                                                          &backColor__Temp));

	if (backColor)
		{
		*backColor = backColor__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetDisplayBackColor (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              MediaPlayerType_VB_OLE_COLOR backColor)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetDisplayBackColor_ (__vtblIFacePtr,
	                                                          backColor));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetDisplayMode (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         enum MediaPlayerEnum_MPDisplayModeConstants *pValue)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pValue__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetDisplayMode_ (__vtblIFacePtr,
	                                                     (long *)&pValue__Temp));

	if (pValue)
		{
		*pValue = pValue__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetDisplayMode (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         enum MediaPlayerEnum_MPDisplayModeConstants pValue)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetDisplayMode_ (__vtblIFacePtr,
	                                                     pValue));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetVideoBorder3D (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           VBOOL *pVideoBorderWidth)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pVideoBorderWidth__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetVideoBorder3D_ (__vtblIFacePtr,
	                                                       &pVideoBorderWidth__Temp));

	if (pVideoBorderWidth)
		{
		*pVideoBorderWidth = pVideoBorderWidth__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetVideoBorder3D (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           VBOOL pVideoBorderWidth)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetVideoBorder3D_ (__vtblIFacePtr,
	                                                       pVideoBorderWidth));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetVideoBorderWidth (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              long *pVideoBorderWidth)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pVideoBorderWidth__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetVideoBorderWidth_ (__vtblIFacePtr,
	                                                          &pVideoBorderWidth__Temp));

	if (pVideoBorderWidth)
		{
		*pVideoBorderWidth = pVideoBorderWidth__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetVideoBorderWidth (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              long pVideoBorderWidth)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetVideoBorderWidth_ (__vtblIFacePtr,
	                                                          pVideoBorderWidth));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetVideoBorderColor (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              MediaPlayerType_VB_OLE_COLOR *pVideoBorderWidth)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	unsigned long pVideoBorderWidth__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetVideoBorderColor_ (__vtblIFacePtr,
	                                                          &pVideoBorderWidth__Temp));

	if (pVideoBorderWidth)
		{
		*pVideoBorderWidth = pVideoBorderWidth__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetVideoBorderColor (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              MediaPlayerType_VB_OLE_COLOR pVideoBorderWidth)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetVideoBorderColor_ (__vtblIFacePtr,
	                                                          pVideoBorderWidth));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetShowGotoBar (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL *pbool)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pbool__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetShowGotoBar_ (__vtblIFacePtr,
	                                                     &pbool__Temp));

	if (pbool)
		{
		*pbool = pbool__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetShowGotoBar (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL pbool)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetShowGotoBar_ (__vtblIFacePtr, pbool));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetShowStatusBar (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           VBOOL *pbool)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pbool__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetShowStatusBar_ (__vtblIFacePtr,
	                                                       &pbool__Temp));

	if (pbool)
		{
		*pbool = pbool__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetShowStatusBar (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           VBOOL pbool)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetShowStatusBar_ (__vtblIFacePtr,
	                                                       pbool));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetShowCaptioning (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VBOOL *pbool)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pbool__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetShowCaptioning_ (__vtblIFacePtr,
	                                                        &pbool__Temp));

	if (pbool)
		{
		*pbool = pbool__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetShowCaptioning (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VBOOL pbool)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetShowCaptioning_ (__vtblIFacePtr,
	                                                        pbool));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetShowAudioControls (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               VBOOL *pbool)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pbool__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetShowAudioControls_ (__vtblIFacePtr,
	                                                           &pbool__Temp));

	if (pbool)
		{
		*pbool = pbool__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetShowAudioControls (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               VBOOL pbool)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetShowAudioControls_ (__vtblIFacePtr,
	                                                           pbool));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetCaptioningID (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          char **pstrText)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pstrText__AutoType = 0;

	if (pstrText)
		*pstrText = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCaptioningID_ (__vtblIFacePtr,
	                                                      &pstrText__AutoType));

	if (pstrText)
		__caErrChk (CA_BSTRGetCString (pstrText__AutoType, pstrText));

Error:
	CA_FreeBSTR (pstrText__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pstrText)
			{
			CA_FreeMemory (*pstrText);
			*pstrText = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetCaptioningID (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          const char *pstrText)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pstrText__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (pstrText, &pstrText__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCaptioningID_ (__vtblIFacePtr,
	                                                      pstrText__AutoType));

Error:
	CA_FreeBSTR (pstrText__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetMute (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VBOOL *vbool)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL vbool__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetMute_ (__vtblIFacePtr, &vbool__Temp));

	if (vbool)
		{
		*vbool = vbool__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetMute (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VBOOL vbool)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetMute_ (__vtblIFacePtr, vbool));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetCanPreview (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *pCanPreview)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pCanPreview__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCanPreview_ (__vtblIFacePtr,
	                                                    &pCanPreview__Temp));

	if (pCanPreview)
		{
		*pCanPreview = pCanPreview__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetPreviewMode (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL *pPreviewMode)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pPreviewMode__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPreviewMode_ (__vtblIFacePtr,
	                                                     &pPreviewMode__Temp));

	if (pPreviewMode)
		{
		*pPreviewMode = pPreviewMode__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetPreviewMode (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL pPreviewMode)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetPreviewMode_ (__vtblIFacePtr,
	                                                     pPreviewMode));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetHasMultipleItems (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              VBOOL *pHasMuliItems)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pHasMuliItems__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetHasMultipleItems_ (__vtblIFacePtr,
	                                                          &pHasMuliItems__Temp));

	if (pHasMuliItems)
		{
		*pHasMuliItems = pHasMuliItems__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetLanguage (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long *pLanguage)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pLanguage__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetLanguage_ (__vtblIFacePtr,
	                                                  &pLanguage__Temp));

	if (pLanguage)
		{
		*pLanguage = pLanguage__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetLanguage (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long pLanguage)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetLanguage_ (__vtblIFacePtr,
	                                                  pLanguage));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetAudioStream (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         long *pStream)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pStream__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetAudioStream_ (__vtblIFacePtr,
	                                                     &pStream__Temp));

	if (pStream)
		{
		*pStream = pStream__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetAudioStream (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         long pStream)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetAudioStream_ (__vtblIFacePtr,
	                                                     pStream));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetSAMIStyle (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       char **pbstrStyle)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrStyle__AutoType = 0;

	if (pbstrStyle)
		*pbstrStyle = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetSAMIStyle_ (__vtblIFacePtr,
	                                                   &pbstrStyle__AutoType));

	if (pbstrStyle)
		__caErrChk (CA_BSTRGetCString (pbstrStyle__AutoType, pbstrStyle));

Error:
	CA_FreeBSTR (pbstrStyle__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pbstrStyle)
			{
			CA_FreeMemory (*pbstrStyle);
			*pbstrStyle = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetSAMIStyle (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       const char *pbstrStyle)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrStyle__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (pbstrStyle, &pbstrStyle__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetSAMIStyle_ (__vtblIFacePtr,
	                                                   pbstrStyle__AutoType));

Error:
	CA_FreeBSTR (pbstrStyle__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetSAMILang (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      char **pbstrLang)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrLang__AutoType = 0;

	if (pbstrLang)
		*pbstrLang = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetSAMILang_ (__vtblIFacePtr,
	                                                  &pbstrLang__AutoType));

	if (pbstrLang)
		__caErrChk (CA_BSTRGetCString (pbstrLang__AutoType, pbstrLang));

Error:
	CA_FreeBSTR (pbstrLang__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pbstrLang)
			{
			CA_FreeMemory (*pbstrLang);
			*pbstrLang = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetSAMILang (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      const char *pbstrLang)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrLang__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (pbstrLang, &pbstrLang__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetSAMILang_ (__vtblIFacePtr,
	                                                  pbstrLang__AutoType));

Error:
	CA_FreeBSTR (pbstrLang__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetSAMIFileName (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          char **pbstrFileName)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrFileName__AutoType = 0;

	if (pbstrFileName)
		*pbstrFileName = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetSAMIFileName_ (__vtblIFacePtr,
	                                                      &pbstrFileName__AutoType));

	if (pbstrFileName)
		__caErrChk (CA_BSTRGetCString (pbstrFileName__AutoType, pbstrFileName));

Error:
	CA_FreeBSTR (pbstrFileName__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pbstrFileName)
			{
			CA_FreeMemory (*pbstrFileName);
			*pbstrFileName = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetSAMIFileName (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          const char *pbstrFileName)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrFileName__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (pbstrFileName, &pbstrFileName__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetSAMIFileName_ (__vtblIFacePtr,
	                                                      pbstrFileName__AutoType));

Error:
	CA_FreeBSTR (pbstrFileName__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetStreamCount (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         long *pStreamCount)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pStreamCount__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetStreamCount_ (__vtblIFacePtr,
	                                                     &pStreamCount__Temp));

	if (pStreamCount)
		{
		*pStreamCount = pStreamCount__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetClientId (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      char **pbstrClientId)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrClientId__AutoType = 0;

	if (pbstrClientId)
		*pbstrClientId = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetClientId_ (__vtblIFacePtr,
	                                                  &pbstrClientId__AutoType));

	if (pbstrClientId)
		__caErrChk (CA_BSTRGetCString (pbstrClientId__AutoType, pbstrClientId));

Error:
	CA_FreeBSTR (pbstrClientId__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pbstrClientId)
			{
			CA_FreeMemory (*pbstrClientId);
			*pbstrClientId = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetConnectionSpeed (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             long *plConnectionSpeed)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long plConnectionSpeed__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetConnectionSpeed_ (__vtblIFacePtr,
	                                                         &plConnectionSpeed__Temp));

	if (plConnectionSpeed)
		{
		*plConnectionSpeed = plConnectionSpeed__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetAutoSize (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *pbool)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pbool__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetAutoSize_ (__vtblIFacePtr,
	                                                  &pbool__Temp));

	if (pbool)
		{
		*pbool = pbool__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetAutoSize (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL pbool)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetAutoSize_ (__vtblIFacePtr, pbool));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetEnableFullScreenControls (CAObjHandle objectHandle,
                                                                      ERRORINFO *errorInfo,
                                                                      VBOOL *pbVal)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pbVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetEnableFullScreenControls_ (__vtblIFacePtr,
	                                                                  &pbVal__Temp));

	if (pbVal)
		{
		*pbVal = pbVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetEnableFullScreenControls (CAObjHandle objectHandle,
                                                                      ERRORINFO *errorInfo,
                                                                      VBOOL pbVal)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetEnableFullScreenControls_ (__vtblIFacePtr,
	                                                                  pbVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetActiveMovie (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CAObjHandle *ppdispatch)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	LPDISPATCH ppdispatch__AutoType = 0;
	LCID __locale;
	int __supportMultithreading;

	if (ppdispatch)
		*ppdispatch = 0;

	__caErrChk (CA_GetLocale (objectHandle, &__locale));
	__caErrChk (CA_GetSupportForMultithreading (objectHandle,
	                                            &__supportMultithreading));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetActiveMovie_ (__vtblIFacePtr,
	                                                     &ppdispatch__AutoType));
	

	if (ppdispatch)
		{
		__caErrChk (CA_CreateObjHandleFromInterface (ppdispatch__AutoType,
		                                             &IID_IDispatch,
		                                             __supportMultithreading,
		                                             __locale, 0, 0, ppdispatch));
		ppdispatch__AutoType = 0;
		}

Error:
	if (ppdispatch__AutoType)
		ppdispatch__AutoType->lpVtbl->Release (ppdispatch__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (ppdispatch)
			{
			CA_DiscardObjHandle (*ppdispatch);
			*ppdispatch = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetNSPlay (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    CAObjHandle *ppdispatch)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	LPDISPATCH ppdispatch__AutoType = 0;
	LCID __locale;
	int __supportMultithreading;

	if (ppdispatch)
		*ppdispatch = 0;

	__caErrChk (CA_GetLocale (objectHandle, &__locale));
	__caErrChk (CA_GetSupportForMultithreading (objectHandle,
	                                            &__supportMultithreading));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetNSPlay_ (__vtblIFacePtr,
	                                                &ppdispatch__AutoType));
	

	if (ppdispatch)
		{
		__caErrChk (CA_CreateObjHandleFromInterface (ppdispatch__AutoType,
		                                             &IID_IDispatch,
		                                             __supportMultithreading,
		                                             __locale, 0, 0, ppdispatch));
		ppdispatch__AutoType = 0;
		}

Error:
	if (ppdispatch__AutoType)
		ppdispatch__AutoType->lpVtbl->Release (ppdispatch__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (ppdispatch)
			{
			CA_DiscardObjHandle (*ppdispatch);
			*ppdispatch = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetWindowlessVideo (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL *pbool)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pbool__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetWindowlessVideo_ (__vtblIFacePtr,
	                                                         &pbool__Temp));

	if (pbool)
		{
		*pbool = pbool__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetWindowlessVideo (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL pbool)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetWindowlessVideo_ (__vtblIFacePtr,
	                                                         pbool));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2Play (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->Play_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2Stop (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->Stop_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2Pause (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->Pause_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetMarkerTime (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        long markerNum,
                                                        double *pMarkerTime)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	double pMarkerTime__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetMarkerTime_ (__vtblIFacePtr,
	                                                    markerNum,
	                                                    &pMarkerTime__Temp));

	if (pMarkerTime)
		{
		*pMarkerTime = pMarkerTime__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetMarkerName (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        long markerNum,
                                                        char **pbstrMarkerName)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrMarkerName__AutoType = 0;

	if (pbstrMarkerName)
		*pbstrMarkerName = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetMarkerName_ (__vtblIFacePtr,
	                                                    markerNum,
	                                                    &pbstrMarkerName__AutoType));

	if (pbstrMarkerName)
		__caErrChk (CA_BSTRGetCString (pbstrMarkerName__AutoType, pbstrMarkerName));

Error:
	CA_FreeBSTR (pbstrMarkerName__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pbstrMarkerName)
			{
			CA_FreeMemory (*pbstrMarkerName);
			*pbstrMarkerName = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2AboutBox (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->AboutBox_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetCodecInstalled (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            long codecNum,
                                                            VBOOL *pCodecInstalled)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pCodecInstalled__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCodecInstalled_ (__vtblIFacePtr,
	                                                        codecNum,
	                                                        &pCodecInstalled__Temp));

	if (pCodecInstalled)
		{
		*pCodecInstalled = pCodecInstalled__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetCodecDescription (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              long codecNum,
                                                              char **pbstrCodecDescription)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrCodecDescription__AutoType = 0;

	if (pbstrCodecDescription)
		*pbstrCodecDescription = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCodecDescription_ (__vtblIFacePtr,
	                                                          codecNum,
	                                                          &pbstrCodecDescription__AutoType));

	if (pbstrCodecDescription)
		__caErrChk (CA_BSTRGetCString (pbstrCodecDescription__AutoType,
	                               pbstrCodecDescription));

Error:
	CA_FreeBSTR (pbstrCodecDescription__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pbstrCodecDescription)
			{
			CA_FreeMemory (*pbstrCodecDescription);
			*pbstrCodecDescription = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetCodecURL (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long codecNum,
                                                      char **pbstrCodecURL)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrCodecURL__AutoType = 0;

	if (pbstrCodecURL)
		*pbstrCodecURL = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCodecURL_ (__vtblIFacePtr, codecNum,
	                                                  &pbstrCodecURL__AutoType));

	if (pbstrCodecURL)
		__caErrChk (CA_BSTRGetCString (pbstrCodecURL__AutoType, pbstrCodecURL));

Error:
	CA_FreeBSTR (pbstrCodecURL__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pbstrCodecURL)
			{
			CA_FreeMemory (*pbstrCodecURL);
			*pbstrCodecURL = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetMoreInfoURL (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         enum MediaPlayerEnum_MPMoreInfoType moreInfoType,
                                                         char **pbstrMoreInfoURL)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrMoreInfoURL__AutoType = 0;

	if (pbstrMoreInfoURL)
		*pbstrMoreInfoURL = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetMoreInfoURL_ (__vtblIFacePtr,
	                                                     moreInfoType,
	                                                     &pbstrMoreInfoURL__AutoType));

	if (pbstrMoreInfoURL)
		__caErrChk (CA_BSTRGetCString (pbstrMoreInfoURL__AutoType,
	                               pbstrMoreInfoURL));

Error:
	CA_FreeBSTR (pbstrMoreInfoURL__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pbstrMoreInfoURL)
			{
			CA_FreeMemory (*pbstrMoreInfoURL);
			*pbstrMoreInfoURL = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetMediaInfoString (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             enum MediaPlayerEnum_MPMediaInfoType mediaInfoType,
                                                             char **pbstrMediaInfo)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrMediaInfo__AutoType = 0;

	if (pbstrMediaInfo)
		*pbstrMediaInfo = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetMediaInfoString_ (__vtblIFacePtr,
	                                                         mediaInfoType,
	                                                         &pbstrMediaInfo__AutoType));

	if (pbstrMediaInfo)
		__caErrChk (CA_BSTRGetCString (pbstrMediaInfo__AutoType, pbstrMediaInfo));

Error:
	CA_FreeBSTR (pbstrMediaInfo__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pbstrMediaInfo)
			{
			CA_FreeMemory (*pbstrMediaInfo);
			*pbstrMediaInfo = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2Cancel (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->Cancel_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2Open (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               const char *bstrFileName)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR bstrFileName__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (bstrFileName, &bstrFileName__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->Open_ (__vtblIFacePtr,
	                                           bstrFileName__AutoType));

Error:
	CA_FreeBSTR (bstrFileName__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2IsSoundCardEnabled (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL *pbSoundCard)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pbSoundCard__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->IsSoundCardEnabled_ (__vtblIFacePtr,
	                                                         &pbSoundCard__Temp));

	if (pbSoundCard)
		{
		*pbSoundCard = pbSoundCard__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2Next (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->Next_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2Previous (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->Previous_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2StreamSelect (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long streamNum)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->StreamSelect_ (__vtblIFacePtr,
	                                                   streamNum));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2FastForward (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->FastForward_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2FastReverse (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->FastReverse_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetStreamName (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        long streamNum,
                                                        char **pbstrStreamName)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrStreamName__AutoType = 0;

	if (pbstrStreamName)
		*pbstrStreamName = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetStreamName_ (__vtblIFacePtr,
	                                                    streamNum,
	                                                    &pbstrStreamName__AutoType));

	if (pbstrStreamName)
		__caErrChk (CA_BSTRGetCString (pbstrStreamName__AutoType, pbstrStreamName));

Error:
	CA_FreeBSTR (pbstrStreamName__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pbstrStreamName)
			{
			CA_FreeMemory (*pbstrStreamName);
			*pbstrStreamName = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetStreamGroup (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         long streamNum,
                                                         long *pStreamGroup)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pStreamGroup__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetStreamGroup_ (__vtblIFacePtr,
	                                                     streamNum,
	                                                     &pStreamGroup__Temp));

	if (pStreamGroup)
		{
		*pStreamGroup = pStreamGroup__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetStreamSelected (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            long streamNum,
                                                            VBOOL *pStreamSelected)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pStreamSelected__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetStreamSelected_ (__vtblIFacePtr,
	                                                        streamNum,
	                                                        &pStreamSelected__Temp));

	if (pStreamSelected)
		{
		*pStreamSelected = pStreamSelected__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetDVD (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 MediaPlayerObj_IMediaPlayerDvd *ppdispatch)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	LPDISPATCH ppdispatch__AutoType = 0;
	LCID __locale;
	int __supportMultithreading;

	if (ppdispatch)
		*ppdispatch = 0;

	__caErrChk (CA_GetLocale (objectHandle, &__locale));
	__caErrChk (CA_GetSupportForMultithreading (objectHandle,
	                                            &__supportMultithreading));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetDVD_ (__vtblIFacePtr,
	                                             &ppdispatch__AutoType));
	

	if (ppdispatch)
		{
		__caErrChk (CA_CreateObjHandleFromInterface (ppdispatch__AutoType,
		                                             &MediaPlayer_IID_IMediaPlayerDvd,
		                                             __supportMultithreading,
		                                             __locale, 0, 0, ppdispatch));
		ppdispatch__AutoType = 0;
		}

Error:
	if (ppdispatch__AutoType)
		ppdispatch__AutoType->lpVtbl->Release (ppdispatch__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (ppdispatch)
			{
			CA_DiscardObjHandle (*ppdispatch);
			*ppdispatch = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetMediaParameter (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            long entryNum,
                                                            const char *bstrParameterName,
                                                            char **pbstrParameterValue)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR bstrParameterName__AutoType = 0;
	BSTR pbstrParameterValue__AutoType = 0;

	if (pbstrParameterValue)
		*pbstrParameterValue = 0;

	__caErrChk (CA_CStringToBSTR (bstrParameterName,
	                              &bstrParameterName__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetMediaParameter_ (__vtblIFacePtr,
	                                                        entryNum,
	                                                        bstrParameterName__AutoType,
	                                                        &pbstrParameterValue__AutoType));

	if (pbstrParameterValue)
		__caErrChk (CA_BSTRGetCString (pbstrParameterValue__AutoType,
	                               pbstrParameterValue));

Error:
	CA_FreeBSTR (bstrParameterName__AutoType);
	CA_FreeBSTR (pbstrParameterValue__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pbstrParameterValue)
			{
			CA_FreeMemory (*pbstrParameterValue);
			*pbstrParameterValue = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetMediaParameterName (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                long entryNum,
                                                                long index,
                                                                char **pbstrParameterName)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrParameterName__AutoType = 0;

	if (pbstrParameterName)
		*pbstrParameterName = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetMediaParameterName_ (__vtblIFacePtr,
	                                                            entryNum,
	                                                            index,
	                                                            &pbstrParameterName__AutoType));

	if (pbstrParameterName)
		__caErrChk (CA_BSTRGetCString (pbstrParameterName__AutoType,
	                               pbstrParameterName));

Error:
	CA_FreeBSTR (pbstrParameterName__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pbstrParameterName)
			{
			CA_FreeMemory (*pbstrParameterName);
			*pbstrParameterName = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetEntryCount (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        long *pNumberEntries)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pNumberEntries__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetEntryCount_ (__vtblIFacePtr,
	                                                    &pNumberEntries__Temp));

	if (pNumberEntries)
		{
		*pNumberEntries = pNumberEntries__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetCurrentEntry (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          long *pEntryNumber)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pEntryNumber__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCurrentEntry_ (__vtblIFacePtr,
	                                                      &pEntryNumber__Temp));

	if (pEntryNumber)
		{
		*pEntryNumber = pEntryNumber__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetCurrentEntry (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          long entryNumber)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCurrentEntry_ (__vtblIFacePtr,
	                                                      entryNumber));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2ShowDialog (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     enum MediaPlayerEnum_MPShowDialogConstants mpDialogIndex)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer2_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer2,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->ShowDialog_ (__vtblIFacePtr,
	                                                 mpDialogIndex));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer2, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_NewIMediaBindStream (const char *server,
                                                 int supportMultithreading,
                                                 LCID locale, int reserved,
                                                 CAObjHandle *objectHandle)
{
	HRESULT __result = S_OK;
	GUID clsid = {0x22D6F312, 0xB0F6, 0x11D0, 0x94, 0xAB, 0x0, 0x80, 0xC7,
	              0x4C, 0x7E, 0x95};

	__result = CA_CreateObjectByClassIdEx (&clsid, server,
	                                       &MediaPlayer_IID_IMediaBindStream,
	                                       supportMultithreading, locale,
	                                       reserved, objectHandle);

	return __result;
}

HRESULT CVIFUNC MediaPlayer_OpenIMediaBindStream (const char *fileName,
                                                  const char *server,
                                                  int supportMultithreading,
                                                  LCID locale, int reserved,
                                                  CAObjHandle *objectHandle)
{
	HRESULT __result = S_OK;
	GUID clsid = {0x22D6F312, 0xB0F6, 0x11D0, 0x94, 0xAB, 0x0, 0x80, 0xC7,
	              0x4C, 0x7E, 0x95};

	__result = CA_LoadObjectFromFileByClassIdEx (fileName, &clsid, server,
	                                             &MediaPlayer_IID_IMediaBindStream,
	                                             supportMultithreading, locale,
	                                             reserved, objectHandle);

	return __result;
}

HRESULT CVIFUNC MediaPlayer_ActiveIMediaBindStream (const char *server,
                                                    int supportMultithreading,
                                                    LCID locale, int reserved,
                                                    CAObjHandle *objectHandle)
{
	HRESULT __result = S_OK;
	GUID clsid = {0x22D6F312, 0xB0F6, 0x11D0, 0x94, 0xAB, 0x0, 0x80, 0xC7,
	              0x4C, 0x7E, 0x95};

	__result = CA_GetActiveObjectByClassIdEx (&clsid, server,
	                                          &MediaPlayer_IID_IMediaBindStream,
	                                          supportMultithreading, locale,
	                                          reserved, objectHandle);

	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaBindStreamLoadMoniker (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         const char *bszTransferContext,
                                                         const char *bszUrl)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaBindStream_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR bszTransferContext__AutoType = 0;
	BSTR bszUrl__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (bszTransferContext,
	                              &bszTransferContext__AutoType));
	__caErrChk (CA_CStringToBSTR (bszUrl, &bszUrl__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaBindStream,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->LoadMoniker_ (__vtblIFacePtr,
	                                                  bszTransferContext__AutoType,
	                                                  bszUrl__AutoType));

Error:
	CA_FreeBSTR (bszTransferContext__AutoType);
	CA_FreeBSTR (bszUrl__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaBindStream,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_NewRadioPlayerIRadioPlayer (const char *server,
                                                        int supportMultithreading,
                                                        LCID locale,
                                                        int reserved,
                                                        CAObjHandle *objectHandle)
{
	HRESULT __result = S_OK;
	GUID clsid = {0x9C2263B0, 0x3E3C, 0x11D2, 0x9B, 0xD3, 0x20, 0x4C, 0x4F,
	              0x4F, 0x50, 0x20};

	__result = CA_CreateObjectByClassIdEx (&clsid, server,
	                                       &MediaPlayer_IID_IRadioPlayer,
	                                       supportMultithreading, locale,
	                                       reserved, objectHandle);

	return __result;
}

HRESULT CVIFUNC MediaPlayer_OpenRadioPlayerIRadioPlayer (const char *fileName,
                                                         const char *server,
                                                         int supportMultithreading,
                                                         LCID locale,
                                                         int reserved,
                                                         CAObjHandle *objectHandle)
{
	HRESULT __result = S_OK;
	GUID clsid = {0x9C2263B0, 0x3E3C, 0x11D2, 0x9B, 0xD3, 0x20, 0x4C, 0x4F,
	              0x4F, 0x50, 0x20};

	__result = CA_LoadObjectFromFileByClassIdEx (fileName, &clsid, server,
	                                             &MediaPlayer_IID_IRadioPlayer,
	                                             supportMultithreading, locale,
	                                             reserved, objectHandle);

	return __result;
}

HRESULT CVIFUNC MediaPlayer_ActiveRadioPlayerIRadioPlayer (const char *server,
                                                           int supportMultithreading,
                                                           LCID locale,
                                                           int reserved,
                                                           CAObjHandle *objectHandle)
{
	HRESULT __result = S_OK;
	GUID clsid = {0x9C2263B0, 0x3E3C, 0x11D2, 0x9B, 0xD3, 0x20, 0x4C, 0x4F,
	              0x4F, 0x50, 0x20};

	__result = CA_GetActiveObjectByClassIdEx (&clsid, server,
	                                          &MediaPlayer_IID_IRadioPlayer,
	                                          supportMultithreading, locale,
	                                          reserved, objectHandle);

	return __result;
}

HRESULT CVIFUNC MediaPlayer_NewRadioServerIRadioPlayer (const char *server,
                                                        int supportMultithreading,
                                                        LCID locale,
                                                        int reserved,
                                                        CAObjHandle *objectHandle)
{
	HRESULT __result = S_OK;
	GUID clsid = {0x8E71888A, 0x423F, 0x11D2, 0x87, 0x6E, 0x0, 0xA0, 0xC9, 0x8,
	              0x24, 0x67};

	__result = CA_CreateObjectByClassIdEx (&clsid, server,
	                                       &MediaPlayer_IID_IRadioPlayer,
	                                       supportMultithreading, locale,
	                                       reserved, objectHandle);

	return __result;
}

HRESULT CVIFUNC MediaPlayer_OpenRadioServerIRadioPlayer (const char *fileName,
                                                         const char *server,
                                                         int supportMultithreading,
                                                         LCID locale,
                                                         int reserved,
                                                         CAObjHandle *objectHandle)
{
	HRESULT __result = S_OK;
	GUID clsid = {0x8E71888A, 0x423F, 0x11D2, 0x87, 0x6E, 0x0, 0xA0, 0xC9, 0x8,
	              0x24, 0x67};

	__result = CA_LoadObjectFromFileByClassIdEx (fileName, &clsid, server,
	                                             &MediaPlayer_IID_IRadioPlayer,
	                                             supportMultithreading, locale,
	                                             reserved, objectHandle);

	return __result;
}

HRESULT CVIFUNC MediaPlayer_ActiveRadioServerIRadioPlayer (const char *server,
                                                           int supportMultithreading,
                                                           LCID locale,
                                                           int reserved,
                                                           CAObjHandle *objectHandle)
{
	HRESULT __result = S_OK;
	GUID clsid = {0x8E71888A, 0x423F, 0x11D2, 0x87, 0x6E, 0x0, 0xA0, 0xC9, 0x8,
	              0x24, 0x67};

	__result = CA_GetActiveObjectByClassIdEx (&clsid, server,
	                                          &MediaPlayer_IID_IRadioPlayer,
	                                          supportMultithreading, locale,
	                                          reserved, objectHandle);

	return __result;
}

HRESULT CVIFUNC MediaPlayer_IRadioPlayerBindRadioMemory (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	MediaPlayer_IRadioPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IRadioPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->BindRadioMemory_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IRadioPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IRadioPlayerReleaseRadio (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	MediaPlayer_IRadioPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IRadioPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->ReleaseRadio_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IRadioPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IRadioPlayerRegisterEvent (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       const char *bszEvent,
                                                       long *plRegister)
{
	HRESULT __result = S_OK;
	MediaPlayer_IRadioPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR bszEvent__AutoType = 0;
	long plRegister__Temp;

	__caErrChk (CA_CStringToBSTR (bszEvent, &bszEvent__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IRadioPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->RegisterEvent_ (__vtblIFacePtr,
	                                                    bszEvent__AutoType,
	                                                    &plRegister__Temp));

	if (plRegister)
		{
		*plRegister = plRegister__Temp;
		}

Error:
	CA_FreeBSTR (bszEvent__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IRadioPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IRadioPlayerRegisterWindow (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        long __MIDL_0012,
                                                        unsigned long dwMessage,
                                                        unsigned long dwCodeSet,
                                                        long *plRegister)
{
	HRESULT __result = S_OK;
	MediaPlayer_IRadioPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long plRegister__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IRadioPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->RegisterWindow_ (__vtblIFacePtr,
	                                                     __MIDL_0012,
	                                                     dwMessage, dwCodeSet,
	                                                     &plRegister__Temp));

	if (plRegister)
		{
		*plRegister = plRegister__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IRadioPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IRadioPlayerGetSection (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    char **bszSection)
{
	HRESULT __result = S_OK;
	MediaPlayer_IRadioPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR bszSection__AutoType = 0;

	if (bszSection)
		*bszSection = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IRadioPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetSection_ (__vtblIFacePtr,
	                                                 &bszSection__AutoType));

	if (bszSection)
		__caErrChk (CA_BSTRGetCString (bszSection__AutoType, bszSection));

Error:
	CA_FreeBSTR (bszSection__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (bszSection)
			{
			CA_FreeMemory (*bszSection);
			*bszSection = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IRadioPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IRadioPlayerUnregister (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long lRegister)
{
	HRESULT __result = S_OK;
	MediaPlayer_IRadioPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IRadioPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->Unregister_ (__vtblIFacePtr, lRegister));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IRadioPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IRadioPlayerGetInstanceCount (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          long *plInstances)
{
	HRESULT __result = S_OK;
	MediaPlayer_IRadioPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long plInstances__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IRadioPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetInstanceCount_ (__vtblIFacePtr,
	                                                       &plInstances__Temp));

	if (plInstances)
		{
		*plInstances = plInstances__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IRadioPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IRadioPlayerPlay (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	MediaPlayer_IRadioPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IRadioPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->Play_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IRadioPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IRadioPlayerStop (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	MediaPlayer_IRadioPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IRadioPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->Stop_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IRadioPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IRadioPlayerSetUrl (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                const char *newValue)
{
	HRESULT __result = S_OK;
	MediaPlayer_IRadioPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR newValue__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (newValue, &newValue__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IRadioPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetUrl_ (__vtblIFacePtr,
	                                             newValue__AutoType));

Error:
	CA_FreeBSTR (newValue__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IRadioPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IRadioPlayerSetVolume (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long newValue)
{
	HRESULT __result = S_OK;
	MediaPlayer_IRadioPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IRadioPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetVolume_ (__vtblIFacePtr, newValue));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IRadioPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IRadioPlayerSetMute (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL newValue)
{
	HRESULT __result = S_OK;
	MediaPlayer_IRadioPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IRadioPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetMute_ (__vtblIFacePtr, newValue));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IRadioPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IRadioPlayerGetStatus (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long *plVolume, long *pfMute,
                                                   long *pfPlay,
                                                   char **__MIDL_0013,
                                                   char **__MIDL_0014,
                                                   char **__MIDL_0015,
                                                   char **__MIDL_0016,
                                                   char **__MIDL_0017,
                                                   char **__MIDL_0018,
                                                   char **__MIDL_0019)
{
	HRESULT __result = S_OK;
	MediaPlayer_IRadioPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long plVolume__Temp;
	long pfMute__Temp;
	long pfPlay__Temp;
	BSTR __MIDL_0013__AutoType = 0;
	BSTR __MIDL_0014__AutoType = 0;
	BSTR __MIDL_0015__AutoType = 0;
	BSTR __MIDL_0016__AutoType = 0;
	BSTR __MIDL_0017__AutoType = 0;
	BSTR __MIDL_0018__AutoType = 0;
	BSTR __MIDL_0019__AutoType = 0;

	if (__MIDL_0013)
		*__MIDL_0013 = 0;
	if (__MIDL_0014)
		*__MIDL_0014 = 0;
	if (__MIDL_0015)
		*__MIDL_0015 = 0;
	if (__MIDL_0016)
		*__MIDL_0016 = 0;
	if (__MIDL_0017)
		*__MIDL_0017 = 0;
	if (__MIDL_0018)
		*__MIDL_0018 = 0;
	if (__MIDL_0019)
		*__MIDL_0019 = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IRadioPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetStatus_ (__vtblIFacePtr,
	                                                &plVolume__Temp,
	                                                &pfMute__Temp,
	                                                &pfPlay__Temp,
	                                                &__MIDL_0013__AutoType,
	                                                &__MIDL_0014__AutoType,
	                                                &__MIDL_0015__AutoType,
	                                                &__MIDL_0016__AutoType,
	                                                &__MIDL_0017__AutoType,
	                                                &__MIDL_0018__AutoType,
	                                                &__MIDL_0019__AutoType));

	if (plVolume)
		{
		*plVolume = plVolume__Temp;
		}
	if (pfMute)
		{
		*pfMute = pfMute__Temp;
		}
	if (pfPlay)
		{
		*pfPlay = pfPlay__Temp;
		}
	if (__MIDL_0013)
		__caErrChk (CA_BSTRGetCString (__MIDL_0013__AutoType, __MIDL_0013));
	if (__MIDL_0014)
		__caErrChk (CA_BSTRGetCString (__MIDL_0014__AutoType, __MIDL_0014));
	if (__MIDL_0015)
		__caErrChk (CA_BSTRGetCString (__MIDL_0015__AutoType, __MIDL_0015));
	if (__MIDL_0016)
		__caErrChk (CA_BSTRGetCString (__MIDL_0016__AutoType, __MIDL_0016));
	if (__MIDL_0017)
		__caErrChk (CA_BSTRGetCString (__MIDL_0017__AutoType, __MIDL_0017));
	if (__MIDL_0018)
		__caErrChk (CA_BSTRGetCString (__MIDL_0018__AutoType, __MIDL_0018));
	if (__MIDL_0019)
		__caErrChk (CA_BSTRGetCString (__MIDL_0019__AutoType, __MIDL_0019));

Error:
	CA_FreeBSTR (__MIDL_0013__AutoType);
	CA_FreeBSTR (__MIDL_0014__AutoType);
	CA_FreeBSTR (__MIDL_0015__AutoType);
	CA_FreeBSTR (__MIDL_0016__AutoType);
	CA_FreeBSTR (__MIDL_0017__AutoType);
	CA_FreeBSTR (__MIDL_0018__AutoType);
	CA_FreeBSTR (__MIDL_0019__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (__MIDL_0013)
			{
			CA_FreeMemory (*__MIDL_0013);
			*__MIDL_0013 = 0;
			}
		if (__MIDL_0014)
			{
			CA_FreeMemory (*__MIDL_0014);
			*__MIDL_0014 = 0;
			}
		if (__MIDL_0015)
			{
			CA_FreeMemory (*__MIDL_0015);
			*__MIDL_0015 = 0;
			}
		if (__MIDL_0016)
			{
			CA_FreeMemory (*__MIDL_0016);
			*__MIDL_0016 = 0;
			}
		if (__MIDL_0017)
			{
			CA_FreeMemory (*__MIDL_0017);
			*__MIDL_0017 = 0;
			}
		if (__MIDL_0018)
			{
			CA_FreeMemory (*__MIDL_0018);
			*__MIDL_0018 = 0;
			}
		if (__MIDL_0019)
			{
			CA_FreeMemory (*__MIDL_0019);
			*__MIDL_0019 = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IRadioPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IRadioPlayerGetState (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long *plOpenState,
                                                  long *pfBuffering,
                                                  long *plBufferingPercent,
                                                  long *plQuality)
{
	HRESULT __result = S_OK;
	MediaPlayer_IRadioPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long plOpenState__Temp;
	long pfBuffering__Temp;
	long plBufferingPercent__Temp;
	long plQuality__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IRadioPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetState_ (__vtblIFacePtr,
	                                               &plOpenState__Temp,
	                                               &pfBuffering__Temp,
	                                               &plBufferingPercent__Temp,
	                                               &plQuality__Temp));

	if (plOpenState)
		{
		*plOpenState = plOpenState__Temp;
		}
	if (pfBuffering)
		{
		*pfBuffering = pfBuffering__Temp;
		}
	if (plBufferingPercent)
		{
		*plBufferingPercent = plBufferingPercent__Temp;
		}
	if (plQuality)
		{
		*plQuality = plQuality__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IRadioPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_NewIRadioServer (const char *server,
                                             int supportMultithreading,
                                             LCID locale, int reserved,
                                             CAObjHandle *objectHandle)
{
	HRESULT __result = S_OK;
	GUID clsid = {0x9C2263B0, 0x3E3C, 0x11D2, 0x9B, 0xD3, 0x20, 0x4C, 0x4F,
	              0x4F, 0x50, 0x20};

	__result = CA_CreateObjectByClassIdEx (&clsid, server,
	                                       &MediaPlayer_IID_IRadioServer,
	                                       supportMultithreading, locale,
	                                       reserved, objectHandle);

	return __result;
}

HRESULT CVIFUNC MediaPlayer_OpenIRadioServer (const char *fileName,
                                              const char *server,
                                              int supportMultithreading,
                                              LCID locale, int reserved,
                                              CAObjHandle *objectHandle)
{
	HRESULT __result = S_OK;
	GUID clsid = {0x9C2263B0, 0x3E3C, 0x11D2, 0x9B, 0xD3, 0x20, 0x4C, 0x4F,
	              0x4F, 0x50, 0x20};

	__result = CA_LoadObjectFromFileByClassIdEx (fileName, &clsid, server,
	                                             &MediaPlayer_IID_IRadioServer,
	                                             supportMultithreading, locale,
	                                             reserved, objectHandle);

	return __result;
}

HRESULT CVIFUNC MediaPlayer_ActiveIRadioServer (const char *server,
                                                int supportMultithreading,
                                                LCID locale, int reserved,
                                                CAObjHandle *objectHandle)
{
	HRESULT __result = S_OK;
	GUID clsid = {0x9C2263B0, 0x3E3C, 0x11D2, 0x9B, 0xD3, 0x20, 0x4C, 0x4F,
	              0x4F, 0x50, 0x20};

	__result = CA_GetActiveObjectByClassIdEx (&clsid, server,
	                                          &MediaPlayer_IID_IRadioServer,
	                                          supportMultithreading, locale,
	                                          reserved, objectHandle);

	return __result;
}

HRESULT CVIFUNC MediaPlayer_IRadioServerBindToRadio (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     const char *wszRadio,
                                                     MediaPlayerObj_IRadioPlayer *ppServer)
{
	HRESULT __result = S_OK;
	MediaPlayer_IRadioServer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR wszRadio__AutoType = 0;
	LPDISPATCH ppServer__AutoType = 0;
	LCID __locale;
	int __supportMultithreading;

	if (ppServer)
		*ppServer = 0;

	__caErrChk (CA_CStringToBSTR (wszRadio, &wszRadio__AutoType));
	__caErrChk (CA_GetLocale (objectHandle, &__locale));
	__caErrChk (CA_GetSupportForMultithreading (objectHandle,
	                                            &__supportMultithreading));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IRadioServer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->BindToRadio_ (__vtblIFacePtr,
	                                                  wszRadio__AutoType,
	                                                  &ppServer__AutoType));
	

	if (ppServer)
		{
		__caErrChk (CA_CreateObjHandleFromInterface (ppServer__AutoType,
		                                             &MediaPlayer_IID_IRadioPlayer,
		                                             __supportMultithreading,
		                                             __locale, 0, 0, ppServer));
		ppServer__AutoType = 0;
		}

Error:
	CA_FreeBSTR (wszRadio__AutoType);
	if (ppServer__AutoType)
		ppServer__AutoType->lpVtbl->Release (ppServer__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (ppServer)
			{
			CA_DiscardObjHandle (*ppServer);
			*ppServer = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IRadioServer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IRadioServerIsRadioExists (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       const char *wszRadio)
{
	HRESULT __result = S_OK;
	MediaPlayer_IRadioServer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR wszRadio__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (wszRadio, &wszRadio__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IRadioServer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->IsRadioExists_ (__vtblIFacePtr,
	                                                    wszRadio__AutoType));

Error:
	CA_FreeBSTR (wszRadio__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IRadioServer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IRadioServerLaunchStandardUrl (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           const char *bszUrl,
                                                           LPUNKNOWN pBrowser)
{
	HRESULT __result = S_OK;
	MediaPlayer_IRadioServer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR bszUrl__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (bszUrl, &bszUrl__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IRadioServer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->LaunchStandardUrl_ (__vtblIFacePtr,
	                                                        bszUrl__AutoType,
	                                                        pBrowser));

Error:
	CA_FreeBSTR (bszUrl__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IRadioServer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_NewIMediaPlayerListener (const char *server,
                                                     int supportMultithreading,
                                                     LCID locale, int reserved,
                                                     CAObjHandle *objectHandle)
{
	HRESULT __result = S_OK;
	GUID clsid = {0x8E71888A, 0x423F, 0x11D2, 0x87, 0x6E, 0x0, 0xA0, 0xC9, 0x8,
	              0x24, 0x67};

	__result = CA_CreateObjectByClassIdEx (&clsid, server,
	                                       &MediaPlayer_IID_IMediaPlayerListener,
	                                       supportMultithreading, locale,
	                                       reserved, objectHandle);

	return __result;
}

HRESULT CVIFUNC MediaPlayer_OpenIMediaPlayerListener (const char *fileName,
                                                      const char *server,
                                                      int supportMultithreading,
                                                      LCID locale, int reserved,
                                                      CAObjHandle *objectHandle)
{
	HRESULT __result = S_OK;
	GUID clsid = {0x8E71888A, 0x423F, 0x11D2, 0x87, 0x6E, 0x0, 0xA0, 0xC9, 0x8,
	              0x24, 0x67};

	__result = CA_LoadObjectFromFileByClassIdEx (fileName, &clsid, server,
	                                             &MediaPlayer_IID_IMediaPlayerListener,
	                                             supportMultithreading, locale,
	                                             reserved, objectHandle);

	return __result;
}

HRESULT CVIFUNC MediaPlayer_ActiveIMediaPlayerListener (const char *server,
                                                        int supportMultithreading,
                                                        LCID locale,
                                                        int reserved,
                                                        CAObjHandle *objectHandle)
{
	HRESULT __result = S_OK;
	GUID clsid = {0x8E71888A, 0x423F, 0x11D2, 0x87, 0x6E, 0x0, 0xA0, 0xC9, 0x8,
	              0x24, 0x67};

	__result = CA_GetActiveObjectByClassIdEx (&clsid, server,
	                                          &MediaPlayer_IID_IMediaPlayerListener,
	                                          supportMultithreading, locale,
	                                          reserved, objectHandle);

	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerListenerPlayStateChanged (CAObjHandle objectHandle,
                                                                  ERRORINFO *errorInfo,
                                                                  long lNewState)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerListener_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerListener,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->PlayStateChanged_ (__vtblIFacePtr,
	                                                       lNewState));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerListener,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerListenerBuffering (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           VBOOL fStart)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerListener_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerListener,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->Buffering_ (__vtblIFacePtr, fStart));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerListener,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerListenerBufferPercent (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               long lBufferPercent)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerListener_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerListener,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->BufferPercent_ (__vtblIFacePtr,
	                                                    lBufferPercent));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerListener,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerListenerOpenStateChanged (CAObjHandle objectHandle,
                                                                  ERRORINFO *errorInfo,
                                                                  long lOpenState)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerListener_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerListener,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->OpenStateChanged_ (__vtblIFacePtr,
	                                                       lOpenState));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerListener,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerListenerMediaInfoChanged (CAObjHandle objectHandle,
                                                                  ERRORINFO *errorInfo,
                                                                  const char *bstrShowTitle,
                                                                  const char *bstrClipTitle,
                                                                  const char *bstrClipAuthor,
                                                                  const char *bstrClipCopyright,
                                                                  const char *bstrStationURL)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerListener_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR bstrShowTitle__AutoType = 0;
	BSTR bstrClipTitle__AutoType = 0;
	BSTR bstrClipAuthor__AutoType = 0;
	BSTR bstrClipCopyright__AutoType = 0;
	BSTR bstrStationURL__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (bstrShowTitle, &bstrShowTitle__AutoType));
	__caErrChk (CA_CStringToBSTR (bstrClipTitle, &bstrClipTitle__AutoType));
	__caErrChk (CA_CStringToBSTR (bstrClipAuthor, &bstrClipAuthor__AutoType));
	__caErrChk (CA_CStringToBSTR (bstrClipCopyright,
	                              &bstrClipCopyright__AutoType));
	__caErrChk (CA_CStringToBSTR (bstrStationURL, &bstrStationURL__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerListener,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->MediaInfoChanged_ (__vtblIFacePtr,
	                                                       bstrShowTitle__AutoType,
	                                                       bstrClipTitle__AutoType,
	                                                       bstrClipAuthor__AutoType,
	                                                       bstrClipCopyright__AutoType,
	                                                       bstrStationURL__AutoType));

Error:
	CA_FreeBSTR (bstrShowTitle__AutoType);
	CA_FreeBSTR (bstrClipTitle__AutoType);
	CA_FreeBSTR (bstrClipAuthor__AutoType);
	CA_FreeBSTR (bstrClipCopyright__AutoType);
	CA_FreeBSTR (bstrStationURL__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerListener,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerListenerQualityChanged (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                long lQuality)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerListener_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerListener,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->QualityChanged_ (__vtblIFacePtr,
	                                                     lQuality));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerListener,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerListenerError (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       const char *bstrError)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerListener_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR bstrError__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (bstrError, &bstrError__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerListener,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->Error_ (__vtblIFacePtr,
	                                            bstrError__AutoType));

Error:
	CA_FreeBSTR (bstrError__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerListener,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_NewIRadioBand (const char *server,
                                           int supportMultithreading,
                                           LCID locale, int reserved,
                                           CAObjHandle *objectHandle)
{
	HRESULT __result = S_OK;
	GUID clsid = {0x8E718888, 0x423F, 0x11D2, 0x87, 0x6E, 0x0, 0xA0, 0xC9, 0x8,
	              0x24, 0x67};

	__result = CA_CreateObjectByClassIdEx (&clsid, server,
	                                       &MediaPlayer_IID_IRadioBand,
	                                       supportMultithreading, locale,
	                                       reserved, objectHandle);

	return __result;
}

HRESULT CVIFUNC MediaPlayer_OpenIRadioBand (const char *fileName,
                                            const char *server,
                                            int supportMultithreading,
                                            LCID locale, int reserved,
                                            CAObjHandle *objectHandle)
{
	HRESULT __result = S_OK;
	GUID clsid = {0x8E718888, 0x423F, 0x11D2, 0x87, 0x6E, 0x0, 0xA0, 0xC9, 0x8,
	              0x24, 0x67};

	__result = CA_LoadObjectFromFileByClassIdEx (fileName, &clsid, server,
	                                             &MediaPlayer_IID_IRadioBand,
	                                             supportMultithreading, locale,
	                                             reserved, objectHandle);

	return __result;
}

HRESULT CVIFUNC MediaPlayer_ActiveIRadioBand (const char *server,
                                              int supportMultithreading,
                                              LCID locale, int reserved,
                                              CAObjHandle *objectHandle)
{
	HRESULT __result = S_OK;
	GUID clsid = {0x8E718888, 0x423F, 0x11D2, 0x87, 0x6E, 0x0, 0xA0, 0xC9, 0x8,
	              0x24, 0x67};

	__result = CA_GetActiveObjectByClassIdEx (&clsid, server,
	                                          &MediaPlayer_IID_IRadioBand,
	                                          supportMultithreading, locale,
	                                          reserved, objectHandle);

	return __result;
}

HRESULT CVIFUNC MediaPlayer_IRadioBandCreate (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo, long *phwnd,
                                              long hwndParent)
{
	HRESULT __result = S_OK;
	MediaPlayer_IRadioBand_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IRadioBand, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->Create_ (__vtblIFacePtr, phwnd,
	                                             hwndParent));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IRadioBand, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetCurrentPosition (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            double *pCurrentPosition)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	double pCurrentPosition__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCurrentPosition_ (__vtblIFacePtr,
	                                                         &pCurrentPosition__Temp));

	if (pCurrentPosition)
		{
		*pCurrentPosition = pCurrentPosition__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetCurrentPosition (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            double pCurrentPosition)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCurrentPosition_ (__vtblIFacePtr,
	                                                         pCurrentPosition));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetDuration (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     double *pDuration)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	double pDuration__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetDuration_ (__vtblIFacePtr,
	                                                  &pDuration__Temp));

	if (pDuration)
		{
		*pDuration = pDuration__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetImageSourceWidth (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             long *pWidth)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pWidth__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetImageSourceWidth_ (__vtblIFacePtr,
	                                                          &pWidth__Temp));

	if (pWidth)
		{
		*pWidth = pWidth__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetImageSourceHeight (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              long *pHeight)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pHeight__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetImageSourceHeight_ (__vtblIFacePtr,
	                                                           &pHeight__Temp));

	if (pHeight)
		{
		*pHeight = pHeight__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetMarkerCount (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        long *pMarkerCount)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pMarkerCount__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetMarkerCount_ (__vtblIFacePtr,
	                                                     &pMarkerCount__Temp));

	if (pMarkerCount)
		{
		*pMarkerCount = pMarkerCount__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetCanScan (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL *pCanScan)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pCanScan__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCanScan_ (__vtblIFacePtr,
	                                                 &pCanScan__Temp));

	if (pCanScan)
		{
		*pCanScan = pCanScan__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetCanSeek (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL *pCanSeek)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pCanSeek__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCanSeek_ (__vtblIFacePtr,
	                                                 &pCanSeek__Temp));

	if (pCanSeek)
		{
		*pCanSeek = pCanSeek__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetCanSeekToMarkers (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL *pCanSeekToMarkers)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pCanSeekToMarkers__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCanSeekToMarkers_ (__vtblIFacePtr,
	                                                          &pCanSeekToMarkers__Temp));

	if (pCanSeekToMarkers)
		{
		*pCanSeekToMarkers = pCanSeekToMarkers__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetCurrentMarker (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          long *pCurrentMarker)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pCurrentMarker__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCurrentMarker_ (__vtblIFacePtr,
	                                                       &pCurrentMarker__Temp));

	if (pCurrentMarker)
		{
		*pCurrentMarker = pCurrentMarker__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetCurrentMarker (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          long pCurrentMarker)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCurrentMarker_ (__vtblIFacePtr,
	                                                       pCurrentMarker));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetFileName (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     char **pbstrFileName)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrFileName__AutoType = 0;

	if (pbstrFileName)
		*pbstrFileName = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetFileName_ (__vtblIFacePtr,
	                                                  &pbstrFileName__AutoType));

	if (pbstrFileName)
		__caErrChk (CA_BSTRGetCString (pbstrFileName__AutoType, pbstrFileName));

Error:
	CA_FreeBSTR (pbstrFileName__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pbstrFileName)
			{
			CA_FreeMemory (*pbstrFileName);
			*pbstrFileName = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetFileName (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     const char *pbstrFileName)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrFileName__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (pbstrFileName, &pbstrFileName__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetFileName_ (__vtblIFacePtr,
	                                                  pbstrFileName__AutoType));

Error:
	CA_FreeBSTR (pbstrFileName__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetSourceLink (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       char **pbstrSourceLink)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrSourceLink__AutoType = 0;

	if (pbstrSourceLink)
		*pbstrSourceLink = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetSourceLink_ (__vtblIFacePtr,
	                                                    &pbstrSourceLink__AutoType));

	if (pbstrSourceLink)
		__caErrChk (CA_BSTRGetCString (pbstrSourceLink__AutoType, pbstrSourceLink));

Error:
	CA_FreeBSTR (pbstrSourceLink__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pbstrSourceLink)
			{
			CA_FreeMemory (*pbstrSourceLink);
			*pbstrSourceLink = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetCreationDate (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         DATE *pCreationDate)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	DATE pCreationDate__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCreationDate_ (__vtblIFacePtr,
	                                                      &pCreationDate__Temp));

	if (pCreationDate)
		{
		*pCreationDate = pCreationDate__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetErrorCorrection (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            char **pbstrErrorCorrection)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrErrorCorrection__AutoType = 0;

	if (pbstrErrorCorrection)
		*pbstrErrorCorrection = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetErrorCorrection_ (__vtblIFacePtr,
	                                                         &pbstrErrorCorrection__AutoType));

	if (pbstrErrorCorrection)
		__caErrChk (CA_BSTRGetCString (pbstrErrorCorrection__AutoType,
	                               pbstrErrorCorrection));

Error:
	CA_FreeBSTR (pbstrErrorCorrection__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pbstrErrorCorrection)
			{
			CA_FreeMemory (*pbstrErrorCorrection);
			*pbstrErrorCorrection = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetBandwidth (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long *pBandwidth)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pBandwidth__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetBandwidth_ (__vtblIFacePtr,
	                                                   &pBandwidth__Temp));

	if (pBandwidth)
		{
		*pBandwidth = pBandwidth__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetSourceProtocol (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           long *pSourceProtocol)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pSourceProtocol__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetSourceProtocol_ (__vtblIFacePtr,
	                                                        &pSourceProtocol__Temp));

	if (pSourceProtocol)
		{
		*pSourceProtocol = pSourceProtocol__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetReceivedPackets (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            long *pReceivedPackets)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pReceivedPackets__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetReceivedPackets_ (__vtblIFacePtr,
	                                                         &pReceivedPackets__Temp));

	if (pReceivedPackets)
		{
		*pReceivedPackets = pReceivedPackets__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetRecoveredPackets (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             long *pRecoveredPackets)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pRecoveredPackets__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetRecoveredPackets_ (__vtblIFacePtr,
	                                                          &pRecoveredPackets__Temp));

	if (pRecoveredPackets)
		{
		*pRecoveredPackets = pRecoveredPackets__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetLostPackets (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        long *pLostPackets)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pLostPackets__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetLostPackets_ (__vtblIFacePtr,
	                                                     &pLostPackets__Temp));

	if (pLostPackets)
		{
		*pLostPackets = pLostPackets__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetReceptionQuality (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             long *pReceptionQuality)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pReceptionQuality__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetReceptionQuality_ (__vtblIFacePtr,
	                                                          &pReceptionQuality__Temp));

	if (pReceptionQuality)
		{
		*pReceptionQuality = pReceptionQuality__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetBufferingCount (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           long *pBufferingCount)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pBufferingCount__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetBufferingCount_ (__vtblIFacePtr,
	                                                        &pBufferingCount__Temp));

	if (pBufferingCount)
		{
		*pBufferingCount = pBufferingCount__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetIsBroadcast (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *pIsBroadcast)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pIsBroadcast__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetIsBroadcast_ (__vtblIFacePtr,
	                                                     &pIsBroadcast__Temp));

	if (pIsBroadcast)
		{
		*pIsBroadcast = pIsBroadcast__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetBufferingProgress (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              long *pBufferingProgress)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pBufferingProgress__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetBufferingProgress_ (__vtblIFacePtr,
	                                                           &pBufferingProgress__Temp));

	if (pBufferingProgress)
		{
		*pBufferingProgress = pBufferingProgress__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetChannelName (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        char **pbstrChannelName)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrChannelName__AutoType = 0;

	if (pbstrChannelName)
		*pbstrChannelName = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetChannelName_ (__vtblIFacePtr,
	                                                     &pbstrChannelName__AutoType));

	if (pbstrChannelName)
		__caErrChk (CA_BSTRGetCString (pbstrChannelName__AutoType,
	                               pbstrChannelName));

Error:
	CA_FreeBSTR (pbstrChannelName__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pbstrChannelName)
			{
			CA_FreeMemory (*pbstrChannelName);
			*pbstrChannelName = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetChannelDescription (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               char **pbstrChannelDescription)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrChannelDescription__AutoType = 0;

	if (pbstrChannelDescription)
		*pbstrChannelDescription = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetChannelDescription_ (__vtblIFacePtr,
	                                                            &pbstrChannelDescription__AutoType));

	if (pbstrChannelDescription)
		__caErrChk (CA_BSTRGetCString (pbstrChannelDescription__AutoType,
	                               pbstrChannelDescription));

Error:
	CA_FreeBSTR (pbstrChannelDescription__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pbstrChannelDescription)
			{
			CA_FreeMemory (*pbstrChannelDescription);
			*pbstrChannelDescription = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetChannelURL (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       char **pbstrChannelURL)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrChannelURL__AutoType = 0;

	if (pbstrChannelURL)
		*pbstrChannelURL = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetChannelURL_ (__vtblIFacePtr,
	                                                    &pbstrChannelURL__AutoType));

	if (pbstrChannelURL)
		__caErrChk (CA_BSTRGetCString (pbstrChannelURL__AutoType, pbstrChannelURL));

Error:
	CA_FreeBSTR (pbstrChannelURL__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pbstrChannelURL)
			{
			CA_FreeMemory (*pbstrChannelURL);
			*pbstrChannelURL = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetContactAddress (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           char **pbstrContactAddress)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrContactAddress__AutoType = 0;

	if (pbstrContactAddress)
		*pbstrContactAddress = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetContactAddress_ (__vtblIFacePtr,
	                                                        &pbstrContactAddress__AutoType));

	if (pbstrContactAddress)
		__caErrChk (CA_BSTRGetCString (pbstrContactAddress__AutoType,
	                               pbstrContactAddress));

Error:
	CA_FreeBSTR (pbstrContactAddress__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pbstrContactAddress)
			{
			CA_FreeMemory (*pbstrContactAddress);
			*pbstrContactAddress = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetContactPhone (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         char **pbstrContactPhone)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrContactPhone__AutoType = 0;

	if (pbstrContactPhone)
		*pbstrContactPhone = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetContactPhone_ (__vtblIFacePtr,
	                                                      &pbstrContactPhone__AutoType));

	if (pbstrContactPhone)
		__caErrChk (CA_BSTRGetCString (pbstrContactPhone__AutoType,
	                               pbstrContactPhone));

Error:
	CA_FreeBSTR (pbstrContactPhone__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pbstrContactPhone)
			{
			CA_FreeMemory (*pbstrContactPhone);
			*pbstrContactPhone = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetContactEmail (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         char **pbstrContactEmail)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrContactEmail__AutoType = 0;

	if (pbstrContactEmail)
		*pbstrContactEmail = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetContactEmail_ (__vtblIFacePtr,
	                                                      &pbstrContactEmail__AutoType));

	if (pbstrContactEmail)
		__caErrChk (CA_BSTRGetCString (pbstrContactEmail__AutoType,
	                               pbstrContactEmail));

Error:
	CA_FreeBSTR (pbstrContactEmail__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pbstrContactEmail)
			{
			CA_FreeMemory (*pbstrContactEmail);
			*pbstrContactEmail = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetBufferingTime (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          double *pBufferingTime)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	double pBufferingTime__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetBufferingTime_ (__vtblIFacePtr,
	                                                       &pBufferingTime__Temp));

	if (pBufferingTime)
		{
		*pBufferingTime = pBufferingTime__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetBufferingTime (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          double pBufferingTime)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetBufferingTime_ (__vtblIFacePtr,
	                                                       pBufferingTime));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetAutoStart (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *pAutoStart)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pAutoStart__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetAutoStart_ (__vtblIFacePtr,
	                                                   &pAutoStart__Temp));

	if (pAutoStart)
		{
		*pAutoStart = pAutoStart__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetAutoStart (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL pAutoStart)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetAutoStart_ (__vtblIFacePtr,
	                                                   pAutoStart));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetAutoRewind (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL *pAutoRewind)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pAutoRewind__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetAutoRewind_ (__vtblIFacePtr,
	                                                    &pAutoRewind__Temp));

	if (pAutoRewind)
		{
		*pAutoRewind = pAutoRewind__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetAutoRewind (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL pAutoRewind)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetAutoRewind_ (__vtblIFacePtr,
	                                                    pAutoRewind));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetRate (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 double *pRate)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	double pRate__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetRate_ (__vtblIFacePtr, &pRate__Temp));

	if (pRate)
		{
		*pRate = pRate__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetRate (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 double pRate)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetRate_ (__vtblIFacePtr, pRate));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetSendKeyboardEvents (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               VBOOL *pSendKeyboardEvents)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pSendKeyboardEvents__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetSendKeyboardEvents_ (__vtblIFacePtr,
	                                                            &pSendKeyboardEvents__Temp));

	if (pSendKeyboardEvents)
		{
		*pSendKeyboardEvents = pSendKeyboardEvents__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetSendKeyboardEvents (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               VBOOL pSendKeyboardEvents)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetSendKeyboardEvents_ (__vtblIFacePtr,
	                                                            pSendKeyboardEvents));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetSendMouseClickEvents (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 VBOOL *pSendMouseClickEvents)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pSendMouseClickEvents__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetSendMouseClickEvents_ (__vtblIFacePtr,
	                                                              &pSendMouseClickEvents__Temp));

	if (pSendMouseClickEvents)
		{
		*pSendMouseClickEvents = pSendMouseClickEvents__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetSendMouseClickEvents (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 VBOOL pSendMouseClickEvents)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetSendMouseClickEvents_ (__vtblIFacePtr,
	                                                              pSendMouseClickEvents));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetSendMouseMoveEvents (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                VBOOL *pSendMouseMoveEvents)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pSendMouseMoveEvents__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetSendMouseMoveEvents_ (__vtblIFacePtr,
	                                                             &pSendMouseMoveEvents__Temp));

	if (pSendMouseMoveEvents)
		{
		*pSendMouseMoveEvents = pSendMouseMoveEvents__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetSendMouseMoveEvents (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                VBOOL pSendMouseMoveEvents)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetSendMouseMoveEvents_ (__vtblIFacePtr,
	                                                             pSendMouseMoveEvents));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetPlayCount (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long *pPlayCount)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pPlayCount__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPlayCount_ (__vtblIFacePtr,
	                                                   &pPlayCount__Temp));

	if (pPlayCount)
		{
		*pPlayCount = pPlayCount__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetPlayCount (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long pPlayCount)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetPlayCount_ (__vtblIFacePtr,
	                                                   pPlayCount));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetClickToPlay (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *pClickToPlay)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pClickToPlay__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetClickToPlay_ (__vtblIFacePtr,
	                                                     &pClickToPlay__Temp));

	if (pClickToPlay)
		{
		*pClickToPlay = pClickToPlay__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetClickToPlay (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL pClickToPlay)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetClickToPlay_ (__vtblIFacePtr,
	                                                     pClickToPlay));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetAllowScan (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *pAllowScan)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pAllowScan__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetAllowScan_ (__vtblIFacePtr,
	                                                   &pAllowScan__Temp));

	if (pAllowScan)
		{
		*pAllowScan = pAllowScan__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetAllowScan (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL pAllowScan)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetAllowScan_ (__vtblIFacePtr,
	                                                   pAllowScan));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetEnableContextMenu (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              VBOOL *pEnableContextMenu)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pEnableContextMenu__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetEnableContextMenu_ (__vtblIFacePtr,
	                                                           &pEnableContextMenu__Temp));

	if (pEnableContextMenu)
		{
		*pEnableContextMenu = pEnableContextMenu__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetEnableContextMenu (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              VBOOL pEnableContextMenu)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetEnableContextMenu_ (__vtblIFacePtr,
	                                                           pEnableContextMenu));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetCursorType (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long *pCursorType)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pCursorType__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCursorType_ (__vtblIFacePtr,
	                                                    &pCursorType__Temp));

	if (pCursorType)
		{
		*pCursorType = pCursorType__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetCursorType (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long pCursorType)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCursorType_ (__vtblIFacePtr,
	                                                    pCursorType));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetCodecCount (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long *pCodecCount)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pCodecCount__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCodecCount_ (__vtblIFacePtr,
	                                                    &pCodecCount__Temp));

	if (pCodecCount)
		{
		*pCodecCount = pCodecCount__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetAllowChangeDisplaySize (CAObjHandle objectHandle,
                                                                   ERRORINFO *errorInfo,
                                                                   VBOOL *pAllowChangeDisplaySize)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pAllowChangeDisplaySize__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetAllowChangeDisplaySize_ (__vtblIFacePtr,
	                                                                &pAllowChangeDisplaySize__Temp));

	if (pAllowChangeDisplaySize)
		{
		*pAllowChangeDisplaySize = pAllowChangeDisplaySize__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetAllowChangeDisplaySize (CAObjHandle objectHandle,
                                                                   ERRORINFO *errorInfo,
                                                                   VBOOL pAllowChangeDisplaySize)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetAllowChangeDisplaySize_ (__vtblIFacePtr,
	                                                                pAllowChangeDisplaySize));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetIsDurationValid (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VBOOL *pIsDurationValid)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pIsDurationValid__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetIsDurationValid_ (__vtblIFacePtr,
	                                                         &pIsDurationValid__Temp));

	if (pIsDurationValid)
		{
		*pIsDurationValid = pIsDurationValid__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetOpenState (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long *pOpenState)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pOpenState__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetOpenState_ (__vtblIFacePtr,
	                                                   &pOpenState__Temp));

	if (pOpenState)
		{
		*pOpenState = pOpenState__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetSendOpenStateChangeEvents (CAObjHandle objectHandle,
                                                                      ERRORINFO *errorInfo,
                                                                      VBOOL *pSendOpenStateChangeEvents)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pSendOpenStateChangeEvents__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetSendOpenStateChangeEvents_ (__vtblIFacePtr,
	                                                                   &pSendOpenStateChangeEvents__Temp));

	if (pSendOpenStateChangeEvents)
		{
		*pSendOpenStateChangeEvents = pSendOpenStateChangeEvents__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetSendOpenStateChangeEvents (CAObjHandle objectHandle,
                                                                      ERRORINFO *errorInfo,
                                                                      VBOOL pSendOpenStateChangeEvents)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetSendOpenStateChangeEvents_ (__vtblIFacePtr,
	                                                                   pSendOpenStateChangeEvents));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetSendWarningEvents (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              VBOOL *pSendWarningEvents)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pSendWarningEvents__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetSendWarningEvents_ (__vtblIFacePtr,
	                                                           &pSendWarningEvents__Temp));

	if (pSendWarningEvents)
		{
		*pSendWarningEvents = pSendWarningEvents__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetSendWarningEvents (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              VBOOL pSendWarningEvents)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetSendWarningEvents_ (__vtblIFacePtr,
	                                                           pSendWarningEvents));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetSendErrorEvents (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VBOOL *pSendErrorEvents)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pSendErrorEvents__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetSendErrorEvents_ (__vtblIFacePtr,
	                                                         &pSendErrorEvents__Temp));

	if (pSendErrorEvents)
		{
		*pSendErrorEvents = pSendErrorEvents__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetSendErrorEvents (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VBOOL pSendErrorEvents)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetSendErrorEvents_ (__vtblIFacePtr,
	                                                         pSendErrorEvents));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetPlayState (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      enum MediaPlayerEnum_MPPlayStateConstants *pPlayState)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pPlayState__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPlayState_ (__vtblIFacePtr,
	                                                   (long *)&pPlayState__Temp));

	if (pPlayState)
		{
		*pPlayState = pPlayState__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetSendPlayStateChangeEvents (CAObjHandle objectHandle,
                                                                      ERRORINFO *errorInfo,
                                                                      VBOOL *pSendPlayStateChangeEvents)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pSendPlayStateChangeEvents__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetSendPlayStateChangeEvents_ (__vtblIFacePtr,
	                                                                   &pSendPlayStateChangeEvents__Temp));

	if (pSendPlayStateChangeEvents)
		{
		*pSendPlayStateChangeEvents = pSendPlayStateChangeEvents__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetSendPlayStateChangeEvents (CAObjHandle objectHandle,
                                                                      ERRORINFO *errorInfo,
                                                                      VBOOL pSendPlayStateChangeEvents)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetSendPlayStateChangeEvents_ (__vtblIFacePtr,
	                                                                   pSendPlayStateChangeEvents));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetDisplaySize (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        enum MediaPlayerEnum_MPDisplaySizeConstants *pDisplaySize)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pDisplaySize__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetDisplaySize_ (__vtblIFacePtr,
	                                                     (long *)&pDisplaySize__Temp));

	if (pDisplaySize)
		{
		*pDisplaySize = pDisplaySize__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetDisplaySize (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        enum MediaPlayerEnum_MPDisplaySizeConstants pDisplaySize)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetDisplaySize_ (__vtblIFacePtr,
	                                                     pDisplaySize));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetInvokeURLs (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL *pInvokeURLs)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pInvokeURLs__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetInvokeURLs_ (__vtblIFacePtr,
	                                                    &pInvokeURLs__Temp));

	if (pInvokeURLs)
		{
		*pInvokeURLs = pInvokeURLs__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetInvokeURLs (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL pInvokeURLs)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetInvokeURLs_ (__vtblIFacePtr,
	                                                    pInvokeURLs));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetBaseURL (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    char **pbstrBaseURL)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrBaseURL__AutoType = 0;

	if (pbstrBaseURL)
		*pbstrBaseURL = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetBaseURL_ (__vtblIFacePtr,
	                                                 &pbstrBaseURL__AutoType));

	if (pbstrBaseURL)
		__caErrChk (CA_BSTRGetCString (pbstrBaseURL__AutoType, pbstrBaseURL));

Error:
	CA_FreeBSTR (pbstrBaseURL__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pbstrBaseURL)
			{
			CA_FreeMemory (*pbstrBaseURL);
			*pbstrBaseURL = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetBaseURL (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    const char *pbstrBaseURL)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrBaseURL__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (pbstrBaseURL, &pbstrBaseURL__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetBaseURL_ (__vtblIFacePtr,
	                                                 pbstrBaseURL__AutoType));

Error:
	CA_FreeBSTR (pbstrBaseURL__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetDefaultFrame (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         char **pbstrDefaultFrame)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrDefaultFrame__AutoType = 0;

	if (pbstrDefaultFrame)
		*pbstrDefaultFrame = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetDefaultFrame_ (__vtblIFacePtr,
	                                                      &pbstrDefaultFrame__AutoType));

	if (pbstrDefaultFrame)
		__caErrChk (CA_BSTRGetCString (pbstrDefaultFrame__AutoType,
	                               pbstrDefaultFrame));

Error:
	CA_FreeBSTR (pbstrDefaultFrame__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pbstrDefaultFrame)
			{
			CA_FreeMemory (*pbstrDefaultFrame);
			*pbstrDefaultFrame = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetDefaultFrame (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         const char *pbstrDefaultFrame)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrDefaultFrame__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (pbstrDefaultFrame,
	                              &pbstrDefaultFrame__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetDefaultFrame_ (__vtblIFacePtr,
	                                                      pbstrDefaultFrame__AutoType));

Error:
	CA_FreeBSTR (pbstrDefaultFrame__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetHasError (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL *pHasError)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pHasError__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetHasError_ (__vtblIFacePtr,
	                                                  &pHasError__Temp));

	if (pHasError)
		{
		*pHasError = pHasError__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetErrorDescription (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             char **pbstrErrorDescription)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrErrorDescription__AutoType = 0;

	if (pbstrErrorDescription)
		*pbstrErrorDescription = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetErrorDescription_ (__vtblIFacePtr,
	                                                          &pbstrErrorDescription__AutoType));

	if (pbstrErrorDescription)
		__caErrChk (CA_BSTRGetCString (pbstrErrorDescription__AutoType,
	                               pbstrErrorDescription));

Error:
	CA_FreeBSTR (pbstrErrorDescription__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pbstrErrorDescription)
			{
			CA_FreeMemory (*pbstrErrorDescription);
			*pbstrErrorDescription = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetErrorCode (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long *pErrorCode)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pErrorCode__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetErrorCode_ (__vtblIFacePtr,
	                                                   &pErrorCode__Temp));

	if (pErrorCode)
		{
		*pErrorCode = pErrorCode__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetAnimationAtStart (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL *pAnimationAtStart)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pAnimationAtStart__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetAnimationAtStart_ (__vtblIFacePtr,
	                                                          &pAnimationAtStart__Temp));

	if (pAnimationAtStart)
		{
		*pAnimationAtStart = pAnimationAtStart__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetAnimationAtStart (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL pAnimationAtStart)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetAnimationAtStart_ (__vtblIFacePtr,
	                                                          pAnimationAtStart));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetTransparentAtStart (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               VBOOL *pTransparentAtStart)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pTransparentAtStart__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetTransparentAtStart_ (__vtblIFacePtr,
	                                                            &pTransparentAtStart__Temp));

	if (pTransparentAtStart)
		{
		*pTransparentAtStart = pTransparentAtStart__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetTransparentAtStart (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               VBOOL pTransparentAtStart)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetTransparentAtStart_ (__vtblIFacePtr,
	                                                            pTransparentAtStart));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetVolume (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long *pVolume)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pVolume__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetVolume_ (__vtblIFacePtr,
	                                                &pVolume__Temp));

	if (pVolume)
		{
		*pVolume = pVolume__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetVolume (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long pVolume)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetVolume_ (__vtblIFacePtr, pVolume));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetBalance (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long *pBalance)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pBalance__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetBalance_ (__vtblIFacePtr,
	                                                 &pBalance__Temp));

	if (pBalance)
		{
		*pBalance = pBalance__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetBalance (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long pBalance)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetBalance_ (__vtblIFacePtr, pBalance));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetReadyState (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       enum MediaPlayerEnum_MPReadyStateConstants *pValue)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pValue__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetReadyState_ (__vtblIFacePtr,
	                                                    (long *)&pValue__Temp));

	if (pValue)
		{
		*pValue = pValue__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetSelectionStart (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           double *pValue)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	double pValue__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetSelectionStart_ (__vtblIFacePtr,
	                                                        &pValue__Temp));

	if (pValue)
		{
		*pValue = pValue__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetSelectionStart (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           double pValue)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetSelectionStart_ (__vtblIFacePtr,
	                                                        pValue));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetSelectionEnd (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         double *pValue)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	double pValue__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetSelectionEnd_ (__vtblIFacePtr,
	                                                      &pValue__Temp));

	if (pValue)
		{
		*pValue = pValue__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetSelectionEnd (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         double pValue)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetSelectionEnd_ (__vtblIFacePtr,
	                                                      pValue));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetShowDisplay (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *show)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL show__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetShowDisplay_ (__vtblIFacePtr,
	                                                     &show__Temp));

	if (show)
		{
		*show = show__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetShowDisplay (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL show)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetShowDisplay_ (__vtblIFacePtr, show));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetShowControls (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL *show)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL show__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetShowControls_ (__vtblIFacePtr,
	                                                      &show__Temp));

	if (show)
		{
		*show = show__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetShowControls (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL show)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetShowControls_ (__vtblIFacePtr, show));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetShowPositionControls (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 VBOOL *show)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL show__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetShowPositionControls_ (__vtblIFacePtr,
	                                                              &show__Temp));

	if (show)
		{
		*show = show__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetShowPositionControls (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 VBOOL show)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetShowPositionControls_ (__vtblIFacePtr,
	                                                              show));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetShowTracker (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *show)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL show__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetShowTracker_ (__vtblIFacePtr,
	                                                     &show__Temp));

	if (show)
		{
		*show = show__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetShowTracker (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL show)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetShowTracker_ (__vtblIFacePtr, show));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetEnablePositionControls (CAObjHandle objectHandle,
                                                                   ERRORINFO *errorInfo,
                                                                   VBOOL *enable)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL enable__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetEnablePositionControls_ (__vtblIFacePtr,
	                                                                &enable__Temp));

	if (enable)
		{
		*enable = enable__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetEnablePositionControls (CAObjHandle objectHandle,
                                                                   ERRORINFO *errorInfo,
                                                                   VBOOL enable)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetEnablePositionControls_ (__vtblIFacePtr,
	                                                                enable));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetEnableTracker (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL *enable)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL enable__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetEnableTracker_ (__vtblIFacePtr,
	                                                       &enable__Temp));

	if (enable)
		{
		*enable = enable__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetEnableTracker (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL enable)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetEnableTracker_ (__vtblIFacePtr,
	                                                       enable));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetEnabled (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL *pEnabled)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pEnabled__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetEnabled_ (__vtblIFacePtr,
	                                                 &pEnabled__Temp));

	if (pEnabled)
		{
		*pEnabled = pEnabled__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetEnabled (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL pEnabled)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetEnabled_ (__vtblIFacePtr, pEnabled));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetDisplayForeColor (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             MediaPlayerType_VB_OLE_COLOR *foreColor)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	unsigned long foreColor__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetDisplayForeColor_ (__vtblIFacePtr,
	                                                          &foreColor__Temp));

	if (foreColor)
		{
		*foreColor = foreColor__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetDisplayForeColor (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             MediaPlayerType_VB_OLE_COLOR foreColor)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetDisplayForeColor_ (__vtblIFacePtr,
	                                                          foreColor));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetDisplayBackColor (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             MediaPlayerType_VB_OLE_COLOR *backColor)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	unsigned long backColor__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetDisplayBackColor_ (__vtblIFacePtr,
	                                                          &backColor__Temp));

	if (backColor)
		{
		*backColor = backColor__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetDisplayBackColor (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             MediaPlayerType_VB_OLE_COLOR backColor)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetDisplayBackColor_ (__vtblIFacePtr,
	                                                          backColor));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetDisplayMode (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        enum MediaPlayerEnum_MPDisplayModeConstants *pValue)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pValue__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetDisplayMode_ (__vtblIFacePtr,
	                                                     (long *)&pValue__Temp));

	if (pValue)
		{
		*pValue = pValue__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetDisplayMode (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        enum MediaPlayerEnum_MPDisplayModeConstants pValue)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetDisplayMode_ (__vtblIFacePtr,
	                                                     pValue));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetVideoBorder3D (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL *pVideoBorderWidth)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pVideoBorderWidth__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetVideoBorder3D_ (__vtblIFacePtr,
	                                                       &pVideoBorderWidth__Temp));

	if (pVideoBorderWidth)
		{
		*pVideoBorderWidth = pVideoBorderWidth__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetVideoBorder3D (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL pVideoBorderWidth)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetVideoBorder3D_ (__vtblIFacePtr,
	                                                       pVideoBorderWidth));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetVideoBorderWidth (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             long *pVideoBorderWidth)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pVideoBorderWidth__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetVideoBorderWidth_ (__vtblIFacePtr,
	                                                          &pVideoBorderWidth__Temp));

	if (pVideoBorderWidth)
		{
		*pVideoBorderWidth = pVideoBorderWidth__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetVideoBorderWidth (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             long pVideoBorderWidth)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetVideoBorderWidth_ (__vtblIFacePtr,
	                                                          pVideoBorderWidth));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetVideoBorderColor (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             MediaPlayerType_VB_OLE_COLOR *pVideoBorderWidth)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	unsigned long pVideoBorderWidth__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetVideoBorderColor_ (__vtblIFacePtr,
	                                                          &pVideoBorderWidth__Temp));

	if (pVideoBorderWidth)
		{
		*pVideoBorderWidth = pVideoBorderWidth__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetVideoBorderColor (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             MediaPlayerType_VB_OLE_COLOR pVideoBorderWidth)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetVideoBorderColor_ (__vtblIFacePtr,
	                                                          pVideoBorderWidth));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetShowGotoBar (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *pbool)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pbool__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetShowGotoBar_ (__vtblIFacePtr,
	                                                     &pbool__Temp));

	if (pbool)
		{
		*pbool = pbool__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetShowGotoBar (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL pbool)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetShowGotoBar_ (__vtblIFacePtr, pbool));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetShowStatusBar (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL *pbool)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pbool__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetShowStatusBar_ (__vtblIFacePtr,
	                                                       &pbool__Temp));

	if (pbool)
		{
		*pbool = pbool__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetShowStatusBar (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL pbool)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetShowStatusBar_ (__vtblIFacePtr,
	                                                       pbool));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetShowCaptioning (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           VBOOL *pbool)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pbool__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetShowCaptioning_ (__vtblIFacePtr,
	                                                        &pbool__Temp));

	if (pbool)
		{
		*pbool = pbool__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetShowCaptioning (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           VBOOL pbool)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetShowCaptioning_ (__vtblIFacePtr,
	                                                        pbool));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetShowAudioControls (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              VBOOL *pbool)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pbool__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetShowAudioControls_ (__vtblIFacePtr,
	                                                           &pbool__Temp));

	if (pbool)
		{
		*pbool = pbool__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetShowAudioControls (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              VBOOL pbool)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetShowAudioControls_ (__vtblIFacePtr,
	                                                           pbool));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetCaptioningID (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         char **pstrText)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pstrText__AutoType = 0;

	if (pstrText)
		*pstrText = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCaptioningID_ (__vtblIFacePtr,
	                                                      &pstrText__AutoType));

	if (pstrText)
		__caErrChk (CA_BSTRGetCString (pstrText__AutoType, pstrText));

Error:
	CA_FreeBSTR (pstrText__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pstrText)
			{
			CA_FreeMemory (*pstrText);
			*pstrText = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetCaptioningID (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         const char *pstrText)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pstrText__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (pstrText, &pstrText__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCaptioningID_ (__vtblIFacePtr,
	                                                      pstrText__AutoType));

Error:
	CA_FreeBSTR (pstrText__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetMute (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL *vbool)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL vbool__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetMute_ (__vtblIFacePtr, &vbool__Temp));

	if (vbool)
		{
		*vbool = vbool__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetMute (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL vbool)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetMute_ (__vtblIFacePtr, vbool));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetCanPreview (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL *pCanPreview)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pCanPreview__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCanPreview_ (__vtblIFacePtr,
	                                                    &pCanPreview__Temp));

	if (pCanPreview)
		{
		*pCanPreview = pCanPreview__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetPreviewMode (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *pPreviewMode)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pPreviewMode__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPreviewMode_ (__vtblIFacePtr,
	                                                     &pPreviewMode__Temp));

	if (pPreviewMode)
		{
		*pPreviewMode = pPreviewMode__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetPreviewMode (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL pPreviewMode)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetPreviewMode_ (__vtblIFacePtr,
	                                                     pPreviewMode));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetHasMultipleItems (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL *pHasMuliItems)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pHasMuliItems__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetHasMultipleItems_ (__vtblIFacePtr,
	                                                          &pHasMuliItems__Temp));

	if (pHasMuliItems)
		{
		*pHasMuliItems = pHasMuliItems__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetLanguage (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long *pLanguage)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pLanguage__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetLanguage_ (__vtblIFacePtr,
	                                                  &pLanguage__Temp));

	if (pLanguage)
		{
		*pLanguage = pLanguage__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetLanguage (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long pLanguage)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetLanguage_ (__vtblIFacePtr,
	                                                  pLanguage));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetAudioStream (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        long *pStream)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pStream__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetAudioStream_ (__vtblIFacePtr,
	                                                     &pStream__Temp));

	if (pStream)
		{
		*pStream = pStream__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetAudioStream (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        long pStream)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetAudioStream_ (__vtblIFacePtr,
	                                                     pStream));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetSAMIStyle (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      char **pbstrStyle)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrStyle__AutoType = 0;

	if (pbstrStyle)
		*pbstrStyle = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetSAMIStyle_ (__vtblIFacePtr,
	                                                   &pbstrStyle__AutoType));

	if (pbstrStyle)
		__caErrChk (CA_BSTRGetCString (pbstrStyle__AutoType, pbstrStyle));

Error:
	CA_FreeBSTR (pbstrStyle__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pbstrStyle)
			{
			CA_FreeMemory (*pbstrStyle);
			*pbstrStyle = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetSAMIStyle (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      const char *pbstrStyle)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrStyle__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (pbstrStyle, &pbstrStyle__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetSAMIStyle_ (__vtblIFacePtr,
	                                                   pbstrStyle__AutoType));

Error:
	CA_FreeBSTR (pbstrStyle__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetSAMILang (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     char **pbstrLang)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrLang__AutoType = 0;

	if (pbstrLang)
		*pbstrLang = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetSAMILang_ (__vtblIFacePtr,
	                                                  &pbstrLang__AutoType));

	if (pbstrLang)
		__caErrChk (CA_BSTRGetCString (pbstrLang__AutoType, pbstrLang));

Error:
	CA_FreeBSTR (pbstrLang__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pbstrLang)
			{
			CA_FreeMemory (*pbstrLang);
			*pbstrLang = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetSAMILang (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     const char *pbstrLang)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrLang__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (pbstrLang, &pbstrLang__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetSAMILang_ (__vtblIFacePtr,
	                                                  pbstrLang__AutoType));

Error:
	CA_FreeBSTR (pbstrLang__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetSAMIFileName (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         char **pbstrFileName)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrFileName__AutoType = 0;

	if (pbstrFileName)
		*pbstrFileName = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetSAMIFileName_ (__vtblIFacePtr,
	                                                      &pbstrFileName__AutoType));

	if (pbstrFileName)
		__caErrChk (CA_BSTRGetCString (pbstrFileName__AutoType, pbstrFileName));

Error:
	CA_FreeBSTR (pbstrFileName__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pbstrFileName)
			{
			CA_FreeMemory (*pbstrFileName);
			*pbstrFileName = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetSAMIFileName (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         const char *pbstrFileName)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrFileName__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (pbstrFileName, &pbstrFileName__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetSAMIFileName_ (__vtblIFacePtr,
	                                                      pbstrFileName__AutoType));

Error:
	CA_FreeBSTR (pbstrFileName__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetStreamCount (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        long *pStreamCount)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pStreamCount__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetStreamCount_ (__vtblIFacePtr,
	                                                     &pStreamCount__Temp));

	if (pStreamCount)
		{
		*pStreamCount = pStreamCount__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetClientId (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     char **pbstrClientId)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrClientId__AutoType = 0;

	if (pbstrClientId)
		*pbstrClientId = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetClientId_ (__vtblIFacePtr,
	                                                  &pbstrClientId__AutoType));

	if (pbstrClientId)
		__caErrChk (CA_BSTRGetCString (pbstrClientId__AutoType, pbstrClientId));

Error:
	CA_FreeBSTR (pbstrClientId__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pbstrClientId)
			{
			CA_FreeMemory (*pbstrClientId);
			*pbstrClientId = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetConnectionSpeed (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            long *plConnectionSpeed)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long plConnectionSpeed__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetConnectionSpeed_ (__vtblIFacePtr,
	                                                         &plConnectionSpeed__Temp));

	if (plConnectionSpeed)
		{
		*plConnectionSpeed = plConnectionSpeed__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetAutoSize (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL *pbool)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pbool__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetAutoSize_ (__vtblIFacePtr,
	                                                  &pbool__Temp));

	if (pbool)
		{
		*pbool = pbool__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetAutoSize (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL pbool)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetAutoSize_ (__vtblIFacePtr, pbool));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetEnableFullScreenControls (CAObjHandle objectHandle,
                                                                     ERRORINFO *errorInfo,
                                                                     VBOOL *pbVal)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pbVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetEnableFullScreenControls_ (__vtblIFacePtr,
	                                                                  &pbVal__Temp));

	if (pbVal)
		{
		*pbVal = pbVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetEnableFullScreenControls (CAObjHandle objectHandle,
                                                                     ERRORINFO *errorInfo,
                                                                     VBOOL pbVal)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetEnableFullScreenControls_ (__vtblIFacePtr,
	                                                                  pbVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetActiveMovie (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        CAObjHandle *ppdispatch)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	LPDISPATCH ppdispatch__AutoType = 0;
	LCID __locale;
	int __supportMultithreading;

	if (ppdispatch)
		*ppdispatch = 0;

	__caErrChk (CA_GetLocale (objectHandle, &__locale));
	__caErrChk (CA_GetSupportForMultithreading (objectHandle,
	                                            &__supportMultithreading));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetActiveMovie_ (__vtblIFacePtr,
	                                                     &ppdispatch__AutoType));
	

	if (ppdispatch)
		{
		__caErrChk (CA_CreateObjHandleFromInterface (ppdispatch__AutoType,
		                                             &IID_IDispatch,
		                                             __supportMultithreading,
		                                             __locale, 0, 0, ppdispatch));
		ppdispatch__AutoType = 0;
		}

Error:
	if (ppdispatch__AutoType)
		ppdispatch__AutoType->lpVtbl->Release (ppdispatch__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (ppdispatch)
			{
			CA_DiscardObjHandle (*ppdispatch);
			*ppdispatch = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetNSPlay (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   CAObjHandle *ppdispatch)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	LPDISPATCH ppdispatch__AutoType = 0;
	LCID __locale;
	int __supportMultithreading;

	if (ppdispatch)
		*ppdispatch = 0;

	__caErrChk (CA_GetLocale (objectHandle, &__locale));
	__caErrChk (CA_GetSupportForMultithreading (objectHandle,
	                                            &__supportMultithreading));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetNSPlay_ (__vtblIFacePtr,
	                                                &ppdispatch__AutoType));
	

	if (ppdispatch)
		{
		__caErrChk (CA_CreateObjHandleFromInterface (ppdispatch__AutoType,
		                                             &IID_IDispatch,
		                                             __supportMultithreading,
		                                             __locale, 0, 0, ppdispatch));
		ppdispatch__AutoType = 0;
		}

Error:
	if (ppdispatch__AutoType)
		ppdispatch__AutoType->lpVtbl->Release (ppdispatch__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (ppdispatch)
			{
			CA_DiscardObjHandle (*ppdispatch);
			*ppdispatch = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetWindowlessVideo (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VBOOL *pbool)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pbool__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetWindowlessVideo_ (__vtblIFacePtr,
	                                                         &pbool__Temp));

	if (pbool)
		{
		*pbool = pbool__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetWindowlessVideo (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VBOOL pbool)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetWindowlessVideo_ (__vtblIFacePtr,
	                                                         pbool));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerPlay (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->Play_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerStop (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->Stop_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerPause (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->Pause_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetMarkerTime (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long markerNum,
                                                       double *pMarkerTime)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	double pMarkerTime__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetMarkerTime_ (__vtblIFacePtr,
	                                                    markerNum,
	                                                    &pMarkerTime__Temp));

	if (pMarkerTime)
		{
		*pMarkerTime = pMarkerTime__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetMarkerName (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long markerNum,
                                                       char **pbstrMarkerName)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrMarkerName__AutoType = 0;

	if (pbstrMarkerName)
		*pbstrMarkerName = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetMarkerName_ (__vtblIFacePtr,
	                                                    markerNum,
	                                                    &pbstrMarkerName__AutoType));

	if (pbstrMarkerName)
		__caErrChk (CA_BSTRGetCString (pbstrMarkerName__AutoType, pbstrMarkerName));

Error:
	CA_FreeBSTR (pbstrMarkerName__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pbstrMarkerName)
			{
			CA_FreeMemory (*pbstrMarkerName);
			*pbstrMarkerName = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerAboutBox (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->AboutBox_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetCodecInstalled (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           long codecNum,
                                                           VBOOL *pCodecInstalled)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pCodecInstalled__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCodecInstalled_ (__vtblIFacePtr,
	                                                        codecNum,
	                                                        &pCodecInstalled__Temp));

	if (pCodecInstalled)
		{
		*pCodecInstalled = pCodecInstalled__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetCodecDescription (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             long codecNum,
                                                             char **pbstrCodecDescription)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrCodecDescription__AutoType = 0;

	if (pbstrCodecDescription)
		*pbstrCodecDescription = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCodecDescription_ (__vtblIFacePtr,
	                                                          codecNum,
	                                                          &pbstrCodecDescription__AutoType));

	if (pbstrCodecDescription)
		__caErrChk (CA_BSTRGetCString (pbstrCodecDescription__AutoType,
	                               pbstrCodecDescription));

Error:
	CA_FreeBSTR (pbstrCodecDescription__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pbstrCodecDescription)
			{
			CA_FreeMemory (*pbstrCodecDescription);
			*pbstrCodecDescription = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetCodecURL (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long codecNum,
                                                     char **pbstrCodecURL)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrCodecURL__AutoType = 0;

	if (pbstrCodecURL)
		*pbstrCodecURL = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCodecURL_ (__vtblIFacePtr, codecNum,
	                                                  &pbstrCodecURL__AutoType));

	if (pbstrCodecURL)
		__caErrChk (CA_BSTRGetCString (pbstrCodecURL__AutoType, pbstrCodecURL));

Error:
	CA_FreeBSTR (pbstrCodecURL__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pbstrCodecURL)
			{
			CA_FreeMemory (*pbstrCodecURL);
			*pbstrCodecURL = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetMoreInfoURL (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        enum MediaPlayerEnum_MPMoreInfoType moreInfoType,
                                                        char **pbstrMoreInfoURL)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrMoreInfoURL__AutoType = 0;

	if (pbstrMoreInfoURL)
		*pbstrMoreInfoURL = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetMoreInfoURL_ (__vtblIFacePtr,
	                                                     moreInfoType,
	                                                     &pbstrMoreInfoURL__AutoType));

	if (pbstrMoreInfoURL)
		__caErrChk (CA_BSTRGetCString (pbstrMoreInfoURL__AutoType,
	                               pbstrMoreInfoURL));

Error:
	CA_FreeBSTR (pbstrMoreInfoURL__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pbstrMoreInfoURL)
			{
			CA_FreeMemory (*pbstrMoreInfoURL);
			*pbstrMoreInfoURL = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetMediaInfoString (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            enum MediaPlayerEnum_MPMediaInfoType mediaInfoType,
                                                            char **pbstrMediaInfo)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrMediaInfo__AutoType = 0;

	if (pbstrMediaInfo)
		*pbstrMediaInfo = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetMediaInfoString_ (__vtblIFacePtr,
	                                                         mediaInfoType,
	                                                         &pbstrMediaInfo__AutoType));

	if (pbstrMediaInfo)
		__caErrChk (CA_BSTRGetCString (pbstrMediaInfo__AutoType, pbstrMediaInfo));

Error:
	CA_FreeBSTR (pbstrMediaInfo__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pbstrMediaInfo)
			{
			CA_FreeMemory (*pbstrMediaInfo);
			*pbstrMediaInfo = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerCancel (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->Cancel_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerOpen (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              const char *bstrFileName)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR bstrFileName__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (bstrFileName, &bstrFileName__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->Open_ (__vtblIFacePtr,
	                                           bstrFileName__AutoType));

Error:
	CA_FreeBSTR (bstrFileName__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerIsSoundCardEnabled (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VBOOL *pbSoundCard)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pbSoundCard__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->IsSoundCardEnabled_ (__vtblIFacePtr,
	                                                         &pbSoundCard__Temp));

	if (pbSoundCard)
		{
		*pbSoundCard = pbSoundCard__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerNext (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->Next_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerPrevious (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->Previous_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerStreamSelect (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long streamNum)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->StreamSelect_ (__vtblIFacePtr,
	                                                   streamNum));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerFastForward (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->FastForward_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerFastReverse (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->FastReverse_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetStreamName (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long streamNum,
                                                       char **pbstrStreamName)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrStreamName__AutoType = 0;

	if (pbstrStreamName)
		*pbstrStreamName = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetStreamName_ (__vtblIFacePtr,
	                                                    streamNum,
	                                                    &pbstrStreamName__AutoType));

	if (pbstrStreamName)
		__caErrChk (CA_BSTRGetCString (pbstrStreamName__AutoType, pbstrStreamName));

Error:
	CA_FreeBSTR (pbstrStreamName__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pbstrStreamName)
			{
			CA_FreeMemory (*pbstrStreamName);
			*pbstrStreamName = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetStreamGroup (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        long streamNum,
                                                        long *pStreamGroup)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	long pStreamGroup__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetStreamGroup_ (__vtblIFacePtr,
	                                                     streamNum,
	                                                     &pStreamGroup__Temp));

	if (pStreamGroup)
		{
		*pStreamGroup = pStreamGroup__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetStreamSelected (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           long streamNum,
                                                           VBOOL *pStreamSelected)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayer_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL pStreamSelected__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayer, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetStreamSelected_ (__vtblIFacePtr,
	                                                        streamNum,
	                                                        &pStreamSelected__Temp));

	if (pStreamSelected)
		{
		*pStreamSelected = pStreamSelected__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayer, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdButtonSelectAndActivate (CAObjHandle objectHandle,
                                                                    ERRORINFO *errorInfo,
                                                                    unsigned long uiButton)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->ButtonSelectAndActivate_ (__vtblIFacePtr,
	                                                              uiButton));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdUpperButtonSelect (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->UpperButtonSelect_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdLowerButtonSelect (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->LowerButtonSelect_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdLeftButtonSelect (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->LeftButtonSelect_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdRightButtonSelect (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->RightButtonSelect_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdButtonActivate (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->ButtonActivate_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdForwardScan (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        double dwSpeed)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->ForwardScan_ (__vtblIFacePtr, dwSpeed));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdBackwardScan (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         double dwSpeed)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->BackwardScan_ (__vtblIFacePtr, dwSpeed));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdPrevPGSearch (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->PrevPGSearch_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdTopPGSearch (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->TopPGSearch_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdNextPGSearch (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->NextPGSearch_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdTitlePlay (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      unsigned long uiTitle)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->TitlePlay_ (__vtblIFacePtr, uiTitle));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdChapterPlay (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        unsigned long uiTitle,
                                                        unsigned long uiChapter)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->ChapterPlay_ (__vtblIFacePtr, uiTitle,
	                                                  uiChapter));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdChapterSearch (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          unsigned long chapter)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->ChapterSearch_ (__vtblIFacePtr,
	                                                    chapter));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdMenuCall (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     enum MediaPlayerEnum_DVDMenuIDConstants menuID)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->MenuCall_ (__vtblIFacePtr, menuID));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdResumeFromMenu (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->ResumeFromMenu_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdTimePlay (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     unsigned long uiTitle,
                                                     const char *bstrTime)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR bstrTime__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (bstrTime, &bstrTime__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->TimePlay_ (__vtblIFacePtr, uiTitle,
	                                               bstrTime__AutoType));

Error:
	CA_FreeBSTR (bstrTime__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdTimeSearch (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       const char *bstrTime)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR bstrTime__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (bstrTime, &bstrTime__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->TimeSearch_ (__vtblIFacePtr,
	                                                 bstrTime__AutoType));

Error:
	CA_FreeBSTR (bstrTime__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdChapterPlayAutoStop (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                unsigned long ulTitle,
                                                                unsigned long ulChapter,
                                                                unsigned long ulChaptersToPlay)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->ChapterPlayAutoStop_ (__vtblIFacePtr,
	                                                          ulTitle,
	                                                          ulChapter,
	                                                          ulChaptersToPlay));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdStillOff (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->StillOff_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGoUp (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GoUp_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetTotalTitleTime (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              char **bstrTime)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR bstrTime__AutoType = 0;

	if (bstrTime)
		*bstrTime = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetTotalTitleTime_ (__vtblIFacePtr,
	                                                        &bstrTime__AutoType));

	if (bstrTime)
		__caErrChk (CA_BSTRGetCString (bstrTime__AutoType, bstrTime));

Error:
	CA_FreeBSTR (bstrTime__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (bstrTime)
			{
			CA_FreeMemory (*bstrTime);
			*bstrTime = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetNumberOfChapters (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                unsigned long ulTitle,
                                                                unsigned long *ulNumChapters)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	unsigned long ulNumChapters__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetNumberOfChapters_ (__vtblIFacePtr,
	                                                          ulTitle,
	                                                          &ulNumChapters__Temp));

	if (ulNumChapters)
		{
		*ulNumChapters = ulNumChapters__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetAudioLanguage (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             unsigned long ulStream,
                                                             char **bstrAudioLang)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR bstrAudioLang__AutoType = 0;

	if (bstrAudioLang)
		*bstrAudioLang = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetAudioLanguage_ (__vtblIFacePtr,
	                                                       ulStream,
	                                                       &bstrAudioLang__AutoType));

	if (bstrAudioLang)
		__caErrChk (CA_BSTRGetCString (bstrAudioLang__AutoType, bstrAudioLang));

Error:
	CA_FreeBSTR (bstrAudioLang__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (bstrAudioLang)
			{
			CA_FreeMemory (*bstrAudioLang);
			*bstrAudioLang = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetSubpictureLanguage (CAObjHandle objectHandle,
                                                                  ERRORINFO *errorInfo,
                                                                  unsigned long ulStream,
                                                                  char **bstrSubpictureLang)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR bstrSubpictureLang__AutoType = 0;

	if (bstrSubpictureLang)
		*bstrSubpictureLang = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetSubpictureLanguage_ (__vtblIFacePtr,
	                                                            ulStream,
	                                                            &bstrSubpictureLang__AutoType));

	if (bstrSubpictureLang)
		__caErrChk (CA_BSTRGetCString (bstrSubpictureLang__AutoType,
	                               bstrSubpictureLang));

Error:
	CA_FreeBSTR (bstrSubpictureLang__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (bstrSubpictureLang)
			{
			CA_FreeMemory (*bstrSubpictureLang);
			*bstrSubpictureLang = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetAllGPRMs (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VARIANT *vtGPRM)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VARIANT vtGPRM__Temp;

	if (vtGPRM)
		CA_VariantSetEmpty (vtGPRM);
	CA_VariantSetEmpty (&vtGPRM__Temp);

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetAllGPRMs_ (__vtblIFacePtr,
	                                                  &vtGPRM__Temp));

	if (vtGPRM)
		{
		*vtGPRM = vtGPRM__Temp;
		CA_VariantSetEmpty (&vtGPRM__Temp);
		}

Error:
	CA_VariantClear (&vtGPRM__Temp);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (vtGPRM)
			CA_VariantClear (vtGPRM);
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetAllSPRMs (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VARIANT *vtSPRM)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VARIANT vtSPRM__Temp;

	if (vtSPRM)
		CA_VariantSetEmpty (vtSPRM);
	CA_VariantSetEmpty (&vtSPRM__Temp);

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetAllSPRMs_ (__vtblIFacePtr,
	                                                  &vtSPRM__Temp));

	if (vtSPRM)
		{
		*vtSPRM = vtSPRM__Temp;
		CA_VariantSetEmpty (&vtSPRM__Temp);
		}

Error:
	CA_VariantClear (&vtSPRM__Temp);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (vtSPRM)
			CA_VariantClear (vtSPRM);
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdUOPValid (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     unsigned long ulUOP,
                                                     VBOOL *bValid)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL bValid__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->UOPValid_ (__vtblIFacePtr, ulUOP,
	                                               &bValid__Temp));

	if (bValid)
		{
		*bValid = bValid__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetButtonsAvailable (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                unsigned long *ulButtonsAvailable)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	unsigned long ulButtonsAvailable__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetButtonsAvailable_ (__vtblIFacePtr,
	                                                          &ulButtonsAvailable__Temp));

	if (ulButtonsAvailable)
		{
		*ulButtonsAvailable = ulButtonsAvailable__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetCurrentButton (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             unsigned long *ulCurrentButton)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	unsigned long ulCurrentButton__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCurrentButton_ (__vtblIFacePtr,
	                                                       &ulCurrentButton__Temp));

	if (ulCurrentButton)
		{
		*ulCurrentButton = ulCurrentButton__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetAudioStreamsAvailable (CAObjHandle objectHandle,
                                                                     ERRORINFO *errorInfo,
                                                                     unsigned long *ulAudioStreamsAvailable)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	unsigned long ulAudioStreamsAvailable__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetAudioStreamsAvailable_ (__vtblIFacePtr,
	                                                               &ulAudioStreamsAvailable__Temp));

	if (ulAudioStreamsAvailable)
		{
		*ulAudioStreamsAvailable = ulAudioStreamsAvailable__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetCurrentAudioStream (CAObjHandle objectHandle,
                                                                  ERRORINFO *errorInfo,
                                                                  unsigned long *ulAudioStream)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	unsigned long ulAudioStream__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCurrentAudioStream_ (__vtblIFacePtr,
	                                                            &ulAudioStream__Temp));

	if (ulAudioStream)
		{
		*ulAudioStream = ulAudioStream__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdSetCurrentAudioStream (CAObjHandle objectHandle,
                                                                  ERRORINFO *errorInfo,
                                                                  unsigned long ulAudioStream)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCurrentAudioStream_ (__vtblIFacePtr,
	                                                            ulAudioStream));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetCurrentSubpictureStream (CAObjHandle objectHandle,
                                                                       ERRORINFO *errorInfo,
                                                                       unsigned long *ulSubpictureStream)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	unsigned long ulSubpictureStream__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCurrentSubpictureStream_ (__vtblIFacePtr,
	                                                                 &ulSubpictureStream__Temp));

	if (ulSubpictureStream)
		{
		*ulSubpictureStream = ulSubpictureStream__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdSetCurrentSubpictureStream (CAObjHandle objectHandle,
                                                                       ERRORINFO *errorInfo,
                                                                       unsigned long ulSubpictureStream)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCurrentSubpictureStream_ (__vtblIFacePtr,
	                                                                 ulSubpictureStream));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetSubpictureStreamsAvailable (CAObjHandle objectHandle,
                                                                          ERRORINFO *errorInfo,
                                                                          unsigned long *ulNumSubpictureStreams)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	unsigned long ulNumSubpictureStreams__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetSubpictureStreamsAvailable_ (__vtblIFacePtr,
	                                                                    &ulNumSubpictureStreams__Temp));

	if (ulNumSubpictureStreams)
		{
		*ulNumSubpictureStreams = ulNumSubpictureStreams__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetSubpictureOn (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VBOOL *bSubpictureON)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL bSubpictureON__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetSubpictureOn_ (__vtblIFacePtr,
	                                                      &bSubpictureON__Temp));

	if (bSubpictureON)
		{
		*bSubpictureON = bSubpictureON__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdSetSubpictureOn (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VBOOL bSubpictureON)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetSubpictureOn_ (__vtblIFacePtr,
	                                                      bSubpictureON));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetAnglesAvailable (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               unsigned long *ulAnglesAvailable)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	unsigned long ulAnglesAvailable__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetAnglesAvailable_ (__vtblIFacePtr,
	                                                         &ulAnglesAvailable__Temp));

	if (ulAnglesAvailable)
		{
		*ulAnglesAvailable = ulAnglesAvailable__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetCurrentAngle (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            unsigned long *ulAngle)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	unsigned long ulAngle__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCurrentAngle_ (__vtblIFacePtr,
	                                                      &ulAngle__Temp));

	if (ulAngle)
		{
		*ulAngle = ulAngle__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdSetCurrentAngle (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            unsigned long ulAngle)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCurrentAngle_ (__vtblIFacePtr,
	                                                      ulAngle));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetCurrentTitle (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            unsigned long *ulTitle)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	unsigned long ulTitle__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCurrentTitle_ (__vtblIFacePtr,
	                                                      &ulTitle__Temp));

	if (ulTitle)
		{
		*ulTitle = ulTitle__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetCurrentChapter (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              unsigned long *ulChapter)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	unsigned long ulChapter__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCurrentChapter_ (__vtblIFacePtr,
	                                                        &ulChapter__Temp));

	if (ulChapter)
		{
		*ulChapter = ulChapter__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetCurrentTime (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           char **bstrTime)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR bstrTime__AutoType = 0;

	if (bstrTime)
		*bstrTime = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCurrentTime_ (__vtblIFacePtr,
	                                                     &bstrTime__AutoType));

	if (bstrTime)
		__caErrChk (CA_BSTRGetCString (bstrTime__AutoType, bstrTime));

Error:
	CA_FreeBSTR (bstrTime__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (bstrTime)
			{
			CA_FreeMemory (*bstrTime);
			*bstrTime = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdSetRoot (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    const char *pbstrPath)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrPath__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (pbstrPath, &pbstrPath__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetRoot_ (__vtblIFacePtr,
	                                              pbstrPath__AutoType));

Error:
	CA_FreeBSTR (pbstrPath__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetRoot (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    char **pbstrPath)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pbstrPath__AutoType = 0;

	if (pbstrPath)
		*pbstrPath = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetRoot_ (__vtblIFacePtr,
	                                              &pbstrPath__AutoType));

	if (pbstrPath)
		__caErrChk (CA_BSTRGetCString (pbstrPath__AutoType, pbstrPath));

Error:
	CA_FreeBSTR (pbstrPath__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pbstrPath)
			{
			CA_FreeMemory (*pbstrPath);
			*pbstrPath = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetFramesPerSecond (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               unsigned long *ulFps)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	unsigned long ulFps__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetFramesPerSecond_ (__vtblIFacePtr,
	                                                         &ulFps__Temp));

	if (ulFps)
		{
		*ulFps = ulFps__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetCurrentDomain (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             unsigned long *ulDomain)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	unsigned long ulDomain__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCurrentDomain_ (__vtblIFacePtr,
	                                                       &ulDomain__Temp));

	if (ulDomain)
		{
		*ulDomain = ulDomain__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetTitlesAvailable (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               unsigned long *ulTitles)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	unsigned long ulTitles__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetTitlesAvailable_ (__vtblIFacePtr,
	                                                         &ulTitles__Temp));

	if (ulTitles)
		{
		*ulTitles = ulTitles__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetVolumesAvailable (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                unsigned long *pulVolumes)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	unsigned long pulVolumes__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetVolumesAvailable_ (__vtblIFacePtr,
	                                                          &pulVolumes__Temp));

	if (pulVolumes)
		{
		*pulVolumes = pulVolumes__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetCurrentVolume (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             unsigned long *pulVolume)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	unsigned long pulVolume__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCurrentVolume_ (__vtblIFacePtr,
	                                                       &pulVolume__Temp));

	if (pulVolume)
		{
		*pulVolume = pulVolume__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetCurrentDiscSide (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               unsigned long *pulDiscSide)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	unsigned long pulDiscSide__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCurrentDiscSide_ (__vtblIFacePtr,
	                                                         &pulDiscSide__Temp));

	if (pulDiscSide)
		{
		*pulDiscSide = pulDiscSide__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetCCActive (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *bCCActive)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	VBOOL bCCActive__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCCActive_ (__vtblIFacePtr,
	                                                  &bCCActive__Temp));

	if (bCCActive)
		{
		*bCCActive = bCCActive__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdSetCCActive (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL bCCActive)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCCActive_ (__vtblIFacePtr,
	                                                  bCCActive));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetCurrentCCService (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                unsigned long *pulService)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	unsigned long pulService__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCurrentCCService_ (__vtblIFacePtr,
	                                                          &pulService__Temp));

	if (pulService)
		{
		*pulService = pulService__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdSetCurrentCCService (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                unsigned long pulService)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCurrentCCService_ (__vtblIFacePtr,
	                                                          pulService));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetUniqueID (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        char **pvtUniqueID)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	BSTR pvtUniqueID__AutoType = 0;

	if (pvtUniqueID)
		*pvtUniqueID = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetUniqueID_ (__vtblIFacePtr,
	                                                  &pvtUniqueID__AutoType));

	if (pvtUniqueID)
		__caErrChk (CA_BSTRGetCString (pvtUniqueID__AutoType, pvtUniqueID));

Error:
	CA_FreeBSTR (pvtUniqueID__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pvtUniqueID)
			{
			CA_FreeMemory (*pvtUniqueID);
			*pvtUniqueID = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetColorKey (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        unsigned long *pClr)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;
	unsigned long pClr__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetColorKey_ (__vtblIFacePtr,
	                                                  &pClr__Temp));

	if (pClr)
		{
		*pClr = pClr__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdSetColorKey (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        unsigned long pClr)
{
	HRESULT __result = S_OK;
	MediaPlayer_IMediaPlayerDvd_Interface * __vtblIFacePtr = 0;
	int __didAddRef;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &MediaPlayer_IID_IMediaPlayerDvd,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetColorKey_ (__vtblIFacePtr, pClr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &MediaPlayer_IID_IMediaPlayerDvd,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

static void CVIFUNC _MediaPlayerEventsRegOnDVDNotify_EventVTableFunc (void *thisPtr,
                                                                      long eventCode,
                                                                      long eventParam1,
                                                                      long eventParam2)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	_MediaPlayerEventsRegOnDVDNotify_CallbackType __callbackFunction;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 0, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, eventCode,
		                               eventParam1, eventParam2);
	
		__caErrChk (__result);
		
		}
Error:

	return;
}

static void CVIFUNC _MediaPlayerEventsRegOnEndOfStream_EventVTableFunc (void *thisPtr,
                                                                        long result)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	_MediaPlayerEventsRegOnEndOfStream_CallbackType __callbackFunction;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 1, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, result);
	
		__caErrChk (__result);
		
		}
Error:

	return;
}

static void CVIFUNC _MediaPlayerEventsRegOnKeyDown_EventVTableFunc (void *thisPtr,
                                                                    short keyCode,
                                                                    short shiftState)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	_MediaPlayerEventsRegOnKeyDown_CallbackType __callbackFunction;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 2, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, keyCode,
		                               shiftState);
	
		__caErrChk (__result);
		
		}
Error:

	return;
}

static void CVIFUNC _MediaPlayerEventsRegOnKeyUp_EventVTableFunc (void *thisPtr,
                                                                  short keyCode,
                                                                  short shiftState)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	_MediaPlayerEventsRegOnKeyUp_CallbackType __callbackFunction;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 3, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, keyCode,
		                               shiftState);
	
		__caErrChk (__result);
		
		}
Error:

	return;
}

static void CVIFUNC _MediaPlayerEventsRegOnKeyPress_EventVTableFunc (void *thisPtr,
                                                                     short characterCode)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	_MediaPlayerEventsRegOnKeyPress_CallbackType __callbackFunction;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 4, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, characterCode);
	
		__caErrChk (__result);
		
		}
Error:

	return;
}

static void CVIFUNC _MediaPlayerEventsRegOnMouseMove_EventVTableFunc (void *thisPtr,
                                                                      short button,
                                                                      short shiftState,
                                                                      long x,
                                                                      long y)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	_MediaPlayerEventsRegOnMouseMove_CallbackType __callbackFunction;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 5, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, button,
		                               shiftState, x, y);
	
		__caErrChk (__result);
		
		}
Error:

	return;
}

static void CVIFUNC _MediaPlayerEventsRegOnMouseDown_EventVTableFunc (void *thisPtr,
                                                                      short button,
                                                                      short shiftState,
                                                                      long x,
                                                                      long y)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	_MediaPlayerEventsRegOnMouseDown_CallbackType __callbackFunction;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 6, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, button,
		                               shiftState, x, y);
	
		__caErrChk (__result);
		
		}
Error:

	return;
}

static void CVIFUNC _MediaPlayerEventsRegOnMouseUp_EventVTableFunc (void *thisPtr,
                                                                    short button,
                                                                    short shiftState,
                                                                    long x,
                                                                    long y)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	_MediaPlayerEventsRegOnMouseUp_CallbackType __callbackFunction;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 7, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, button,
		                               shiftState, x, y);
	
		__caErrChk (__result);
		
		}
Error:

	return;
}

static void CVIFUNC _MediaPlayerEventsRegOnClick_EventVTableFunc (void *thisPtr,
                                                                  short button,
                                                                  short shiftState,
                                                                  long x, long y)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	_MediaPlayerEventsRegOnClick_CallbackType __callbackFunction;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 8, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, button,
		                               shiftState, x, y);
	
		__caErrChk (__result);
		
		}
Error:

	return;
}

static void CVIFUNC _MediaPlayerEventsRegOnDblClick_EventVTableFunc (void *thisPtr,
                                                                     short button,
                                                                     short shiftState,
                                                                     long x,
                                                                     long y)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	_MediaPlayerEventsRegOnDblClick_CallbackType __callbackFunction;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 9, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, button,
		                               shiftState, x, y);
	
		__caErrChk (__result);
		
		}
Error:

	return;
}

static void CVIFUNC _MediaPlayerEventsRegOnOpenStateChange_EventVTableFunc (void *thisPtr,
                                                                            long oldState,
                                                                            long newState)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	_MediaPlayerEventsRegOnOpenStateChange_CallbackType __callbackFunction;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 10, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, oldState,
		                               newState);
	
		__caErrChk (__result);
		
		}
Error:

	return;
}

static void CVIFUNC _MediaPlayerEventsRegOnPlayStateChange_EventVTableFunc (void *thisPtr,
                                                                            long oldState,
                                                                            long newState)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	_MediaPlayerEventsRegOnPlayStateChange_CallbackType __callbackFunction;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 11, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, oldState,
		                               newState);
	
		__caErrChk (__result);
		
		}
Error:

	return;
}

static void CVIFUNC _MediaPlayerEventsRegOnScriptCommand_EventVTableFunc (void *thisPtr,
                                                                          BSTR scType,
                                                                          BSTR param)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	_MediaPlayerEventsRegOnScriptCommand_CallbackType __callbackFunction;
	char * scType__CType = 0;
	char * param__CType = 0;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 12, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
		__caErrChk (CA_BSTRGetCString (scType, &scType__CType));
		__caErrChk (CA_BSTRGetCString (param, &param__CType));
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, scType__CType,
		                               param__CType);
	
		__caErrChk (__result);
		
		}
Error:
	CA_FreeMemory (scType__CType);
	CA_FreeMemory (param__CType);

	return;
}

static void CVIFUNC _MediaPlayerEventsRegOnBuffering_EventVTableFunc (void *thisPtr,
                                                                      VBOOL start)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	_MediaPlayerEventsRegOnBuffering_CallbackType __callbackFunction;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 13, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, start);
	
		__caErrChk (__result);
		
		}
Error:

	return;
}

static void CVIFUNC _MediaPlayerEventsRegOnError_EventVTableFunc (void *thisPtr)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	_MediaPlayerEventsRegOnError_CallbackType __callbackFunction;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 14, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData);
	
		__caErrChk (__result);
		
		}
Error:

	return;
}

static void CVIFUNC _MediaPlayerEventsRegOnMarkerHit_EventVTableFunc (void *thisPtr,
                                                                      long markerNum)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	_MediaPlayerEventsRegOnMarkerHit_CallbackType __callbackFunction;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 15, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, markerNum);
	
		__caErrChk (__result);
		
		}
Error:

	return;
}

static void CVIFUNC _MediaPlayerEventsRegOnWarning_EventVTableFunc (void *thisPtr,
                                                                    long warningType,
                                                                    long param,
                                                                    BSTR description)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	_MediaPlayerEventsRegOnWarning_CallbackType __callbackFunction;
	char * description__CType = 0;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 16, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
		__caErrChk (CA_BSTRGetCString (description, &description__CType));
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, warningType,
		                               param, description__CType);
	
		__caErrChk (__result);
		
		}
Error:
	CA_FreeMemory (description__CType);

	return;
}

static void CVIFUNC _MediaPlayerEventsRegOnNewStream_EventVTableFunc (void *thisPtr)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	_MediaPlayerEventsRegOnNewStream_CallbackType __callbackFunction;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 17, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData);
	
		__caErrChk (__result);
		
		}
Error:

	return;
}

static void CVIFUNC _MediaPlayerEventsRegOnDisconnect_EventVTableFunc (void *thisPtr,
                                                                       long result)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	_MediaPlayerEventsRegOnDisconnect_CallbackType __callbackFunction;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 18, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, result);
	
		__caErrChk (__result);
		
		}
Error:

	return;
}

static void CVIFUNC _MediaPlayerEventsRegOnPositionChange_EventVTableFunc (void *thisPtr,
                                                                           double oldPosition,
                                                                           double newPosition)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	_MediaPlayerEventsRegOnPositionChange_CallbackType __callbackFunction;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 19, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, oldPosition,
		                               newPosition);
	
		__caErrChk (__result);
		
		}
Error:

	return;
}

static void CVIFUNC _MediaPlayerEventsRegOnDisplayModeChange_EventVTableFunc (void *thisPtr)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	_MediaPlayerEventsRegOnDisplayModeChange_CallbackType __callbackFunction;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 20, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData);
	
		__caErrChk (__result);
		
		}
Error:

	return;
}

static void CVIFUNC _MediaPlayerEventsRegOnReadyStateChange_EventVTableFunc (void *thisPtr,
                                                                             long readyState)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	_MediaPlayerEventsRegOnReadyStateChange_CallbackType __callbackFunction;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 21, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, readyState);
	
		__caErrChk (__result);
		
		}
Error:

	return;
}

static long CVIFUNC _IRadioPlayerEventsRegOnStateChange_EventVTableFunc (void *thisPtr,
                                                                         BSTR bszUrl,
                                                                         VBOOL fPlay,
                                                                         long lVolume,
                                                                         VBOOL fMute)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	_IRadioPlayerEventsRegOnStateChange_CallbackType __callbackFunction;
	long __returnValue = 0;
	char * bszUrl__CType = 0;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 0, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
		__caErrChk (CA_BSTRGetCString (bszUrl, &bszUrl__CType));
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, bszUrl__CType,
		                               fPlay, lVolume, fMute, &__returnValue);
	
		__caErrChk (__result);
		
		}
Error:
	CA_FreeMemory (bszUrl__CType);

	return __returnValue;
}

HRESULT CVIFUNC MediaPlayer__MediaPlayerEventsRegOnDVDNotify (CAObjHandle serverObject,
                                                              _MediaPlayerEventsRegOnDVDNotify_CallbackType callbackFunction,
                                                              void *callbackData,
                                                              int enableCallbacks,
                                                              int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &__MediaPlayerEvents_CAEventClassDefn,
	                                     0, callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC MediaPlayer__MediaPlayerEventsRegOnEndOfStream (CAObjHandle serverObject,
                                                                _MediaPlayerEventsRegOnEndOfStream_CallbackType callbackFunction,
                                                                void *callbackData,
                                                                int enableCallbacks,
                                                                int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &__MediaPlayerEvents_CAEventClassDefn,
	                                     1, callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC MediaPlayer__MediaPlayerEventsRegOnKeyDown (CAObjHandle serverObject,
                                                            _MediaPlayerEventsRegOnKeyDown_CallbackType callbackFunction,
                                                            void *callbackData,
                                                            int enableCallbacks,
                                                            int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &__MediaPlayerEvents_CAEventClassDefn,
	                                     2, callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC MediaPlayer__MediaPlayerEventsRegOnKeyUp (CAObjHandle serverObject,
                                                          _MediaPlayerEventsRegOnKeyUp_CallbackType callbackFunction,
                                                          void *callbackData,
                                                          int enableCallbacks,
                                                          int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &__MediaPlayerEvents_CAEventClassDefn,
	                                     3, callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC MediaPlayer__MediaPlayerEventsRegOnKeyPress (CAObjHandle serverObject,
                                                             _MediaPlayerEventsRegOnKeyPress_CallbackType callbackFunction,
                                                             void *callbackData,
                                                             int enableCallbacks,
                                                             int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &__MediaPlayerEvents_CAEventClassDefn,
	                                     4, callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC MediaPlayer__MediaPlayerEventsRegOnMouseMove (CAObjHandle serverObject,
                                                              _MediaPlayerEventsRegOnMouseMove_CallbackType callbackFunction,
                                                              void *callbackData,
                                                              int enableCallbacks,
                                                              int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &__MediaPlayerEvents_CAEventClassDefn,
	                                     5, callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC MediaPlayer__MediaPlayerEventsRegOnMouseDown (CAObjHandle serverObject,
                                                              _MediaPlayerEventsRegOnMouseDown_CallbackType callbackFunction,
                                                              void *callbackData,
                                                              int enableCallbacks,
                                                              int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &__MediaPlayerEvents_CAEventClassDefn,
	                                     6, callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC MediaPlayer__MediaPlayerEventsRegOnMouseUp (CAObjHandle serverObject,
                                                            _MediaPlayerEventsRegOnMouseUp_CallbackType callbackFunction,
                                                            void *callbackData,
                                                            int enableCallbacks,
                                                            int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &__MediaPlayerEvents_CAEventClassDefn,
	                                     7, callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC MediaPlayer__MediaPlayerEventsRegOnClick (CAObjHandle serverObject,
                                                          _MediaPlayerEventsRegOnClick_CallbackType callbackFunction,
                                                          void *callbackData,
                                                          int enableCallbacks,
                                                          int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &__MediaPlayerEvents_CAEventClassDefn,
	                                     8, callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC MediaPlayer__MediaPlayerEventsRegOnDblClick (CAObjHandle serverObject,
                                                             _MediaPlayerEventsRegOnDblClick_CallbackType callbackFunction,
                                                             void *callbackData,
                                                             int enableCallbacks,
                                                             int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &__MediaPlayerEvents_CAEventClassDefn,
	                                     9, callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC MediaPlayer__MediaPlayerEventsRegOnOpenStateChange (CAObjHandle serverObject,
                                                                    _MediaPlayerEventsRegOnOpenStateChange_CallbackType callbackFunction,
                                                                    void *callbackData,
                                                                    int enableCallbacks,
                                                                    int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &__MediaPlayerEvents_CAEventClassDefn,
	                                     10, callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC MediaPlayer__MediaPlayerEventsRegOnPlayStateChange (CAObjHandle serverObject,
                                                                    _MediaPlayerEventsRegOnPlayStateChange_CallbackType callbackFunction,
                                                                    void *callbackData,
                                                                    int enableCallbacks,
                                                                    int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &__MediaPlayerEvents_CAEventClassDefn,
	                                     11, callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC MediaPlayer__MediaPlayerEventsRegOnScriptCommand (CAObjHandle serverObject,
                                                                  _MediaPlayerEventsRegOnScriptCommand_CallbackType callbackFunction,
                                                                  void *callbackData,
                                                                  int enableCallbacks,
                                                                  int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &__MediaPlayerEvents_CAEventClassDefn,
	                                     12, callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC MediaPlayer__MediaPlayerEventsRegOnBuffering (CAObjHandle serverObject,
                                                              _MediaPlayerEventsRegOnBuffering_CallbackType callbackFunction,
                                                              void *callbackData,
                                                              int enableCallbacks,
                                                              int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &__MediaPlayerEvents_CAEventClassDefn,
	                                     13, callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC MediaPlayer__MediaPlayerEventsRegOnError (CAObjHandle serverObject,
                                                          _MediaPlayerEventsRegOnError_CallbackType callbackFunction,
                                                          void *callbackData,
                                                          int enableCallbacks,
                                                          int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &__MediaPlayerEvents_CAEventClassDefn,
	                                     14, callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC MediaPlayer__MediaPlayerEventsRegOnMarkerHit (CAObjHandle serverObject,
                                                              _MediaPlayerEventsRegOnMarkerHit_CallbackType callbackFunction,
                                                              void *callbackData,
                                                              int enableCallbacks,
                                                              int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &__MediaPlayerEvents_CAEventClassDefn,
	                                     15, callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC MediaPlayer__MediaPlayerEventsRegOnWarning (CAObjHandle serverObject,
                                                            _MediaPlayerEventsRegOnWarning_CallbackType callbackFunction,
                                                            void *callbackData,
                                                            int enableCallbacks,
                                                            int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &__MediaPlayerEvents_CAEventClassDefn,
	                                     16, callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC MediaPlayer__MediaPlayerEventsRegOnNewStream (CAObjHandle serverObject,
                                                              _MediaPlayerEventsRegOnNewStream_CallbackType callbackFunction,
                                                              void *callbackData,
                                                              int enableCallbacks,
                                                              int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &__MediaPlayerEvents_CAEventClassDefn,
	                                     17, callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC MediaPlayer__MediaPlayerEventsRegOnDisconnect (CAObjHandle serverObject,
                                                               _MediaPlayerEventsRegOnDisconnect_CallbackType callbackFunction,
                                                               void *callbackData,
                                                               int enableCallbacks,
                                                               int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &__MediaPlayerEvents_CAEventClassDefn,
	                                     18, callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC MediaPlayer__MediaPlayerEventsRegOnPositionChange (CAObjHandle serverObject,
                                                                   _MediaPlayerEventsRegOnPositionChange_CallbackType callbackFunction,
                                                                   void *callbackData,
                                                                   int enableCallbacks,
                                                                   int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &__MediaPlayerEvents_CAEventClassDefn,
	                                     19, callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC MediaPlayer__MediaPlayerEventsRegOnDisplayModeChange (CAObjHandle serverObject,
                                                                      _MediaPlayerEventsRegOnDisplayModeChange_CallbackType callbackFunction,
                                                                      void *callbackData,
                                                                      int enableCallbacks,
                                                                      int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &__MediaPlayerEvents_CAEventClassDefn,
	                                     20, callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC MediaPlayer__MediaPlayerEventsRegOnReadyStateChange (CAObjHandle serverObject,
                                                                     _MediaPlayerEventsRegOnReadyStateChange_CallbackType callbackFunction,
                                                                     void *callbackData,
                                                                     int enableCallbacks,
                                                                     int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &__MediaPlayerEvents_CAEventClassDefn,
	                                     21, callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC MediaPlayer__IRadioPlayerEventsRegOnStateChange (CAObjHandle serverObject,
                                                                 _IRadioPlayerEventsRegOnStateChange_CallbackType callbackFunction,
                                                                 void *callbackData,
                                                                 int enableCallbacks,
                                                                 int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &__IRadioPlayerEvents_CAEventClassDefn,
	                                     0, callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}
