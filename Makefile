# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/19 11:44:14 by jrinna            #+#    #+#              #
#    Updated: 2022/03/23 11:29:55 by jrinna           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

#### LIST ####
LST_SRC := minishell.c 
LST_SRC_BNS := minishell_bonus.c 
LST_OBJ := $(LST_SRC:.c=.o)
LST_OBJ_BNS := $(LST_SRC_BNS:.c=.o)
LST_INC := minishell.h 
LST_INC_BNS := minishell_bonus.h 
#### LSIT ####

#### DIRECTORY ####
DIR_SRC := source
DIR_SRC_BNS := source_bonus
DIR_OBJ := .object
DIR_OBJ_BNS := .object_bonus
DIR_INC := include
DIR_INC_BNS := include_bonus
#### DIRECTORY ####

#### COMPLETE_PATH ####
SRC := $(addprefix $(DIR_SRC)/,$(LST_SRC))
SRC_BNS := $(addprefix $(DIR_SRC_BNS)/,$(LST_SRC_BNS))
OBJ := $(addprefix $(DIR_OBJ)/,$(LST_OBJ))
OBJ_BNS := $(addprefix $(DIR_OBJ_BNS)/,$(LST_OBJ_BNS))
INC := $(addprefix $(DIR_INC)/,$(LST_INC))
INC_BNS := $(addprefix $(DIR_INC_BNS)/,$(LST_INC_BNS))
#### COMPLETE_PATH ####

#### OTHER ####
CC := gcc
CFLAGS := -Wall -Werror -Wextra -g
NAME := minishell
NAME_BNS := minishell_bonus
#### OTHER ####

#### STANDARD_RULE ####
all : $(NAME) $(NAME_BNS)

bonus : $(NAME_BNS)

re : fclean all

clean :
	rm -rf $(DIR_OBJ)
	rm -rf $(DIR_OBJ_BNS)

fclean : clean
	rm -rf $(NAME)
	rm -rf $(NAME_BNS)
#### STANDARD_RULE ####

### CUSTOM_RULE ####
$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $^ -o $(NAME) -lreadline

$(NAME_BNS) : $(OBJ_BNS)
	$(CC) $(CFLAGS) $^ -o $(NAME_BNS) -lreadline

$(DIR_OBJ)/%.o : $(DIR_SRC)/%.c $(INC) Makefile | $(DIR_OBJ)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(DIR_INC)

$(DIR_OBJ_BNS)/%.o : $(DIR_SRC_BNS)/%.c $(INC_BNS) Makefile | $(DIR_OBJ_BNS)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(DIR_INC_BNS)

$(DIR_OBJ) :
	mkdir -p $(DIR_OBJ)

$(DIR_OBJ_BNS) :
	mkdir -p $(DIR_OBJ_BNS)
#### CUSTOM_RULE ####

#### UTILS ####
.PHONY : all bonus re clean fclean
#### UTILS ####
