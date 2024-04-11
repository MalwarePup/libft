/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:36:34 by ladloff           #+#    #+#             */
/*   Updated: 2024/04/11 14:03:05 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_putchar_fd(char c, int fd)
{
	if (write(fd, &c, sizeof(char)) == -1)
	{
		perror("write (ft_putchar_fd)");
		return (1);
	}
	return (0);
}
