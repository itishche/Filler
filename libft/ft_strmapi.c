/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itishche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 13:08:54 by itishche          #+#    #+#             */
/*   Updated: 2018/11/05 13:08:56 by itishche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ptr;
	int		i;

	if (s != 0 && f)
	{
		ptr = (char *)malloc((sizeof(char)) * (ft_strlen(s) + 1));
		if (ptr != 0)
		{
			i = 0;
			while (s[i] != '\0')
			{
				ptr[i] = f(i, s[i]);
				i++;
			}
			ptr[i] = '\0';
			return (ptr);
		}
		else
			return (0);
	}
	else
		return (0);
}
