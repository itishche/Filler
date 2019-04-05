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

int		ft_abs(int a)
{
	return (a < 0 ? -a : a);
}

void	free_free(char **arr)
{
	int		i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
}
//создать функцию на сравнение двух карт

void	check_position(t_filler *t, int *fd)
{
	int	i;
	int	j;
	int k;
	int x;
	int y;

	if (t->up1_down2 == 2)
	{
		i = t->my_x;
		j = t->my_y - t->piece_y + 1;
	}
	else
	{
		i = t->my_x - t->piece_x + 1;
		j = t->my_y - t->piece_y + 1;
	}
	x = 0;
	k = 0;
	while (x < t->piece_x)
	{
		y = 0;
		while (y < t->piece_y)
		{
			// if ((t->map[i][j] == t->piece[x][y] && t->map[i][j] == '.') ||
			// 	(t->map[i][j] == '.' && t->piece[x][y] == '*')
			// 	)
			if ((t->map[i][j] == t->symb[0] || t->map[i][j] == t->symb[1]) &&
				t->piece[x][y] == '*')
				k++;
			if (k > 1)
			{
				ft_putstr_fd("к = ", *fd); ft_putnbr_fd(k, *fd);ft_putstr_fd("\n", *fd);
				y = t->piece_y;
				k = 0;
				x = -1;
				if (j < t->map_y)
					j++;
				else
				{
					j = t->my_y - t->piece_y + 1;
					i++;
				}
			}
			y++;
		}
		x++;
	}
	ft_putstr_fd("к = ", *fd); ft_putnbr_fd(k, *fd);ft_putstr_fd("\n", *fd);
	if (k == 1)
	{
		ft_putstr_fd("i = ", *fd);
		ft_putnbr_fd(i, *fd);
		ft_putstr_fd("; j = ", *fd);
		ft_putnbr_fd(j, *fd);
		ft_putstr_fd("\n", *fd);
	}
}

void	map_size(t_filler *t)
{
	char	**s;
	int i;

	s = ft_strsplit(t->line, ' ');
	t->map_x = ft_atoi(s[1]);
	t->map_y = ft_atoi(s[2]);
	t->map = (char**)malloc(sizeof(char*) * t->map_x + 1);
	i = 0;
	while (i < t->map_y)
	{
		t->map[i++] = (char*)malloc(sizeof(char) * t->map_y + 1);
		ft_bzero(t->map[i - 1], sizeof(t->map[i]));
	}
	t->map[i] = NULL;
	// ft_bzero(t->map, sizeof(t->map));
	free_free(s);
}


// void	return_coord(void)
// {
// 	ft_putnbr(12);
// 	write(1, " ", 1);
// 	ft_putnbr(14);
// 	write(1, "\n", 1);
// }

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

void	piece_size(t_filler *t)
{
	char	**s;

	s = ft_strsplit(t->line, ' ');
	t->piece_x = ft_atoi(s[1]);
	t->piece_y = ft_atoi(s[2]);
	t->piece = (char**)malloc(sizeof(char*) * t->piece_x + 1);
	free_free(s);
}

void	find_pos(t_filler *t, int *fd)
{
	int	i;
	int	j;

	i = 0;
	while (i < t->map_x)
	{
		j = 0;
		while (j < t->map_y)
		{
			if (t->map[i][j] == t->symb[0] ||
				t->map[i][j] == t->symb[1])
			{
				t->my_x = i;
				t->my_y = j;
			}
			if (t->map[i][j] != t->symb[0] &&
				t->map[i][j] != t->symb[1] && t->map[i][j] != '.')
			{
				t->his_x = i;
				t->his_y = j;
			}
			j++;
		}
		i++;
	}
	if (t->my_x > t->his_x)
		t->up1_down2 = 2;
	else
		t->up1_down2 = 1;
	// t->dist = ft_abs(t->my_x - t->his_x) + ft_abs(t->my_y - t->his_y);


	ft_putstr_fd("my_x = ", *fd);
	ft_putnbr_fd(t->my_x, *fd);
	ft_putstr_fd("\n", *fd);
	ft_putstr_fd("my_y = ", *fd);
	ft_putnbr_fd(t->my_y, *fd);
	ft_putstr_fd("\n", *fd);
	ft_putstr_fd("his_x = ", *fd);
	ft_putnbr_fd(t->his_x, *fd);
	ft_putstr_fd("\n", *fd);
	ft_putstr_fd("his_y = ", *fd);
	ft_putnbr_fd(t->his_y, *fd);
	ft_putstr_fd("\n", *fd);
	// ft_putstr_fd("t->dist = ", *fd);
	// ft_putnbr_fd(t->dist, *fd);
	// ft_putstr_fd("\n", *fd);
}

