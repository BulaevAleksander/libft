# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/04 18:34:35 by kjamar            #+#    #+#              #
#    Updated: 2021/01/06 12:57:08 by kjamar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARG_PS	:= lem-in
CFLAGS 	:= -Wall -Werror -Wextra
CC 		:= gcc

# Source and object direct
LIBFT	:= ./libft/libft_full.a
INC		:= ./include/
LFT_DIR := ./libft/
OBJ_DIR	:= ./obj/

# Source files
FILE	:=	array_sort.c \
			array_utils.c \
			dijkstra.c \
			ft_protected_memalloc.c \
			graph_utils.c \
			input_parse.c \
			input_parse_2.c \
			lemin.c \
			list_utils.c \
			main.c \
			parse_rooms.c \
			parse_utils.c \
			paths_utils.c \
			paths_utils2.c \
			paths_utils3.c \
			pq_tree.c \
			pq_tree2.c \
			suurballe.c


SRCS	+= $(notdir $(FILE))
HEADER	:= include/lemin.h

# Object files
OBJF	:= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

vpath %.c src/

RED 	:= \033[31;1m
GREEN 	:= \033[32;1m
DBLUE 	:= \033[34m
WHITE	:= \033[39;1m
EOC		:= \033[00m

all: $(TARG_PS)

$(TARG_PS): obj $(LIBFT) $(OBJF)
	@$(CC) $(OBJF) $(LIBFT) -o $@ $(CFLAGS)
	@printf "\n$(GREEN)compiled: $(WHITE)$(TARG_PS)$(EOC)\n"


obj:
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c $(HEADER) Makefile
	@printf "$(DBLUE) - Compiling $< into $@\r$(EOC)"
	@$(CC) -I $(INC) -I $(LFT_DIR)/includes -c $< -o $@ -Wall -Werror -Wextra

$(LIBFT): FORCE
	@make -C $(LFT_DIR)

clean:
	@rm -rf *.o obj
	@make clean -C $(LFT_DIR)
	@echo "$(RED)deleted: $(WHITE)obj files$(EOC)"

fclean: clean
	@rm -f $(TARG_PS)
	@make fclean -C $(LFT_DIR)
	@echo "$(RED)deleted: $(WHITE)$(TARG_PS)$(EOC)"

re: fclean all

FORCE:

.PHONY: clean fclean re all FORCE
