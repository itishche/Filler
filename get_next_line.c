 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itishche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 13:58:59 by itishche          #+#    #+#             */
/*   Updated: 2018/11/16 13:59:05 by itishche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/filler.h"

static size_t	ft_strlen_chr(const char *str, int ch)
{
	size_t len;

	len = 0;
	while (str[len] != ch)
	{
		if (str[len] == '\0')
			return (0);
		len++;
	}
	return (len);
}

static int	fill_line(char **line, char **buff, char *res_read, int flag)
{
	char	*ptr;
	int		len_ch;
	int		res;

	res = 0;
	if (flag == 1 && (res = 1))
	{
		len_ch = ft_strlen_chr(*buff, '\n');
		*line = ft_strsub(*buff, 0, len_ch);
		ptr = *buff;
		*buff = ft_strdup(ptr + len_ch + 1);
		free(ptr);
	}
	else if (flag == 2 && (res = 1))
	{
		len_ch = ft_strlen_chr(res_read, '\n');
		ptr = ft_strsub(res_read, 0, len_ch);
		*line = ft_strjoin(*buff, ptr);
		free(*buff);
		free(ptr);
		*buff = ft_strdup(res_read + len_ch + 1);
		free(res_read);
	}
	return (res);
}

int			get_next_line(int const fd, char **line)
{
	static char	*buff = NULL;
	char		*res_read;
	int			res;
	char		*ptr;

	if (buff != NULL && ft_strchr(buff, '\n') != NULL)
		return (fill_line(line, &buff, NULL, 1));
	res_read = ft_strnew(BUFF_SIZE);
	while ((res = read(fd, res_read, BUFF_SIZE)) > 0)
	{
		res_read[res] = '\0';
		if (ft_strchr(res_read, '\n') != NULL)
			return (fill_line(line, &buff, res_read, 2));
		ptr = buff;
		buff = ft_strjoin(ptr, res_read);
		free(ptr);
	}
	ft_strdel(&res_read);
	if (res == -1)
		return (-1);
	if (buff == NULL)
		return (0);
	*line = ft_strdup(buff);
	ft_strdel(&buff);
	return (1);
}
// static t_list	*checklist(const int fd, t_list **list)
// {
// 	t_list *pro;

// 	if (!(*list))
// 	{
// 		*list = ft_lstnew("", fd);
// 		return (*list);
// 	}
// 	pro = *list;
// 	while (pro)
// 	{
// 		if (pro->content_size == (size_t)fd)
// 			return (pro);
// 		pro = pro->next;
// 	}
// 	pro = ft_lstnew("", fd);
// 	ft_lstadd(list, pro);
// 	return (*list);
// }

// static	int		nextlines(t_list **alst, char ***line)
// {
// 	char			*str;
// 	int				i;

// 	i = 0;
// 	str = (*alst)->content;
// 	if (ft_strlen(str) == 0)
// 		return (0);
// 	while (str[i] != '\0' && str[i] != '\n')
// 		i++;
// 	**line = ft_strsub(str, 0, i);
// 	if (str[i] == '\n')
// 		str = ft_strdup(ft_strchr(str, '\n') + 1);
// 	else
// 		str = ft_strdup(ft_strchr(str, '\0'));
// 	free((*alst)->content);
// 	(*alst)->content = ft_strdup(str);
// 	free(str);
// 	return (1);
// }

// static	void	input(t_list **alst, const int fd)
// {
// 	char			*buff;
// 	char			*temp;
// 	int				d;

// 	buff = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
// 	while ((d = read(fd, buff, BUFF_SIZE)))
// 	{
// 		buff[d] = '\0';
// 		temp = (*alst)->content;
// 		(*alst)->content = ft_strjoin((*alst)->content, buff);
// 		free(temp);
// 		if (ft_strchr((*alst)->content, '\n'))
// 			break ;
// 	}
// 	free(buff);
// }

// int				get_next_line(const int fd, char **line)
// {
// 	static	t_list	*alst;
// 	t_list			*x;
// 	int				d;

// 	if (BUFF_SIZE < 1 || fd < 0 || read(fd, NULL, 0) < 0)
// 		return (-1);
// 	x = checklist(fd, &alst);
// 	input(&x, fd);
// 	d = nextlines(&x, &line);
// 	if (d == 0)
// 		return (0);
// 	else if (d < 0)
// 		return (-1);
// 	return (1);
// }
