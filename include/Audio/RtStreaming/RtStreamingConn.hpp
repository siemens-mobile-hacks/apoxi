/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_RtStreamingConn_hpp)
#define Apoxi_RtStreamingConn_hpp

#include <Kernel/Types.hpp>

//  Forward declarations of classes
class RtStreamingSink;
class RtStreamingSource;
class RtStreamingBuffer;

class RtStreamingConn {

    friend class RtStreamingEndPoint;
    friend class RtStreamingSink;
    friend class RtStreamingSource;

    public:
        enum StopCause {
            StOnEndOfData,  
            StOnCommand,    
            StOnSrcError,       
            StOnSnkError        
        };

        RtStreamingConn();

        virtual ~RtStreamingConn();

        BOOLEAN                 Start();

        BOOLEAN                 Stop();

    protected:

        virtual BOOLEAN         StopAction();

        virtual void            OnStarted() {};

        virtual void            OnStopped(StopCause cause) {};

        void                    Attach(RtStreamingSink &        sink);
        void                    Attach(RtStreamingSource &      source);

    private:
        enum StreamingState {
            StmgInitial,
            StmgReady,
            StmgStart,
            StmgStarted,
            StmgActive,
            StmgStopped
        };

        StreamingState          m_stm_state;
        StopCause               m_end_cause;
        INT                     m_buf_cnt;
        RtStreamingSource *     m_src_ptr;
        RtStreamingSink *       m_snk_ptr;

        inline  BOOLEAN         IsInState(StreamingState    s) const;
        void                    SetStreamingState(StreamingState    s);

        void                    CheckStateAfterAttach();
        void                    CheckStateAfterDetach();

        void                    Detach(RtStreamingSink &        sink);
        void                    Detach(RtStreamingSource &      source);
        
        void                    HandleDataReady();
        void                    HandleError();
        void                    HandleStoppedOnCause(RtStreamingConn::StopCause cause);

        void                    HandleBufferSwitch(RtStreamingBuffer &  buffer);
};

/*  ------------------------------------------------------------------------
    IsInState
    ------------------------------------------------------------------------ */
BOOLEAN RtStreamingConn::IsInState(StreamingState   s) const
{
    return (s == m_stm_state);
}// IsInState
                             
#endif  // Apoxi_RtStreamingConn_hpp

