/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itishche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 10:41:21 by itishche          #+#    #+#             */
/*   Updated: 2018/11/06 10:41:23 by itishche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static	int		ksliv(char const *str, char c)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i] == '\0')
			break ;
		else
			k++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (k);
}

static	int		kbukv(char const *s, char c)
{
	int		k;
	int		i;

	k = 0;
	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		k++;
	}
	return (k);
}

static	void	*poshuk(char **ptr, char const *s, char c)
{
	int		i;
	int		k;
	int		j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] == '\0')
			break ;
		else
		{
			k = kbukv(&s[i], c);
			i = i + k;
			ptr[j] = (char *)malloc(sizeof(char) * (k + 1));
			ptr[j] = ft_strsub(s, i - k, k);
			j++;
		}
	}
	ptr[j] = NULL;
	return (ptr);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**ptr;
	int		k;

	if (s != 0 && c)
	{
		k = ksliv(s, c);
		ptr = (char **)malloc(sizeof(char *) * (k + 1));
		if (ptr == 0)
			return (0);
		else
		{
			if (k == 0)
			{
				ptr[0] = NULL;
				return (ptr);
			}
			else
			{
				ptr = poshuk(ptr, s, c);
				return (ptr);
			}
		}
	}
	else
		return (0);
}
