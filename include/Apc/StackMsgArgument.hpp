/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Apc_StackMsgArgument_hpp)
#define Apc_StackMsgArgument_hpp

#include <Auxiliary/Macros.hpp>
#include <Auxiliary/BinarySearch.hpp>
#include <Kernel/Os/Os.hpp>

/*  ========================================================================
    StackMsgArgId
    ======================================================================== */
typedef INT StackMsgArgId;

class StackMsgArgument;
/*  ========================================================================
    StackMsgArgMap
    ======================================================================== */
template<class T> struct StackMsgArgMap {
    StackMsgArgId arg_id;
    BOOLEAN (T::*OnArg)(const StackMsgArgument &arg);
};

/*  ========================================================================
    ArgumentDestroyEntry
    ======================================================================== */
struct ArgumentDestroyEntry {
    StackMsgArgId id;
    void (*destroy_func)(StackMsgArgument *arg);
};

/*  ========================================================================
    ArgumentDestroyEntryCompare (for binary search)
    ======================================================================== */
struct ArgumentDestroyEntryCompare {
    public:
        inline INT Compare(StackMsgArgId id, const ArgumentDestroyEntry &entry) const { 
            return id < entry.id ? -1 : (id == entry.id ? 0 : 1); }
};

/*  ========================================================================
    StackMsgArgDestroyTableNode
    ======================================================================== */
class StackMsgArgDestroyTableNode {
    friend class StackMsgArgument;
    public:
        StackMsgArgDestroyTableNode(const ArgumentDestroyEntry * destroy_table, INT16 table_length);
        void DestroySelf();
        BOOLEAN Destroy(StackMsgArgument *arg);

    protected:
        virtual void Dummy() {}

    private:
        void SetNext(StackMsgArgDestroyTableNode *node);
        BOOLEAN DestroyArg(StackMsgArgument *arg);

        static ArgumentDestroyEntryCompare m_compare;
        const CArray<ArgumentDestroyEntry> m_destroy_table;

        StackMsgArgDestroyTableNode *m_next;
};

/*  ========================================================================
    StackMsgArgument
    ======================================================================== */
class StackMsgArgument {
    friend class FromStackMsg;
    friend class ToStackMsg;
    friend class StackMsgArgDestroyTableNode;
    friend class SsStackMsgArgument;

    public:

        StackMsgArgument(StackMsgArgId id = 0);

        StackMsgArgId Id() const { return (m_id); }

    private:
        INT m_ref_count;
        StackMsgArgId m_id;
        static StackMsgArgDestroyTableNode *m_anchor;

        void AddRef(INT n = 1);

        static void Attach(StackMsgArgDestroyTableNode *node);
};

/*  ========================================================================
    NoStackMsgArg
    ======================================================================== */
class NoStackMsgArg : public StackMsgArgument {
    friend class StackMsgArgument;
    public:
        NoStackMsgArg();
        ~NoStackMsgArg();

        enum { ID = 0 }; 

    private:
        static void Destroy(StackMsgArgument *arg) { delete ((NoStackMsgArg *) arg); }
};



/*  ========================================================================
    AbstractStackMsgArgMapContainer
    ======================================================================== */
class AbstractStackMsgArgMapContainer {
    public:
        virtual BOOLEAN Execute(const StackMsgArgument &arg) const = 0;
};

/*  ========================================================================
    StackMsgArgMapContainer
    ======================================================================== */
template<class T> class StackMsgArgMapContainer : public AbstractStackMsgArgMapContainer {
    public:
        StackMsgArgMapContainer(T *dispatcher = 0, const StackMsgArgMap<T> *arg_map = 0) :  
          m_dispatcher(dispatcher), m_arg_map(arg_map) { }

        virtual void Init(T *dispatcher, const StackMsgArgMap<T> *arg_map) {
            m_dispatcher = dispatcher;
            m_arg_map = arg_map;
        } // Init
        
        virtual BOOLEAN Execute(const StackMsgArgument &arg) const {
//          ASSERT_INFO(m_dispatcher != 0 && m_arg_map != 0, L"StackMsgArgMapContainer not initialized!\n");
            ASSERT_ALWAYS(m_dispatcher != 0 && m_arg_map != 0); 
            StackMsgArgMap<T>* entry = (StackMsgArgMap<T>*)m_arg_map;
            while (entry->arg_id != NoStackMsgArg::ID) {
                ASSERT_ALWAYS(entry->OnArg != 0);
                if (entry->arg_id == arg.Id()) {
                    return ((m_dispatcher->*(entry->OnArg))(arg));
                } // if
                entry++;
            } // while
            return (FALSE);
        }   // Execute

    
    private:
        T *m_dispatcher;
        const StackMsgArgMap<T>* m_arg_map;
};


#endif // Apc_StackMsgArgument_hpp


