# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaewoo <jaewoo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/25 16:50:46 by jaewoo            #+#    #+#              #
#    Updated: 2022/06/20 13:26:48 by jaewoo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PIPE = pipex
PIPE_B = pipex_bonus

SRCS = srcs/pipex.c srcs/utils.c
OBJS = ${SRCS:.c=.o}

SRCS_B = srcs/pipex_bonus.c srcs/utils_bonus.c
OBJS_B = ${SRCS_B:.c=.o}

HEADER = -I includes

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

.c.o : %.o : %.c
	@gcc ${CFLAGS} ${HEADER} -c $< -o $(<:.c=.o)

all : ${PIPE}

bonus : ${PIPE_B}

${PIPE} : ${OBJS}
	@make re -C ./libft
	@$(CC) ${OBJS} -L libft -lft -o ${PIPE}

${PIPE_B} : ${OBJS_B}
	@make re -C ./libft
	@$(CC) ${OBJS_B} -L libft -lft -o ${PIPE_B}

clean :
	@make clean -C ./libft
	@rm -f ${OBJS} ${OBJS_B}

fclean : clean
	@make fclean -C ./libft
	@rm -f $(NAME)
	@rm -f ${PIPE}

re : fclean all

re_bonus : fclean bonus

.PHONY : all clean fclean re bonus re_bonus
