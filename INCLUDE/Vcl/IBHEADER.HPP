// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IBHeader.pas' rev: 5.00

#ifndef IBHeaderHPP
#define IBHeaderHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IBExternals.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Ibheader
{
//-- type declarations -------------------------------------------------------
typedef void * *TISC_ATT_HANDLE;

typedef Ibexternals::PVoid *PISC_ATT_HANDLE;

typedef void * *TISC_BLOB_HANDLE;

typedef Ibexternals::PVoid *PISC_BLOB_HANDLE;

typedef void * *TISC_DB_HANDLE;

typedef Ibexternals::PVoid *PISC_DB_HANDLE;

typedef void * *TISC_FORM_HANDLE;

typedef Ibexternals::PVoid *PISC_FORM_HANDLE;

typedef void * *TISC_REQ_HANDLE;

typedef Ibexternals::PVoid *PISC_REQ_HANDLE;

typedef void * *TISC_STMT_HANDLE;

typedef Ibexternals::PVoid *PISC_STMT_HANDLE;

typedef void * *TISC_SVC_HANDLE;

typedef Ibexternals::PVoid *PISC_SVC_HANDLE;

typedef void * *TISC_TR_HANDLE;

typedef Ibexternals::PVoid *PISC_TR_HANDLE;

typedef void * *TISC_WIN_HANDLE;

typedef Ibexternals::PVoid *PISC_WIN_HANDLE;

typedef void __fastcall (*TISC_CALLBACK)(void);

typedef int ISC_SVC_HANDLE;

typedef int ISC_DATE;

typedef int *PISC_DATE;

typedef unsigned ISC_TIME;

typedef unsigned *PISC_TIME;

struct TISC_TIMESTAMP
{
	int timestamp_date;
	unsigned timestamp_time;
} ;

typedef TISC_TIMESTAMP *PISC_TIMESTAMP;

struct TGDS_QUAD
{
	int gds_quad_high;
	unsigned gds_quad_low;
} ;

typedef TGDS_QUAD  TGDS__QUAD;

typedef TGDS_QUAD  TISC_QUAD;

typedef TGDS_QUAD *PGDS_QUAD;

typedef TGDS_QUAD *PGDS__QUAD;

typedef TGDS_QUAD *PISC_QUAD;

struct TISC_ARRAY_BOUND
{
	short array_bound_lower;
	short array_bound_upper;
} ;

typedef TISC_ARRAY_BOUND *PISC_ARRAY_BOUND;

struct TISC_ARRAY_DESC
{
	Byte array_desc_dtype;
	char array_desc_scale;
	Word array_desc_length;
	char array_desc_field_name[32];
	char array_desc_relation_name[32];
	short array_desc_dimensions;
	short array_desc_flags;
	TISC_ARRAY_BOUND array_desc_bounds[16];
} ;

typedef TISC_ARRAY_DESC *PISC_ARRAY_DESC;

struct TISC_BLOB_DESC
{
	short blob_desc_subtype;
	short blob_desc_charset;
	short blob_desc_segment_size;
	Byte blob_desc_field_name[32];
	Byte blob_desc_relation_name[32];
} ;

typedef TISC_BLOB_DESC *PISC_BLOB_DESC;

typedef int __fastcall (*TISC_BLOB_CTL_SOURCE_FUNCTION)(void);

struct TISC_BLOB_CTL;
typedef TISC_BLOB_CTL *PISC_BLOB_CTL;

struct TISC_BLOB_CTL
{
	TISC_BLOB_CTL_SOURCE_FUNCTION ctl_source;
	TISC_BLOB_CTL *ctl_source_handle;
	short ctl_to_sub_type;
	short ctl_from_sub_type;
	Word ctl_buffer_length;
	Word ctl_segment_length;
	Word ctl_bpb_length;
	char *ctl_bpb;
	Byte *ctl_buffer;
	int ctl_max_segment;
	int ctl_number_segments;
	int ctl_total_length;
	int *ctl_status;
	int ctl_data[8];
} ;

struct TBSTREAM
{
	void * *bstr_blob;
	char *bstr_buffer;
	char *bstr_ptr;
	short bstr_length;
	short bstr_cnt;
	char bstr_mode;
} ;

typedef TBSTREAM *PBSTREAM;

struct TXSQLVAR
{
	short sqltype;
	short sqlscale;
	short sqlsubtype;
	short sqllen;
	char *sqldata;
	short *sqlind;
	short sqlname_length;
	char sqlname[32];
	short relname_length;
	char relname[32];
	short ownname_length;
	char ownname[32];
	short aliasname_length;
	char aliasname[32];
} ;

typedef TXSQLVAR *PXSQLVAR;

struct TXSQLDA
{
	short version;
	char sqldaid[8];
	int sqldabc;
	short sqln;
	short sqld;
	TXSQLVAR sqlvar[1];
} ;

typedef TXSQLDA *PXSQLDA;

struct TISC_START_TRANS
{
	Ibexternals::PVoid *db_handle;
	Word tpb_length;
	char *tpb_address;
} ;

struct TISC_TEB
{
	Ibexternals::PVoid *db_handle;
	int tpb_length;
	char *tpb_address;
} ;

typedef TISC_TEB *PISC_TEB;

typedef TISC_TEB TISC_TEB_ARRAY[1];

typedef TISC_TEB *PISC_TEB_ARRAY;

typedef int __stdcall (*Tisc_attach_database)(Ibexternals::PISC_STATUS status_vector, short db_name_length
	, char * db_name, PISC_DB_HANDLE db_handle, short parm_buffer_length, char * parm_buffer);

typedef int __stdcall (*Tisc_array_gen_sdl)(Ibexternals::PISC_STATUS status_vector, PISC_ARRAY_DESC 
	isc_array_desc, Ibexternals::PShort isc_arg3, char * isc_arg4, Ibexternals::PShort isc_arg5);

typedef int __stdcall (*Tisc_array_get_slice)(Ibexternals::PISC_STATUS status_vector, PISC_DB_HANDLE 
	db_handle, PISC_TR_HANDLE trans_handle, PISC_QUAD array_id, PISC_ARRAY_DESC descriptor, Ibexternals::PVoid 
	dest_array, int slice_length);

typedef int __stdcall (*Tisc_array_lookup_bounds)(Ibexternals::PISC_STATUS status_vector, PISC_DB_HANDLE 
	db_handle, PISC_TR_HANDLE trans_handle, char * table_name, char * column_name, PISC_ARRAY_DESC descriptor
	);

typedef int __stdcall (*Tisc_array_lookup_desc)(Ibexternals::PISC_STATUS status_vector, PISC_DB_HANDLE 
	db_handle, PISC_TR_HANDLE trans_handle, char * table_name, char * column_name, PISC_ARRAY_DESC descriptor
	);

typedef int __stdcall (*Tisc_array_set_desc)(Ibexternals::PISC_STATUS status_vector, char * table_name
	, char * column_name, Ibexternals::PShort sql_dtype, Ibexternals::PShort sql_length, Ibexternals::PShort 
	sql_dimensions, PISC_ARRAY_DESC descriptor);

typedef int __stdcall (*Tisc_array_put_slice)(Ibexternals::PISC_STATUS status_vector, PISC_DB_HANDLE 
	db_handle, PISC_TR_HANDLE trans_handle, PISC_QUAD array_id, PISC_ARRAY_DESC descriptor, Ibexternals::PVoid 
	source_array, Ibexternals::PISC_LONG slice_length);

typedef void __stdcall (*Tisc_blob_default_desc)(PISC_BLOB_DESC descriptor, Ibexternals::PUChar table_name
	, Ibexternals::PUChar column_name);

typedef int __stdcall (*Tisc_blob_gen_bpb)(Ibexternals::PISC_STATUS status_vector, PISC_BLOB_DESC to_descriptor
	, PISC_BLOB_DESC from_descriptor, Word bpb_buffer_length, Ibexternals::PUChar bpb_buffer, Ibexternals::PUShort 
	bpb_length);

typedef int __stdcall (*Tisc_blob_info)(Ibexternals::PISC_STATUS status_vector, PISC_BLOB_HANDLE blob_handle
	, short item_list_buffer_length, char * item_list_buffer, short result_buffer_length, char * result_buffer
	);

typedef int __stdcall (*Tisc_blob_lookup_desc)(Ibexternals::PISC_STATUS status_vector, PISC_DB_HANDLE 
	db_handle, PISC_TR_HANDLE trans_handle, char * table_name, char * column_name, PISC_BLOB_DESC descriptor
	, Ibexternals::PUChar global);

typedef int __stdcall (*Tisc_blob_set_desc)(Ibexternals::PISC_STATUS status_vector, char * table_name
	, char * column_name, short subtype, short charset, short segment_size, PISC_BLOB_DESC descriptor);
	

typedef int __stdcall (*Tisc_cancel_blob)(Ibexternals::PISC_STATUS status_vector, PISC_BLOB_HANDLE blob_handle
	);

typedef int __stdcall (*Tisc_cancel_events)(Ibexternals::PISC_STATUS status_vector, PISC_DB_HANDLE db_handle
	, Ibexternals::PISC_LONG event_id);

typedef int __stdcall (*Tisc_close_blob)(Ibexternals::PISC_STATUS status_vector, PISC_BLOB_HANDLE blob_handle
	);

typedef int __stdcall (*Tisc_commit_retaining)(Ibexternals::PISC_STATUS status_vector, PISC_TR_HANDLE 
	tran_handle);

typedef int __stdcall (*Tisc_commit_transaction)(Ibexternals::PISC_STATUS status_vector, PISC_TR_HANDLE 
	tran_handle);

typedef int __stdcall (*Tisc_create_blob)(Ibexternals::PISC_STATUS status_vector, PISC_DB_HANDLE db_handle
	, PISC_TR_HANDLE tran_handle, PISC_BLOB_HANDLE blob_handle, PISC_QUAD blob_id);

typedef int __stdcall (*Tisc_create_blob2)(Ibexternals::PISC_STATUS status_vector, PISC_DB_HANDLE db_handle
	, PISC_TR_HANDLE tran_handle, PISC_BLOB_HANDLE blob_handle, PISC_QUAD blob_id, short bpb_length, char * 
	bpb_address);

typedef int __stdcall (*Tisc_create_database)(Ibexternals::PISC_STATUS status_vector, short isc_arg2
	, char * isc_arg3, PISC_DB_HANDLE db_handle, short isc_arg5, char * isc_arg6, short isc_arg7);

typedef int __stdcall (*Tisc_database_info)(Ibexternals::PISC_STATUS status_vector, PISC_DB_HANDLE db_handle
	, short item_list_buffer_length, char * item_list_buffer, short result_buffer_length, char * result_buffer
	);

typedef void __stdcall (*Tisc_decode_date)(PISC_QUAD ib_date, Ibexternals::PCTimeStructure tm_date);
	

typedef void __stdcall (*Tisc_decode_sql_date)(PISC_DATE ib_date, Ibexternals::PCTimeStructure tm_date
	);

typedef void __stdcall (*Tisc_decode_sql_time)(PISC_TIME ib_time, Ibexternals::PCTimeStructure tm_date
	);

typedef void __stdcall (*Tisc_decode_timestamp)(PISC_TIMESTAMP ib_timestamp, Ibexternals::PCTimeStructure 
	tm_date);

typedef int __stdcall (*Tisc_detach_database)(Ibexternals::PISC_STATUS status_vector, PISC_DB_HANDLE 
	db_handle);

typedef int __stdcall (*Tisc_drop_database)(Ibexternals::PISC_STATUS status_vector, PISC_DB_HANDLE db_handle
	);

typedef int __stdcall (*Tisc_dsql_allocate_statement)(Ibexternals::PISC_STATUS status_vector, PISC_DB_HANDLE 
	db_handle, PISC_STMT_HANDLE stmt_handle);

typedef int __stdcall (*Tisc_dsql_alloc_statement2)(Ibexternals::PISC_STATUS status_vector, PISC_DB_HANDLE 
	db_handle, PISC_STMT_HANDLE stmt_handle);

typedef int __stdcall (*Tisc_dsql_describe)(Ibexternals::PISC_STATUS status_vector, PISC_STMT_HANDLE 
	stmt_handle, Word dialect, PXSQLDA xsqlda);

typedef int __stdcall (*Tisc_dsql_describe_bind)(Ibexternals::PISC_STATUS status_vector, PISC_STMT_HANDLE 
	stmt_handle, Word dialect, PXSQLDA xsqlda);

typedef int __stdcall (*Tisc_dsql_exec_immed2)(Ibexternals::PISC_STATUS status_vector, PISC_DB_HANDLE 
	db_handle, PISC_TR_HANDLE tran_handle, Word length, char * statement, Word dialect, PXSQLDA in_xsqlda
	, PXSQLDA out_xsqlda);

typedef int __stdcall (*Tisc_dsql_execute)(Ibexternals::PISC_STATUS status_vector, PISC_TR_HANDLE tran_handle
	, PISC_STMT_HANDLE stmt_handle, Word dialect, PXSQLDA xsqlda);

typedef int __stdcall (*Tisc_dsql_execute2)(Ibexternals::PISC_STATUS status_vector, PISC_TR_HANDLE tran_handle
	, PISC_STMT_HANDLE stmt_handle, Word dialect, PXSQLDA in_xsqlda, PXSQLDA out_xsqlda);

typedef int __stdcall (*Tisc_dsql_execute_immediate)(Ibexternals::PISC_STATUS status_vector, PISC_DB_HANDLE 
	db_handle, PISC_TR_HANDLE tran_handle, Word length, char * statement, Word dialect, PXSQLDA xsqlda)
	;

typedef int __stdcall (*Tisc_dsql_fetch)(Ibexternals::PISC_STATUS status_vector, PISC_STMT_HANDLE stmt_handle
	, Word dialect, PXSQLDA xsqlda);

typedef int __stdcall (*Tisc_dsql_finish)(PISC_DB_HANDLE db_handle);

typedef int __stdcall (*Tisc_dsql_free_statement)(Ibexternals::PISC_STATUS status_vector, PISC_STMT_HANDLE 
	stmt_handle, Word options);

typedef int __stdcall (*Tisc_dsql_insert)(Ibexternals::PISC_STATUS status_vector, PISC_STMT_HANDLE stmt_handle
	, Word arg3, PXSQLDA xsqlda);

typedef int __stdcall (*Tisc_dsql_prepare)(Ibexternals::PISC_STATUS status_vector, PISC_TR_HANDLE tran_handle
	, PISC_STMT_HANDLE stmt_handle, Word length, char * statement, Word dialect, PXSQLDA xsqlda);

typedef int __stdcall (*Tisc_dsql_set_cursor_name)(Ibexternals::PISC_STATUS status_vector, PISC_STMT_HANDLE 
	stmt_handle, char * cursor_name, Word _type);

typedef int __stdcall (*Tisc_dsql_sql_info)(Ibexternals::PISC_STATUS status_vector, PISC_STMT_HANDLE 
	stmt_handle, short item_length, char * items, short buffer_length, char * buffer);

typedef void __stdcall (*Tisc_encode_date)(Ibexternals::PCTimeStructure tm_date, PISC_QUAD ib_date);
	

typedef void __stdcall (*Tisc_encode_sql_date)(Ibexternals::PCTimeStructure tm_date, PISC_DATE ib_date
	);

typedef void __stdcall (*Tisc_encode_sql_time)(Ibexternals::PCTimeStructure tm_date, PISC_TIME ib_time
	);

typedef void __stdcall (*Tisc_encode_timestamp)(Ibexternals::PCTimeStructure tm_date, PISC_TIMESTAMP 
	ib_timestamp);

typedef int __cdecl (*Tisc_event_block)(Ibexternals::PPChar event_buffer, Ibexternals::PPChar result_buffer
	, Word id_count, const char * * event_list, const int event_list_Size);

typedef void __stdcall (*Tisc_event_counts)(Ibexternals::PISC_STATUS status_vector, short buffer_length
	, char * event_buffer, char * result_buffer);

typedef void __cdecl (*Tisc_expand_dpb)(Ibexternals::PPChar dpb, Ibexternals::PShort dpb_length, const 
	void * * item_list, const int item_list_Size);

typedef int __stdcall (*Tisc_modify_dpb)(Ibexternals::PPChar dpb, Ibexternals::PShort isc_arg2, Ibexternals::PShort 
	isc_arg3, Word isc_arg4, char * isc_arg5, short isc_arg6);

typedef int __stdcall (*Tisc_free)(char * isc_arg1);

typedef int __stdcall (*Tisc_get_segment)(Ibexternals::PISC_STATUS status_vector, PISC_BLOB_HANDLE blob_handle
	, Ibexternals::PUShort actual_seg_length, Word seg_buffer_length, char * seg_buffer);

typedef int __stdcall (*Tisc_get_slice)(Ibexternals::PISC_STATUS status_vector, PISC_DB_HANDLE db_handle
	, PISC_TR_HANDLE tran_handle, PISC_QUAD isc_arg4, short isc_arg5, char * isc_arg6, short isc_arg7, 
	Ibexternals::PISC_LONG isc_arg8, int isc_arg9, Ibexternals::PVoid isc_arg10, Ibexternals::PISC_LONG 
	isc_arg11);

typedef int __stdcall (*Tisc_interprete)(char * buffer, Ibexternals::PPISC_STATUS status_vector);

typedef int __stdcall (*Tisc_open_blob)(Ibexternals::PISC_STATUS status_vector, PISC_DB_HANDLE db_handle
	, PISC_TR_HANDLE tran_handle, PISC_BLOB_HANDLE blob_handle, PISC_QUAD blob_id);

typedef int __stdcall (*Tisc_open_blob2)(Ibexternals::PISC_STATUS status_vector, PISC_DB_HANDLE db_handle
	, PISC_TR_HANDLE tran_handle, PISC_BLOB_HANDLE blob_handle, PISC_QUAD blob_id, short bpb_length, char * 
	bpb_buffer);

typedef int __stdcall (*Tisc_prepare_transaction2)(Ibexternals::PISC_STATUS status_vector, PISC_TR_HANDLE 
	tran_handle, short msg_length, char * msg);

typedef void __stdcall (*Tisc_print_sqlerror)(short sqlcode, Ibexternals::PISC_STATUS status_vector)
	;

typedef int __stdcall (*Tisc_print_status)(Ibexternals::PISC_STATUS status_vector);

typedef int __stdcall (*Tisc_put_segment)(Ibexternals::PISC_STATUS status_vector, PISC_BLOB_HANDLE blob_handle
	, Word seg_buffer_len, char * seg_buffer);

typedef int __stdcall (*Tisc_put_slice)(Ibexternals::PISC_STATUS status_vector, PISC_DB_HANDLE db_handle
	, PISC_TR_HANDLE tran_handle, PISC_QUAD isc_arg4, short isc_arg5, char * isc_arg6, short isc_arg7, 
	Ibexternals::PISC_LONG isc_arg8, int isc_arg9, Ibexternals::PVoid isc_arg10);

typedef int __stdcall (*Tisc_que_events)(Ibexternals::PISC_STATUS status_vector, PISC_DB_HANDLE db_handle
	, Ibexternals::PISC_LONG event_id, short length, char * event_buffer, TISC_CALLBACK event_function, 
	Ibexternals::PVoid event_function_arg);

typedef int __stdcall (*Tisc_rollback_retaining)(Ibexternals::PISC_STATUS status_vector, PISC_TR_HANDLE 
	tran_handle);

typedef int __stdcall (*Tisc_rollback_transaction)(Ibexternals::PISC_STATUS status_vector, PISC_TR_HANDLE 
	tran_handle);

typedef int __stdcall (*Tisc_start_multiple)(Ibexternals::PISC_STATUS status_vector, PISC_TR_HANDLE 
	tran_handle, short db_handle_count, PISC_TEB teb_vector_address);

typedef int __cdecl (*Tisc_start_transaction)(Ibexternals::PISC_STATUS status_vector, PISC_TR_HANDLE 
	tran_handle, short db_handle_count, PISC_DB_HANDLE db_handle, Word tpb_length, char * tpb_address);
	

typedef int __stdcall (*Tisc_sqlcode)(Ibexternals::PISC_STATUS status_vector);

typedef void __stdcall (*Tisc_sql_interprete)(short sqlcode, char * buffer, short buffer_length);

typedef int __stdcall (*Tisc_transaction_info)(Ibexternals::PISC_STATUS status_vector, PISC_TR_HANDLE 
	tran_handle, short item_list_buffer_length, char * item_list_buffer, short result_buffer_length, char * 
	result_buffer);

typedef int __stdcall (*Tisc_transact_request)(Ibexternals::PISC_STATUS status_vector, PISC_DB_HANDLE 
	db_handle, PISC_TR_HANDLE tran_handle, Word isc_arg4, char * isc_arg5, Word isc_arg6, char * isc_arg7
	, Word isc_arg8, char * isc_arg9);

typedef int __stdcall (*Tisc_vax_integer)(char * buffer, short length);

typedef __int64 __stdcall (*Tisc_portable_integer)(char * buffer, short length);

struct TUserSecData
{
	short sec_flags;
	int uid;
	int gid;
	int protocol;
	char *server;
	char *user_name;
	char *password;
	char *group_name;
	char *first_name;
	char *middle_name;
	char *last_name;
	char *dba_user_name;
	char *dba_password;
} ;

typedef TUserSecData *PUserSecData;

typedef int __stdcall (*Tisc_add_user)(Ibexternals::PISC_STATUS status_vector, PUserSecData user_sec_data
	);

typedef int __stdcall (*Tisc_delete_user)(Ibexternals::PISC_STATUS status_vector, PUserSecData user_sec_data
	);

typedef int __stdcall (*Tisc_modify_user)(Ibexternals::PISC_STATUS status_vector, PUserSecData user_sec_data
	);

typedef int __stdcall (*Tisc_compile_request)(Ibexternals::PISC_STATUS status_vector, PISC_DB_HANDLE 
	db_handle, PISC_REQ_HANDLE request_handle, short isc_arg4, char * isc_arg5);

typedef int __stdcall (*Tisc_compile_request2)(Ibexternals::PISC_STATUS status_vector, PISC_DB_HANDLE 
	db_handle, PISC_REQ_HANDLE request_handle, short isc_arg4, char * isc_arg5);

typedef int __stdcall (*Tisc_ddl)(Ibexternals::PISC_STATUS status_vector, PISC_DB_HANDLE db_handle, 
	PISC_TR_HANDLE tran_handle, short isc_arg4, char * isc_arg5);

typedef int __stdcall (*Tisc_prepare_transaction)(Ibexternals::PISC_STATUS status_vector, PISC_TR_HANDLE 
	tran_handle);

typedef int __stdcall (*Tisc_receive)(Ibexternals::PISC_STATUS status_vector, PISC_REQ_HANDLE request_handle
	, short isc_arg3, short isc_arg4, Ibexternals::PVoid isc_arg5, short isc_arg6);

typedef int __stdcall (*Tisc_receive2)(Ibexternals::PISC_STATUS status_vector, PISC_REQ_HANDLE request_handle
	, short isc_arg3, short isc_arg4, Ibexternals::PVoid isc_arg5, short isc_arg6, short isc_arg7, int 
	isc_arg8);

typedef int __stdcall (*Tisc_reconnect_transaction)(Ibexternals::PISC_STATUS status_vector, PISC_DB_HANDLE 
	db_handle, PISC_TR_HANDLE tran_handle, short isc_arg4, char * isc_arg5);

typedef int __stdcall (*Tisc_release_request)(Ibexternals::PISC_STATUS status_vector, PISC_REQ_HANDLE 
	request_handle);

typedef int __stdcall (*Tisc_request_info)(Ibexternals::PISC_STATUS status_vector, PISC_REQ_HANDLE request_handle
	, short isc_arg3, short isc_arg4, char * isc_arg5, short isc_arg6, char * isc_arg7);

typedef int __stdcall (*Tisc_seek_blob)(Ibexternals::PISC_STATUS status_vector, PISC_BLOB_HANDLE blob_handle
	, short isc_arg3, int isc_arg4, Ibexternals::PISC_LONG isc_arg5);

typedef int __stdcall (*Tisc_send)(Ibexternals::PISC_STATUS status_vector, PISC_REQ_HANDLE request_handle
	, short isc_arg3, short isc_arg4, Ibexternals::PVoid isc_arg5, short isc_arg6);

typedef int __stdcall (*Tisc_start_and_send)(Ibexternals::PISC_STATUS status_vector, PISC_REQ_HANDLE 
	request_handle, PISC_TR_HANDLE tran_handle, short isc_arg4, short isc_arg5, Ibexternals::PVoid isc_arg6
	, short isc_arg7);

typedef int __stdcall (*Tisc_start_request)(Ibexternals::PISC_STATUS status_vector, PISC_REQ_HANDLE 
	request_handle, PISC_TR_HANDLE tran_handle, short isc_arg4);

typedef int __stdcall (*Tisc_unwind_request)(Ibexternals::PISC_STATUS status_vector, PISC_TR_HANDLE 
	tran_handle, short isc_arg3);

typedef int __stdcall (*Tisc_wait_for_event)(Ibexternals::PISC_STATUS status_vector, PISC_DB_HANDLE 
	db_handle, short length, char * event_buffer, char * result_buffer);

typedef int __stdcall (*Tisc_close)(Ibexternals::PISC_STATUS status_vector, char * isc_arg2);

typedef int __stdcall (*Tisc_declare)(Ibexternals::PISC_STATUS status_vector, char * isc_arg2, char * 
	isc_arg3);

typedef int __stdcall (*Tisc_describe)(Ibexternals::PISC_STATUS status_vector, char * isc_arg2, PXSQLDA 
	isc_arg3);

typedef int __stdcall (*Tisc_describe_bind)(Ibexternals::PISC_STATUS status_vector, char * isc_arg2, 
	PXSQLDA isc_arg3);

typedef int __stdcall (*Tisc_execute)(Ibexternals::PISC_STATUS status_vector, PISC_TR_HANDLE tran_handle
	, char * isc_arg3, PXSQLDA isc_arg4);

typedef int __stdcall (*Tisc_execute_immediate)(Ibexternals::PISC_STATUS status_vector, PISC_DB_HANDLE 
	db_handle, PISC_TR_HANDLE tran_handle, Ibexternals::PShort isc_arg4, char * isc_arg5);

typedef int __stdcall (*Tisc_fetch)(Ibexternals::PISC_STATUS status_vector, char * isc_arg2, PXSQLDA 
	isc_arg3);

typedef int __stdcall (*Tisc_open)(Ibexternals::PISC_STATUS status_vector, PISC_TR_HANDLE tran_handle
	, char * isc_arg3, PXSQLDA isc_arg4);

typedef int __stdcall (*Tisc_prepare)(Ibexternals::PISC_STATUS status_vector, PISC_DB_HANDLE db_handle
	, PISC_TR_HANDLE tran_handle, char * isc_arg4, Ibexternals::PShort isc_arg5, char * isc_arg6, PXSQLDA 
	isc_arg7);

typedef int __stdcall (*Tisc_dsql_execute_m)(Ibexternals::PISC_STATUS status_vector, PISC_TR_HANDLE 
	tran_handle, PISC_STMT_HANDLE statement_handle, Word isc_arg4, char * isc_arg5, Word isc_arg6, Word 
	isc_arg7, char * isc_arg8);

typedef int __stdcall (*Tisc_dsql_execute2_m)(Ibexternals::PISC_STATUS status_vector, PISC_TR_HANDLE 
	tran_handle, PISC_STMT_HANDLE statement_handle, Word isc_arg4, char * isc_arg5, Word isc_arg6, Word 
	isc_arg7, char * isc_arg8, Word isc_arg9, char * isc_arg10, Word isc_arg11, Word isc_arg12, char * 
	isc_arg13);

typedef int __stdcall (*Tisc_dsql_execute_immediate_m)(Ibexternals::PISC_STATUS status_vector, PISC_DB_HANDLE 
	db_handle, PISC_TR_HANDLE tran_handle, Word isc_arg4, char * isc_arg5, Word isc_arg6, Word isc_arg7
	, char * isc_arg8, Word isc_arg9, Word isc_arg10, char * isc_arg11);

typedef int __stdcall (*Tisc_dsql_exec_immed3_m)(Ibexternals::PISC_STATUS status_vector, PISC_DB_HANDLE 
	db_handle, PISC_TR_HANDLE tran_handle, Word isc_arg4, char * isc_arg5, Word isc_arg6, Word isc_arg7
	, char * isc_arg8, Word isc_arg9, Word isc_arg10, char * isc_arg11, Word isc_arg12, char * isc_arg13
	, Word isc_arg14, Word isc_arg15, char * isc_arg16);

typedef int __stdcall (*Tisc_dsql_fetch_m)(Ibexternals::PISC_STATUS status_vector, PISC_STMT_HANDLE 
	statement_handle, Word isc_arg3, char * isc_arg4, Word isc_arg5, Word isc_arg6, char * isc_arg7);

typedef int __stdcall (*Tisc_dsql_insert_m)(Ibexternals::PISC_STATUS status_vector, PISC_STMT_HANDLE 
	statement_handle, Word isc_arg3, char * isc_arg4, Word isc_arg5, Word isc_arg6, char * isc_arg7);

typedef int __stdcall (*Tisc_dsql_prepare_m)(Ibexternals::PISC_STATUS status_vector, PISC_TR_HANDLE 
	tran_handle, PISC_STMT_HANDLE statement_handle, Word isc_arg4, char * isc_arg5, Word isc_arg6, Word 
	isc_arg7, char * isc_arg8, Word isc_arg9, char * isc_arg10);

typedef int __stdcall (*Tisc_dsql_release)(Ibexternals::PISC_STATUS status_vector, char * isc_arg2);
	

typedef int __stdcall (*Tisc_embed_dsql_close)(Ibexternals::PISC_STATUS status_vector, char * isc_arg2
	);

typedef int __stdcall (*Tisc_embed_dsql_declare)(Ibexternals::PISC_STATUS status_vector, char * isc_arg2
	, char * isc_arg3);

typedef int __stdcall (*Tisc_embed_dsql_describe)(Ibexternals::PISC_STATUS status_vector, char * isc_arg2
	, Word isc_arg3, PXSQLDA isc_arg4);

typedef int __stdcall (*Tisc_embed_dsql_describe_bind)(Ibexternals::PISC_STATUS status_vector, char * 
	isc_arg2, Word isc_arg3, PXSQLDA isc_arg4);

typedef int __stdcall (*Tisc_embed_dsql_execute)(Ibexternals::PISC_STATUS status_vector, PISC_TR_HANDLE 
	tran_handle, char * isc_arg3, Word isc_arg4, PXSQLDA isc_arg5);

typedef int __stdcall (*Tisc_embed_dsql_execute2)(Ibexternals::PISC_STATUS status_vector, PISC_TR_HANDLE 
	tran_handle, char * isc_arg3, Word isc_arg4, PXSQLDA isc_arg5, PXSQLDA isc_arg6);

typedef int __stdcall (*Tisc_embed_dsql_execute_immed)(Ibexternals::PISC_STATUS status_vector, PISC_DB_HANDLE 
	db_handle, PISC_TR_HANDLE tran_handle, Word isc_arg4, char * isc_arg5, Word isc_arg6, PXSQLDA isc_arg7
	);

typedef int __stdcall (*Tisc_embed_dsql_fetch)(Ibexternals::PISC_STATUS status_vector, char * isc_arg2
	, Word isc_arg3, PXSQLDA isc_arg4);

typedef int __stdcall (*Tisc_embed_dsql_open)(Ibexternals::PISC_STATUS status_vector, PISC_TR_HANDLE 
	tran_handle, char * isc_arg3, Word isc_arg4, PXSQLDA isc_arg5);

typedef int __stdcall (*Tisc_embed_dsql_open2)(Ibexternals::PISC_STATUS status_vector, PISC_TR_HANDLE 
	tran_handle, char * isc_arg3, Word isc_arg4, PXSQLDA isc_arg5, PXSQLDA isc_arg6);

typedef int __stdcall (*Tisc_embed_dsql_insert)(Ibexternals::PISC_STATUS status_vector, char * isc_arg2
	, Word isc_arg3, PXSQLDA isc_arg4);

typedef int __stdcall (*Tisc_embed_dsql_prepare)(Ibexternals::PISC_STATUS status_vector, PISC_DB_HANDLE 
	db_handle, PISC_TR_HANDLE tran_handle, char * isc_arg4, Word isc_arg5, char * isc_arg6, Word isc_arg7
	, PXSQLDA isc_arg8);

typedef int __stdcall (*Tisc_embed_dsql_release)(Ibexternals::PISC_STATUS status_vector, char * isc_arg2
	);

typedef PBSTREAM __stdcall (*TBLOB_open)(Ibexternals::PVoid blob_handle, char * isc_arg2, int isc_arg3
	);

typedef int __stdcall (*TBLOB_put)(char isc_arg1, PBSTREAM isc_arg2);

typedef int __stdcall (*TBLOB_close)(PBSTREAM isc_arg1);

typedef int __stdcall (*TBLOB_get)(PBSTREAM isc_arg1);

typedef int __stdcall (*TBLOB_display)(PISC_QUAD isc_arg1, Ibexternals::PVoid db_handle, Ibexternals::PVoid 
	tran_handle, char * isc_arg4);

typedef int __stdcall (*TBLOB_dump)(PISC_QUAD isc_arg1, Ibexternals::PVoid db_handle, Ibexternals::PVoid 
	tran_handle, char * isc_arg4);

typedef int __stdcall (*TBLOB_edit)(PISC_QUAD isc_arg1, Ibexternals::PVoid db_handle, Ibexternals::PVoid 
	tran_handle, char * isc_arg4);

typedef int __stdcall (*TBLOB_load)(PISC_QUAD isc_arg1, Ibexternals::PVoid db_handle, Ibexternals::PVoid 
	tran_handle, char * isc_arg4);

typedef int __stdcall (*TBLOB_text_dump)(PISC_QUAD isc_arg1, Ibexternals::PVoid db_handle, Ibexternals::PVoid 
	tran_handle, char * isc_arg4);

typedef int __stdcall (*TBLOB_text_load)(PISC_QUAD isc_arg1, Ibexternals::PVoid db_handle, Ibexternals::PVoid 
	tran_handle, char * isc_arg4);

typedef int __stdcall (*TBopen)(PISC_QUAD isc_arg1, Ibexternals::PVoid db_handle, Ibexternals::PVoid 
	tran_handle, char * isc_arg4);

typedef PBSTREAM __stdcall (*TBopen2)(PISC_QUAD isc_arg1, Ibexternals::PVoid db_handle, Ibexternals::PVoid 
	tran_handle, char * isc_arg4, Word isc_arg5);

typedef int __stdcall (*Tisc_ftof)(char * isc_arg1, Word isc_arg2, char * isc_arg3, Word isc_arg4);

typedef int __stdcall (*Tisc_print_blr)(char * isc_arg1, TISC_CALLBACK isc_arg2, Ibexternals::PVoid 
	isc_arg3, short isc_arg4);

typedef void __stdcall (*Tisc_set_debug)(int isc_arg1);

typedef void __stdcall (*Tisc_qtoq)(PISC_QUAD isc_arg1, PISC_QUAD isc_arg2);

typedef void __stdcall (*Tisc_vtof)(char * isc_arg1, char * isc_arg2, Word isc_arg3);

typedef void __stdcall (*Tisc_vtov)(char * isc_arg1, char * isc_arg2, short isc_arg3);

typedef int __stdcall (*Tisc_version)(PISC_DB_HANDLE db_handle, TISC_CALLBACK isc_arg2, Ibexternals::PVoid 
	isc_arg3);

typedef int __stdcall (*Tisc_reset_fpe)(Word isc_arg1);

typedef int __stdcall (*Tisc_service_attach)(Ibexternals::PISC_STATUS status_vector, Word isc_arg2, 
	char * isc_arg3, PISC_SVC_HANDLE service_handle, Word isc_arg5, char * isc_arg6);

typedef int __stdcall (*Tisc_service_detach)(Ibexternals::PISC_STATUS status_vector, PISC_SVC_HANDLE 
	service_handle);

typedef int __stdcall (*Tisc_service_query)(Ibexternals::PISC_STATUS status_vector, PISC_SVC_HANDLE 
	service_handle, PISC_SVC_HANDLE recv_handle, Word isc_arg4, char * isc_arg5, Word isc_arg6, char * 
	isc_arg7, Word isc_arg8, char * isc_arg9);

typedef int __stdcall (*Tisc_service_start)(Ibexternals::PISC_STATUS status_vector, PISC_SVC_HANDLE 
	service_handle, PISC_SVC_HANDLE recv_handle, Word isc_arg4, char * isc_arg5);

typedef int __stdcall (*Tisc_compile_map)(Ibexternals::PISC_STATUS status_vector, PISC_FORM_HANDLE form_handle
	, PISC_REQ_HANDLE request_handle, Ibexternals::PShort isc_arg4, char * isc_arg5);

typedef int __stdcall (*Tisc_compile_menu)(Ibexternals::PISC_STATUS status_vector, PISC_FORM_HANDLE 
	form_handle, PISC_REQ_HANDLE request_handle, Ibexternals::PShort isc_arg4, char * isc_arg5);

typedef int __stdcall (*Tisc_compile_sub_map)(Ibexternals::PISC_STATUS status_vector, PISC_WIN_HANDLE 
	win_handle, PISC_REQ_HANDLE request_handle, Ibexternals::PShort isc_arg4, char * isc_arg5);

typedef int __stdcall (*Tisc_create_window)(Ibexternals::PISC_STATUS status_vector, PISC_WIN_HANDLE 
	win_handle, Ibexternals::PShort isc_arg3, char * isc_arg4, Ibexternals::PShort isc_arg5, Ibexternals::PShort 
	isc_arg6);

typedef int __stdcall (*Tisc_delete_window)(Ibexternals::PISC_STATUS status_vector, PISC_WIN_HANDLE 
	win_handle);

typedef int __stdcall (*Tisc_drive_form)(Ibexternals::PISC_STATUS status_vector, PISC_DB_HANDLE db_handle
	, PISC_TR_HANDLE tran_handle, PISC_WIN_HANDLE win_handle, PISC_REQ_HANDLE request_handle, Ibexternals::PUChar 
	isc_arg6, Ibexternals::PUChar isc_arg7);

typedef int __stdcall (*Tisc_drive_menu)(Ibexternals::PISC_STATUS status_vector, PISC_WIN_HANDLE win_handle
	, PISC_REQ_HANDLE request_handle, Ibexternals::PShort isc_arg4, char * isc_arg5, Ibexternals::PShort 
	isc_arg6, char * isc_arg7, Ibexternals::PShort isc_arg8, Ibexternals::PShort isc_arg9, char * isc_arg10
	, Ibexternals::PISC_LONG isc_arg11);

typedef int __stdcall (*Tisc_form_delete)(Ibexternals::PISC_STATUS status_vector, PISC_FORM_HANDLE form_handle
	);

typedef int __stdcall (*Tisc_form_fetch)(Ibexternals::PISC_STATUS status_vector, PISC_DB_HANDLE db_handle
	, PISC_TR_HANDLE tran_handle, PISC_REQ_HANDLE request_handle, Ibexternals::PUChar isc_arg5);

typedef int __stdcall (*Tisc_form_insert)(Ibexternals::PISC_STATUS status_vector, PISC_DB_HANDLE db_handle
	, PISC_TR_HANDLE tran_handle, PISC_REQ_HANDLE request_handle, Ibexternals::PUChar isc_arg5);

typedef int __stdcall (*Tisc_get_entree)(Ibexternals::PISC_STATUS status_vector, PISC_REQ_HANDLE request_handle
	, Ibexternals::PShort isc_arg3, char * isc_arg4, Ibexternals::PISC_LONG isc_arg5, Ibexternals::PShort 
	isc_arg6);

typedef int __stdcall (*Tisc_initialize_menu)(Ibexternals::PISC_STATUS status_vector, PISC_REQ_HANDLE 
	request_handle);

typedef int __stdcall (*Tisc_menu)(Ibexternals::PISC_STATUS status_vector, PISC_WIN_HANDLE win_handle
	, PISC_REQ_HANDLE request_handle, Ibexternals::PShort isc_arg4, char * isc_arg5);

typedef int __stdcall (*Tisc_load_form)(Ibexternals::PISC_STATUS status_vector, PISC_DB_HANDLE db_handle
	, PISC_TR_HANDLE tran_handle, PISC_FORM_HANDLE form_handle, Ibexternals::PShort isc_arg5, char * isc_arg6
	);

typedef int __stdcall (*Tisc_pop_window)(Ibexternals::PISC_STATUS status_vector, PISC_WIN_HANDLE win_handle
	);

typedef int __stdcall (*Tisc_put_entree)(Ibexternals::PISC_STATUS status_vector, PISC_REQ_HANDLE request_handle
	, Ibexternals::PShort isc_arg3, char * isc_arg4, Ibexternals::PISC_LONG isc_arg5);

typedef int __stdcall (*Tisc_reset_form)(Ibexternals::PISC_STATUS status_vector, PISC_REQ_HANDLE request_handle
	);

typedef int __stdcall (*Tisc_suspend_window)(Ibexternals::PISC_STATUS status_vector, PISC_WIN_HANDLE 
	win_handle);

//-- var, const, procedure ---------------------------------------------------
static const Shortint ISC_TRUE = 0x1;
static const Shortint ISC_FALSE = 0x0;
static const Shortint DSQL_close = 0x1;
static const Shortint DSQL_drop = 0x2;
#define IBASE_DLL "gds32.dll"
static const Shortint SQLDA_VERSION1 = 0x1;
static const Shortint SQLDA_VERSION2 = 0x2;
static const Shortint SQL_DIALECT_V5 = 0x1;
static const Shortint SQL_DIALECT_V6_TRANSITION = 0x2;
static const Shortint SQL_DIALECT_V6 = 0x3;
static const Shortint SQL_DIALECT_CURRENT = 0x3;
static const Word TIME_SECONDS_PRECISION = 0x2710;
static const Shortint TIME_SECONDS_PRECISION_SCALE = 0xfffffffc;
static const Shortint sec_uid_spec = 0x1;
static const Shortint sec_gid_spec = 0x2;
static const Shortint sec_server_spec = 0x4;
static const Shortint sec_password_spec = 0x8;
static const Shortint sec_group_name_spec = 0x10;
static const Shortint sec_first_name_spec = 0x20;
static const Shortint sec_middle_name_spec = 0x40;
static const Byte sec_last_name_spec = 0x80;
static const Word sec_dba_user_name_spec = 0x100;
static const Word sec_dba_password_spec = 0x200;
static const Shortint sec_protocol_tcpip = 0x1;
static const Shortint sec_protocol_netbeui = 0x2;
static const Shortint sec_protocol_spx = 0x3;
static const Shortint sec_protocol_local = 0x4;
static const Shortint isc_blob_filter_open = 0x0;
static const Shortint isc_blob_filter_get_segment = 0x1;
static const Shortint isc_blob_filter_close = 0x2;
static const Shortint isc_blob_filter_create = 0x3;
static const Shortint isc_blob_filter_put_segment = 0x4;
static const Shortint isc_blob_filter_alloc = 0x5;
static const Shortint isc_blob_filter_free = 0x6;
static const Shortint isc_blob_filter_seek = 0x7;
static const Shortint blr_text = 0xe;
static const Shortint blr_text2 = 0xf;
static const Shortint blr_short = 0x7;
static const Shortint blr_long = 0x8;
static const Shortint blr_quad = 0x9;
static const Shortint blr_float = 0xa;
static const Shortint blr_double = 0x1b;
static const Shortint blr_d_float = 0xb;
static const Shortint blr_timestamp = 0x23;
static const Shortint blr_varying = 0x25;
static const Shortint blr_varying2 = 0x26;
static const Word blr_blob = 0x105;
static const Shortint blr_cstring = 0x28;
static const Shortint blr_cstring2 = 0x29;
static const Shortint blr_blob_id = 0x2d;
static const Shortint blr_sql_date = 0xc;
static const Shortint blr_sql_time = 0xd;
static const Shortint blr_int64 = 0x10;
static const Shortint blr_date = 0x23;
static const Shortint blr_inner = 0x0;
static const Shortint blr_left = 0x1;
static const Shortint blr_right = 0x2;
static const Shortint blr_full = 0x3;
static const Shortint blr_gds_code = 0x0;
static const Shortint blr_sql_code = 0x1;
static const Shortint blr_exception = 0x2;
static const Shortint blr_trigger_code = 0x3;
static const Shortint blr_default_code = 0x4;
static const Shortint blr_version4 = 0x4;
static const Shortint blr_version5 = 0x5;
static const Shortint blr_eoc = 0x4c;
static const Shortint blr_end = 0xffffffff;
static const Shortint blr_assignment = 0x1;
static const Shortint blr_begin = 0x2;
static const Shortint blr_dcl_variable = 0x3;
static const Shortint blr_message = 0x4;
static const Shortint blr_erase = 0x5;
static const Shortint blr_fetch = 0x6;
static const Shortint blr_for = 0x7;
static const Shortint blr_if = 0x8;
static const Shortint blr_loop = 0x9;
static const Shortint blr_modify = 0xa;
static const Shortint blr_handler = 0xb;
static const Shortint blr_receive = 0xc;
static const Shortint blr_select = 0xd;
static const Shortint blr_send = 0xe;
static const Shortint blr_store = 0xf;
static const Shortint blr_label = 0x11;
static const Shortint blr_leave = 0x12;
static const Shortint blr_store2 = 0x13;
static const Shortint blr_post = 0x14;
static const Shortint blr_literal = 0x15;
static const Shortint blr_dbkey = 0x16;
static const Shortint blr_field = 0x17;
static const Shortint blr_fid = 0x18;
static const Shortint blr_parameter = 0x19;
static const Shortint blr_variable = 0x1a;
static const Shortint blr_average = 0x1b;
static const Shortint blr_count = 0x1c;
static const Shortint blr_maximum = 0x1d;
static const Shortint blr_minimum = 0x1e;
static const Shortint blr_total = 0x1f;
static const Shortint blr_add = 0x22;
static const Shortint blr_subtract = 0x23;
static const Shortint blr_multiply = 0x24;
static const Shortint blr_divide = 0x25;
static const Shortint blr_negate = 0x26;
static const Shortint blr_concatenate = 0x27;
static const Shortint blr_substring = 0x28;
static const Shortint blr_parameter2 = 0x29;
static const Shortint blr_from = 0x2a;
static const Shortint blr_via = 0x2b;
static const Shortint blr_user_name = 0x2c;
static const Shortint blr_null = 0x2d;
static const Shortint blr_eql = 0x2f;
static const Shortint blr_neq = 0x30;
static const Shortint blr_gtr = 0x31;
static const Shortint blr_geq = 0x32;
static const Shortint blr_lss = 0x33;
static const Shortint blr_leq = 0x34;
static const Shortint blr_containing = 0x35;
static const Shortint blr_matching = 0x36;
static const Shortint blr_starting = 0x37;
static const Shortint blr_between = 0x38;
static const Shortint blr_or = 0x39;
static const Shortint blr_and = 0x3a;
static const Shortint blr_not = 0x3b;
static const Shortint blr_any = 0x3c;
static const Shortint blr_missing = 0x3d;
static const Shortint blr_unique = 0x3e;
static const Shortint blr_like = 0x3f;
static const Shortint blr_stream = 0x41;
static const Shortint blr_set_index = 0x42;
static const Shortint blr_rse = 0x43;
static const Shortint blr_first = 0x44;
static const Shortint blr_project = 0x45;
static const Shortint blr_sort = 0x46;
static const Shortint blr_boolean = 0x47;
static const Shortint blr_ascending = 0x48;
static const Shortint blr_descending = 0x49;
static const Shortint blr_relation = 0x4a;
static const Shortint blr_rid = 0x4b;
static const Shortint blr_union = 0x4c;
static const Shortint blr_map = 0x4d;
static const Shortint blr_group_by = 0x4e;
static const Shortint blr_aggregate = 0x4f;
static const Shortint blr_join_type = 0x50;
static const Shortint blr_agg_count = 0x53;
static const Shortint blr_agg_max = 0x54;
static const Shortint blr_agg_min = 0x55;
static const Shortint blr_agg_total = 0x56;
static const Shortint blr_agg_average = 0x57;
static const Shortint blr_parameter3 = 0x58;
static const Shortint blr_run_count = 0x76;
static const Shortint blr_run_max = 0x59;
static const Shortint blr_run_min = 0x5a;
static const Shortint blr_run_total = 0x5b;
static const Shortint blr_run_average = 0x5c;
static const Shortint blr_agg_count2 = 0x5d;
static const Shortint blr_agg_count_distinct = 0x5e;
static const Shortint blr_agg_total_distinct = 0x5f;
static const Shortint blr_agg_average_distinct = 0x60;
static const Shortint blr_function = 0x64;
static const Shortint blr_gen_id = 0x65;
static const Shortint blr_prot_mask = 0x66;
static const Shortint blr_upcase = 0x67;
static const Shortint blr_lock_state = 0x68;
static const Shortint blr_value_if = 0x69;
static const Shortint blr_matching2 = 0x6a;
static const Shortint blr_index = 0x6b;
static const Shortint blr_ansi_like = 0x6c;
static const Shortint blr_bookmark = 0x6d;
static const Shortint blr_crack = 0x6e;
static const Shortint blr_force_crack = 0x6f;
static const Shortint blr_seek = 0x70;
static const Shortint blr_find = 0x71;
static const Shortint blr_continue = 0x0;
static const Shortint blr_forward = 0x1;
static const Shortint blr_backward = 0x2;
static const Shortint blr_bof_forward = 0x3;
static const Shortint blr_eof_backward = 0x4;
static const Shortint blr_lock_relation = 0x72;
static const Shortint blr_lock_record = 0x73;
static const Shortint blr_set_bookmark = 0x74;
static const Shortint blr_get_bookmark = 0x75;
static const Shortint blr_rs_stream = 0x77;
static const Shortint blr_exec_proc = 0x78;
static const Shortint blr_begin_range = 0x79;
static const Shortint blr_end_range = 0x7a;
static const Shortint blr_delete_range = 0x7b;
static const Shortint blr_procedure = 0x7c;
static const Shortint blr_pid = 0x7d;
static const Shortint blr_exec_pid = 0x7e;
static const Shortint blr_singular = 0x7f;
static const Byte blr_abort = 0x80;
static const Byte blr_block = 0x81;
static const Byte blr_error_handler = 0x82;
static const Byte blr_cast = 0x83;
static const Byte blr_release_lock = 0x84;
static const Byte blr_release_locks = 0x85;
static const Byte blr_start_savepoint = 0x86;
static const Byte blr_end_savepoint = 0x87;
static const Byte blr_find_dbkey = 0x88;
static const Byte blr_range_relation = 0x89;
static const Byte blr_delete_ranges = 0x8a;
static const Byte blr_plan = 0x8b;
static const Byte blr_merge = 0x8c;
static const Byte blr_join = 0x8d;
static const Byte blr_sequential = 0x8e;
static const Byte blr_navigational = 0x8f;
static const Byte blr_indices = 0x90;
static const Byte blr_retrieve = 0x91;
static const Byte blr_relation2 = 0x92;
static const Byte blr_rid2 = 0x93;
static const Byte blr_reset_stream = 0x94;
static const Byte blr_release_bookmark = 0x95;
static const Byte blr_set_generator = 0x96;
static const Byte blr_ansi_any = 0x97;
static const Byte blr_exists = 0x98;
static const Byte blr_cardinality = 0x99;
static const Byte blr_record_version = 0x9a;
static const Byte blr_stall = 0x9b;
static const Byte blr_seek_no_warn = 0x9c;
static const Byte blr_find_dbkey_version = 0x9d;
static const Byte blr_ansi_all = 0x9e;
static const Byte blr_extract = 0x9f;
static const Shortint blr_extract_year = 0x0;
static const Shortint blr_extract_month = 0x1;
static const Shortint blr_extract_day = 0x2;
static const Shortint blr_extract_hour = 0x3;
static const Shortint blr_extract_minute = 0x4;
static const Shortint blr_extract_second = 0x5;
static const Shortint blr_extract_weekday = 0x6;
static const Shortint blr_extract_yearday = 0x7;
static const Byte blr_current_date = 0xa0;
static const Byte blr_current_timestamp = 0xa1;
static const Byte blr_current_time = 0xa2;
static const Byte blr_add2 = 0xa3;
static const Byte blr_subtract2 = 0xa4;
static const Byte blr_multiply2 = 0xa5;
static const Byte blr_divide2 = 0xa6;
static const Byte blr_agg_total2 = 0xa7;
static const Byte blr_agg_total_distinct2 = 0xa8;
static const Byte blr_agg_average2 = 0xa9;
static const Byte blr_agg_average_distinct2 = 0xaa;
static const Byte blr_average2 = 0xab;
static const Byte blr_gen_id2 = 0xac;
static const Byte blr_set_generator2 = 0xad;
static const Shortint isc_dpb_version1 = 0x1;
static const Shortint isc_dpb_cdd_pathname = 0x1;
static const Shortint isc_dpb_allocation = 0x2;
static const Shortint isc_dpb_journal = 0x3;
static const Shortint isc_dpb_page_size = 0x4;
static const Shortint isc_dpb_num_buffers = 0x5;
static const Shortint isc_dpb_buffer_length = 0x6;
static const Shortint isc_dpb_debug = 0x7;
static const Shortint isc_dpb_garbage_collect = 0x8;
static const Shortint isc_dpb_verify = 0x9;
static const Shortint isc_dpb_sweep = 0xa;
static const Shortint isc_dpb_enable_journal = 0xb;
static const Shortint isc_dpb_disable_journal = 0xc;
static const Shortint isc_dpb_dbkey_scope = 0xd;
static const Shortint isc_dpb_number_of_users = 0xe;
static const Shortint isc_dpb_trace = 0xf;
static const Shortint isc_dpb_no_garbage_collect = 0x10;
static const Shortint isc_dpb_damaged = 0x11;
static const Shortint isc_dpb_license = 0x12;
static const Shortint isc_dpb_sys_user_name = 0x13;
static const Shortint isc_dpb_encrypt_key = 0x14;
static const Shortint isc_dpb_activate_shadow = 0x15;
static const Shortint isc_dpb_sweep_interval = 0x16;
static const Shortint isc_dpb_delete_shadow = 0x17;
static const Shortint isc_dpb_force_write = 0x18;
static const Shortint isc_dpb_begin_log = 0x19;
static const Shortint isc_dpb_quit_log = 0x1a;
static const Shortint isc_dpb_no_reserve = 0x1b;
static const Shortint isc_dpb_user_name = 0x1c;
static const Shortint isc_dpb_password = 0x1d;
static const Shortint isc_dpb_password_enc = 0x1e;
static const Shortint isc_dpb_sys_user_name_enc = 0x1f;
static const Shortint isc_dpb_interp = 0x20;
static const Shortint isc_dpb_online_dump = 0x21;
static const Shortint isc_dpb_old_file_size = 0x22;
static const Shortint isc_dpb_old_num_files = 0x23;
static const Shortint isc_dpb_old_file = 0x24;
static const Shortint isc_dpb_old_start_page = 0x25;
static const Shortint isc_dpb_old_start_seqno = 0x26;
static const Shortint isc_dpb_old_start_file = 0x27;
static const Shortint isc_dpb_drop_walfile = 0x28;
static const Shortint isc_dpb_old_dump_id = 0x29;
static const Shortint isc_dpb_wal_backup_dir = 0x2a;
static const Shortint isc_dpb_wal_chkptlen = 0x2b;
static const Shortint isc_dpb_wal_numbufs = 0x2c;
static const Shortint isc_dpb_wal_bufsize = 0x2d;
static const Shortint isc_dpb_wal_grp_cmt_wait = 0x2e;
static const Shortint isc_dpb_lc_messages = 0x2f;
static const Shortint isc_dpb_lc_ctype = 0x30;
static const Shortint isc_dpb_cache_manager = 0x31;
static const Shortint isc_dpb_shutdown = 0x32;
static const Shortint isc_dpb_online = 0x33;
static const Shortint isc_dpb_shutdown_delay = 0x34;
static const Shortint isc_dpb_reserved = 0x35;
static const Shortint isc_dpb_overwrite = 0x36;
static const Shortint isc_dpb_sec_attach = 0x37;
static const Shortint isc_dpb_disable_wal = 0x38;
static const Shortint isc_dpb_connect_timeout = 0x39;
static const Shortint isc_dpb_dummy_packet_interval = 0x3a;
static const Shortint isc_dpb_gbak_attach = 0x3b;
static const Shortint isc_dpb_sql_role_name = 0x3c;
static const Shortint isc_dpb_set_page_buffers = 0x3d;
static const Shortint isc_dpb_working_directory = 0x3e;
static const Shortint isc_dpb_SQL_dialect = 0x3f;
static const Shortint isc_dpb_set_db_readonly = 0x40;
static const Shortint isc_dpb_set_db_SQL_dialect = 0x41;
static const Shortint isc_dpb_gfix_attach = 0x42;
static const Shortint isc_dpb_gstat_attach = 0x43;
static const Shortint isc_dpb_last_dpb_constant = 0x43;
static const Shortint isc_dpb_pages = 0x1;
static const Shortint isc_dpb_records = 0x2;
static const Shortint isc_dpb_indices = 0x4;
static const Shortint isc_dpb_transactions = 0x8;
static const Shortint isc_dpb_no_update = 0x10;
static const Shortint isc_dpb_repair = 0x20;
static const Shortint isc_dpb_ignore = 0x40;
static const Shortint isc_dpb_shut_cache = 0x1;
static const Shortint isc_dpb_shut_attachment = 0x2;
static const Shortint isc_dpb_shut_transaction = 0x4;
static const Shortint isc_dpb_shut_force = 0x8;
static const Shortint RDB_system = 0x1;
static const Shortint RDB_id_assigned = 0x2;
static const Shortint isc_tpb_version1 = 0x1;
static const Shortint isc_tpb_version3 = 0x3;
static const Shortint isc_tpb_consistency = 0x1;
static const Shortint isc_tpb_concurrency = 0x2;
static const Shortint isc_tpb_shared = 0x3;
static const Shortint isc_tpb_protected = 0x4;
static const Shortint isc_tpb_exclusive = 0x5;
static const Shortint isc_tpb_wait = 0x6;
static const Shortint isc_tpb_nowait = 0x7;
static const Shortint isc_tpb_read = 0x8;
static const Shortint isc_tpb_write = 0x9;
static const Shortint isc_tpb_lock_read = 0xa;
static const Shortint isc_tpb_lock_write = 0xb;
static const Shortint isc_tpb_verb_time = 0xc;
static const Shortint isc_tpb_commit_time = 0xd;
static const Shortint isc_tpb_ignore_limbo = 0xe;
static const Shortint isc_tpb_read_committed = 0xf;
static const Shortint isc_tpb_autocommit = 0x10;
static const Shortint isc_tpb_rec_version = 0x11;
static const Shortint isc_tpb_no_rec_version = 0x12;
static const Shortint isc_tpb_restart_requests = 0x13;
static const Shortint isc_tpb_no_auto_undo = 0x14;
static const Shortint isc_tpb_last_tpb_constant = 0x14;
static const Shortint isc_bpb_version1 = 0x1;
static const Shortint isc_bpb_source_type = 0x1;
static const Shortint isc_bpb_target_type = 0x2;
static const Shortint isc_bpb_type = 0x3;
static const Shortint isc_bpb_source_interp = 0x4;
static const Shortint isc_bpb_target_interp = 0x5;
static const Shortint isc_bpb_filter_parameter = 0x6;
static const Shortint isc_bpb_type_segmented = 0x0;
static const Shortint isc_bpb_type_stream = 0x1;
static const Shortint isc_spb_user_name = 0x1;
static const Shortint isc_spb_sys_user_name = 0x2;
static const Shortint isc_spb_sys_user_name_enc = 0x3;
static const Shortint isc_spb_password = 0x4;
static const Shortint isc_spb_password_enc = 0x5;
static const Shortint isc_spb_command_line = 0x6;
static const Shortint isc_spb_dbname = 0x7;
static const Shortint isc_spb_verbose = 0x8;
static const Shortint isc_spb_options = 0x9;
static const Shortint isc_spb_connect_timeout = 0xa;
static const Shortint isc_spb_dummy_packet_interval = 0xb;
static const Shortint isc_spb_sql_role_name = 0xc;
static const Shortint isc_spb_last_spb_constant = 0xc;
static const Shortint isc_spb_version1 = 0x1;
static const Shortint isc_spb_current_version = 0x2;
static const Shortint isc_spb_version = 0x2;
static const Shortint isc_spb_user_name_mapped_to_server = 0x1c;
static const Shortint isc_spb_sys_user_name_mapped_to_server = 0x13;
static const Shortint isc_spb_sys_user_name_enc_mapped_to_server = 0x1f;
static const Shortint isc_spb_password_mapped_to_server = 0x1d;
static const Shortint isc_spb_password_enc_mapped_to_server = 0x1e;
static const Shortint isc_spb_command_line_mapped_to_server = 0x69;
static const Shortint isc_spb_dbname_mapped_to_server = 0x6a;
static const Shortint isc_spb_verbose_mapped_to_server = 0x6b;
static const Shortint isc_spb_options_mapped_to_server = 0x6c;
static const Shortint isc_spb_connect_timeout_mapped_to_server = 0x39;
static const Shortint isc_spb_dummy_packet_interval_mapped_to_server = 0x3a;
static const Shortint isc_spb_sql_role_name_mapped_to_server = 0x3c;
static const Shortint isc_info_end = 0x1;
static const Shortint isc_info_truncated = 0x2;
static const Shortint isc_info_error = 0x3;
static const Shortint isc_info_data_not_ready = 0x4;
static const Shortint isc_info_flag_end = 0x7f;
static const Shortint isc_info_db_id = 0x4;
static const Shortint isc_info_reads = 0x5;
static const Shortint isc_info_writes = 0x6;
static const Shortint isc_info_fetches = 0x7;
static const Shortint isc_info_marks = 0x8;
static const Shortint isc_info_implementation = 0xb;
static const Shortint isc_info_version = 0xc;
static const Shortint isc_info_base_level = 0xd;
static const Shortint isc_info_page_size = 0xe;
static const Shortint isc_info_num_buffers = 0xf;
static const Shortint isc_info_limbo = 0x10;
static const Shortint isc_info_current_memory = 0x11;
static const Shortint isc_info_max_memory = 0x12;
static const Shortint isc_info_window_turns = 0x13;
static const Shortint isc_info_license = 0x14;
static const Shortint isc_info_allocation = 0x15;
static const Shortint isc_info_attachment_id = 0x16;
static const Shortint isc_info_read_seq_count = 0x17;
static const Shortint isc_info_read_idx_count = 0x18;
static const Shortint isc_info_insert_count = 0x19;
static const Shortint isc_info_update_count = 0x1a;
static const Shortint isc_info_delete_count = 0x1b;
static const Shortint isc_info_backout_count = 0x1c;
static const Shortint isc_info_purge_count = 0x1d;
static const Shortint isc_info_expunge_count = 0x1e;
static const Shortint isc_info_sweep_interval = 0x1f;
static const Shortint isc_info_ods_version = 0x20;
static const Shortint isc_info_ods_minor_version = 0x21;
static const Shortint isc_info_no_reserve = 0x22;
static const Shortint isc_info_logfile = 0x23;
static const Shortint isc_info_cur_logfile_name = 0x24;
static const Shortint isc_info_cur_log_part_offset = 0x25;
static const Shortint isc_info_num_wal_buffers = 0x26;
static const Shortint isc_info_wal_buffer_size = 0x27;
static const Shortint isc_info_wal_ckpt_length = 0x28;
static const Shortint isc_info_wal_cur_ckpt_interval = 0x29;
static const Shortint isc_info_wal_prv_ckpt_fname = 0x2a;
static const Shortint isc_info_wal_prv_ckpt_poffset = 0x2b;
static const Shortint isc_info_wal_recv_ckpt_fname = 0x2c;
static const Shortint isc_info_wal_recv_ckpt_poffset = 0x2d;
static const Shortint isc_info_wal_grpc_wait_usecs = 0x2f;
static const Shortint isc_info_wal_num_io = 0x30;
static const Shortint isc_info_wal_avg_io_size = 0x31;
static const Shortint isc_info_wal_num_commits = 0x32;
static const Shortint isc_info_wal_avg_grpc_size = 0x33;
static const Shortint isc_info_forced_writes = 0x34;
static const Shortint isc_info_user_names = 0x35;
static const Shortint isc_info_page_errors = 0x36;
static const Shortint isc_info_record_errors = 0x37;
static const Shortint isc_info_bpage_errors = 0x38;
static const Shortint isc_info_dpage_errors = 0x39;
static const Shortint isc_info_ipage_errors = 0x3a;
static const Shortint isc_info_ppage_errors = 0x3b;
static const Shortint isc_info_tpage_errors = 0x3c;
static const Shortint isc_info_set_page_buffers = 0x3d;
static const Shortint isc_info_db_SQL_dialect = 0x3e;
static const Shortint isc_info_db_read_only = 0x3f;
static const Shortint isc_info_db_size_in_pages = 0x40;
static const Shortint isc_info_db_impl_rdb_vms = 0x1;
static const Shortint isc_info_db_impl_rdb_eln = 0x2;
static const Shortint isc_info_db_impl_rdb_eln_dev = 0x3;
static const Shortint isc_info_db_impl_rdb_vms_y = 0x4;
static const Shortint isc_info_db_impl_rdb_eln_y = 0x5;
static const Shortint isc_info_db_impl_jri = 0x6;
static const Shortint isc_info_db_impl_jsv = 0x7;
static const Shortint isc_info_db_impl_isc_a = 0x19;
static const Shortint isc_info_db_impl_isc_u = 0x1a;
static const Shortint isc_info_db_impl_isc_v = 0x1b;
static const Shortint isc_info_db_impl_isc_s = 0x1c;
static const Shortint isc_info_db_impl_isc_apl_68K = 0x19;
static const Shortint isc_info_db_impl_isc_vax_ultr = 0x1a;
static const Shortint isc_info_db_impl_isc_vms = 0x1b;
static const Shortint isc_info_db_impl_isc_sun_68k = 0x1c;
static const Shortint isc_info_db_impl_isc_os2 = 0x1d;
static const Shortint isc_info_db_impl_isc_sun4 = 0x1e;
static const Shortint isc_info_db_impl_isc_hp_ux = 0x1f;
static const Shortint isc_info_db_impl_isc_sun_386i = 0x20;
static const Shortint isc_info_db_impl_isc_vms_orcl = 0x21;
static const Shortint isc_info_db_impl_isc_mac_aux = 0x22;
static const Shortint isc_info_db_impl_isc_rt_aix = 0x23;
static const Shortint isc_info_db_impl_isc_mips_ult = 0x24;
static const Shortint isc_info_db_impl_isc_xenix = 0x25;
static const Shortint isc_info_db_impl_isc_dg = 0x26;
static const Shortint isc_info_db_impl_isc_hp_mpexl = 0x27;
static const Shortint isc_info_db_impl_isc_hp_ux68K = 0x28;
static const Shortint isc_info_db_impl_isc_sgi = 0x29;
static const Shortint isc_info_db_impl_isc_sco_unix = 0x2a;
static const Shortint isc_info_db_impl_isc_cray = 0x2b;
static const Shortint isc_info_db_impl_isc_imp = 0x2c;
static const Shortint isc_info_db_impl_isc_delta = 0x2d;
static const Shortint isc_info_db_impl_isc_next = 0x2e;
static const Shortint isc_info_db_impl_isc_dos = 0x2f;
static const Shortint isc_info_db_impl_isc_winnt = 0x30;
static const Shortint isc_info_db_impl_isc_epson = 0x31;
static const Shortint isc_info_db_class_access = 0x1;
static const Shortint isc_info_db_class_y_valve = 0x2;
static const Shortint isc_info_db_class_rem_int = 0x3;
static const Shortint isc_info_db_class_rem_srvr = 0x4;
static const Shortint isc_info_db_class_pipe_int = 0x7;
static const Shortint isc_info_db_class_pipe_srvr = 0x8;
static const Shortint isc_info_db_class_sam_int = 0x9;
static const Shortint isc_info_db_class_sam_srvr = 0xa;
static const Shortint isc_info_db_class_gateway = 0xb;
static const Shortint isc_info_db_class_cache = 0xc;
static const Shortint isc_info_number_messages = 0x4;
static const Shortint isc_info_max_message = 0x5;
static const Shortint isc_info_max_send = 0x6;
static const Shortint isc_info_max_receive = 0x7;
static const Shortint isc_info_state = 0x8;
static const Shortint isc_info_message_number = 0x9;
static const Shortint isc_info_message_size = 0xa;
static const Shortint isc_info_request_cost = 0xb;
static const Shortint isc_info_access_path = 0xc;
static const Shortint isc_info_req_select_count = 0xd;
static const Shortint isc_info_req_insert_count = 0xe;
static const Shortint isc_info_req_update_count = 0xf;
static const Shortint isc_info_req_delete_count = 0x10;
static const Shortint isc_info_rsb_end = 0x0;
static const Shortint isc_info_rsb_begin = 0x1;
static const Shortint isc_info_rsb_type = 0x2;
static const Shortint isc_info_rsb_relation = 0x3;
static const Shortint isc_info_rsb_plan = 0x4;
static const Shortint isc_info_rsb_unknown = 0x1;
static const Shortint isc_info_rsb_indexed = 0x2;
static const Shortint isc_info_rsb_navigate = 0x3;
static const Shortint isc_info_rsb_sequential = 0x4;
static const Shortint isc_info_rsb_cross = 0x5;
static const Shortint isc_info_rsb_sort = 0x6;
static const Shortint isc_info_rsb_first = 0x7;
static const Shortint isc_info_rsb_boolean = 0x8;
static const Shortint isc_info_rsb_union = 0x9;
static const Shortint isc_info_rsb_aggregate = 0xa;
static const Shortint isc_info_rsb_merge = 0xb;
static const Shortint isc_info_rsb_ext_sequential = 0xc;
static const Shortint isc_info_rsb_ext_indexed = 0xd;
static const Shortint isc_info_rsb_ext_dbkey = 0xe;
static const Shortint isc_info_rsb_left_cross = 0xf;
static const Shortint isc_info_rsb_select = 0x10;
static const Shortint isc_info_rsb_sql_join = 0x11;
static const Shortint isc_info_rsb_simulate = 0x12;
static const Shortint isc_info_rsb_sim_cross = 0x13;
static const Shortint isc_info_rsb_once = 0x14;
static const Shortint isc_info_rsb_procedure = 0x15;
static const Shortint isc_info_rsb_and = 0x1;
static const Shortint isc_info_rsb_or = 0x2;
static const Shortint isc_info_rsb_dbkey = 0x3;
static const Shortint isc_info_rsb_index = 0x4;
static const Shortint isc_info_req_active = 0x2;
static const Shortint isc_info_req_inactive = 0x3;
static const Shortint isc_info_req_send = 0x4;
static const Shortint isc_info_req_receive = 0x5;
static const Shortint isc_info_req_select = 0x6;
static const Shortint isc_info_req_sql_stall = 0x7;
static const Shortint isc_info_blob_num_segments = 0x4;
static const Shortint isc_info_blob_max_segment = 0x5;
static const Shortint isc_info_blob_total_length = 0x6;
static const Shortint isc_info_blob_type = 0x7;
static const Shortint isc_info_tra_id = 0x4;
static const Shortint isc_action_svc_backup = 0x1;
static const Shortint isc_action_svc_restore = 0x2;
static const Shortint isc_action_svc_repair = 0x3;
static const Shortint isc_action_svc_add_user = 0x4;
static const Shortint isc_action_svc_delete_user = 0x5;
static const Shortint isc_action_svc_modify_user = 0x6;
static const Shortint isc_action_svc_display_user = 0x7;
static const Shortint isc_action_svc_properties = 0x8;
static const Shortint isc_action_svc_add_license = 0x9;
static const Shortint isc_action_svc_remove_license = 0xa;
static const Shortint isc_action_svc_db_stats = 0xb;
static const Shortint isc_action_svc_get_ib_log = 0xc;
static const Shortint isc_info_svc_svr_db_info = 0x32;
static const Shortint isc_info_svc_get_license = 0x33;
static const Shortint isc_info_svc_get_license_mask = 0x34;
static const Shortint isc_info_svc_get_config = 0x35;
static const Shortint isc_info_svc_version = 0x36;
static const Shortint isc_info_svc_server_version = 0x37;
static const Shortint isc_info_svc_implementation = 0x38;
static const Shortint isc_info_svc_capabilities = 0x39;
static const Shortint isc_info_svc_user_dbpath = 0x3a;
static const Shortint isc_info_svc_get_env = 0x3b;
static const Shortint isc_info_svc_get_env_lock = 0x3c;
static const Shortint isc_info_svc_get_env_msg = 0x3d;
static const Shortint isc_info_svc_line = 0x3e;
static const Shortint isc_info_svc_to_eof = 0x3f;
static const Shortint isc_info_svc_timeout = 0x40;
static const Shortint isc_info_svc_get_licensed_users = 0x41;
static const Shortint isc_info_svc_limbo_trans = 0x42;
static const Shortint isc_info_svc_running = 0x43;
static const Shortint isc_info_svc_get_users = 0x44;
static const Shortint isc_spb_sec_userid = 0x5;
static const Shortint isc_spb_sec_groupid = 0x6;
static const Shortint isc_spb_sec_username = 0x7;
static const Shortint isc_spb_sec_password = 0x8;
static const Shortint isc_spb_sec_groupname = 0x9;
static const Shortint isc_spb_sec_firstname = 0xa;
static const Shortint isc_spb_sec_middlename = 0xb;
static const Shortint isc_spb_sec_lastname = 0xc;
static const Shortint isc_spb_lic_key = 0x5;
static const Shortint isc_spb_lic_id = 0x6;
static const Shortint isc_spb_bkp_file = 0x5;
static const Shortint isc_spb_bkp_factor = 0x6;
static const Shortint isc_spb_bkp_length = 0x7;
static const Shortint isc_spb_bkp_ignore_checksums = 0x1;
static const Shortint isc_spb_bkp_ignore_limbo = 0x2;
static const Shortint isc_spb_bkp_metadata_only = 0x4;
static const Shortint isc_spb_bkp_no_garbage_collect = 0x8;
static const Shortint isc_spb_bkp_old_descriptions = 0x10;
static const Shortint isc_spb_bkp_non_transportable = 0x20;
static const Shortint isc_spb_bkp_convert = 0x40;
static const Shortint isc_spb_lck_sample = 0x5;
static const Shortint isc_spb_lck_secs = 0x6;
static const Shortint isc_spb_lck_contents = 0x1;
static const Shortint isc_spb_lck_summary = 0x2;
static const Shortint isc_spb_lck_wait = 0x4;
static const Shortint isc_spb_lck_stats = 0x8;
static const Shortint isc_spb_prp_page_buffers = 0x5;
static const Shortint isc_spb_prp_sweep_interval = 0x6;
static const Shortint isc_spb_prp_shutdown_db = 0x7;
static const Shortint isc_spb_prp_deny_new_attachments = 0x9;
static const Shortint isc_spb_prp_deny_new_transactions = 0xa;
static const Shortint isc_spb_prp_reserve_space = 0xb;
static const Shortint isc_spb_prp_write_mode = 0xc;
static const Shortint isc_spb_prp_access_mode = 0xd;
static const Shortint isc_spb_prp_set_sql_dialect = 0xe;
static const Word isc_spb_prp_activate = 0x100;
static const Word isc_spb_prp_db_online = 0x200;
static const Shortint isc_spb_prp_res_use_full = 0x23;
static const Shortint isc_spb_prp_res = 0x24;
static const Shortint isc_spb_prp_wm_async = 0x25;
static const Shortint isc_spb_prp_wm_sync = 0x26;
static const Shortint isc_spb_prp_am_readonly = 0x27;
static const Shortint isc_spb_prp_am_readwrite = 0x28;
static const Shortint isc_spb_rpr_commit_trans = 0xf;
static const Shortint isc_spb_rpr_rollback_trans = 0x22;
static const Shortint isc_spb_rpr_recover_two_phase = 0x11;
static const Shortint isc_spb_tra_id = 0x12;
static const Shortint isc_spb_single_tra_id = 0x13;
static const Shortint isc_spb_multi_tra_id = 0x14;
static const Shortint isc_spb_tra_state = 0x15;
static const Shortint isc_spb_tra_state_limbo = 0x16;
static const Shortint isc_spb_tra_state_commit = 0x17;
static const Shortint isc_spb_tra_state_rollback = 0x18;
static const Shortint isc_spb_tra_state_unknown = 0x19;
static const Shortint isc_spb_tra_host_site = 0x1a;
static const Shortint isc_spb_tra_remote_site = 0x1b;
static const Shortint isc_spb_tra_db_path = 0x1c;
static const Shortint isc_spb_tra_advise = 0x1d;
static const Shortint isc_spb_tra_advise_commit = 0x1e;
static const Shortint isc_spb_tra_advise_rollback = 0x1f;
static const Shortint isc_spb_tra_advise_unknown = 0x21;
static const Shortint isc_spb_rpr_list_limbo_trans = 0x1;
static const Shortint isc_spb_rpr_check_db = 0x2;
static const Shortint isc_spb_rpr_ignore_checksum = 0x4;
static const Shortint isc_spb_rpr_kill_shadows = 0x8;
static const Shortint isc_spb_rpr_mend_db = 0x10;
static const Shortint isc_spb_rpr_sweep_db = 0x20;
static const Shortint isc_spb_rpr_validate_db = 0x40;
static const Byte isc_spb_rpr_full = 0x80;
static const Shortint isc_spb_res_buffers = 0x9;
static const Shortint isc_spb_res_page_size = 0xa;
static const Shortint isc_spb_res_length = 0xb;
static const Shortint isc_spb_res_access_mode = 0xc;
static const Word isc_spb_res_deactivate_idx = 0x100;
static const Word isc_spb_res_no_shadow = 0x200;
static const Word isc_spb_res_no_validity = 0x400;
static const Word isc_spb_res_one_ata_time = 0x800;
static const Word isc_spb_res_replace = 0x1000;
static const Word isc_spb_res_create = 0x2000;
static const Word isc_spb_res_use_all_space = 0x4000;
static const Shortint isc_spb_res_am_readonly = 0x27;
static const Shortint isc_spb_res_am_readwrite = 0x28;
static const Shortint isc_spb_num_att = 0x5;
static const Shortint isc_spb_num_db = 0x6;
static const Shortint isc_spb_sts_data_pages = 0x1;
static const Shortint isc_spb_sts_db_log = 0x2;
static const Shortint isc_spb_sts_hdr_pages = 0x4;
static const Shortint isc_spb_sts_idx_pages = 0x8;
static const Shortint isc_spb_sts_sys_relations = 0x10;
static const Shortint isc_info_sql_select = 0x4;
static const Shortint isc_info_sql_bind = 0x5;
static const Shortint isc_info_sql_num_variables = 0x6;
static const Shortint isc_info_sql_describe_vars = 0x7;
static const Shortint isc_info_sql_describe_end = 0x8;
static const Shortint isc_info_sql_sqlda_seq = 0x9;
static const Shortint isc_info_sql_message_seq = 0xa;
static const Shortint isc_info_sql_type = 0xb;
static const Shortint isc_info_sql_sub_type = 0xc;
static const Shortint isc_info_sql_scale = 0xd;
static const Shortint isc_info_sql_length = 0xe;
static const Shortint isc_info_sql_null_ind = 0xf;
static const Shortint isc_info_sql_field = 0x10;
static const Shortint isc_info_sql_relation = 0x11;
static const Shortint isc_info_sql_owner = 0x12;
static const Shortint isc_info_sql_alias = 0x13;
static const Shortint isc_info_sql_sqlda_start = 0x14;
static const Shortint isc_info_sql_stmt_type = 0x15;
static const Shortint isc_info_sql_get_plan = 0x16;
static const Shortint isc_info_sql_records = 0x17;
static const Shortint isc_info_sql_batch_fetch = 0x18;
static const Shortint isc_info_sql_stmt_select = 0x1;
static const Shortint isc_info_sql_stmt_insert = 0x2;
static const Shortint isc_info_sql_stmt_update = 0x3;
static const Shortint isc_info_sql_stmt_delete = 0x4;
static const Shortint isc_info_sql_stmt_ddl = 0x5;
static const Shortint isc_info_sql_stmt_get_segment = 0x6;
static const Shortint isc_info_sql_stmt_put_segment = 0x7;
static const Shortint isc_info_sql_stmt_exec_procedure = 0x8;
static const Shortint isc_info_sql_stmt_start_trans = 0x9;
static const Shortint isc_info_sql_stmt_commit = 0xa;
static const Shortint isc_info_sql_stmt_rollback = 0xb;
static const Shortint isc_info_sql_stmt_select_for_upd = 0xc;
static const Shortint isc_info_sql_stmt_set_generator = 0xd;
static const Shortint ISCCFG_LOCKMEM_KEY = 0x0;
static const Shortint ISCCFG_LOCKSEM_KEY = 0x1;
static const Shortint ISCCFG_LOCKSIG_KEY = 0x2;
static const Shortint ISCCFG_EVNTMEM_KEY = 0x3;
static const Shortint ISCCFG_DBCACHE_KEY = 0x4;
static const Shortint ISCCFG_PRIORITY_KEY = 0x5;
static const Shortint ISCCFG_IPCMAP_KEY = 0x6;
static const Shortint ISCCFG_MEMMIN_KEY = 0x7;
static const Shortint ISCCFG_MEMMAX_KEY = 0x8;
static const Shortint ISCCFG_LOCKORDER_KEY = 0x9;
static const Shortint ISCCFG_ANYLOCKMEM_KEY = 0xa;
static const Shortint ISCCFG_ANYLOCKSEM_KEY = 0xb;
static const Shortint ISCCFG_ANYLOCKSIG_KEY = 0xc;
static const Shortint ISCCFG_ANYEVNTMEM_KEY = 0xd;
static const Shortint ISCCFG_LOCKHASH_KEY = 0xe;
static const Shortint ISCCFG_DEADLOCK_KEY = 0xf;
static const Shortint ISCCFG_LOCKSPIN_KEY = 0x10;
static const Shortint ISCCFG_CONN_TIMEOUT_KEY = 0x11;
static const Shortint ISCCFG_DUMMY_INTRVL_KEY = 0x12;
static const Shortint isc_facility = 0x14;
static const int isc_err_base = 0x14000000;
static const Shortint isc_err_factor = 0x1;
static const Shortint isc_arg_end = 0x0;
static const Shortint isc_arg_gds = 0x1;
static const Shortint isc_arg_string = 0x2;
static const Shortint isc_arg_cstring = 0x3;
static const Shortint isc_arg_number = 0x4;
static const Shortint isc_arg_interpreted = 0x5;
static const Shortint isc_arg_vms = 0x6;
static const Shortint isc_arg_unix = 0x7;
static const Shortint isc_arg_domain = 0x8;
static const Shortint isc_arg_dos = 0x9;
static const Shortint isc_arg_mpexl = 0xa;
static const Shortint isc_arg_mpexl_ipc = 0xb;
static const Shortint isc_arg_next_mach = 0xf;
static const Shortint isc_arg_netware = 0x10;
static const Shortint isc_arg_win32 = 0x11;
static const Shortint isc_arg_warning = 0x12;
static const Shortint isc_dyn_version_1 = 0x1;
static const Shortint isc_dyn_eoc = 0xffffffff;
static const Shortint isc_dyn_begin = 0x2;
static const Shortint isc_dyn_end = 0x3;
static const Shortint isc_dyn_if = 0x4;
static const Shortint isc_dyn_def_database = 0x5;
static const Shortint isc_dyn_def_global_fld = 0x6;
static const Shortint isc_dyn_def_local_fld = 0x7;
static const Shortint isc_dyn_def_idx = 0x8;
static const Shortint isc_dyn_def_rel = 0x9;
static const Shortint isc_dyn_def_sql_fld = 0xa;
static const Shortint isc_dyn_def_view = 0xc;
static const Shortint isc_dyn_def_trigger = 0xf;
static const Shortint isc_dyn_def_security_class = 0x78;
static const Byte isc_dyn_def_dimension = 0x8c;
static const Shortint isc_dyn_def_generator = 0x18;
static const Shortint isc_dyn_def_function = 0x19;
static const Shortint isc_dyn_def_filter = 0x1a;
static const Shortint isc_dyn_def_function_arg = 0x1b;
static const Shortint isc_dyn_def_shadow = 0x22;
static const Shortint isc_dyn_def_trigger_msg = 0x11;
static const Shortint isc_dyn_def_file = 0x24;
static const Shortint isc_dyn_mod_database = 0x27;
static const Shortint isc_dyn_mod_rel = 0xb;
static const Shortint isc_dyn_mod_global_fld = 0xd;
static const Shortint isc_dyn_mod_idx = 0x66;
static const Shortint isc_dyn_mod_local_fld = 0xe;
static const Byte isc_dyn_mod_sql_fld = 0xd8;
static const Shortint isc_dyn_mod_view = 0x10;
static const Shortint isc_dyn_mod_security_class = 0x7a;
static const Shortint isc_dyn_mod_trigger = 0x71;
static const Shortint isc_dyn_mod_trigger_msg = 0x1c;
static const Shortint isc_dyn_delete_database = 0x12;
static const Shortint isc_dyn_delete_rel = 0x13;
static const Shortint isc_dyn_delete_global_fld = 0x14;
static const Shortint isc_dyn_delete_local_fld = 0x15;
static const Shortint isc_dyn_delete_idx = 0x16;
static const Shortint isc_dyn_delete_security_class = 0x7b;
static const Byte isc_dyn_delete_dimensions = 0x8f;
static const Shortint isc_dyn_delete_trigger = 0x17;
static const Shortint isc_dyn_delete_trigger_msg = 0x1d;
static const Shortint isc_dyn_delete_filter = 0x20;
static const Shortint isc_dyn_delete_function = 0x21;
static const Shortint isc_dyn_delete_shadow = 0x23;
static const Shortint isc_dyn_grant = 0x1e;
static const Shortint isc_dyn_revoke = 0x1f;
static const Shortint isc_dyn_def_primary_key = 0x25;
static const Shortint isc_dyn_def_foreign_key = 0x26;
static const Shortint isc_dyn_def_unique = 0x28;
static const Byte isc_dyn_def_procedure = 0xa4;
static const Byte isc_dyn_delete_procedure = 0xa5;
static const Byte isc_dyn_def_parameter = 0x87;
static const Byte isc_dyn_delete_parameter = 0x88;
static const Byte isc_dyn_mod_procedure = 0xaf;
static const Byte isc_dyn_def_log_file = 0xb0;
static const Byte isc_dyn_def_cache_file = 0xb4;
static const Byte isc_dyn_def_exception = 0xb5;
static const Byte isc_dyn_mod_exception = 0xb6;
static const Byte isc_dyn_del_exception = 0xb7;
static const Byte isc_dyn_drop_log = 0xc2;
static const Byte isc_dyn_drop_cache = 0xc3;
static const Byte isc_dyn_def_default_log = 0xca;
static const Shortint isc_dyn_view_blr = 0x2b;
static const Shortint isc_dyn_view_source = 0x2c;
static const Shortint isc_dyn_view_relation = 0x2d;
static const Shortint isc_dyn_view_context = 0x2e;
static const Shortint isc_dyn_view_context_name = 0x2f;
static const Shortint isc_dyn_rel_name = 0x32;
static const Shortint isc_dyn_fld_name = 0x33;
static const Byte isc_dyn_new_fld_name = 0xd7;
static const Shortint isc_dyn_idx_name = 0x34;
static const Shortint isc_dyn_description = 0x35;
static const Shortint isc_dyn_security_class = 0x36;
static const Shortint isc_dyn_system_flag = 0x37;
static const Shortint isc_dyn_update_flag = 0x38;
static const Byte isc_dyn_prc_name = 0xa6;
static const Byte isc_dyn_prm_name = 0x89;
static const Byte isc_dyn_sql_object = 0xc4;
static const Byte isc_dyn_fld_character_set_name = 0xae;
static const Shortint isc_dyn_rel_dbkey_length = 0x3d;
static const Shortint isc_dyn_rel_store_trig = 0x3e;
static const Shortint isc_dyn_rel_modify_trig = 0x3f;
static const Shortint isc_dyn_rel_erase_trig = 0x40;
static const Shortint isc_dyn_rel_store_trig_source = 0x41;
static const Shortint isc_dyn_rel_modify_trig_source = 0x42;
static const Shortint isc_dyn_rel_erase_trig_source = 0x43;
static const Shortint isc_dyn_rel_ext_file = 0x44;
static const Shortint isc_dyn_rel_sql_protection = 0x45;
static const Byte isc_dyn_rel_constraint = 0xa2;
static const Byte isc_dyn_delete_rel_constraint = 0xa3;
static const Shortint isc_dyn_fld_type = 0x46;
static const Shortint isc_dyn_fld_length = 0x47;
static const Shortint isc_dyn_fld_scale = 0x48;
static const Shortint isc_dyn_fld_sub_type = 0x49;
static const Shortint isc_dyn_fld_segment_length = 0x4a;
static const Shortint isc_dyn_fld_query_header = 0x4b;
static const Shortint isc_dyn_fld_edit_string = 0x4c;
static const Shortint isc_dyn_fld_validation_blr = 0x4d;
static const Shortint isc_dyn_fld_validation_source = 0x4e;
static const Shortint isc_dyn_fld_computed_blr = 0x4f;
static const Shortint isc_dyn_fld_computed_source = 0x50;
static const Shortint isc_dyn_fld_missing_value = 0x51;
static const Shortint isc_dyn_fld_default_value = 0x52;
static const Shortint isc_dyn_fld_query_name = 0x53;
static const Shortint isc_dyn_fld_dimensions = 0x54;
static const Shortint isc_dyn_fld_not_null = 0x55;
static const Shortint isc_dyn_fld_precision = 0x56;
static const Byte isc_dyn_fld_char_length = 0xac;
static const Byte isc_dyn_fld_collation = 0xad;
static const Byte isc_dyn_fld_default_source = 0xc1;
static const Byte isc_dyn_del_default = 0xc5;
static const Byte isc_dyn_del_validation = 0xc6;
static const Byte isc_dyn_single_validation = 0xc7;
static const Byte isc_dyn_fld_character_set = 0xcb;
static const Shortint isc_dyn_fld_source = 0x5a;
static const Shortint isc_dyn_fld_base_fld = 0x5b;
static const Shortint isc_dyn_fld_position = 0x5c;
static const Shortint isc_dyn_fld_update_flag = 0x5d;
static const Shortint isc_dyn_idx_unique = 0x64;
static const Shortint isc_dyn_idx_inactive = 0x65;
static const Shortint isc_dyn_idx_type = 0x67;
static const Shortint isc_dyn_idx_foreign_key = 0x68;
static const Shortint isc_dyn_idx_ref_column = 0x69;
static const Byte isc_dyn_idx_statistic = 0xcc;
static const Shortint isc_dyn_trg_type = 0x6e;
static const Shortint isc_dyn_trg_blr = 0x6f;
static const Shortint isc_dyn_trg_source = 0x70;
static const Shortint isc_dyn_trg_name = 0x72;
static const Shortint isc_dyn_trg_sequence = 0x73;
static const Shortint isc_dyn_trg_inactive = 0x74;
static const Shortint isc_dyn_trg_msg_number = 0x75;
static const Shortint isc_dyn_trg_msg = 0x76;
static const Shortint isc_dyn_scl_acl = 0x79;
static const Byte isc_dyn_grant_user = 0x82;
static const Byte isc_dyn_grant_proc = 0xba;
static const Byte isc_dyn_grant_trig = 0xbb;
static const Byte isc_dyn_grant_view = 0xbc;
static const Byte isc_dyn_grant_options = 0x84;
static const Byte isc_dyn_grant_user_group = 0xcd;
static const Byte isc_dyn_dim_lower = 0x8d;
static const Byte isc_dyn_dim_upper = 0x8e;
static const Shortint isc_dyn_file_name = 0x7d;
static const Shortint isc_dyn_file_start = 0x7e;
static const Shortint isc_dyn_file_length = 0x7f;
static const Byte isc_dyn_shadow_number = 0x80;
static const Byte isc_dyn_shadow_man_auto = 0x81;
static const Byte isc_dyn_shadow_conditional = 0x82;
static const Byte isc_dyn_log_file_sequence = 0xb1;
static const Byte isc_dyn_log_file_partitions = 0xb2;
static const Byte isc_dyn_log_file_serial = 0xb3;
static const Byte isc_dyn_log_file_overflow = 0xc8;
static const Byte isc_dyn_log_file_raw = 0xc9;
static const Byte isc_dyn_log_group_commit_wait = 0xbd;
static const Byte isc_dyn_log_buffer_size = 0xbe;
static const Byte isc_dyn_log_check_point_length = 0xbf;
static const Byte isc_dyn_log_num_of_buffers = 0xc0;
static const Byte isc_dyn_function_name = 0x91;
static const Byte isc_dyn_function_type = 0x92;
static const Byte isc_dyn_func_module_name = 0x93;
static const Byte isc_dyn_func_entry_point = 0x94;
static const Byte isc_dyn_func_return_argument = 0x95;
static const Byte isc_dyn_func_arg_position = 0x96;
static const Byte isc_dyn_func_mechanism = 0x97;
static const Byte isc_dyn_filter_in_subtype = 0x98;
static const Byte isc_dyn_filter_out_subtype = 0x99;
static const Byte isc_dyn_description2 = 0x9a;
static const Byte isc_dyn_fld_computed_source2 = 0x9b;
static const Byte isc_dyn_fld_edit_string2 = 0x9c;
static const Byte isc_dyn_fld_query_header2 = 0x9d;
static const Byte isc_dyn_fld_validation_source2 = 0x9e;
static const Byte isc_dyn_trg_msg2 = 0x9f;
static const Byte isc_dyn_trg_source2 = 0xa0;
static const Byte isc_dyn_view_source2 = 0xa1;
static const Byte isc_dyn_xcp_msg2 = 0xb8;
static const Shortint isc_dyn_generator_name = 0x5f;
static const Shortint isc_dyn_generator_id = 0x60;
static const Byte isc_dyn_prc_inputs = 0xa7;
static const Byte isc_dyn_prc_outputs = 0xa8;
static const Byte isc_dyn_prc_source = 0xa9;
static const Byte isc_dyn_prc_blr = 0xaa;
static const Byte isc_dyn_prc_source2 = 0xab;
static const Byte isc_dyn_prm_number = 0x8a;
static const Byte isc_dyn_prm_type = 0x8b;
static const Byte isc_dyn_xcp_msg = 0xb9;
static const Byte isc_dyn_foreign_key_update = 0xcd;
static const Byte isc_dyn_foreign_key_delete = 0xce;
static const Byte isc_dyn_foreign_key_cascade = 0xcf;
static const Byte isc_dyn_foreign_key_default = 0xd0;
static const Byte isc_dyn_foreign_key_null = 0xd1;
static const Byte isc_dyn_foreign_key_none = 0xd2;
static const Byte isc_dyn_def_sql_role = 0xd3;
static const Byte isc_dyn_sql_role_name = 0xd4;
static const Byte isc_dyn_grant_admin_options = 0xd5;
static const Byte isc_dyn_del_sql_role = 0xd6;
static const Byte isc_dyn_last_dyn_value = 0xd8;
static const Shortint isc_sdl_version1 = 0x1;
static const Shortint isc_sdl_eoc = 0xffffffff;
static const Shortint isc_sdl_relation = 0x2;
static const Shortint isc_sdl_rid = 0x3;
static const Shortint isc_sdl_field = 0x4;
static const Shortint isc_sdl_fid = 0x5;
static const Shortint isc_sdl_struct = 0x6;
static const Shortint isc_sdl_variable = 0x7;
static const Shortint isc_sdl_scalar = 0x8;
static const Shortint isc_sdl_tiny_integer = 0x9;
static const Shortint isc_sdl_short_integer = 0xa;
static const Shortint isc_sdl_long_integer = 0xb;
static const Shortint isc_sdl_literal = 0xc;
static const Shortint isc_sdl_add = 0xd;
static const Shortint isc_sdl_subtract = 0xe;
static const Shortint isc_sdl_multiply = 0xf;
static const Shortint isc_sdl_divide = 0x10;
static const Shortint isc_sdl_negate = 0x11;
static const Shortint isc_sdl_eql = 0x12;
static const Shortint isc_sdl_neq = 0x13;
static const Shortint isc_sdl_gtr = 0x14;
static const Shortint isc_sdl_geq = 0x15;
static const Shortint isc_sdl_lss = 0x16;
static const Shortint isc_sdl_leq = 0x17;
static const Shortint isc_sdl_and = 0x18;
static const Shortint isc_sdl_or = 0x19;
static const Shortint isc_sdl_not = 0x1a;
static const Shortint isc_sdl_while = 0x1b;
static const Shortint isc_sdl_assignment = 0x1c;
static const Shortint isc_sdl_label = 0x1d;
static const Shortint isc_sdl_leave = 0x1e;
static const Shortint isc_sdl_begin = 0x1f;
static const Shortint isc_sdl_end = 0x20;
static const Shortint isc_sdl_do3 = 0x21;
static const Shortint isc_sdl_do2 = 0x22;
static const Shortint isc_sdl_do1 = 0x23;
static const Shortint isc_sdl_element = 0x24;
static const Shortint isc_interp_eng_ascii = 0x0;
static const Shortint isc_interp_jpn_sjis = 0x5;
static const Shortint isc_interp_jpn_euc = 0x6;
static const Shortint isc_fetch_next = 0x0;
static const Shortint isc_fetch_prior = 0x1;
static const Shortint isc_fetch_first = 0x2;
static const Shortint isc_fetch_last = 0x3;
static const Shortint isc_fetch_absolute = 0x4;
static const Shortint isc_fetch_relative = 0x5;
static const Word SQL_VARYING = 0x1c0;
static const Word SQL_TEXT = 0x1c4;
static const Word SQL_DOUBLE = 0x1e0;
static const Word SQL_FLOAT = 0x1e2;
static const Word SQL_LONG = 0x1f0;
static const Word SQL_SHORT = 0x1f4;
static const Word SQL_TIMESTAMP = 0x1fe;
static const Word SQL_BLOB = 0x208;
static const Word SQL_D_FLOAT = 0x212;
static const Word SQL_ARRAY = 0x21c;
static const Word SQL_QUAD = 0x226;
static const Word SQL_TYPE_TIME = 0x230;
static const Word SQL_TYPE_DATE = 0x23a;
static const Word SQL_INT64 = 0x244;
static const Word SQL_DATE = 0x1fe;
static const Shortint isc_blob_untyped = 0x0;
static const Shortint isc_blob_text = 0x1;
static const Shortint isc_blob_blr = 0x2;
static const Shortint isc_blob_acl = 0x3;
static const Shortint isc_blob_ranges = 0x4;
static const Shortint isc_blob_summary = 0x5;
static const Shortint isc_blob_format = 0x6;
static const Shortint isc_blob_tra = 0x7;
static const Shortint isc_blob_extfile = 0x8;
static const Shortint isc_blob_formatted_memo = 0x14;
static const Shortint isc_blob_paradox_ole = 0x15;
static const Shortint isc_blob_graphic = 0x16;
static const Shortint isc_blob_dbase_ole = 0x17;
static const Shortint isc_blob_typed_binary = 0x18;
extern PACKAGE int __fastcall XSQLDA_LENGTH(int n);
extern PACKAGE char __fastcall getb(PBSTREAM p);
extern PACKAGE int __fastcall putb(char x, PBSTREAM p);
extern PACKAGE int __fastcall putbx(char x, PBSTREAM p);
extern PACKAGE void __fastcall add_spb_length(char * &p, int length);
extern PACKAGE void __fastcall add_spb_numeric(char * &p, int data);

}	/* namespace Ibheader */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Ibheader;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IBHeader
