[!outputon] // $Revision:   1.2  $
[!if=(Requesting, "InstantiateTie")]
		[!ImplClassName] [!VariableName];
		[!TieTemplateName]<[!ImplClassName]> tie_[!VariableName]([!VariableName], [!ObjectName]);
		boa->obj_is_ready(&tie_[!VariableName]);
[!else]
[!if=(Requesting, "InstantiateDerived")]
		[!ImplClassName] [!VariableName]([!ObjectName]);
		boa->obj_is_ready(&[!VariableName]);
[!else]
[!if=(Requesting, "InstantiateDataModule")]
		T[!ImplClassName]* [!VariableName] = new T[!ImplClassName](NULL);
		[!TieTemplateName]<T[!ImplClassName]> tie_[!VariableName](*[!VariableName], [!ObjectName], true);
		boa->obj_is_ready(&tie_[!VariableName]);
[!endif]
