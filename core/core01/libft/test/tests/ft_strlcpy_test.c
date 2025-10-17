#include "libtest.h"


int LLVMFuzzerTestOneInput(uint8_t *data, size_t size) {
	// for this test we need a src string a dest string and a size so this is how i will use the random data:
	// get the first two bytes for size will make an 16 bits integer ans the rest do two str of size (size - 2) / 2 the
	size_t src_size = 0;
	if (size <= 2)
		return (0);
	size_t cpy_size = (size_t)data[0] << 8;
	cpy_size += data[1];
	if (size <= 3)
	{
		if (data[0] << 7)
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
	//dst[i] = '\0';
	// not null teminated cause the function strlcat should do it
	i = 0;
	while (i < src_size)
	{
		src[i] = data[i + 2 + dst_size]; // i + 2 !!
		i++;
	}
	src[i] = '\0';
	i = 0;
	src_size = strlen(src); // in case a char is \0
	if(dst_size < src_size)
	{	
		assert(ft_strlcpy(dst, src, dst_size) == strlen(src));
		while (i < src_size
			&& i < dst_size)
		{
			assert(src[i] == dst[i]); // i + 2 !!
			i++;
		}
	}
	free(dst);
	free(src);
	return (0);
}