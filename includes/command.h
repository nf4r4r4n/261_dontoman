#ifndef COMMAND_H
# define COMMAND_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef COMMANDS_SIZE
#  define COMMANDS_SIZE 4
# endif

typedef struct s_command
{
	char		command[1024];
	void		(*action)(void *);
	void		*args;
	const char	*description;
}	t_command;

typedef struct s_help_args
{
	t_command		*commands;
	unsigned int	size;
}	t_help_args;

unsigned int	command_exists(const char *command, t_command *commands, unsigned int size);
void			exit_command(void *args);
void			veloma_command(void *args);
void			help_command(t_help_args args);
void			clear_command(void *args);

#endif
