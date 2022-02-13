NAME = push_swap.a

SRC_DIR = ./src

CMD_DIR = ./src/commands

UTILS_DIR = ./src/utils

SRC_MAIN = $(SRC_DIR)/push_swap.c $(SRC_DIR)/select_swap.c

SRC_UTILS = $(UTILS_DIR)/fill_stack.c $(UTILS_DIR)/algorithm_utils.c $(UTILS_DIR)/print_commands.c

SRC_COMMANDS = $(CMD_DIR)/swap.c $(CMD_DIR)/push.c $(CMD_DIR)/rotate.c $(CMD_DIR)/reverse_rotate.c

SRC = $(SRC_MAIN) $(SRC_UTILS) $(SRC_COMMANDS)

OBJ = $(SRC:%.c=%.o)

CC = gcc

RM = rm -rf

HEADER = push_swap.h

CFLAGS = -Wall -Werror -Wextra

LIB = libft.a

LIB_DIR = ./libft

BINARY = push_swap

.PHONY : all clean fclean re

all : $(LIB) $(NAME) $(BINARY)

$(BINARY)	:	$(LIB) $(NAME)
				$(CC) -o $(BINARY) $(SRC_DIR)/push_swap.c $(NAME)

$(NAME) : $(OBJ) $(HEADER) $(LIB_DIR)/$(LIB)
			ar rcs $(NAME) $? $(LIB_DIR)/*.o

$(LIB) :
		cd $(LIB_DIR) && $(MAKE) all

%.o : %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean :
		$(RM) $(OBJ)
		cd $(LIB_DIR) && $(MAKE) clean

fclean : clean
		$(RM) $(NAME)
		cd $(LIB_DIR) && $(MAKE) fclean

re     : fclean all