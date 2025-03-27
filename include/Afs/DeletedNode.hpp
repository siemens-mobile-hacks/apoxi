/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */     

#if !defined(Apoxi_DeletedNode_hpp)
#define Apoxi_DeletedNode_hpp


class DeletedNode {

    public:
        DeletedNode() : m_file_id(0), m_next(0), m_prev(0)
        {}

        DeletedNode(INT file_id) : m_file_id(file_id), m_next(0), m_prev(0)
        {}

        ~DeletedNode(){}

        

        INT GetFileId()
        {
            return m_file_id;
        }

        void SetFileId(INT file_id)
        {
            m_file_id = file_id;
        }

        DeletedNode* GetNext()
        {
            return m_next;
        }

        void SetNext(DeletedNode* next)
        {
            m_next = next;
        }

        DeletedNode* GetPrevious()
        {
            return m_prev;
        }

        void SetPrevious(DeletedNode* prev)
        {
            m_prev = prev;
        }

    private:
        
        INT m_file_id;
        DeletedNode*    m_next;
        DeletedNode*    m_prev; 
};


class DeletedNodeList {

    public:

        DeletedNodeList() : m_start(0), m_end(0)
        {}

        ~DeletedNodeList()
        {
            DeletedNode* temp = m_start;
            while(temp)  {
                temp = m_start->GetNext();
                delete m_start;
            }
        }

        DeletedNode* PopBack()
        {
            DeletedNode* ret_val = m_end;
            if(m_end)  {
                if(m_start == m_end)  {
                    m_start = m_end = 0;
                    return ret_val;
                }
                m_end = m_end->GetPrevious();
                m_end->SetNext(0);
                
                ret_val->SetPrevious(0);
            }
            return ret_val;
        }

        void PushBack(DeletedNode* node)
        {
            if(!node)
                return;
            if(!m_start)  {
                m_start = m_end = node;
                return;
            }
            m_end->SetNext(node);
            node->SetPrevious(m_end);
            m_end = node;
        }

        DeletedNode* GetFirst()
        {
            return m_start;
        }

    private:
        DeletedNode*    m_start;
        DeletedNode*    m_end;
};

#endif


