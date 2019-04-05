/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itishche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 14:37:45 by itishche          #+#    #+#             */
/*   Updated: 2018/11/02 11:52:29 by itishche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memset(void *dst, int c, size_t n)
{
	size_t			i;
	unsigned char	*d;

	d = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		d[i] = (unsigned char)c;
		i++;
	}
	return (dst);
}
