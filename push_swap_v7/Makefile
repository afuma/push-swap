


CC = cc

NAME = push_swap
BONUS_NAME = checker

INCLUDES = ./includes
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES)

SRC =	src/ft_parse.c \
	src/ft_libft.c \
	src/ft_init.c \
	src/ft_moves.c \
	src/ft_utils.c \
	src/ft_utils2.c \
	src/ft_exec.c \
	src/ft_exec_func.c \
	src/ft_cost.c

SRC_MAIN = src/main.c

SRC_BONUS = bonus/ft_checker.c \
	bonus/get_next_line_bonus.c \
	bonus/get_next_line_utils_bonus.c

OBJ = $(SRC:.c=.o)
OBJ_MAIN = $(SRC_MAIN:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

bonus: $(BONUS_NAME)

%.o : %.c $(INCLUDES)
	$(CC) $(CFLAGS) -g -c $< -o $(<:.c=.o)

clean:
	$(RM) $(OBJ) $(OBJ_MAIN) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

$(NAME): $(OBJ) $(OBJ_MAIN)
	$(CC) $(CFLAGS) $(OBJ) $(OBJ_MAIN) -o $(NAME)

$(BONUS_NAME) : $(OBJ) $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ) $(OBJ_BONUS) -o $(BONUS_NAME)

.PHONY: all clean fclean re bonus

