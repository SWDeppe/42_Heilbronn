NAME = ft_display_file

CFLAGS += -Wall -Werror -Wextra

CC=cc
CFILES = main.c

OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OFILES)
	$(CC) $(OFILES) -o $@

clean:
	rm -f $(OFILES)
	
re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@  

fclean: clean
	rm -f $(NAME)

