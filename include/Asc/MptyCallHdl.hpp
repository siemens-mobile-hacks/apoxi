/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Asc_MptyCallHdl_hpp)
#define Asc_MptyCallHdl_hpp

#include <Asc/CallHdlBase.hpp>

#include <Asc/CallHandler.hpp>

class CallHdl;
class MptyCallHdl :public CallHdlBase {
    typedef CallHdlBase Base;

    public:
        //---------------------------------------------------------------------
        // Construction, destruction initialization
        //---------------------------------------------------------------------
        
        explicit MptyCallHdl(ChannelNo channel_no = c_null_channel_no);

        virtual ~MptyCallHdl();

        
        // --------------------------------------------------------------------
        // providing CallHdls for active, held and setup call
        // --------------------------------------------------------------------
        
        static MptyCallHdl GetMptyCallHdl();


        // --------------------------------------------------------------------
        // call related operations on CallHdl
        // --------------------------------------------------------------------
        
#if defined(APOXI_SYNC_RELEASE)
        virtual CallApiRc Release(TimeSpan * calling_time = 0, BOOLEAN wait_condition = TRUE);
#else
        virtual CallApiRc Release(TimeSpan * calling_time = 0, BOOLEAN wait_condition = FALSE);
#endif

        
        virtual CallApiRc Hold();


        virtual CallApiRc Retrieve();


        CallApiRc Split(const CallHdl & active_call) const;

        virtual CallApiRc StartDtmfToneGeneration(KeyCode key);

        
        virtual CallApiRc StopDtmfToneGeneration();

        // --------------------------------------------------------------------
        // access to multi-party call data
        // --------------------------------------------------------------------

        CallHdl GetMember(INT pos = 0) const;

        
        INT GetMemberCount() const;


        virtual DateTime GetStartTime() const ;


        // --------------------------------------------------------------------
        // general information of call referred by a CallHdl
        // --------------------------------------------------------------------

        virtual BOOLEAN IsActive() const;

        virtual BOOLEAN IsHeld() const;

        virtual BOOLEAN IsSame(const MptyCallHdl & mpty_call) const;

        virtual BOOLEAN IsValid() const { return m_mpty_channel_no != c_null_channel_no; }


        // --------------------------------------------------------------------
        // misc
        // --------------------------------------------------------------------

        virtual BOOLEAN IsHoldPermitted() const;

        virtual BOOLEAN IsRetrievePermitted() const;

        BOOLEAN IsSplitPermitted(const CallHdl & call) const;

        virtual void Invalidate() { m_mpty_channel_no = c_null_channel_no; }

        ChannelNo GetMptyChannelNo() const { return m_mpty_channel_no; }

        virtual CallIndex GetCallIndex() const { return c_mpty_indication; }

        virtual TimeSpan GetCallDuration() const;

    private:
        ChannelNo m_mpty_channel_no;
};

#endif // Asc_MptyCallHdl_hpp



