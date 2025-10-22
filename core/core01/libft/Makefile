CC = cc
CFLAGS += -Wall -Werror -Wextra

NAME = libft.a

LIBC_FUNCTION_NAMES = isalpha \
				bzero \
				isalnum \
				isascii \
				isdigit \
				isprint \
				memcpy \
				memmove \
				memset \
				strlcat \
				strlcpy \
				strlen \
				toupper \
				tolower 


FT_FUNCTION_NAMES = nothing



FUNCTION_NAMES = $(LIBC_FUNCTION_NAMES) #$(FT_FUNCTION_NAMES)
				
export LIBC_FUNCTION_NAMES

SOURCE_ROOT = ./
SOURCE_FILES = $(addprefix $(SOURCE_ROOT), $(FUNCTION_NAMES:%=ft_%.c)) 

OBJECT_ROOT = ./
OBJECT_FILES = $(addprefix $(SOURCE_ROOT), $(FUNCTION_NAMES:%=ft_%.o))

TEST_ROOT = ./test/
TEST_OBJECT_FILES = $(addprefix $(TEST_ROOT), $(FUNCTION_NAMES:%=ft_%.o))

all: $(NAME)

re:	fclean | $(NAME)



$(NAME): $(OBJECT_FILES)
	ar crs $@ $^

$(OBJECT_ROOT)%.o: $(SOURCE_ROOT)%.c
	$(CC) -c $^  $(CFLAGS) -o $@

fclean: clean
	rm -f $(NAME)

clean: 
	rm -f $(OBJECT_FILES)

header:	
	rm -f libft.h
	echo | head -n11 ft_isalpha.c | sed 's/ft_isalpha.c/libft.h/' >> libft.h
	$(MAKE) -f make_h.mk create_header

try_it:
	./try "$(FUNCTION_NAMES)"

ctest: 


test: $(TEST_OBJECT_FILES) | all
	$(CC) $(TEST_ROOT)  $(CFLAGS) -g -o $(TEST_ROOT)test.out -L. -lft
	gdb $(TEST_ROOT)test.out

$(TEST_ROOT)%.o: $(SOURCE_ROOT)%.c
	$(CC) -c $^  $(CFLAGS) -g -o $@
