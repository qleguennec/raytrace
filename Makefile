NAME = rt
SRC = $(filter %.c, $(shell ls))
OBJ = $(SRC:.c=.o)
LIB = libft/libft.a

CFLAGS += -g -Wall -Wextra -Werror
LDLIBS += -lX11 -lft
LOADLIBES += -Llibft
LDFLAGS += -g

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	$(CC) $(LDFLAGS) -o $(NAME) $(OBJ) $(LOADLIBES) $(LDLIBS)

%.a:
	make -C $(shell echo $*.a | sed 's/\// /')

clean:
	@rm $(OBJ) 2> /dev/null || true

fclean: clean
	@rm $(NAME) 2> /dev/null || true

re: fclean all
