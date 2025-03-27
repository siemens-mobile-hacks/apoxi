/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON Software GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Atl_Gui_Indicator_hpp)
#define Atl_Gui_Indicator_hpp

#include <Kernel/Types.hpp>
#include <Gui/PaintDc.hpp>
#include <Auxiliary/ObservableObject.hpp>
#include <Auxiliary/WString.hpp>
#include <Atl/Gui/IndicatorID.hpp>
#include <Atl/Gui/IndicatorBarID.hpp>
#include <Atl/Gui/IndicatorDescription.hpp>



class Indicator : public ObservableObject {
    public:
        

        
        enum IndicatorAlignment {
            Left = 0,   // order must not be changed
            Center = 1,
            Right = 2
        };
        typedef INT IndicatorPosition;

        Indicator(IndicatorPosition pos, IndicatorAlignment align);

        void SetAlignment(IndicatorAlignment align);

        IndicatorAlignment GetAlignment() const { return m_data.align; }

        void SetPosition(IndicatorPosition pos);

        IndicatorPosition GetPosition() const   { return m_pos; }




        Indicator(); 

        void Init(const IndicatorID& indicatorId, const IndicatorDescription* desc = 0);

        void SetIndicatorDescription(const IndicatorDescription *desc);

        const IndicatorDescription *GetIndicatorDescription() const { return m_description; }

        virtual ~Indicator();

        virtual Size GetSize() const = 0;

        void SetVisible(BOOLEAN flag);


        virtual BOOLEAN IsVisible() const { return m_data.visible; }

        virtual void Draw(DeviceContext* dc, Point pos, Rect draw_rect) = 0;
        
        const IndicatorID &GetId() const { return m_indicator_id; };

    private:

        struct {
            UINT    visible : 2;
            IndicatorAlignment  align : 3;  //OBSOLETE SINCE 1.21

        } m_data;
        
        IndicatorID             m_indicator_id;
        const IndicatorDescription* m_description;
        
        IndicatorPosition   m_pos;
};

class IconIndicator : public Indicator {
    typedef Indicator Base;

    public:
        
        IconIndicator(const BitmapRes* icon = 0, IndicatorPosition pos = 0, IndicatorAlignment align = Center);
    
//      IconIndicator(const BitmapRes* icon); HAS TO BE REACTIVATED
        virtual ~IconIndicator();

        virtual Size GetSize() const;       

        void SetIcon (const BitmapRes* icon) { m_icon = icon; }
        const BitmapRes* GetIcon() const { return m_icon; }
        
        virtual void Draw(DeviceContext* dc, Point pos, Rect draw_rect);

    private:
        const BitmapRes* m_icon;
};

class TextIndicator : public Indicator {
    typedef Indicator Base;

    public:
        TextIndicator(){m_text = L"";};
        TextIndicator(const WString& text);
        virtual ~TextIndicator();

        virtual Size GetSize() const;       

        void SetText (const WString& text);
        const WString& GetText() const { return m_text; }

        virtual void Draw(DeviceContext* dc, Point pos, Rect draw_rect);

    private:
        WString m_text;

};

class CenteredTextIndicator : public TextIndicator {
    typedef TextIndicator Base;

    public:
        CenteredTextIndicator() {};
        CenteredTextIndicator(const WString& text);
        virtual ~CenteredTextIndicator();

        virtual Size GetSize() const;       
};


class IconTextIndicator : public Indicator {
    typedef Indicator Base;

    public:

        IconTextIndicator(){m_ind_text = L""; m_icon = 0;};
        IconTextIndicator(const WString& text, const BitmapRes* icon = 0);
        virtual ~IconTextIndicator();

        void SetText (const WString& text) { m_ind_text = text; }

        // Returns the size of the indicator.
        virtual Size GetSize() const;       

        const WString& GetText() const { return m_ind_text; }

        void SetIcon (const BitmapRes* icon) { m_icon = icon; }

        const BitmapRes* GetIcon() const { return m_icon; }

        virtual void Draw(DeviceContext* dc, Point pos, Rect draw_rect);

    private:
        WString m_ind_text;
        const BitmapRes* m_icon;

};

class ValueIndicator : public Indicator {
    typedef Indicator Base;

    public:

        ValueIndicator(IndicatorPosition pos, IndicatorAlignment align);
        
        ValueIndicator();
        virtual ~ValueIndicator();

        INT GetMaximumValue() const { return m_max; }
        INT GetMinimumValue() const { return m_min; }
        INT GetValue() const { return m_value; }
        virtual INT GetStep() const;
        void SetRange(INT min, INT max);
        void SetValue(INT value);

    private:
        INT m_value;
        INT m_min;
        INT m_max;  
};

struct IconValueIndicator : public ValueIndicator {
    typedef ValueIndicator Base;
    typedef const BitmapRes* BitmapResArray;
    
    public:
        
        IconValueIndicator(const BitmapResArray* icons = 0, UINT8 icon_count = 0, IndicatorPosition pos = 0, IndicatorAlignment align = Left);

        
//      IconValueIndicator(const BitmapResArray* icons = 0, UINT8 icon_count = 0); HAS TO BE REACTIVATED
        virtual ~IconValueIndicator();

        virtual Size GetSize() const;

        virtual INT GetStep() const;
        
        virtual const BitmapRes* GetIcon() const;

        void SetIcons(const BitmapResArray* icons, UINT8 icon_count);

        virtual void Draw(DeviceContext* dc, Point pos, Rect draw_rect);

    private:
        UINT8 m_icon_count;
        const BitmapResArray* m_icons;
};

#endif  // Atl_Gui_Indicator_hpp


