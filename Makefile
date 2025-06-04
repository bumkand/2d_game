NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
LIBMLX = ./MLX42
HEADER_DIR = ./headers
PRINTF_PATH = ./ft_printf/
PRINTF_LIB = $(PRINTF_PATH)libftprintf.a

HEADERS = -I $(LIBMLX)/include -I $(HEADER_DIR) -I ./get_next_line
LIBS = 	$(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm $(PRINTF_LIB)
SRCS = $(shell find ./src -iname "*.c") $(shell find ./get_next_line -iname "*.c")
OBJS = $(SRCS:.c=.o)

all: $(PRINTF_LIB) libmlx $(NAME)

$(PRINTF_LIB):
	@make -C $(PRINTF_PATH) all

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME): $(OBJS)
	$(CC) $(HEADERS) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

clean:
	rm -rf $(OBJS)
	rm -rf $(LIBMLX)/build
	@make -C $(PRINTF_PATH) clean

fclean: clean
	rm -rf $(NAME)
	@make -C $(PRINTF_PATH) fclean

re: fclean all

.PHONY: all libmlx clean fclean re