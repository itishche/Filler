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
	// int i;

	s = ft_strsplit(t->line, ' ');
	t->map_x = ft_atoi(s[1]);
	t->map_y = ft_atoi(s[2]);
	t->map = (char**)malloc(sizeof(char*) * t->map_x + 1);
	// i = 0;
	// while (i < t->map_y)
	// {
	// 	t->map[i] = (char*)malloc(sizeof(char) * t->map_y + 1);
	// 	ft_bzero(t->map[i], sizeof(t->map[i]));
	// 	i++;
	// }
	// t->map[i] = NULL;
	// ft_bzero(t->map, sizeof(t->map));
	//free_free(s);
}

void	print_map_fd(t_filler *t, int *fd)
{
	int i = 0;

	while (i < t->map_x)
	{
		ft_putstr_fd(t->map[i], *fd);
		ft_putstr_fd("\n", *fd);
		i++;
	}
	i = 0;
	while (i < t->piece_x)
	{
		ft_putstr_fd(t->piece[i], *fd);
		ft_putstr_fd("\n", *fd);
		i++;
	}
}


void	find_symb(t_filler *t)
{
	int i;
	int j;
	char c2;
	char s2;

	c2 = 'O';
	s2 = 'X';
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
}

void	find_pos(t_filler *t)//, int *fd)
{
	find_symb(t);
	if (t->my_y > t->his_y)
		t->up1_down2 = 1;
	else
		t->up1_down2 = 2;

	// ft_putstr_fd("my_x = ", *fd);
	// ft_putnbr_fd(t->my_x, *fd);
	// ft_putstr_fd("\n", *fd);
	// ft_putstr_fd("my_y = ", *fd);
	// ft_putnbr_fd(t->my_y, *fd);
	// ft_putstr_fd("\n", *fd);
	// ft_putstr_fd("his_x = ", *fd);
	// ft_putnbr_fd(t->his_x, *fd);
	// ft_putstr_fd("\n", *fd);
	// ft_putstr_fd("his_y = ", *fd);
	// ft_putnbr_fd(t->his_y, *fd);
	// ft_putstr_fd("\n", *fd);
}

void	check_symb(t_filler *t)
{
	t->symb[0] = (t->p1 == 1) ? 'O' : 'X';
	t->symb[1] = (t->p1 == 0) ? 'O' : 'X';
	t->symb[2] = '\0';
}

int		check_place(int i, int j, t_filler *t)//, int *fd)
{
	int	x;
	int y;
	int	k;
	int a;
	int b;

	x = 0;
	k = 0;
	a = i;
	
	// ft_putstr_fd("in  check_place\n", *fd);
	// ft_putstr_fd("\n", *fd);
	while (x < t->piece_x)
	{
		y = 0;
		b = j;
		while (y < t->piece_y)
		{
	// ft_putstr_fd("in arr", *fd);
			if (i <= t->map_x - t->piece_x && j <= t->map_y - t->piece_y)
			{
				if (t->piece[x][y] == '*' && t->map[a][b] == t->symb[1])
						{
							// ft_putchar_fd(t->symb[1], *fd);
							// ft_putstr_fd("* on his coordinates\n", *fd);
							return (0);
						}
						if (t->piece[x][y] == '*' && t->map[a][b] == t->symb[0])
						{		
							// ft_putchar_fd(t->symb[0], *fd);
							// ft_putstr_fd("* on my symb\n", *fd);
							k++;
						}
					}

			b++;
			y++;
		}
		a++;
		x++;
	}
	// ft_putstr_fd("endof\n", *fd);
	// if (k == 1)
	// {
	// 	ft_putstr_fd("i = ", *fd);
	// 	ft_putnbr_fd(i, *fd);
	// 	ft_putstr_fd("; j = ", *fd);
	// 	ft_putnbr_fd(j, *fd);
	// 	ft_putstr_fd("\n", *fd);
	// }
	// ft_putstr_fd("k = ", *fd);
	// ft_putnbr_fd(k, *fd);
	// ft_putstr_fd("\n", *fd);
	return (k);
}

