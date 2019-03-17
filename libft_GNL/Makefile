# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okherson <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/30 13:06:10 by okherson          #+#    #+#              #
#    Updated: 2018/11/14 15:34:40 by okherson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ./*.c

OBJ = ./*.o

HEADER = libft.h

all: $(NAME)

$(NAME): $(SRC)
	gcc -c $(SRC) $(HEADER) -Wall -Wextra -Werror
	ar rc $(NAME) $(OBJ)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all re fclean clean 
