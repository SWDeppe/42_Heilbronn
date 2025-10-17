#include "libtest.h"


int LLVMFuzzerTestOneInput(uint8_t *data, size_t size) {
	assert(toupper(*data) == ft_toupper(*data));
	return 0;
}