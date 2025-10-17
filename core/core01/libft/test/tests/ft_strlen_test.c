#include "libtest.h"


int LLVMFuzzerTestOneInput(uint8_t *data, size_t size) {
	char *str;
	str = (char *)malloc(size + 1);
	int i = 0;
	while (i < size)
	{
		str[i] = data[i];
		i++;
	}
	str[i] = '\0';
	assert(strlen(str) == ft_strlen(str));
	free(str);
	return 0;
}