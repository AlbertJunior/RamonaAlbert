#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <pthread.h>
#include <sqlite3.h> 

#include <time.h>

/* portul folosit */
#define PORT 2910

/* codul de eroare returnat de anumite apeluri */
extern int errno;


pthread_mutex_t mlock=PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t block=PTHREAD_MUTEX_INITIALIZER;

typedef struct thData{
	int idThread; //id-ul thread-ului tinut in evidenta de acest program
	int cl; //descriptorul intors de accept
    int idConv;
    char userNameAlMeu[100];
    int logata;
    int admin;
}thData;
thData clienti[100];
int nrClienti;
void trimiteMesajul(char* mesaj, int sd);
void primesteMesajul(char* mesajPrimit, int sd);

#include "bazadate.h"
#include "bazanotificari.h"
#include "functii.h"
static void *treat(void *); /* functia executata de fiecare thread ce realizeaza comunicarea cu clientii */
void raspunde(void *);


int main ()
{
  struct sockaddr_in server;	// structura folosita de server
  struct sockaddr_in from;	
  int nr;		//mesajul primit de trimis la client 
  int sd;		//descriptorul de socket 
  int pid;
  pthread_t th[100];    //Identificatorii thread-urilor care se vor crea
	int i=0;
  
    for (i=0;i<100;i++)
        clienti[i].cl=-1;




  /* crearea unui socket */
  if ((sd = socket (AF_INET, SOCK_STREAM, 0)) == -1)
    {
      perror ("[server]Eroare la socket().\n");
      return errno;
    }
  /* utilizarea optiunii SO_REUSEADDR */
  int on=1;
  setsockopt(sd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on));
  
  /* pregatirea structurilor de date */
  bzero (&server, sizeof (server));
  bzero (&from, sizeof (from));
  
  /* umplem structura folosita de server */
  /* stabilirea familiei de socket-uri */
    server.sin_family = AF_INET;	
  /* acceptam orice adresa */
    server.sin_addr.s_addr = htonl (INADDR_ANY);
  /* utilizam un port utilizator */
    server.sin_port = htons (PORT);
  
  /* atasam socketul */
  if (bind (sd, (struct sockaddr *) &server, sizeof (struct sockaddr)) == -1)
    {
      perror ("[server]Eroare la bind().\n");
      return errno;
    }

  /* punem serverul sa asculte daca vin clienti sa se conecteze */
  if (listen (sd, 2) == -1)
    {
      perror ("[server]Eroare la listen().\n");
      return errno;
    }
  /* servim in mod concurent clientii...folosind thread-uri */
  while (1)
    {
      int client;
      thData * td; //parametru functia executata de thread     
      int length = sizeof (from);

      printf ("[server]Asteptam la portul %d...\n",PORT);
      fflush (stdout);

      // client= malloc(sizeof(int));
      /* acceptam un client (stare blocanta pina la realizarea conexiunii) */
      if ( (client = accept (sd, (struct sockaddr *) &from, &length)) < 0)
	{
	  perror ("[server]Eroare la accept().\n");
	  continue;
	}
	
        /* s-a realizat conexiunea, se astepta mesajul */
    
	// int idThread; //id-ul threadului
	// int cl; //descriptorul intors de accept

	td=(struct thData*)malloc(sizeof(struct thData));	
	td->idThread=i++;
	td->cl=client; // ai retin socketul prin care comunic
    
    for (i=1;i<100;i++)
    {
            if (clienti[i].cl==-1)
                 {clienti[i].idThread=i;
                 clienti[i].cl=client;break;}
    }
    nrClienti++;
    td->idThread=i;
	td->cl=client; // ai retin socketul prin care comunic
    

	pthread_create(&th[i], NULL, &treat, td);	      
				
	}//while    
};				
static void *treat(void * arg)
{		
		struct thData tdL; 
		tdL= *((struct thData*)arg);	
	//	printf ("[thread]- %d - Asteptam mesajul...\n", tdL.idThread);
	//	fflush (stdout);		 
		pthread_detach(pthread_self());		
		raspunde((struct thData*)arg);
		/* am terminat cu acest client, inchidem conexiunea */
		close ((intptr_t)arg);
		return(NULL);	
  		
};

