/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itishche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 10:41:10 by itishche          #+#    #+#             */
/*   Updated: 2018/11/06 10:41:12 by itishche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static	int		ftstrlen2(char const *s)
{
	int		i;
	int		k;
	int		len;

	len = ft_strlen(s);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (i == len)
		k = -1;
	else
	{
		k = len - i;
		i = len - 1;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i--;
		k = k - (len - i) + 1;
	}
	return (k);
}

char			*ft_strtrim(char const *s)
{
	char	*ptr;
	int		i;
	int		k;

	if (s != 0)
	{
		k = ftstrlen2(s);
		ptr = (char *)malloc(sizeof(char) * (ftstrlen2(s) + 1));
		if (ptr == 0)
			return (NULL);
		else
		{
			i = 0;
			while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
				i++;
			ptr = ft_strsub(s, i, k);
			i = ft_strlen(ptr) - 1;
			while (ptr[i] == ' ' || ptr[i] == '\n' || ptr[i] == '\t')
				i--;
			ptr[i + 1] = '\0';
			return (ptr);
		}
	}
	else
		return (NULL);
}
