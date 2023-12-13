#include "main.h"

/**
 * inter_mode - interactive mode
 */

void inter_mode(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 3);
		fflush(stdout);
	}
}
