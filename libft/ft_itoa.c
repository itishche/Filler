/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itishche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 10:41:58 by itishche          #+#    #+#             */
/*   Updated: 2018/11/06 10:42:00 by itishche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static	char	*ft_strrev(char *s)
{
	int		i;
	int		j;
	char	c;

	i = ft_strlen(s);
	i--;
	j = 0;
	while (j < i)
	{
		c = s[j];
		s[j] = s[i];
		s[i] = c;
		j++;
		i--;
	}
	return (s);
}

static	int		kdigits(int n)
{
	size_t	k;
	size_t	sign;

	k = 0;
	sign = 0;
	if (n == 214783647)
	{
		k = 1;
		n = 14783647;
	}
	if (n < 0)
	{
		sign = 1;
		n = n * (-1);
	}
	while (n > 0)
	{
		k++;
		n = n / 10;
	}
	return (k + sign);
}

static	char	*stroka(char *ptr, int n)
{
	size_t	i;
	int		sign;

	i = 0;
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		n = n * (-1);
	}
	while (n > 0)
	{
		ptr[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	if (sign == -1)
	{
		ptr[i] = '-';
		i++;
	}
	ptr[i] = '\0';
	ft_strrev(ptr);
	return (ptr);
}

static	char	*intmin(void)
{
	return (ft_strcpy(ft_strnew(11), "-2147483648"));
}

char			*ft_itoa(int n)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (n)
	{
		if (n == (-2147483648))
		{
			ptr = intmin();
			return (ptr);
		}
		else
		{
			ptr = (char *)malloc(sizeof(char) * (kdigits(n) + 1));
			if (ptr == 0)
				return (0);
			else
				return (stroka(ptr, n));
		}
	}
	else
	{
		ptr = ft_strcpy(ft_strnew(1), "0");
		return (ptr);
	}
}
