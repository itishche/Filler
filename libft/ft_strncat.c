/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itishche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 11:23:45 by itishche          #+#    #+#             */
/*   Updated: 2018/10/26 11:34:10 by itishche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	unsigned int i;
	unsigned int j;

	j = 0;
	i = ft_strlen(s1);
	while ((j < n) && (s2[j] != '\0'))
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}
