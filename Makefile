# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pjerddee <pjerddee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/01 23:56:26 by pjerddee          #+#    #+#              #
#    Updated: 2022/04/17 00:04:39 by pjerddee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	ft_utils1.c\
		ft_utils2.c\
		ft_printf.c

CFLAGS = -Wall -Werror -Wextra

OBJS = $(SRCS:%.c=%.o)

$(NAME): $(OBJS)
	@gcc -c $(CFLAGS) $(SRCS)
	@ar -rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

bonus: $(NAME)

.PHONY: all clean fclean re bonus
