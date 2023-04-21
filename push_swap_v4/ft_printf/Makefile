
CC = cc
NAME = libftprintf.a

INCLUDES = ./ft_printf.h
CFLAGS = -Wall -Wextra -Werror

RM = rm -f
AR = ar
ARFLAGS = crs

SRC = ft_convert_1.c \
		ft_convert_2.c \
		ft_dispatcher.c \
		ft_printf.c \
		ft_convert_1.c \
		ft_utils_1.c \
		ft_utils_2.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o : %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
	
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	
.PHONY: all clean fclean re
