/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itishche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 14:34:17 by itishche          #+#    #+#             */
/*   Updated: 2018/11/05 14:34:20 by itishche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	j = 0;
	if (s != 0)
	{
		ptr = (char *)malloc(sizeof(char) * (len + 1));
		if (ptr == 0)
			return (NULL);
		else
		{
			i = start;
			while (len-- && s[i] != '\0')
			{
				ptr[j++] = s[i++];
			}
			ptr[j] = '\0';
			return (ptr);
		}
	}
	else
		return (0);
}
