#include "libtest.h"


int LLVMFuzzerTestOneInput(uint8_t *data, size_t size) {
	if (size > 0)
		assert(isdigit(*data) == ft_isdigit(*data));
	return 0;
}