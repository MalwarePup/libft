/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:50:26 by ladloff           #+#    #+#             */
/*   Updated: 2024/04/11 14:02:27 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return (1);
	if (write(fd, s, ft_strlen(s)) == -1)
	{
		perror("write (ft_putstr_fd)");
		return (1);
	}
	return (0);
}
