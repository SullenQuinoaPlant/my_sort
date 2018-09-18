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
	void *const		pivot = ar->last;
	void			*stop;
	void			*p;

	stop = ar->first;
	p = pivot - sz;
	while (p > stop)
		if ((*cmp)(p, pivot) < SORT_EQ)
		{
			ft_memswap(p, stop, buf, sz);
			stop += sz;
		}
		else
			p -= sz;
	if ((*cmp)(p, pivot) < SORT_EQ)
		p += sz;
	else
		ft_memswap(p, pivot, buf, sz);
	if (ar->last - p)
		here_sort(buf, cmp, &(t_s_sort_ard){sz, p, ar->last});
	if (p > ar->first + sz)
		here_sort(buf, cmp, &(t_s_sort_ard){sz, ar->first, p - sz});
}

int							sort_ar_ip(
	t_sort_cmp cmp,
	t_s_sort_ard *ar)
{
	unsigned char	*buf;

	if (!(buf = malloc(ar->type_sz)))
		return (SORT_SYS_ERR);
	here_sort(buf, cmp, ar);
	ft_cleanfree(buf, ar->type_sz);
	return (SORT_SUCCESS);
}
