/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_RegIterator_hpp)
#define Apoxi_RegIterator_hpp
#include <Afs/Uri.hpp>
#include <Afs/RegistryTypes.hpp>


class RegIterator{

public:

    enum NodeType{
        InteriorType,
        LeafType
    };

    enum LeafnodeType{
        BooleanNodeType,
        StringNodeType,
        BlobNodeType,
        IntegerNodeType,
        BlobFileType
    };
    struct LeafMetaData{
        LeafnodeType type;
        UINT32 size;
    };
    struct InteriorMetaData{
        UINT16 childcount;
    };
    
    RegIterator() : m_file_id(-1), m_node_uri(".") {}

    ~RegIterator() {};

    RegResult Get(Uri& it_uri);

    RegResult Set(const Uri& it_uri);
        
    RegResult TraverseDown(NodeType& nodetype);
        
    RegResult TraverseUp(NodeType& nodetype);
        
    RegResult TraverseNext(NodeType& nodetype);
        
    RegResult GetLeafMetaData(LeafMetaData& metadata);
        
    RegResult GetInteriorMetaData(InteriorMetaData& metadata);

    private:
                        
    INT16  m_file_id;

    Uri m_node_uri;
};//RegIterator

#endif  // Apoxi_PathIterator_hpp

