NAME = push_swap
CHECKER = checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address 
RM = rm -f

SRCS = mandatory/algo.c mandatory/ft_push.c mandatory/ft_reverse_rotate.c mandatory/ft_rotate.c mandatory/ft_swap.c   \
       mandatory/is_valid.c mandatory/main_push_swap.c mandatory/sorting_2_5.c mandatory/set_stack.c mandatory/sort.c \
       mandatory/utils.c mandatory/free_functions.c

SRCSB = bonus/get_next_line.c bonus/instractions_1.c bonus/instractions_2.c bonus/instractions_3.c bonus/main_push_swap_bonus.c \
        bonus/utils_get_next_line.c bonus/utils_push_swap_bonus.c bonus/is_valid_bonus.c  bonus/utils_bonus.c bonus/free_functions.c

OBJS = $(SRCS:.c=.o)
OBJSB = $(SRCSB:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(CHECKER)

$(CHECKER): $(OBJSB)
	$(CC) $(CFLAGS) $(OBJSB) -o $(CHECKER)

clean:
	$(RM) $(OBJS) $(OBJSB)

fclean: clean
	$(RM) $(NAME) $(CHECKER)

re: fclean all

.phony: clean