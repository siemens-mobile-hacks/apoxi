/*  ------------------------------------------------------------------------
    Copyright (C) 2001 COMNEON Software GmbH & Co. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(Mmi_ToDoRecord_hpp)
#define Mmi_ToDoRecord_hpp

#include <AddOns/AdcExtensions/Record.hpp>
#include <Auxiliary/Date.hpp>


const INT c_note_max_length = 160;
const Date c_invalid_date(99, 99, 9999);

class ToDoRecord : public Record {
    typedef Record Base;
    public:         
        enum ToDoRecMarkLevel{
              unmarked = 0,
              marked = 1
        };

        enum ToDoRecProrityLevel{
               Low = 0,
               Medium = 1,
               High = 2,
               PriorityCount = 3
        };  

        enum Type {
            Deleted = 0,
            Used = 1
            };

                
        ToDoRecord (Type type = Deleted,
                         ToDoRecProrityLevel priorityLevel = Low, 
                         Date toDoListDateTime = Date::Today,
                         ToDoRecMarkLevel markLevel = unmarked,
                             WString note = L"\0");
        

        virtual const UINT8* GetData();
        
        virtual void SetData(const UINT8* data);

        virtual INT GetPersistentSize();

        void SetType(Type type) { m_data.type = type; }     

        Type GetType() const { return (Type)m_data.type; }

        BOOLEAN IsRecordDeleted();

        void MarkDeleted();

        
        struct Persist {
            Type type;
            ToDoRecProrityLevel priorityLevel;
            Date toDoListDateTime;
            ToDoRecMarkLevel markLevel;
            WCHAR note[c_note_max_length + 1];
        } m_data;
        
};
#endif  // Mmi_ToDoListRecord_hpp
