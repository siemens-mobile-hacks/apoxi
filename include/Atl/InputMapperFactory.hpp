/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(GuiExtensions_InputMapperFactory_hpp)
#define GuiExtensions_InputMapperFactory_hpp

class InputMapper;

class InputMapperFactory {
    public:
        
        InputMapperFactory();

        virtual ~InputMapperFactory();

        virtual void Init() =0;

        virtual InputMapper* CreateInstance() = 0;

        virtual INT GetId() const = 0;
};
#endif  // GuiExtensions_InputMapperFactory_hpp


