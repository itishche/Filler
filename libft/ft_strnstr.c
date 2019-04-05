/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itishche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 12:30:31 by itishche          #+#    #+#             */
/*   Updated: 2018/11/02 13:17:34 by itishche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strnstr(const char *str, const char *src, size_t len)
{
	unsigned int i;
	unsigned int j;

	j = 0;
	if (ft_strlen(src) == 0)
		return ((char *)str);
	while (str[j] != '\0' && j < len)
	{
		i = 0;
		while (src[i] == str[j + i] && (j + i) < len)
		{
			if (src[i + 1] == '\0')
			{
				return ((char *)&str[j]);
			}
			i++;
		}
		j++;
	}
	return (0);
}
