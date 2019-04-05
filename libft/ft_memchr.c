/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itishche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 15:11:15 by itishche          #+#    #+#             */
/*   Updated: 2018/10/31 14:24:35 by itishche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memchr(const void *str, int val, size_t num)
{
	size_t			i;
	size_t			k;
	unsigned char	*s;

	i = 0;
	k = 0;
	s = (unsigned char *)str;
	while ((k == 0) && i < num)
	{
		if (s[i] == (unsigned char)val)
			k = 1;
		i++;
	}
	if (k == 1)
		return ((void *)&s[i - 1]);
	else
		return (0);
}
