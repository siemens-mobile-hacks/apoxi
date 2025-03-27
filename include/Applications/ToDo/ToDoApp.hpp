/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */
#if !defined(ToDoApp_hpp)
#define ToDoApp_hpp

#include <Common/MmiApplication.hpp>
#include "ToDoListWin.hpp"
#include "ToDoProvider.hpp"
#include "ToDoDialogWin.hpp"
#include "ToDoComposeWin.hpp"


/*  ========================================================================
    App
    ======================================================================== */
class ToDoApp : public MmiApplication 
{
    typedef MmiApplication Base;

    public:
        virtual ~ToDoApp(); 

        static ToDoApp* GetInstance();  
    

    protected:
        virtual void OnStartup();

        virtual void OnOpen();
        
        virtual BOOLEAN OnFeatureTriggered (const FeatureID& feature_id);
        
        virtual BOOLEAN OnMessage(const Message &msg);

    private:
        ToDoApp();

        void InsertToDoItem();

        void SetToDoOptionMenuFeature (BOOLEAN flag);

        void OpenToDoMainWindow();

        void SaveToDoItem();

        void MarkUnmarkToDoItem();

        void ViewToDoItem();

        void EditToDoItem();

        void OpenToDoInsertItemWins();

        void SaveToDoItemPriority();

        void DeleteToDoItem();

        void DeleteAllToDoItems();
        

        enum FeatureItemIds {           
            ToDo,
            ToDoView,
            ToDoNew,
            ToDoEdit,
            ToDoDelete,
            ToDoDeleteAll,
            ToDoMarkUnmark,
            ToDoPriority,
            ToDoStore,
            ToDoPredInput,
            ToDoT9Disabled,
            ToDoT9English,
            ToDoT9SimpChinese,
            ToDoT9TradChinese,
            ToDoT9Pinyin,
            ToDoT9BoPoMoFo,
            ToDoFeatureCnt
        };
                
        Feature                     m_items[ToDoFeatureCnt];
        static ToDoApp              m_instance;
        ToDoListWin                 m_todo_list_window;
        ToDoProvider                m_todo_provider;
        ToDoRecord                  m_tmp_record;
        ToDoDateDialogWin           m_todo_date_dialog_win;
        ToDoPriorityDialogWin       m_todo_priority_dialog_win;
        ToDoComposeWin              m_editor_win;
        BOOLEAN                     m_is_a_new_todo_item;
        INT                         m_selected_idx; 
};      

#endif  // ToDoPlugin_hpp


