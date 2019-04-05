/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itishche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 14:34:30 by itishche          #+#    #+#             */
/*   Updated: 2018/11/05 14:34:33 by itishche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void			*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;

	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 != 0 && s2 != 0)
	{
		ptr = (char *)malloc(sizeof(char) *
			(ft_strlen(s1) + ft_strlen(s2) + 1));
		if (ptr == 0)
			return (NULL);
		else
		{
			ft_strcpy(ptr, s1);
			ft_strcat(ptr, s2);
			return (ptr);
		}
	}
	else
		return (NULL);
}
