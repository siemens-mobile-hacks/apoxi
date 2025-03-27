/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_NonCloneable_hpp)
#define Apoxi_NonCloneable_hpp


class NonCloneable {
    public:
        NonCloneable();

        //We need to add a virtual destructor,
        //otherwise the default destructor would be non-default,
        //and the derived-classes could not have any virtual methods.
        virtual ~NonCloneable();

    private:
        //Make this, and derived classes, non-copyable:
        NonCloneable(const NonCloneable &);
        NonCloneable& operator=(const NonCloneable &);
};


#endif  // Apoxi_NonCloneable_hpp


