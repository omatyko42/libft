CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

NAME = libft.a

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
       ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
       ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
       ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
       ft_strnstr.c ft_atoi.c ft_calloc.c ft_min_max_abs.c ft_strdup.c \
       ft_substr.c ft_strjoin.c ft_strtrim.c  ft_split.c ft_itoa.c \
       ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
       ft_putnbr_fd.c ft_printf.c ft_print_utils.c ft_print_functions.c \
       ft_strichr.c ft_free.c ft_is_spaces.c gnl/get_next_line_utils.c \
       gnl/get_next_line.c

BONUS_SRCS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
             ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
             ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

.SECONDARY: $(OBJS)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "Library $(NAME) created."

bonus: $(NAME) $(BONUS_OBJS)
	@ar rcs $(NAME) $(BONUS_OBJS)
	@echo "Bonus files added to $(NAME)."

%.o: %.c libft.h gnl/get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)
	@echo "Object files removed."

fclean: clean
	@rm -f $(NAME)
	@echo "Library $(NAME) removed."

re: fclean all

.PHONY: all clean fclean re bonus
