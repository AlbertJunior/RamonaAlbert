

void itoa(int a, char* buff);


void dataActualaa(char* dataActuala)
{
        char aux[100];
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        sprintf(dataActuala, "%d-%d-%d %d:%d:%d", tm.tm_year + 1900, tm.tm_mon + 1,tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
        sprintf(dataActuala, "%d-", tm.tm_year + 1900);

        strcpy(aux, dataActuala);
        if (tm.tm_mon + 1<10)
            sprintf(dataActuala, "%s0%d-", aux, tm.tm_mon + 1);
        else
            sprintf(dataActuala, "%s%d-", aux, tm.tm_mon + 1);

        strcpy(aux, dataActuala);
        if (tm.tm_mday<10)
            sprintf(dataActuala, "%s0%d ", aux, tm.tm_mday);
        else
            sprintf(dataActuala, "%s%d ", aux, tm.tm_mday);

        strcpy(aux, dataActuala);
        if (tm.tm_hour<10)
            sprintf(dataActuala, "%s0%d:", aux, tm.tm_hour);
        else
            sprintf(dataActuala, "%s%d:", aux, tm.tm_hour);

        strcpy(aux, dataActuala);
        if (tm.tm_min<10)
            sprintf(dataActuala, "%s0%d:", aux, tm.tm_min);
        else
            sprintf(dataActuala, "%s%d:", aux, tm.tm_min);

        strcpy(aux, dataActuala);
        if (tm.tm_sec<10)
            sprintf(dataActuala, "%s0%d", aux, tm.tm_sec);
        else
            sprintf(dataActuala, "%s%d", aux, tm.tm_sec);
            
                        
}




int punePeLinii(char* Rezultat)
{
        int i=0;
            int nr=0;
            char aux[100000];
            char buff[20];
            strcpy(aux, Rezultat);
            Rezultat[0]='1';
            Rezultat[1]='.';
            Rezultat[2]=0;
            strcat(Rezultat,aux);
            while (i<strlen(Rezultat))
            {
                if (Rezultat[i]==' ')
                {   nr++;
                    if (nr%2==0 && nr>0)
                    {
                        strcpy(aux, Rezultat+i+1);
                        Rezultat[i]=0;
                         itoa(nr/2+1, buff);
                        strcat(Rezultat,"\n");
                        strcat(Rezultat,buff);
                    strcat(Rezultat,".");
                        strcat(Rezultat, aux);
                    }
                }
                i++;
            }
        return nr/2;
}




struct structura
{
    char id[100];
    int uz;
} str[100];

int verificare_online(char* p)
{
        int i=0;
        for (i=1;i<=nrClienti;i++)
            if (strcmp(clienti[i].userNameAlMeu, p)==0 && clienti[i].logata==1)
                return 1;
        return 0;
}

void prelucrare(char* Rezultat, char* Rezultat2)
{
        //printf("Am intrat in fucntie\n");
        char aux[1000], aux2[1000];
        char* p;
        int nr=0;
        p=strtok(Rezultat2, " ");
        strcpy(aux, Rezultat);
            int i=0, j=0;;
        while (i<strlen(Rezultat))
        {
            i++;
          //  printf("%s\n", Rezultat);
            if (Rezultat[i]==' ') nr++;
            if (nr%2==0 && nr>0)
            {
                strcpy(aux, Rezultat+i+1);
               // printf("AUZILIAT %s\n", aux);
                Rezultat[i]=0;
                if (p!=NULL)
                {
                    //    printf("pul %s\n", p);
                      if (verificare_online(p)==1)
                        {
                                strcat(Rezultat, "+ ");i++;
                                strcat(Rezultat, aux);
                        }
                        else 
                           {
                                strcat(Rezultat, "- ");i++;
                                strcat(Rezultat, aux);
                        }  
                      p=strtok(NULL, " ");
                }
                nr=0;
                
            }
                        
        }
    printf("PRELUCARE%s\n", Rezultat);
}

int puneInStructura(char* Rezultat)
{
        int i=0;
            int nr=0;
            char aux[100];
            while (i<strlen(Rezultat))
            {
                if (Rezultat[i]==' ')
                { 
                    nr++;
                    strcpy(aux, Rezultat+i+1);
                        Rezultat[i]=0;
                        strcpy(str[nr].id, Rezultat);
                        str[nr].uz=0;
                        strcpy(Rezultat, aux);
                    i=-1;
                }
                i++;
            }
        if (i==0)
            return -1;
        strcpy(str[++nr].id, Rezultat);
        str[nr].uz=0;
      return nr;
}

void trimiteAnunt(char* Username, char* mesaj, char* dataActuala, char* userNameAlMeu)
{
        int i, ok=0;
        char Rezultat[5000];
        for (i=1;i<=nrClienti;i++)
        {
            if (strcmp(clienti[i].userNameAlMeu, Username)==0)
            {
                 ok=1;
	             introduc_notificare_altfel(Username, userNameAlMeu, dataActuala, Rezultat, mesaj);
                if (strcmp(Rezultat, "EROARE")!=0)
                    trimiteMesajul(Rezultat,  clienti[i].cl);
            }
        }
        if (ok==0)
            introduc_notificare_altfel(Username, userNameAlMeu, dataActuala, Rezultat, mesaj);
}

void TrimiteTuturor(char* NumeChat, char* userNameAlMeu, int idConv, int cl, char* mesajPrimit, thData* clienti, int nrClienti)
{
        int i, nr, j, ok;
        char Rezultat[1000], buff[20];
        itoa(idConv, buff);
     //   printf("Am Ajuns si aici dupa itoa\n");


        char dataActuala[500];
        dataActualaa(dataActuala); // creez o data actuala corecta
        extragere_iduri_conv(buff,Rezultat, userNameAlMeu);
        
        nr=puneInStructura(Rezultat); 
        
        for (i=1;i<=nr;i++)
            printf("%s\n", str[i].id);
        
        for (j=1;j<=nr;j++)
             printf("%s %d||\n", str[j].id, str[j].uz);

        printf("Numar clienti:%d\n", nrClienti);
         for (i=1;i<=nrClienti;i++)
        {
            if (clienti[i].idConv==idConv && clienti[i].cl!=cl)
            {
	             trimiteMesajul(mesajPrimit, clienti[i].cl);
                  for (j=1;j<=nr;j++)
                 {
                    
                   // printf("comparatie %s %s comparatie\n", str[j].id, clienti[i].userNameAlMeu);
                    if (strcmp(str[j].id, clienti[i].userNameAlMeu)==0)
                          {str[j].uz=1;printf("!!!%s %s %s\n",str[j].id, clienti[i].userNameAlMeu, userNameAlMeu);}
                 }
            }
        }
        printf("<3%s<3\n", userNameAlMeu);
        for (j=1;j<=nr;j++)
             if (strcmp(str[j].id, userNameAlMeu)==0)
                       str[j].uz=1;
        
        printf("NR%dNR\n", nr);
        for (j=1;j<=nr;j++)
             printf("%s %d||\n", str[j].id, str[j].uz);

        for (j=1;j<=nr;j++)
             if (str[j].uz==0)
             {
                    ok=0;
                    strcpy(Rezultat, "ALTCEVA");
                   //verific daca e online
                    for (i=1;i<=nrClienti;i++)
                      {
                    //printf("comparatie %s %s comparatie\n", str[j].id, clienti[i].userNameAlMeu);
                        if (strcmp(str[j].id, clienti[i].userNameAlMeu)==0)
                            {
                                introduc_notificare(NumeChat, str[j].id, dataActuala, Rezultat);

                                printf("!!!!!!!!%s!!!!!!!!%s!!!!!!\n", Rezultat, str[j].id);
                                if (strcmp(Rezultat, "EROARE")!=0)
                                {
                                     char aux[100];
                                     strcpy(aux, "Anunt: Ai un mesaj nou pe chatul:");
                                     strcat(aux, NumeChat);
        
                                     trimiteMesajul(aux, clienti[i].cl);
                                }
                                ok=1;                            
                            }
                       }
                    if (ok==0)
                        introduc_notificare(NumeChat, str[j].id, dataActuala, Rezultat);
             }
}
void TrimiteNotificare(int idConv, char* mesajAlternativ, char* userNameAlMeu, char* dataActuala, char* Rezultat, char* NumeChat)
{
        int i, nr, j, ok;
        char Rezultat1[1000], buff[20], aux[100];
        itoa(idConv, buff);


        extragere_iduri_conv(buff,Rezultat1, userNameAlMeu);
        
        nr=puneInStructura(Rezultat1); 
        if (nr==-1) return;
       for (j=1;j<=nr;j++)
             {
                   // printf("Cum e posibil:%s %sCUM\n", str[j].id, Rezultat);
                    if (strcmp(str[j].id, Rezultat)==0)
                     {
                           strcpy(aux, mesajAlternativ);
                           strcpy(mesajAlternativ, "Ai fost adaugat in conversatia ");
                           strcat(mesajAlternativ, NumeChat);
                    }

                    ok=0;
                   //verific daca e online
                    for (i=1;i<=nrClienti;i++)
                      {
                    //printf("comparatie %s %s comparatie\n", str[j].id, clienti[i].userNameAlMeu);
                        if (strcmp(str[j].id, clienti[i].userNameAlMeu)==0)
                            {
                           
                                introduc_notificare_diferita(mesajAlternativ, str[j].id, dataActuala, Rezultat1);
                                if (strcmp(Rezultat1, "EROARE")!=0)
                                    trimiteMesajul(mesajAlternativ, clienti[i].cl);
                                ok=1;                            
                            }
                       }
                    if (ok==0)
                        introduc_notificare_diferita(mesajAlternativ, str[j].id, dataActuala, Rezultat1);

                    if (strcmp(str[j].id, Rezultat)==0)
                     {
                           strcpy(mesajAlternativ, aux);
                    }

             }
}

void itoa(int a, char* buff)
{
        int aux=a;
        int nr=0;
        while (a!=0)
        {
            a/=10;
            nr++;
        }
        buff[nr]=0;
        while (aux!=0)
        {
            buff[nr-1]=aux%10+'0';
            aux/=10;
            nr--;
        }
        
}

void creare_conv(char* userNameAlMeu, char* Username, char* Rezultat, char* NumeC)
{
       // int b;
       // int* a=b;
        char a[100];
        adaugare_conv(NumeC, userNameAlMeu);
        id_conv(Rezultat);
        printf("%s\n", Rezultat);
        adaugare_participanti(userNameAlMeu, Rezultat, a);
        adaugare_participanti(Username, Rezultat,a);
}

int verificareData(char* mesajPrimit)
{
    if ((mesajPrimit[0]=='1' || mesajPrimit[0]=='2') && 
        (mesajPrimit[1]>='0' && mesajPrimit[1]<='9') &&
        (mesajPrimit[2]>='0' && mesajPrimit[2]<='9') &&
        (mesajPrimit[3]>='0' && mesajPrimit[3]<='9') &&
        mesajPrimit[4]=='-' &&
         (mesajPrimit[5]=='0' && (mesajPrimit[6]>='0' && mesajPrimit[6]<='9') || 
          mesajPrimit[5]=='1' && (mesajPrimit[6]>='0' && mesajPrimit[6]<='2')) &&
         mesajPrimit[7]=='-' &&
     ((mesajPrimit[8]=='0' || mesajPrimit[8]=='1'|| mesajPrimit[8]=='2')&& (mesajPrimit[9]>='0' && mesajPrimit[9]<='9') || 
       mesajPrimit[8]=='3' && (mesajPrimit[9]>='0' && mesajPrimit[9]<='1')) &&
        mesajPrimit[10]==' ' &&
     
     ((mesajPrimit[11]>='0' && mesajPrimit[11]<='1') &&  (mesajPrimit[12]>='0' && mesajPrimit[12]<='9') ||
     (mesajPrimit[11]=='2' && (mesajPrimit[12]>='0' && mesajPrimit[12]<='3'))) &&
      mesajPrimit[13]==':' &&
     ((mesajPrimit[14]>='0' && mesajPrimit[14]<='5') &&  (mesajPrimit[15]>='0' && mesajPrimit[15]<='9') ||
     (mesajPrimit[14]=='6' && mesajPrimit[15]=='0')) &&
      mesajPrimit[16]==':' &&
     ((mesajPrimit[17]>='0' && mesajPrimit[17]<='5') &&  (mesajPrimit[18]>='0' && mesajPrimit[18]<='9') ||
     (mesajPrimit[17]=='6' && mesajPrimit[18]=='0')))
        return 1;
    return 0;
   
}
void separareNume(char* Nume, char* Prenume)
{
    int i=0, ok=0;
    while (i<strlen(Nume) && Nume[i]!=' ') {i++;}

        if (Nume[i]==' ') //avem 2 dupa care sa cautam
        {
            strcpy(Prenume, Nume+i+1);     
            Nume[i]=0; 
        }
}
void aflareNume(char* Rezultat, char* Nume)
{
        char* p;
        p=(char*)malloc(sizeof(char)*1000);	
        char aux[1000];
        int nr=0;
        strcat(Nume, ".");
        p=strstr(Rezultat, Nume);
        if (p!=NULL)
        { 
                while (p[nr]>='0' && p[nr]<='9') nr++;
                nr++;
                int i=0;
                for (int k=0;k<=100;k++)
                    Nume[k]=0;
                while (p[nr]!='\n')
                {
                    Nume[i]=p[nr];
                    nr++;
                    i++;
                }
        }
        else
            Nume[0]=0;
        printf("ASASA%s\n", Nume);
        
}




int Search(char* Rezultat,char* Nume,char* Prenume,int cl, char* Username, char* userNameAlMeu, int logata)
{   
        Rezultat[0]=0;
        trimiteMesajul("Intoduceti numele, prenumele sau amandoua:", cl);     
        primesteMesajul(Nume, cl);
        int i=0, ok=0;
        while (i<strlen(Nume) && Nume[i]!=' ') {i++;}

        if (Nume[i]==' ') //avem 2 dupa care sa cautam
        {
            strcpy(Prenume, Nume+i+1);
            
            printf("%d %s\n", i, Prenume);
            Nume[i]=0;
            printf("%d %s\n", i, Nume);
            cautare_persoana2(Nume, Prenume, Rezultat);

            if (strcmp(Rezultat, "\0")==0)
                {trimiteMesajul("Nu am gasit niciun rezultat", cl);return 5;}
            else ok=1;
            
        }
        else //avem un singur nume
        {
            cautare_persoana(Nume, Rezultat);
            printf("%s\n", Rezultat);
            if (strcmp(Rezultat, "\0")==0)
                     {trimiteMesajul("Nu am gasit niciun rezultat", cl);return 5;}
           punePeLinii(Rezultat);
            Rezultat[strlen(Rezultat)-3]=0;
            trimiteMesajul("Alegeti persoana pe care o cautati", cl);
            
            trimiteMesajul(Rezultat, cl);
            primesteMesajul(Nume, cl);

            aflareNume(Rezultat, Nume);
            if (Nume[0]==0) {trimiteMesajul("Nu ati introdus ceva valid", cl);return 5;}
            int i=0;
            while (i<strlen(Nume) && Nume[i]!=' ') {i++;}
            if (Nume[i]==' ') //avem 2 dupa care sa cautam
            {
                strcpy(Prenume, Nume+i+1);
                
                printf("%d %s\n", i, Prenume);
                Nume[i]=0;
                printf("%d %s\n", i, Nume);
                cautare_persoana2(Nume, Prenume, Rezultat);
                if (strcmp(Rezultat, "\0")==0)
                     {trimiteMesajul("Nu am gasit niciun rezultat", cl);return 5;}
                   else ok=1;
            }
       } 
        if (ok==1)
        {
            printf("AJUNGE AICI?\n");
            char mesajAlternativ[500];
            //verific daca exista o prietenie si ce tip e in caz ca exista
            extragereTip(Nume, Prenume, userNameAlMeu, Rezultat);
            printf("rezultat: %s", Rezultat);
            if (logata==1)
            {
                if (Rezultat[0]==0)
                    trimiteMesajul("Nu sunteti prieteni", cl);
                else
                    {
                    strcpy(mesajAlternativ, "Sunteti prieteni de tipul: ");strcat(mesajAlternativ, Rezultat);
                    trimiteMesajul(mesajAlternativ, cl);
                    }
            }
            afisare_date_tip(Nume, Prenume, Rezultat, Username, Rezultat); // rezultat este tip

            
            if(strcmp(Username, userNameAlMeu)==0)
                {trimiteMesajul("Esti chiar tu", cl);ok=0;}
            Rezultat[strlen(Rezultat)-1]=0;
            trimiteMesajul(Rezultat, cl);
        }
        
        return ok;      
}
void nDaysAgo(char* mesajPrimit, char* Rezultat)
{

          sqlite3 *db;
       char *zErrMsg = 0;
       int rc;
       char sqlAjutor[5000];
       char *sql;//=(char*)malloc(sizeof(char)*500);
       char* data=(char*)malloc(sizeof(char)*1000);
        data[0]=0;
pthread_mutex_lock(&block);
           rc = sqlite3_open("virtualSoc.db", &db);

           if( rc ) {
              fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
              return;
           } else {
              fprintf(stderr, "Opened database successfully\n");
           }

        strcpy(sqlAjutor, "SELECT datetime( julianday(date('now'))-");
        strcat(sqlAjutor, mesajPrimit);
        strcat(sqlAjutor, ");"); 

        printf("\n%s\n", sqlAjutor);
            sql=sqlAjutor;
             rc = sqlite3_exec(db, sql, callback2, (void*) data, &zErrMsg);
            printf("%s\n", data);
            
       
           if( rc != SQLITE_OK ){
              fprintf(stderr, "SQL error: %s\n", zErrMsg);
              sqlite3_free(zErrMsg);
               
           } else {
              fprintf(stdout, "Records created successfully\n");
           }
         sqlite3_close(db);pthread_mutex_unlock(&block);
        strcpy(Rezultat, data);

}


