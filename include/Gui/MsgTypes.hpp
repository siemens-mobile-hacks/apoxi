/*  ------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    --------------------------------------------------------
    ========================================================
    This file was generated with ApoxiMessageGenerator as
    defined in "apoxi\development\msg\MsgTypes.xml"
    DO NOT CHANGE IT MANUALLY!
    --------------------------------------------------------------*/
#if !defined(MsgTypes_hpp__ST_1092996111155)
#define MsgTypes_hpp__ST_1092996111155
#include <Kernel/MsgTypes.hpp>
#include <Auxiliary/WString.hpp>
#include <Gui/Rect.hpp>

class ContextMenu;
class Component;
class AbstractMenuAccessor;
class Image;
class Dispatcher;
class Menu;
class Window;
class BinData;
class ImageEncoder;
class AbstractGrid;

/* ----------------------------------------------------------------------
    Classes
    ---------------------------------------------------------------------- */
/*  ======================================================================
    Class FocusNextControlMsg
    ====================================================================== */
class FocusNextControlMsg : public ControlMsg {
    public:
        FocusNextControlMsg(Control* control);
        virtual ~FocusNextControlMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 1100
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };
/*  ======================================================================
    Class FocusPreviousControlMsg
    ====================================================================== */
class FocusPreviousControlMsg : public ControlMsg {
    public:
        FocusPreviousControlMsg(Control* control);
        virtual ~FocusPreviousControlMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 1101
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };
/*  ======================================================================
    Class SelectionChangedMsg
    ====================================================================== */
class SelectionChangedMsg : public ControlMsg {
    public:
        SelectionChangedMsg(Control* control, INT index, AbstractGrid* sender = 0);
        virtual ~SelectionChangedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        INT GetIndex() const { return m_index; }
        const AbstractGrid* GetSender() const { return m_sender; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 1102
            };
        
    private:
        static const MsgMetaData m_meta_data;
        INT m_index;
        AbstractGrid* m_sender;
        
    };
#ifdef APOXI_COMPAT_1_9_0
/*  ======================================================================
    Class ConfirmMsg
    ====================================================================== */
class ConfirmMsg : public Message {
    public:
        ConfirmMsg();
        virtual ~ConfirmMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 1011
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };
#endif //APOXI_COMPAT_1_9_0
#ifdef APOXI_COMPAT_1_9_0
/*  ======================================================================
    Class CancelMsg
    ====================================================================== */
class CancelMsg : public Message {
    public:
        CancelMsg();
        virtual ~CancelMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 1012
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };
#endif //APOXI_COMPAT_1_9_0
#ifdef APOXI_COMPAT_1_9_0
/*  ======================================================================
    Class SoftkeyPressedMsg
    ====================================================================== */
class SoftkeyPressedMsg : public Message {
    public:
        SoftkeyPressedMsg(INT index);
        virtual ~SoftkeyPressedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetIndex(INT index) { m_index = index; }
        INT GetIndex() const { return m_index; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 1013
            };
        
    private:
        static const MsgMetaData m_meta_data;
        INT m_index;
        
    };
#endif //APOXI_COMPAT_1_9_0
#ifdef APOXI_COMPAT_1_9_0
/*  ======================================================================
    Class SoftkeyReleasedMsg
    ====================================================================== */
class SoftkeyReleasedMsg : public Message {
    public:
        SoftkeyReleasedMsg(INT index);
        virtual ~SoftkeyReleasedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetIndex(INT index) { m_index = index; }
        INT GetIndex() const { return m_index; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 1014
            };
        
    private:
        static const MsgMetaData m_meta_data;
        INT m_index;
        
    };
#endif //APOXI_COMPAT_1_9_0
#ifdef APOXI_COMPAT_1_9_0
/*  ======================================================================
    Class MenuTriggeredMsg
    ====================================================================== */
