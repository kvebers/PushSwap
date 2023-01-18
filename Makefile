# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 15:18:33 by kvebers           #+#    #+#              #
#    Updated: 2023/01/18 13:17:29 by kvebers          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
CFLAGS	= -Wall -Wextra -Werror
CC		= cc
SRC	=	src/start.c src/protection.c src/init_data.c src/protection1.c \
		src/free.c src/sort.c fun/pa.c fun/pb.c fun/ra.c fun/rb.c fun/rr.c \
		fun/rra.c fun/rrb.c fun/rrr.c fun/sa.c fun/sb.c fun/ss.c \
		src/sort_utils.c fun/fix.c 
RM = 		rm -f
SRC_O	= $(SRC:%.c=%.o)

all:  $(NAME)

$(NAME): $(SRC_O)
	make -C ./libft
	$(CC) $(CFLAGS) $(SRC_O) libft/libft.a -o $(NAME)

clean:
	@make clean -C libft/
	- @$(RM) $(SRC_O)

fclean: clean
	@make fclean -C libft/
	- @$(RM) ${NAME}

re: fclean all

.PHONY: clean fclean all re 