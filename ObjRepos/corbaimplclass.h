[!outputon] // $Revision:   1.1  $
[!if=(Tie, "TRUE")]
class [!ImplClassName]   /* [!SkeletonClassName] [!IdlInterfaceToken] */
{
protected:
public:
	[!ImplClassName]();
};
[!else]
class [!ImplClassName]: public [!SkeletonClassName]
{
protected:
public:
	[!ImplClassName](const char *object_name=NULL);
};
[!endif]

