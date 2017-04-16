#include "shell.h"

/**
 *
 *
 *
 */

void free_shell_info(info_t *info)
{
	free_path_list(info->path_head);
	if (info->line != NULL)
		free(info->line);
	if (info->args != NULL)
		free(info->args);

}
