NAME = miniRT

INCLUDES = includes

LINUX_FLAGS = -lm -lX11 -lXext -lpthread

MAC_FLAGS = -framework OpenGL -framework AppKit

SRCS =  $(addprefix srcs/, main.c utils_init.c render.c camera.c intersection.c matrix.c pbr.c) \
		$(addprefix srcs/parsing/, parse_utils.c parse.c) \
		$(addprefix srcs/utils/, utils.c utils_vec3.c utils_color.c utils_camera.c) \
		$(addprefix srcs/events/, events.c mouse_events.c) \
		$(addprefix includes/get_next_line/, get_next_line.c get_next_line_utils.c)

LIBS = $(addprefix includes/, libft/libft.a)
OBJS	= ${SRCS:.c=.o}
CFLAGS	=  -Wall -Wextra -Werror
CC		= gcc
RM		= rm -f

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	make -C includes/libft
	make -C includes/minilibx-linux
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) includes/minilibx-linux/libmlx.a -fsanitize=address $(LINUX_FLAGS) -o $(NAME)


all:		$(NAME)

clean:
			$(RM) $(OBJS)
			make clean -C includes/minilibx-linux

fclean:		clean
			$(RM) $(NAME)
			make fclean -C includes/libft

re:			fclean all

.PHONY: all clean fclean re