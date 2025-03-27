/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Services_Service_hpp)
#define Services_Service_hpp

#include <Kernel/Types.hpp>
#include <Kernel/AppContainer.hpp>
#include <Auxiliary/HashTable.hpp>

class Guid {
    public:
        UINT32 data1;
        UINT16 data2;
        UINT16 data3;
        UINT8  data4[8];

        BOOLEAN operator == (const Guid& guid) const {
            return memcmp(this, &guid, sizeof(Guid)) == 0;
        }

        BOOLEAN operator != (const Guid& guid) const {
            return memcmp(this, &guid, sizeof(Guid)) != 0;
        }
};


class Service : public Linkable<Service> {
    public:
        enum ServiceResult {
            ServResSuccess,
            ServResError
        };

        Service(Guid guid);

        virtual ~Service();

        const Guid& GetGuid() const;

    private:
        Guid m_guid;
};

template<class T> class ServicePtr {
    public:
        ServicePtr() : m_p(0) {}
        ServicePtr(Service *serv_ptr) : m_p((T*)serv_ptr) {}

        void Init(Service *serv_ptr) {
            m_p = (T*)serv_ptr;
        }

        T* operator->() const {
            return m_p;
        }

        ServicePtr<T> operator=(const Service *s) {
            m_p = (T*) s;
            return *this;
        }

        BOOLEAN operator !=(const ServicePtr<T>& s) const {
            return m_p != s.m_p;
        }

        BOOLEAN operator ==(const ServicePtr<T>& s) const {
            return m_p == s.m_p;
        }

        T& operator*() {
            return *m_p;
        }

    private:
        T *m_p;
};

typedef Service::ServiceResult ServiceResult;

#define DefGuid_NoGuid {0x0, 0x0, 0x0, {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}}
extern const Guid Guid_NoGuid;

#endif  // Services_Service_hpp

