CC = cc
CFLAGS += -Wall -Werror -Wextra
LIB_FLAGS = -lft -Llibft/ -Ilibft/libft.h

NAME = libftprintf.a


RAW_NAMES = printf

RAW_HEADER_NAMES = printf

RAW_BONUS_NAMES = 

RAW_BONUS_HEADER_NAMES = 

HEADER_ROOT = ./headers
HEADER_FILES = $(addprefix $(SOURCE_ROOT), $(HEADER_NAMES:%=ft_%.h)) 

BONUS_HEADER_ROOT = ./bonus/headers
BONUS_HEADER_FILES = $(addprefix $(SOURCE_ROOT), $(HEADER_NAMES:%=ft_%.h)) 

SOURCE_ROOT = ./srcs
SOURCE_FILES = $(addprefix $(SOURCE_ROOT), $(FUNCTION_NAMES:%=ft_%.c)) 


OBJECT_ROOT = ./objs
OBJECT_FILES = $(addprefix $(OBJECT_ROOT), $(FUNCTION_NAMES:%=ft_%.o))


BONUS_SOURCE_ROOT = ./bonus/srcs
BONUS_SOURCE_FILES = $(addprefix $(BONUS_SOURCE_ROOT), $(BONUS_FUNCTION_NAMES:%=ft_%_bonus.c))


BONUS_OBJECT_ROOT = ./bonus/objs
BONUS_OBJECT_FILES = $(addprefix $(BONUS_SOURCE_ROOT), $(BONUS_FUNCTION_NAMES:%=ft_%_bonus.o))



all: $(NAME)

re:	fclean | $(NAME)

$(NAME): lib | $(OBJECT_FILES)
	ar crs $@ $^
	$(MAKE) -C libft/ fclean

$(OBJECT_ROOT)%.o: $(SOURCE_ROOT)%.c
	$(CC) -c $^  $(CFLAGS) -o $@ -I$(HEADER_FILES) $(LIB_FLAGS)

$(BONUS_OBJECT_ROOT)%_bonus.o: $(BONUS_SOURCE_ROOT)%_bonus.c
	$(CC) -c $^  $(CFLAGS) -o $@ -I$(BONUS_HEADER_FILES) $(LIB_FLAGS)

fclean: clean
	rm -f $(NAME)

clean: 
	rm -f $(OBJECT_FILES) $(BONUS_OBJECT_FILES)

bonus: $(BONUS_OBJECT_FILES) $(OBJECT_FILES)
	ar crs $(NAME) $^

lib:
	$(MAKE) -C libft/ all
	$(MAKE) -C libft/ clean

# TODO fclean after compiling