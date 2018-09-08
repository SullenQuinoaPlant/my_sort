static void					sort(
	unsigned char *buf,
	t_sort_ard *ar,
	t_sort_cmp cmp)
{
	void			*const stop = ar->ar + ar->elem_count * ar->type_sz;
	void			*const pivot = ar->ar;
	t_s_sort_ard	sub_ars[t_e_mol];
	void			*p;

	pivot = ar->ar;
	sub_ars[e_less] = (t_s_sort_ard){ar->type_sz, 0, pivot + ar->type_sz)
	while (++i < 

}

void						sort_ar_ip(
	t_sort_cmp cmp,
	t_s_sort_ard *ar)
{
}
