# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivan-mel <ivan-mel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 12:51:22 by ivan-mel          #+#    #+#              #
#    Updated: 2023/04/11 18:58:06 by ivan-mel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		:= 	so_long
LIBS		:=	./libft/libft.a
HEADER		:=	-I libft -I MLX42/include/MLX42
#MLX
MLX			:=	./MLX42
LIBS_MLX	:=	$(MLX)/build/libmlx42.a -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
#UTILS
RM 			:=	rm -rf
FLAGS 		:=	-Wall -Werror -Wextra
SRC			:=	create_map.c \
				create_map_utils.c \
				main.c \
				map_parsing.c \
				map_parsing2.c \
				map_parsing3.c \
				moving.c \
				window.c \
				images.c \
				keyboard.c \
				free.c 
#BONUS
# SRCB		:=	

#OBJB_FILES	=	${SRCB:.c=.o}
OBJ_DIR		:=	./obj
SRC_DIR 	:= 	./src
# Reset
Color_Off	=	"\033[0m"			# Text Reset
# Regular Colors
Black		=	"\033[0;30m"		# Black
Red			=	"\033[0;31m"		# Red
Green		=	"\033[0;32m"		# Green
Yellow		=	"\033[0;33m"		# Yellow
Blue		=	"\033[0;34m"		# Blue
Purple		=	"\033[0;35m"		# Purple
Cyan		=	"\033[0;36m"		# Cyan
White		=	"\033[0;37m"		# White
# Avoid relinking in bonus
# ifdef WITH_BONUS
# 	NAME	:=	checker
# 	OBJ		:=	$(addprefix $(OBJ_DIR)/,$(SRCB:.c=.o))
# else
# 	OBJ		:=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
# endif
# Add obj directory to obj path
OBJ		:= 	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
SRC		:=	$(addprefix $(SRC_DIR)/,$(SRC))

all: libmlx ${NAME}

libmlx:
	@cmake $(MLX) -B $(MLX)/build && make -C $(MLX)/build -j4
	
${NAME}: ${OBJ}
	@echo ${Blue} Building ${NAME} ${Color_Off}
	@${MAKE} -C libft
	@${MAKE} -C MLX42/build
	@${CC} $^ ${LIBS} ${LIBS_MLX} ${FLAGS} -o ${NAME}
	@echo ${Green} Complete 😊 ${Color_off}

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) | $(OBJ_DIR)
	@echo ${Blue} Compiling: $< ${Color_Off}
	@${CC} ${FLAGS} ${HEADER} -c $< -o $@


$(OBJ_DIR):
	@mkdir $@

# Set 'WITH_BONUS' option to make with bonus
# bonus:
# 	@${MAKE} WITH_BONUS=1 all

clean:
	@echo ${Yellow} Deleting ${OBJ_DIR} ${Color_off}
	@${MAKE} -C libft clean
	@${MAKE} -C ${MLX}/build clean
	@${RM} ${OBJ_DIR}

fclean: clean
	@echo ${Yellow} Deleting ${NAME} ${Color_off}
	@${MAKE} -C libft fclean
	@${RM} ${MLX}/build 
	@${RM} ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re libmlx