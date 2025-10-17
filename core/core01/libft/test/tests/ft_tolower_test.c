#include "libtest.h"


int LLVMFuzzerTestOneInput(uint8_t *data, size_t size) {
	assert(tolower(*data) == ft_tolower(*data));
	return 0;
}