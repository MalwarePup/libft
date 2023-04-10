/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:07:22 by ladloff           #+#    #+#             */
/*   Updated: 2023/04/06 15:48:16 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# include "libft.h"

typedef struct s_list_gnl
{
	size_t				i;
	char				*buffer;
	ssize_t				read_bytes;
	struct s_list_gnl	*next;
}	t_list_gnl;

/**
 * get_next_line.c
 */
char	*get_next_line(int fd);

#endif
