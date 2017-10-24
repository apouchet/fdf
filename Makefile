# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apouchet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/10 00:33:28 by apouchet          #+#    #+#              #
#    Updated: 2017/03/10 00:33:31 by apouchet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIB = ./libft/

SRC = ./src/key.c ./src/fdf.c ./src/affichage.c ./src/trace.c ./src/autre.c \
./src/get_next_line.c ./src/ligne.c ./src/rotation.c

OBJ = $(SRC:.c=.o)

all: $(NAME) 

$(NAME) : $(OBJ)
	make -C $(LIB)
	gcc -Wall -Werror -Wextra -lmlx -framework openGL -framework AppKit -o fdf $(LIB)libft.a $(OBJ)

norm :
	clear
	norminette -R CheckForbiddenSourceHeader *.c

clean :
	make clean -C $(LIB)
	rm -f src/*.o

re : fclean all

check : 
	sh ../../42FileChecker/42FileChecker.sh

log :
	open /Users/apouchet/Documents/42FileChecker/libft-unit-test/result.log 

fclean : clean
	rm -f $(NAME)
	rm -f $(LIB)libft.a
