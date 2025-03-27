// /*   ------------------------------------------------------------------------
//  Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
//  ------------------------------------------------------------------------
//  This document contains proprietary information belonging to COMNEON.
//  Passing on and copying of this document, use and communication of its
//  contents is not permitted without prior written authorisation.
//  ------------------------------------------------------------------------ */
// 

#if ! defined(UnifiedInbox_UibServiceImpl_hpp)
#define UnifiedInbox_UibServiceImpl_hpp

#include <Common/MmiServices.hpp>
#include <Config/UibConfig.hpp>


class UibServiceImpl : public UibService
{
    public:
        
        virtual ~UibServiceImpl();

        UibServiceImpl();

        void Init(Application* app);

        virtual ServiceResult NotifyArrival() const;

        virtual ServiceResult Register(UINT8 box_type, Provider* folder) const;

    private:
        Application* m_app;

};

#endif // UnifiedInbox_UibServiceImpl_hpp
