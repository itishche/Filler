/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itishche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 14:15:40 by itishche          #+#    #+#             */
/*   Updated: 2019/03/26 14:15:45 by itishche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

void	map_size(t_filler *t)
{
	char	**s;

	s = ft_strsplit(t->line, ' ');
	t->map_x = ft_atoi(s[1]);
	t->map_y = ft_atoi(s[2]);
	t->map = (char**)malloc(sizeof(char*) * t->map_x + 1);
	t->map[t->map_x] = NULL;
	free_free(s);
	free(s);
}

void	find_symb(t_filler *t)
{
	int i;
	int j;
	char c2;
	char s2;
	int a = 0;
	int b = 0;

	c2 = 'O';
	s2 = 'X';
	if (t->his_x != 0 && t->his_y != 0)
	{
		a = t->his_x;
		b = t->his_y;
	}
	i = 0;
	while (i < t->map_x)
	{
		j = 0;
		while (j < t->map_y)
		{
			if (t->map[i][j] == c2)
			{
				t->my_x = i;
				t->my_y = j;
			}
			j++;
		}
		i++;
	}
	i = t->map_x - 1;

	while (i >= 0)
	{
		j = t->map_y - 1;
		while (j >= 0)
		{
			if (t->map[i][j] == s2)
			{
				t->his_x = i;
				t->his_y = j;
			}
			j--;
		}
		i--;
	}
	if (t->symb[0] == s2)
	{
		i = t->my_x;
		t->my_x = t->his_x;
		t->his_x = i;
		i = t->my_y;
		t->my_y = t->his_y;
		t->his_y = i;
	}
	if (a != 0 && b != 0)
	{
		t->his_x = a;
		t->his_y = b;
	}
}

void	find_pos(t_filler *t)
{
	find_symb(t);
	if (t->my_y > t->his_y)
		t->up1_down2 = 1;
	else
		t->up1_down2 = 2;
}

void	check_symb(t_filler *t)
{
	t->symb[0] = (t->p1 == 1) ? 'O' : 'X';
	t->symb[1] = (t->p1 == 0) ? 'O' : 'X';
	t->symb[2] = '\0';
}
// если мой стоит близко к границе - то попытатьс досттигнуть ее
int		check_place(int i, int j, t_filler *t)
{
	int	x;
	int y;
	int	k;
	int a;
	int b;

	x = 0;
	k = 0;
	a = i;
	while (x < t->piece_x)
	{
		y = 0;
		b = j;
		while (y < t->piece_y)
		{
			if ((a < 0 || b < 0) && t->piece[x][y] == '*')
				return (0);
			if (i <= t->map_x - t->piece_x && j <= t->map_y - t->piece_y)
			{
				if (t->piece[x][y] == '*' && (t->map[a][b] == t->symb[1] || t->map[a][b] == t->symb[1] + 32))
					return (0);
				if (t->piece[x][y] == '*' && (t->map[a][b] == t->symb[0] || t->map[a][b] == t->symb[0] + 32))
					k++;
			}
			b++;
			y++;
		}
		a++;
		x++;
	}
	return (k);
}

void	check_dist(int i, int j, t_filler *t)
{
	int d;

	d = ft_abs(i - t->his_x) + ft_abs(j - t->his_y);
	if (i <= t->map_x - t->piece_x && j <= t->map_y - t->piece_y)
	{	
		if (t->p_dist == 0 || d < t->p_dist)
		{
			t->p_dist = d;
			t->i = i;
			t->j = j;
		}
	}
}

void	return_coord(t_filler *t)
{
	int i;
	i = 0;
	free_free(t->map);
	free_free(t->piece);
	free(t->piece);
	ft_putnbr(t->i);
	write(1, " ", 1);
	ft_putnbr(t->j);
	write(1, "\n", 1);
	
	t->i = 0;
	t->j = 0;
	t->p_dist = 0;
	

}

void go_up1(t_filler *t)
{
	int	i;
	int	j;

	i = t->map_x - 1;
	while (i >= 1 - t->piece_x)
	{
		j = t->map_y - 1;
		while (j >= 1 - t->piece_y)
		{
			if (check_place(i, j, t) == 1)
				check_dist(i, j, t);
			j--;
		}
		i--;
	}
}

void	go_down2(t_filler *t)
{
	int	i;
	int	j;

	i = 1 - t->piece_x;
	while (i <= t->map_x - t->piece_x)
	{
		j = 1 - t->piece_y;
		while (j <= t->map_y - t->piece_y)
		{
			if (check_place(i, j, t) == 1)
				check_dist(i, j, t);
			j++;
		}
		i++;
	}
}

void	check_players(t_filler *t)
{
	int		k;
	int		i;
	int		j;

	k = 0;
	i = 0;
	j = 0;
	while (get_next_line(0, &(t->line)) > 0)
	{
		ft_putendl_fd(t->line, 3);
		if (ft_strstr(t->line, "Plateau") != NULL && t->map_x == 0)
			map_size(t);
		if (t->p1 == 0 && t->p2 == 0)
		{
			t->p1 = (ft_strstr(t->line, "p1") == NULL) ? 0 : 1;
			t->p2 = (ft_strstr(t->line, "p2") == NULL) ? 0 : 1;
		}
		if (k > 2 && k <= t->map_x + 2)
			t->map[i++] = ft_strdup(t->line + 4);
		if (ft_strstr(t->line, "Piece") != NULL)
			piece_size(t);
		if (k > t->map_x + 3 && k <= t->map_x + 3 + t->piece_x)
			t->piece[j++] = ft_strdup(t->line);
		if (k == t->map_x + 3 + t->piece_x)
		{
			k = 0;
			i = 0;
			j = 0;
			check_symb(t);
			find_pos(t);
			if (t->up1_down2 == 1)
				go_up1(t);
			else
				go_down2(t);
			return_coord(t);
		}
		k++;
		free(t->line);
	}
}

int		main(void)
{
	t_filler	t;
	int			fd;

	fd = open("./resources/test", O_WRONLY);
	
	ft_bzero(&t, sizeof(t_filler));
	check_players(&t);
	close(fd);
	// long long int i =-10000000000000;
	// while (i > -10000000000000 -1)
	// 	i++;
	free(t.map);
	system("leaks itishche.filler > file.txt");
	return (0);
}
