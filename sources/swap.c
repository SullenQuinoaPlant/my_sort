#include "inner.h"

void			swap(
	void *a,
	void *b,
	void *buff,
	size_t sz)
{
	ft_memcpy(buff, a, sz);
	ft_memcpy(a, b, sz);
	ft_memcpy(b, buff, sz)
}
