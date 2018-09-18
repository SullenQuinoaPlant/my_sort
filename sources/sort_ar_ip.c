/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ar_ip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 11:16:27 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/09 08:19:10 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inner.h"
#include "sort_ar_ip.h"

/*
** ft_memswaps on less_than to shorten the comparison time (maybe)
**  -> only one bit to check for >= on two's complement machine
*/

static void					here_sort(
	unsigned char *buf,
	t_sort_cmp cmp,
	t_s_sort_ard *ar)
{
	size_t const	sz = ar->type_sz;
	void *const		pivot = ar->ar + (ar->elem_count - 1) * sz;
	t_s_sort_ard	sub_ars[e_mol_sz];
	void			*stop;
	void			*p;

	sub_ars[e_less] = (t_s_sort_ard){sz, 0, ar->ar};
	sub_ars[e_more] = (t_s_sort_ard){sz, ar->elem_count, pivot};
	stop = ar->ar;
	p = pivot - sz;
	while (p > stop)
		if ((*cmp)(p, pivot) < SORT_EQ)
		{
			ft_memswap(p, stop, buf, sz);
			sub_ars[e_less].elem_count++;
			stop += sz;
		}
		else
			p -= sz;
	if ((*cmp)(p, pivot) < SORT_EQ)
		sub_ars[e_less].elem_count++;
	else
		ft_memswap(p, pivot, buf, sz);
	sub_ars[e_more].elem_count -= sub_ars[e_less].elem_count;
	sort_some_more(buf, cmp, sub_ars);
}

static void					sort_some_more(
	unsigned char *buf,
	t_sort_cmp cmp,
	t_s_sort_ard ars[])
{
	here_sort(buf, cmp, &ars[e_more]);
	here_sort(buf, cmp, &ars[e_less]);
}

int							sort_ar_ip(
	t_sort_cmp cmp,
	t_s_sort_ard *ar)
{
	size_t const	sz = ar->type_sz;
	unsigned char	*buf;

	if (!(buf = malloc(sz)))
		return (SORT_SYS_ERR);
	here_sort(buf, cmp, ar);
	ft_cleanfree(buf, sz);
	return (SORT_SUCCESS);
}