void raspunde(void *arg)
{
    int nr, i=0, lungimeMesaj, mic_semnal, mic_semnal2;
    char mesajPrimit[1000], mesajDeTrimis[1000], mesajAlternativ[1000], cevaNou[1000],NumeChat[1000],Nume[1000],Prenume[1000], Data_nastere[1000], Tip[1000], Parola[1000], Username[1000], Rezultat[10000], Rezultat2[10000];
     /*Nume=(char*)malloc(sizeof(char)*1000);	
     Prenume=(char*)malloc(sizeof(char)*100);
     Data_nastere=(char*)malloc(sizeof(char)*1000);	
     Parola=(char*)malloc(sizeof(char)*100);
     Tip=(char*)malloc(sizeof(char)*100);
    Username=(char*)malloc(sizeof(char)*1000);
    Rezultat=(char*)malloc(sizeof(char)*10000);
Rezultat2=(char*)malloc(sizeof(char)*10000);
*/    
    int logata=0, admin=0;

     char *userNameAlMeu;
     userNameAlMeu=(char*)malloc(sizeof(char)*1000);
	struct thData tdL;
    int logat=0; 
	tdL= *((struct thData*)arg);
    trimiteMesajul("Bine ai venit!\nIn orice moment poti accesa comanda 'man' pentru a vedea obtiunile curente.", tdL.cl);
    while (1)
    {
       // printf("Ia sa astept\n");
       // sleep(1000);
	   primesteMesajul(mesajPrimit, tdL.cl);
		  //  strcat(mesajPrimit, "OK");      
            lungimeMesaj=strlen(mesajPrimit);
            if (strcmp(mesajPrimit, "man")==0 || (strcmp(mesajPrimit, "10")==0 && logata==1) || (strcmp(mesajPrimit, "4")==0 && logata==0))
            {
                if (logata==0)
                {
                    strcpy(Rezultat, "login  signup  search  man  quit");
                    punePeLinii(Rezultat);
                    trimiteMesajul(Rezultat, tdL.cl);
                }else
                { 
                    if (admin==0)
                    {
                          strcpy(Rezultat, "logout  search  notificari  posteaza  noutati  friends  create_chat  chat  delete_me  man");
                          punePeLinii(Rezultat);
                          trimiteMesajul(Rezultat, tdL.cl);
                    }
                    else
                    {
                         strcpy(Rezultat, "logout  search  notificari  posteaza  noutati  friends  create_chat  chat  delete_me  man  users  trimite_anunt  delete_user  check  conversatii");
                          punePeLinii(Rezultat);
                          trimiteMesajul(Rezultat, tdL.cl);
                    }
                }
            }
            else
            if (strcmp(mesajPrimit, "trimite_anunt")==0 || strcmp(mesajPrimit, "12")==0)
            {
                if (admin==1)
                {
                    trimiteMesajul("Te rugam sa introduci anuntul", tdL.cl);
                    primesteMesajul(mesajPrimit, tdL.cl);
                    strcpy(mesajDeTrimis, mesajPrimit);
                    sprintf(mesajPrimit, "\"%s\" by %s", mesajDeTrimis, userNameAlMeu);
                    users(Rezultat);
                    int nr=punePeLinii(Rezultat);
                    printf("%dNR\n", nr);
                    if (strlen(Rezultat)<3)
                                {
                                    trimiteMesajul("Nu exista utilizatori", tdL.cl);
                                  //  mic_semnal2=1;
                                    continue;
                                }
                                Rezultat[strlen(Rezultat)-3]=0;
                    strcat(Rezultat, "\nall (pentru toata lumea)");
                    trimiteMesajul(Rezultat, tdL.cl);
                    trimiteMesajul("Cui vrei sa il trimiti?", tdL.cl);

                    primesteMesajul(Nume, tdL.cl);
                    char dataActuala[500];
                    dataActualaa(dataActuala);
                    int j;
                    if (strcmp(Nume, "all")==0)
                    {
                        for (int i=1;i<=nr;i++)
                        {
                            itoa(i, Nume);
                            aflareNume(Rezultat, Nume);
                            Nume[strlen(Nume)-1]=0;
                            
                            introduc_notificare_diferita(mesajPrimit,Nume, dataActuala,Prenume);
                           for (j=1;j<=nrClienti;j++)
                            if (strcmp(clienti[j].userNameAlMeu, Nume)==0 && clienti[j].logata==1)
                                {
                                    trimiteMesajul(mesajPrimit, clienti[j].cl);
                                }
                        }
                        trimiteMesajul("Ai trimis cu succes!", tdL.cl);


                    }else
                    {

                           aflareNume(Rezultat, Nume);
                         if (Nume[0]==0) {trimiteMesajul("Nu ati introdus ceva valid", tdL.cl);continue;}
                           Nume[strlen(Nume)-1]=0;
                        introduc_notificare_diferita(mesajPrimit,Nume, dataActuala,Prenume);
                        for (i=1;i<=nrClienti;i++)
                            if (strcmp(clienti[i].userNameAlMeu, Nume)==0 && clienti[i].logata==1)
                                {
                                    trimiteMesajul(mesajPrimit, clienti[i].cl);
                                }
                        trimiteMesajul("Ai trimis cu succes!", tdL.cl);

                    }
                  //  adaugare_anunt(mesajPrimit);
                }
                else   
                  {
                        trimiteMesajul("Nu esti conectata cu un cont de admin", tdL.cl);
                        continue;
                    }            

            }
            else
             if (strcmp(mesajPrimit, "delete_user")==0 || strcmp(mesajPrimit, "13")==0)
            {
                if (admin==1)
                {
                    users(Rezultat);
                    punePeLinii(Rezultat);
                    if (strlen(Rezultat)<3)
                                {
                                    trimiteMesajul("Nu exista utilizatori", tdL.cl);
                                  //  mic_semnal2=1;
                                    continue;
                                }
                                Rezultat[strlen(Rezultat)-3]=0;
                    trimiteMesajul(Rezultat, tdL.cl);
                    trimiteMesajul("Pe cine vrei sa stergi?", tdL.cl);
                    primesteMesajul(Nume, tdL.cl);
                    aflareNume(Rezultat, Nume);
                    
                      if (Nume[0]==0) {trimiteMesajul("Nu ati introdus ceva valid", tdL.cl);continue;}
                    Nume[strlen(Nume)-1]=0;

                    int j;
                    int ok=0;
                    for (j=1;j<=nrClienti;j++)
                    {
                            printf("%s         %sBLA\n", clienti[j].userNameAlMeu, Nume);
                            if (strcmp(clienti[j].userNameAlMeu, Nume)==0 && clienti[j].logata==1)
                                {
                                   trimiteMesajul("Nu puteti cat utilizatorul este online", tdL.cl);
                                    ok=1;break;
                                }
                    }
                    if (ok==1) {continue;}

                    
                    delete_from_participanti(Nume);
                    delete_from_conversatii(Nume);
                    delete_from_persoane(Nume);
                     trimiteMesajul("Eliminare cu succes", tdL.cl);
                    
                }
                else   
                  {
                        trimiteMesajul("Nu esti conectata cu un cont de admin", tdL.cl);
                        continue;
                    }            

            }else
             if (strcmp(mesajPrimit, "users")==0 || strcmp(mesajPrimit, "11")==0)
            {
                if (admin==1)
                {
                    users(Rezultat);
                    punePeLinii(Rezultat);
                    if (strlen(Rezultat)<3)
                                {
                                    trimiteMesajul("Nu exista utilizatori", tdL.cl);
                                  //  mic_semnal2=1;
                                    continue;
                                }
                                Rezultat[strlen(Rezultat)-3]=0;
                    trimiteMesajul(Rezultat, tdL.cl);
                }
                else   
                  {
                        trimiteMesajul("Nu esti conectata cu un cont de admin", tdL.cl);
                        continue;
                    }            

            }else
            if (strcmp(mesajPrimit, "conversatii")==0 || strcmp(mesajPrimit, "15")==0)
            {
                if (admin==1)
                {

                    conversatii(Rezultat);
                    
                    punePeLinii(Rezultat);
                    if (strlen(Rezultat)<3)
                                {
                                    trimiteMesajul("Nu exista conversatii", tdL.cl);
                                  //  mic_semnal2=1;
                                    continue;
                                }
                                Rezultat[strlen(Rezultat)-3]=0;
                    trimiteMesajul(Rezultat, tdL.cl);

                    trimiteMesajul("La care vrei sa te uiti?", tdL.cl);
                    primesteMesajul(Nume, tdL.cl);
        
                    aflareNume(Rezultat, Nume);
                    

                if (Nume[0]==0) {trimiteMesajul("Nu ati introdus ceva valid", tdL.cl);continue;}
                    Nume[strlen(Nume)-1]=0;
                    
                    i=0;
                    while (Nume[i]!='-') i++;
                    Nume[i]=0;
                    printf("%sNUME\n",Nume);
                    int nrconv;
                    sscanf(Nume, "CONV[%d]", &nrconv);
                    char buff[20];
                    itoa(nrconv, buff);

                    trimiteMesajul("Ce vrei sa verifici?\n1.membrii\n2.mesaje", tdL.cl);
                    primesteMesajul(mesajPrimit, tdL.cl);

                     if (strcmp(mesajPrimit, "1")==0)
                    {
                        afisare_membrii_id(buff, Rezultat);
                        if (strlen(Rezultat)<3)
                            trimiteMesajul("Nu are niciun membru", tdL.cl);
                        else
                        {
                            Rezultat[strlen(Rezultat)-1]=0;
                            trimiteMesajul(Rezultat, tdL.cl);
                        }
                
                    }
                    else if (strcmp(mesajPrimit, "2")==0)
                    {
                           afisare_mesaje_id(buff, Rezultat);
                           if (strlen(Rezultat)<5)
                            trimiteMesajul("Nu a scris nimeni nimic inca", tdL.cl);
                            else
                            {
                                Rezultat[strlen(Rezultat)-1]=0;
                                trimiteMesajul(Rezultat, tdL.cl);
                            }
                    }
                    else
                        continue;
                    



                }
                else   
                  {
                        trimiteMesajul("Nu esti conectata cu un cont de admin", tdL.cl);
                        continue;
                    }            

            }else
             if (strcmp(mesajPrimit, "check")==0 || strcmp(mesajPrimit, "14")==0)
            {
                if (admin==1)
                {
                    users(Rezultat);
                    punePeLinii(Rezultat);
                    if (strlen(Rezultat)<3)
                                {
                                    trimiteMesajul("Nu exista utilizatori", tdL.cl);
                                  //  mic_semnal2=1;
                                    continue;
                                }
                                Rezultat[strlen(Rezultat)-3]=0;
                    trimiteMesajul(Rezultat, tdL.cl);
                    trimiteMesajul("Pe cine vrei sa verifici?", tdL.cl);
                    primesteMesajul(Nume, tdL.cl);
                    aflareNume(Rezultat, Nume);
                if (Nume[0]==0) {trimiteMesajul("Nu ati introdus ceva valid", tdL.cl);continue;}
                    Nume[strlen(Nume)-1]=0;
                    
                    trimiteMesajul("Ce vrei sa verifici?\n1.mesajele\n2.notificarile\n3.postarile", tdL.cl);
                    primesteMesajul(mesajPrimit, tdL.cl);

                    if (strcmp(mesajPrimit, "1")==0)
                    {
                        afisare_mesaje(Nume, Rezultat);
                        if (strlen(Rezultat)<5)
                            trimiteMesajul("Nu a trimis niciun mesaj", tdL.cl);
                        else
                        {
                            Rezultat[strlen(Rezultat)-1]=0;
                            trimiteMesajul(Rezultat, tdL.cl);
                        }
                
                    }
                    else if (strcmp(mesajPrimit, "2")==0)
                    {
                           afiseaza_notificarile_tale(Nume, Rezultat);
                           if (strlen(Rezultat)<5)
                            trimiteMesajul("Nu are notificari", tdL.cl);
                            else
                            {
                                Rezultat[strlen(Rezultat)-1]=0;
                                trimiteMesajul(Rezultat, tdL.cl);
                            }
                    }
                    else if (strcmp(mesajPrimit, "3")==0)
                    {
                            afiseaza_toate_postarile(Nume, Rezultat);
                             if (strlen(Rezultat)<5)
                            trimiteMesajul("Nu are nicio postare", tdL.cl);
                            else
                            {
                                Rezultat[strlen(Rezultat)-1]=0;
                                trimiteMesajul(Rezultat, tdL.cl);
                            }
                    }
                    else
                        continue;
                    


                }
                else   
                  {
                        trimiteMesajul("Nu esti conectata cu un cont de admin", tdL.cl);
                        continue;
                    }            

            }
            else  if (strcmp(mesajPrimit, "delete_me")==0 || strcmp(mesajPrimit, "9")==0)
            {
                          
                if (logata==1)
                {
                    trimiteMesajul("Esti sigur ca doresti stergerea contului? DA/NU", tdL.cl);
                     primesteMesajul(mesajPrimit, tdL.cl);
                    if (strcmp(mesajPrimit, "DA")==0)
                    {
                        delete_from_participanti(userNameAlMeu);
                        delete_from_conversatii(userNameAlMeu);
                        delete_from_persoane(userNameAlMeu);
                    }
                    else
                    continue;


                    logata=0;
                    for (i=1;i<=nrClienti;i++)
                            if (clienti[i].cl==tdL.cl)
                                {clienti[i].logata=0;clienti[i].userNameAlMeu[0]=0;}
                    
                }
                else trimiteMesajul("Inca nu ati intrat intr-un cont", tdL.cl);
                continue;
                
            }else
            if (strcmp(mesajPrimit, "quit")==0 || (logata==0 && strcmp(mesajPrimit, "5")==0))
                { 
                    if (logata==1)
                    {
                        trimiteMesajul("Intai trebuie sa va delogati cu 'logout'", tdL.cl);
                        continue;
                    }
                   for (i=1;i<=nrClienti;i++)
                        if (clienti[i].cl==tdL.cl)
                            clienti[i].cl=-1;
                    nrClienti--;
                     trimiteMesajul("OPRESTE-TE", tdL.cl);
                   break;
                }
            else
            if (strcmp(mesajPrimit, "posteaza")==0 || strcmp(mesajPrimit, "4")==0)
            {
                if (logata==0)
                {
                    trimiteMesajul("Trebuie sa te loghezi intai!", tdL.cl);
                    continue;
                }
                trimiteMesajul("Odata publicata o stire, aceasta nu va mai putea fi stersa.\nDoriti in continuare sa postati?\n1.DA\n2.NU", tdL.cl);
                  primesteMesajul(mesajPrimit, tdL.cl);
                if (strcmp(mesajPrimit, "NU")==0 || strcmp(mesajPrimit, "2")==0)
                {
                    trimiteMesajul("OK. Revenim la meniul principal", tdL.cl);
                    continue;
                }
                else  if (strcmp(mesajPrimit, "DA")==0 || strcmp(mesajPrimit, "1")==0)
                {

                        trimiteMesajul("Introduceti postarea pe care doriti sa o publicati", tdL.cl);
                        primesteMesajul(mesajPrimit, tdL.cl);
                        trimiteMesajul("Carui grup de oameni doriti sa distribuiti:\n1.prieten\n2.apropiat\n3.departat\n4.public", tdL.cl);

                        primesteMesajul(Tip, tdL.cl); //////////////////
                        if (strcmp(Tip, "1")==0)
                            strcpy(Tip, "prieten");
                        else if (strcmp(Tip, "2")==0)
                            strcpy(Tip, "apropiat");
                        else if (strcmp(Tip, "3")==0)
                            strcpy(Tip, "departat");
                         else if (strcmp(Tip, "4")==0)
                            strcpy(Tip, "public");

                        if (strcmp(Tip, "public")==0 || strcmp(Tip, "departat")==0 ||strcmp(Tip, "prieten")==0 || strcmp(Tip, "apropiat")==0)
                        {
                                char dataActuala[500];
                                dataActualaa(dataActuala);

                                adauga_postare(userNameAlMeu, mesajPrimit, Tip, dataActuala, Rezultat);

                                if (strcmp(Rezultat, "Nu este permis spamul")==0)
                                    trimiteMesajul(Rezultat, tdL.cl);
                                else
                                    trimiteMesajul("Ai postat cu succes!", tdL.cl);
                        }
                        else
                        {
            
                             trimiteMesajul("Nu ati introdus un numar valid.\nRevenim la meniul principal", tdL.cl);
                            continue;
                        }

                       
                }
                else
                {
                     trimiteMesajul("Nu ati introdus un numar valid.\nRevenim la meniul principal", tdL.cl);
                    continue;
                }
                                    
            }
            else
            if (strcmp(mesajPrimit, "noutati")==0 || strcmp(mesajPrimit, "5")==0)
            {

                 if (logata==0)
                    {
                        trimiteMesajul("Trebuie sa te loghezi intai!", tdL.cl);
                        continue;
                    }

                trimiteMesajul("Alegeti:\n1.cereri\n2.postari", tdL.cl);     
                primesteMesajul(mesajPrimit, tdL.cl);
                if (strcmp(mesajPrimit, "postari")==0 || strcmp(mesajPrimit, "2")==0)
                {
                    // pun intr o matrice toate postarile si le afisez cate una
                    afisare_postari(userNameAlMeu, Rezultat);
                    if (strlen(Rezultat)<5)
                        trimiteMesajul("Prietenii tai nu au postat nimic", tdL.cl);                    
                    trimiteMesajul(Rezultat, tdL.cl);
                    
                    
                }
                else
                if (strcmp(mesajPrimit, "cereri")==0 ||strcmp(mesajPrimit, "1")==0)
                {
                    do{
                         afisare_cerere(userNameAlMeu, Username, Tip); //al prietenului
                         if (Username[0]==0) {trimiteMesajul("Nu ai primit nicio cerere noua de prietenie",tdL.cl);break;}
                         trimiteMesajul("Ai primit cerere de prietenie de la: ", tdL.cl);
                         afisare_date_user(Username, Rezultat, Tip);
                        Rezultat[strlen(Rezultat)-1]=0;
                         trimiteMesajul(Rezultat, tdL.cl);
                         sleep(1);


                        char aux[100];
                               strcpy(aux, "Acesta doreste sa fie un: ");
                               strcat(aux, Tip);
        
                         trimiteMesajul(aux, tdL.cl); 
                         sleep(1);

                        // trimiteMesajul("Prietenii sai:", tdL.cl); 
                         Rezultat[0]=0;
                         afisare_prieteni(Username, Rezultat);
                         punePeLinii(Rezultat);
                         if (strlen(Rezultat)<3)
                                {
                                    trimiteMesajul("Nu are prieteni", tdL.cl);
                          
                                }
                         else
                        {
                            Rezultat[strlen(Rezultat)-3]=0;
                             char aux[1000];
                               strcpy(aux, "Prietenii sai:\n");
                               strcat(aux, Rezultat);
                          
                            trimiteMesajul(aux, tdL.cl);
                         }
                         trimiteMesajul("Accepti prietenia? DA sau NU", tdL.cl);
                         primesteMesajul(mesajPrimit, tdL.cl);  
                         if (strcmp(mesajPrimit, "DA")==0)
                            {
                                char dataActuala[500];
                                dataActualaa(dataActuala);
                                update_prietenie(userNameAlMeu, Username);
                                trimiteAnunt(Username, "Ti s-a acceptat cererea de la ", dataActuala, userNameAlMeu);
                            }
                         else 
                            stergere_prietenie(userNameAlMeu, Username);
                         trimiteMesajul("next/back", tdL.cl);
                         primesteMesajul(mesajPrimit, tdL.cl);   
                        
                    }while (strcmp(mesajPrimit, "next")==0);
                    if(strcmp(mesajPrimit, "next")==0)trimiteMesajul("Nu mai ai cereri la care sa raspunzi", tdL.cl);
                    continue;
                }
                else
                {
                    trimiteMesajul("Nu ai introdus un numar valid", tdL.cl);
                    continue;
                }
            }
            else
            if (logata==0 && (strcmp(mesajPrimit, "signup")==0 || strcmp(mesajPrimit, "2")==0))
            {
                trimiteMesajul("Pt inreg introduceti urmatoarele date:\nUserName:", tdL.cl);     
                primesteMesajul(Username, tdL.cl);
///////////////////////////////////////////////////////////
                trimiteMesajul("Nume:", tdL.cl);
                primesteMesajul(Nume, tdL.cl);

                trimiteMesajul("Prenume:", tdL.cl);
                primesteMesajul(Prenume, tdL.cl);

                trimiteMesajul("Data nastere in format 'DD-Mon-YYYY':", tdL.cl);
                primesteMesajul(Data_nastere, tdL.cl);


                trimiteMesajul("Parola:", tdL.cl);
                primesteMesajul(Parola, tdL.cl);
                
                trimiteMesajul("Tip-ul user-ului: \n1.obisnuit\n2.admin\nIntroduceti cifra corespunzatoare", tdL.cl);
                primesteMesajul(Tip, tdL.cl);
                char buff[20];
                if (strcmp(Tip, "2")==0)
                {
                    trimiteMesajul("Pentru a fi admin trebuie sa introduceti parola:", tdL.cl);
                    primesteMesajul(mesajPrimit, tdL.cl);
                    if (strcmp(mesajPrimit, "temarc")==0)
                           adaugare_persoana(Nume, Prenume, Data_nastere, Parola, "admin", Username, buff);
                    else
                        {
                            trimiteMesajul("Ati introdus parola gresita", tdL.cl);
                            continue;
                        }              
                }else if (strcmp(Tip, "1")==0)
                {
                    adaugare_persoana(Nume, Prenume, Data_nastere, Parola, "obisnuit", Username, buff);

                    if (strcmp(buff, "EROARE")==0)
                        trimiteMesajul("Mai exista un utilizator cu acest id", tdL.cl);
                    else
                        trimiteMesajul("Te-ai inregistrat cu succes! Acum poti folosi comanda 'login'", tdL.cl);
                    buff[0]=0;
                    continue;     
                }
                else
                {
                    trimiteMesajul("Te rugam sa introduci o valoare valida. Revenim la meniul principal", tdL.cl);
                    continue;       
                }            
            }
            else
            if (logata==0 &&(strcmp(mesajPrimit, "login")==0 || strcmp(mesajPrimit, "1")==0))
            {
                trimiteMesajul("Introduceti Username:", tdL.cl);     
                primesteMesajul(Username, tdL.cl);


                trimiteMesajul("Introduceti parola:", tdL.cl);
                primesteMesajul(Parola, tdL.cl);

                if (strlen(Parola)>0 && verificare_persoana(Username, Parola))
                    {
                        trimiteMesajul("Conectare cu succes", tdL.cl);
                        strcpy(userNameAlMeu, Username);
                        for (i=1;i<=nrClienti;i++)
                        {
                           if (clienti[i].idThread==tdL.idThread)
                                {strcpy(clienti[i].userNameAlMeu, userNameAlMeu);clienti[i].logata=1;}
                        }
                        //strcpy(tdL.userNameAlMeu, Username);
                        logata=1;
                        admin=esteAdmin(userNameAlMeu);
                    }
                else trimiteMesajul("Nume sau parola incorecte", tdL.cl);
                continue;
                
            }else
            if (logata==1 && (strcmp(mesajPrimit, "logout")==0 || strcmp(mesajPrimit, "1")==0))
            {
                if (logata==1)
                {
                logata=0;
                for (i=1;i<=nrClienti;i++)
                        if (clienti[i].cl==tdL.cl)
                            {clienti[i].logata=0;clienti[i].userNameAlMeu[0]=0;}
                userNameAlMeu[0]=0;
                trimiteMesajul("Tocmai ati iesit din cont", tdL.cl);}
                else trimiteMesajul("Inca nu ati intrat intr-un cont", tdL.cl);
                continue;
            }else


             if (strcmp(mesajPrimit, "search")==0 || (strcmp(mesajPrimit, "2")==0 && logata==1) ||  (strcmp(mesajPrimit, "3")==0 && logata==0))
            {
               int ok= Search(Rezultat, Nume, Prenume, tdL.cl, Username, userNameAlMeu, logata);
                if (ok==5)
                    continue;
                if (ok==0) 
                {
                    afiseaza_toate_postarile(userNameAlMeu, Rezultat);
                   // afisari_postari_publice(Username, Rezultat);
                     if (strlen(Rezultat)>3)
                    {
                        Rezultat[strlen(Rezultat)-1]=0;
                        trimiteMesajul(Rezultat, tdL.cl);
                    }
                    continue;
                }
                afisari_postari_publice(Username, Rezultat);
                if (strlen(Rezultat)>3)
                trimiteMesajul(Rezultat, tdL.cl);
                
                primesteMesajul(mesajPrimit, tdL.cl);
                Rezultat[0]=0;

            while (strcmp(mesajPrimit, "back")!=0 && strcmp(mesajPrimit, "2")!=0)
           {
                  
                if (strcmp(mesajPrimit, "add_friend")==0 || strcmp(mesajPrimit, "3")==0)
                {
                    if (logata==1)                
                    {
                        
                        trimiteMesajul("Alege tipul prieteniei\n1.departat\n2.apropiat\n3.prieten", tdL.cl);
                        primesteMesajul(mesajPrimit, tdL.cl); //este tipul prieteniei
                        
                        if (strcmp(mesajPrimit, "1")==0)
                               adauga_prietenie(userNameAlMeu, Username, "departat", Rezultat);
                        else if (strcmp(mesajPrimit, "2")==0)
                               adauga_prietenie(userNameAlMeu, Username, "apropiat", Rezultat);
                        else if (strcmp(mesajPrimit, "3")==0)
                            adauga_prietenie(userNameAlMeu, Username, "prieten", Rezultat);
                        else    {trimiteMesajul("Nu ati introdus un numar valid", tdL.cl);continue;}                     
    
                        if (strcmp(Rezultat, "Deja sunteti prieteni sau deja ati trimis cerere de prietenie. Consultati comanda 'friends'")==0)
                            trimiteMesajul(Rezultat, tdL.cl);
                        else
                        {
                            char dataActuala[500];
                            dataActualaa(dataActuala);
                            trimiteMesajul("Ai trimis cererea de prietenie!", tdL.cl);
                            trimiteAnunt(Username, "Ti-a trimis cerere de prietenie ", dataActuala, userNameAlMeu);
                        }
                    }
                    else trimiteMesajul("Trebuie sa te loghezi mai intai", tdL.cl);
                }      
                else if (strcmp(mesajPrimit, "delete_friend")==0 ||strcmp(mesajPrimit, "4")==0)
                {
                    if (logata==1)                
                    {
                        char dataActuala[500];
                        dataActualaa(dataActuala);
                        Rezultat[0]=0;
                        sterge_prietenie(userNameAlMeu, Username, Rezultat);
                        if (strlen(Rezultat)<2)
                            trimiteMesajul("Nu esti inca prieten cu aceasta persoana", tdL.cl);
                        else
                        {
                            trimiteAnunt(Username, "Ai fost sters de la prieteni de catre ", dataActuala, userNameAlMeu);
                            trimiteMesajul("Ai \"scapat\" de acest prieten", tdL.cl);
                        }                    
                    }
                    else trimiteMesajul("Trebuie sa te loghezi mai intai", tdL.cl);
                }
                else  if (strcmp(mesajPrimit, "man")==0 || strcmp(mesajPrimit, "1")==0)
                {
                    if (logata==0)
                    {
                        strcpy(Rezultat, "man  back");
                        punePeLinii(Rezultat);
                        trimiteMesajul(Rezultat, tdL.cl);
                    }else
                    { 
                        strcpy(Rezultat, "man  back  add_friend  delete_friend");
                        punePeLinii(Rezultat);
                        trimiteMesajul(Rezultat, tdL.cl);
                    }
                }
                else
                       trimiteMesajul("Va rugam sa introduceti o comanda valida. Consultati comanda 'man'", tdL.cl);
            
                primesteMesajul(mesajPrimit, tdL.cl);
            }
            trimiteMesajul("Ai iesit de pe wall-ul persoanei", tdL.cl);
            continue;     
                
            }else
            if (strcmp(mesajPrimit, "notificari")==0 || strcmp(mesajPrimit, "3")==0)
            {
                if (logata==0)
                {                
                    trimiteMesajul("Trebuie sa te loghezi intai", tdL.cl);
                    continue;
                }
                afiseaza_notificarile_tale(userNameAlMeu, Rezultat);
                Rezultat[strlen(Rezultat)-1]=0;
                trimiteMesajul(Rezultat, tdL.cl);
            
            }
            else
            if (strcmp(mesajPrimit, "friends")==0 || strcmp(mesajPrimit, "6")==0)
            {
                if (logata==0)
                    {
                             trimiteMesajul("Mai intai trebuie sa intrii in cont", tdL.cl);
                                    continue;
                }
                Rezultat[0]=0;
                afisare_prieteni(userNameAlMeu, Rezultat);
                afisare_prieteni_id(userNameAlMeu, Rezultat2);
                printf("Am reusit\n");
                prelucrare(Rezultat, Rezultat2);
                punePeLinii(Rezultat);
                if (strlen(Rezultat)<3)
                                {
                                    trimiteMesajul("Ne pare rau, dar nu ai prieteni..", tdL.cl);
                                    continue;
                                }
                Rezultat[strlen(Rezultat)-3]=0;
                trimiteMesajul(Rezultat, tdL.cl);
                continue;             
                
            }else
            if (strcmp(mesajPrimit, "create_chat")==0 || strcmp(mesajPrimit, "7")==0)
            {
                if (logata==0)
                    {
                        trimiteMesajul("Trebuie sa te loghezi intai!", tdL.cl);
                        continue;
                    }

                Rezultat[0]=0;
                afisare_prieteni(userNameAlMeu, Rezultat);
                punePeLinii(Rezultat);
                if (strlen(Rezultat)<3)
                                {
                                    trimiteMesajul("Ne pare rau, dar nu ai prieteni..", tdL.cl);
                                    continue;
                                }
                Rezultat[strlen(Rezultat)-3]=0;
                trimiteMesajul(Rezultat, tdL.cl);
    

                trimiteMesajul("Introduceti numarul corespunzator persoanei:", tdL.cl); 
                primesteMesajul(Nume, tdL.cl);
            
                aflareNume(Rezultat, Nume);
                  if (Nume[0]==0) {trimiteMesajul("Nu ati introdus ceva valid", tdL.cl);continue;}
                separareNume(Nume, Prenume);
                
                trimiteMesajul("Introduceti un nume pentru conversatie:", tdL.cl);     
                primesteMesajul(Parola, tdL.cl);
                
                afisare_date(Nume, Prenume, Rezultat, Username);
                if (strcmp(Rezultat, "EROARE")==0)
                         trimiteMesajul("Nu este gasita aceasta persoana", tdL.cl); 
                else
                {    
                    Rezultat[0]=0;
                    creare_conv(userNameAlMeu, Username, Rezultat, Parola);  
                    trimiteMesajul("Conv creata cu succes!", tdL.cl); 
                }
            } else
            if (strcmp(mesajPrimit, "chat")==0 || strcmp(mesajPrimit, "8")==0)
            {
                 if (logata==0)
                    {
                             trimiteMesajul("Mai intai trebuie sa intrii in cont", tdL.cl);
                                    continue;
                }
                Rezultat[0]=0;
                afisare_chaturi(userNameAlMeu, Rezultat);
                trimiteMesajul("Alege chat-ul in care vrei sa intrii", tdL.cl);
        if (strlen(Rezultat)<3)
                                {
                                    trimiteMesajul("Nu exista niciun chat. Creaza unul utilizand comanda 'create_chat'", tdL.cl);
                                    continue;
                                }
                punePeLinii(Rezultat);
                Rezultat[strlen(Rezultat)-3]=0;
                trimiteMesajul(Rezultat, tdL.cl);

                primesteMesajul(Nume, tdL.cl); //primesc un nume de chat
                aflareNume(Rezultat, Nume);
                 if (Nume[0]==0) {trimiteMesajul("Nu ati introdus ceva valid", tdL.cl);continue;}
                Nume[strlen(Nume)-1]=0;
                printf("%s%s!!!!!!!!!\n", Nume, NumeChat);
                strcpy(NumeChat, Nume);
                printf("%s%s!!!!!!!!!\n", Nume, NumeChat);
                Rezultat[0]=0;
                extragereIdChat(Nume, userNameAlMeu, Rezultat);
                Rezultat[strlen(Rezultat)-1]=0;
                strcpy(cevaNou, Rezultat);
                strcpy(Parola, Rezultat);
                
                printf("---------%s %s\n", Parola, Rezultat);
                tdL.idConv=atoi(Rezultat);
                
                 char buff[20];
                    strcpy(buff, Rezultat);
          //       itoa(tdL.idConv, buff);
                    mic_semnal=0;
                    mic_semnal2=0;

                 for (i=1;i<=nrClienti;i++)
                    {
                       if (clienti[i].idConv==tdL.idConv && clienti[i].cl!=tdL.cl)
                        {
                             aflare_nume(userNameAlMeu, Rezultat);
                                char aux[100];
                               strcpy(aux, "Anunt: A intrat in chat ");
                               strcat(aux, Rezultat);
        
                              trimiteMesajul(aux, clienti[i].cl);
                        }
                            
                    }                
                trimiteMesajul("Ai intrat cu succes in conversatie", tdL.cl);
                  for (i=1;i<=nrClienti;i++)
                    {
                       if (clienti[i].idThread==tdL.idThread)
                            clienti[i].idConv=tdL.idConv;
                    }
                printf("%d\n", tdL.idConv);
printf("%s%s\n", Nume, NumeChat);
                primesteMesajul(mesajPrimit, tdL.cl);
                while (strcmp(mesajPrimit, "back")!=0 && strcmp(mesajPrimit, "7")!=0)
                {
                    mic_semnal2=0;
                    printf("%s%s\n", Nume, NumeChat);
                        if (strcmp(mesajPrimit, "man")==0)
                        {
                            strcpy(Rezultat, "add_friend  delete_friend  istoric  users  leave_chat  rename  back  *orice_alt_mesaj_va_fi_trimis_celorlalti*");
                            punePeLinii(Rezultat);
                            trimiteMesajul(Rezultat, tdL.cl);
                        }
                            else
                            if (strcmp(mesajPrimit, "add_friend")==0 || strcmp(mesajPrimit, "1")==0)
                            {
                                    Rezultat[0]=0;
                                    afisare_prieteni(userNameAlMeu, Rezultat);

                                    punePeLinii(Rezultat);
                                      if (strlen(Rezultat)<3)
                                            {
                                                trimiteMesajul("Ne pare rau dar nu ai niciun prieten", tdL.cl);
                                                mic_semnal2=1; primesteMesajul(mesajPrimit, tdL.cl);continue;
                                            }

                                         Rezultat[strlen(Rezultat)-3]=0;
                                         trimiteMesajul(Rezultat, tdL.cl);
                                    
                                            trimiteMesajul("Pe cine vrei sa adaugi ca prieten?", tdL.cl);

                                            primesteMesajul(Nume, tdL.cl);
                                            strcat(Rezultat, "\n");
                                            aflareNume(Rezultat, Nume);
                                     if (Nume[0]==0) {
                                        trimiteMesajul("Nu ati introdus ceva valid", tdL.cl);
                                        mic_semnal2=1; primesteMesajul(mesajPrimit, tdL.cl);
                                        continue;
                                    }
                                    separareNume(Nume, Prenume);

                                    scoatereIDprieten(userNameAlMeu, Nume, Prenume, Rezultat);
                                    printf("%s\n", Rezultat);
                                    char Eroare[20];
                                    Eroare[0]=0; 
                                    char dataActuala[500];
                                    dataActualaa(dataActuala);
                                    adaugare_participanti(Rezultat, cevaNou, Eroare);
                                    if (Eroare[0]!=0)
                                        trimiteMesajul("Deja face parte din cov", tdL.cl);  
                                    else
                                    {
                                        strcpy(mesajAlternativ, "Anunt: A fost adaugat in Chatul:");
                                        strcat(mesajAlternativ, NumeChat);
                                        strcat(mesajAlternativ, " persoana: ");
                                        strcat(mesajAlternativ, Nume);  
                                        strcat(mesajAlternativ, " ");
                                        strcat(mesajAlternativ, Prenume);
                                        TrimiteNotificare(tdL.idConv, mesajAlternativ, userNameAlMeu, dataActuala, Rezultat, NumeChat);
                                        trimiteMesajul ("Adaugare cu succes!", tdL.cl);
                                    }  

                            }
                            else if (strcmp(mesajPrimit, "istoric")==0 || strcmp(mesajPrimit, "3")==0)
                            {
                                trimiteMesajul("Alegeti o varianta cu ajutorul caruia doriti sa introduceti data de la care sa vizualitati mesajele\n1. 'n' days ago\n2. Dupa urmatorul format 'YYYY-MM-DD HH:MI:SS'",tdL.cl);
                                primesteMesajul(mesajPrimit, tdL.cl);
                                if (strcmp(mesajPrimit, "2")==0)
                                {
                                        trimiteMesajul("Introduceti data de la care doriti sa vizualizati\nDupa urmatorul format 'YYYY-MM-DD HH:MI:SS'", tdL.cl);   
                                        primesteMesajul(mesajPrimit, tdL.cl);
                                
                                        if (verificareData(mesajPrimit)==0)
                                            {
                                                trimiteMesajul("Nu ati introdus o data valida. Va rugam sa respectati formatul'", tdL.cl);  
                                                mic_semnal2=1; primesteMesajul(mesajPrimit, tdL.cl);continue;
                                             } 
                                }
                                if (strcmp(mesajPrimit, "1")==0)
                                {
                                        trimiteMesajul("Introduceti valoarea lui 'n', unde 'n' este numarul de zile de la care doriti sa vizualizati mesajele", tdL.cl);
                                        primesteMesajul(mesajPrimit, tdL.cl); 
                                        nDaysAgo(mesajPrimit, Rezultat);
                                        strcat(Rezultat, " -> incepanad de la aceasta data");
                                        trimiteMesajul(Rezultat, tdL.cl);
                                        strcpy(mesajPrimit, Rezultat);
                                        sleep(1);
                                        
                                }
                                else
                                {   
                                    trimiteMesajul("Nu ati introdus un numar valid", tdL.cl);  
                                                mic_semnal2=1; primesteMesajul(mesajPrimit, tdL.cl);continue;
                                }

                                afiseazaReplici(Parola, mesajPrimit, Rezultat); //idconv
                                if (strlen(Rezultat)<3)
                                    trimiteMesajul("Nu s-a vorbit pe acest chat", tdL.cl);
                                else
                                {
                                    Rezultat[strlen(Rezultat)-1]=0;  
                                    trimiteMesajul(Rezultat, tdL.cl); 
                                } 
                            }
                            else if (strcmp(mesajPrimit, "users")==0 || strcmp(mesajPrimit, "4")==0)
                            {
                                afisare_participanti(buff, Rezultat, userNameAlMeu);
                                        punePeLinii(Rezultat);
                                        if (strlen(Rezultat)<3)
                                        {
                                            trimiteMesajul("Nu mai este nimeni in conversatie", tdL.cl);
                                            mic_semnal2=1; primesteMesajul(mesajPrimit, tdL.cl);continue;
                                        }
                                        Rezultat[strlen(Rezultat)-3]=0;
                                        trimiteMesajul(Rezultat, tdL.cl);
                                 mic_semnal2=1;
                                primesteMesajul(mesajPrimit, tdL.cl);
                                continue;
                            }
                            else if (strcmp(mesajPrimit, "delete_friend")==0 || strcmp(mesajPrimit, "2")==0)
                            {
                                
                                verificare_admin(buff, Rezultat);
                                if (strcmp(Rezultat, userNameAlMeu)!=0)
                                    trimiteMesajul("Nu ai acest drept..nu esti admin", tdL.cl);
                                else
                                    {
               
                                        afisare_participanti(buff, Rezultat, userNameAlMeu);
                                        punePeLinii(Rezultat);
                                        if (strlen(Rezultat)<3)
                                        {
                                            trimiteMesajul("Nu mai este nimeni in conversatie", tdL.cl);
                                            mic_semnal2=1; primesteMesajul(mesajPrimit, tdL.cl);continue;
                                        }
                                        Rezultat[strlen(Rezultat)-3]=0;
                                        trimiteMesajul(Rezultat, tdL.cl);
                                
                                        trimiteMesajul("Pe cine vrei sa stergi?", tdL.cl);

                                        primesteMesajul(Nume, tdL.cl);

         //                               Rezultat[strlen(Rezultat)+2]='0';
           //                              Rezultat[strlen(Rezultat)+1]='\n';

                                        aflareNume(Rezultat, Nume);

                                       if (Nume[0]==0) {trimiteMesajul("Nu ati introdus ceva valid", tdL.cl); primesteMesajul(mesajPrimit, tdL.cl);continue;}
                                        printf("NUME:%s\n", Nume);

                                        separareNume(Nume, Prenume);
                                        char dataActuala[500];
                                        dataActualaa(dataActuala);
                                        
                                        stergere_participant(NumeChat, Nume, Prenume, buff, Rezultat, dataActuala);


                                        if (strcmp(Rezultat, "EROARE1")==0)
                                        {
                                            trimiteMesajul("Nu poti face acest lucru cat timp este intrat in conversatie", tdL.cl);
                                            
                                        }
                                        else
                                        {
                                            strcpy(mesajAlternativ, "Anunt: A fost eliminat din chat-ul ");
                                            strcat(mesajAlternativ, NumeChat);
                                            strcat(mesajAlternativ, " persoana: ");
                                            strcat(mesajAlternativ, Nume);  
                                            strcat(mesajAlternativ, " ");
                                            strcat(mesajAlternativ, Prenume);
                                            
                                            TrimiteNotificare(tdL.idConv, mesajAlternativ, userNameAlMeu, dataActuala, Prenume, NumeChat);
                                            trimiteMesajul("Eliminare cu succes!", tdL.cl);
                                        }
                                    }
                            }  
                            else if (strcmp(mesajPrimit, "leave_chat")==0 || strcmp(mesajPrimit, "5")==0)
                            {

                                verificare_admin(buff, Rezultat);
                                if (strcmp(Rezultat, userNameAlMeu)==0)
                                  trimiteMesajul("Nu poti parasi acest grup pentru ca esti admin", tdL.cl);
                                else{
                                    trimiteMesajul("Esti sigur? DA/NU", tdL.cl);
                                    primesteMesajul(mesajPrimit, tdL.cl);
                                    if (strcmp(mesajPrimit, "DA")==0)
                                    {
                                        char dataActuala[500];
                                        dataActualaa(dataActuala);
                                        parasire_chat(buff, userNameAlMeu);

                                        aflare_nume(userNameAlMeu, Rezultat);
                                           
                                        strcpy(mesajAlternativ, "Anunt: A parasit Chatul ");
                                        strcat(mesajAlternativ, NumeChat);
                                        strcat(mesajAlternativ, " persoana: ");
                                        strcat(mesajAlternativ, Rezultat);  
                                            
                                        TrimiteNotificare(tdL.idConv, mesajAlternativ, userNameAlMeu, dataActuala, Rezultat, NumeChat);
                                        mic_semnal=1;
                                        break;
                                    }
                                }                    
                            } 
                            else if (strcmp(mesajPrimit, "rename")==0 || strcmp(mesajPrimit, "6")==0)
                            {

                                verificare_admin(buff, Rezultat);
                                if (strcmp(Rezultat, userNameAlMeu)==1)
                                  trimiteMesajul("Nu poti face acest lucru pentru ca nu esti admin", tdL.cl);
                                else{
                                    trimiteMesajul("Introduceti noua denumire", tdL.cl);
                                    primesteMesajul(mesajPrimit, tdL.cl);
                                    schimbareDenumireConv(mesajPrimit, buff);
                                    trimiteMesajul("Ati schimbat denumirea cu succes!", tdL.cl);     
                                }                    
                            }                
                            else
                            if (mic_semnal2==0)
                            { 
                                char dataActuala[500];

                                extragereNume(userNameAlMeu, Rezultat); //functie importanta                     
                                strcpy(dataActuala, mesajPrimit);
                                strcpy(mesajPrimit, Rezultat);
                                strcat(mesajPrimit, ": ");
                                strcat(mesajPrimit, dataActuala);

                                dataActualaa(dataActuala); // creez o data actuala corecta
                                printf("%s\n", dataActuala);

                                adauga_replica(userNameAlMeu, mesajPrimit, Parola, dataActuala);
                        
                                //printf("Am ajuns dupa ce am adaugar replica\n");
                                TrimiteTuturor(NumeChat, userNameAlMeu, tdL.idConv, tdL.cl, mesajPrimit, clienti, nrClienti);
                                //printf("De asta am eroare\n");
                            }
                    mic_semnal2=0;
                    primesteMesajul(mesajPrimit, tdL.cl);

                }
                if (mic_semnal==0)
                for (i=1;i<=nrClienti;i++)
                    {
                       if (clienti[i].idConv==tdL.idConv && clienti[i].cl!=tdL.cl)
                        {
                              aflare_nume(userNameAlMeu, Rezultat);
                                char aux[100];
                               strcpy(aux, "Anunt: A iesit din chat ");
                               strcat(aux, Rezultat);
        
                              trimiteMesajul(aux, clienti[i].cl);
                        }
                    }
                
                tdL.idConv=0;
                pthread_mutex_lock(&mlock);
                 for (i=1;i<=nrClienti;i++)
                    {
                       if (clienti[i].idThread==tdL.idThread)
                            clienti[i].idConv=0;
                    }
                pthread_mutex_unlock(&mlock);
                trimiteMesajul("Ai iesit din conversatie", tdL.cl);
                continue;
            }

            else 
            {
                trimiteMesajul("Va rugam sa introduceti o comanda valida. Consultati comanda 'man'", tdL.cl);
            }
            
	
    }

}



void trimiteMesajul(char* mesaj, int sd)
{
    int nr=strlen(mesaj);
    write(sd, &nr, sizeof(int));
    write(sd, mesaj, nr);

}

void primesteMesajul(char* mesajPrimit, int sd)
{
    int nr;
       if (read (sd, &nr,sizeof(int)) <= 0)
			    {
			   //   printf("[Thread %d]\n",tdL.idThread);
			     // perror ("Eroare la read() de la client.\n");
			    
			    }
                  if (read (sd, mesajPrimit,nr) <= 0)
			    {
			     // printf("[Thread %d]\n",tdL.idThread);
			     // perror ("Eroare la read() de la client.\n");  
			    }
          mesajPrimit[nr]=0;
}