void	check_dist(int i, int j, t_filler *t)//, int *fd)
{
	int d;

	// ft_putstr_fd("in check_dist\n ", *fd);
	d = ft_abs(i - t->his_x) + ft_abs(j - t->his_y);
	if (i <= t->map_x - t->piece_x && j <= t->map_y - t->piece_y)
	{	
		// ft_putstr_fd("i <= t->map_x - t->piece_x && j <= t->map_y - t->piece_y\n", *fd);
		// ft_putstr_fd("p_dist = ", *fd);
		// 	ft_putnbr_fd(t->p_dist, *fd);
		// 	ft_putstr_fd("\n", *fd);
		if (t->p_dist == 0 || d < t->p_dist)
		{
			t->p_dist = d;
			t->i = i;
			t->j = j;
			// ft_putstr_fd("t->i = ", *fd);
			// ft_putnbr_fd(t->i, *fd);
			// ft_putstr_fd("; t->j = ", *fd);
			// ft_putnbr_fd(t->j, *fd);
			// ft_putstr_fd("\n", *fd);
			// // ft_putstr_fd("p_dist = ", *fd);
			// // ft_putnbr_fd(t->p_dist, *fd);
			// // ft_putstr_fd("\n", *fd);
		}
	}
	// ft_putstr_fd("end of check_dist\n ", *fd);

}

void	check_down2(t_filler *t, int *fd)
{
	int	i;
	int	j;

	i = 0;
	ft_putstr_fd("in  check_down2", *fd);
	ft_putstr_fd("\n", *fd);
	while (i <= t->map_x - t->piece_x)
	{
		j = 0;
		while (j <= t->map_y - t->piece_y)
		{
			if (check_place(i, j, t) == 1)//, fd) == 1)
				check_dist(i, j, t, fd);
			j++;
		}
		i++;
	}
	ft_putstr_fd("end of check_down2\n\n ", *fd);

}
void	check_up1(t_filler *t, int *fd)
{
	int	i;
	int	j;

	ft_putstr_fd("in  check_up1", *fd);
	ft_putstr_fd("\n", *fd);
	i = t->map_x - 1;
	while (i >= 0)
	{
		j = t->map_y - 1;
		while (j >= 0)
		{
			if (check_place(i, j, t) == 1)//, fd) == 1)
				check_dist(i, j, t, fd);
			j--;
		}
		i--;
	}
	ft_putstr_fd("end of check_up1\n\n ", *fd);

}
void	return_coord(t_filler *t, int *fd)
{
	ft_putstr_fd("in return_coord", *fd);
	ft_putstr_fd("\n", *fd);
	ft_putnbr_fd(t->i, *fd);
	ft_putstr_fd(" ", *fd);
	ft_putnbr_fd(t->j, *fd);
	ft_putstr_fd("\n", *fd);
	ft_putnbr(t->i);
	write(1, " ", 1);
	ft_putnbr(t->j);
	write(1, "\n", 1);
	t->i = 0;
	t->j = 0;
	t->p_dist = 0;

	//free_free(piece);
}
void	check_players(t_filler *t, int *fd)
{
	int		k;
	int		i;
	int		j;

	k = 0;
	i = 0;
	j = 0;
	while (get_next_line(0, &(t->line)) > 0)
	{
		ft_putendl_fd(t->line, *fd);
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
			find_pos(t, fd);
			if (t->up1_down2 == 1)
				check_up1(t, fd);
			else
				check_down2(t, fd);
			return_coord(t, fd);
		}
		k++;
		free(t->line);
	}
}

int		main(void)
{
	t_filler	t;
	int			fd;

	fd = open("test", O_WRONLY);
	
	ft_bzero(&t, sizeof(t_filler));
	check_players(&t, &fd);
	return (0);
}
//   ./filler_vm -p1 players/champely.filler -p2 ../itishche.filler -v -f maps/map00
