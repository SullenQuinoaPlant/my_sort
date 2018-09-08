/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ar_ip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 11:16:27 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/08 11:23:04 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void					sort_some_more(
	unsigned char *buf,
	t_sort_cmp cmp,
	t_sort_ord ars[])
{
	sort(buf, cmp, &ars[e_more]);
	sort(buf, cmp, &ars[e_less]);
}

/*
** swaps on less_than to shorten the comparison time (maybe)
**  -> only one bit to check for >= on two's complement machine
*/

static void					sort(
	unsigned char *buf,
	t_sort_cmp cmp,
	t_sort_ard *ar)
{
	size_t const	sz = ar->type_sz;
	void *const		pivot = ar->ar + (ar->elem_count - 1) * sz;
	t_s_sort_ard	sub_ars[t_e_mol];
	void			*stop;
	void			*p;

	sub_ars[e_less] = (t_s_sort_ard){sz, 0, ar->ar};
	sum_ars[e_more] = (t_s_sort_ard){sz, ar->elem_count, pivot};
	stop = ar->ar;
	p = pivot - sz;
	while (p > stop)
		if ((*cmp)(p, pivot) < SORT_EQ)
		{
			swap(p, stop, buf, sz);
			sub_ars[e_less].elem_count++;
			stop += sz;
		}
		else
			p -= sz;
	if ((*cmp)(p, pivot) < SORT_EQ)
		small->elem_count++;
	else
		swap(p, pivot, buf, small->type_sz);
	sub_ars[e_more].elem_count -= sub_ars[e_less].elem_count;
	sort_some_more(buf, cmp, sub_ars);
}

void						sort_ar_ip(
	t_sort_cmp cmp,
	t_s_sort_ard *ar)
{
	unsigned char	*buf;

	if ((buf = malloc(ar->type_sz)))
		sort(buf, cmp,  ar);
	else
		return (SORT_SYS_ERR);
	return (SORT_SUCCESS);
}
