/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itishche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 12:04:07 by itishche          #+#    #+#             */
/*   Updated: 2019/03/26 12:04:09 by itishche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/filler.h"

int		ft_abs(int a)
{
	return (a < 0 ? -a : a);
}

void	free_free(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
}

void	piece_size(t_filler *t)
{
	char	**s;

	s = ft_strsplit(t->line, ' ');
	t->piece_x = ft_atoi(s[1]);
	t->piece_y = ft_atoi(s[2]);
	t->piece = (char**)malloc(sizeof(char*) * t->piece_x + 1);
	t->piece[t->piece_x] = NULL;
	free_free(s);
	free(s);
}
