# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/25 17:24:42 by mgayduk           #+#    #+#              #
#    Updated: 2019/08/17 15:19:25 by maks             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		:= gcc -Wall -Wextra -Werror -c -g

NAME 	:= libft.a

SRC_DIR := ./sources
INC_DIR := ./includes
OBJ_DIR	:= ./objs
DEP_DIR	:= ./deps

SRC_DIRS := mem_funcs	str_funcs	str_arr_funcs	\
			char_funcs 	list_funcs 	int_funcs		\
			rw_funcs 	ft_printf 	btree_funcs		\
			ft_getopt
SRC_DIRS := $(addprefix $(SRC_DIR)/, $(SRC_DIRS))

# Source files
SEARCH_WILCARDS := $(addsuffix /*.c,$(SRC_DIRS))
SRC := $(notdir $(wildcard $(SEARCH_WILCARDS)))

# Object files
OBJ := $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: prepare_dirs $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

prepare_dirs:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(DEP_DIR)

VPATH := $(SRC_DIRS)

$(OBJ_DIR)/%.o: %.c
	$(CC) $< -I$(INC_DIR) -MMD -MF $(DEP_DIR)/$(notdir $(patsubst %.o,%.d,$@)) -o $@

include $(wildcard $(DEP_DIR)/*.d)

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(DEP_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
