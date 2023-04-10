/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:09:24 by ladloff           #+#    #+#             */
/*   Updated: 2023/04/06 17:18:47 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list_gnl	*free_t_lst_gnl(t_list_gnl *lst)
{
	t_list_gnl	*next_node;

	if (!lst)
		return (NULL);
	next_node = lst->next;
	free(lst->buffer);
	free(lst);
	lst = NULL;
	return (next_node);
}

static t_list_gnl	*create_t_list_gnl_node(int fd)
{
	t_list_gnl	*new_node;

	new_node = ft_calloc(1, sizeof(t_list_gnl));
	if (!new_node)
		return (NULL);
	new_node->buffer = ft_calloc(BUFFER_SIZE, sizeof(char));
	if (!new_node->buffer)
	{
		free(new_node);
		return (NULL);
	}
	new_node->read_bytes = read(fd, new_node->buffer, BUFFER_SIZE);
	if (new_node->read_bytes < 0)
	{
		free_t_lst_gnl(new_node);
		return (NULL);
	}
	new_node->i = 0;
	new_node->next = NULL;
	return (new_node);
}

static char	*extract_line(t_list_gnl **lst, size_t line_size)
{
	ssize_t	i;
	char	*line;
	char	*p_line;

	if (!lst || !line_size)
		return (NULL);
	line = ft_calloc((line_size + 1), sizeof(char));
	if (!line)
		return (NULL);
	p_line = line;
	i = (*lst)->i;
	while (line_size--)
	{
		*line++ = (*lst)->buffer[i++];
		if ((*lst)->read_bytes == i)
		{
			*lst = free_t_lst_gnl(*lst);
			i = 0;
		}
	}
	if (*lst)
		(*lst)->i = i;
	return (p_line);
}

static size_t	get_line_size(t_list_gnl *lst, int fd)
{
	ssize_t		i;
	size_t		line_size;
	t_list_gnl	*new_node;

	if (!lst || !lst->buffer)
		return (0);
	line_size = 1;
	i = lst->i;
	while (lst->buffer[i] && lst->buffer[i++] != '\n')
	{
		if (lst->read_bytes == i)
		{
			new_node = create_t_list_gnl_node(fd);
			if (!new_node)
				return (0);
			new_node->next = lst->next;
			lst->next = new_node;
			lst = new_node;
			i = 0;
		}
		line_size++;
	}
	return (line_size);
}

char	*get_next_line(int fd)
{
	char				*line;
	size_t				line_size;
	static t_list_gnl	*lst[FD_SETSIZE];

	if (fd < 0 || fd > FD_SETSIZE)
		return (NULL);
	if (!lst[fd])
		lst[fd] = create_t_list_gnl_node(fd);
	if (!lst[fd])
		return (NULL);
	if (!lst[fd]->read_bytes)
	{
		lst[fd] = free_t_lst_gnl(lst[fd]);
		return (NULL);
	}
	line_size = get_line_size(lst[fd], fd);
	if (!line_size)
		return (NULL);
	line = extract_line(&lst[fd], line_size);
	return (line);
}
