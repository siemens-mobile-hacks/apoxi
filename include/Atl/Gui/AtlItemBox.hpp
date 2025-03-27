/*  ------------------------------------------------------------------------
Copyright (C) COMNEON Software GmbH&  Co. OHG. All rights reserved.
------------------------------------------------------------------------
This document contains proprietary information belonging to COMNEON.
Passing on and copying of this document, use and communication of its
contents is not permitted without prior written authorisation.
------------------------------------------------------------------------ */

#if !defined(Apoxi_AtlItemBox_hpp)
#define Apoxi_AtlItemBox_hpp

#include <Gui/ItemBox.hpp>
#include <Kernel/UserDispatcher.hpp>

#if defined(APOXI_COMPAT_2_7_0)
#include <Atl/Properties/Property.hpp>
#endif  // APOXI_COMPAT_2_7_0

class Item;
class Feature;
class AtlItemBox : public ItemBox {
    typedef ItemBox Base;

    class FeatureListener : public UserDispatcher {

        public: 
            FeatureListener();
            virtual ~FeatureListener();
            void Init(AtlItemBox* box);

        protected:

            virtual BOOLEAN OnMessage(const Message& msg);

        private:
            AtlItemBox* m_box;
    };

    public:
        enum {
            ID = 101
        };

        AtlItemBox();

        AtlItemBox(Control* control, Item* item);

        virtual ~AtlItemBox();

        void Init(Control* control, Item* item);

    protected:
        virtual BOOLEAN OnMessage(const Message& msg);

        virtual void OnFeatureChanged(Feature* changed_feature, INT property_id);

        virtual void Refresh(const Rect& rect = Rect());

    private:
        void AddToParent();
        void RemoveFromParent();

        void CheckAvailability(Feature* changed_feature);

        FeatureListener m_feature_listener;
        Control* m_box_parent;

    friend class FeatureListener;
};
#endif  // Apoxi_AtlItemBox_hpp

