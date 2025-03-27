/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(ResourceID_hpp)
#define ResourceID_hpp



#include <Auxiliary/String.hpp>

class ResourceID { 
   public:
        
      ResourceID ();

      ResourceID (const String& resourceID);


      ResourceID (const CHAR* id);

      ~ResourceID();

      void SetID(const String& id);

      const String& ToString() const  {return m_id; }; 

      BOOLEAN IsEmpty() const  {return m_id.IsEmpty(); }; 

      friend inline BOOLEAN operator == (const ResourceID& lhs, const ResourceID& rhs);
      friend inline BOOLEAN operator != (const ResourceID& lhs, const ResourceID& rhs);
      friend inline BOOLEAN operator < (const ResourceID& lhs, const ResourceID& rhs);
      friend inline BOOLEAN operator > (const ResourceID& lhs, const ResourceID& rhs);

   private:
      String m_id;
      inline const String& GetID() const { return m_id; }


};


/*  ------------------------------------------------------------------------
    Operator ==
    ------------------------------------------------------------------------ */
inline BOOLEAN operator == (const ResourceID& lhs, const ResourceID& rhs) 
{
   return lhs.GetID() == rhs.GetID();
}

/*  ------------------------------------------------------------------------
    Operator !=
    ------------------------------------------------------------------------ */
inline BOOLEAN operator != (const ResourceID& lhs, const ResourceID& rhs) 
{
   return !(lhs.GetID() == rhs.GetID());
}

/*  ------------------------------------------------------------------------
    Operator >
    ------------------------------------------------------------------------ */
inline BOOLEAN operator > (const ResourceID& lhs, const ResourceID& rhs) 
{
   return (lhs.GetID() > rhs.GetID());
}


/*  ------------------------------------------------------------------------
    Operator <
    ------------------------------------------------------------------------ */
inline BOOLEAN operator < (const ResourceID& lhs, const ResourceID& rhs) 
{
   return (lhs.GetID() < rhs.GetID());
}



#endif /* ResourceID_hpp */

