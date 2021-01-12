# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/25 15:26:14 by kupsyloc          #+#    #+#              #
#    Updated: 2020/11/02 18:21:24 by kupsyloc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft_full.a
CC = gcc
FLAG =  -Wall -Werror -Wextra

GREEN 	:= \033[32;1m
WHITE	:= \033[39;1m
EOC		:= \033[00m

DIR_PRINTF = ./ft_printf/src/
DIR_LIBFT = ./libft/
DIR_GNL = ./get_next_line/
DIR_O = ./obj/

HEADER_PRINTF = -I ./ft_printf/include
HEADER_LIBFT = -I ./libft
HEADER_GNL = -I ./get_next_line

SOURCES_PRINTF = check_flags.c check_flags_extra.c ft_itoa_external.c \
ft_str_concat.c norm.c parse.c parse_extra.c printf.c pusher_c_s_p.c \
pusher_c_s_p_extra.c pusher_diuox.c pusher_f.c stars_manager.c
SOURCES_GNL = get_next_line.c
SOURCES_LIBFT = ft_abs.c ft_atoi.c ft_bzero.c ft_isalnum.c \
ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
ft_list_size.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c \
ft_lstmap.c ft_lstnew.c ft_max.c ft_memalloc.c ft_memccpy.c \
ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c \
ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c \
ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c \
ft_sqrt.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c \
ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c \
ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c \
ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c \
ft_strnstr.c ft_strrchr.c ft_strrev.c ft_strsplit.c ft_strstr.c \
ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_memswap.c

PATH_PRINTF = $(addprefix $(DIR_PRINTF), $(SOURCES_PRINTF))
PATH_LIBFT = $(addprefix $(DIR_LIBFT), $(SOURCES_LIBFT))
PATH_GNL = $(addprefix $(DIR_GNL), $(SOURCES_GNL))

OBJS = $(addprefix $(DIR_O),$(SOURCES_PRINTF:.c=.o)) $(addprefix $(DIR_O),\
$(SOURCES_LIBFT:.c=.o)) $(addprefix $(DIR_O),$(SOURCES_GNL:.c=.o)) 

all: obj $(NAME)
obj:
	@mkdir -p $(DIR_O)
	@$(CC) $(FLAG) $(HEADER_PRINTF) $(HEADER_LIBFT) $(HEADER_GNL) $(PATH_GNL) $(PATH_LIBFT) $(PATH_PRINTF) -c $<
	@mv *.o $(DIR_O)
	@ar rc $(NAME) $(OBJS)
	@echo "$(GREEN)compiled:$(EOC) $(WHITE)$(NAME)$(EOC)"
clean:
	@rm -rf $(DIR_O)
fclean: clean
	@rm $(NAME)
re: clean all
