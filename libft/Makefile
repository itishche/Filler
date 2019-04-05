# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itishche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/02 12:24:56 by itishche          #+#    #+#              #
#    Updated: 2018/11/02 13:06:20 by itishche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror
FILEC = ft_lstiter.c ft_lstdel.c ft_lstadd.c ft_lstdelone.c ft_lstnew.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putnbr_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putchar_fd.c ft_putendl.c ft_strjoin.c ft_strsub.c ft_strnequ.c ft_strequ.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_memalloc.c ft_memdel.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_strnew.c ft_strdel.c ft_strclr.c ft_atoi.c ft_bzero.c ft_isalpha.c ft_isalnum.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memcpy.c ft_memcmp.c ft_memccpy.c ft_memchr.c ft_memset.c ft_strcat.c ft_memmove.c ft_strcmp.c ft_strchr.c ft_strcpy.c ft_strlen.c ft_strlcat.c ft_strdup.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_tolower.c ft_toupper.c ft_strnstr.c ft_strstr.c ft_strrchr.c
FILEO = ft_lstiter.o ft_lstdel.o ft_lstadd.o ft_lstdelone.o ft_lstnew.o ft_strtrim.o ft_strsplit.o ft_itoa.o ft_putnbr_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putchar_fd.o ft_putendl.o ft_strjoin.o ft_strsub.o ft_strnequ.o ft_strequ.o ft_striter.o ft_striteri.o ft_strmap.o ft_strmapi.o ft_memalloc.o ft_memdel.o ft_putchar.o ft_putnbr.o ft_putstr.o ft_strnew.o ft_strdel.o ft_strclr.o ft_atoi.o ft_bzero.o ft_isalpha.o ft_isalnum.o ft_isascii.o ft_isdigit.o ft_isprint.o ft_memcpy.o ft_memcmp.o ft_memccpy.o ft_memchr.o ft_memset.o ft_strcat.o ft_memmove.o ft_strcmp.o ft_strchr.o ft_strcpy.o ft_strlen.o ft_strlcat.o ft_strdup.o ft_strncat.o ft_strncmp.o ft_strncpy.o ft_tolower.o ft_toupper.o ft_strnstr.o ft_strstr.o ft_strrchr.o
NAME = libft.a
FILEH = libft.h

all: $(NAME)

$(NAME):
	@gcc -c -I$(FILEH) $(FILEC)
	@ar rc $@ $(FILEO)
	@ranlib $@

clean:
	@/bin/rm -f $(FILEO)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
