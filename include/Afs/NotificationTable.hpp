#if !defined(Apoxi_NotificationTable_hpp)
#define Apoxi_NotificationTable_hpp


#include <Auxiliary/Linkable.hpp>
#include <Kernel/MsgTypes.hpp>
#include <Afs/Uri.hpp>

#if !defined(APOXI_REGISTERED_TABLE_SIZE)
    #define APOXI_REGISTERED_TABLE_SIZE 10
#endif

class ExecutionContext;

typedef void (* Cb_function_ptr) (const CHAR*);

/*  ======================================================================
    Class RegCbNotifyMsg
    ====================================================================== */

class RegCbNotifyMsg : public ContextExecuteMsg {
    public:
        RegCbNotifyMsg(ExecutionContext* context, void* callback, const Uri& uri);

        virtual ~RegCbNotifyMsg();

        virtual void Execute();

        virtual Message* Clone() const;

    private:
        static const MsgMetaData m_meta_data;
        void* m_callback;
        Uri m_uri;

};


class NotificationTableEntry {
    public:

        NotificationTableEntry() : m_cb_function_ptr(0), m_app_ptr(0)
        {}

        NotificationTableEntry(Uri& uri, Cb_function_ptr cb_function_ptr, Application *app_ptr)
            : m_cb_function_ptr(cb_function_ptr), m_app_ptr(app_ptr), m_uri(uri)
        {}

        NotificationTableEntry(NotificationTableEntry *rhs)
        {
            m_uri = rhs->GetUri();
            m_cb_function_ptr = rhs->GetCbFunction();
            m_app_ptr = rhs->GetAppPtr();
        }

        ~NotificationTableEntry() {}

        //Following are getter and setter functions
        Uri GetUri() const
        {
            return m_uri;
        }

        void SetUri(const Uri& uri)
        {
            m_uri = uri;
        }

        Cb_function_ptr GetCbFunction()
        {
            return m_cb_function_ptr;
        }

        void SetCbFunction(Cb_function_ptr cb_function_ptr)
        {
            m_cb_function_ptr = cb_function_ptr;
        }

        Application* GetAppPtr()
        {
            return m_app_ptr;
        }

        void SetAppPtr(Application* app_ptr)
        {
            m_app_ptr = app_ptr;
        }


        //The following only checks if the this->URI is less than
        //rhs->URI
        BOOLEAN operator < (NotificationTableEntry& rhs) const;

        BOOLEAN operator == (NotificationTableEntry& rhs) const;

    private:
        Cb_function_ptr m_cb_function_ptr; //Callback function pointer
        Application* m_app_ptr; //Application function pointer
        Uri m_uri; //Uri pointer
};


class NotificationArray : public Linkable <NotificationArray> {
    public:

        enum {
                c_table_size = APOXI_REGISTERED_TABLE_SIZE,
                c_table_full = -1
        };

        INT16 AddUri(const Uri& uri, Cb_function_ptr cb_function_ptr, Application *app_ptr);

        INT16 DeleteUri(const Uri& uri, Cb_function_ptr cb_function_ptr, Application *app_ptr);
        INT16 SearchUri(const Uri& uri, Cb_function_ptr cb_fn_ptr, Application *app_ptr);

        void SendNotification(const Uri& uri);


    private:

        NotificationTableEntry m_notification_table_entry[c_table_size];

};

//This class contains the List of NotificationArrays
class NotificationTable {
    public:

        ~NotificationTable()
        {
            NotificationArray* temp = 0;
            NotificationArray* notification_array_ptr = m_notification_list.GetFront();
            FOREVER
            {
                if(notification_array_ptr == 0)
                    break;
                temp = notification_array_ptr;
                notification_array_ptr = notification_array_ptr->GetNext();
                delete temp;
            }
        }

        static NotificationTable* GetTable();

        BOOLEAN AddRegistration(const Uri& uri, Cb_function_ptr cb_function_ptr, Application *app_ptr);

        BOOLEAN DeleteRegistration(const Uri& uri, Cb_function_ptr cb_function_ptr, Application *app_ptr);

        void SendNotificationsToApps(const Uri& uri) const;

    private:

        NotificationTable() {};

        BOOLEAN CreateNotificationTable();

        static void NotificationCallBack(Uri& uri, Application *app_ptr);

        static NotificationTable m_notification_table;

        LinkedList <NotificationArray> m_notification_list;
};


#endif


