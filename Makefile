# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile_2                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: huller <huller@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/26 05:09:33 by huller            #+#    #+#              #
#    Updated: 2019/08/26 06:28:15 by huller           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


GRN         =   \x1B[32m
MAG         =   \x1B[35m
RES         =   \x1B[0m

NAME1			=	checker
NAME2			=	push_swap

# CHECKER

SRC1_PATH		=	srcs/
OBJ1_PATH		=	srcs_checker/obj/
INC1_PATH		=	includes/

# PUSH_SWAP

SRC2_PATH		=	srcs/
OBJ2_PATH		=	srcs_checker/obj/
INC2_PATH		=	includes/

# LIBFT

LIB_PATH		=	libft/
LIB_INC_PATH	=	libft/includes/

# CHECKER
SRC1_NAME		=	checker.c apply_instructions.c apply_instructions_2.c\
					visualizer.c get_instructions.c reader_checker.c\

OBJ1_NAME		=	$(SRC1_NAME:.c=.o)
INC1_NAME		=	checker.h

# PUSH_SWAP

SRC2_NAME		=	push_swap.c\

OBJ2_NAME		=	$(SRC2_NAME:.c=.o)
INC2_NAME		=	checker.h

# LIBFT

LIB_NAME		=	libft.a
LIB_INC_NAME	=	libft.h

# CHECKER

OBJ1			=	$(addprefix $(OBJ1_PATH), $(OBJ1_NAME))
INC1			=	$(addprefix $(INC1_PATH), $(INC1_NAME))

# PUSH_SWAP

OBJ2			=	$(addprefix $(OBJ2_PATH), $(OBJ2_NAME))
INC2			=	$(addprefix $(INC2_PATH), $(INC2_NAME))
INC3			=	$(addprefix $(INC3_PATH), $(INC3_NAME))

# LIBFT

LIB				=	$(addprefix $(LIB_PATH), $(LIB_NAME))
LIB_INC			=	$(addprefix $(LIB_INC_PATH), $(LIB_INC_NAME))

.PHONY:				all $(LIB_NAME) clean fclean re


all:				$(LIB_NAME) $(NAME1) $(NAME2)

# LIBFT

$(LIB_NAME):
					@make -C $(LIB_PATH)
# CHECKER

$(NAME1):			$(LIB) $(OBJ1)
					@gcc -Wall -Wextra -Werror \
						$(OBJ1) -L $(LIB_PATH) -lft -o $(NAME1)
					@echo "$(GRN)CHECKER IS READY!$(RES)"
# PUSH_SWAP

$(NAME2):			$(LIB) $(OBJ2)
					@gcc -Wall -Wextra -Werror \
						$(OBJ2) -L $(LIB_PATH) -lft -o $(NAME2)
					@echo "$(GRN)PUSH SWAP IS READY!$(RES)"

# LIBFT

$(LIB):				$(LIB_NAME)

#CHECKER

$(OBJ1_PATH)%.o:	$(SRC1_PATH)%.c $(INC1) $(LIB_INC)
					@mkdir -p $(OBJ1_PATH)
					@gcc -Wall -Wextra -Wextra \
						-I $(INC1_PATH) -I $(LIB_INC_PATH) -o $@ -c $<
# PUSH_SWAP
$(OBJ2_PATH)%.o:	$(SRC2_PATH)%.c $(INC2) $(LIB_INC)
					@mkdir -p $(OBJ2_PATH)
					@gcc -Wall -Wextra -Wextra \
						-I $(INC2_PATH) -I $(LIB_INC_PATH) -o $@ -c $<


clean:
					@make -C $(LIB_PATH) fclean
					@rm -f $(OBJ1) $(OBJ2) $(OBJ3)
					@rm -rf $(OBJ1_PATH) $(OBJ2_PATH) $(OBJ3_PATH)

fclean:				clean
					@rm -f $(NAME1) $(NAME2)
					@echo "$(MAG)Delete [ $(NAME1) ] OK"
					@echo "Delete [ $(NAME2) ] OK$(RES)"

re:					fclean all