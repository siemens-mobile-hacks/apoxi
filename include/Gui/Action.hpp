/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Action_hpp)
#define Apoxi_Action_hpp

class ResourceParser;
class ActionExtension;

#include <Gui/Item.hpp>
#include <Kernel/Dispatcher.hpp>

class Action : public Item {
    typedef Item Base;
    
    public:
        enum {
            ID = 1
        };

        typedef void (Dispatcher::*ExecFn)();

        Action();

        Action(Dispatcher* dispatcher,
               const WCHAR* text,
               const BitmapRes* icon = 0,
               BOOLEAN enabled = TRUE);

        Action(Dispatcher* dispatcher,
               const WString& text,
               const BitmapRes* icon = 0,
               BOOLEAN enabled = TRUE);

        Action(Dispatcher* dispatcher,
               const WString& text,
               const ImageObtainer& icon,
               BOOLEAN enabled = TRUE);

        Action(Dispatcher* dispatcher,
               const WString& text,
               const IconSet& icon_set,
               BOOLEAN enabled = TRUE);

        Action(Dispatcher* dispatcher,
               const WString& text,
               ExecFn exec_fn);

        virtual ~Action();

        void Init(Dispatcher* dispatcher,
                  const WCHAR* text,
                  const BitmapRes* icon = 0,
                  BOOLEAN enabled = TRUE);

        void Init(Dispatcher* dispatcher,
                  const WString& text,
                  const BitmapRes* icon = 0,
                  BOOLEAN enabled = TRUE);

        void Init(Dispatcher* dispatcher,
                  const WString& text,
                  const ImageObtainer& icon,
                  BOOLEAN enabled = TRUE);

        void Init(Dispatcher* dispatcher,
                  const WString& text,
                  const IconSet& icon_set,
                  BOOLEAN enabled = TRUE);

        void Init(Dispatcher* dispatcher,
                  const WString& text,
                  ExecFn exec_fn);

        BOOLEAN SetProperty(ResourceParser& parser, const GuiObjectFactory::PropertyId prop_id, UINT16 object_id);

        virtual BOOLEAN Execute();

        virtual BOOLEAN IsInstanceOf(INT id) const;

        void SetExecFn(ExecFn exec_fn) { m_exec_fn = exec_fn; }

        ExecFn GetExecFn() const { return m_exec_fn; }

#ifdef APOXI_COMPAT_2_2_0

        Action(const WCHAR* text,
               const BitmapRes* icon = 0,
               BOOLEAN enabled = TRUE);

        void Init(const WCHAR* text,
                  const BitmapRes* icon = 0,
                  BOOLEAN enabled = TRUE);
        
        void SetBitmap(const BitmapRes* bitmap);

        const BitmapRes* GetBitmap() const;

        virtual const ActionExtension* GetExtension() const;
#endif // APOXI_COMPAT_2_2_0

    private:
        ExecFn m_exec_fn;
};

#endif  // Apoxi_Action_hpp


