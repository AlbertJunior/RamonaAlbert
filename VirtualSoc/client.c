/* cliTCPIt.c - Exemplu de client TCP
   Trimite un numar la server; primeste de la server numarul incrementat.
         
   Autor: Lenuta Alboaie  <adria@infoiasi.ro> (c)2009
*/
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <pthread.h>


/* codul de eroare returnat de anumite apeluri */
extern int errno;

typedef struct thData{
	int tip; //id-ul thread-ului tinut in evidenta de acest program
}thData;

/* portul de conectare la server*/
int port;
void citire();
void scriere();
static void *treat(void * arg); /* functia executata de fiecare thread ce realizeaza comunicarea cu clientii */
int sd; // descriptorul de socket

int main (int argc, char *argv[])
{

  struct sockaddr_in server;	// structura folosita pentru conectare 
  		// mesajul trimis
  int nr=0;
  pthread_t th[2];

  /* exista toate argumentele in linia de comanda? */
  if (argc != 3)
    {
      printf ("Sintaxa: %s <adresa_server> <port>\n", argv[0]);
      return -1;
    }

  /* stabilim portul */
  port = atoi (argv[2]);

  /* cream socketul */
  if ((sd = socket (AF_INET, SOCK_STREAM, 0)) == -1)
    {
      perror ("Eroare la socket().\n");
      return errno;
    }

  /* umplem structura folosita pentru realizarea conexiunii cu serverul */
  /* familia socket-ului */
  server.sin_family = AF_INET;
  /* adresa IP a serverului */
  server.sin_addr.s_addr = inet_addr(argv[1]);
  /* portul de conectare */
  server.sin_port = htons (port);

  /* ne conectam la server */
  if (connect (sd, (struct sockaddr *) &server,sizeof (struct sockaddr)) == -1)
    {
      perror ("[client]Eroare la connect().\n");
      return errno;
    }
//printf("%d\n", sd);
    thData * td;
    thData * td1;

    td=(struct thData*)malloc(sizeof(struct thData));	
	td->tip=1;
       pthread_create(&th[0], NULL, &treat, td);
   // printf("ceva2\n");
    td1=(struct thData*)malloc(sizeof(struct thData));	
	td1->tip=2;
      pthread_create(&th[1], NULL, &treat, td1);
    while (1){}
  //  printf("ceva3\n");
  /* inchidem conexiunea, am terminat */
  //close (sd);
}
static void *treat(void * arg)
{		 
	
        struct thData tdL; 
		tdL= *((struct thData*)arg);	
		//printf ("[thread]- %d - Asteptam mesajul...\n", tdL.tip);
        //printf ("%d\n", sd);
		fflush (stdout);		 
		//pthread_detach(pthread_self());	
        //printf("altceva\n");
        if (tdL.tip==1) scriere();
            else citire();
		/* am terminat cu acest client, inchidem conexiunea */
		//close ((intptr_t)arg);
		return(NULL);	
  		
};


void scriere()
{
      char buf[1000];
    int nr;
    while (1)
    {
	     
          nr=read (0, buf, sizeof(buf));
          nr--;
           buf[nr]=0;

          /* trimiterea mesajului la server */
           
            char* mesajDeTransmis=buf;

            int nr1= strlen(mesajDeTransmis);
            //printf("%d\n", nr1);

          if (write (sd,&nr1,sizeof(int)) < 0)
            {
              perror ("[client]Eroare la write() spre server.\n");
              return errno;
            }
          if (write (sd,mesajDeTransmis,nr1) < 0)
            {
              perror ("[client]Eroare la write() spre server.\n");
              return errno;
            }
	
    }
}

void citire()
{
    int nr1;
    char mesajDePrimit[10000];
    while (1)
    {
	     

          /* citirea raspunsului dat de server 
             (apel blocant pina cind serverul raspunde) */
            if (read (sd, &nr1,sizeof(int)) < 0)
            {
              perror ("[client]Eroare la read() de la server.\n");
              return errno;
            }
            if (read (sd, mesajDePrimit,nr1) < 0)
                {
                  perror ("[client]Eroare la read() de la server.\n");
                  return errno;
                }
            mesajDePrimit[nr1]=0;
          /* afisam mesajul primit */
          printf ("\n(^-^)\n%s\n(^-^)\n\n", mesajDePrimit);
           if (strcmp(mesajDePrimit, "OPRESTE-TE")==0)
                {close(sd);exit(0);}
	
    }
}




