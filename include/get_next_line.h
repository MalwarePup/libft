/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:07:22 by ladloff           #+#    #+#             */
/*   Updated: 2024/06/04 11:18:09 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

typedef struct s_gnl
{
	size_t			buffer_index;
	char			*buffer;
	ssize_t			read_bytes;
	struct s_gnl	*next;
}	t_gnl;

/* get_next_line_utils.c */

t_gnl	*free_gnl_node(t_gnl *current);
void	free_gnl_list(t_gnl *list);

/* get_next_line.c */

char	*get_next_line(int fd, bool free_static);

#endif /* GET_NEXT_LINE_H */
