NAME	= fractol

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -O3

SRCS 	= ./srcs/
OBJS 	= ./objs/
LIBFT 	= ./libft/
LIBX	= ./minilibx-linux/

CFILE	= $(SRCS)burningship.c $(SRCS)draw.c $(SRCS)input.c $(SRCS)julia.c \
		$(SRCS)main.c $(SRCS)mandelbrot.c $(SRCS)utility.c

OFILE	= $(CFILE:$(SRCS)%.c=$(OBJS)%.o)

all: $(NAME)

$(NAME): $(OFILE)
	@make -C $(LIBFT)
	@make -C $(LIBX)
	@$(CC) $(CFLAGS) -o $(NAME) $(OFILE) -L $(LIBFT) -lft -L $(LIBX) -lmlx -lXext -lX11 -lm -lbsd
	@echo -e "\033[32m----------------[\033[33m$(NAME)\033[32m is compiled]----------------\033[0m"

$(OBJS)%.o: $(SRCS)%.c
	@mkdir -p $(OBJS)
	@$(CC) $(CFLAGS) -c $< -o $@ -lmlx -lXext -lX11 -lm -lbsd -I $(LIBFT) -I $(LIBX)
	@echo -e "\033[32m[`expr $$(expr $$(find $(OBJS) -name "*.o" | wc -l) \* 100) / $$(find $(SRCS) -name "*.c" | wc -l)`%]\033[0m Compilation de \033[33m$<\033[0m"

clean:
	@make clean -C $(LIBFT)
	@make clean -C $(LIBX)
	@rm -rf $(OBJS)
	@echo -e "\033[31m----------------[\033[33m$(OBJS)\033[31m deleted]----------------\033[0m"

fclean: clean
	@make fclean -C $(LIBFT)
	@rm -f $(NAME)
	@echo -e "\033[31m----------------[\033[33m$(NAME)\033[31m deleted]----------------\033[0m"

re: fclean all

.PHONY: all clean fclean re