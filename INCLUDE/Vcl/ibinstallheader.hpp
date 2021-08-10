// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IBInstallHeader.pas' rev: 6.00

#ifndef IBInstallHeaderHPP
#define IBInstallHeaderHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Ibinstallheader
{
//-- type declarations -------------------------------------------------------
typedef int OPTIONS_HANDLE;

typedef int *POPTIONS_HANDLE;

typedef int MSG_NO;

typedef int OPT;

typedef char *TEXT;

typedef int __stdcall (*FP_ERROR)(int IscCode, void * UserContext, const char * ActionDescription);

typedef int __stdcall (*FP_STATUS)(int Status, void * UserContext, const char * ActionDescription);

typedef int __stdcall (*Tisc_install_clear_options)(POPTIONS_HANDLE hOption);

typedef int __stdcall (*Tisc_install_execute)(int hOption, char * src_dir, char * dest_dir, FP_STATUS status_func, void * status_data, FP_ERROR error_func, void * error_data, char * uninstal_file_name);

typedef int __stdcall (*Tisc_install_get_info)(int info_type, int option, void * info_buffer, unsigned buf_len);

typedef int __stdcall (*Tisc_install_get_message)(int hOption, int message_no, void * message_txt, unsigned message_len);

typedef int __stdcall (*Tisc_install_load_external_text)(char * msg_file_name);

typedef int __stdcall (*Tisc_install_precheck)(int hOption, char * src_dir, char * dest_dir);

typedef int __stdcall (*Tisc_install_set_option)(POPTIONS_HANDLE hOption, int option);

typedef int __stdcall (*Tisc_uninstall_execute)(char * uninstall_file_name, FP_STATUS status_func, void * status_data, FP_ERROR error_func, void * error_data);

typedef int __stdcall (*Tisc_uninstall_precheck)(char * uninstall_file_name);

typedef int __stdcall (*Tisc_install_unset_option)(POPTIONS_HANDLE hOption, int option);

//-- var, const, procedure ---------------------------------------------------
#define IB_INSTALL_DLL "ibinstall.dll"
static const Shortint isc_install_fp_retry = 0xffffffff;
static const Shortint isc_install_fp_continue = 0x0;
static const Shortint isc_install_fp_abort = 0x1;
static const Shortint isc_install_info_destination = 0x1;
static const Shortint isc_install_info_opspace = 0x2;
static const Shortint isc_install_info_opname = 0x3;
static const Shortint isc_install_info_opdescription = 0x4;
static const Word ISC_INSTALL_MAX_MESSAGE_LEN = 0x12c;
static const Byte ISC_INSTALL_MAX_MESSAGES = 0xc8;
static const Word ISC_INSTALL_MAX_PATH = 0x100;
static const Word INTERBASE = 0x3e8;
static const Word IB_SERVER = 0x3e9;
static const Word IB_CLIENT = 0x3ea;
static const Word IB_CMD_TOOLS = 0x3eb;
static const Word IB_CMD_TOOLS_DB_MGMT = 0x3ec;
static const Word IB_CMD_TOOLS_USR_MGMT = 0x3ed;
static const Word IB_CMD_TOOLS_DB_QUERY = 0x3ee;
static const Word IB_GUI_TOOLS = 0x3ef;
static const Word IB_DOC = 0x3f3;
static const Word IB_EXAMPLES = 0x3f4;
static const Word IB_EXAMPLE_API = 0x3f5;
static const Word IB_EXAMPLE_DB = 0x3f6;
static const Word IB_DEV = 0x3f7;
static const Word IB_CONNECTIVITY_SERVER = 0x44c;
static const Word IB_CONNECTIVITY = 0x44d;
static const Word IB_ODBC_CLIENT = 0x44e;
static const Word IB_JDBC_CLIENT = 0x44f;
static const Word IB_OLEDB_CLIENT = 0x450;
static const Shortint isc_install_optlist_empty = 0xffffffff;
static const Shortint isc_install_actlist_empty = 0xfffffffe;
static const Shortint isc_install_fp_copy_delayed = 0xfffffffd;
static const Shortint isc_install_fp_delete_delayed = 0xfffffffc;
static const Shortint isc_install_option_not_found = 0xfffffffb;
static const Shortint isc_install_msg_version = 0xfffffffa;
static const Shortint isc_install_cant_load_msg = 0xfffffff9;
static const Shortint isc_install_invalid_msg = 0xfffffff8;
static const Shortint isc_install_invalid_tbl = 0xfffffff7;
static const Shortint isc_install_cant_create_msg = 0xfffffff6;
static const Shortint isc_install_handle_not_allocated = 0xfffffff5;
static const Shortint isc_install_odbc_comp_notfound = 0xfffffff4;
static const Shortint isc_install_cant_delete = 0xfffffff3;
static const Shortint isc_install_cant_rmdir = 0xfffffff2;
static const Shortint isc_install_key_nonempty = 0xfffffff1;
static const Shortint isc_install_success = 0x0;
static const Shortint isc_install_file_error = 0x0;
static const Shortint isc_install_path_not_valid = 0x1;
static const Shortint isc_install_path_not_exists = 0x2;
static const Shortint isc_install_cant_write = 0x3;
static const Shortint isc_install_type_unknown = 0x4;
static const Shortint isc_install_cant_move_file = 0x5;
static const Shortint isc_install_device_not_valid = 0x6;
static const Shortint isc_install_data_truncated = 0x7;
static const Shortint isc_install_cant_get_temp = 0x8;
static const Shortint isc_install_no_file = 0x9;
static const Shortint isc_install_cant_load_lib = 0xa;
static const Shortint isc_install_cant_lookup_lib = 0xb;
static const Shortint isc_install_file_exists = 0xc;
static const Shortint isc_install_cant_open_log = 0xd;
static const Shortint isc_install_write_error = 0xe;
static const Shortint isc_install_read_error = 0xf;
static const Shortint isc_install_invalid_log = 0x10;
static const Shortint isc_install_cant_read = 0x11;
static const Shortint isc_install_no_diskspace = 0x12;
static const Shortint isc_install_cant_create_dir = 0x13;
static const Shortint isc_install_msg_syntax = 0x14;
static const Shortint isc_install_fp_delete_error = 0x15;
static const Shortint isc_install_fp_rename_error = 0x16;
static const Shortint isc_install_fp_copy_error = 0x17;
static const Shortint isc_install_precheck_error = 0x18;
static const Shortint isc_install_system_not_supported = 0x18;
static const Shortint isc_install_server_running = 0x19;
static const Shortint isc_install_classic_found = 0x1a;
static const Shortint isc_install_no_privileges = 0x1b;
static const Shortint isc_install_cant_get_free_space = 0x1c;
static const Shortint isc_install_guardian_running = 0x1d;
static const Shortint isc_install_invalid_option = 0x1e;
static const Shortint isc_install_invalid_handle = 0x1f;
static const Shortint isc_install_message_not_found = 0x20;
static const Shortint isc_install_ip_error = 0x21;
static const Shortint isc_install_no_stack = 0x21;
static const Shortint isc_install_cant_add_service = 0x22;
static const Shortint isc_install_invalid_port = 0x23;
static const Shortint isc_install_invalid_service = 0x24;
static const Shortint isc_install_no_proto = 0x25;
static const Shortint isc_install_no_services_entry = 0x26;
static const Shortint isc_install_sock_error = 0x27;
static const Shortint isc_install_conversion_error = 0x28;
static const Shortint isc_install_op_error = 0x29;
static const Shortint isc_install_cant_copy = 0x29;
static const Shortint isc_install_no_mem = 0x2a;
static const Shortint isc_install_queue_failed = 0x2b;
static const Shortint isc_install_invalid_param = 0x2c;
static const Shortint isc_install_fp_error_exception = 0x2d;
static const Shortint isc_install_fp_status_exception = 0x2e;
static const Shortint isc_install_user_aborted = 0x2f;
static const Shortint isc_install_reg_error = 0x30;
static const Shortint isc_install_key_exists = 0x30;
static const Shortint isc_install_cant_create_key = 0x31;
static const Shortint isc_install_cant_set_value = 0x32;
static const Shortint isc_install_cant_open_key = 0x33;
static const Shortint isc_install_cant_delete_key = 0x34;
static const Shortint isc_install_cant_query_key = 0x35;
static const Shortint isc_install_cant_delete_value = 0x36;
static const Shortint isc_install_serv_error = 0x37;
static const Shortint isc_install_service_existed = 0x37;
static const Shortint isc_install_cant_create_service = 0x38;
static const Shortint isc_install_cant_open_service = 0x39;
static const Shortint isc_install_cant_query_service = 0x3a;
static const Shortint isc_install_service_running = 0x3b;
static const Shortint isc_install_cant_delete_service = 0x3c;
static const Shortint isc_install_cant_open_manager = 0x3d;
static const Shortint isc_install_system_error = 0x3e;
static const Shortint isc_install_com_regfail = 0x3f;
static const Shortint isc_install_dcom_required = 0x40;
static const Shortint isc_install_odbc_error = 0x41;
static const Shortint isc_install_odbc_general = 0x41;
static const Shortint isc_install_core_version = 0x42;
static const Shortint isc_install_drv_version = 0x43;
static const Shortint isc_install_tran_version = 0x44;

}	/* namespace Ibinstallheader */
using namespace Ibinstallheader;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IBInstallHeader
