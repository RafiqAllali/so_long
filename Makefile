SOURCE = libft/ft_strjoin.c libft/split.c main_code/exit.c main_code/main.c main_code/movements.c parsing/characters.c parsing/mapsides.c parsing/flood.c parsing/shape.c parsing/utils.c

RM = rm -f

CC = cc -g

CFLAGS = -Wall -Wextra -Werror 

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

OBJ = $(SOURCE:.c=.o)

AR = ar rc

NAME = so_long

%.o: %.c so_long
	$(CC)  $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLXFLAGS) 
all: $(NAME)
 
clean:
	$(RM) $(OBJ) $(BOBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all