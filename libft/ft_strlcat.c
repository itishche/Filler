/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itishche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 11:37:41 by itishche          #+#    #+#             */
/*   Updated: 2018/10/26 12:29:30 by itishche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t len)
{
	unsigned int i;
	unsigned int j;

	i = ft_strlen(dst);
	j = ft_strlen(src);
	if (i > len)
		return (j + len);
	j = 0;
	while (src[j] != '\0' && (i + j < len - 1))
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	j = ft_strlen(src);
	return (i + j);
}
