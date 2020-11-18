#include "Signal.h"


void Signal::sigintHandler()
{
	signal(SIGINT, SIG_DFL); 
}

void Signal::sigstpHandler()
{
	signal(SIGTSTP, SIG_IGN);
}
