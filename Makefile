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

SRC = ft_printf.c params.c fonction_of_conversion.c conversion.c\
		params_two.c flag.c argument_flag.c ft_putstr_len.c option_flag.c\
		ft_ulltoa.c ft_atoull.c mid_body.c conversion_two.c\
		ft_lltoa.c ft_atoll.c flag_h_l.c valid_flag.c conversion_three.c\
		ft_lltoa_base.c ft_buff_printf.c ft_ulltoa_base.c ft_dotoa.c

OBJET = $(SRC:.c=.o)

OBJET_LIB = libft/ft_atoi.o libft/ft_itoa.o\
			libft/ft_memalloc.o libft/ft_memset.o\
			libft/ft_putstr.o libft/ft_strcat.o\
			libft/ft_strdup.o libft/ft_strlen.o\
			libft/ft_strncpy.o libft/ft_strndup.o\
			libft/ft_bzero.o libft/ft_putchar.o\
			libft/ft_strcpy.o

HEAD = -I ft_printf.h

FLAG = -Wall -Wextra -Werror

MAIN = main.c

all : $(NAME)

lib :
	clear
	#------------ make libft ------------#
	@make -C libft
	#------------ make libft ------------#

$(NAME) : $(OBJET) $(OBJET_LIB)
	@ar rc $@ $^
	@ranlib $@

%.o:%.c %.h
	@clang $(FLAG) $(HEAD) -o $@ -c $< 

comp : lib $(NAME) main.c
	@gcc $(NAME) $(HEAD) $(MAIN) -o $(EXE)
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
	@make clean -C libft

fclean : clean
	@rm -f $(NAME)
	@rm -f $(EXE)
	@make fclean -C libft

re : fclean all
