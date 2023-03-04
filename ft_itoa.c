/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:21:04 by ladloff           #+#    #+#             */
/*   Updated: 2022/10/29 19:20:24 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_len(int n)
{
	size_t	len;

	len = (n <= 0);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_int_to_char(char *str, long nb, size_t i)
{
	str[i--] = '\0';
	if (nb == 0)
	{
		str[0] = 48;
		return (str);
	}
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		str[i--] = 48 + (nb % 10);
		nb /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	size_t	i;
	long	nb;
	char	*str;

	nb = n;
	i = ft_get_len(n);
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str = ft_int_to_char(str, nb, i);
	return (str);
}
