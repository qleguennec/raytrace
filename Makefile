NAME = rt
SRC = $(filter %.c, $(shell ls))
OBJ = $(SRC:.c=.o)
LIB =

SCN=scn_draw.o

INCS += -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/System/Library/Frameworks/Tk.framework/Versions/8.4/Headers/X11/ \
	-I/System/Library/Frameworks/Carbon.framework/Versions/A/Frameworks/HIToolbox.framework/Versions/A/Headers
CFLAGS += -g -Wall -Wextra -Werror $(INCS)
LDLIBS += -framework OpenGL -framework AppKit -framework Cocoa -lmlx
LOADLIBES +=
LDFLAGS += -g

all: $(LIB) $(NAME)

$(NAME): $(OBJ)

%.a:
	make -C $(shell echo $*.a | sed 's/\// /')

clean:
	@rm $(OBJ) 2> /dev/null || true

fclean: clean
	@rm $(NAME) 2> /dev/null || true

re: fclean all

scene:
	@rm $(SCN) 2> /dev/null || true
	@make

.PHONY: scene
.PHONY: all clean fclean re
