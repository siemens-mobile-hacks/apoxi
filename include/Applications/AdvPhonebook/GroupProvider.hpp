/* =============================================================================
** Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
** =============================================================================
**
** =============================================================================
**
** This document contains proprietary information belonging to COMNEON.
** Passing on and copying of this document, use and communication of its
** contents is not permitted without prior written authorisation.
**
** =============================================================================
*/

#if ! defined(Mmi_GroupProvider_hpp)
#define Mmi_GroupProvider_hpp

#include <Auxiliary/Provider.hpp>
#include <Config/Config.hpp>

const INT c_max_groups = 10;

/*------------------------------------------------------------------
                            GroupProvider
 ------------------------------------------------------------------*/

class GroupProvider : public Provider {

    public:

        struct GroupRec {
            INT         id;
            WString     name;
        };

        typedef Provider Base;

        GroupProvider();
        virtual ~GroupProvider();

        void Init();

        virtual INT GetProviderId() const;
        virtual INT RowCount();
        
        virtual BOOLEAN GetDataItem(IN INT columnid, 
                                    IN INT row, 
                                    OUT DataItem & item);


    private:
        GroupRec m_groups[c_max_groups];
};

#endif
