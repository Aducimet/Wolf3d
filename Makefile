# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: aducimet <aducimet@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/13 16:45:37 by aducimet     #+#   ##    ##    #+#        #
#    Updated: 2019/04/09 15:49:10 by aducimet    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = wolf3d

SRCS =	srcs/main.c \
		srcs/utils.c \
		srcs/define_wolf3d.c \
		srcs/hook.c \
		srcs/parsing.c \
		srcs/ft_color.c \
		srcs/apply_texture.c \
		srcs/draw.c \
		srcs/draw_wall.c \
		srcs/hud.c \
		srcs/hook_2.c \

OBJ = $(SRCS:.c=.o)

FLAG = -g -Wall -Wextra -Werror -O3

CC = gcc $(FLAG)

RM = /bin/rm -f

OPENGL = -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):$(OBJ) 
	@make -C libft/
	@make -C minilibx_macos/
	@$(CC) -o $(NAME)  $(SRCS) minilibx_macos/libmlx.a libft/libft.a $(OPENGL)
	@echo "Make executable $(NAME):\033[0;32m DONE !\033[0m"

%.o: %.c
	@$(CC) -o $@ -c $< -I./

clean:
	@make clean -C libft/
	@make clean -C minilibx_macos/
	@$(RM) $(OBJ) 

fclean: clean
	@make fclean -C libft/
	@make fclean -C minilibx_macos/
	@$(RM) $(NAME)
	@echo "Executable $(NAME) clean :\033[0;32m DONE !\033[0m"

re:	fclean all
	@make re -C minilibx_macos/

.PHONY: all clean fclean re
