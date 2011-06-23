#include <stdio.h>
#include <ffi/ffi.h>
#include "times.h"

int main(int argc, char **argv)
{
	ffi_cif cif;
	ffi_type *args[1];
	void *values[1];
	char *s;
	int rc;
	int i;
	int c;

	c = times(argc, argv);
	if (c < 0)
		return c;

	args[0] = &ffi_type_pointer;
	values[0] = &s;

	rc = ffi_prep_cif(&cif, FFI_DEFAULT_ABI, 1, &ffi_type_uint, args);
	if (rc != FFI_OK)
		return -1;

	for (i = 0; i < c; i++) {
		s = "Hello World!";
		ffi_call(&cif, puts, &rc, values);
	}

	return 0;
}

