/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmyhash.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 08:42:50 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/07 08:42:51 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMYHASH_H
# define LIBMYHASH_H

# include <stddef.h>

size_t
	h_djb2(
		char const *val, size_t len);

size_t
	h_djb2_str(
		char const *str);

size_t
	h_djb2a(
		char const *val, size_t len);

size_t
	h_djb2a_str(
		char const *str);

#endif
