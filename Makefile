
NAME = ft_ssl

# Compiler
CC		= gcc
FLAGS	= -Wall -Wextra -Werror -g

ALGOS = md5 sha256 sha224

# Directories
SRC_DIR := ./sources
OBJ_DIR := ./objects
LFT_DIR := ./libft
INC_DIR := ./includes $(LFT_DIR)/includes
DEP_DIR := ./deps
ALGO_DIRS := $(addprefix $(SRC_DIR)/, $(ALGOS))
SRC_DIRS := $(SRC_DIR) $(ALGO_DIRS)

# Object files
SEARCH_WILCARDS := $(addsuffix /*.c,$(SRC_DIRS))
SRC := $(notdir $(patsubst %.c,%.o,$(wildcard $(SEARCH_WILCARDS))))
OBJ := $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

#includes
INC := $(addprefix -I, $(INC_DIR))

# Libs
LFT := $(LFT_DIR)/libft.a

.PHONY = all clean fclean re

all: prepare_dirs build_lib $(NAME)

$(NAME): $(LFT) $(OBJ)
	$(CC) $(FLAGS) $^ -o $(NAME) $(LFT)

prepare_dirs:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(DEP_DIR)

build_lib:
	@make  -s -C $(LFT_DIR)

VPATH := $(SRC_DIRS)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(FLAGS) $(INC) -MMD -MF $(DEP_DIR)/$(notdir $(patsubst %.o,%.d,$@)) -c $< -o $@

include $(wildcard $(DEP_DIR)/*.d)

clean:
	@make -s -C $(LFT_DIR) clean
	rm -rf $(OBJ_DIR)
	rm -rf $(DEP_DIR)

fclean: clean
	rm -f $(LFT)
	rm -f $(NAME)

re: fclean all

clear:
	rm -f $(NAME)
