/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itishche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 13:37:27 by itishche          #+#    #+#             */
/*   Updated: 2018/10/29 11:01:33 by itishche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*p;

	i = 0;
	while (src[i] != '\0')
		i++;
	p = (char*)malloc(sizeof(char) * i + 1);
	if (p == 0)
		return (0);
	else
	{
		i = 0;
		while (src[i] != '\0')
		{
			p[i] = src[i];
			i++;
		}
		p[i] = '\0';
		return (p);
	}
}
