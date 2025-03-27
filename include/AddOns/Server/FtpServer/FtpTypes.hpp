/*  ------------------------------------------------------------------------
    Copyright (C) COMNEON electronic technology GmbH & Co. OHG.
    All rights reserved.
    ------------------------------------------------------------------------
    This document contains proprietary information belonging to COMNEON.
    Passing on and copying of this document, use and communication of its
    contents is not permitted without prior written authorisation.
    ------------------------------------------------------------------------ */

#if !defined(Apoxi_AddOns_Server_FtpServer_FtpTypes_hpp)
#define Apoxi_AddOns_Server_FtpServer_FtpTypes_hpp


// DBG_OUT range for general FtpServer stuff
#define FTPSERVER_DBG_OUT_RANGE 35910
// DBG_OUT range for extended FtpServer stuff
#define FTPSERVER_DBG_OUT_RANGE_EXTENDED 35911
// DBG_OUT range for FTP commands
#define FTPSERVER_DBG_OUT_RANGE_CMD 35912
// DBG_OUT range for FTP replies
#define FTPSERVER_DBG_OUT_RANGE_REPLY 35913


// maximum length of an FTP request
#define APOXI_FTPSERVER_REQUEST_LENGTH 1024


#if defined(APOXI_TARGETSYSTEM_HOST)

// default size for transmitting data from or to clients
#define APOXI_FTPSERVER_TRANSFER_DEFAULT_BLOCKLENGTH (128*1024)
// default maximum of currently connected clients
#define APOXI_FTPSERVER_DEFAULT_MAX_USERS 5
// default value for backlog of FtpServerSocket when listening
#define APOXI_FTPSERVER_DEFAULT_BACKLOG 25

#elif defined(APOXI_TARGETSYSTEM_HW)

// default size for transmitting data from or to clients
#define APOXI_FTPSERVER_TRANSFER_DEFAULT_BLOCKLENGTH (8*1024)
// default maximum of currently connected clients
#define APOXI_FTPSERVER_DEFAULT_MAX_USERS 5
// default value for backlog of FtpServerSocket when listening
#define APOXI_FTPSERVER_DEFAULT_BACKLOG 15

#endif


/* Commands used internally by FtpServer to keep public interface but 
    initialize SocketHandler in the right ExecutionContext.
*/
enum FtpServiceCommand {
    c_ftp_service_command_init,
    c_ftp_service_command_terminate,
    c_ftp_service_command_start,
    c_ftp_service_command_stop
};

enum FtpServiceCommandError {
    c_ftp_service_command_error_success,
    c_ftp_service_command_error_failed
};

/* Types of connections.
*/
enum FtpConnectionType {
    c_ftp_conn_type_control,
    c_ftp_conn_type_data
};

/* Types of modi for establishing the data connection (from the server's point of view).
*/
enum FtpDataConnectionType {
    c_ftp_data_conn_type_active,
    c_ftp_data_conn_type_passive
};

/* Types which are used defining the data connection.
*/
enum FtpTransferMode {
    c_ftp_transfer_mode_stream,
    c_ftp_transfer_mode_block,
    c_ftp_transfer_mode_compressed
};

enum FtpTransferType {
    c_ftp_transfer_type_ascii,
    c_ftp_transfer_type_image
};

enum FtpTransferStructure {
    c_ftp_transfer_structure_file,
    c_ftp_transfer_structure_record,
    //  c_ftp_transfer_structure_page
};

enum FtpTransferError {
    c_ftp_transfer_error_created,   // a new transfer was created
    c_ftp_transfer_error_started,   // a transfer was started
    c_ftp_transfer_error_progress,  // a transfer successfully progressed
    c_ftp_transfer_error_not_running,   // a transfer is not running (e.g. when trying to progress the transfer)
    c_ftp_transfer_error_aborted,   // a transfer was aborted by user intention
    c_ftp_transfer_error_failed,    // a transfer failed due to technical reasons
    c_ftp_transfer_error_complete   // a transfer was completed
};

enum FtpTransferDirection {
    c_ftp_transfer_direction_in,    // ingoing transfer
    c_ftp_transfer_direction_out    // outgoing transfer
};

#endif  // Apoxi_AddOns_Server_FtpServer_FtpTypes_hpp