class MenuTriggeredMsg : public Message {
    public:
        MenuTriggeredMsg(AbstractMenuAccessor* menu_accessor, INT index);
        virtual ~MenuTriggeredMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetMenuAccessor(AbstractMenuAccessor* menu_accessor) { m_menu_accessor = menu_accessor; }
        AbstractMenuAccessor* GetMenuAccessor() const { return m_menu_accessor; }
        void SetIndex(INT index) { m_index = index; }
        INT GetIndex() const { return m_index; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 1115
            };
        
    private:
        static const MsgMetaData m_meta_data;
        AbstractMenuAccessor* m_menu_accessor;
        INT m_index;
        
    };
#endif //APOXI_COMPAT_1_9_0
#ifdef APOXI_COMPAT_1_9_0
/*  ======================================================================
    Class MenuBackMsg
    ====================================================================== */
class MenuBackMsg : public Message {
    public:
        MenuBackMsg(AbstractMenuAccessor* menu_accessor);
        virtual ~MenuBackMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetMenuAccessor(AbstractMenuAccessor* menu_accessor) { m_menu_accessor = menu_accessor; }
        AbstractMenuAccessor* GetMenuAccessor() const { return m_menu_accessor; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 1116
            };
        
    private:
        static const MsgMetaData m_meta_data;
        AbstractMenuAccessor* m_menu_accessor;
        
    };
#endif //APOXI_COMPAT_1_9_0
#ifdef APOXI_COMPAT_1_9_0
/*  ======================================================================
    Class IdleModeStateChangedMsg
    ====================================================================== */
class IdleModeStateChangedMsg : public Message {
    public:
        IdleModeStateChangedMsg(BOOLEAN idle);
        virtual ~IdleModeStateChangedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetIdle(BOOLEAN idle) { m_idle = idle; }
        BOOLEAN IsIdle() const { return m_idle; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 1117
            };
        
    private:
        static const MsgMetaData m_meta_data;
        BOOLEAN m_idle;
        
    };
#endif //APOXI_COMPAT_1_9_0
/*  ======================================================================
    Class InvalidateMsg
    ====================================================================== */
class InvalidateMsg : public Message {
    public:
        InvalidateMsg(Component* component, Dispatcher* dispatcher, const Rect& rect);
        virtual ~InvalidateMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        Component* GetComponent() const { return m_component; }
        Dispatcher* GetDispatcher() const { return m_dispatcher; }
        const Rect& GetRect() const { return m_rect; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 1118
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Component* m_component;
        Dispatcher* m_dispatcher;
        Rect m_rect;
        
    };
#ifdef APOXI_COMPAT_1_9_0
/*  ======================================================================
    Class MenuAccessorChangedMsg
    ====================================================================== */
class MenuAccessorChangedMsg : public Message {
    public:
        MenuAccessorChangedMsg(Menu* menu, AbstractMenuAccessor* menu_accessor);
        virtual ~MenuAccessorChangedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        Menu* GetMenu() const { return m_menu; }
        AbstractMenuAccessor* GetMenuAccessor() const { return m_menu_accessor; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 1119
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Menu* m_menu;
        AbstractMenuAccessor* m_menu_accessor;
        
    };
#endif //APOXI_COMPAT_1_9_0
/*  ======================================================================
    Class ImageDecodingProgressMsg
    ====================================================================== */
class ImageDecodingProgressMsg : public Message {
    public:
        ImageDecodingProgressMsg(const Image* image, INT progress);
        virtual ~ImageDecodingProgressMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        const Image* GetImage() const { return m_image; }
        INT GetProgress() const { return m_progress; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 1120
            };
        
    private:
        static const MsgMetaData m_meta_data;
        const Image* m_image;
        INT m_progress;
        
    };
/*  ======================================================================
    Class ViewfinderErrorMsg
    ====================================================================== */
class ViewfinderErrorMsg : public Message {
    public:
        ViewfinderErrorMsg();
        virtual ~ViewfinderErrorMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 1121
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };
/*  ======================================================================
    Class ContextMenuClosedMsg
    ====================================================================== */
class ContextMenuClosedMsg : public Message {
    public:
        ContextMenuClosedMsg(ContextMenu* context_menu);
        virtual ~ContextMenuClosedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        ContextMenu* GetContextMenu() const { return m_context_menu; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 1122
            };
        
