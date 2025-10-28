CC = cc
CFLAGS += -Wall -Werror -Wextra

NAME = libft.a

LIBC_FUNCTION_NAMES = 	isalpha \
						bzero 	\
						isalnum \
						isascii \
						isdigit \
						isprint \
						memcpy 	\
						memmove \
						memset 	\
						strlcat \
						strlcpy \
						strlen 	\
						toupper \
						tolower \
						strchr 	\
						strrchr \
						strncmp \
						memchr	\
						memcmp	\
						strnstr \
						atoi	\
						calloc	\
						strdup	\
						substr 	\

				

FT_FUNCTION_NAMES = 	strjoin		\
						strtrim		\
						split		\
						itoa		\
						strmapi 	\
						striteri	\
						putchar_fd	\
						putstr_fd	\
						putendl_fd	\
						putnbr_fd

FT_BONUS_FUNCTION_NAMES = 	lstnew		\
							lstadd_front \
							lstsize		\
							lstlast		\
							lstadd_back	\
							lstdelone	\
							lstclear	\
							lstmap		\
							lstiter

FUNCTION_NAMES = $(LIBC_FUNCTION_NAMES) $(FT_FUNCTION_NAMES)

SOURCE_ROOT = ./
SOURCE_FILES = $(addprefix $(SOURCE_ROOT), $(FUNCTION_NAMES:%=ft_%.c)) 


OBJECT_ROOT = ./
OBJECT_FILES = $(addprefix $(OBJECT_ROOT), $(FUNCTION_NAMES:%=ft_%.o))


BONUS_SOURCE_ROOT = ./
BONUS_SOURCE_FILES = $(addprefix $(BONUS_SOURCE_ROOT), $(FT_BONUS_FUNCTION_NAMES:%=ft_%_bonus.c))

BONUS_OBJECT_ROOT = ./
BONUS_OBJECT_FILES = $(addprefix $(BONUS_SOURCE_ROOT), $(FT_BONUS_FUNCTION_NAMES:%=ft_%_bonus.o))


all: $(NAME)

re:	fclean | $(NAME)

$(NAME): $(OBJECT_FILES)
	ar crs $@ $^

$(OBJECT_ROOT)%.o: $(SOURCE_ROOT)%.c
	$(CC) -c $^  $(CFLAGS) -o $@

$(BONUS_OBJECT_ROOT)%_bonus.o: $(BONUS_SOURCE_ROOT)%_bonus.c
	$(CC) -c $^  $(CFLAGS) -o $@

fclean: clean
	rm -f $(NAME)

clean: 
	rm -f $(OBJECT_FILES) $(BONUS_OBJECT_FILES)

bonus: $(BONUS_OBJECT_FILES) $(OBJECT_FILES)
	ar crs $(NAME) $^