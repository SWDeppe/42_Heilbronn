#include <bsd/string.h>
#include <strings.h>
#include <stdio.h>
#include "libft.h"

int main()
{
	char dst1[10];
	char dst2[10];
	char *src  = "hello world";
	printf("return normal :%zu\n", strlcpy(dst1, src, 10));
	printf("return of mine :%zu\n", strlcpy(dst2, src, 10));

	printf("dest normal :%s\n", dst1);
	printf("dest of mine :%s\n", dst2);

	return (0);
}