# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/25 23:01:19 by brvalcas          #+#    #+#              #
#    Updated: 2018/04/25 23:01:22 by brvalcas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a

EXE = executable

SRC = ft_printf.c




OBJET = $(SRC:.c=.o)

HEAD = -I ft_printf.h

FLAG = -Wall -Wextra -Werror

all : lib $(NAME)

lib :
	#------------ make libft ------------#
	@make -C ../libft
	#------------ make libft ------------#
$(NAME) : $(OBJET)
	@ar rc $@ $^
	@ranlib $@

%.o:%.c %.h
	@clang $(FLAG) -o $@ -c $<

comp : lib $(NAME) main.c
	@gcc $(NAME) main.c -o $(EXE)
exe : comp
	#------------ execution  ------------#
	@./$(EXE)
	#------------ execution  ------------#
debug : main.c
	cpp main.c
norm :
	#------- only [*.c] and [*.h] -------#
	@norminette *.c *.h

clean :
	@rm -f $(OBJET)
	@make clean -C ../libft

fclean : clean
	@rm -f $(NAME)
	@rm -f $(EXE)
	@make fclean -C ../libft

re : fclean all
