# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsiddiqu <gsiddiqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/25 18:39:04 by gsiddiqu          #+#    #+#              #
#    Updated: 2021/08/16 15:11:10 by gsiddiqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = push_swap

LIBFT = ./libft/libft.a

PRINTFLIB = ./printf/libprintf.a

SOURCES = ft_pushswap.c ft_checkinput.c initialize.c stkfuncs.c stkfuncs2.c movefuncs.c analyse.c \
			initpush.c crunchsol.c insert.c multimoves.c ft_helpfuncs.c ps_utils.c

SIMS = pushswap_sim/pssim.c ft_checkinput.c initialize.c stkfuncs.c stkfuncs2.c movefuncs.c ps_utils.c 

CHECKER = checker_function/checker.c ft_checkinput.c initialize.c stkfuncs.c stkfuncs2.c movefuncs.c ps_utils.c \
			checker_function/checker_utils.c

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTFLIB) $(SOURCES) 
	$(CC) $(CFLAGS) -o $(NAME) $(SOURCES) -Lprintf -lprintf -Llibft -lft
	
$(LIBFT):
	cd libft && $(MAKE) 
	cd libft && $(MAKE) bonus

$(PRINTFLIB):
	cd printf && $(MAKE)

clean:
	cd libft && $(MAKE) clean
	cd printf && $(MAKE) clean
	/bin/rm -f *.o

fclean: clean
	cd libft && $(MAKE) fclean
	cd printf && $(MAKE) fclean
	/bin/rm -f $(NAME)

re: fclean all

debug : $(LIBFT) $(SOURCES) $(PRINTFLIB)
	$(CC) $(CFLAGS) -g -o $(NAME).debug $(SOURCES) -Lprintf -lprintf -Llibft -lft

sim: $(LIBFT) $(PRINTFLIB) $(SIMS) 
	$(CC) $(CFLAGS) -o $(NAME).sim $(SIMS) -Lprintf -lprintf -Llibft -lft

conv: $(LIBFT)
	gcc -o conv pushswap_sim/conv.c -Llibft -lft

bonus: $(LIBFT) $(PRINTFLIB) $(CHECKER) 
	$(CC) $(CFLAGS) -o checker $(CHECKER) -Llibft -lft