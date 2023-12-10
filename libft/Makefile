# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccrecent <ccrecent@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/19 13:02:38 by ccrecent          #+#    #+#              #
#    Updated: 2023/08/19 13:02:40 by ccrecent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES =	ft_isalnum.c	\
		ft_isalpha.c	\
		ft_isascii.c	\
		ft_isdigit.c	\
		ft_isprint.c	\
		ft_strlen.c	\
		ft_strlcat.c	\
		ft_strlcpy.c	\
 		ft_bzero.c	\
		ft_memcpy.c	\
		ft_memmove.c	\
		ft_memset.c	\
		ft_tolower.c	\
		ft_toupper.c	\
		ft_strchr.c	\
		ft_strrchr.c	\
		ft_strncmp.c	\
		ft_memchr.c	\
		ft_memcmp.c	\
		ft_strnstr.c	\
		ft_atoi.c	\
		ft_calloc.c	\
		ft_strdup.c	\
		ft_substr.c	\
		ft_strjoin.c	\
		ft_strtrim.c	\
		ft_split.c	\
		ft_itoa.c	\
		ft_strmapi.c	\
		ft_striteri.c	\
		ft_putchar_fd.c	\
		ft_putstr_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c	\
		ft_printf.c	\
		ft_put_s.c	\
		ft_putptr.c	\
		ft_get_next_line.c	\
		ft_get_next_line_utils.c	\

BONUS_SOURCES =	ft_lstnew.c	\
				ft_lstadd_front.c	\
				ft_lstsize.c	\
				ft_lstlast.c	\
				ft_lstadd_back.c	\
				ft_lstdelone.c	\
				ft_lstclear.c	\
				ft_lstiter.c	\
				ft_lstmap.c	\
		
OBJECTS = $(SOURCES:.c=.o)
BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJECTS)	$(BONUS_OBJECTS)
	ar -crs $@ $^

bonus: $(OBJECTS)	$(BONUS_OBJECTS)
	$(AR) -r $(NAME) $?

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re