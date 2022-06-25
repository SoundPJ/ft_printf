# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/01 23:56:26 by pjerddee          #+#    #+#              #
#    Updated: 2022/06/26 02:23:21 by pjerddee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	./ft_put/ft_putchar.c	\
		./ft_put/ft_putlu.c	\
		./ft_put/ft_putnbr.c	\
		./ft_put/ft_putp.c	\
		./ft_put/ft_putpercent.c	\
		./ft_put/ft_putstr.c	\
		ft_utils1.c			\
		ft_flag1.c			\
		ft_printf.c			

# CFLAGS = -Wall -Werror -Wextra

OBJS = $(SRCS:%.c=%.o)

$(NAME): $(OBJS)
	# @gcc -c $(CFLAGS) $(SRCS)
	@gcc -c $(SRCS)
	@ar -rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	@rm -f *.o
	@rm -f */*.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

bonus: $(NAME)

.PHONY: all clean fclean re bonus
