/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 22:25:01 by ladloff           #+#    #+#             */
/*   Updated: 2023/05/07 11:55:49 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/libft.h"

void	*ft_realloc(void *ptr, size_t current_size, size_t new_size)
{
	void	*new_ptr;

	if (ptr == NULL)
		return (malloc(new_size));
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size <= current_size)
		return (ptr);
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	if (ft_memcpy(new_ptr, ptr, current_size) == NULL)
	{
		free(new_ptr);
		return (NULL);
	}
	free(ptr);
	return (new_ptr);
}
