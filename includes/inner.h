/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inner.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 11:43:49 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/09 08:24:02 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INNER_H
# define INNER_H

# include <stdlib.h>
# include "libft.h"
# include "libmyhash.h"
# include "mysort.h" 

typedef enum			e_more_or_less {
	e_less,
	e_more,
	e_mol_sz
}						t_e_mol;

size_t					def_rander(
	size_t		in);

void					swap(
	void		*a,
	void		*b,
	void		*buf,
	size_t		sz);

#endif
