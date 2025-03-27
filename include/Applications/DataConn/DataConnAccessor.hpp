/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(ApoxiRb_DataConnAccessor_hpp)
#define ApoxiRb_DataConnAccessor_hpp

#include <Socket/SocketTypes.hpp>
#include <GuiExtensions/AbstractMmiMenuAccessor.hpp>
#include <GuiExtensions/MmiPrompt.hpp>
#include <DataConn/DataConnOptionWin.hpp>


#if defined (APOXI_STACK_UMTS)
    const INT c_psd_menu_item_count = 24;
#else
    const INT c_psd_menu_item_count = 10;
#endif

#if !defined(DATA_CONN_APP_EXCLUDE_SERIAL)
    const INT c_ser_menu_item_count = 2;
#endif
class DataConnProfile;
class CsdDataConnProfile;
class PsdDataConnProfile;

class DataConnAccessor : public AbstractMmiMenuAccessor {
    typedef AbstractMmiMenuAccessor Base;

    public:
        DataConnAccessor(DataConnProfile *profile);
        virtual ~DataConnAccessor();

        void Init();

        virtual BOOLEAN First();
        virtual BOOLEAN Next();

        virtual const WCHAR* GetItemText(BOOLEAN highlighted);

        virtual INT CountSettings() const;
                
        virtual void Update();
        
        virtual BOOLEAN IsEnabled();
        
    protected:
        DataConnProfileId GetProfileId() { return m_profile_id; }
        virtual INT GetIndex() { return m_it; }

        virtual void OnTrigger(INT selected_idx);

    private:
        WString             m_settings[10];
        INT                 m_it;
        DataConnProfileId   m_profile_id;
        DataConnProfile     *m_profile;
};

class CsdDataConnAccessor : public DataConnAccessor {
    typedef DataConnAccessor Base;

    public:
        CsdDataConnAccessor(CsdDataConnProfile *profile);
        virtual ~CsdDataConnAccessor();

        void Init();
        
        virtual const WCHAR* GetItemText(BOOLEAN highlighted);
        
        virtual void Update();

    protected:
        virtual INT CountSettings() const;
        virtual void OnTrigger(INT selected_idx);

    private:
        CsdDataConnProfile *m_profile;
        WString             m_add_settings[10];
};

class PsdDataConnAccessor : public DataConnAccessor {
    typedef DataConnAccessor Base;

    public:
        PsdDataConnAccessor(PsdDataConnProfile *profile);
        virtual ~PsdDataConnAccessor();

        void Init();
        
        virtual const WCHAR* GetItemText(BOOLEAN highlighted);

        virtual void Update();
        
    protected:
        virtual INT CountSettings() const;
        virtual void OnTrigger(INT selected_idx);

    private:        
        PsdDataConnProfile *    m_profile;
        WString                 m_add_settings[c_psd_menu_item_count];
};

#if !defined(DATA_CONN_APP_EXCLUDE_SERIAL)
class SerDataConnProfile;
class SerDataConnAccessor : public DataConnAccessor {
    typedef DataConnAccessor Base;

    public:
        SerDataConnAccessor(SerDataConnProfile *profile);
        virtual ~SerDataConnAccessor();

        void Init();
        
        virtual const WCHAR* GetItemText(BOOLEAN highlighted);

        virtual void Update();
        
    protected:
        virtual INT CountSettings() const;
        virtual void OnTrigger(INT selected_idx);

    private:        
        SerDataConnProfile *    m_profile;
        WString                 m_add_settings[c_ser_menu_item_count];
};
#endif

#endif  // ApoxiRb_DataConnAccessor_hpp
