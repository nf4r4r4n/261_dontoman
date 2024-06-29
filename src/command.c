#include "../includes/command.h"

unsigned int	command_exists(const char *command, t_command *commands, unsigned int size)
{
	unsigned int	exists;

	exists = 0;
	for (unsigned int i = 0; i < size && !exists; i++)
		if (strcmp(command, commands[i].command) == 0)
			exists = 1;
	return (exists);
}
