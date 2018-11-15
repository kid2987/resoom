#ifndef _MEDIAPLAYER_H
#define _MEDIAPLAYER_H

#if defined(INCLUDE_AFTER_WINDOWS_H) && !defined(_INC_WINDOWS)
#error  This header must be included before utility.h and formatio.h
#error  because it includes cviauto.h which includes Windows SDK headers.
#endif /* INCLUDE_AFTER_WINDOWS_H */

#include <cviauto.h>

#ifdef __cplusplus
    extern "C" {
#endif
/* NICDBLD_BEGIN> Type Library Specific Types */

enum MediaPlayerEnum_MPPlayStateConstants
{
	MediaPlayerConst_mpStopped = 0,
	MediaPlayerConst_mpPaused = 1,
	MediaPlayerConst_mpPlaying = 2,
	MediaPlayerConst_mpWaiting = 3,
	MediaPlayerConst_mpScanForward = 4,
	MediaPlayerConst_mpScanReverse = 5,
	MediaPlayerConst_mpClosed = 6,
	_MediaPlayer_MPPlayStateConstantsForceSizeToFourBytes = 0xFFFFFFFF
};
enum MediaPlayerEnum_MPDisplaySizeConstants
{
	MediaPlayerConst_mpDefaultSize = 0,
	MediaPlayerConst_mpHalfSize = 1,
	MediaPlayerConst_mpDoubleSize = 2,
	MediaPlayerConst_mpFullScreen = 3,
	MediaPlayerConst_mpFitToSize = 4,
	MediaPlayerConst_mpOneSixteenthScreen = 5,
	MediaPlayerConst_mpOneFourthScreen = 6,
	MediaPlayerConst_mpOneHalfScreen = 7,
	_MediaPlayer_MPDisplaySizeConstantsForceSizeToFourBytes = 0xFFFFFFFF
};
enum MediaPlayerEnum_MPReadyStateConstants
{
	MediaPlayerConst_mpReadyStateUninitialized = 0,
	MediaPlayerConst_mpReadyStateLoading = 1,
	MediaPlayerConst_mpReadyStateInteractive = 3,
	MediaPlayerConst_mpReadyStateComplete = 4,
	_MediaPlayer_MPReadyStateConstantsForceSizeToFourBytes = 0xFFFFFFFF
};
enum MediaPlayerEnum_MPDisplayModeConstants
{
	MediaPlayerConst_mpTime = 0,
	MediaPlayerConst_mpFrames = 1,
	_MediaPlayer_MPDisplayModeConstantsForceSizeToFourBytes = 0xFFFFFFFF
};
enum MediaPlayerEnum_MPMoreInfoType
{
	MediaPlayerConst_mpShowURL = 0,
	MediaPlayerConst_mpClipURL = 1,
	MediaPlayerConst_mpBannerURL = 2,
	_MediaPlayer_MPMoreInfoTypeForceSizeToFourBytes = 0xFFFFFFFF
};
enum MediaPlayerEnum_MPMediaInfoType
{
	MediaPlayerConst_mpShowFilename = 0,
	MediaPlayerConst_mpShowTitle = 1,
	MediaPlayerConst_mpShowAuthor = 2,
	MediaPlayerConst_mpShowCopyright = 3,
	MediaPlayerConst_mpShowRating = 4,
	MediaPlayerConst_mpShowDescription = 5,
	MediaPlayerConst_mpShowLogoIcon = 6,
	MediaPlayerConst_mpClipFilename = 7,
	MediaPlayerConst_mpClipTitle = 8,
	MediaPlayerConst_mpClipAuthor = 9,
	MediaPlayerConst_mpClipCopyright = 10,
	MediaPlayerConst_mpClipRating = 11,
	MediaPlayerConst_mpClipDescription = 12,
	MediaPlayerConst_mpClipLogoIcon = 13,
	MediaPlayerConst_mpBannerImage = 14,
	MediaPlayerConst_mpBannerMoreInfo = 15,
	MediaPlayerConst_mpWatermark = 16,
	_MediaPlayer_MPMediaInfoTypeForceSizeToFourBytes = 0xFFFFFFFF
};
enum MediaPlayerEnum_MPShowDialogConstants
{
	MediaPlayerConst_mpShowDialogHelp = 0,
	MediaPlayerConst_mpShowDialogStatistics = 1,
	MediaPlayerConst_mpShowDialogOptions = 2,
	MediaPlayerConst_mpShowDialogContextMenu = 3,
	_MediaPlayer_MPShowDialogConstantsForceSizeToFourBytes = 0xFFFFFFFF
};
enum MediaPlayerEnum_ReadyStateConstants
{
	MediaPlayerConst_amvUninitialized = 0,
	MediaPlayerConst_amvLoading = 1,
	MediaPlayerConst_amvInteractive = 3,
	MediaPlayerConst_amvComplete = 4,
	_MediaPlayer_ReadyStateConstantsForceSizeToFourBytes = 0xFFFFFFFF
};
enum MediaPlayerEnum_DVDMenuIDConstants
{
	MediaPlayerConst_dvdMenu_Title = 2,
	MediaPlayerConst_dvdMenu_Root = 3,
	MediaPlayerConst_dvdMenu_Subpicture = 4,
	MediaPlayerConst_dvdMenu_Audio = 5,
	MediaPlayerConst_dvdMenu_Angle = 6,
	MediaPlayerConst_dvdMenu_Chapter = 7,
	_MediaPlayer_DVDMenuIDConstantsForceSizeToFourBytes = 0xFFFFFFFF
};
typedef CAObjHandle MediaPlayerObj_IServiceProvider;
typedef unsigned long MediaPlayerType_VB_OLE_COLOR;
typedef CAObjHandle MediaPlayerObj_IMediaPlayerDvd;
typedef long MediaPlayerType_OLE_XPOS_PIXELS;
typedef long MediaPlayerType_OLE_YPOS_PIXELS;
typedef CAObjHandle MediaPlayerObj_IRadioPlayer;
typedef HRESULT (CVICALLBACK *_MediaPlayerEventsRegOnDVDNotify_CallbackType) (CAObjHandle caServerObjHandle,
                                                                              void *caCallbackData,
                                                                              long  eventCode,
                                                                              long  eventParam1,
                                                                              long  eventParam2);
typedef HRESULT (CVICALLBACK *_MediaPlayerEventsRegOnEndOfStream_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                void *caCallbackData,
                                                                                long  result);
typedef HRESULT (CVICALLBACK *_MediaPlayerEventsRegOnKeyDown_CallbackType) (CAObjHandle caServerObjHandle,
                                                                            void *caCallbackData,
                                                                            short  keyCode,
                                                                            short  shiftState);
typedef HRESULT (CVICALLBACK *_MediaPlayerEventsRegOnKeyUp_CallbackType) (CAObjHandle caServerObjHandle,
                                                                          void *caCallbackData,
                                                                          short  keyCode,
                                                                          short  shiftState);
typedef HRESULT (CVICALLBACK *_MediaPlayerEventsRegOnKeyPress_CallbackType) (CAObjHandle caServerObjHandle,
                                                                             void *caCallbackData,
                                                                             short  characterCode);
typedef HRESULT (CVICALLBACK *_MediaPlayerEventsRegOnMouseMove_CallbackType) (CAObjHandle caServerObjHandle,
                                                                              void *caCallbackData,
                                                                              short  button,
                                                                              short  shiftState,
                                                                              MediaPlayerType_OLE_XPOS_PIXELS  x,
                                                                              MediaPlayerType_OLE_YPOS_PIXELS  y);
typedef HRESULT (CVICALLBACK *_MediaPlayerEventsRegOnMouseDown_CallbackType) (CAObjHandle caServerObjHandle,
                                                                              void *caCallbackData,
                                                                              short  button,
                                                                              short  shiftState,
                                                                              MediaPlayerType_OLE_XPOS_PIXELS  x,
                                                                              MediaPlayerType_OLE_YPOS_PIXELS  y);
typedef HRESULT (CVICALLBACK *_MediaPlayerEventsRegOnMouseUp_CallbackType) (CAObjHandle caServerObjHandle,
                                                                            void *caCallbackData,
                                                                            short  button,
                                                                            short  shiftState,
                                                                            MediaPlayerType_OLE_XPOS_PIXELS  x,
                                                                            MediaPlayerType_OLE_YPOS_PIXELS  y);
typedef HRESULT (CVICALLBACK *_MediaPlayerEventsRegOnClick_CallbackType) (CAObjHandle caServerObjHandle,
                                                                          void *caCallbackData,
                                                                          short  button,
                                                                          short  shiftState,
                                                                          MediaPlayerType_OLE_XPOS_PIXELS  x,
                                                                          MediaPlayerType_OLE_YPOS_PIXELS  y);
typedef HRESULT (CVICALLBACK *_MediaPlayerEventsRegOnDblClick_CallbackType) (CAObjHandle caServerObjHandle,
                                                                             void *caCallbackData,
                                                                             short  button,
                                                                             short  shiftState,
                                                                             MediaPlayerType_OLE_XPOS_PIXELS  x,
                                                                             MediaPlayerType_OLE_YPOS_PIXELS  y);
typedef HRESULT (CVICALLBACK *_MediaPlayerEventsRegOnOpenStateChange_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                    void *caCallbackData,
                                                                                    long  oldState,
                                                                                    long  newState);
typedef HRESULT (CVICALLBACK *_MediaPlayerEventsRegOnPlayStateChange_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                    void *caCallbackData,
                                                                                    long  oldState,
                                                                                    long  newState);
typedef HRESULT (CVICALLBACK *_MediaPlayerEventsRegOnScriptCommand_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                  void *caCallbackData,
                                                                                  char *scType,
                                                                                  char *param);
typedef HRESULT (CVICALLBACK *_MediaPlayerEventsRegOnBuffering_CallbackType) (CAObjHandle caServerObjHandle,
                                                                              void *caCallbackData,
                                                                              VBOOL  start);
typedef HRESULT (CVICALLBACK *_MediaPlayerEventsRegOnError_CallbackType) (CAObjHandle caServerObjHandle,
                                                                          void *caCallbackData);
typedef HRESULT (CVICALLBACK *_MediaPlayerEventsRegOnMarkerHit_CallbackType) (CAObjHandle caServerObjHandle,
                                                                              void *caCallbackData,
                                                                              long  markerNum);
typedef HRESULT (CVICALLBACK *_MediaPlayerEventsRegOnWarning_CallbackType) (CAObjHandle caServerObjHandle,
                                                                            void *caCallbackData,
                                                                            long  warningType,
                                                                            long  param,
                                                                            char *description);
typedef HRESULT (CVICALLBACK *_MediaPlayerEventsRegOnNewStream_CallbackType) (CAObjHandle caServerObjHandle,
                                                                              void *caCallbackData);
typedef HRESULT (CVICALLBACK *_MediaPlayerEventsRegOnDisconnect_CallbackType) (CAObjHandle caServerObjHandle,
                                                                               void *caCallbackData,
                                                                               long  result);
typedef HRESULT (CVICALLBACK *_MediaPlayerEventsRegOnPositionChange_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                   void *caCallbackData,
                                                                                   double  oldPosition,
                                                                                   double  newPosition);
typedef HRESULT (CVICALLBACK *_MediaPlayerEventsRegOnDisplayModeChange_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                      void *caCallbackData);
typedef HRESULT (CVICALLBACK *_MediaPlayerEventsRegOnReadyStateChange_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                     void *caCallbackData,
                                                                                     enum MediaPlayerEnum_ReadyStateConstants  readyState);
typedef HRESULT (CVICALLBACK *_IRadioPlayerEventsRegOnStateChange_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                 void *caCallbackData,
                                                                                 char *bszUrl,
                                                                                 VBOOL  fPlay,
                                                                                 long  lVolume,
                                                                                 VBOOL  fMute,
                                                                                 long *__returnValue);
/* NICDBLD_END> Type Library Specific Types */

extern const IID MediaPlayer_IID_IDirectControl;
extern const IID MediaPlayer_IID_IDirectContainer;
extern const IID MediaPlayer_IID_IMediaPlayer2;
extern const IID MediaPlayer_IID_IMediaBindStream;
extern const IID MediaPlayer_IID_IRadioPlayer;
extern const IID MediaPlayer_IID_IRadioServer;
extern const IID MediaPlayer_IID_IMediaPlayerListener;
extern const IID MediaPlayer_IID_IRadioBand;
extern const IID MediaPlayer_IID__MediaPlayerEvents;
extern const IID MediaPlayer_IID__IRadioPlayerEvents;
extern const IID MediaPlayer_IID_IMediaPlayer;
extern const IID MediaPlayer_IID_IMediaPlayerDvd;

HRESULT CVIFUNC MediaPlayer_NewIDirectControl (const char *server,
                                               int supportMultithreading,
                                               LCID locale, int reserved,
                                               CAObjHandle *objectHandle);

HRESULT CVIFUNC MediaPlayer_OpenIDirectControl (const char *fileName,
                                                const char *server,
                                                int supportMultithreading,
                                                LCID locale, int reserved,
                                                CAObjHandle *objectHandle);

HRESULT CVIFUNC MediaPlayer_ActiveIDirectControl (const char *server,
                                                  int supportMultithreading,
                                                  LCID locale, int reserved,
                                                  CAObjHandle *objectHandle);

HRESULT CVIFUNC MediaPlayer_IDirectControlCreateView (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      const char *bszClsid);

HRESULT CVIFUNC MediaPlayer_IDirectControlDestroyAllViews (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo);

HRESULT CVIFUNC MediaPlayer_NewIDirectContainer (const char *server,
                                                 int supportMultithreading,
                                                 LCID locale, int reserved,
                                                 CAObjHandle *objectHandle);

HRESULT CVIFUNC MediaPlayer_OpenIDirectContainer (const char *fileName,
                                                  const char *server,
                                                  int supportMultithreading,
                                                  LCID locale, int reserved,
                                                  CAObjHandle *objectHandle);

HRESULT CVIFUNC MediaPlayer_ActiveIDirectContainer (const char *server,
                                                    int supportMultithreading,
                                                    LCID locale, int reserved,
                                                    CAObjHandle *objectHandle);

HRESULT CVIFUNC MediaPlayer_IDirectContainerCreateControl (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           const char *bszClsid,
                                                           unsigned long dwClsContext,
                                                           CAObjHandle *ppunk,
                                                           unsigned long dwWindowStyle);

HRESULT CVIFUNC MediaPlayer_IDirectContainerSetServiceProvider (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                MediaPlayerObj_IServiceProvider pspSet);

HRESULT CVIFUNC MediaPlayer_IDirectContainerSetIInputObjectSite (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 CAObjHandle pios);

HRESULT CVIFUNC MediaPlayer_IDirectContainerShowControl (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo);

HRESULT CVIFUNC MediaPlayer_IDirectContainerHideControl (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo);

HRESULT CVIFUNC MediaPlayer_IDirectContainerIsControlCreated (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo);

HRESULT CVIFUNC MediaPlayer_IDirectContainerDestroyControl (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo);

HRESULT CVIFUNC MediaPlayer_NewIMediaPlayer2 (const char *server,
                                              int supportMultithreading,
                                              LCID locale, int reserved,
                                              CAObjHandle *objectHandle);

HRESULT CVIFUNC MediaPlayer_OpenIMediaPlayer2 (const char *fileName,
                                               const char *server,
                                               int supportMultithreading,
                                               LCID locale, int reserved,
                                               CAObjHandle *objectHandle);

HRESULT CVIFUNC MediaPlayer_ActiveIMediaPlayer2 (const char *server,
                                                 int supportMultithreading,
                                                 LCID locale, int reserved,
                                                 CAObjHandle *objectHandle);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetCurrentPosition (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             double *pCurrentPosition);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetCurrentPosition (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             double pCurrentPosition);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetDuration (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      double *pDuration);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetImageSourceWidth (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              long *pWidth);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetImageSourceHeight (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               long *pHeight);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetMarkerCount (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         long *pMarkerCount);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetCanScan (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL *pCanScan);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetCanSeek (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL *pCanSeek);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetCanSeekToMarkers (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              VBOOL *pCanSeekToMarkers);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetCurrentMarker (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           long *pCurrentMarker);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetCurrentMarker (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           long pCurrentMarker);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetFileName (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      char **pbstrFileName);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetFileName (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      const char *pbstrFileName);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetSourceLink (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        char **pbstrSourceLink);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetCreationDate (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          DATE *pCreationDate);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetErrorCorrection (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             char **pbstrErrorCorrection);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetBandwidth (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long *pBandwidth);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetSourceProtocol (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            long *pSourceProtocol);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetReceivedPackets (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             long *pReceivedPackets);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetRecoveredPackets (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              long *pRecoveredPackets);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetLostPackets (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         long *pLostPackets);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetReceptionQuality (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              long *pReceptionQuality);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetBufferingCount (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            long *pBufferingCount);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetIsBroadcast (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL *pIsBroadcast);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetBufferingProgress (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               long *pBufferingProgress);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetChannelName (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         char **pbstrChannelName);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetChannelDescription (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                char **pbstrChannelDescription);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetChannelURL (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        char **pbstrChannelURL);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetContactAddress (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            char **pbstrContactAddress);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetContactPhone (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          char **pbstrContactPhone);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetContactEmail (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          char **pbstrContactEmail);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetBufferingTime (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           double *pBufferingTime);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetBufferingTime (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           double pBufferingTime);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetAutoStart (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL *pAutoStart);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetAutoStart (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL pAutoStart);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetAutoRewind (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *pAutoRewind);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetAutoRewind (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL pAutoRewind);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetRate (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  double *pRate);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetRate (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  double pRate);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetSendKeyboardEvents (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                VBOOL *pSendKeyboardEvents);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetSendKeyboardEvents (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                VBOOL pSendKeyboardEvents);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetSendMouseClickEvents (CAObjHandle objectHandle,
                                                                  ERRORINFO *errorInfo,
                                                                  VBOOL *pSendMouseClickEvents);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetSendMouseClickEvents (CAObjHandle objectHandle,
                                                                  ERRORINFO *errorInfo,
                                                                  VBOOL pSendMouseClickEvents);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetSendMouseMoveEvents (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 VBOOL *pSendMouseMoveEvents);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetSendMouseMoveEvents (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 VBOOL pSendMouseMoveEvents);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetPlayCount (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long *pPlayCount);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetPlayCount (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long pPlayCount);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetClickToPlay (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL *pClickToPlay);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetClickToPlay (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL pClickToPlay);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetAllowScan (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL *pAllowScan);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetAllowScan (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL pAllowScan);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetEnableContextMenu (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               VBOOL *pEnableContextMenu);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetEnableContextMenu (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               VBOOL pEnableContextMenu);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetCursorType (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        long *pCursorType);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetCursorType (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        long pCursorType);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetCodecCount (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        long *pCodecCount);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetAllowChangeDisplaySize (CAObjHandle objectHandle,
                                                                    ERRORINFO *errorInfo,
                                                                    VBOOL *pAllowChangeDisplaySize);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetAllowChangeDisplaySize (CAObjHandle objectHandle,
                                                                    ERRORINFO *errorInfo,
                                                                    VBOOL pAllowChangeDisplaySize);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetIsDurationValid (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL *pIsDurationValid);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetOpenState (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long *pOpenState);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetSendOpenStateChangeEvents (CAObjHandle objectHandle,
                                                                       ERRORINFO *errorInfo,
                                                                       VBOOL *pSendOpenStateChangeEvents);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetSendOpenStateChangeEvents (CAObjHandle objectHandle,
                                                                       ERRORINFO *errorInfo,
                                                                       VBOOL pSendOpenStateChangeEvents);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetSendWarningEvents (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               VBOOL *pSendWarningEvents);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetSendWarningEvents (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               VBOOL pSendWarningEvents);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetSendErrorEvents (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL *pSendErrorEvents);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetSendErrorEvents (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL pSendErrorEvents);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetPlayState (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       enum MediaPlayerEnum_MPPlayStateConstants *pPlayState);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetSendPlayStateChangeEvents (CAObjHandle objectHandle,
                                                                       ERRORINFO *errorInfo,
                                                                       VBOOL *pSendPlayStateChangeEvents);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetSendPlayStateChangeEvents (CAObjHandle objectHandle,
                                                                       ERRORINFO *errorInfo,
                                                                       VBOOL pSendPlayStateChangeEvents);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetDisplaySize (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         enum MediaPlayerEnum_MPDisplaySizeConstants *pDisplaySize);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetDisplaySize (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         enum MediaPlayerEnum_MPDisplaySizeConstants pDisplaySize);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetInvokeURLs (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *pInvokeURLs);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetInvokeURLs (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL pInvokeURLs);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetBaseURL (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     char **pbstrBaseURL);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetBaseURL (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     const char *pbstrBaseURL);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetDefaultFrame (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          char **pbstrDefaultFrame);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetDefaultFrame (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          const char *pbstrDefaultFrame);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetHasError (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *pHasError);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetErrorDescription (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              char **pbstrErrorDescription);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetErrorCode (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long *pErrorCode);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetAnimationAtStart (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              VBOOL *pAnimationAtStart);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetAnimationAtStart (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              VBOOL pAnimationAtStart);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetTransparentAtStart (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                VBOOL *pTransparentAtStart);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetTransparentAtStart (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                VBOOL pTransparentAtStart);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetVolume (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long *pVolume);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetVolume (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long pVolume);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetBalance (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long *pBalance);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetBalance (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long pBalance);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetReadyState (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        enum MediaPlayerEnum_MPReadyStateConstants *pValue);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetSelectionStart (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            double *pValue);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetSelectionStart (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            double pValue);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetSelectionEnd (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          double *pValue);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetSelectionEnd (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          double pValue);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetShowDisplay (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL *show);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetShowDisplay (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL show);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetShowControls (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL *show);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetShowControls (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL show);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetShowPositionControls (CAObjHandle objectHandle,
                                                                  ERRORINFO *errorInfo,
                                                                  VBOOL *show);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetShowPositionControls (CAObjHandle objectHandle,
                                                                  ERRORINFO *errorInfo,
                                                                  VBOOL show);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetShowTracker (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL *show);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetShowTracker (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL show);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetEnablePositionControls (CAObjHandle objectHandle,
                                                                    ERRORINFO *errorInfo,
                                                                    VBOOL *enable);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetEnablePositionControls (CAObjHandle objectHandle,
                                                                    ERRORINFO *errorInfo,
                                                                    VBOOL enable);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetEnableTracker (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           VBOOL *enable);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetEnableTracker (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           VBOOL enable);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetEnabled (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL *pEnabled);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetEnabled (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL pEnabled);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetDisplayForeColor (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              MediaPlayerType_VB_OLE_COLOR *foreColor);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetDisplayForeColor (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              MediaPlayerType_VB_OLE_COLOR foreColor);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetDisplayBackColor (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              MediaPlayerType_VB_OLE_COLOR *backColor);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetDisplayBackColor (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              MediaPlayerType_VB_OLE_COLOR backColor);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetDisplayMode (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         enum MediaPlayerEnum_MPDisplayModeConstants *pValue);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetDisplayMode (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         enum MediaPlayerEnum_MPDisplayModeConstants pValue);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetVideoBorder3D (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           VBOOL *pVideoBorderWidth);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetVideoBorder3D (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           VBOOL pVideoBorderWidth);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetVideoBorderWidth (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              long *pVideoBorderWidth);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetVideoBorderWidth (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              long pVideoBorderWidth);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetVideoBorderColor (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              MediaPlayerType_VB_OLE_COLOR *pVideoBorderWidth);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetVideoBorderColor (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              MediaPlayerType_VB_OLE_COLOR pVideoBorderWidth);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetShowGotoBar (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL *pbool);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetShowGotoBar (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL pbool);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetShowStatusBar (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           VBOOL *pbool);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetShowStatusBar (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           VBOOL pbool);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetShowCaptioning (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VBOOL *pbool);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetShowCaptioning (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VBOOL pbool);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetShowAudioControls (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               VBOOL *pbool);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetShowAudioControls (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               VBOOL pbool);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetCaptioningID (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          char **pstrText);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetCaptioningID (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          const char *pstrText);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetMute (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VBOOL *vbool);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetMute (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VBOOL vbool);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetCanPreview (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *pCanPreview);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetPreviewMode (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL *pPreviewMode);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetPreviewMode (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL pPreviewMode);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetHasMultipleItems (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              VBOOL *pHasMuliItems);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetLanguage (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long *pLanguage);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetLanguage (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long pLanguage);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetAudioStream (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         long *pStream);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetAudioStream (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         long pStream);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetSAMIStyle (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       char **pbstrStyle);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetSAMIStyle (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       const char *pbstrStyle);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetSAMILang (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      char **pbstrLang);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetSAMILang (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      const char *pbstrLang);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetSAMIFileName (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          char **pbstrFileName);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetSAMIFileName (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          const char *pbstrFileName);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetStreamCount (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         long *pStreamCount);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetClientId (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      char **pbstrClientId);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetConnectionSpeed (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             long *plConnectionSpeed);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetAutoSize (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *pbool);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetAutoSize (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL pbool);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetEnableFullScreenControls (CAObjHandle objectHandle,
                                                                      ERRORINFO *errorInfo,
                                                                      VBOOL *pbVal);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetEnableFullScreenControls (CAObjHandle objectHandle,
                                                                      ERRORINFO *errorInfo,
                                                                      VBOOL pbVal);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetActiveMovie (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CAObjHandle *ppdispatch);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetNSPlay (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    CAObjHandle *ppdispatch);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetWindowlessVideo (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL *pbool);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetWindowlessVideo (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL pbool);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2Play (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2Stop (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2Pause (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetMarkerTime (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        long markerNum,
                                                        double *pMarkerTime);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetMarkerName (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        long markerNum,
                                                        char **pbstrMarkerName);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2AboutBox (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetCodecInstalled (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            long codecNum,
                                                            VBOOL *pCodecInstalled);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetCodecDescription (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              long codecNum,
                                                              char **pbstrCodecDescription);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetCodecURL (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long codecNum,
                                                      char **pbstrCodecURL);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetMoreInfoURL (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         enum MediaPlayerEnum_MPMoreInfoType moreInfoType,
                                                         char **pbstrMoreInfoURL);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetMediaInfoString (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             enum MediaPlayerEnum_MPMediaInfoType mediaInfoType,
                                                             char **pbstrMediaInfo);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2Cancel (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2Open (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               const char *bstrFileName);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2IsSoundCardEnabled (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL *pbSoundCard);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2Next (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2Previous (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2StreamSelect (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long streamNum);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2FastForward (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2FastReverse (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetStreamName (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        long streamNum,
                                                        char **pbstrStreamName);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetStreamGroup (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         long streamNum,
                                                         long *pStreamGroup);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetStreamSelected (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            long streamNum,
                                                            VBOOL *pStreamSelected);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetDVD (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 MediaPlayerObj_IMediaPlayerDvd *ppdispatch);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetMediaParameter (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            long entryNum,
                                                            const char *bstrParameterName,
                                                            char **pbstrParameterValue);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetMediaParameterName (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                long entryNum,
                                                                long index,
                                                                char **pbstrParameterName);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetEntryCount (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        long *pNumberEntries);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2GetCurrentEntry (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          long *pEntryNumber);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2SetCurrentEntry (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          long entryNumber);

HRESULT CVIFUNC MediaPlayer_IMediaPlayer2ShowDialog (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     enum MediaPlayerEnum_MPShowDialogConstants mpDialogIndex);

HRESULT CVIFUNC MediaPlayer_NewIMediaBindStream (const char *server,
                                                 int supportMultithreading,
                                                 LCID locale, int reserved,
                                                 CAObjHandle *objectHandle);

HRESULT CVIFUNC MediaPlayer_OpenIMediaBindStream (const char *fileName,
                                                  const char *server,
                                                  int supportMultithreading,
                                                  LCID locale, int reserved,
                                                  CAObjHandle *objectHandle);

HRESULT CVIFUNC MediaPlayer_ActiveIMediaBindStream (const char *server,
                                                    int supportMultithreading,
                                                    LCID locale, int reserved,
                                                    CAObjHandle *objectHandle);

HRESULT CVIFUNC MediaPlayer_IMediaBindStreamLoadMoniker (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         const char *bszTransferContext,
                                                         const char *bszUrl);

HRESULT CVIFUNC MediaPlayer_NewRadioPlayerIRadioPlayer (const char *server,
                                                        int supportMultithreading,
                                                        LCID locale,
                                                        int reserved,
                                                        CAObjHandle *objectHandle);

HRESULT CVIFUNC MediaPlayer_OpenRadioPlayerIRadioPlayer (const char *fileName,
                                                         const char *server,
                                                         int supportMultithreading,
                                                         LCID locale,
                                                         int reserved,
                                                         CAObjHandle *objectHandle);

HRESULT CVIFUNC MediaPlayer_ActiveRadioPlayerIRadioPlayer (const char *server,
                                                           int supportMultithreading,
                                                           LCID locale,
                                                           int reserved,
                                                           CAObjHandle *objectHandle);

HRESULT CVIFUNC MediaPlayer_NewRadioServerIRadioPlayer (const char *server,
                                                        int supportMultithreading,
                                                        LCID locale,
                                                        int reserved,
                                                        CAObjHandle *objectHandle);

HRESULT CVIFUNC MediaPlayer_OpenRadioServerIRadioPlayer (const char *fileName,
                                                         const char *server,
                                                         int supportMultithreading,
                                                         LCID locale,
                                                         int reserved,
                                                         CAObjHandle *objectHandle);

HRESULT CVIFUNC MediaPlayer_ActiveRadioServerIRadioPlayer (const char *server,
                                                           int supportMultithreading,
                                                           LCID locale,
                                                           int reserved,
                                                           CAObjHandle *objectHandle);

HRESULT CVIFUNC MediaPlayer_IRadioPlayerBindRadioMemory (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo);

HRESULT CVIFUNC MediaPlayer_IRadioPlayerReleaseRadio (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo);

HRESULT CVIFUNC MediaPlayer_IRadioPlayerRegisterEvent (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       const char *bszEvent,
                                                       long *plRegister);

HRESULT CVIFUNC MediaPlayer_IRadioPlayerRegisterWindow (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        long __MIDL_0012,
                                                        unsigned long dwMessage,
                                                        unsigned long dwCodeSet,
                                                        long *plRegister);

HRESULT CVIFUNC MediaPlayer_IRadioPlayerGetSection (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    char **bszSection);

HRESULT CVIFUNC MediaPlayer_IRadioPlayerUnregister (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long lRegister);

HRESULT CVIFUNC MediaPlayer_IRadioPlayerGetInstanceCount (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          long *plInstances);

HRESULT CVIFUNC MediaPlayer_IRadioPlayerPlay (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo);

HRESULT CVIFUNC MediaPlayer_IRadioPlayerStop (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo);

HRESULT CVIFUNC MediaPlayer_IRadioPlayerSetUrl (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                const char *newValue);

HRESULT CVIFUNC MediaPlayer_IRadioPlayerSetVolume (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long newValue);

HRESULT CVIFUNC MediaPlayer_IRadioPlayerSetMute (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL newValue);

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
                                                   char **__MIDL_0019);

HRESULT CVIFUNC MediaPlayer_IRadioPlayerGetState (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long *plOpenState,
                                                  long *pfBuffering,
                                                  long *plBufferingPercent,
                                                  long *plQuality);

HRESULT CVIFUNC MediaPlayer_NewIRadioServer (const char *server,
                                             int supportMultithreading,
                                             LCID locale, int reserved,
                                             CAObjHandle *objectHandle);

HRESULT CVIFUNC MediaPlayer_OpenIRadioServer (const char *fileName,
                                              const char *server,
                                              int supportMultithreading,
                                              LCID locale, int reserved,
                                              CAObjHandle *objectHandle);

HRESULT CVIFUNC MediaPlayer_ActiveIRadioServer (const char *server,
                                                int supportMultithreading,
                                                LCID locale, int reserved,
                                                CAObjHandle *objectHandle);

HRESULT CVIFUNC MediaPlayer_IRadioServerBindToRadio (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     const char *wszRadio,
                                                     MediaPlayerObj_IRadioPlayer *ppServer);

HRESULT CVIFUNC MediaPlayer_IRadioServerIsRadioExists (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       const char *wszRadio);

HRESULT CVIFUNC MediaPlayer_IRadioServerLaunchStandardUrl (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           const char *bszUrl,
                                                           LPUNKNOWN pBrowser);

HRESULT CVIFUNC MediaPlayer_NewIMediaPlayerListener (const char *server,
                                                     int supportMultithreading,
                                                     LCID locale, int reserved,
                                                     CAObjHandle *objectHandle);

HRESULT CVIFUNC MediaPlayer_OpenIMediaPlayerListener (const char *fileName,
                                                      const char *server,
                                                      int supportMultithreading,
                                                      LCID locale, int reserved,
                                                      CAObjHandle *objectHandle);

HRESULT CVIFUNC MediaPlayer_ActiveIMediaPlayerListener (const char *server,
                                                        int supportMultithreading,
                                                        LCID locale,
                                                        int reserved,
                                                        CAObjHandle *objectHandle);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerListenerPlayStateChanged (CAObjHandle objectHandle,
                                                                  ERRORINFO *errorInfo,
                                                                  long lNewState);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerListenerBuffering (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           VBOOL fStart);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerListenerBufferPercent (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               long lBufferPercent);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerListenerOpenStateChanged (CAObjHandle objectHandle,
                                                                  ERRORINFO *errorInfo,
                                                                  long lOpenState);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerListenerMediaInfoChanged (CAObjHandle objectHandle,
                                                                  ERRORINFO *errorInfo,
                                                                  const char *bstrShowTitle,
                                                                  const char *bstrClipTitle,
                                                                  const char *bstrClipAuthor,
                                                                  const char *bstrClipCopyright,
                                                                  const char *bstrStationURL);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerListenerQualityChanged (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                long lQuality);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerListenerError (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       const char *bstrError);

HRESULT CVIFUNC MediaPlayer_NewIRadioBand (const char *server,
                                           int supportMultithreading,
                                           LCID locale, int reserved,
                                           CAObjHandle *objectHandle);

HRESULT CVIFUNC MediaPlayer_OpenIRadioBand (const char *fileName,
                                            const char *server,
                                            int supportMultithreading,
                                            LCID locale, int reserved,
                                            CAObjHandle *objectHandle);

HRESULT CVIFUNC MediaPlayer_ActiveIRadioBand (const char *server,
                                              int supportMultithreading,
                                              LCID locale, int reserved,
                                              CAObjHandle *objectHandle);

HRESULT CVIFUNC MediaPlayer_IRadioBandCreate (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo, long *phwnd,
                                              long hwndParent);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetCurrentPosition (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            double *pCurrentPosition);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetCurrentPosition (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            double pCurrentPosition);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetDuration (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     double *pDuration);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetImageSourceWidth (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             long *pWidth);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetImageSourceHeight (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              long *pHeight);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetMarkerCount (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        long *pMarkerCount);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetCanScan (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL *pCanScan);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetCanSeek (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL *pCanSeek);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetCanSeekToMarkers (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL *pCanSeekToMarkers);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetCurrentMarker (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          long *pCurrentMarker);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetCurrentMarker (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          long pCurrentMarker);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetFileName (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     char **pbstrFileName);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetFileName (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     const char *pbstrFileName);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetSourceLink (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       char **pbstrSourceLink);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetCreationDate (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         DATE *pCreationDate);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetErrorCorrection (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            char **pbstrErrorCorrection);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetBandwidth (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long *pBandwidth);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetSourceProtocol (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           long *pSourceProtocol);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetReceivedPackets (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            long *pReceivedPackets);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetRecoveredPackets (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             long *pRecoveredPackets);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetLostPackets (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        long *pLostPackets);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetReceptionQuality (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             long *pReceptionQuality);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetBufferingCount (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           long *pBufferingCount);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetIsBroadcast (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *pIsBroadcast);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetBufferingProgress (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              long *pBufferingProgress);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetChannelName (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        char **pbstrChannelName);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetChannelDescription (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               char **pbstrChannelDescription);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetChannelURL (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       char **pbstrChannelURL);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetContactAddress (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           char **pbstrContactAddress);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetContactPhone (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         char **pbstrContactPhone);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetContactEmail (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         char **pbstrContactEmail);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetBufferingTime (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          double *pBufferingTime);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetBufferingTime (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          double pBufferingTime);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetAutoStart (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *pAutoStart);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetAutoStart (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL pAutoStart);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetAutoRewind (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL *pAutoRewind);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetAutoRewind (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL pAutoRewind);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetRate (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 double *pRate);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetRate (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 double pRate);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetSendKeyboardEvents (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               VBOOL *pSendKeyboardEvents);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetSendKeyboardEvents (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               VBOOL pSendKeyboardEvents);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetSendMouseClickEvents (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 VBOOL *pSendMouseClickEvents);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetSendMouseClickEvents (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 VBOOL pSendMouseClickEvents);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetSendMouseMoveEvents (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                VBOOL *pSendMouseMoveEvents);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetSendMouseMoveEvents (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                VBOOL pSendMouseMoveEvents);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetPlayCount (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long *pPlayCount);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetPlayCount (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long pPlayCount);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetClickToPlay (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *pClickToPlay);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetClickToPlay (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL pClickToPlay);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetAllowScan (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *pAllowScan);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetAllowScan (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL pAllowScan);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetEnableContextMenu (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              VBOOL *pEnableContextMenu);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetEnableContextMenu (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              VBOOL pEnableContextMenu);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetCursorType (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long *pCursorType);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetCursorType (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long pCursorType);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetCodecCount (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long *pCodecCount);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetAllowChangeDisplaySize (CAObjHandle objectHandle,
                                                                   ERRORINFO *errorInfo,
                                                                   VBOOL *pAllowChangeDisplaySize);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetAllowChangeDisplaySize (CAObjHandle objectHandle,
                                                                   ERRORINFO *errorInfo,
                                                                   VBOOL pAllowChangeDisplaySize);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetIsDurationValid (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VBOOL *pIsDurationValid);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetOpenState (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long *pOpenState);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetSendOpenStateChangeEvents (CAObjHandle objectHandle,
                                                                      ERRORINFO *errorInfo,
                                                                      VBOOL *pSendOpenStateChangeEvents);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetSendOpenStateChangeEvents (CAObjHandle objectHandle,
                                                                      ERRORINFO *errorInfo,
                                                                      VBOOL pSendOpenStateChangeEvents);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetSendWarningEvents (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              VBOOL *pSendWarningEvents);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetSendWarningEvents (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              VBOOL pSendWarningEvents);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetSendErrorEvents (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VBOOL *pSendErrorEvents);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetSendErrorEvents (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VBOOL pSendErrorEvents);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetPlayState (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      enum MediaPlayerEnum_MPPlayStateConstants *pPlayState);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetSendPlayStateChangeEvents (CAObjHandle objectHandle,
                                                                      ERRORINFO *errorInfo,
                                                                      VBOOL *pSendPlayStateChangeEvents);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetSendPlayStateChangeEvents (CAObjHandle objectHandle,
                                                                      ERRORINFO *errorInfo,
                                                                      VBOOL pSendPlayStateChangeEvents);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetDisplaySize (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        enum MediaPlayerEnum_MPDisplaySizeConstants *pDisplaySize);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetDisplaySize (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        enum MediaPlayerEnum_MPDisplaySizeConstants pDisplaySize);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetInvokeURLs (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL *pInvokeURLs);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetInvokeURLs (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL pInvokeURLs);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetBaseURL (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    char **pbstrBaseURL);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetBaseURL (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    const char *pbstrBaseURL);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetDefaultFrame (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         char **pbstrDefaultFrame);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetDefaultFrame (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         const char *pbstrDefaultFrame);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetHasError (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL *pHasError);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetErrorDescription (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             char **pbstrErrorDescription);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetErrorCode (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long *pErrorCode);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetAnimationAtStart (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL *pAnimationAtStart);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetAnimationAtStart (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL pAnimationAtStart);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetTransparentAtStart (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               VBOOL *pTransparentAtStart);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetTransparentAtStart (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               VBOOL pTransparentAtStart);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetVolume (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long *pVolume);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetVolume (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   long pVolume);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetBalance (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long *pBalance);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetBalance (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long pBalance);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetReadyState (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       enum MediaPlayerEnum_MPReadyStateConstants *pValue);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetSelectionStart (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           double *pValue);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetSelectionStart (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           double pValue);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetSelectionEnd (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         double *pValue);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetSelectionEnd (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         double pValue);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetShowDisplay (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *show);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetShowDisplay (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL show);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetShowControls (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL *show);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetShowControls (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL show);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetShowPositionControls (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 VBOOL *show);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetShowPositionControls (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 VBOOL show);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetShowTracker (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *show);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetShowTracker (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL show);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetEnablePositionControls (CAObjHandle objectHandle,
                                                                   ERRORINFO *errorInfo,
                                                                   VBOOL *enable);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetEnablePositionControls (CAObjHandle objectHandle,
                                                                   ERRORINFO *errorInfo,
                                                                   VBOOL enable);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetEnableTracker (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL *enable);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetEnableTracker (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL enable);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetEnabled (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL *pEnabled);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetEnabled (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL pEnabled);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetDisplayForeColor (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             MediaPlayerType_VB_OLE_COLOR *foreColor);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetDisplayForeColor (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             MediaPlayerType_VB_OLE_COLOR foreColor);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetDisplayBackColor (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             MediaPlayerType_VB_OLE_COLOR *backColor);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetDisplayBackColor (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             MediaPlayerType_VB_OLE_COLOR backColor);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetDisplayMode (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        enum MediaPlayerEnum_MPDisplayModeConstants *pValue);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetDisplayMode (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        enum MediaPlayerEnum_MPDisplayModeConstants pValue);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetVideoBorder3D (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL *pVideoBorderWidth);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetVideoBorder3D (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL pVideoBorderWidth);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetVideoBorderWidth (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             long *pVideoBorderWidth);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetVideoBorderWidth (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             long pVideoBorderWidth);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetVideoBorderColor (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             MediaPlayerType_VB_OLE_COLOR *pVideoBorderWidth);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetVideoBorderColor (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             MediaPlayerType_VB_OLE_COLOR pVideoBorderWidth);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetShowGotoBar (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *pbool);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetShowGotoBar (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL pbool);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetShowStatusBar (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL *pbool);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetShowStatusBar (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL pbool);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetShowCaptioning (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           VBOOL *pbool);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetShowCaptioning (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           VBOOL pbool);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetShowAudioControls (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              VBOOL *pbool);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetShowAudioControls (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              VBOOL pbool);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetCaptioningID (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         char **pstrText);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetCaptioningID (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         const char *pstrText);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetMute (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL *vbool);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetMute (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL vbool);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetCanPreview (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL *pCanPreview);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetPreviewMode (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *pPreviewMode);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetPreviewMode (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL pPreviewMode);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetHasMultipleItems (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL *pHasMuliItems);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetLanguage (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long *pLanguage);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetLanguage (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long pLanguage);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetAudioStream (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        long *pStream);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetAudioStream (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        long pStream);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetSAMIStyle (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      char **pbstrStyle);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetSAMIStyle (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      const char *pbstrStyle);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetSAMILang (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     char **pbstrLang);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetSAMILang (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     const char *pbstrLang);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetSAMIFileName (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         char **pbstrFileName);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetSAMIFileName (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         const char *pbstrFileName);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetStreamCount (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        long *pStreamCount);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetClientId (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     char **pbstrClientId);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetConnectionSpeed (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            long *plConnectionSpeed);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetAutoSize (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL *pbool);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetAutoSize (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL pbool);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetEnableFullScreenControls (CAObjHandle objectHandle,
                                                                     ERRORINFO *errorInfo,
                                                                     VBOOL *pbVal);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetEnableFullScreenControls (CAObjHandle objectHandle,
                                                                     ERRORINFO *errorInfo,
                                                                     VBOOL pbVal);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetActiveMovie (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        CAObjHandle *ppdispatch);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetNSPlay (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   CAObjHandle *ppdispatch);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetWindowlessVideo (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VBOOL *pbool);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerSetWindowlessVideo (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VBOOL pbool);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerPlay (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerStop (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerPause (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetMarkerTime (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long markerNum,
                                                       double *pMarkerTime);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetMarkerName (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long markerNum,
                                                       char **pbstrMarkerName);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerAboutBox (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetCodecInstalled (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           long codecNum,
                                                           VBOOL *pCodecInstalled);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetCodecDescription (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             long codecNum,
                                                             char **pbstrCodecDescription);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetCodecURL (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long codecNum,
                                                     char **pbstrCodecURL);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetMoreInfoURL (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        enum MediaPlayerEnum_MPMoreInfoType moreInfoType,
                                                        char **pbstrMoreInfoURL);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetMediaInfoString (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            enum MediaPlayerEnum_MPMediaInfoType mediaInfoType,
                                                            char **pbstrMediaInfo);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerCancel (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerOpen (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              const char *bstrFileName);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerIsSoundCardEnabled (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VBOOL *pbSoundCard);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerNext (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerPrevious (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerStreamSelect (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long streamNum);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerFastForward (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerFastReverse (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetStreamName (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long streamNum,
                                                       char **pbstrStreamName);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetStreamGroup (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        long streamNum,
                                                        long *pStreamGroup);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerGetStreamSelected (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           long streamNum,
                                                           VBOOL *pStreamSelected);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdButtonSelectAndActivate (CAObjHandle objectHandle,
                                                                    ERRORINFO *errorInfo,
                                                                    unsigned long uiButton);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdUpperButtonSelect (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdLowerButtonSelect (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdLeftButtonSelect (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdRightButtonSelect (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdButtonActivate (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdForwardScan (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        double dwSpeed);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdBackwardScan (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         double dwSpeed);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdPrevPGSearch (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdTopPGSearch (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdNextPGSearch (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdTitlePlay (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      unsigned long uiTitle);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdChapterPlay (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        unsigned long uiTitle,
                                                        unsigned long uiChapter);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdChapterSearch (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          unsigned long chapter);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdMenuCall (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     enum MediaPlayerEnum_DVDMenuIDConstants menuID);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdResumeFromMenu (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdTimePlay (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     unsigned long uiTitle,
                                                     const char *bstrTime);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdTimeSearch (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       const char *bstrTime);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdChapterPlayAutoStop (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                unsigned long ulTitle,
                                                                unsigned long ulChapter,
                                                                unsigned long ulChaptersToPlay);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdStillOff (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGoUp (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetTotalTitleTime (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              char **bstrTime);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetNumberOfChapters (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                unsigned long ulTitle,
                                                                unsigned long *ulNumChapters);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetAudioLanguage (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             unsigned long ulStream,
                                                             char **bstrAudioLang);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetSubpictureLanguage (CAObjHandle objectHandle,
                                                                  ERRORINFO *errorInfo,
                                                                  unsigned long ulStream,
                                                                  char **bstrSubpictureLang);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetAllGPRMs (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VARIANT *vtGPRM);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetAllSPRMs (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VARIANT *vtSPRM);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdUOPValid (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     unsigned long ulUOP,
                                                     VBOOL *bValid);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetButtonsAvailable (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                unsigned long *ulButtonsAvailable);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetCurrentButton (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             unsigned long *ulCurrentButton);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetAudioStreamsAvailable (CAObjHandle objectHandle,
                                                                     ERRORINFO *errorInfo,
                                                                     unsigned long *ulAudioStreamsAvailable);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetCurrentAudioStream (CAObjHandle objectHandle,
                                                                  ERRORINFO *errorInfo,
                                                                  unsigned long *ulAudioStream);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdSetCurrentAudioStream (CAObjHandle objectHandle,
                                                                  ERRORINFO *errorInfo,
                                                                  unsigned long ulAudioStream);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetCurrentSubpictureStream (CAObjHandle objectHandle,
                                                                       ERRORINFO *errorInfo,
                                                                       unsigned long *ulSubpictureStream);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdSetCurrentSubpictureStream (CAObjHandle objectHandle,
                                                                       ERRORINFO *errorInfo,
                                                                       unsigned long ulSubpictureStream);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetSubpictureStreamsAvailable (CAObjHandle objectHandle,
                                                                          ERRORINFO *errorInfo,
                                                                          unsigned long *ulNumSubpictureStreams);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetSubpictureOn (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VBOOL *bSubpictureON);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdSetSubpictureOn (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VBOOL bSubpictureON);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetAnglesAvailable (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               unsigned long *ulAnglesAvailable);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetCurrentAngle (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            unsigned long *ulAngle);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdSetCurrentAngle (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            unsigned long ulAngle);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetCurrentTitle (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            unsigned long *ulTitle);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetCurrentChapter (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              unsigned long *ulChapter);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetCurrentTime (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           char **bstrTime);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdSetRoot (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    const char *pbstrPath);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetRoot (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    char **pbstrPath);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetFramesPerSecond (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               unsigned long *ulFps);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetCurrentDomain (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             unsigned long *ulDomain);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetTitlesAvailable (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               unsigned long *ulTitles);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetVolumesAvailable (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                unsigned long *pulVolumes);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetCurrentVolume (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             unsigned long *pulVolume);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetCurrentDiscSide (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               unsigned long *pulDiscSide);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetCCActive (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *bCCActive);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdSetCCActive (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL bCCActive);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetCurrentCCService (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                unsigned long *pulService);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdSetCurrentCCService (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                unsigned long pulService);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetUniqueID (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        char **pvtUniqueID);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdGetColorKey (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        unsigned long *pClr);

HRESULT CVIFUNC MediaPlayer_IMediaPlayerDvdSetColorKey (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        unsigned long pClr);

HRESULT CVIFUNC MediaPlayer__MediaPlayerEventsRegOnDVDNotify (CAObjHandle serverObject,
                                                              _MediaPlayerEventsRegOnDVDNotify_CallbackType callbackFunction,
                                                              void *callbackData,
                                                              int enableCallbacks,
                                                              int *callbackId);

HRESULT CVIFUNC MediaPlayer__MediaPlayerEventsRegOnEndOfStream (CAObjHandle serverObject,
                                                                _MediaPlayerEventsRegOnEndOfStream_CallbackType callbackFunction,
                                                                void *callbackData,
                                                                int enableCallbacks,
                                                                int *callbackId);

HRESULT CVIFUNC MediaPlayer__MediaPlayerEventsRegOnKeyDown (CAObjHandle serverObject,
                                                            _MediaPlayerEventsRegOnKeyDown_CallbackType callbackFunction,
                                                            void *callbackData,
                                                            int enableCallbacks,
                                                            int *callbackId);

HRESULT CVIFUNC MediaPlayer__MediaPlayerEventsRegOnKeyUp (CAObjHandle serverObject,
                                                          _MediaPlayerEventsRegOnKeyUp_CallbackType callbackFunction,
                                                          void *callbackData,
                                                          int enableCallbacks,
                                                          int *callbackId);

HRESULT CVIFUNC MediaPlayer__MediaPlayerEventsRegOnKeyPress (CAObjHandle serverObject,
                                                             _MediaPlayerEventsRegOnKeyPress_CallbackType callbackFunction,
                                                             void *callbackData,
                                                             int enableCallbacks,
                                                             int *callbackId);

HRESULT CVIFUNC MediaPlayer__MediaPlayerEventsRegOnMouseMove (CAObjHandle serverObject,
                                                              _MediaPlayerEventsRegOnMouseMove_CallbackType callbackFunction,
                                                              void *callbackData,
                                                              int enableCallbacks,
                                                              int *callbackId);

HRESULT CVIFUNC MediaPlayer__MediaPlayerEventsRegOnMouseDown (CAObjHandle serverObject,
                                                              _MediaPlayerEventsRegOnMouseDown_CallbackType callbackFunction,
                                                              void *callbackData,
                                                              int enableCallbacks,
                                                              int *callbackId);

HRESULT CVIFUNC MediaPlayer__MediaPlayerEventsRegOnMouseUp (CAObjHandle serverObject,
                                                            _MediaPlayerEventsRegOnMouseUp_CallbackType callbackFunction,
                                                            void *callbackData,
                                                            int enableCallbacks,
                                                            int *callbackId);

HRESULT CVIFUNC MediaPlayer__MediaPlayerEventsRegOnClick (CAObjHandle serverObject,
                                                          _MediaPlayerEventsRegOnClick_CallbackType callbackFunction,
                                                          void *callbackData,
                                                          int enableCallbacks,
                                                          int *callbackId);

HRESULT CVIFUNC MediaPlayer__MediaPlayerEventsRegOnDblClick (CAObjHandle serverObject,
                                                             _MediaPlayerEventsRegOnDblClick_CallbackType callbackFunction,
                                                             void *callbackData,
                                                             int enableCallbacks,
                                                             int *callbackId);

HRESULT CVIFUNC MediaPlayer__MediaPlayerEventsRegOnOpenStateChange (CAObjHandle serverObject,
                                                                    _MediaPlayerEventsRegOnOpenStateChange_CallbackType callbackFunction,
                                                                    void *callbackData,
                                                                    int enableCallbacks,
                                                                    int *callbackId);

HRESULT CVIFUNC MediaPlayer__MediaPlayerEventsRegOnPlayStateChange (CAObjHandle serverObject,
                                                                    _MediaPlayerEventsRegOnPlayStateChange_CallbackType callbackFunction,
                                                                    void *callbackData,
                                                                    int enableCallbacks,
                                                                    int *callbackId);

HRESULT CVIFUNC MediaPlayer__MediaPlayerEventsRegOnScriptCommand (CAObjHandle serverObject,
                                                                  _MediaPlayerEventsRegOnScriptCommand_CallbackType callbackFunction,
                                                                  void *callbackData,
                                                                  int enableCallbacks,
                                                                  int *callbackId);

HRESULT CVIFUNC MediaPlayer__MediaPlayerEventsRegOnBuffering (CAObjHandle serverObject,
                                                              _MediaPlayerEventsRegOnBuffering_CallbackType callbackFunction,
                                                              void *callbackData,
                                                              int enableCallbacks,
                                                              int *callbackId);

HRESULT CVIFUNC MediaPlayer__MediaPlayerEventsRegOnError (CAObjHandle serverObject,
                                                          _MediaPlayerEventsRegOnError_CallbackType callbackFunction,
                                                          void *callbackData,
                                                          int enableCallbacks,
                                                          int *callbackId);

HRESULT CVIFUNC MediaPlayer__MediaPlayerEventsRegOnMarkerHit (CAObjHandle serverObject,
                                                              _MediaPlayerEventsRegOnMarkerHit_CallbackType callbackFunction,
                                                              void *callbackData,
                                                              int enableCallbacks,
                                                              int *callbackId);

HRESULT CVIFUNC MediaPlayer__MediaPlayerEventsRegOnWarning (CAObjHandle serverObject,
                                                            _MediaPlayerEventsRegOnWarning_CallbackType callbackFunction,
                                                            void *callbackData,
                                                            int enableCallbacks,
                                                            int *callbackId);

HRESULT CVIFUNC MediaPlayer__MediaPlayerEventsRegOnNewStream (CAObjHandle serverObject,
                                                              _MediaPlayerEventsRegOnNewStream_CallbackType callbackFunction,
                                                              void *callbackData,
                                                              int enableCallbacks,
                                                              int *callbackId);

HRESULT CVIFUNC MediaPlayer__MediaPlayerEventsRegOnDisconnect (CAObjHandle serverObject,
                                                               _MediaPlayerEventsRegOnDisconnect_CallbackType callbackFunction,
                                                               void *callbackData,
                                                               int enableCallbacks,
                                                               int *callbackId);

HRESULT CVIFUNC MediaPlayer__MediaPlayerEventsRegOnPositionChange (CAObjHandle serverObject,
                                                                   _MediaPlayerEventsRegOnPositionChange_CallbackType callbackFunction,
                                                                   void *callbackData,
                                                                   int enableCallbacks,
                                                                   int *callbackId);

HRESULT CVIFUNC MediaPlayer__MediaPlayerEventsRegOnDisplayModeChange (CAObjHandle serverObject,
                                                                      _MediaPlayerEventsRegOnDisplayModeChange_CallbackType callbackFunction,
                                                                      void *callbackData,
                                                                      int enableCallbacks,
                                                                      int *callbackId);

HRESULT CVIFUNC MediaPlayer__MediaPlayerEventsRegOnReadyStateChange (CAObjHandle serverObject,
                                                                     _MediaPlayerEventsRegOnReadyStateChange_CallbackType callbackFunction,
                                                                     void *callbackData,
                                                                     int enableCallbacks,
                                                                     int *callbackId);

HRESULT CVIFUNC MediaPlayer__IRadioPlayerEventsRegOnStateChange (CAObjHandle serverObject,
                                                                 _IRadioPlayerEventsRegOnStateChange_CallbackType callbackFunction,
                                                                 void *callbackData,
                                                                 int enableCallbacks,
                                                                 int *callbackId);
#ifdef __cplusplus
    }
#endif
#endif /* _MEDIAPLAYER_H */
