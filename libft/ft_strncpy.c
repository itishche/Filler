/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itishche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 11:04:48 by itishche          #+#    #+#             */
/*   Updated: 2018/10/26 11:13:24 by itishche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	unsigned int i;

	i = 0;
	while ((i < len) && (src[i] != '\0'))
	{
		dst[i] = src[i];
		i++;
	}
	if (i == len - 1)
	{
		dst[i] = '\0';
		return (dst);
	}
	else
	{
		ft_bzero(&dst[i], len - i);
		return (dst);
	}
}
