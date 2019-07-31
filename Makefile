NAME = ft_ssl

# Compiler
CC		= gcc
FLAGS	= -Wall -Wextra -Werror -g

# Directories
SRC_DIR := ./sources
OBJ_DIR := ./objects
INC_DIR := ./includes ./libft/includes
LFT_DIR := ./libft
MD5_DIR := $(SRC_DIR)/md5

# Source files
SRC :=	main.c

# MD5 sources
MD5_SRC := md5.c md5_core.c md5_parser.c

SRC := $(SRC) $(MD5_SRC)

# Object files
OBJ := $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

#includes
INC := $(addprefix -I, $(INC_DIR))

# Libs
LFT := libft.a

.PHONY = all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LFT_DIR) all
	$(CC) $(FLAGS) $(OBJ) $(LFT_DIR)/$(LFT) $(INC) -o $(NAME)

VPATH := $(SRC_DIR) $(MD5_DIR)

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) $(INC) -c $< -o $@

clean:
	make -C $(LFT_DIR) clean
	rm -rf $(OBJ)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(LFT_DIR)/$(LFT)
	rm -rf $(NAME)

re: fclean all

clear:
	rm -rf $(NAME)

build: clear all