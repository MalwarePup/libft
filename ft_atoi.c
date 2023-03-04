/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 23:32:40 by ladloff           #+#    #+#             */
/*   Updated: 2022/10/30 09:06:43 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		res;
	int		sign;

	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -sign;
	res = 0;
	while (ft_isdigit(*str))
		res = res * 10 + *str++ - 48;
	return (sign * res);
}
