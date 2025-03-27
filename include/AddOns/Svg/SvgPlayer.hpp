/* ------------------------------------------------------------------------
   Copyright (C) COMNEON electronic technology GmbH&  Co. OHG.
   All rights reserved.
   ------------------------------------------------------------------------
   This document contains proprietary information belonging to COMNEON.
   Passing on and copying of this document, use and communication of its
   contents is not permitted without prior written authorisation.
   ------------------------------------------------------------------------ */

#if !defined(Apoxi_SvgPlayer_hpp)
#define Apoxi_SvgPlayer_hpp

#include <Auxiliary/TriggerTimer.hpp>
#include <Kernel/Threadlet.hpp>
#include <Gui/DrawableObject.hpp>

#include "SvgFixPoint.hpp"

#include "SvgDebug.hpp"

class SvgDecoder;
class BinData;
class Bitmap;
class SvgPlayer;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

class SvgThreadlet : public Threadlet {
    typedef Threadlet Base;

    public:
        virtual ~SvgThreadlet();

        static SvgThreadlet* CreateInstance(SvgPlayer* player);

        virtual void ReleaseInstance();

        virtual INT Fn();

    private:
        SvgThreadlet(SvgPlayer* player);
        SvgPlayer *m_player;
};
#endif // DOXYGEN_SHOULD_SKIP_THIS

class SvgPlayer : public DrawableObject {
    typedef DrawableObject Base;

    public:
        /* The types of events that the player supports, note:
            * this list is still very much draft. */
        typedef enum {
            SvgFocusInEvent = 1,
            SvgFocusOutEvent,
            SvgUiActivateEvent,
            SvgActivateEvent,
            SvgClickEvent,
            SvgSelectPreviousHyperlinkEvent,
            SvgSelectNextHyperlinkEvent,
            SvgShowHyperlinksEvent,
            SvgHideHyperlinksEvent,
            SvgUndefinedEvent
        } SvgEventType;

        /* Error codes that the SvgPlayer can generate */
        typedef enum {
            NoError = 0,
            OutOfMemoryError,
            InitializationError,
            AllocationError,
            AnimationLoadFailureError,
            SizeNotSetInDocument,
            IllegalZoomLevel,
            AlreadySet,
            UnspecifiedError,
            DecodingInterruptedError,
            SvgStatusEventHandled = 1
        } SvgErrorType;

        SvgPlayer();

        SvgPlayer(Control* parent);

        SvgPlayer(Control* parent, BinData* p_bindata);

        virtual ~SvgPlayer(void);

        void Init(Control* parent);

        BOOLEAN Init(Control* parent, BinData* data);

        BOOLEAN Load(BinData* data);

        void Play(UINT32 time = 0);

        void Stop();

        void Restart();

        void SetTimePosition(UINT32 time = 0);

        UINT32 GetTimePosition(void) const { return m_player_time_offset; };

        BOOLEAN Rotate(INT16 angle);

        BOOLEAN SetZoomLevel(INT8 level);

        BOOLEAN Pan(XYDIM dx, XYDIM dy);

        WCHAR *GetDocumentTitle(void);

        WCHAR *GetDocumentDescription(void);

        WCHAR *GetPlayerName(void);

        WCHAR *GetPlayerVersion(void);

        void SetEvent(SvgEventType event);

        virtual XYDIM GetDefaultWidth(void) const;

        virtual XYDIM GetDefaultHeight(void) const;

        void SetWidth(XYDIM width);

        void SetHeight(XYDIM height);

        XYDIM GetWidth() const;
        XYDIM GetHeight() const;

        void SetBaseURL(WCHAR *url);

        BOOLEAN IsDocumentZoomable(void) const;
        BOOLEAN IsDocumentPanable(void) const;

        SvgErrorType GetErrorCode (void) const { return m_error_code; };

        BOOLEAN IsDecodingFinished() const { return (BOOLEAN)m_bits.finished_decoding; }

        BOOLEAN IsDecoding() const { return (BOOLEAN)m_bits.is_decoding; }

    protected:
        virtual BOOLEAN OnMessage(const Message& msg);

        virtual void Cleanup();

    private:
        enum {
            SvgStopped   = 0,
            SvgAutoStart = 1,
            SvgRunning   = 2,
            Finished     = 3
        };

        void WaitUntilDecodingIsFinished() { WaitForDecoding(TRUE); }

        void WaitForDecoding(BOOLEAN wait_until_finished);

        void InitProperties();

        void SetErrorCode(SvgErrorType error_code) { m_error_code = error_code; };

        BOOLEAN IsInitialized() const { return (BOOLEAN)m_bits.initialized; };

        void StartDecoding();

        WCHAR* GetMetaDataString(UINT16 key);

        void Halt();

        void OnTimer();

        void Render();

        BOOLEAN Load(BinData* data, BOOLEAN blocking);

        struct {
            UINT op_event_set      : 1;
            UINT finished_decoding : 1;
            UINT is_decoding       : 1;
            UINT stop_decoding     : 1;
            UINT initialized       : 1;
            UINT state             : 2;
            UINT first_frame       : 1;
            UINT subscribed        : 1;
        } m_bits;

        SvgErrorType m_error_code;

        BinData *m_bindata;
        Bitmap *m_bitmap;

        SvgDecoder *m_decoder;
        Application *m_app;

        SvgFixPointTrans m_trans;
        SvgFixPointTrans m_th_trans;

        Ticks m_ticks;
        UINT32 m_player_time_offset;
        UINT32 m_user_time_offset;
        UINT32 m_normalized_time;
        INT32 m_delta;

        XYDIM m_width, m_height;
        XYDIM m_new_width, m_new_height;

        WCHAR *m_url;

        /* Event handling */
        SvgEventType m_event_input;
        SvgEventType m_th_event_input;

        INT8 m_previous_zoom_level;

        /* Animation handling */
        TriggerTimer<SvgPlayer> m_anim_timer;

        /* synchronization */
        Mutex m_paint_mutex;

        /* Friends of this class */
        friend class TriggerTimer<SvgPlayer>;
        friend class SvgPlayerView;
        friend class SvgThreadlet;
        friend class LoadingFinishedCondition;
};

#ifndef DOXYGEN_SHOULD_SKIP_THIS

class SvgPlayerView : public DrawableObjectView {
    typedef DrawableObjectView Base;

    public:
        virtual ~SvgPlayerView();

    private:
        virtual void Draw(const Component& component,
                          DeviceContext* dc,
                          const Rect& repaint_rect) const;

        void StartAnimTimer(SvgPlayer& svg_player, const Ticks& ticks) const;
};
#endif

#endif

