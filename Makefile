# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/03 18:56:12 by ladloff           #+#    #+#              #
#    Updated: 2023/04/25 11:48:40 by ladloff          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	?=	libft.a

SRC_DIR	?=	./src
OBJ_DIR	?=	./obj
INC_DIR	?=	./include

SRCS	:=	$(wildcard $(SRC_DIR)/**/*.c)
INCS	:=	$(addprefix -I, $(INC_DIR))
OBJS	:=	$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

CFLAGS	:=	-Wall -Wextra -Werror $(INCS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(OBJ_DIR)
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
