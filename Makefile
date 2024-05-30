SOURCE = libft/ft_strjoin.c libft/split.c main_code/exit.c main_code/main.c main_code/movements.c \
         parsing/characters.c parsing/mapsides.c parsing/flood.c parsing/shape.c parsing/utils.c \
         main_code/free.c main_code/read.c

OBJ = $(SOURCE:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

NAME = so_long

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLXFLAGS)

%.o: %.c so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
