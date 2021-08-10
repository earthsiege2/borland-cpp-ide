int	_usefasttls__;

extern	unsigned char	__useDynamicTLS;

static	void	useFastTLS(void)
{
	__useDynamicTLS = 0;
}
#pragma startup	useFastTLS 0 /* Sets the __useDynamicTLS symbol */

