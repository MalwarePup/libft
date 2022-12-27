/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 20:23:49 by ladloff           #+#    #+#             */
/*   Updated: 2022/12/27 13:46:51 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa(unsigned int n)
{
	size_t		i;
	char		*str;
	const char	digits[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

	i = 0;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (n == 0)
	{
		str[0] = 48;
		return (str);
	}
	while (n > 0)
	{
		str[i--] = digits[n % 10];
		n /= 10;
	}
	return (str);
}
