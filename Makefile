NAME = fdf

OBJ = $(patsubst %.c, %.o, $(wildcard srcs/*.c)) main.o

FLAGS = -Wall -Wextra -Werror

HEADER = includes

HEADERDIR = libft/includes

LIB = libft/libft.a

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	gcc $(OBJ) -o $(NAME) -I $(HEADERDIR) -L libft/ -lft -L minilibx/ -lmlx -framework OpenGL -framework AppKit

%.o: %.c $(HEADER)
	gcc -I $(HEADERDIR) -I $(HEADER) -I minilibx -c $< -o $@ -g

$(LIB):
	make -C libft/
	make -C minilibx/

clean:
	rm -rf $(OBJ)
	make clean -C libft/
	make clean -C minilibx/

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft/

re: fclean all
