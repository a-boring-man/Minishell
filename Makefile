# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/19 11:44:14 by jrinna            #+#    #+#              #
#    Updated: 2022/07/22 18:53:52 by jrinna           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

#### LIST ####
LST_SRC_BNS := built_in_bonus.c calloc_bonus.c cd_bonus.c cmd_executor_bonus.c cmd_tokenizer_bonus.c echo_bonus.c env_bonus.c env_check_bonus.c env_init_bonus.c executor_bonus.c exit_bonus.c expand_line_2_bonus.c expand_line_bonus.c export_bonus.c free_bonus.c ft_dprintf_bonus.c getenv_bonus.c is_in_charset_bonus.c isalnum_bonus.c itoa_bonus.c linklist_env2_bonus.c linklist_env_bonus.c max_min_bonus.c minishell_bonus.c moulinator_bonus.c parsing_bonus.c pipex_executor_bonus.c pipex_tokenizer_bonus.c precall_cd_bonus.c precall_echo_bonus.c precall_exit_bonus.c precall_export_bonus.c precall_unset_bonus.c pwd_bonus.c reverse_env_bonus.c signal_bonus.c split_bonus.c strcmp_bonus.c strdup_bonus.c strjoin_bonus.c strlen_bonus.c strtrim_bonus.c substr_bonus.c super_atol_bonus.c super_split_bonus.c termios_stuff_bonus.c unset_bonus.c utils_bonus.c valid_env_var_name_bonus.c 
LST_SRC := built_in.c calloc.c cd.c cmd_executor.c cmd_tokenizer.c echo.c env.c env_check.c env_init.c executor.c exit.c expand_line.c expand_line_2.c export.c free.c ft_dprintf.c getenv.c is_in_charset.c isalnum.c itoa.c linklist_env.c linklist_env2.c max_min.c minishell.c moulinator.c parsing.c pipex_executor.c pipex_tokenizer.c precall_cd.c precall_echo.c precall_exit.c precall_export.c precall_unset.c pwd.c reverse_env.c signal.c split.c strcmp.c strdup.c strjoin.c strlen.c strtrim.c substr.c super_atol.c super_split.c termios_stuff.c unset.c utils.c valid_env_var_name.c 
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
DIR_BIN := binary
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
CFLAGS := -Wall -Werror -Wextra -g3 #-fsanitize=address
LDFLAGS := -L$(HOME)/homebrew/opt/readline/lib
CPPFLAGS := -I$(HOME)/homebrew/opt/readline/include
NAME := $(DIR_BIN)/minishell
NAME_BNS := $(DIR_BIN)/minishell_bonus
#### OTHER ####

#### STANDARD_RULE ####
all : $(NAME_BNS) $(NAME)

bonus : $(NAME_BNS)

re : fclean all

clean :
	rm -rf $(DIR_OBJ)
	rm -rf $(DIR_OBJ_BNS)

fclean : clean
	rm -rf $(DIR_BIN)
#### STANDARD_RULE ####

### CUSTOM_RULE ####
$(NAME) : $(OBJ) | $(DIR_BIN)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $^ -o $(NAME) -lreadline

$(NAME_BNS) : $(OBJ_BNS) | $(DIR_BIN)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $^ -o $(NAME_BNS) -lreadline

$(DIR_OBJ)/%.o : $(DIR_SRC)/%.c $(INC) Makefile | $(DIR_OBJ)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@ -I $(DIR_INC)

$(DIR_OBJ_BNS)/%.o : $(DIR_SRC_BNS)/%.c $(INC_BNS) Makefile | $(DIR_OBJ_BNS)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@ -I $(DIR_INC_BNS)

$(DIR_OBJ) :
	mkdir -p $(DIR_OBJ)

$(DIR_OBJ_BNS) :
	mkdir -p $(DIR_OBJ_BNS)

$(DIR_BIN) :
	mkdir -p $(DIR_BIN)
#### CUSTOM_RULE ####

#### UTILS ####
.PHONY : all bonus re clean fclean
#### UTILS ####
