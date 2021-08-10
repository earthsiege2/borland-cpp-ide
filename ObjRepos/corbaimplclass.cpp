[!outputon] // $Revision:   1.1  $
[!if=(Tie, "TRUE")]
[!ImplClassName]::[!ImplClassName]()
{
}
[!else]
[!ImplClassName]::[!ImplClassName](const char *object_name):
	[!SkeletonClassName](object_name)                 
{                                   
}                                          
[!endif]

