# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itishche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/26 15:12:25 by itishche          #+#    #+#              #
#    Updated: 2019/03/26 15:12:28 by itishche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	= 	itishche.filler
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -I ./includes
SRC		=	./main.c \
			./get_next_line.c \
			./minilib.c

OBJ = $(SRC:.c=.o)
FT_DIR	= ./libft/
FT_LNK	= -L $(FT_DIR) -lft
all: $(NAME)

$(NAME): $(OBJ) includes/filler.h
	make -C $(FT_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(FT_LNK) -o $(NAME)

clean:
	make -C $(FT_DIR) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(FT_DIR) fclean
	rm -f $(NAME)

re: fclean all
