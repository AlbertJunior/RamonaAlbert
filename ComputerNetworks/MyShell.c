#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/socket.h>

#include "pipe.h"
#include "mkfifo.h"
#include "socket.h"


void pipe_uri();
void mkfifo1();
void sockets();

int main(int argc, char* argv[])
{
	char MesajPrimire[]="Buna! Pentru a continua te rugam sa faci login\n";
	write (1, MesajPrimire, strlen(MesajPrimire));
    write (1, MSG1, strlen(MSG1));
    char tip;
    read(0, &tip, 2);
    write(1, MSG2, strlen(MSG2));
    if (tip=='1')
        pipe_uri();
    else if (tip=='2')
        mkfifo1();
    else if (tip=='3')
        sockets();
	return 0;
}



