.PHONY: all clean fclean re

NAME = fdf

SRCS = *.c
INCS = /usr/local/include
FLAGS = -Wall -Wextra -Werror
LFTDIR = /libs/libft
LFTFLAGS = -lft
LMATHDIR = /libs/libmath
LMATHFLAG = -lmath
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
MLXDIR = /minilibx_macos
GCC = gcc

all: $(NAME)

$(NAME): $(SRCS)
	cd libs/libft && make
	cd libs/libmath && make
	$(GCC) $(FLAGS) $(SRCS) -L.$(MLXDIR) $(MLXFLAGS)  -L.$(LFTDIR) $(LFTFLAGS) -L.$(LMATHDIR) $(LMATHFLAG) -o $(NAME)

clean:
	cd libs/libft && make clean
	cd libs/libmath && make clean

fclean: clean
	rm -f $(NAME)
	cd libs/libft && make fclean
	cd libs/libmath && make fclean

re: fclean all