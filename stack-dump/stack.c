#include <stdio.h>
#include <ffi/ffi.h>

int print_log(const char *s, unsigned int count)
{
	int i;
	for (i = 0; i < count; i++)
		puts(s);
}

int main(int argc, char **argv)
{
	ffi_cif cif;
	ffi_type *args[2];
	void *values[2];
	char *s = "Hello World!";
	int count = 32;
	int rc;

	args[0] = &ffi_type_pointer;
	args[1] = &ffi_type_uint;
	values[0] = &s;
	values[1] = &count;

	rc = ffi_prep_cif(&cif, FFI_DEFAULT_ABI, 2, &ffi_type_uint, args);
	if (rc != FFI_OK)
		return -1;

	ffi_call(&cif, print_log, &rc, values);

	return 0;
}
