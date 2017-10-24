# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apouchet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 05:07:37 by apouchet          #+#    #+#              #
#    Updated: 2016/11/22 18:30:23 by apouchet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ./ft_putnbr.c ./ft_isascii.c ./ft_strcpy.c \
	./ft_strncpy.c ./ft_isdigit.c ./ft_putstr.c ./ft_strdup.c ./ft_strrchr.c \
	./ft_atoi.c ./ft_isprint.c ./ft_strcat.c ./ft_strlen.c ./ft_tolower.c \
	./ft_isalnum.c ./ft_putchar.c ./ft_strchr.c ./ft_strncat.c ./ft_toupper.c \
	./ft_isalpha.c ./ft_strcmp.c ./ft_strncmp.c ./ft_strlcat.c ./ft_strstr.c \
	./ft_memset.c ./ft_memcpy.c ./ft_memccpy.c ./ft_memchr.c ./ft_strsub.c \
	./ft_memcmp.c ./ft_bzero.c ./ft_strnstr.c ./ft_strdel.c ./ft_strclr.c \
	./ft_strnew.c ./ft_strsplit.c ./ft_putchar_fd.c ./ft_putstr_fd.c \
	./ft_putendl.c ./ft_putendl_fd.c ./ft_putnbr_fd.c ./ft_striter.c ./ft_itoa.c \
	./ft_striteri.c ./ft_strequ.c ./ft_strnequ.c ./ft_memdel.c ./ft_strjoin.c \
	./ft_memalloc.c ./ft_strtrim.c ./ft_strmap.c ./ft_strmapi.c ./ft_memmove.c \
	./ft_lstnew.c ./ft_lstdelone.c ./ft_lstdel.c ./ft_lstiter.c ./ft_lstadd.c ./ft_lstmap.c \
	./ft_ultimate_range.c ./ft_strupcase.c ./ft_strlowcase.c ./ft_concat_params.c ./ft_strcapitalize.c

OBJ = $(SRC:.c=.o)

all: $(NAME) 

$(NAME) : $(OBJ)
	gcc -c -Wall -Werror -Wextra $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib libft.a

norm :
	clear
	norminette -R CheckForbiddenSourceHeader *.c

clean :
	rm -f *.o

re : fclean all

check : 
	sh ../../42FileChecker/42FileChecker.sh

log :
	open /Users/apouchet/Documents/42FileChecker/libft-unit-test/result.log 

fclean : clean
	rm -f $(NAME)
