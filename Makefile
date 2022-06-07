# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkempf-e <tkempf-e@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/07 17:56:59 by tkempf-e          #+#    #+#              #
#    Updated: 2022/06/07 18:01:12 by tkempf-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_atoi.c ps_arguments_tests.c ps_lists_utils.c ps_operations.c \
			ps_radix_sort.c ps_utils.c push_swap.c

OBJS	=	$(SRCS:.c=.o)

GCC 	=	gcc

RM		=	rm -f

FLAGS	=	-Wall -Werror -Wextra

NAME	=	push_swap

.c.o:
	$(GCC) $(FLAGS) -c -I. $< -o ${<:.c=.o}

$(NAME):	$(OBJS)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME) a.out

re:			fclean all

.PHONY:		all clean fclean re