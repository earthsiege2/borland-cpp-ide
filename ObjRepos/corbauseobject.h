[!outputon] // $Revision:   1.1  $
[!if=(Property, "TRUE")
[!if=(Requesting, "GetMethod")]
	[!InterfaceName]_ptr __fastcall Get[!BaseName]();
[!else]
[!if=(Requesting, "SetMethod")]
	void __fastcall Set[!BaseName]([!InterfaceName]_ptr _ptr);
[!else]
[!if=(Requesting, "InstanceVariable")]
	[!InterfaceName]_var F[!BaseName];
[!endif]	
[!endif]
[!endif]
[!else]
[!if=(Requesting, "GetMethod")]
	[!InterfaceName]_ptr Get[!BaseName]();
[!else]
[!if=(Requesting, "SetMethod")]
	void Set[!BaseName]([!InterfaceName]_ptr _ptr);
[!else]
[!if=(Requesting, "InstanceVariable")]
	[!InterfaceName]_var [!BaseName];
[!endif]
[!endif]
[!endif]
[!endif]
[!if=(Requesting, "ReadOnlyProperty")]
	__property [!InterfaceName]_ptr [!BaseName] = {read=Get[!BaseName]};
[!else]
[!if=(Requesting, "WriteOnlyProperty")]
	__property [!InterfaceName]_ptr [!BaseName] = {write=Set[!BaseName]};
[!else]
[!if=(Requesting, "ReadWriteProperty")]
	__property [!InterfaceName]_ptr [!BaseName] = {read=Get[!BaseName], write=Set[!BaseName]};
[!endif]
[!endif]
[!endif]

