CC=clang
CFLAGS += -Wall -Werror -Wextra -g 
NAME = tests/libtest.a

LIBC_FUNCTION_NAMES = isalpha 	\
					  isalnum 	\
					  isdigit 	\
					  isascii 	\
					  isprint 	\
					  toupper 	\
					  tolower 	\
					  strlen  	\
					  strlcpy	\
					  strlcat


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

test: all | $(TEST_BIN_FILES)  $(TEST_FILES) 

tests_bin/%_test.out: $(TESTS_ROOT)%_test.c
	$(CC) -g -fsanitize=address,fuzzer  tests/$*_test.c -o $@  -Ltests/ -ltest -lbsd

full:
	./try $(FUNCTION_NAMES)

simple_test:
	cc -g tests/test.c -o $(TESTS_BIN_ROOT)/simple_test.out -Ltests/ -ltest

$(TESTS_ROOT)%_test.c: 
	touch .$^/$@