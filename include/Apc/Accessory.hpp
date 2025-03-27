/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apc_Accessory_hpp)
#define Apc_Accessory_hpp

#include <Kernel/Types.hpp>

/*  ------------------------------------------------------------------------
    Accessory
    ------------------------------------------------------------------------ */
class Accessory
{
    friend class HeadSet;
    public:
        //TODO: enum-values must be hold up-to-date with acc.h!!!
        enum Type {
            None            = 0x0000,
            HeadSet         = 0x0001, 
            ServicePlug     = 0x0002,
            AcDcAdaptor     = 0x0004,
            GpsModule       = 0x0008,
            DataCable       = 0x0010,
            StereoHeadSet   = 0x0020,
            HandsFreeCarKit = 0x0040,
            Unknown         = 0x7FFF
        };

        Accessory(UINT16 *data = 0) { 
            if (data != 0) {
                memcpy(m_data, data, sizeof(m_data)); 

                // override type sent from driver on attaching
                if ((GetType() == HeadSet) && (GetParam(1) == 0x21)) {
                    SetType(StereoHeadSet);
                }
            }
            else {
                m_data[0] = (UINT16) Unknown;
            }
        }
    
        Type GetType() const { return (Type) m_data[0]; };
        void SetType(Type type) { m_data[0] = (UINT16) type; };

        UINT16 GetParam(INT i) const { return ((i >= 0 && i <= 7) ? m_data[i] : 0xffff); };
        void SetParam(INT i, UINT16 param) { if (i >= 0 && i <= 7) m_data[i] = param; };

    private:
        UINT16 m_data[8];
};

/*  ------------------------------------------------------------------------
    HeadSet
    ------------------------------------------------------------------------ */
class HeadSet {
    public:
        HeadSet(Accessory *accessory) : m_accessory(accessory) { 
            ASSERT_ALWAYS(accessory != 0 && ((accessory->GetType() == Accessory::HeadSet) || (accessory->GetType() == Accessory::StereoHeadSet))); 
        }
        void SetAttached(BOOLEAN attached) { m_accessory->m_data[1] = (BOOLEAN) attached; } 
        BOOLEAN IsAttached() const { return (m_accessory->m_data[1] != 0); }
        BOOLEAN IsMono() const { return (m_accessory->GetType() == Accessory::HeadSet); }
    private:
        Accessory *m_accessory;
};


#endif  // Apc_Accessory_hpp

