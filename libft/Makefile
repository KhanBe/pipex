# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaewoo <jaewoo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 21:04:12 by jaewoo            #+#    #+#              #
#    Updated: 2021/12/22 17:38:13 by jaewoo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

AR = ar
ARFLAGS = crv
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c \
       ft_isascii.c ft_isprint.c ft_strlen.c \
       ft_memset.c ft_bzero.c ft_memcpy.c \
       ft_memmove.c ft_strlcpy.c ft_strlcat.c \
       ft_toupper.c ft_tolower.c ft_strchr.c \
       ft_strrchr.c ft_strncmp.c ft_memchr.c \
       ft_memcmp.c ft_strnstr.c ft_atoi.c \
       ft_calloc.c ft_strdup.c \
       ft_substr.c ft_strjoin.c ft_strtrim.c \
       ft_split.c ft_itoa.c ft_strmapi.c \
       ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
       ft_putendl_fd.c ft_putnbr_fd.c

SRCS_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
	     ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
	     ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all : $(NAME)

clean :
	rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean
	rm -f $(NAME)

re : fclean all

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

bonus : $(OBJS) $(OBJS_BONUS)
	$(AR) $(ARFLAGS) $(NAME) $^

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

.PHONY : all clean fclean re
