# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/03 18:56:12 by ladloff           #+#    #+#              #
#    Updated: 2023/05/20 13:30:25 by ladloff          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	?=	libft.a

SRC_DIR	?=	./src
OBJ_DIR	?=	./obj
INC_DIR	?=	./include

SRCS	:=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
			ft_isascii.c ft_isdigit.c ft_isprint.c ft_isspace.c ft_itoa.c \
			ft_latoi.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
			ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c \
			ft_lstsize.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
			ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_putstr_fd.c ft_realloc.c ft_split.c ft_strchr.c ft_strcmp.c \
			ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
			ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strndup.c ft_strnstr.c \
			ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
			ft_uitoa.c ft_printf/ft_printf.c ft_printf/ft_printf_utils.c \
			get_next_line/get_next_line.c
INCS	:=	$(addprefix -I, $(INC_DIR))
OBJS	:=	$(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS))

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
