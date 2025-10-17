#include "libtest.h"

int main()
{
	
	 char out = ft_toupper('a');
	// write(1, &out, 1);
	char data[] = {99,111,110,118,101,114,116,85,84,70,56,50,67,104,97,114,58,32,101,114,114,111,114,49,32,78,65,78,33};
	size_t size = sizeof(data);
		size_t src_size = 0;
	if (size <= 2)
		return (0);
	size_t cpy_size = (size_t)data[0] << 8;
	cpy_size += data[1];
	if (size <= 4)
	{
		if (data[0])
			src_size = 1;
	}
	else
		src_size = (cpy_size % ((size - 2) / 2)) + 1; // make a random size where the src size is higher than the half

	// make a random 16 bits interger

	size_t dst_size = (size - 2) - src_size; // give the rest of the size to dest
	if (cpy_size > dst_size)	
		cpy_size = dst_size;
	char *dst;
	char *src;
	dst = (char *)malloc(dst_size + 1);
	src = (char *)malloc(src_size + 1);

	int i = 0;
	while (i < dst_size)
	{
		dst[i] = data[i + 2]; // i + 2 !!
		i++;
	}
	dst[i] = '\0';
	// not null teminated cause the function strlcat should do it
	i = 0;
	while (i < src_size)
	{
		src[i] = data[i + 2 + dst_size]; // i + 2 !!
		i++;
	}
	src[i] = '\0';
	i = 0;
	assert(ft_strlcpy(dst, src, cpy_size) == strlen(src));
	while (i < src_size
		&& i < cpy_size)
	{
		assert(src[i] == dst[i]);
		i++;
	}
	free(dst);
	free(src);
}

