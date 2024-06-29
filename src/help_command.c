#include "../includes/command.h"
#include "../includes/repl.h"

void	help_command(t_help_args args)
{
	printf("Help:\n\n");
	for (unsigned int i = 0; i < args.size; i++)
		printf("\t%s- %s:%s\t%s\n", WHITE, args.commands[i].command, NO_COLOR, args.commands[i].description);
	printf("\n\n");
}
