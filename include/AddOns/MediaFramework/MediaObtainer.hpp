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
File        : MediaObtainer.hpp
Description : 

Revision Record:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Date            Id          Author          Comment 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
28th October, 2004          Shyam Sanker P S    Initial Code
*******************************************************************************
*/

#if !defined(Apoxi_MediaObtainer_hpp)
#define Apoxi_MediaObtainer_hpp

#include <Gui/Size.hpp>
#include <Auxiliary/BinData.hpp>

#include "Media.hpp"



class MediaObtainer : public ObjectObtainer {

    typedef ObjectObtainer Base;

    public:

        MediaObtainer(Media* media);

        virtual ~MediaObtainer();

        //Init(Media* media);

        virtual Media* GetMedia() const;

//      virtual const Media* GetMedia() const;

    private :

};//class MediaObtainer

#endif //Apoxi_MediaObtainer_hpp

