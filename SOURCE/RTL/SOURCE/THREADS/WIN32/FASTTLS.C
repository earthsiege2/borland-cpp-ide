int	_usefasttls__;

extern	int	__useDynamicTLS;

static	void	useFastTLS(void)
{
	__useDynamicTLS = 0;
}
#pragma startup	useFastTLS 0

