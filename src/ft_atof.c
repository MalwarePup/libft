/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 00:06:34 by ladloff           #+#    #+#             */
/*   Updated: 2024/09/10 11:57:26 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <string.h>
#include "libft.h"

static double	handle_exponent(const char *str, double result)
{
	int		exponent;
	int8_t	exp_sign;

	exponent = 0;
	exp_sign = 1;
	if (*str == 'e' || *str == 'E')
	{
		str++;
		if (*str == '-' || *str == '+')
		{
			if (*str++ == '-')
				exp_sign = -1;
		}
		while (*str && *str >= '0' && *str <= '9')
			exponent = exponent * 10 + (*str++ - '0');
		result *= pow(10.0, exp_sign * exponent);
	}
	return (result);
}

static double	parse_fraction(const char **str)
{
	double	factor;
	double	result;

	result = 0.0;
	factor = 1.0;
	if (**str == '.')
	{
		(*str)++;
		while (**str && **str >= '0' && **str <= '9')
		{
			result = result * 10.0 + (**str - '0');
			factor *= 10.0;
			(*str)++;
		}
	}
	return (result / factor);
}

double	ft_atof(const char *str)
{
	double	result;
	int8_t	sign;

	if (!str)
		return (0.0);
	result = 0.0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	if (ft_strcmp(str, "inf") == 0 || ft_strcmp(str, "infinity") == 0)
		return (sign * INFINITY);
	if (ft_strcmp(str, "nan") == 0)
		return (NAN);
	while (*str >= '0' && *str <= '9')
		result = result * 10.0 + (*str++ - '0');
	result += parse_fraction(&str);
	return (handle_exponent(str, result * sign));
}
