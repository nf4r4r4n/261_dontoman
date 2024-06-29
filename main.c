#include "includes/repl.h"

int	main(void)
{
	signal(SIGINT, interrupt_handler);
	repl_loop();
}
