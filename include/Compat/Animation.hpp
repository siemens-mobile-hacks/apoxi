/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_Animation_hpp)
#define Apoxi_Animation_hpp

#include <Gui/Lib.hpp>
#include <Kernel/Timer.hpp>

class AnimationBmpIterator {
    public:
        virtual INT BitmapCount() const = 0;
        virtual const BitmapRes* operator()(INT idx) const = 0;
};

class AnimationBmpArrayIterator : public AnimationBmpIterator {
    public:
        AnimationBmpArrayIterator(INT bmp_count = 0, const BitmapRes *bmp = 0);

        virtual INT BitmapCount() const { return m_bmp_count; }
        virtual const BitmapRes* operator()(INT idx) const {
            ASSERT(idx >= 0 && idx < m_bmp_count);
            return &m_bmp[idx];
        }

        void Init(INT bmp_count, const BitmapRes *bmp) {
            m_bmp_count = bmp_count;
            m_bmp = bmp;
        }

    private:
        INT m_bmp_count;
        const BitmapRes *m_bmp;
};


class AnimationBmpPointerArrayIterator : public AnimationBmpIterator {
    public:
        typedef const BitmapRes* CBitmapResPtr;

        AnimationBmpPointerArrayIterator(INT bmp_count = 0, const CBitmapResPtr *bmp = 0);

        virtual INT BitmapCount() const { return m_bmp_count; }
        virtual const BitmapRes* operator()(INT idx) const {
            ASSERT(idx >= 0 && idx < m_bmp_count);
            return m_bmp[idx];
        }

        void Init(INT bmp_count, const CBitmapResPtr *bmp) {
            m_bmp_count = bmp_count;
            m_bmp = bmp;
        }

    private:
        INT m_bmp_count;
        const CBitmapResPtr *m_bmp;
};

class AnimationModel : public Model {
    typedef Model Base;

    public:
        AnimationModel();

        void SetIndex(INT index) { m_index = index; };

        INT GetIndex() const { return m_index; };

        void SetBmpIterator(const AnimationBmpIterator *bmp_it) { m_bmp_it = bmp_it; }

        const AnimationBmpIterator* GetBmpIterator() const { return m_bmp_it; }

        const BitmapRes& GetActiveBitmap() const { return *m_bmp_it->operator()(m_index); }

    private:
        INT             m_index;
        const AnimationBmpIterator *m_bmp_it;
};

class AnimationView : public DrawableObjectView {
    public:
        typedef DrawableObjectView Base;

        virtual ~AnimationView();
        
        virtual void Draw(const Component &component, DeviceContext *dc, const Rect &repaint_rect) const;
};

class Animation : public DrawableObject, private Timer {
    public:
        typedef DrawableObject Base;

        enum AnimationType {
            Cycle,
            Oscillate,
            Once
        };
        
        Animation();

        Animation(Control *control,
                  const AnimationBmpIterator *bmp_it,
                  UINT32 timeout = 0,
                  AnimationType type = Cycle);

        virtual ~Animation();

        void Init(Control *control,
                  const AnimationBmpIterator *bmp_it,
                  UINT32 timeout = 0,
                  AnimationType type = Cycle);

        void Start();

        using Timer::Stop;

        void SetIndex(INT index);

        INT GetIndex() const;

        void SetBmpIterator(const AnimationBmpIterator *bmp_it);

        const AnimationBmpIterator* GetBmpIterator() const;
        
        virtual XYDIM GetDefaultWidth() const;

        virtual XYDIM GetDefaultHeight() const;

    protected:
        virtual Model* CreateModel() const;

        virtual void OnTimer();

        virtual void OnThemeChanged();

    private:
        struct {
            UINT cycle_forward  : 1;
            UINT type           : 2;
        } m_bits;

        static AnimationView m_view;

        AnimationModel* GetMyModel() const { return (AnimationModel *)GetModel(); }
        virtual void AdjustThemeDependencies();
};


#endif  // Apoxi_Animation_hpp


