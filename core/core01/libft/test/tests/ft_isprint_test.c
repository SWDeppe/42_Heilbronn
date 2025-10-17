#include "libtest.h"


int LLVMFuzzerTestOneInput(uint8_t *data, size_t size) {
	assert(isprint(*data) == ft_isprint(*data));
	return 0;
}