/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itishche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 14:50:17 by itishche          #+#    #+#             */
/*   Updated: 2018/11/02 12:00:01 by itishche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	i = 0;
	while (s1[i] == s2[i] && s2[i] && i < n)
		i++;
	if (i == n && s1[i - 1] == s2[i - 1])
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
