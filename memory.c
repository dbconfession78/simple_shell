#include "shell.h"

/**
 * _malloc - memorry allocator that will bail on failure.
 * 
 *
 *
 */

void *_malloc(unsigned int n, info_t *info)
{
	void *ptr;

	ptr = malloc(n);
	if (!ptr)
	{
		perror("Failed to allocate memory");
		if (!info)
			_exit(98);
	}
	//TODO exit_builtin("98", NULL, info);
	return (ptr);
}
