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
File        : Media.hpp
Description : 

Revision Record:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Date            Id          Author          Comment 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
28th October, 2004          Shyam Sanker P S    Initial Code
*******************************************************************************
*/

#if !defined(Apoxi_Media_hpp)
#define Apoxi_Media_hpp

#include <Auxiliary/ObjectObtainer.hpp>
#include <Auxiliary/MimeTypeTable.hpp>

class Size;
class BinData;


class Media : public ObtainableObject{

    typedef ObtainableObject Base;

    public:

        struct Parameters {
            Size resolution;
            UINT16 frame_rate_numerator;
            UINT16 frame_rate_denominator;
            /* Duration in milli seconds */
            UINT32 duration;
            MimeType mime_type;
        };

        Media(BinData *bin_data, MimeType mime_type);

        Media(BinData *bin_data, Parameters& params);

        virtual ~Media() {m_bin_data_pointer->ReleaseInstance();}

        virtual BinData* GetBinData();

    //  virtual const BinData* GetBinData() const;

        virtual Size GetResolution() ;

        virtual void GetFrameRate(  UINT16& frame_rate_numerator,
                                    UINT16& frame_rate_denominator) ;

        virtual UINT32 GetDuration() ;

        virtual MimeType GetMimeType() ;

    private :

        Size m_resolution;
        UINT16 m_frame_rate_numerator;
        UINT16 m_frame_rate_denominator;

        /* Duration in milli seconds */
        UINT32 m_duration;

        MimeType m_mime_type;

        BinData *m_bin_data_pointer;

        friend class MediaObtainer;
};//class media

#endif  // Apoxi_Media_hpp


