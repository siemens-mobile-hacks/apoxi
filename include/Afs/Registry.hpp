/*  ------------------------------------------------------------------------
    Copyright (C) 2000 COMNEON GmbH & Co. OHG. All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

/* Contains Registry Interface declarations and global defines */

#if !defined(Apoxi_Registry_hpp)
#define Apoxi_Registry_hpp

class Ticks;
class Guid;
class DataItem;
class Application;

#include <Afs/RegistryTypes.hpp>
#include <Afs/Uri.hpp>
#include <Kernel/Os/Semaphore.hpp>

class Registry {

    public:

        static RegResult GetVersion (INT16& version, const Ticks& timeout);

        static RegResult GetVersion(INT16& version);

        static RegResult Get(const Uri& reg_uri, DataItem& item, const Ticks& timeout);

        static RegResult Get(const Uri& reg_uri, DataItem& item);

        static RegResult Set(const Uri& node_uri, const DataItem& item, const Ticks& timeout);

        static RegResult Set(const Uri& node_uri, const DataItem& item);

        static RegResult Delete(const Uri& uri, const Ticks& timeout);

        static RegResult Delete(const Uri& uri);

        static RegResult CreateInteriorNode(const Uri& uri, const Ticks& timeout);

        static RegResult CreateInteriorNode(const Uri& uri);

        static RegResult RegisterNotify(const Uri& uri, const Ticks& timeout);

        static RegResult RegisterNotify(const Uri& uri);

        static RegResult UnregisterNotify(const Uri& uri, const Ticks& timeout);
        static RegResult UnregisterNotify(const Uri& uri);

        static RegResult Lock(const Uri& uri, INT16& lockid, const Ticks& timeout);

        static RegResult Lock(const Uri& uri, INT16& lockid);

        static RegResult Unlock(INT16 lockid, const Ticks& timeout);

        static RegResult Unlock(INT16 lockid);

        static RegResult EnableTransaction(const Uri& uri, INT16& transaction_id, const Ticks& timeout);

        static RegResult EnableTransaction(const Uri& uri, INT16& transaction_id);

        static RegResult CommitTransaction(INT16 transaction_id, const Ticks& timeout);

        static RegResult CommitTransaction(INT16 transaction_id);



        static RegResult Get(const CHAR* uri, RegObjectData& reg_data_object, INT16 bufsize, const Ticks& timeout) ;

        static RegResult Get(const CHAR* uri, RegObjectData& reg_data_object, INT16 bufsize) ;

        static RegResult Replace(const CHAR* uri, const RegObjectData& reg_data_object,const Ticks& timeout);

        static RegResult Replace(const CHAR* uri, const RegObjectData& reg_data_object);

        static RegResult Add(const CHAR* uri,const RegObjectData& reg_data_object,const Ticks& timeout);

        static RegResult Add(const CHAR* uri,const RegObjectData& reg_data_object);

        static RegResult Delete(const CHAR* uri,const Ticks& timeout);

        static RegResult Delete(const CHAR* uri);

        static RegResult RegisterNotify(const CHAR* uri, void (*fp_cbfunction) (const CHAR* changed_uri), const Ticks& timeout);

        static RegResult RegisterNotify(const CHAR* uri, void (*fp_cbfunction) (const CHAR* changed_uri));

        static RegResult RegisterNotify(const CHAR* uri, const Ticks& timeout);

        static RegResult RegisterNotify(const CHAR* uri);


        static RegResult UnregisterNotify(const CHAR* uri, void (*fp_cbfunction) (const CHAR* changed_uri), const Ticks& timeout);
        static RegResult UnregisterNotify(const CHAR* uri, void (*fp_cbfunction) (const CHAR* changed_uri));
        static RegResult UnregisterNotify(const CHAR* uri, const Ticks& timeout);
        static RegResult UnregisterNotify(const CHAR* uri);

        static RegResult Lock(const CHAR* uri, INT16& lockid,const Ticks& timeout);

        static RegResult Lock(const CHAR* uri, INT16& lockid);


        //static RegResult Unlock(const INT16& lockid,const Ticks& timeout);



        static RegResult RegisterRemoteObjectTree(const CHAR* object_tree_root_uri, const Guid& service_id,const Ticks& timeout);

        static RegResult RegisterRemoteObjectTree(const CHAR* object_tree_root_uri, const Guid& service_id);

        static void Notify(const CHAR* uri, const RegChangeType* c_type, const INT16 count, const Ticks& timeout);

        static void Notify(const CHAR* uri, const RegChangeType* c_type, const INT16 count);




    private:
        Registry();
        ~Registry() ;

        static const INT16 m_registry_version;

        friend class RegManager;

        friend class RegIterator;

        static Semaphore m_sem_access;
        static BOOLEAN m_sem_initialized;

        static BOOLEAN InitSemaphore();

        static Application* GetCurrentApp();

        static RegResult RegGetDataItem(const Uri &reg_uri, DataItem &item);

        static RegResult RegSetDataItem(const Uri &node_uri, const DataItem &item);

        static RegResult RegCreateInteriorNode(const Uri &reg_uri);

        static RegResult RegGet(const Uri& reg_uri, RegObjectData& reg_data_object, INT16 bufsize);

        static RegResult RegReplace(const Uri& reg_uri, const RegObjectData& reg_data_object);

        static RegResult RegAdd(const Uri& reg_uri,const RegObjectData& reg_data_object);

        static RegResult RegDelete(const Uri& reg_uri);

        static RegResult RegRegisterNotify(const Uri& reg_uri, void (*fp_cbfunction) (const CHAR* changed_uri), Application* app);

        static RegResult RegUnregisterNotify(const Uri& reg_uri, void (*fp_cbfunction) (const CHAR* changed_uri), Application* app);

        static RegResult RegLock(const Uri& reg_uri, INT16& lockid, BOOLEAN transac_flag);

        static RegResult RegUnlock(const INT16 lockid, BOOLEAN transac_flag);

        static RegResult RegRegisterRemoteObjectTree(const Uri& object_tree_root_uri, const Guid& service_id);

        static void RegNotify(const Uri& reg_uri, const RegChangeType* ctype, const INT16 count);

        static BOOLEAN IsEnableTransactionPossible(const Uri& uri);

        static RegResult IsCommitPossible(INT16 transaction_id);


        //Following two lines should be removed in future
        friend class NotificationArray;

        static INT16 GetVersion() {
            return m_registry_version;
        } //GetVersion

};

#endif

