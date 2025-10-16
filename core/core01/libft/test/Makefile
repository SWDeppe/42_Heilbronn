CC=clang
CFLAGS += -Wall -Werror -Wextra -g 
NAME = tests/libtest.a

LIBC_FUNCTION_NAMES = isalpha \
					  isalnum 

			


FT_FUNCTION_NAMES = nothing



FUNCTION_NAMES = $(LIBC_FUNCTION_NAMES) #$(FT_FUNCTION_NAMES)


SOURCE_ROOT = ../
SOURCE_FILES = $(addprefix $(SOURCE_ROOT), $(FUNCTION_NAMES:%=ft_%.c)) 

OBJECT_ROOT = objs/
OBJECT_FILES = $(addprefix $(OBJECT_ROOT), $(FUNCTION_NAMES:%=ft_%.o))

TESTS_ROOT = tests/
TEST_FILES = $(addprefix $(TESTS_ROOT), $(FUNCTION_NAMES:%=ft_%_test.c))

TESTS_BIN_ROOT = tests_bin/
TEST_BIN_FILES = $(addprefix $(TESTS_BIN_ROOT), $(FUNCTION_NAMES:%=ft_%_test.out))

.PHONY: all re fclean clean test

all: $(NAME)

re:	 fclean | test


$(NAME): $(OBJECT_FILES)
	ar crs $@ $^

$(OBJECT_ROOT)%.o: $(SOURCE_ROOT)%.c
	cc -c $^  $(CFLAGS) -o $@

fclean: clean
	rm -f $(NAME) $(TEST_BIN_FILES)

clean: 
	rm -f $(OBJECT_FILES)

test: $(TEST_BIN_FILES) 

tests_bin/%.out: $(TEST_FILES)| all
	$(CC) -g -fsanitize=address,fuzzer  $< -o $@  -Ltests/ -ltest


$(TESTS_ROOT)%_test.c: 
	touch .$^/$@