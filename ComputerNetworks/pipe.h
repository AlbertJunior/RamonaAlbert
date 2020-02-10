#define MSG1 "Va rugam introduceti 1, 2, respectiv 3 pentru a face comunicarea prin pipe-uri, mkfifo, respectiv sockets.\n"
#define MSG2 "Va rugam sa va logati cu comanda 'login : user'\n"
#define MSG_UV "Utilizator valid"
#define MSG_EV "Exit valid"
#define MSG_UIV "Utilizator invalid"
#define MSG_EIV "Exit invalid"
#define MSG_DELOGARE "Delogare"
#define MSG_EXIT "Iesire"

#define MSG3 "Conectare cu succes\n"
#define MSG4 "Deja sunteti conectat\n"
#define MSG5 "Userul cu care incercati sa va conectati nu este valid\n"
#define MSG6 "Trebuie sa va deconectati cu Comanda 'logout'\n"
#define MSG7 "Multumim pentru utilizare\n"
#define MSG8 "Deja sunteti delogat\n"
#define MSG9 "Delogare cu succes\n"


void pipe_uri()
{
     char cerinta[500];
     int conectat = 0;
     int p[2], q[2];
     if (-1==pipe(p))
     {
         perror("Eroare la creare pipe:");
	 exit(1);
     }
     if (-1==pipe(q))
     {
         perror("Eroare la creare pipe:");
	 exit(2);
     }
    int pid;
    if (-1==(pid=fork()))
    {
        perror("Eroare la fork:");
	exit(3);
    }
    if (pid==0) //SC
    { 
          close(p[0]);
          close(q[1]);
          int octetiCititi;
          char buff[50000];
          while (read(q[0], &octetiCititi, sizeof(int))!=0)
          {
               read(q[0], buff, octetiCititi);
               buff[octetiCititi]=0;
              // printf("[SC] am primit cerinta [%s %d]de la P\n", buff, octetiCititi);
               int p2[2], q2[2];
               if (-1==pipe (p2))
               {
                    perror("Eroare la creare pipe:");
		    exit(4);
               }
               if (-1==pipe(q2))
               { 
                    perror("Eroare la creare pipe:");
		    exit(5);

               }
               int pid2;
               if (-1==(pid2=fork()))
               {
                    perror("Eroare la fork:");
		    exit(5);
               }
               if (pid2!=0) // SUNT IN SC
               {
                    close(q2[0]);
                    close(p2[1]);
                    write(q2[1], &octetiCititi, sizeof(int));
                    write(q2[1], buff, octetiCititi);
                    //printf("[SC] am trimis copilului cerinta[%s,%d]\n", buff, octetiCititi);
                    int i=0;
                    int nr;
                    while (1)
                    {
                        nr=read(p2[0], &buff[i], 1);
                        if (nr==0)
                            break;
                        i++;
                    }
                    buff[i]=0;
                    //printf("[SC] Am citit din copil cuvantul [%s %d]\n", buff, i);
                    write(p[1], &i, sizeof(int));
                    write(p[1], buff, i);
                    //printf("[SC] l am dat parintelui P cuvantul %s de %d carecrere\n", buff, octetiCititi);
                    close(q2[1]);
                    close(p2[0]);
                    wait(NULL);
               }
               else // SUNT IN COPIL C
               {
                    close(q2[1]);
                    close(p2[0]);

                    int octetiCititi1;
                    //printf("[C] S-a ajuns in copil\n");
                    read(q2[0], &octetiCititi1, sizeof(int));
                    read(q2[0], buff, octetiCititi1);
                    buff[octetiCititi]=0;
                    close(q2[0]);
                    //printf("[C] Am citit cerinta [%s, %d]de la P\n", buff, octetiCititi);
                    int i=0;
		    int j=0;
		    char ch;
		    char* treaba[50];
		    char sir[100][50];
		    int ok=0;
                    int nr=0;
		    while (buff[nr]!=0)
		   {
			    if (buff[nr]==' ' && ok==1)
			    {
				    sir[j][i]=0;
				    treaba[j]=sir[j];
				    j++;i=0;
			  	    ok=0;
			    }
			    else if (buff[nr]!=' ')
			    {
				    ok=1;
				    sir[j][i]=buff[nr];
				    i++;
			    }
        	                nr++;
		    }
		    sir[j][i]=0;
		    treaba[j]=sir[j];
		    treaba[j+1]=NULL;
                    char ajutor[100]="./";
                    char user[100][100];

                    if (strcmp(sir[0], "login")==0 && j+1==3)
                    {
                            i=0;
                            j=0;
                            int ok=0;
                            int fd=open("users.txt", O_RDONLY);
	        	    while (octetiCititi=read(fd, &ch, 1)!=0)
		            {
		                if (ch=='\n')
		                {
			                user[j][i]=0;
			                j++;i=0;
		                }
		                else
		               {
			                user[j][i]=ch;
			                i++;
		                }
	                    }
                            close(fd);
                            for (i=0;i<j;i++)
	                    {
                                //printf("%s\n", user[i]);
			             if (strcmp(user[i], sir[2])==0)
			             {
				              ok=1;
					                //printf("[C]Am gasit un utilizator\n");
		         	              break;
				     }
		            }
                            if (ok==1)
                                write(p2[1], MSG_UV, strlen(MSG_UV));
                            else
                                write(p2[1], MSG_UIV, strlen(MSG_UIV));
                            close(p2[1]);
                            exit(1);
                    }
                    else
                    if (strcmp(sir[0], "logout")==0 && j+1==1)
                    {
                        write(p2[1], MSG_DELOGARE, strlen(MSG_DELOGARE));
                        close(p2[1]);
                        exit(1);
                    }
                    if (strcmp(sir[0], "quit")==0 && j+1==1)
                    {
                        write(p2[1], MSG_EXIT, strlen(MSG_EXIT));
                        close(p2[1]);
                        exit(1);
                    }
                    if ((strcmp(sir[0], "mystat")==0 || strcmp(sir[0], "myfind")==0) && j+1==2)
                    {
                        sir[0][0]=sir[0][0]-('a'-'A');
                        sir[0][2]=sir[0][2]-('a'-'A');
                        strcat(ajutor, sir[0]);
                        strcat(ajutor, ".exe");
                        strcpy(sir[0], ajutor);
                    }
                    dup2(p2[1], 1);///////dup
                    dup2(p2[1], 2);
                    //printf("%s\n%s", treaba[0], treaba[1]);
		    execvp(treaba[0], treaba);
		    printf("Nu ati introdus o comanda valida\n");
		    exit(6);
                    //printf("[C] Am trimis lui SC un cuvantul [%s %d]\n", trimis, 5);
                   // close(p2[1]);
               }
         }
    }
    else // parintele doar primeste ce trebyuie sa afiseze 
        {
            int octetiCititi, octetiScrisi;
            int nrOcteti;
            close(p[1]);
            close(q[0]);
            while (1)
           {
	        octetiCititi=read(0, cerinta, 500);
	        cerinta[octetiCititi-1]=0;
                //printf("[P]Am primit cerinta de la tastatura\n");
                write(q[1], &octetiCititi, sizeof(int));
                write(q[1], cerinta, octetiCititi);
                //printf("[P]Am dat cerinta [%s %d] mai departe la SC\n", cerinta, octetiCititi); 
                read(p[0], &octetiScrisi, sizeof(int));
                char buff[1000];
                read(p[0], buff, octetiScrisi);
                buff[octetiScrisi]=0;
                //printf("[P]Am citit cuvantul %s \n", buff);
                if (strcmp(buff, MSG_UV)==0 && conectat==0)
                {
                        conectat=1;
                        octetiScrisi+=strlen(MSG3);
                        printf("%d\n", octetiScrisi);
                        printf("%s\n%s", MSG_UV, MSG3);
                }
                else if (strcmp(buff, MSG_UV)==0 && conectat==1)
                {
                        octetiScrisi+=strlen(MSG4);
                        printf("%d\n", octetiScrisi);
                        printf("%s\n%s", MSG_UV, MSG4);
                }
                else if (strcmp(buff, MSG_UIV)==0 && conectat==1)
                {
                        octetiScrisi+=strlen(MSG4);
                        printf("%d\n", octetiScrisi);
                        printf("%s\n%s", MSG_UIV, MSG4);
                }
                else if (strcmp(buff, MSG_UIV)==0 && conectat==0)
                {
                        octetiScrisi=strlen(MSG5);
                        printf("%d\n", octetiScrisi);
                        printf("%s", MSG5);
                }
                else if (strcmp(buff, MSG_EXIT)==0 && conectat==1)
                {
                        octetiScrisi=strlen(MSG6);
                        printf("%d\n", octetiScrisi);
                        printf("%s", MSG6);
                }
                else if (strcmp(buff, MSG_EXIT)==0 && conectat==0)
                {
                        octetiScrisi=strlen(MSG7);
                        printf("%d\n", octetiScrisi);
                        printf("%s", MSG7);
                        break;
                }
                else if (strcmp(buff, MSG_DELOGARE)==0 && conectat==0)
                {
                        octetiScrisi=strlen(MSG8);
                        printf("%d\n", octetiScrisi);
                        printf("%s", MSG8);
                }
                else if (strcmp(buff, MSG_DELOGARE)==0 && conectat==1)
                {
                        conectat=0;
                        octetiScrisi=strlen(MSG9);
                        printf("%d\n", octetiScrisi);
                        printf("%s", MSG9);
                }
                else if (conectat==1)
                {
                    printf("%d\n", octetiScrisi);
                    printf("%s", buff);
                    //printf("Am afisat rezultatul primit de la SP\n");
                }
                else if (conectat==0)
                {
                    octetiScrisi=strlen(MSG2);
                    printf("%d\n", octetiScrisi);
                    printf("%s", MSG2);
                }
            }

        }
}
