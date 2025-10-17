#include "libtest.h"


int LLVMFuzzerTestOneInput(uint8_t *data, size_t size) {
	if (size > 0)
		assert(isascii(*data) == ft_isascii(*data));
	return 0;
}