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

NAME = libft.a

EXE = executable

SRC = srcs/ft_atoi.c srcs/ft_bzero.c srcs/ft_isalnum.c srcs/ft_strnchr.c\
	srcs/ft_isalpha.c srcs/ft_isascii.c srcs/ft_isdigit.c srcs/ft_isprint.c\
	srcs/ft_itoa.c srcs/ft_lstnew.c srcs/ft_memalloc.c srcs/ft_memccpy.c\
	srcs/ft_memchr.c srcs/ft_memcmp.c srcs/ft_memcpy.c srcs/ft_memdel.c\
	srcs/ft_memmove.c srcs/ft_memset.c srcs/ft_putchar.c srcs/ft_putchar_fd.c\
	srcs/ft_putendl.c srcs/ft_putendl_fd.c srcs/ft_putnbr.c srcs/ft_putnbr_fd.c\
	srcs/ft_putstr.c srcs/ft_putstr_fd.c srcs/ft_strcat.c srcs/ft_strchr.c\
	srcs/ft_strclr.c srcs/ft_strcmp.c srcs/ft_strcpy.c srcs/ft_strdel.c\
	srcs/ft_strdup.c srcs/ft_strequ.c srcs/ft_striter.c srcs/ft_striteri.c\
	srcs/ft_strjoin.c srcs/ft_strlcat.c srcs/ft_strlen.c srcs/ft_strmap.c\
	srcs/ft_strmapi.c srcs/ft_strncat.c srcs/ft_strncmp.c srcs/ft_strncpy.c\
	srcs/ft_strnequ.c srcs/ft_strnew.c srcs/ft_strnstr.c srcs/ft_strrchr.c\
	srcs/ft_strsplit.c srcs/ft_strstr.c srcs/ft_strsub.c srcs/ft_strtrim.c\
	srcs/ft_tolower.c srcs/ft_toupper.c srcs/ft_lstdelone.c srcs/ft_lstadd.c\
	srcs/ft_lstiter.c srcs/ft_lstmap.c srcs/ft_lstdel.c srcs/ft_strnjoin.c\
	srcs/ft_print_words_tables.c srcs/ft_strndup.c srcs/ft_print_lst.c\
	srcs/ft_lltoa.c srcs/ft_atoll.c srcs/ft_dotoa.c srcs/ft_ulltoa_base.c\
	srcs/ft_atoull.c srcs/ft_lltoa_base.c srcs/ft_strjoin_free.c\
	srcs/ft_ulltoa.c srcs/ft_putstr_len.c srcs/ft_memjoin.c srcs/ft_putwchar.c\
	srcs/ft_wmemset.c

OBJET = $(SRC:.c=.o)

HEAD = -I includes/libft.h

FLAG = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJET)
	@ar rc $@ $^
	@ranlib $@

%.o:%.c %.h
	@clang $(FLAG) -o $@ -c $<

comp : $(NAME) main.c
	@gcc $(NAME) main.c -o $(EXE)
exe : comp
	@./$(EXE)
debug : main.c
	cpp main.c

norm :
	#------- only [*.c] and [*.h] -------#
	@norminette **/*.[ch] > norm.txt

norm_line: norm
	#------- only ["function"] and ["line has"] -------#
	@clear
	@cat norm.txt | grep -v "C++ comment" | grep -v "bad indentation" | grep -v "multiple empty lines"
	@rm norm.txt

norm_cat: norm 
	@clear
	@cat norm.txt
	@rm norm.txt

clean :
	@rm -f $(OBJET)

fclean : clean
	@rm -f $(NAME)
	@rm -f $(EXE)
re : fclean all
