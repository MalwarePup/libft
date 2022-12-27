/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 20:23:49 by ladloff           #+#    #+#             */
/*   Updated: 2022/12/27 18:01:44 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_int_to_char(char *str, unsigned int nb, int i)
{
	const char	digits[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

	str[i--] = '\0';
	if (nb == 0)
	{
		str[0] = 48;
		return (str);
	}
	while (nb > 0)
	{
		str[i--] = digits[nb % 10];
		nb /= 10;
	}
	return (str);
}

char	*ft_uitoa(unsigned int n)
{
	int				i;
	unsigned int	nb;
	char			*str;

	i = 0;
	nb = n;
	while (nb > 0)
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
