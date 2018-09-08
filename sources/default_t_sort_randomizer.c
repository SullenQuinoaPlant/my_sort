/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_t_sort_randomizer.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 12:28:47 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/08 12:30:29 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inner.h"

size_t					def_rander(
	size_t in)
{
	size_t	out;

	out = h_djb2a((char*)&in, sizeof(size_t));
	return (out);
}
