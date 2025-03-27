/*  ------------------------------------------------------------------------
    Copyright (C) 2003 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_DrmInfo_hpp)
#define Apoxi_DrmInfo_hpp


#include <Auxiliary/NonCloneable.hpp>
#include <Kernel/Types.hpp>

struct DrmInfoPersistStructure {
    UINT16 m_permissions;
};

class DrmInfo : public NonCloneable {

    public:

        enum Operation {
            c_none =    0,
            c_play =    1,
            c_display = 2,
            c_execute = 4,
            c_print =   8, 
            c_forward = 16,

            c_no_lock = 32,
            c_forward_lock = 64,
            c_combined_delivery = 128,
            c_separate_delivery = 256
        };


        DrmInfo();
        virtual ~DrmInfo(); 

        void Init(UINT16 drm_method);

        void ReadFrom(const DrmInfoPersistStructure &persist_structure);
        void WriteTo(DrmInfoPersistStructure *persist_structure) const;

        
        BOOLEAN IsForwardLocked();

        BOOLEAN IsCombinedDelivered();

        BOOLEAN IsSeparateDelivered();


        BOOLEAN IsPlayable();

        BOOLEAN IsDisplayable();

        BOOLEAN IsExecutable();
        
        BOOLEAN IsPrintable();

        BOOLEAN IsForwardable();
        
    private:
        UINT16 m_permissions;
};      


#endif //Apoxi_DrmInfo_hpp

