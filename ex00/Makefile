# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 11:12:25 by tgiraudo          #+#    #+#              #
#    Updated: 2023/06/06 14:27:30 by thibaultgir      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLE

NAME			=	Bureaucrat

LIST_SRCS		=	main.cpp		\
					Bureaucrat.cpp	\

LIST_INCS		=	Bureaucrat.hpp	\

# DIRECTORY
DIR_OBJS		=	.objs/

DIR_SRCS		=	srcs/

DIR_INCS		=	includes/

# CONSTANT

PRINT 			= 	@printf

FLAGS			=	-Wall -Wextra -Werror

STD				=	-std=c++98

MAKEFLAGS		+=	--no-print-directory

CC 				=	c++

OBJS 			=	$(patsubst %.cpp, $(DIR_OBJS)%.o, $(SRCS))

SRCS			=	${addprefix ${DIR_SRCS}, ${LIST_SRCS}}

INCLUDES		=	${addprefix ${DIR_INCS}, ${LIST_INCS}}

# COLOR

RED 			=	\033[1;31m
GREEN 			=	\033[1;32m
YELLOW 			=	\033[1;33m
SUPPR   		=	\r\033[2K
DEFAULT 		=	\033[0m

# RULES

${DIR_OBJS}%.o 	:	%.cpp Makefile
				@mkdir -p $(shell dirname $@)
				@${PRINT} "${YELLOW}${SUPPR}Creating ${NAME}'s objects : $@${DEFAULT}"
				@${CC} ${FLAGS} ${STD} -c $< -o $@ 
				@${PRINT} "${GREEN}${SUPPR}Creating ${NAME}'s objects : DONE${DEFAULT}"

${NAME}			:	${OBJS} ${INCLUDES}
				@${PRINT} "${GREEN}${SUPPR}Creating ${NAME}'s objects : DONE${DEFAULT}"
				@${PRINT} "\n${YELLOW}Compiling ${NAME}...${DEFAULT}"
				@${CC} ${OBJS} -I ${INCLUDES} -o ${NAME}
				@${PRINT} "\r${GREEN}Compiling ${NAME} : DONE${DEFAULT}\n\n"

all				:	${NAME}

clean			:
				@${PRINT} "${RED}Deleting objects : DONE\n"
				@rm -rf ${DIR_OBJS}

fclean			:	clean
				@${PRINT} "${RED}Deleting executable : DONE\n\n${DEFAULT}"
				@rm -f ${NAME}

re				:	fclean all

${DIR_OBJS}		:
				mkdir -p ${DIR_OBJS}

.PHONY		: all clean fclean re
