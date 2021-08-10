[!outputon] // $Revision:   1.1  $
[!if=(Property, "TRUE")
[!if=(Requesting, "GetMethod")]
[!InterfaceName]_ptr __fastcall [!ImplClassName]::Get[!BaseName](void)
{
	if (F[!BaseName] == NULL)
	{
		F[!BaseName] = [!InterfaceName]::_bind([!ObjectName]);
	}
	return F[!BaseName];
}
[!else]
[!if=(Requesting, "SetMethod")]
void __fastcall [!ImplClassName]::Set[!BaseName]([!InterfaceName]_ptr _ptr)
{
	F[!BaseName] = _ptr;
}
[!endif]
[!endif]
[!else]
[!if=(Requesting, "GetMethod")]
[!InterfaceName]_ptr [!ImplClassName]::Get[!BaseName](void)
{
	if ([!BaseName] == NULL)
	{
		[!BaseName] = [!InterfaceName]::_bind([!ObjectName]);
	}
	return [!BaseName];
}
[!else]
[!if=(Requesting, "SetMethod")]
void [!ImplClassName]::Set[!BaseName]([!InterfaceName]_ptr _ptr)
{
	[!BaseName] = _ptr;
}
[!endif]
[!endif]
[!endif]

