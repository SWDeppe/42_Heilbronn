#include "libtest.h"


int LLVMFuzzerTestOneInput(uint8_t *data, size_t size) {
	if (size > 0)
		assert(isalpha(*data) == ft_isalpha(*data));
	return 0;
}