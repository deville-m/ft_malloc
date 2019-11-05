NAME = libft_malloc.so
CC = gcc
CFLAGS = -Wall -Wextra -fPIC
INCLUDES = -Iincludes/ -Ilibft/includes
LDLIB = -Llibft/
LDFLAGS = -lft
SRCDIR= srcs/
LIB = libft.a
LIBDIR = libft

SRC =	malloc.c \
		realloc.c \
		calloc.c \
		free.c \
		show_alloc_mem.c \
		chunk.c

TEST =	correc/test0.c \
		correc/test1.c \
		correc/test2.c \
		correc/test3.c \
		correc/test3_bis.c \
		correc/test4.c \
		test_tiny.c \
		test_medium.c


SRC := $(addprefix $(SRCDIR), $(SRC))
OBJ := $(SRC:.c=.o)

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

TMP_NAME = libft_malloc_$(HOSTTYPE).so

all: $(NAME)

$(LIBDIR)/$(LIB):
	@$(MAKE) -j8 -C $(LIBDIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(TMP_NAME): $(OBJ) $(LIBDIR)/$(LIB)
	$(CC) $(CFLAGS) -shared -I$(INCLUDES) -o $@ $(OBJ) $(LDLIB) $(LDFLAGS)

$(NAME): $(TMP_NAME)
	ln -fs $< $@

clean:
	rm -f $(OBJ) && $(MAKE) -C $(LIBDIR) clean

fclean: clean
	rm -f $(NAME) $(TMP_NAME) && $(MAKE) -C $(LIBDIR) fclean

re: fclean $(NAME)

.PHONY: all clean fclean re
