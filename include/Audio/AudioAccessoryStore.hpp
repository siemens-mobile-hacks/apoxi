/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AudioAccessoryStore_hpp)
#define Apoxi_AudioAccessoryStore_hpp

#include <Audio/AudioAccessoryDetails.hpp>

class AudioAccessoryStore
{
    protected:
        AudioAccessoryStore();
        
    public:
        virtual ~AudioAccessoryStore(); //This should be private, but an MSVC++ bug prevents that.

        // override
        virtual const WCHAR* GetName() const;

        static AudioAccessoryStore* GetInstance();

        typedef LinkedList<AudioAccessoryDetails> AccessoryList;
        const AccessoryList& GetAccessoryList() const;

        void AddItem(const AudioAccessoryDetails::AudioAccessoryConfigurationType configuration,
                    const AudioPath::UplinkPathType uplinkPath,
                    const AudioPath::DownlinkPathType downlinkPath,
                    BOOLEAN active,
                    const UINT compat_setting,
                    const WString &type_name,
                    const WString &actual_name = "");


        BOOLEAN UseAccessory (AudioAccessoryDetails *accessory);

        const AudioAccessoryDetails* GetActiveAccessory_HighestPriority() const;
        
        AudioAccessoryDetails* GetAccessoryByName(const WString &accessory_type_name, const WString &accessory_actual_name = "") const;

        AudioAccessoryDetails* GetAccessoryByCfgType(const AudioAccessoryDetails::AudioAccessoryConfigurationType configuration) const;

    protected:
        AccessoryList m_accessory_list;
        static AudioAccessoryStore m_instance;

};

#endif  // Apoxi_AudioAccessoryStore_hpp


