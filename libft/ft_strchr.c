/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itishche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 12:31:36 by itishche          #+#    #+#             */
/*   Updated: 2018/11/02 11:57:31 by itishche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static	int	poshuk(const char *str, int symb)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while ((k == 0) && (str[i] != '\0'))
	{
		if (str[i] == symb)
			k = 1;
		i++;
	}
	return (k);
}

char		*ft_strchr(const char *str, int symb)
{
	int i;
	int k;

	i = 0;
	if (symb == '\0')
		return ((char *)&str[ft_strlen(str)]);
	k = poshuk(str, symb);
	if (k == 1)
	{
		i = 0;
		while (str[i] != symb)
			i++;
		return ((char *)&str[i]);
	}
	else
		return (0);
}
