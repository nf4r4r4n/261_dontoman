#ifndef REPL_H
# define REPL_H

# include "command.h"
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include <string.h>

# ifndef GREEN
#  define GREEN "\33[1;32m"
# endif
# ifndef RED
#  define RED "\33[1;31m"
# endif
# ifndef WHITE
#  define WHITE "\33[1;97m"
# endif
# ifndef NO_COLOR
#  define NO_COLOR "\33[0m"
# endif

typedef struct s_repl
{
	char			command[1024];
	unsigned int	quit;
}	t_repl;

void	repl_loop(void);
void	repl_eval(const char *command, t_command *commands, unsigned int size);
void	interrupt_handler(int sig);

#endif
