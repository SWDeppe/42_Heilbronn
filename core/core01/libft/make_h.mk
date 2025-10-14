create_header: $(LIBC_FUNCTION_NAMES)
	if ! grep -q "#endif" libft.h ; then \
		echo "\n\
	#endif" >> libft.h;\
	fi	

$(LIBC_FUNCTION_NAMES):
	if ! grep -q "# define" libft.h ; then \
		echo "\n\
	#ifndef LIBFT_H\n\
	# define LIBFT_H\n\
	#include <stddef.h>\n\
	#include <stdlib.h>\n"  >> libft.h;\
	fi; \
	if ! grep -q "$@" libft.h ; then \
		man $@.3 | grep '$@(.*)' | head -n1 | sed -e "s/$@/	ft_$@/" -e "s/\s*//" -e "s/\s*//" -e "s/ft_strlcat/size_t	ft_strlcat/" -e "s/ft_strlcpy/size_t	ft_strlcpy/" >> libft.h;  \
	fi;
	if ! find ft_$@.c; then \
		echo | head -n11 ft_isalpha.c | sed 's/ft_isalpha.c/ft_$@.c/' >> ft_$@.c; \
		echo '\n' >> ft_$@.c; \
		man $@.3 | grep '$@(.*)' | head -n1 | sed -e "s/$@/ft_$@/" -e "s/\s*//" -e "s/\s*//" >> ft_$@.c;  \
		code ft_$@.c; \
	fi
	