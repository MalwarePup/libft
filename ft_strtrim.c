/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:26:41 by ladloff           #+#    #+#             */
/*   Updated: 2022/10/30 15:42:43 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_in_set(const char *set, char c)
{
	size_t	i;

	i = -1;
	while (set[++i])
		if (set[i] == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	len_total;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	i = -1;
	while (s1[++i] && ft_is_in_set(set, s1[i]))
		;
	j = ft_strlen(s1);
	while (i < --j && ft_is_in_set(set, s1[j]))
		;
	str = malloc((j - i + 2) * sizeof(char));
	if (!str)
		return (NULL);
	len_total = (j - i + 1);
	ft_memmove(str, s1 + i, len_total);
	str[len_total] = '\0';
	return (str);
}
