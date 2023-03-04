/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:21:04 by ladloff           #+#    #+#             */
/*   Updated: 2022/12/27 18:02:00 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_int_to_char(char *str, long nb, int i)
{
	const char	digits[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

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
		str[i--] = digits[nb % 10];
		nb /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		i;
	int		nb;
	char	*str;

	nb = n;
	i = (nb <= 0);
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str = ft_int_to_char(str, n, i);
	return (str);
}
