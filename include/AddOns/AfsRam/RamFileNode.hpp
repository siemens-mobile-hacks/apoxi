/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined Apoxi_RamFileNode_hpp
#define Apoxi_RamFileNode_hpp

#include <Auxiliary/String.hpp>
#include <AddOns/AfsRam/RamTypes.hpp>
#include <AddOns/AfsRam/RamFileObj.hpp>

class RamFileNode;

typedef RamFileNode *RamHandle;
// TODO comment and document all header files -> DOXYGEN
class RamFileNode
{
    public:
        RamFileNode(
            RamFileObj *file_obj = 0,
            RamFileNode *parent = 0,
            RamFileNode *equal_directory_item = 0,
            RamFileNode *sub_directory_item = 0); // nodes and file object must be created externally
        ~RamFileNode();

        BOOLEAN InsertEqualNode(RamFileNode *directory_item);
        BOOLEAN InsertSubNode(RamFileNode *file_item);

        BOOLEAN DeleteSubNode(const Pathname &pathname);
        BOOLEAN DeleteEqualNode(const Pathname &pathname);
        BOOLEAN DeleteAllSubNodes();
        BOOLEAN DeleteAllEqualNodes();

        RamFileNode* GetParentNode() const;
        RamFileNode* GetEqualDirectoryNode() const;
        RamFileNode* GetSubDirectoryNode() const;
        RamFileObj* GetRamFileObj() const;
        void SetRamFileObj(RamFileObj *file_obj); // file_obj must not be null

        WString GetSegmentName() const;
        BOOLEAN SetSegmentName(const WString &segment_name);

        WString TrackPathToRoot();

    private:
        void InitFileNode(
            WString segment_name,
            RamFileObj *file_obj = 0,
            RamFileNode *parent = 0,
            RamFileNode *equal_directory_item = 0,
            RamFileNode *sub_directory_item = 0);

        void SetParentNode(RamFileNode *parent);
        void SetEqualDirectoryNode(RamFileNode *equal_item);
        void SetSubDirectoryNode(RamFileNode *sub_item);

        BOOLEAN IsRootNode() const;

        BOOLEAN DeleteFileObj();

        WString m_segment_name;
        RamFileNode *m_parent;
        RamFileNode *m_equal_directory_item;
        RamFileNode *m_sub_directory_item;
        RamFileObj *m_file_obj;

        friend class RamFileSystem;
};

#endif  // Apoxi_RamFileNode_hpp


