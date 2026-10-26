NAME = push_swap
BONUS_NAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror

MAND_DIR = mandatory
SRC_DIR = $(MAND_DIR)/src
INC_DIR = $(MAND_DIR)/includes
LIB_DIR = $(INC_DIR)/libs

BONUS_DIR = bonus
BONUS_SRC_DIR = $(BONUS_DIR)/src
BONUS_INC_DIR = $(BONUS_DIR)/includes

INCLUDES = -I $(INC_DIR) -I $(LIB_DIR)
BONUS_INCLUDES = -I $(BONUS_INC_DIR) -I $(INC_DIR) -I $(LIB_DIR)

SRCS = $(SRC_DIR)/main.c \
	   $(SRC_DIR)/initializer/start.c \
	   $(SRC_DIR)/parser/parser.c \
	   $(SRC_DIR)/parser/parser_utils.c \
	   $(SRC_DIR)/parser/parser_free.c \
	   $(SRC_DIR)/modes/mode_selector.c \
	   $(SRC_DIR)/modes/cal_index.c \
	   $(SRC_DIR)/modes/adaptive/adaptive_mode.c \
	   $(SRC_DIR)/modes/adaptive/cal_index_error.c \
	   $(SRC_DIR)/modes/bench/bench_mode.c \
	   $(SRC_DIR)/modes/bench/print_disorder.c \
	   $(SRC_DIR)/modes/bench/print_strategy.c \
	   $(SRC_DIR)/modes/bench/print_total.c \
	   $(SRC_DIR)/modes/bench/print_movements.c \
	   $(SRC_DIR)/modes/complex/complex_mode.c \
	   $(SRC_DIR)/modes/complex/complex_mode_utils.c \
	   $(SRC_DIR)/modes/medium/medium_mode.c \
	   $(SRC_DIR)/modes/medium/medium_mode_utils.c \
	   $(SRC_DIR)/modes/simple/simple_mode.c \
	   $(SRC_DIR)/modes/simple/simple_mode_utils.c \
	   $(SRC_DIR)/modes/simple/look_for_target.c \
	   $(SRC_DIR)/modes/simple/cost.c \
	   $(SRC_DIR)/modes/less_than_five/less_than_five.c \
	   $(SRC_DIR)/modes/less_than_five/less_than_five_utils.c \
	   $(SRC_DIR)/movements/pa.c \
	   $(SRC_DIR)/movements/pb.c \
	   $(SRC_DIR)/movements/ra.c \
	   $(SRC_DIR)/movements/rb.c \
	   $(SRC_DIR)/movements/rr.c \
	   $(SRC_DIR)/movements/rra.c \
	   $(SRC_DIR)/movements/rrb.c \
	   $(SRC_DIR)/movements/rrr.c \
	   $(SRC_DIR)/movements/push.c \
	   $(SRC_DIR)/movements/rotate.c \
	   $(SRC_DIR)/movements/rotatereverse.c \
	   $(SRC_DIR)/movements/sa.c \
	   $(SRC_DIR)/movements/sb.c \
	   $(SRC_DIR)/movements/ss.c \
	   $(SRC_DIR)/movements/swap.c \
	   $(SRC_DIR)/movements/pos_upper_len.c

BONUS_SRCS = $(BONUS_SRC_DIR)/main.c \
			 $(BONUS_SRC_DIR)/parser_movements.c \
			 $(BONUS_SRC_DIR)/cal_index_error.c \
			 $(BONUS_SRC_DIR)/cal_index.c \
			 $(BONUS_SRC_DIR)/initializer/start.c \
			 $(SRC_DIR)/parser/parser.c \
             $(SRC_DIR)/parser/parser_utils.c \
             $(SRC_DIR)/parser/parser_free.c \
             $(SRC_DIR)/movements/push.c \
             $(SRC_DIR)/movements/rotate.c \
             $(SRC_DIR)/movements/rotatereverse.c \
             $(SRC_DIR)/movements/swap.c

LIBFT = $(LIB_DIR)/libft.a

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)

$(BONUS_DIR)/%.o: $(BONUS_DIR)/%.c
	$(CC) $(CFLAGS) $(BONUS_INCLUDES) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

