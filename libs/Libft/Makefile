# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/06 17:10:58 by hiroaki           #+#    #+#              #
#    Updated: 2022/11/22 06:44:33 by hiroaki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libft.a
CFLAGS			=	-Wall -Wextra -Werror

SRCS			=	ft_isdigit.c \
					ft_isspace.c \
					ft_strlcpy.c \
					ft_strlen.c \
					ft_strdup.c \
					ft_strchr.c \
					ft_substr.c \
					ft_strcmp.c

OBJS			=	$(SRCS:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus
