/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itishche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 10:29:27 by itishche          #+#    #+#             */
/*   Updated: 2018/11/02 11:36:19 by itishche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_memcmp(const void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	if (n == 0)
		return (0);
	i = 0;
	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	while (s1[i] == s2[i] && i < n - 1)
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
