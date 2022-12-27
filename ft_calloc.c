/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:03:59 by ladloff           #+#    #+#             */
/*   Updated: 2022/12/27 18:44:37 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	void	*p;

	if (count == 0 || size == 0)
		return (ft_strdup(""));
	if (count > ULONG_MAX / 2 || size > ULONG_MAX / 2)
		return (NULL);
	total_size = count * size;
	p = malloc(total_size);
		if (!p)
			return (NULL);
	ft_bzero(p, total_size);
	return (p);
}
