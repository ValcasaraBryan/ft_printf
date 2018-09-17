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

SRC = ft_printf.c conversion.c conversion_two.c conversion_three.c \
		../ft_putstr_len.c argument_flag.c

OBJET = $(SRC:.c=.o)

OBJET_LIB = ../libft/ft_atoi.o ../ft_atoll.o ../libft/ft_memalloc.o ../libft/ft_strdup.o ../libft/ft_strlen.o ../libft/ft_strndup.o \
			../libft/ft_bzero.o ../libft/ft_strcpy.o ../libft/ft_strncpy.o ../libft/ft_strcat.o ../libft/ft_memset.o ../libft/ft_strjoin.o\
			../ft_lltoa.o ../ft_dotoa.o
HEAD = -I ft_printf.h

FLAG = -Wall -Wextra -Werror

MAIN = main.c

NORM = norm.txt

all : $(EXE)

lib : $(OBJET_LIB)
	@make -C ../

comp : $(SRC) lib main.c
	@gcc $(SRC) $(HEAD) $(OBJET_LIB) $(MAIN) -o $(EXE)

exe : comp
	#------------ execution  ------------#
	@./$(EXE)
	#------------ execution  ------------#

exe_more : comp
	#------------ execution  ------------#
	@./$(EXE) | more
	#------------ execution  ------------#

debug : main.c
	cpp main.c

norm :
	#------- only [*.c] and [*.h] -------#
	@norminette $(SRC) ft_printf.h > $(NORM)

norm_line: norm
	#------- only ["function"] and ["line has"] -------#
	@clear
	@cat norm.txt | grep -v "C++ comment" | grep -v "bad indentation" | grep -v "multiple empty lines"
	@rm $(NORM)

norm_cat: norm 
	@clear
	@cat norm.txt
	@rm $(NORM)

clean :
	@rm -f $(OBJET)
	@make clean -C ../

fclean : clean
	@rm -f $(NAME)
	@rm -f $(EXE)
	@make fclean -C ../

re : fclean all
