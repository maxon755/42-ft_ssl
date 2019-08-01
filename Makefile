
NAME = ft_ssl

# Compiler
CC		= gcc
FLAGS	= -Wall -Wextra -Werror -g

# Directories
SRC_DIR := ./sources
OBJ_DIR := ./objects
LFT_DIR := ./libft
INC_DIR := ./includes $(LFT_DIR)/includes
DEP_DIR := ./deps
MD5_DIR := $(SRC_DIR)/md5
SRC_DIR := $(SRC_DIR) $(MD5_DIR) 

# Object files
SEARCH_WILCARDS := $(addsuffix /*.c,$(SRC_DIR))
SRC := $(notdir $(patsubst %.c,%.o,$(wildcard $(SEARCH_WILCARDS))))
OBJ := $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

#includes
INC := $(addprefix -I, $(INC_DIR))

# Libs
LFT := $(LFT_DIR)/libft.a

.PHONY = all clean fclean re

all:  prepare_dirs build_lib $(NAME)

$(NAME): $(LFT) $(OBJ)
	$(CC) $(FLAGS) $(LFT) $^ -o $(NAME)

prepare_dirs:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(DEP_DIR)

build_lib:
	@make  -s -C $(LFT_DIR)

VPATH := $(SRC_DIR)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(FLAGS) $(INC) -MMD -MF $(DEP_DIR)/$(notdir $(patsubst %.o,%.d,$@)) -c $< -o $@

include $(wildcard $(DEP_DIR)/*.d)

clean:
	@make -s -C $(LFT_DIR) clean
	rm -rf $(OBJ_DIR)
	rm -rf $(DEP_DIR)

fclean: clean
	rm -rf $(LFT)
	rm -rf $(NAME)

re: fclean all

clear:
	rm -rf $(NAME)
