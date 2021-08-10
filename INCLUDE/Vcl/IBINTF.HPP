// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IBIntf.pas' rev: 6.00

#ifndef IBIntfHPP
#define IBIntfHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IBExternals.hpp>	// Pascal unit
#include <IBInstallHeader.hpp>	// Pascal unit
#include <IBHeader.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Ibintf
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Ibheader::TBLOB_get BLOB_get;
extern PACKAGE Ibheader::TBLOB_put BLOB_put;
extern PACKAGE Ibheader::Tisc_sqlcode isc_sqlcode;
extern PACKAGE Ibheader::Tisc_sql_interprete isc_sql_interprete;
extern PACKAGE Ibheader::Tisc_interprete isc_interprete;
extern PACKAGE Ibheader::Tisc_vax_integer isc_vax_integer;
extern PACKAGE Ibheader::Tisc_blob_info isc_blob_info;
extern PACKAGE Ibheader::Tisc_open_blob2 isc_open_blob2;
extern PACKAGE Ibheader::Tisc_close_blob isc_close_blob;
extern PACKAGE Ibheader::Tisc_get_segment isc_get_segment;
extern PACKAGE Ibheader::Tisc_put_segment isc_put_segment;
extern PACKAGE Ibheader::Tisc_create_blob2 isc_create_blob2;
extern PACKAGE Ibheader::Tisc_service_attach isc_service_attach;
extern PACKAGE Ibheader::Tisc_service_detach isc_service_detach;
extern PACKAGE Ibheader::Tisc_service_query isc_service_query;
extern PACKAGE Ibheader::Tisc_service_start isc_service_start;
extern PACKAGE Ibheader::Tisc_decode_date isc_decode_date;
extern PACKAGE Ibheader::Tisc_decode_sql_date isc_decode_sql_date;
extern PACKAGE Ibheader::Tisc_decode_sql_time isc_decode_sql_time;
extern PACKAGE Ibheader::Tisc_decode_timestamp isc_decode_timestamp;
extern PACKAGE Ibheader::Tisc_encode_date isc_encode_date;
extern PACKAGE Ibheader::Tisc_encode_sql_date isc_encode_sql_date;
extern PACKAGE Ibheader::Tisc_encode_sql_time isc_encode_sql_time;
extern PACKAGE Ibheader::Tisc_encode_timestamp isc_encode_timestamp;
extern PACKAGE Ibheader::Tisc_dsql_free_statement isc_dsql_free_statement;
extern PACKAGE Ibheader::Tisc_dsql_execute2 isc_dsql_execute2;
extern PACKAGE Ibheader::Tisc_dsql_execute isc_dsql_execute;
extern PACKAGE Ibheader::Tisc_dsql_set_cursor_name isc_dsql_set_cursor_name;
extern PACKAGE Ibheader::Tisc_dsql_fetch isc_dsql_fetch;
extern PACKAGE Ibheader::Tisc_dsql_sql_info isc_dsql_sql_info;
extern PACKAGE Ibheader::Tisc_dsql_alloc_statement2 isc_dsql_alloc_statement2;
extern PACKAGE Ibheader::Tisc_dsql_prepare isc_dsql_prepare;
extern PACKAGE Ibheader::Tisc_dsql_describe_bind isc_dsql_describe_bind;
extern PACKAGE Ibheader::Tisc_dsql_describe isc_dsql_describe;
extern PACKAGE Ibheader::Tisc_dsql_execute_immediate isc_dsql_execute_immediate;
extern PACKAGE Ibheader::Tisc_drop_database isc_drop_database;
extern PACKAGE Ibheader::Tisc_detach_database isc_detach_database;
extern PACKAGE Ibheader::Tisc_attach_database isc_attach_database;
extern PACKAGE Ibheader::Tisc_database_info isc_database_info;
extern PACKAGE Ibheader::Tisc_start_multiple isc_start_multiple;
extern PACKAGE Ibheader::Tisc_commit_transaction isc_commit_transaction;
extern PACKAGE Ibheader::Tisc_commit_retaining isc_commit_retaining;
extern PACKAGE Ibheader::Tisc_rollback_transaction isc_rollback_transaction;
extern PACKAGE Ibheader::Tisc_rollback_retaining isc_rollback_retaining;
extern PACKAGE Ibheader::Tisc_cancel_events isc_cancel_events;
extern PACKAGE Ibheader::Tisc_que_events isc_que_events;
extern PACKAGE Ibheader::Tisc_event_counts isc_event_counts;
extern PACKAGE Ibheader::Tisc_event_block isc_event_block;
extern PACKAGE Ibheader::Tisc_free isc_free;
extern PACKAGE Ibheader::Tisc_add_user isc_add_user;
extern PACKAGE Ibheader::Tisc_delete_user isc_delete_user;
extern PACKAGE Ibheader::Tisc_modify_user isc_modify_user;
extern PACKAGE Ibheader::Tisc_prepare_transaction isc_prepare_transaction;
extern PACKAGE Ibheader::Tisc_prepare_transaction2 isc_prepare_transaction2;
extern PACKAGE Ibinstallheader::Tisc_install_clear_options isc_install_clear_options;
extern PACKAGE Ibinstallheader::Tisc_install_execute isc_install_execute;
extern PACKAGE Ibinstallheader::Tisc_install_get_info isc_install_get_info;
extern PACKAGE Ibinstallheader::Tisc_install_get_message isc_install_get_message;
extern PACKAGE Ibinstallheader::Tisc_install_load_external_text isc_install_load_external_text;
extern PACKAGE Ibinstallheader::Tisc_install_precheck isc_install_precheck;
extern PACKAGE Ibinstallheader::Tisc_install_set_option isc_install_set_option;
extern PACKAGE Ibinstallheader::Tisc_uninstall_execute isc_uninstall_execute;
extern PACKAGE Ibinstallheader::Tisc_uninstall_precheck isc_uninstall_precheck;
extern PACKAGE Ibinstallheader::Tisc_install_unset_option isc_install_unset_option;
extern PACKAGE void __fastcall LoadIBLibrary(void);
extern PACKAGE void __fastcall FreeIBLibrary(void);
extern PACKAGE void __fastcall LoadIBInstallLibrary(void);
extern PACKAGE void __fastcall FreeIBInstallLibrary(void);
extern PACKAGE bool __fastcall TryIBLoad(void);
extern PACKAGE void __fastcall CheckIBLoaded(void);
extern PACKAGE int __fastcall GetIBClientVersion(void);
extern PACKAGE void __fastcall CheckIBInstallLoaded(void);
extern PACKAGE int __stdcall isc_rollback_retaining_stub(Ibexternals::PISC_STATUS status_vector, Ibheader::PISC_TR_HANDLE tran_handle);
extern PACKAGE int __stdcall isc_service_attach_stub(Ibexternals::PISC_STATUS status_vector, Word isc_arg2, char * isc_arg3, Ibheader::PISC_SVC_HANDLE service_handle, Word isc_arg5, char * isc_arg6);
extern PACKAGE int __stdcall isc_service_detach_stub(Ibexternals::PISC_STATUS status_vector, Ibheader::PISC_SVC_HANDLE service_handle);
extern PACKAGE int __stdcall isc_service_query_stub(Ibexternals::PISC_STATUS status_vector, Ibheader::PISC_SVC_HANDLE service_handle, Ibheader::PISC_SVC_HANDLE recv_handle, Word isc_arg4, char * isc_arg5, Word isc_arg6, char * isc_arg7, Word isc_arg8, char * isc_arg9);
extern PACKAGE int __stdcall isc_service_start_stub(Ibexternals::PISC_STATUS status_vector, Ibheader::PISC_SVC_HANDLE service_handle, Ibheader::PISC_SVC_HANDLE recv_handle, Word isc_arg4, char * isc_arg5);
extern PACKAGE void __stdcall isc_encode_sql_date_stub(Ibexternals::PCTimeStructure tm_date, Ibheader::PISC_DATE ib_date);
extern PACKAGE void __stdcall isc_encode_sql_time_stub(Ibexternals::PCTimeStructure tm_date, Ibheader::PISC_TIME ib_time);
extern PACKAGE void __stdcall isc_encode_timestamp_stub(Ibexternals::PCTimeStructure tm_date, Ibheader::PISC_TIMESTAMP ib_timestamp);
extern PACKAGE void __stdcall isc_decode_sql_date_stub(Ibheader::PISC_DATE ib_date, Ibexternals::PCTimeStructure tm_date);
extern PACKAGE void __stdcall isc_decode_sql_time_stub(Ibheader::PISC_TIME ib_time, Ibexternals::PCTimeStructure tm_date);
extern PACKAGE void __stdcall isc_decode_timestamp_stub(Ibheader::PISC_TIMESTAMP ib_timestamp, Ibexternals::PCTimeStructure tm_date);
extern PACKAGE int __stdcall isc_install_clear_options_stub(Ibinstallheader::POPTIONS_HANDLE hOption);
extern PACKAGE int __stdcall isc_install_execute_stub(int hOption, char * src_dir, char * dest_dir, Ibinstallheader::FP_STATUS status_func, void * status_data, Ibinstallheader::FP_ERROR error_func, void * error_data, char * uninstal_file_name);
extern PACKAGE int __stdcall isc_install_get_info_stub(int info_type, int option, void * info_buffer, unsigned buf_len);
extern PACKAGE int __stdcall isc_install_get_message_stub(int hOption, int message_no, void * message_txt, unsigned message_len);
extern PACKAGE int __stdcall isc_install_load_external_text_stub(char * msg_file_name);
extern PACKAGE int __stdcall isc_install_precheck_stub(int hOption, char * src_dir, char * dest_dir);
extern PACKAGE int __stdcall isc_install_set_option_stub(Ibinstallheader::POPTIONS_HANDLE hOption, int option);
extern PACKAGE int __stdcall isc_uninstall_execute_stub(char * uninstall_file_name, Ibinstallheader::FP_STATUS status_func, void * status_data, Ibinstallheader::FP_ERROR error_func, void * error_data);
extern PACKAGE int __stdcall isc_uninstall_precheck_stub(char * uninstall_file_name);
extern PACKAGE int __stdcall isc_install_unset_option_stub(Ibinstallheader::POPTIONS_HANDLE hOption, int option);

}	/* namespace Ibintf */
using namespace Ibintf;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IBIntf
