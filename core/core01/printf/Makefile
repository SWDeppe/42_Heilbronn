CC = cc
CFLAGS += -Wall -Werror -Wextra -g #TODO -> remove -g

LIBFT = libft.a
NAME = libftprintf.a

LIBFT_ROOT = ./libft/


#******************************    MENDATORY   ********************************#
RAW_NAMES = printf			\
			parser			\
			renderer		\
			render_nums		\
			render_strings	\

RAW_HEADER_NAMES = printf

SOURCE_ROOT = ./srcs/
SOURCE_FILES = $(addprefix $(SOURCE_ROOT), $(RAW_NAMES:%=ft_%.c)) 

OBJECT_ROOT = ./objs/
OBJECT_FILES = $(addprefix $(OBJECT_ROOT), $(RAW_NAMES:%=ft_%.o))

HEADER_ROOT_AND_FLAG = -I./headers/
# HEADER_FILES = $(addprefix $(HEADER_ROOT_AND_FLAG), $(RAW_HEADER_NAMES:%=ft_%.h))


#******************************     BONUS      ********************************#
# RAW_BONUS_NAMES = 

# RAW_BONUS_HEADER_NAMES = 

# BONUS_SOURCE_ROOT = ./bonus/srcs/
# BONUS_SOURCE_FILES = $(addprefix $(BONUS_SOURCE_ROOT), $(RAW_BONUS_NAMES:%=ft_%_bonus.c))

# BONUS_OBJECT_ROOT = ./bonus/objs/
# BONUS_OBJECT_FILES = $(addprefix $(BONUS_OBJECT_ROOT), $(RAW_BONUS_NAMES:%=ft_%_bonus.o))

# BONUS_HEADER_ROOT_AND_FLAG = -I./bonus/headers/
# BONUS_HEADER_FILES = $(addprefix $(SOURCE_ROOT), $(RAW_BONUS_HEADER_NAMES:%=ft_%.h))


all: $(NAME)

re:	fclean | $(NAME)

$(NAME): $(OBJECT_FILES)
	$(MAKE) -C $(LIBFT_ROOT) re
	cp $(LIBFT_ROOT)libft.a $@
	ar rs $@ $^

$(OBJECT_ROOT)%.o: $(SOURCE_ROOT)%.c
	$(CC) -c $<  $(CFLAGS) -o $@ $(HEADER_ROOT_AND_FLAG) -I$(LIBFT_ROOT)

$(BONUS_OBJECT_ROOT)%_bonus.o:$(BONUS_SOURCE_ROOT)%_bonus.c
	$(CC) -c $<  $(CFLAGS) -o $@ $(BONUS_HEADER_ROOT_AND_FLAG) -I$(LIBFT_ROOT) 

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_ROOT) fclean

clean: 
	rm -f $(OBJECT_FILES) $(BONUS_OBJECT_FILES)
	$(MAKE) -C $(LIBFT_ROOT) clean

bonus: $(NAME)