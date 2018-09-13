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

NAME = libftprintf.a

EXE = ft_printf

SRC = ft_printf.c fonction.c conversion.c conversion_two.c conversion_three.c \
		../ft_putstr_len.c argument_flag.c

OBJET = $(SRC:.c=.o)

OBJET_LIB = ../libft/ft_atoi.o ../ft_atoll.o ../libft/ft_memalloc.o ../libft/ft_strdup.o ../libft/ft_strlen.o ../libft/ft_strndup.o \
			../libft/ft_bzero.o ../libft/ft_strcpy.o ../libft/ft_strncpy.o ../libft/ft_strcat.o ../libft/ft_memset.o ../libft/ft_strjoin.o\
			../ft_lltoa.o
HEAD = -I ft_printf.h

FLAG = -Wall -Wextra -Werror

MAIN = main.c

all : $(EXE)

comp : $(SRC) main.c
	@gcc $(SRC) $(HEAD) $(OBJET_LIB) $(MAIN) -o $(EXE)

exe : comp
	#------------ execution  ------------#
	@./$(EXE)
	#------------ execution  ------------#

debug : main.c
	cpp main.c
norm :
	clear
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
