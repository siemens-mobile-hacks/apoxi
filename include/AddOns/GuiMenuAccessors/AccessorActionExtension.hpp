/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH&  Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AccessorActionExtension_hpp)
#define Apoxi_AccessorActionExtension_hpp

#include <Gui/ActionExtension.hpp>
#include <Auxiliary/WString.hpp>

class AbstractMenuAccessor;

class AccessorActionExtension : public ActionExtension {
    public:
        enum { ID = 0 };

        AccessorActionExtension();

        virtual ~AccessorActionExtension();

        virtual INT GetId() const;

        virtual BOOLEAN IsInstanceOf(INT id) const;

        void SetMenuAccessor(AbstractMenuAccessor* accessor) { m_accessor = accessor; }

        AbstractMenuAccessor* GetMenuAccessor() const { return m_accessor; }

    private:
        AbstractMenuAccessor* m_accessor;
};

#endif // Apoxi_AccessorActionExtension_hpp