    private:
        static const MsgMetaData m_meta_data;
        ContextMenu* m_context_menu;
        
    };
/*  ======================================================================
    Class RefreshComponentMsg
    ====================================================================== */
class RefreshComponentMsg : public Message {
    public:
        RefreshComponentMsg(Component* component);
        virtual ~RefreshComponentMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        Component* GetComponent() const { return m_component; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 1123
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Component* m_component;
        
    };
/*  ======================================================================
    Class CloseWindowMsg
    ====================================================================== */
class CloseWindowMsg : public Message {
    public:
        CloseWindowMsg(Window* window, INT exit_code = 0);
        virtual ~CloseWindowMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        Window* GetWindow() const { return m_window; }
        INT GetExitCode() const { return m_exit_code; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 1124
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Window* m_window;
        INT m_exit_code;
        
    };
/*  ======================================================================
    Class AragonMsg
    ====================================================================== */
class AragonMsg : public Message {
    public:
        AragonMsg(UINT32 command, BinData* data);
        virtual ~AragonMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        UINT32 GetCommand() const { return m_command; }
        BinData* GetData() const { return m_data; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 1125
            };
        
    private:
        static const MsgMetaData m_meta_data;
        UINT32 m_command;
        BinData* m_data;
        
    };
/*  ======================================================================
    Class T9NoWordFoundMsg
    ====================================================================== */
class T9NoWordFoundMsg : public Message {
    public:
        T9NoWordFoundMsg(const WString& active_word);
        virtual ~T9NoWordFoundMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetActiveWord(const WString& active_word) { m_active_word = active_word; }
        const WString& GetActiveWord() const { return m_active_word; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 30101
            };
        
    private:
        static const MsgMetaData m_meta_data;
        WString m_active_word;
        
    };
/*  ======================================================================
    Class T9AddWordMsg
    ====================================================================== */
class T9AddWordMsg : public Message {
    public:
        T9AddWordMsg(const WString& new_word);
        virtual ~T9AddWordMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetNewWord(const WString& new_word) { m_new_word = new_word; }
        const WString& GetNewWord() const { return m_new_word; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 30102
            };
        
    private:
        static const MsgMetaData m_meta_data;
        WString m_new_word;
        
    };
/*  ======================================================================
    Class T9EnteredUnknownWordMsg
    ====================================================================== */
class T9EnteredUnknownWordMsg : public Message {
    public:
        T9EnteredUnknownWordMsg(const WString& word);
        virtual ~T9EnteredUnknownWordMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetWord(const WString& word) { m_word = word; }
        const WString& GetWord() const { return m_word; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 30103
            };
        
    private:
        static const MsgMetaData m_meta_data;
        WString m_word;
        
    };
/*  ======================================================================
    Class T9SymbolEntryRequestMsg
    ====================================================================== */
class T9SymbolEntryRequestMsg : public Message {
    public:
        T9SymbolEntryRequestMsg();
        virtual ~T9SymbolEntryRequestMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 30110
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };
/*  ======================================================================
    Class T9MatrixModeKeypressed
    ====================================================================== */
    class T9MatrixModeKeypressed : public Message {
    public:
        T9MatrixModeKeypressed(const KeyCode& key_code);
        virtual ~T9MatrixModeKeypressed();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetKeyCode(const KeyCode& key_code) { m_key_code = key_code; }
        const KeyCode& GetKeyCode() const { return m_key_code; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 30120
            };
        
