
# d'apres Olivier, faire un make libft 
# puis inserez le .a de la libft dans la ligne 
# de compilation cc principale
CC = cc
NAME = push_swap

INCLUDES = ./push_swap.h
CFLAGS = -Wall -Wextra -Werror

RM = rm -f
AR = ar
ARFLAGS = crs

#libft
#LIBFTPATH = libft/
#LIBFT = libft/libft.a

SRC = 	main.c \
		ft_parse.c \
		ft_first_trie.c \
		ft_init.c \
		ft_utils.c \
		ft_utils2.c \
		ft_preprocess.c \
		ft_dispatcher.c \
		ft_exec.c \
		ft_cost.c \
		ft_push.c \
		ft_rotate.c \
		ft_reverse_rotate.c \
		ft_swap.c \
		ft_push_swap_utils.c

SRC_LIBFT = ./libft/ft_isdigit.c \
			./libft/ft_atol.c \
			./libft/ft_atoi.c

SRC_FTPRINTF = 	./ft_printf/ft_convert_1.c \
				./ft_printf/ft_convert_2.c \
				./ft_printf/ft_dispatcher.c \
				./ft_printf/ft_printf.c \
				./ft_printf/ft_utils_1.c \
				./ft_printf/ft_utils_2.c

#SRC_BONUS = ft_lstnew.c
            
OBJ = $(SRC:.c=.o)
OBJ_LIBFT = $(SRC_LIBFT:.c=.o)
OBJ_FTPRINTF = $(SRC_FTPRINTF:.c=.o)
#OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

%.o : %.c $(INCLUDES)
	$(CC) $(CFLAGS) -g -c $< -o $(<:.c=.o)

clean:
	$(RM) $(OBJ_LIBFT) $(OBJ_FTPRINTF) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

#$(LIBFT) :
#	@make -sC $(LIBFTPATH)

$(NAME): $(OBJ_LIBFT) $(OBJ) $(OBJ_FTPRINTF)
	$(CC) $(OBJ_LIBFT) $(OBJ_FTPRINTF) $(OBJ) -o $(NAME)
#$(AR) $(ARFLAGS) $(NAME) $(OBJ)

#bonus : $(OBJ) $(OBJ_BONUS)
#	$(AR) $(ARFLAGS) $(NAME) $(OBJ) $(OBJ_BONUS)

.PHONY: all clean fclean re bonus
