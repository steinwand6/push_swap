# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tishigak <tishigak@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/11 03:09:50 by tishigak          #+#    #+#              #
#    Updated: 2021/08/17 14:09:06 by tishigak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CC			= gcc
CFLAGS	= -Wall -Werror -Wextra
SRCS		= element.c ft_atol.c ope1.c stack.c utils.c \
				main.c
HEADERPATH	= -I ./include

OBJS	= $(SRCS:.c=.o)
OBJSB	= $(SRCB:.c=.o)
ifdef WITH_BONUS
ALL_OBJS = $(OBJS) $(OBJSB)
else
ALL_OBJS = $(OBJS)
endif

all:	$(NAME)

clean:
	rm -f $(OBJS)
	rm -f $(OBJSB)
	@make -C libft clean

fclean:	clean
	rm -f $(NAME)
	@make -C libft fclean

re:	fclean all

#bonus:
#	@$(MAKE) WITH_BONUS=1 $(NAME)

%.o:	%.c
	@make -C ./libft
	$(CC) -c $(CFLAGS) -o $@ $< $(HEADERPATH)

$(NAME):	$(ALL_OBJS)
	gcc -o  $(NAME) $(ALL_OBJS) ./libft/libft.a

.PHONY:	all clean fclean re bonus

vpath %.c src
