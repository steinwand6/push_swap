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
SRCS		= element.c ft_atol.c ope_base.c stack.c utils.c coordinate_compression.c \
				init_info.c operations1.c operations2.c utils2.c free_funcs.c \
				smart_operations.c solver_with_small.c main.c push_swap.c utils3.c
HEADERPATH	= -I ./include
OBJDIR		= ./obj
LIBFT		= ./libft/libft.a

OBJS	= $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
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
	rm -f $(LIBFT)

re:	fclean all

#bonus:
#	@$(MAKE) WITH_BONUS=1 $(NAME)

$(OBJDIR)/%.o:	%.c
	@[ -d $(OBJDIR) ]
	$(CC) -c $(CFLAGS) -o $@ $< $(HEADERPATH)

$(LIBFT):
	@make -C ./libft

$(NAME):	$(LIBFT) $(ALL_OBJS)
	gcc -o  $(NAME) $(ALL_OBJS) ./libft/libft.a

#debug:		$(ALL_OBJS)
#	gcc --sanitize=leak -o  $(NAME) $(ALL_OBJS) ./libft/libft.a

.PHONY:	all clean fclean re bonus

vpath %.c src
