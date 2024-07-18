# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hel-zant <hel-zant@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/18 17:39:39 by hel-zant          #+#    #+#              #
#    Updated: 2024/07/18 18:16:44 by hel-zant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	$(wildcard src/*.c utils/*.c)

OBJS		=	${SRCS:.c=.o}

NAME		=	push_swap

LIBFTNAME	=	./ft_printf/libftprintf.a

CC			=	cc

RM			=	rm -f

LIBFTDIR	=	./ft_printf

CFLAGS		=	-Wall -Werror -Wextra -Iincludes -g

all:		${NAME}

%.o %.c
			${CC} ${CFLAGS} -c $< -o $@

$(NAME):$(OBJS)
		make -C $(LIBFTDIR)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFTNAME)

clean:
			${RM} ${OBJS}
			@cd $(LIBFTDIR) && make clean

fclean:		clean
			${RM} ${NAME}
			@cd ${LIBFTDIR} && make fclean

re:			fclean all

.PHONY:		all clean fclean re