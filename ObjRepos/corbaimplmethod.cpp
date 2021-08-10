[!outputon] // $Revision:   1.2  $
[!if=(IsForm, "TRUE")]
[!ReturnType] __fastcall [!ImplClassName]::[!MethodName]([!ParamNames])
[!else]
[!ReturnType] [!ImplClassName]::[!MethodName]([!ParamNames])
[!endif]
[!if=(ReplacingDeclaration, "FALSE")]
{
}
[!endif]
