# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apouchet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/10 00:33:28 by apouchet          #+#    #+#              #
#    Updated: 2019/10/24 09:08:15 by apouchet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIB = ./libft/

SRC = ./src/key.c ./src/fdf.c ./src/affichage.c ./src/trace.c ./src/autre.c \
./src/ligne.c ./src/rotation.c

OBJ = $(SRC:.c=.o)

all: $(NAME) 

$(NAME) : $(OBJ)
	make -C $(LIB)
	gcc -Wall -Werror -Wextra -Lmlx/ -Imlx/ mlx/libmlx.a libft/libft.a -framework openGL -framework AppKit -o fdf $(LIB)libft.a $(OBJ)

norm :
	clear
	norminette -R CheckForbiddenSourceHeader *.c

clean :
	make clean -C $(LIB)
	rm -f $(OBJ)

re : fclean all

check : 
	sh ../../42FileChecker/42FileChecker.sh

log :
	open /Users/apouchet/Documents/42FileChecker/libft-unit-test/result.log 

fclean : clean
	rm -f $(NAME)
	make fclean -C $(LIB)
