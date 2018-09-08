/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ar_shfl_ip.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 12:12:28 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/08 12:33:27 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inner.h"

int						sort_ar_shfl_ip(
	t_sort_cmp cmp,
	t_sort_randomizer rander,
	t_s_sort_ard *ar)
{
	void *const		ar = ar->ar;
	size_t const	sz = ar->type_sz;
	size_t const	count = ar->elem_count;
	unsigned char	*b;
	size_t			i;

	if (!(b = malloc(sz)))
		return (SORT_SYS_ERR);
	if (!rander)
		rander = &def_rander;
	i = -1;
	while (++i < count)
		swap(ar + i * sz, ar + (rand(i) % count) * sz, b, sz);
	ft_cleanfree(b);
	sort_ar_shfl_ip(cmp, ar);
}
