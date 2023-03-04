/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:03:59 by ladloff           #+#    #+#             */
/*   Updated: 2022/11/17 13:03:36 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	void	*p;

	if (count == 0 || size == 0)
		return (ft_strdup(""));
	total_size = count * size;
	if (count < ULONG_MAX / size)
	{
		p = malloc(total_size);
		if (!p)
			return (NULL);
	}
	else
		return (NULL);
	ft_bzero(p, total_size);
	return (p);
}
/*
int	main(void)
{
	void	*ptr1;
	void	*ptr2;

	printf("\033[0;33m~~~~~~ft_calloc tester~~~~~~\033[0m\n");
	printf("\033[0;36m\t  ladloff\033[0m\n");
	ptr1 = ft_calloc(20, sizeof(char));
	ptr2 = calloc(20, sizeof(char));
	printf("\n\033[0;35m1. light allocation:\033[0m\n");
	printf("ft_calloc: [%p]\ncalloc:    [%p]\n", ptr1, ptr2);
	if (ft_memcmp(ptr1, ptr2, 20 * sizeof(char)) == 0)
		printf("\033[0;32mOK\033[0m\n");
	else
		printf("\033[0;31mOK\033[0m\n");
	ptr1 = ft_calloc(INT_MAX, sizeof(int));
	ptr2 = calloc(INT_MAX, sizeof(int));
	printf("\n\033[0;35m2. large allocation:\033[0m\n");
	printf("ft_calloc: [%p]\ncalloc:    [%p]\n", ptr1, ptr2);
	if (ft_memcmp(ptr1, ptr2, INT_MAX * sizeof(char)) == 0)
		printf("\033[0;32mOK\033[0m\n");
	else
		printf("\033[0;31mOK\033[0m\n");
	ptr1 = ft_calloc(0, sizeof(int));
	ptr2 = calloc(0, sizeof(int));
	printf("\n\033[0;35m3. The 1st parameter is set to 0:\033[0m\n");
	printf("ft_calloc: [%p]\ncalloc:    [%p]\n", ptr1, ptr2);
	if (ft_memcmp(ptr1, ptr2, 2 * sizeof(char)) == 0)
		printf("\033[0;32mOK\033[0m\n");
	else
		printf("\033[0;31mOK\033[0m\n");
	ptr1 = ft_calloc(20, 0);
	ptr2 = calloc(20, 0);
	printf("\n\033[0;35m4. The 2nd parameter 0 is set to 0:\033[0m\n");
	printf("ft_calloc: [%p]\ncalloc:    [%p]\n", ptr1, ptr2);
	if (ft_memcmp(ptr1, ptr2, 2 * sizeof(char)) == 0)
		printf("\033[0;32mOK\033[0m\n");
	else
		printf("\033[0;31mOK\033[0m\n");
	ptr1 = ft_calloc(0, 0);
	ptr2 = calloc(0, 0);
	printf("\n\033[0;35m5. The 2 parameters is set to 0:\033[0m\n");
	printf("ft_calloc: [%p]\ncalloc:    [%p]\n", ptr1, ptr2);
	if (ft_memcmp(ptr1, ptr2, 2 * sizeof(char)) == 0)
		printf("\033[0;32mOK\033[0m\n");
	else
		printf("\033[0;31mOK\033[0m\n");
	ptr1 = ft_calloc(18446744073709551615UL, 18446744073709551615UL);
	ptr2 = calloc(18446744073709551615UL, 18446744073709551615UL);
	printf("\n\033[0;35m6. Overflow size_t test:\033[0m\n");
	printf("ft_calloc: [%p]\ncalloc:    [%p]\n", ptr1, ptr2);
	if (ptr1 == ptr2)
		printf("\033[0;32mOK\033[0m\n");
	else
		printf("\033[0;31mOK\033[0m\n");
	free(ptr1);
	free(ptr2);
	return (0);
}
*/
