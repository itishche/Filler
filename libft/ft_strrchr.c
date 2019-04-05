/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itishche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 13:43:57 by itishche          #+#    #+#             */
/*   Updated: 2018/11/02 12:01:23 by itishche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static	int	poshuk(const char *str, int symb)
{
	int i;
	int k;

	k = 0;
	i = ft_strlen(str);
	i--;
	while ((k == 0) && (i >= 0))
	{
		if (str[i] == symb)
			k = 1;
		i--;
	}
	return (k);
}

char		*ft_strrchr(const char *str, int symb)
{
	int i;
	int k;

	i = 0;
	if (symb == '\0')
		return ((char *)&str[ft_strlen(str)]);
	k = poshuk(str, symb);
	if (k == 1)
	{
		i = ft_strlen(str);
		i--;
		k = 0;
		while (str[i] != symb)
			i--;
		return ((char *)&str[i]);
	}
	else
		return (0);
}
