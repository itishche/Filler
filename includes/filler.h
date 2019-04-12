/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itishche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 14:16:30 by itishche          #+#    #+#             */
/*   Updated: 2019/03/26 14:16:32 by itishche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include "../libft/libft.h"
# define BUFF_SIZE 32

typedef struct	s_filler
{
	int			p1;
	int			p2;
	int			map_x;
	int			map_y;
	int			i;
	int			j;
	int			p_dist;
	int			piece_x;
	int			piece_y;
	int			my_x;
	int			my_y;
	int			his_x;
	int			his_y;
	int			up1_down2;
	int			dist;
	char		**map;
	char		*line;
	char		**piece;
	char		symb[3];//symb[0] - это я
}				t_filler;


int				get_next_line(const int fd, char **line);
int				ft_abs(int a);
void			free_free(char **arr);
void			piece_size(t_filler *t);

#endif
