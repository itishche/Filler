/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itishche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:42:50 by itishche          #+#    #+#             */
/*   Updated: 2018/11/19 12:42:54 by itishche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*head;

	if ((head = (t_list *)malloc(sizeof(*head))) == 0)
		return (0);
	if (content == 0)
	{
		head->content_size = 0;
		head->content = NULL;
	}
	else
	{
		head->content = malloc(sizeof(*(head->content)) * content_size);
		if (head->content == 0)
			return (0);
		head->content = ft_memcpy(head->content, content, content_size);
		head->content_size = content_size;
	}
	head->next = NULL;
	return (head);
}
