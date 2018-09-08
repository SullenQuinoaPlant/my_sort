/*
** swaps on less_than to shorten the comparison time (maybe)
**  -> only one bit to check for >= on two's complement machine
*/
static void					sort(
	unsigned char *buf,
	t_sort_ard *ar,
	t_sort_cmp cmp)
{
	size_t const	sz = ar->type_sz;
	void			*const pivot = ar->ar + (ar->elem_count - 1) * sz;
	t_s_sort_ard	sub_ars[t_e_mol];
	void			*stop;
	void			*p;

	stop = ar->ar;
	sub_ars[e_less] = (t_s_sort_ard){sz, 0, stop};
	sum_ars[e_more] = (t_s_sort_ard){sz, 1, pivot};
	p = pivot - sz;
	while (p >= stop)
		if ((*cmp)(p, pivot) < SORT_EQ)
		{
			swap(p, stop, buf, sz);
			stop += sz;
			sub_ars[e_less].elem_count++;
		}
		else
		{
			p -= sz;
			sub_ars[e_more].elem_count++;
		}
}

void						sort_ar_ip(
	t_sort_cmp cmp,
	t_s_sort_ard *ar)
{
}
