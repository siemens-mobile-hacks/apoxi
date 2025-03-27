/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH&  Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_WindowManager_hpp)
#define Apoxi_WindowManager_hpp

#include <Kernel/Types.hpp>
#include <Auxiliary/Vector.hpp>

class Window;
class Application;

class WindowHierarchyIterator {
    public:
        WindowHierarchyIterator(const Window* win = 0);
        ~WindowHierarchyIterator();

        BOOLEAN Begin(const Window* win = 0);

        WindowHierarchyIterator& operator++();

        WindowHierarchyIterator operator++(INT);

        WindowHierarchyIterator& operator--();

        WindowHierarchyIterator operator--(INT);

        Window* Get(Application** app = 0) const;

        BOOLEAN Next();

        BOOLEAN Previous();

        void Release() {}

    private:
        INT m_pos;
};

class WindowManager {
    public:
        static Window* GetForegroundWindow() { return m_foreground_win; }

        static Window* GetDisplayForegrWin(INT display_idx);

        static void Insert(Window* win, Window* foregr_win = 0);

        static void Remove(Window* win);

        static void SetAlphaMaskEnabled(BOOLEAN flag);

        static BOOLEAN IsAlphaMaskEnabled();

    private:
        struct Node {
            Window* win;
            Application* app;
        };

        // m_foreground_win: redundant member to allow a fast access to the foreground-window
        // (the method WindowManager::GetForegroundWindow is invoked for each method of the device-context)
        static Window* m_foreground_win;
        // m_nodes: contains all opened windows of all applications
        static Vector<Node> m_nodes;

        static BOOLEAN m_initialized;
        static Mutex m_mutex;
        static INT m_alpha_mask_counter;

        WindowManager();
        static void InternalInsert(Window* win, Window* foregr_win = 0);
        static void InternalRemove(Window* win);
        static INT GetWindowIndex(const Window* win);
        static BOOLEAN Contains(const Window* win);
        static BOOLEAN InitMutex();
        
        friend class WindowHierarchyIterator;
};

#endif  // Apoxi_WindowManager_hpp


