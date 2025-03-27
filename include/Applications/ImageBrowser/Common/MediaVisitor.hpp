/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_MediaVisitor_hpp)
#define Apoxi_MediaVisitor_hpp

#include "MediaRef.hpp"
#include "Afs/Rfs/Path.hpp"
#include "Auxiliary/Vector.hpp"

class MediaVisitor
{

protected:
    MediaVisitor();

public:
    virtual ~MediaVisitor();
    
    // visit a media ref object
    virtual void Visit(const MediaRef& media_ref) = 0;
};





class MediaPathnameVisitor : public MediaVisitor
{
public:
    MediaPathnameVisitor();

    virtual ~MediaPathnameVisitor();
    
    // visit a media ref object
    void Visit(const MediaRef& media_ref);

    // returns a path array of the visited paths
    void GetPaths(Vector<Path> &paths);

private:
    Vector<Path> m_paths;
};


#endif  // Apoxi_MediaVisitor_hpp
