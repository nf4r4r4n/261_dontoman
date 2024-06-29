#include "../includes/repl.h"
#include "../includes/command.h"

void	repl_loop(void)
{
	t_repl	repl = (t_repl){.command = "", .quit = 0};
	t_command	commands[COMMANDS_SIZE] = {
		(t_command){.command = "exit", .action = exit_command, .args = NULL, .description = "Maybe exit or quit the program"},
		(t_command){.command = "quit", .action = exit_command, .args = NULL, .description = "Maybe exit or quit the program"},
		(t_command){.command = "veloma", .action = veloma_command, .args = &repl.quit, .description = "What is that?"},
		(t_command){.command = "clear", .action = clear_command, .args = NULL, .description = "Clear the screen" }
	};

	while (!repl.quit)
	{
		printf(GREEN "#261_dontoman> " NO_COLOR);
		scanf("%s", repl.command);
		if (strcmp(repl.command, "help") == 0)
			help_command((t_help_args){.commands = commands, .size = COMMANDS_SIZE});
		else if (!command_exists(repl.command, commands, COMMANDS_SIZE))
			printf("%sCommand not found: %s%s\n", RED, NO_COLOR, repl.command);
		repl_eval(repl.command, commands, COMMANDS_SIZE);
	}
}

void	repl_eval(const char *command, t_command *commands, unsigned int size)
{
	for (unsigned int i = 0; i < size; i++)
	{
		if (strcmp(command, commands[i].command) == 0 && commands[i].action)
		{
			commands[i].action(commands[i].args);
			break ;
		}
	}
}

void	interrupt_handler(int sig)
{
	(void)sig;
	printf("\n[Dontman has been interrupted] See you soon\n");
	exit(EXIT_SUCCESS);
}
