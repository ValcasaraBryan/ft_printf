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

SRC =	srcs/ft_is/ft_isalnum.c\
		srcs/ft_is/ft_isalpha.c\
		srcs/ft_is/ft_isascii.c\
		srcs/ft_is/ft_isdigit.c\
		srcs/ft_is/ft_isprint.c\
		\
		srcs/ft_lst/ft_lstadd.c\
		srcs/ft_lst/ft_lstdel.c\
		srcs/ft_lst/ft_lstdelone.c\
		srcs/ft_lst/ft_lstiter.c\
		srcs/ft_lst/ft_lstmap.c\
		srcs/ft_lst/ft_lstnew.c\
		\
		srcs/ft_mem/ft_bzero.c\
		srcs/ft_mem/ft_memalloc.c\
		srcs/ft_mem/ft_memccpy.c\
		srcs/ft_mem/ft_memchr.c\
		srcs/ft_mem/ft_memcmp.c\
		srcs/ft_mem/ft_memcpy.c\
		srcs/ft_mem/ft_memdel.c\
		srcs/ft_mem/ft_memjoin.c\
		srcs/ft_mem/ft_memmove.c\
		srcs/ft_mem/ft_memset.c\
		\
		srcs/ft_print/ft_print_lst.c\
		srcs/ft_print/ft_print_words_tables.c\
		\
		srcs/ft_put/ft_putchar.c\
		srcs/ft_put/ft_putchar_fd.c\
		srcs/ft_put/ft_putchar_len.c\
		srcs/ft_put/ft_putendl.c\
		srcs/ft_put/ft_putendl_fd.c\
		srcs/ft_put/ft_putnbr.c\
		srcs/ft_put/ft_putnbr_fd.c\
		srcs/ft_put/ft_putstr.c\
		srcs/ft_put/ft_putstr_fd.c\
		srcs/ft_put/ft_putstr_len.c\
		\
		srcs/ft_str/ft_strcat.c\
		srcs/ft_str/ft_strchr.c\
		srcs/ft_str/ft_strclr.c\
		srcs/ft_str/ft_strcmp.c\
		srcs/ft_str/ft_strcpy.c\
		srcs/ft_str/ft_strdel.c\
		srcs/ft_str/ft_strdup.c\
		srcs/ft_str/ft_strequ.c\
		srcs/ft_str/ft_striter.c\
		srcs/ft_str/ft_striteri.c\
		srcs/ft_str/ft_strjoin.c\
		srcs/ft_str/ft_strjoin_free.c\
		srcs/ft_str/ft_strlcat.c\
		srcs/ft_str/ft_strlen.c\
		srcs/ft_str/ft_strmap.c\
		srcs/ft_str/ft_strmapi.c\
		srcs/ft_str/ft_strncat.c\
		srcs/ft_str/ft_strnchr.c\
		srcs/ft_str/ft_strncmp.c\
		srcs/ft_str/ft_strncpy.c\
		srcs/ft_str/ft_strndup.c\
		srcs/ft_str/ft_strnequ.c\
		srcs/ft_str/ft_strnew.c\
		srcs/ft_str/ft_strnjoin.c\
		srcs/ft_str/ft_strnstr.c\
		srcs/ft_str/ft_strrchr.c\
		srcs/ft_str/ft_strsplit.c\
		srcs/ft_str/ft_strstr.c\
		srcs/ft_str/ft_strsub.c\
		srcs/ft_str/ft_strtrim.c\
		\
		srcs/ft_to/ft_tolower.c\
		srcs/ft_to/ft_toupper.c\
		\
		srcs/ft_to_ascii/ft_dotoa.c\
		srcs/ft_to_ascii/ft_itoa.c\
		srcs/ft_to_ascii/ft_lltoa.c\
		srcs/ft_to_ascii/ft_lltoa_base.c\
		srcs/ft_to_ascii/ft_ulltoa.c\
		srcs/ft_to_ascii/ft_ulltoa_base.c\
		\
		srcs/ft_to_int/ft_atoi.c\
		srcs/ft_to_int/ft_atoll.c\
		srcs/ft_to_int/ft_atoull.c\
		\
		srcs/ft_unicode/ft_putval_tab.c\
		srcs/ft_unicode/ft_putwchar.c\
		srcs/ft_unicode/ft_set_octet.c\
		srcs/ft_unicode/ft_set_unichar.c\
		srcs/ft_unicode/ft_wchar_len.c\
		srcs/ft_unicode/ft_wset_plage_byte.c\
		\
		srcs/GNL/get_next_line.c
	
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
