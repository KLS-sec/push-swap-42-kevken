NAME = push_swap.a

# Libft files
SRC_LIBFT = Libft/ft_atoi.c \
            Libft/ft_bzero.c \
            Libft/ft_calloc.c \
            Libft/ft_isalnum.c \
            Libft/ft_isalpha.c \
            Libft/ft_isascii.c \
            Libft/ft_isdigit.c \
            Libft/ft_isprint.c \
            Libft/ft_itoa.c \
            Libft/ft_lstadd_back_bonus.c \
            Libft/ft_lstadd_front_bonus.c \
            Libft/ft_lstclear_bonus.c \
            Libft/ft_lstdelone_bonus.c \
            Libft/ft_lstiter_bonus.c \
            Libft/ft_lstlast_bonus.c \
            Libft/ft_lstmap_bonus.c \
            Libft/ft_lstnew_bonus.c \
            Libft/ft_lstsize_bonus.c \
            Libft/ft_memchr.c \
            Libft/ft_memcmp.c \
            Libft/ft_memcpy.c \
            Libft/ft_memmove.c \
            Libft/ft_memset.c \
            Libft/ft_putchar_fd.c \
            Libft/ft_putendl_fd.c \
            Libft/ft_putnbr_fd.c \
            Libft/ft_putstr_fd.c \
            Libft/ft_split.c \
            Libft/ft_strchr.c \
            Libft/ft_strdup.c \
            Libft/ft_striteri.c \
            Libft/ft_strjoin.c \
            Libft/ft_strlcat.c \
            Libft/ft_strlcpy.c \
            Libft/ft_strlen.c \
            Libft/ft_strmapi.c \
            Libft/ft_strncmp.c \
            Libft/ft_strnstr.c \
            Libft/ft_strrchr.c \
            Libft/ft_strtrim.c \
            Libft/ft_substr.c \
            Libft/ft_tolower.c \
            Libft/ft_toupper.c

# Main file
SRC_MAIN = push_swap.c

# Double Chained List files
SRC_DLST = Double_Chained_List/ft_dlst_create_check.c \
           Double_Chained_List/ft_dlst_push_clear.c

# Operating actions files
SRC_OPS = Operating_actions/reverse_rotate_ab.c \
          Operating_actions/rotate_ab.c \
          Operating_actions/swap_and_push_ab.c

# Error printing files
SRC_ERR = ft_print_error/ft_print_error.c \
          ft_print_error/ft_print_error_utils.c


# Printf files
SRC_PRINTF = ft_printf/ft_printf.c \
             ft_printf/ft_printf_utils.c

# Bench file
SRC_BENCH = Bench_Codes/bench_count.c

# Launch and check files
SRC_LNCH = Launcher/error_detection.c \
           Launcher/instructions.c \
           Launcher/stack_normalizer.c

# Sorting stacks files
SRC_SORT = Sorting_Stacks/complex_sorting_radix.c \
           Sorting_Stacks/medium_sorting_Chunk-based.c \
           Sorting_Stacks/sort_of_bubulle_sort.c

# Combine all sources (DON'T FORGET TO REMOVE # FOR $(SRC_SORT))
SRC = $(SRC_MAIN) $(SRC_DLST) $(SRC_OPS) $(SRC_ERR) $(SRC_LIBFT) $(SRC_PRINTF) $(SRC_BENCH) $(SRC_LNCH) #$(SRC_SORT)

#SRC_BONUS = (Si jamais on se motive pour faire le bonus)

OBJ = $(SRC:.c=.o)

#OBJ_BONUS = $(SRC_BONUS:.c=.o)

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
