NAME = so_long
NAME2 = push_swap

LIBFT = libft/libft.a

MINILIBX = minilibx-linux/libmlx.a

SRC =	push_swap.c \
		push_utils.c \
		push_core.c \
		sort_big.c \
		s_functions.c \
		s2_functions.c \
		big_functions.c \
		alloc.c \

FLAGS =  -g -Wall -Werror -Wextra

all: $(NAME)

$(NAME): libcomp comp

libcomp:
		@make -C libft

comp:
	cc $(FLAGS) $(SRC) $(LIBFT) $(LINKS) -o $(NAME2)
	
bonus: $(NAME)
            
libclean:
		@make clean -C libft
		
clean:		libclean

libfclean:
		@make fclean -C libft

fclean:   	clean libfclean
		rm -rf $(NAME) $(NAME2)
		rm -rf maps/list_maps.txt
		
re: fclean all

reb: fclean bonus

.PHONY: all re clean fclean bonus maps

.SILENT:
