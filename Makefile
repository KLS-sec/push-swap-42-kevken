NAME = push_swap.a

DIRS = Libft ft_printf Double_Chained_List

# !!!!!!!!!!!!! ATTENTION, CORRIGER LE *.C QUI EST INTERDIT !!!!!!!!!!

SRC = push_swap.c $(foreach dir, $(DIRS), $(wildcard $(dir)/*.c))

#SRC_BONUS = (Si jamais on se motive pour faire le bonus)

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

HEADER = push_swap.h

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

bonus: $(OBJ) $(OBJ_BONUS)
	ar rcs $(NAME) $(OBJ) $(OBJ_BONUS)