# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: welida <welida@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/09 10:24:46 by welida            #+#    #+#              #
#    Updated: 2021/02/09 13:36:36 by welida           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR_HEADERS	= ./includes/

DIR_SRCS	= ./srcs/

SRC		=	utils/exit_error.c utils/split.c utils/get_next_line.c utils/libft.c \
			utils/ft_free.c \
			geometry/vector.c geometry/vector2.c geometry/get_normal.c \
			scene/camera.c scene/bmp.c scene/paint.c \
			scene/color.c scene/color2.c \
			figures/figures.c \
			ray_tracing/trace_ray.c \
			parser/parser.c parser/parse_figures.c parser/parse_objects.c \
			parser/parser_utils.c parser/parser_utils2.c \
			intersections/get_intersect.c intersections/triangle_intersect.c \
			intersections/sphere_intersect.c  intersections/square_intersect.c \
			intersections/cylinder_intesect.c \
			main.c

SRCS	= $(addprefix $(DIR_SRCS), $(SRC))

OBJS	= $(SRCS:.c=.o)

NAME	= miniRT

LIBMLX	= libmlx.dylib

GCC		= gcc
RM		= rm -f
CFLAGS = -Wall -Werror -Wextra

%.o: %.c
			$(GCC) $(CFLAGS) -I $(DIR_HEADERS) -c $< -o $@

$(NAME):	$(OBJS)
				make -C ./minilibx_mms_20200219
				cp ./minilibx_mms_20200219/libmlx.dylib .
				$(GCC) $(CFLAGS) -I $(DIR_HEADERS) $(LIBMLX) $(OBJS) -o $(NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
				make clean -C ./minilibx_mms_20200219
				$(RM) $(LIBMLX)
				$(RM) $(NAME)

re:				fclean all

.PHONY:		all clean fclean re