    private:
        static const MsgMetaData m_meta_data;
        KeyCode m_key_code;
        
    };
/*  ======================================================================
    Class Zi8NoWordFoundMsg
    ====================================================================== */
class Zi8NoWordFoundMsg : public Message {
    public:
        Zi8NoWordFoundMsg(const WString& active_word);
        virtual ~Zi8NoWordFoundMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetActiveWord(const WString& active_word) { m_active_word = active_word; }
        const WString& GetActiveWord() const { return m_active_word; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 30201
            };
        
    private:
        static const MsgMetaData m_meta_data;
        WString m_active_word;
        
    };
/*  ======================================================================
    Class Zi8AddWordMsg
    ====================================================================== */
class Zi8AddWordMsg : public Message {
    public:
        Zi8AddWordMsg(const WString& new_word);
        virtual ~Zi8AddWordMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetNewWord(const WString& new_word) { m_new_word = new_word; }
        const WString& GetNewWord() const { return m_new_word; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 30202
            };
        
    private:
        static const MsgMetaData m_meta_data;
        WString m_new_word;
        
    };
/*  ======================================================================
    Class Zi8EnteredUnknownWordMsg
    ====================================================================== */
class Zi8EnteredUnknownWordMsg : public Message {
    public:
        Zi8EnteredUnknownWordMsg(const WString& word);
        virtual ~Zi8EnteredUnknownWordMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        void SetWord(const WString& word) { m_word = word; }
        const WString& GetWord() const { return m_word; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 30203
            };
        
    private:
        static const MsgMetaData m_meta_data;
        WString m_word;
        
    };
/*  ======================================================================
    Class ImageDrawingInterruptedMsg
    ====================================================================== */
class ImageDrawingInterruptedMsg : public ContextMsg {
    public:
        ImageDrawingInterruptedMsg(ExecutionContext* context, Image* image);
        virtual ~ImageDrawingInterruptedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        Image* GetImage() const { return m_image; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 1126
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Image* m_image;
        
    };
/*  ======================================================================
    Class DeleteComponentMsg
    ====================================================================== */
class DeleteComponentMsg : public ContextMsg {
    public:
        DeleteComponentMsg(ExecutionContext* context, Component* component);
        virtual ~DeleteComponentMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        Component* GetComponent() const { return m_component; }
        virtual Message* Clone() const;
        
        enum  {
            ID = 1127
            };
        
    private:
        static const MsgMetaData m_meta_data;
        Component* m_component;
        
    };
/*  ======================================================================
    Class ImageEncodingProgressMsg
    ====================================================================== */
class ImageEncodingProgressMsg : public Message {
public:
    ImageEncodingProgressMsg(const ImageEncoder& encoder, INT progress);
    virtual ~ImageEncodingProgressMsg();

    virtual const MsgMetaData& GetMetaData() const;
    const ImageEncoder& GetEncoder() const { return m_encoder; }
    INT GetProgress() const { return m_progress; }
    virtual Message* Clone() const;

    enum  {
        ID = 1128
    };

private:
    static const MsgMetaData m_meta_data;
    const ImageEncoder& m_encoder;
    INT m_progress;

};

/*  ======================================================================
    Class ItemRendererPropertiesChangedMsg
    ====================================================================== */

class ItemRendererPropertiesChangedMsg : public Message {
    public:
        ItemRendererPropertiesChangedMsg();
        virtual ~ItemRendererPropertiesChangedMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        
        enum  {
            ID = 1129
            };
        
    private:
        static const MsgMetaData m_meta_data;
        
    };

/*  ======================================================================
    Class RedrawDisplayMsg
    ====================================================================== */

class RedrawDisplayMsg : public Message {
    public:
        RedrawDisplayMsg(INT index);
        virtual ~RedrawDisplayMsg();
        
        virtual const MsgMetaData& GetMetaData() const;
        virtual Message* Clone() const;
        INT GetIndex() const { return m_index; }
        
        enum  {
            ID = 1130
            };
        
    private:
        static const MsgMetaData m_meta_data;
        INT m_index;        
    };

#endif // MsgTypes_hpp__ST_1092996111155


