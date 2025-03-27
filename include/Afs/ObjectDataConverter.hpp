/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_ObjectDataConverter_hpp)
#define Apoxi_ObjectDataConverter_hpp

#include <Afs/RegistryTypes.hpp>

class DataItem;

class ObjectDataConverter {
    public:

        static void ConvertObjectDataToDataItem(const RegObjectData& object_data, DataItem& data_item);

        static BOOLEAN ConvertDataItemToObjectData(const DataItem& data_item, RegObjectData& object_data);

};
#endif


