NAME = fdf

SRC =	main.c \
		ft_read_map.c \
		chack_map.c \
		give_mem.c \
		give_tot_mem.c \
		paint_1p.c \
		key_press.c \
		iso.c \
		paint_iso.c \
		line_put.c \
		print_mas.c

# OBJ_DIR = ./obj
# LIB_DIR = ./libft_GNL
# INC_DIR = ./inc

FLAGS = -Wall -Wextra -Werror

FLAGMLX = -lmlx -framework OpenGL -framework AppKit

OBJ = $(addprefix $(OBJ_DIR), $(SRC: .c=.o))

all: $(NAME)

$(NAME): $(OBJ)
		@clang -g $(FLAGS) $(OBJ) libft_GNL/libft.a $(FLAGMLX) -o $(NAME)

# $(OBJ_DIR)%.o: %.c
# 		gcc -c $< -o $@ -I $(INC_DIR)

clean:
		@rm -f $(OBJ_FILES)

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
