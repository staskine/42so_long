# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 17:03:00 by sataskin          #+#    #+#              #
#    Updated: 2024/05/02 14:11:02 by sataskin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFTPATH = ./libft

LIBFT = $(LIBFTPATH)/libft.a

LIBMLX    := ./MLX42

HEADERS    := -I $(LIBMLX)/include

SRCS =  check_file.c \
			check_lines.c \
			create_map.c \
			error_handling.c \
			exit_mlx.c \
			floodfill.c \
			get_next_line_utils.c \
			get_next_line.c \
			img_to_window.c \
			initialize_image.c  \
			main.c \
			map_parsing.c \
			so_long.c \
			validate_utils.c \
			so_long_utils.c \
			movement.c \
			delete_me.c

OBJS= $(SRCS:.c=.o)

LIBS := $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm -L "/Users/$(USER)/.brew/opt/glfw/lib/"

all: libmlx $(NAME)

libmlx:
	@if [ ! -d $(LIBMLX)/build ]; then\
		cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4;\
	fi

$(OBJS): $(SRCS)
	cc -Wall -Wextra -Werror -c -g $(@:.o=.c) -o $@

$(LIBFT):
	make -C $(LIBFTPATH)

$(NAME): $(LIBFT) $(OBJS)
	cc -Wall -Wextra -Werror $(SRCS) $(LIBS) $(HEADERS) $(LIBFT) -o $@

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFTPATH)
	@rm -rf $(LIBMLX)/build

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFTPATH)

re: fclean libmlx $(NAME)

.PHONY: all, clean, fclean, libmlx, re