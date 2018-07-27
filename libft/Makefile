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

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c\
	ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c\
	ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c\
	ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c\
	ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c\
	ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c\
	ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c\
	ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c\
	ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c\
	ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c\
	ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c\
	ft_tolower.c ft_toupper.c ft_lstdelone.c ft_lstadd.c ft_lstiter.c\
	ft_lstmap.c ft_lstdel.c ft_print_words_tables.c ft_strndup.c\
	ft_print_lst.c ft_strnjoin.c ft_strnchr.c

OBJET = $(SRC:.c=.o)

HEAD = -I libft.h

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

clean :
	@rm -f $(OBJET)

fclean : clean
	@rm -f $(NAME)
	@rm -f $(EXE)
re : fclean all
