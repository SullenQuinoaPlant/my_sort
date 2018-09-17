#include "inner_aux.h"

int
	int_ord(
		void *pa, void *pb)
{
	int		a;
	int		b;

	a = *(int*)pa;
	b = *(int*)pb;
	return (a - b);
}
