/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Auxiliary_BinDataOwner_hpp)
#define Auxiliary_BinDataOwner_hpp

#include <Auxiliary/BinData.hpp>
#include <Auxiliary/NiSharedPtr.hpp>
#include <Auxiliary/DataSource.hpp>

#ifndef DOXYGEN_SHOULD_SKIP_THIS

class BinDataOwner
{
public:


    inline BinDataOwner(BinData* bin_data);


    inline ~BinDataOwner();


    inline BOOLEAN Read(UINT32 idx, UINT8 &val) const;


    inline UINT32 Read(UINT32 idx, void *buf, UINT32 nbytes) const;


    inline UINT32 GetLength() const;


    inline const DrmAsset& GetDrmAsset() const;

    inline const BinData* GetBinData();

private:
    BinData*    m_bin_data;
};

typedef NiSharedPtr<BinDataOwner> BinDataPtr;

/*  ------------------------------------------------------------------------
    BinDataOwner
    ------------------------------------------------------------------------ */
BinDataOwner::BinDataOwner(BinData* bin_data) : m_bin_data(bin_data) {
}

/*  ------------------------------------------------------------------------
    ~BinDataOwner
    ------------------------------------------------------------------------ */
BinDataOwner::~BinDataOwner() {
    m_bin_data->ReleaseInstance();
}

/*  ------------------------------------------------------------------------
    Read
    ------------------------------------------------------------------------ */
BOOLEAN BinDataOwner::Read(UINT32 idx, UINT8 &val) const  
{ 
    return m_bin_data->Read(idx, val); 
}

/*  ------------------------------------------------------------------------
    Read
    ------------------------------------------------------------------------ */
UINT32 BinDataOwner::Read(UINT32 idx, void *buf, UINT32 nbytes) const 
{ 
    return m_bin_data->Read(idx, buf, nbytes); 
}

/*  ------------------------------------------------------------------------
    GetLength
    ------------------------------------------------------------------------ */
UINT32 BinDataOwner::GetLength() const 
{ 
    return m_bin_data->GetLength(); 
}

/*  ------------------------------------------------------------------------
    GetDrmAsset
    ------------------------------------------------------------------------ */
const DrmAsset& BinDataOwner::GetDrmAsset() const 
{ 
    return m_bin_data->GetDrmAsset(); 
}

/*  ------------------------------------------------------------------------
    GetBinData
    ------------------------------------------------------------------------ */
const BinData* BinDataOwner::GetBinData() 
{ 
    return m_bin_data; 
}

#endif // DOXYGEN_SHOULD_SKIP_THIS

#endif //Auxiliary_BinDataOwner_hpp