void	check_symb(t_filler *t)
{
	t->symb[0] = (t->p1 == 1) ? 'o' : 'x';
	t->symb[1] = (t->p1 == 1) ? 'O' : 'X';
	t->symb[2] = '\0';
}

// void	put_figure_on_map(t_filler *t, int *fd)
// {
// 	int	i;
// 	int	j;
// 	int	x;
// 	int y;

// 	i = 0;
// 	while (i < t->map_x)
// 	{
// 		j = 0;
// 		while (j < t->map_y)
// 		{
			


// 			j++;
// 		}
// 		i++;
// 	}
// }

void	check_players(t_filler *t, int *fd)
{
	
	int		k;
	int		i;
	int		j;

	k = 0;
	i = 0;
	j = 0;
	while (get_next_line(0, &(t->line)) == 1)
	{
		ft_putstr_fd(t->line, *fd);
		ft_putstr_fd("\n", *fd);
		//определить тип карты
		if (ft_strstr(t->line, "Plateau") != NULL)
			map_size(t);
		if (t->p1 == 0 && t->p2 == 0)//сначала определить кто игрок 1, а кто игрок номер 2 
		{
			t->p1 = (ft_strstr(t->line, "p1") == NULL) ? 0 : 1;
			t->p2 = (ft_strstr(t->line, "p2") == NULL) ? 0 : 1;
		}
		if (k > 2 && k <= t->map_x + 2)
			ft_strcpy(t->map[i++], t->line + 4);
			// t->map[i++] = ft_strdup(t->line + 4);
		//запомнить фигурку
		if (ft_strstr(t->line, "Piece") != NULL)
			piece_size(t);
		if (k > t->map_x + 3)
			t->piece[j++] = ft_strdup(t->line);
		k++;
		free(t->line);
	}
	check_symb(t);
	// ft_putstr_fd("my_symb = ", *fd);
	// ft_putstr_fd(t->symb, *fd);
	// ft_putstr_fd("\n", *fd);
	print_map_fd(t, fd);
	find_pos(t, fd);//функция находит последнюю позицию моего символа- подходит для пути вниз!
	//если не получается поставить - надо сделать попытку найти предыдущую точку!
	//сделать функцию на определение  пути - идти вниз или вверх - для анализа относительно положения противника)
	// put_figure_on_map(t, fd);
	check_position(t, fd);
	// return_coord();
}

int		main(void)
{
	t_filler	t;
	int			fd;

	fd = open("test", O_WRONLY);
	
	ft_bzero(&t, sizeof(t_filler));
	check_players(&t, &fd);
	ft_putstr_fd("t.p1 = ", fd);
	ft_putnbr_fd(t.p1, fd);
	ft_putstr_fd("\n", fd);
	ft_putstr_fd("t.p2 = ", fd);
	ft_putnbr_fd(t.p2, fd);
	ft_putstr_fd("\n", fd);


	ft_putstr_fd("map.size_x = ", fd);
	ft_putnbr_fd(t.map_x, fd);
	ft_putstr_fd("\n", fd);

	ft_putstr_fd("map.size_y = ", fd);
	ft_putnbr_fd(t.map_y, fd);
	ft_putstr_fd("\n", fd);

	ft_putstr_fd("piece.size_x = ", fd);
	ft_putnbr_fd(t.piece_x, fd);
	ft_putstr_fd("\n", fd);
	ft_putstr_fd("piece.size_y = ", fd);
	ft_putnbr_fd(t.piece_y, fd);
	ft_putstr_fd("\n", fd);
	return (0);
}
//   ./filler_vm -p1 players/champely.filler -p2 ../itishche.filler -v -f maps/map00
