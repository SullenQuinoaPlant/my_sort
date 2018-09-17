/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmysort.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 11:43:52 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/08 12:28:05 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMYSORT_H
# define LIBMYSORT_H

# include <stddef.h>

/*
** compare *firstarg to *secondarg
** return :
**  < 0 if *firstarg < *secondarg
**  0   if *firstarg = *secondarg
**  > 0 if *firstarg > *secondarg
*/
# define SORT_LT -1
# define SORT_EQ 0
# define SORT_GT 1
typedef int (*t_sort_cmp)(void *, void *);

typedef struct	s_sort_array_description {
	size_t	type_sz;
	size_t	elem_count;
	void	*ar;
}				t_s_sort_ard;

typedef size_t (*t_sort_randomizer)(size_t);

/*
** functions :
*/
/*
** sort array in place
*/
int				sort_ar_ip(
	t_sort_cmp		cmp,
	t_s_sort_ard	*array);

/*
** sort shuffled array in place
*/
int				sort_ar_shfl_ip(
	t_sort_cmp			cmp,
	t_sort_randomizer	rander,
	t_s_sort_ard		*array);

int				sort_intar_ip(
	size_t	ar_sz,
	int		*ar);

/*
** rondomizing function defaults to libmyhash:djb2a
*/
int				sort_intar_ip_shuffle(
	t_sort_randomizer	rander,
	size_t				ar_sz,
	int					*ar);

# define SORT_SYS_ERR -1
# define SORT_SUCCESS 0
#endif
