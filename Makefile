# -*- Makefile -*-

NAME = fdf
CC = cc
FLAGS = -Wall -Wextra -Werror
SUB_FLAGS = -lmlx -framework OpenGL -framework AppKit
RM = rm -rf

SOURCES = ./srcs/get_next_line/get_next_line_utils.c \
		  ./srcs/get_next_line/get_next_line.c \
		  ./srcs/map.c \
		  ./srcs/map_utils.c \
		  ./srcs/utils.c \
		  ./srcs/parsing.c \
		  ./srcs/ft_atoi_base.c \
		  ./srcs/fdf.c \
		  ./srcs/draw_line.c \
		  ./srcs/colors_utils.c \
		  ./srcs/read_map.c

OBJECTS = $(SOURCES:.c=.o)

%.o: %.c 
	$(CC) $(FLAGS) -c -o $@ $<

all : libft $(NAME)

$(NAME) : $(OBJECTS) ./srcs/fdf.h ./srcs/get_next_line/get_next_line.h
	$(CC) $(FLAGS) $(SUB_FLAGS) -o $(NAME) $(OBJECTS) libft/libft.a

libft :
	make -C libft

clean :
	$(RM) $(OBJECTS)
	make -C libft fclean

fclean : clean
	$(RM) $(NAME)
	make -C libft fclean

re : fclean all

.PHONY: libft all clean fclean re
