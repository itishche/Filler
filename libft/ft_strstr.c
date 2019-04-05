/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itishche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 11:03:12 by itishche          #+#    #+#             */
/*   Updated: 2018/11/02 11:39:44 by itishche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static	char	*poshuk(const char *str, const char *src)
{
	unsigned int i;
	unsigned int j;

	j = 0;
	while (str[j] != '\0')
	{
		i = 0;
		while (src[i] == str[j + i])
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

char			*ft_strstr(const char *str, const char *s2)
{
	if (ft_strlen(s2) == 0)
		return ((char *)str);
	else if (ft_strcmp(str, s2) == 0)
		return ((char *)str);
	else
		return (poshuk(str, s2));
}
