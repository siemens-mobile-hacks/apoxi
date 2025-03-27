/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apoxi_ObjectTreeService_hpp)
#define Apoxi_ObjectTreeService_hpp
#include <AddOns/Services/Service.hpp>
#include <Afs/Registry.hpp>


class ObjectTreeService : public Service {
    public:

        ObjectTreeService(const Guid& guid);

        virtual ~ObjectTreeService();

        // The following Interfaces are for Generic Applications (App -> Registry)

        virtual RegResult Get(const CHAR* uri, RegObjectData& reg_data_object, INT16 bufsize) = 0; 

        virtual RegResult Replace(const CHAR* uri, const RegObjectData& reg_data_object) = 0; 

        virtual RegResult Add(const CHAR* uri, const RegObjectData& reg_data_object)= 0;

        virtual RegResult Delete(const CHAR* uri) = 0;

        virtual RegResult Lock(const CHAR* uri, INT16 lockid) = 0;

        virtual RegResult Unlock(INT16 lockid) = 0;

};
#endif


