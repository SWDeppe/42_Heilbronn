#include "libtest.h"

int LLVMFuzzerTestOneInput(uint8_t *data, size_t size) {
	if (size > 0)
		assert(isalnum(*data) == ft_isalnum(*data));
	return 0;
}