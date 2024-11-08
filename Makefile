# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/03 22:28:56 by gabriel           #+#    #+#              #
#    Updated: 2024/11/08 13:28:17 by gabriel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
# Colours
################################################################################

RST				= \033[0;39m
GRAY			= \033[0;90m
RED				= \033[0;91m
GREEN			= \033[0;92m
YELLOW			= \033[0;93m
BLUE			= \033[0;94m
MAGENTA			= \033[0;95m
CYAN			= \033[0;96m
WHITE			= \033[0;97m

################################################################################
# Folders
################################################################################

GNL_DIR		= ./gnl
GNL_LIB		= ${GNL_DIR}/bin/libgnl.a
LIBFT_DIR 	= ./libft
LIBFT_LIB 	= ${LIBFT_DIR}/bin/libft.a

SRC_DIR = ./src
OBJ_DIR = ./obj
BIN_DIR = ./bin
INC_DIR = ./include

PROJ_DIRS = ${OBJ_DIR} ${BIN_DIR}

################################################################################
# Compiler stuff
################################################################################

NAME		= minishell
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -MMD -MP

ifdef	CSANITIZE
	SANITIZE_FLAGS	= -g3 -fsanitize=address -fsanitize=leak
endif

LIBS_FLAG = -lreadline -lft -lgnl 

SRC = 	main.c							\
		builtins/builtin_exit.c			\
		builtins/builtins_utils.c		\
		env/env_utils.c					\
		env/environment.c				\
		file/fd.c						\
		tokenizer/token.c				\
		tokenizer/tokenizer.c			\
		tokenizer/tokenizer_utils.c		\
		shell/minishell.c				\
		shell/minishell_utils.c			\
		utils/pair.c


#HDR =	builtin
#		colours.h			\
		config.h			\
		executor.h			\
		expansor.h			\
		lexer.h				\
		minishell.h			\
		parser.h			\
		signal_manager.h

SRCS = $(patsubst %.c,${SRC_DIR}/%.c, ${SRC})
OBJS = $(patsubst %.c,${OBJ_DIR}/%.o, ${SRC})
DEPS = $(patsubst %.c,${OBJ_DIR}/%.d, ${SRC})


all: ${PROJ_DIRS} ${BIN_DIR}/${NAME}

${PROJ_DIRS}:
	@mkdir -p ${OBJ_DIR}
	@mkdir -p ${OBJ_DIR}/builtins/
	@mkdir -p ${OBJ_DIR}/env/
	@mkdir -p ${OBJ_DIR}/file/
	@mkdir -p ${OBJ_DIR}/shell/
	@mkdir -p ${OBJ_DIR}/tokenizer/
	@mkdir -p ${OBJ_DIR}/utils/
	@mkdir -p ${BIN_DIR}

update_libs:
	@echo "\t${CYAN}Updating libs...${RST}"
	@git  submodule update --init --remote --recursive

${LIBFT_LIB}:
	@echo "\t${CYAN}Making libft...${RST}"
	@make --no-print-directory all -C ${LIBFT_DIR} 

${GNL_LIB}:
	@echo "\t${CYAN}Making gnl...${RST}"
	@make --no-print-directory all -C ${GNL_DIR} 
	
${BIN_DIR}/${NAME}: update_libs ${LIBFT_LIB} ${GNL_LIB} ${OBJS} Makefile
	@echo "${CYAN}Linking ${NAME}...${RST}"
	@${CC} ${CFLAGS} ${SANITIZE_FLAGS} -L ${LIBFT_DIR}/bin -L ${GNL_DIR}/bin -o ${BIN_DIR}/${NAME} ${OBJS} ${LIBS_FLAG}


${OBJ_DIR}/%.o : ${SRC_DIR}/%.c Makefile
	@echo "\t${YELLOW}Compiling ${RST} $<"
	@${CC} ${CFLAGS} ${SANITIZE_FLAGS} -I ${INC_DIR} -I ${LIBFT_DIR}/include -I ${GNL_DIR}/include -c $< -o $@ 

clean:
	@make --no-print-directory clean -C ${LIBFT_DIR}
	@make --no-print-directory clean -C ${GNL_DIR}
	@rm -rf ${OBJ_DIR}

fclean: clean
	@make --no-print-directory fclean -C ${LIBFT_DIR}
	@make --no-print-directory fclean -C ${GNL_DIR}
	@rm -rf ${BIN_DIR}

re: fclean all

-include ${DEPS}

.PHONY: all clean fclean re update_libs