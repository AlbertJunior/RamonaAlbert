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

void sockets()
{
    char cerinta[500];
     int conectat = 0;
    int sockp[2], child; 

    if (socketpair(AF_UNIX, SOCK_STREAM, 0, sockp) < 0) 
      { 
        perror("Err... socketpair"); 
        exit(1); 
      }
    int pid;
    if (-1==(pid=fork()))
    {
        perror("eroare la fork:");
	exit(2);
    }
    if (pid==0) //SC
    { 
          int octetiCititi;
          char buff[50000];
           close(sockp[0]);
          while (read(sockp[1], &octetiCititi, sizeof(int))!=0)
          {
               read(sockp[1], buff, octetiCititi);
               buff[octetiCititi]=0;
               //printf("[SC] am primit cerinta [%s %d]de la P\n", buff, octetiCititi);
               int sockp1[2];
               if (socketpair(AF_UNIX, SOCK_STREAM, 0, sockp1) < 0) 
                  { 
                    perror("Err... socketpair"); 
                    exit(3); 
                  }
               int pid2;
               if (-1==(pid2=fork()))
               {
                    perror("Eroare la fork:");
		    exit(4);
               }
               if (pid2!=0) // SUNT IN SC
               {
                    close(sockp1[0]);
                    write(sockp1[1], &octetiCititi, sizeof(int));
                    write(sockp1[1], buff, octetiCititi);
                   // printf("[SC] am trimis copilului cerinta[%s,%d]\n", buff, octetiCititi);
                    int i=0;
                    int nr;
                    while (1)
                    {
                        nr=read(sockp1[1], &buff[i], 1);
                        if (nr==0)
                            break;
                        i++;
                    }
                    
                    buff[i]=0;
                   // printf("[SC] Am citit din copil cuvantul [%s %d]\n", buff, i);
                    write(sockp[1], &i, sizeof(int));
                    write(sockp[1], buff, i);
                    //printf("[SC] l am dat parintelui P cuvantul %s de %d carecrere\n", buff, octetiCititi);
                    wait(NULL);
               }
               else // SUNT IN COPIL C
               {
                    close(sockp1[1]);
                    int octetiCititi1;
                   // printf("[C] S-a ajuns in copil\n");
                    read(sockp1[0], &octetiCititi1, sizeof(int));
                    read(sockp1[0], buff, octetiCititi1);
                    buff[octetiCititi]=0;
                 //   printf("[C] Am citit cerinta [%s, %d]de la P\n", buff, octetiCititi);
                    
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
			    if (fd==-1)
				{perror("eroare la open");exit(5);}
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
					               // printf("[C]Am gasit un utilizator\n");
					                break;
				                }
			                }
                            if (ok==1)
                                write(sockp1[0], MSG_UV, strlen(MSG_UV));
                            else
                                write(sockp1[0], MSG_UIV, strlen(MSG_UIV));
                            exit(1);
                            
                                            
                    }
                    else
                    if (strcmp(sir[0], "logout")==0 && j+1==1)
                    {
                        write(sockp1[0], MSG_DELOGARE, strlen(MSG_DELOGARE));
                        exit(1);
                    }
                    if (strcmp(sir[0], "quit")==0 && j+1==1)
                    {
                        write(sockp1[0], MSG_EXIT, strlen(MSG_EXIT));
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
                    dup2(sockp1[0], 2);
                    dup2(sockp1[0], 1);///////dup
                    //printf("%s\n%s", treaba[0], treaba[1]);
				    execvp(treaba[0], treaba);
				    printf("Nu ati introdus o comanda valida\n");
				    exit(1);
                    
                    //printf("[C] Am trimis lui SC un cuvantul [%s %d]\n", trimis, 5);

                   // close(p2[1]);
               }
                    
         }
           
    }
    else // parintele doar primeste ce trebyuie sa afiseze 
        {
            int octetiCititi, octetiScrisi;
            int nrOcteti;
            close(sockp[1]);
    
            while (1)
	        {
		        octetiCititi=read(0, cerinta, 500);
		        cerinta[octetiCititi-1]=0;
                //printf("[P]Am primit cerinta de la tastatura\n");
                write(sockp[0], &octetiCititi, sizeof(int));
                write(sockp[0], cerinta, octetiCititi);
                //printf("[P]Am dat cerinta [%s %d] mai departe la SC\n", cerinta, octetiCititi);
                read(sockp[0], &octetiScrisi, sizeof(int));
                //if (octetiScrisi==0)
                //    break;
                char buff[50000];
                //printf("%d\n", octetiScrisi);
                read(sockp[0], buff, octetiScrisi);
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

