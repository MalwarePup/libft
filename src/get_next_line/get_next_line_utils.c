/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:12:27 by ladloff           #+#    #+#             */
/*   Updated: 2024/06/04 11:16:26 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl	*free_gnl_node(t_gnl *current)
{
	t_gnl	*next;

	if (!current)
		return (NULL);
	next = current->next;
	free(current->buffer);
	free(current);
	return (next);
}

void	free_gnl_list(t_gnl *list)
{
	while (list)
		list = free_gnl_node(list);
}
