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

SRC = srcs/ft_printf.c srcs/argument_flag.c srcs/init_list.c\
		srcs/tab_option.c srcs/option_value.c srcs/free_data.c\
		srcs/conversion.c srcs/conversion_two.c \
		srcs/conversion_three.c srcs/conversion_four.c

OBJET = $(SRC:.c=.o)

OBJET_LIB = libft/libft.a

HEAD = -I ft_printf.h

FLAG = -Wall -Wextra -Werror

MAIN = main.c

NORM = norm.txt

all : $(NAME)

$(NAME) : $(OBJET)
	make -C libft
	@libtool -static -o $@ $(OBJET_LIB) $^
	@ranlib $@

%.o:%.c %.h
	@gcc $(FLAG) $(HEAD) -o $@ -c $< 

comp : $(NAME) main.c
	@gcc $(SRC) $(HEAD) $(OBJET_LIB) $(MAIN) -o $(EXE)
	@gcc $(SRC) $(HEAD) $(OBJET_LIB) main_2.c -o ft_printf_2

exe : $(NAME) comp
	#------------ execution  ------------#
	@./$(EXE)
	@./ft_printf_2
	#------------ execution  ------------#

exe_more : comp
	#------------ execution  ------------#
	@./$(EXE) | more
	#------------ execution  ------------#
exe_grep : comp
	#------------ execution  ------------#
	@./$(EXE) | grep "len -- OK --"
	#------------ execution  ------------#
exe_grep_no : comp
	#------------ execution  ------------#
	@./$(EXE) | grep "len // NO //"
	#------------ execution  ------------#

debug : main.c
	cpp main.c

norm :
	#------- only [all.c] and [all.h] -------#
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
	@make clean -C libft

fclean : clean
	@rm -f $(NAME)
	@rm -f $(EXE)
	@make fclean -C libft

re : fclean all

re_printf :
	@rm -f $(OBJET)
	@rm -f $(NAME)
	@rm -f $(EXE)
	make