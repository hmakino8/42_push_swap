# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 03:03:24 by hiroaki           #+#    #+#              #
#    Updated: 2022/11/22 07:38:58 by hiroaki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap
BONUS_NAME		=	checker

ifdef VISUALIZER
	FLAGS		=	-Wall -Wextra -Werror -D VIS
else
	FLAGS		=	-Wall -Wextra -Werror
	#FLAGS			=	-Wall -Wextra -Werror -g -fsanitize=address -fsanitize=integer -fsanitize=undefined
endif

SRCS			=	main/push_swap.c \
					command/exec_cmd.c \
					command/optimize.c \
					command/print_cmd.c \
					command/push.c \
					command/rotate.c \
					command/swap.c \
					sort/distribute.c \
					sort/sort_array.c \
					sort/under7.c \
					sort/over7.c \
					utils/check.c \
					utils/delete.c \
					utils/atoi_split.c \
					utils/split_white_sp.c \
					utils/init.c \
					utils/parse.c \
					utils/list_operate.c \
					utils/cmd_arr_realloc.c \
					utils/exit.c \
					visualizer/print_colored_cmd.c \
					visualizer/visualizer.c

MAND			=	main.c

BONS			=	checker_bonus.c

SRCS_PATH		= 	$(addprefix src/, $(SRCS))
OBJS_PATH		=	$(SRCS_PATH:%.c=%.o)

MAND_PATH		= 	$(addprefix src/main/, $(MAND))
MAND_OBJS_PATH	=	$(MAND_PATH:%.c=%.o)

BONS_PATH		= 	$(addprefix src/bonus/, $(BONS))
BONS_OBJS_PATH	=	$(BONS_PATH:%.c=%.o)

all: 			$(NAME)

$(NAME):		$(OBJS_PATH) $(MAND_OBJS_PATH) $(LIBFT) $(PRINT) $(GNL)
				$(MAKE) -C ./libs/libft
				$(MAKE) -C ./libs/ft_print
				$(MAKE) -C ./libs/gnl
				$(CC) $(FLAGS) $(SRCS_PATH) $(MAND_PATH) $(LIBFT) $(PRINT) $(GNL) -o $(NAME)

$(BONUS_NAME):	$(OBJS_PATH) $(BONS_OBJS_PATH) $(LIBFT) $(PRINT) $(GNL)
				$(MAKE) -C ./libs/libft
				$(MAKE) -C ./libs/ft_print
				$(MAKE) -C ./libs/gnl
				$(CC) $(FLAGS) $(OBJS_PATH) $(BONS_OBJS_PATH) $(LIBFT) $(PRINT) $(GNL) -o $(BONUS_NAME)

LIBFT			=	libs/libft/libft.a
PRINT			=	libs/ft_print/libftprint.a
GNL				=	libs/gnl/libftgnl.a

clean:
				$(MAKE) -C libs/libft clean
				$(MAKE) -C libs/ft_print clean
				$(MAKE) -C libs/gnl clean
				$(RM) $(OBJS_PATH)
				$(RM) $(MAND_OBJS_PATH)
				$(RM) $(BONS_OBJS_PATH)

fclean:			clean
				$(RM) $(LIBFT)
				$(RM) $(PRINT)
				$(RM) $(GNL)
				$(RM) $(NAME)
				$(RM) $(BONUS_NAME)

re:				fclean all

v:
				make VISUALIZER=1

bonus:			$(BONUS_NAME)

.PHONY:			all clean fclean re bonus
