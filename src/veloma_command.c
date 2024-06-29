#include "../includes/command.h"

void	veloma_command(void *args)
{
	*((int *)args) = 1; // args is quit
}
