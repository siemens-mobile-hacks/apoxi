/*
*******************************************************************************
                       Copyright eMuzed Inc., 2001-2004.
All rights Reserved, Licensed Software Confidential and Proprietary Information
    of eMuzed Incorporation Made available under Non-Disclosure Agreement OR
                            License as applicable.
*******************************************************************************
*/

/*
*******************************************************************************
Product     : MMFr and MM Apps on APOXI
Module      : MMFr
File        : MediaBox.hpp
Description : 

Revision Record:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Date            Id          Author          Comment 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
31st August 2004        Naveen Narayanan    Added private members
------------------------------------------------------------------------ */


#ifndef MediaBox_hpp
#define MediaBox_hpp

class MediaInfo;
class MediaPlayer;
class MediaManager;

#include <Auxiliary/MimeTypeTable.hpp>
#include <Gui/DrawableObject.hpp> 

class BinData;

class MediaBoxView : public DrawableObjectView {
    public:
        MediaBoxView();
        virtual ~MediaBoxView();
        virtual void Draw(const Component& component, DeviceContext* dc,
            const Rect& repaint_rect) const;
};

class MediaBox : public DrawableObject {
    
    typedef DrawableObject Base;
    public:
        MediaBox();
        virtual void Init(Control* parent);
        virtual ~MediaBox();
        MediaPlayer* CreatePlayerInstance(BinData* media_source,
                                            MediaInfo& media_info,
                                            MimeType& media_mime_type,
                                            void *mesg_dispatcher,
                                            MediaManager::MmfResult& mmf_result);

        MediaPlayer* CreatePlayerInstance(char* media_source,
                                            MediaInfo& media_info,
                                            MimeType& media_mime_type,
                                            void *mesg_dispatcher,
                                            MediaManager::MmfResult& mmf_result);
                                        
        void DestroyPlayerInstance(MediaPlayer* media_player);
        MediaPlayer* GetPlayerInstance();
    private:
        static MediaBoxView m_view;
        MediaPlayer*    m_p_media_player;
};

#endif //MediaBox_hpp

