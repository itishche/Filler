/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itishche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 15:27:11 by itishche          #+#    #+#             */
/*   Updated: 2018/11/02 13:09:35 by itishche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	int				k;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	k = 0;
	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	while (i < n && k == 0)
	{
		if (s2[i] == (unsigned char)c)
			k = 1;
		s1[i] = s2[i];
		i++;
	}
	if (k == 1)
		return (&s1[i]);
	else
		return (NULL);
}
