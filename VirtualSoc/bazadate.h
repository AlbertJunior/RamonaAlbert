

void adaugare_conv(char* nume, char* username);

void adaugare_persoana(char* Nume, char* Prenume, char* Data_nastere, char* Parola, char* Tip, char* Username, char* buff);
void cautare_persoana(char* Nume, char* Rezultat);
void cautare_persoana2(char* Nume, char* Prenume, char* Rezultat);
void afisare_date(char* Nume, char* Prenume, char* Rezultat, char* Username);
int verificare_persoana(char* Username, char* Parola);
void id_conv(char* Rezultat);
void adaugare_participanti(char* user1, char* idConv, char* a);
void afisare_chaturi(char* userNameAlMeu, char* Rezultat);
void extragereIdChat(char* Nume, char* userNameAlMeu, char* Rezultat);
void afisare_prieteni(char* userNameAlMeu, char* Rezultat);
void adauga_replica(char* userNameAlMeu, char* masajPrimit, char* idconv, char* dataActuala);
void afisare_cerere(char* userNameAlMeu, char* username, char* tip);
void afisare_date_user(char* Username, char* Rezultat, char* Tip);
void update_prietenie(char* userNameAlMeu, char* Username);
void stergere_prietenie(char* userNameAlMeu, char* Username);

void extragereTip(char* Nume, char* Prenume, char* userNameAlMeu, char* Rezultat);
void adauga_postare(char* userNameAlMeu, char* mesajPrimit, char* Tip, char* dataActuala, char* Rezultat);

void afisare_postari(char* userNameAlMeu, char* Rezultat);
void sterge_prietenie(char* user1, char* user2, char* Rezultat);
void verificare_admin(char* buff, char* Rezultat);

void afisare_participanti(char* buff, char* Rezultat, char* userNameAlMeu);
void stergere_participant(char* NumeChat, char* Nume, char* Prenume, char* buff, char* Rezultat, char* dataActuala);
void parasire_chat(char* buff, char* userNameAlMeu);




void extragere_iduri_conv(char* buff, char* Rezultat, char* userNameAlMeu);
void introduc_notificare(char* NumeChat, char* username, char* dataActuala, char* Rezultat);
void introduc_notificare2(char* NumeChat, char* username, char* dataActuala, char* Rezultat);
void introduc_notificare_diferita(char* mesajAlternativ, char* username, char* dataActuala, char* Rezultat);
void introduc_notificare_altfel(char* Username, char* userNameAlMeu, char* dataActuala, char* Rezultat, char* mesaj);
void afiseaza_notificarile_tale(char* userNameAlMeu, char* Rezultat);
void aflare_nume(char* userNameAlMeu, char* Rezultat);


void delete_from_participanti(char* Nume);
void delete_from_conversatii(char* Nume);
void delete_from_persoane(char* Nume);




static int callback(void *NotUsed, int argc, char **argv, char **azColName);
static int callback2(void *data, int argc, char **argv, char **azColName);
static int callback3(void *data, int argc, char **argv, char **azColName);
static int callback4(void *data, int argc, char **argv, char **azColName) ;
static int callback5(void *data, int argc, char **argv, char **azColName);
static int callback6(void *data, int argc, char **argv, char **azColName);
static int callback7(void *data, int argc, char **argv, char **azColName);
static int callback8(void *data, int argc, char **argv, char **azColName);

void adauga_replica(char* userNameAlMeu, char* mesajPrimit, char* idConv, char* dataActuala)
{
        
        sqlite3 *db;
       char *zErrMsg = 0;
       int rc;
       char sqlAjutor[5000];
       char *sql;//=(char*)malloc(sizeof(char)*500);
       char* data=(char*)malloc(sizeof(char)*100000);
        data[0]=0;
pthread_mutex_lock(&block);
           rc = sqlite3_open("virtualSoc.db", &db);

           if( rc ) {
              fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
              return;
           } else {
              fprintf(stderr, "Opened database successfully\n");
           }

         strcpy(sqlAjutor, "INSERT INTO REPLICI (IDCONV, username, text, dat) VALUES( \0");
        strcat(sqlAjutor, idConv);
        strcat(sqlAjutor,",'");
        strcat(sqlAjutor, userNameAlMeu);
        strcat(sqlAjutor,"','");
        strcat(sqlAjutor, mesajPrimit);
        strcat(sqlAjutor,"','");
        strcat(sqlAjutor, dataActuala);
        strcat(sqlAjutor,"');");

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
      //  strcpy(Rezultat, data);
       // Rezultat[strlen(Rezultat)-1]=0;
}


void scoatereIDprieten(char* userNameAlMeu, char* Nume, char* Prenume, char* Rezultat)
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

        strcpy(sqlAjutor, "SELECT username2 FROM persoane JOIN prieteni ON persoane.username=prieteni.username2 WHERE username1='");
        strcat(sqlAjutor, userNameAlMeu);

        strcat(sqlAjutor, "' AND nume='");
        strcat(sqlAjutor, Nume);
        strcat(sqlAjutor, "' AND prenume='");
        strcat(sqlAjutor, Prenume);
        strcat(sqlAjutor, "';");

        printf("\n%s\n", sqlAjutor);
            sql=sqlAjutor;
             rc = sqlite3_exec(db, sql, callback2, (void*) data, &zErrMsg);
            printf("%s\n", data);
            
        if (data[0]==0)
            
       { strcpy(sqlAjutor, "SELECT username1 FROM persoane JOIN prieteni ON persoane.username=prieteni.username1 WHERE username2='");
        strcat(sqlAjutor, userNameAlMeu);

        strcat(sqlAjutor, "' AND nume='");
        strcat(sqlAjutor, Nume);
        strcat(sqlAjutor, "' AND prenume='");
        strcat(sqlAjutor, Prenume);
        strcat(sqlAjutor, "';");

        printf("\n%s\n", sqlAjutor);
            sql=sqlAjutor;
             rc = sqlite3_exec(db, sql, callback2, (void*) data, &zErrMsg);
            printf("%s\n", data);
            }
           if( rc != SQLITE_OK ){
              fprintf(stderr, "SQL error: %s\n", zErrMsg);
              sqlite3_free(zErrMsg);
               
           } else {
              fprintf(stdout, "Records created successfully\n");
           }
         sqlite3_close(db);pthread_mutex_unlock(&block);
        strcpy(Rezultat, data);
        Rezultat[strlen(Rezultat)-1]=0;
}

void extragereTip(char* Nume, char* Prenume, char* userNameAlMeu, char* Rezultat)
{
    sqlite3 *db;
       char *zErrMsg = 0;
       int rc;
       char sqlAjutor[5000];
       char *sql=(char*)malloc(sizeof(char)*5000);
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

        strcpy(sqlAjutor, "SELECT prieteni.tip FROM persoane JOIN prieteni ON persoane.username=prieteni.username2 WHERE prieteni.validare=1 AND username1='");
        strcat(sqlAjutor, userNameAlMeu);
        
        strcat(sqlAjutor, "' AND nume='");
        strcat(sqlAjutor, Nume);
        strcat(sqlAjutor, "' AND prenume='");
        strcat(sqlAjutor, Prenume);

        strcat(sqlAjutor, "' UNION SELECT prieteni.tip FROM persoane JOIN prieteni ON persoane.username=prieteni.username1 WHERE prieteni.validare=1 AND username2='");
        strcat(sqlAjutor, userNameAlMeu);
        strcat(sqlAjutor, "' AND nume='");
        strcat(sqlAjutor, Nume);
        strcat(sqlAjutor, "' AND prenume='");
        strcat(sqlAjutor, Prenume);
        strcat(sqlAjutor, "';"); 

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
        if (userNameAlMeu[0]==0)
            strcpy(Rezultat, "departat ");
        else
        strcpy(Rezultat, data);
}

void afisare_prieteni(char* userNameAlMeu, char* Rezultat)
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

        strcpy(sqlAjutor, "SELECT nume, prenume, username FROM persoane JOIN prieteni ON persoane.username=prieteni.username2 WHERE prieteni.validare=1 AND username1='");
        strcat(sqlAjutor, userNameAlMeu);
        strcat(sqlAjutor, "' UNION SELECT nume, prenume, username FROM persoane JOIN prieteni ON persoane.username=prieteni.username1 WHERE prieteni.validare=1 AND username2='");
        strcat(sqlAjutor, userNameAlMeu);
        strcat(sqlAjutor, "' ORDER BY username ;"); 

        printf("\n%s\n", sqlAjutor);
            sql=sqlAjutor;
             rc = sqlite3_exec(db, sql, callback8, (void*) data, &zErrMsg);
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
void afisare_prieteni_id(char* userNameAlMeu, char* Rezultat)
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

        strcpy(sqlAjutor, "SELECT username FROM persoane JOIN prieteni ON persoane.username=prieteni.username2 WHERE prieteni.validare=1 AND username1='");
        strcat(sqlAjutor, userNameAlMeu);
        strcat(sqlAjutor, "' UNION SELECT username FROM persoane JOIN prieteni ON persoane.username=prieteni.username1 WHERE prieteni.validare=1 AND username2='");
        strcat(sqlAjutor, userNameAlMeu);
        strcat(sqlAjutor, "' ORDER BY username;"); 

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

void afisare_chaturi(char* userNameAlMeu, char* Rezultat)
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

        strcpy(sqlAjutor, "SELECT nume FROM participanti NATURAL JOIN conversatii WHERE idpers='");
        strcat(sqlAjutor, userNameAlMeu);
        strcat(sqlAjutor, "';");

        printf("\n%s\n", sqlAjutor);
            sql=sqlAjutor;
             rc = sqlite3_exec(db, sql, callback7, (void*) data, &zErrMsg);
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
void extragereIdChat(char* Nume, char* userNameAlMeu, char* Rezultat)
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

        strcpy(sqlAjutor, "SELECT idconv FROM participanti NATURAL JOIN conversatii WHERE idpers='");
        strcat(sqlAjutor, userNameAlMeu);
        strcat(sqlAjutor, "' AND nume='");
        strcat(sqlAjutor, Nume);
        strcat(sqlAjutor, "';");

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

void adaugare_participanti(char* user1, char* idConv, char* a)
{
     sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char sqlAjutor[5000];
   char *sql;//=(char*)malloc(sizeof(char)*500);
pthread_mutex_lock(&block);
       rc = sqlite3_open("virtualSoc.db", &db);

       if( rc ) {
          fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
          return;
       } else {
          fprintf(stderr, "Opened database successfully\n");
       }

        strcpy(sqlAjutor, "INSERT INTO participanti (IDCONV, IDPERS) VALUES('");
        strcat(sqlAjutor, idConv);
        strcat(sqlAjutor,"','");
        strcat(sqlAjutor, user1);
        strcat(sqlAjutor, "');");

        printf("\n%s\n", sqlAjutor);
        sql=sqlAjutor;
         rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   
       if( rc != SQLITE_OK ){
          fprintf(stderr, "SQL error: %s\n", zErrMsg);
          sqlite3_free(zErrMsg);
            a[0]=1;
       } else {
          fprintf(stdout, "Records created successfully\n");
       }

     sqlite3_close(db);pthread_mutex_unlock(&block);
}
void id_conv(char* Rezultat)
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

           if( rc ){
              fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
              return;
           } else {
              fprintf(stderr, "Opened database successfully\n");
           }

        strcpy(sqlAjutor, "SELECT MAX(IDCONV) FROM CONVERSATII;");

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
        Rezultat[strlen(Rezultat)-1]=0;
}

void adaugare_conv(char* nume, char* username)
{
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char sqlAjutor[5000];
   char *sql;//=(char*)malloc(sizeof(char)*500);
pthread_mutex_lock(&block);
       rc = sqlite3_open("virtualSoc.db", &db);

       if( rc ) {
          fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
          return;
       } else {
          fprintf(stderr, "Opened database successfully\n");
       }

        strcpy(sqlAjutor, "INSERT INTO conversatii (NUME, admin) VALUES('");
        strcat(sqlAjutor, nume);
        strcat(sqlAjutor, "','");

        strcat(sqlAjutor, username);
        strcat(sqlAjutor, "');");
        
        printf("\n%s\n", sqlAjutor);
        sql=sqlAjutor;
         rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   
       if( rc != SQLITE_OK ){
          fprintf(stderr, "SQL error: %s\n", zErrMsg);
          sqlite3_free(zErrMsg);
       } else {
          fprintf(stdout, "Records created successfully\n");
       }
     sqlite3_close(db);pthread_mutex_unlock(&block);
}

void afisare_date_user(char* Username, char* Rezultat, char* Tip)
{
    sqlite3 *db;
       char *zErrMsg = 0;
       int rc;
       char sqlAjutor[5000];
       char *sql;//=(char*)malloc(sizeof(char)*500);
       char* data=(char*)malloc(sizeof(char)*10000);
        data[0]=0;
pthread_mutex_lock(&block);
           rc = sqlite3_open("virtualSoc.db", &db);

           if( rc ) {
              fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
              return;
           } else {
              fprintf(stderr, "Opened database successfully\n");
           }
        if (strcmp(Tip, "prieten")==0)
           strcpy(sqlAjutor, "SELECT nume, prenume, data_nastere FROM persoane WHERE (username='");
        else if (strcmp(Tip, "apropiat")==0)
           strcpy(sqlAjutor, "SELECT nume, prenume, data_nastere, username FROM persoane WHERE (username='");
        else if (strcmp(Tip, "departat")==0)
                strcpy(sqlAjutor, "SELECT nume, prenume FROM persoane WHERE (username='");


        strcat(sqlAjutor, Username);
        
        strcat(sqlAjutor, "');");

        printf("\n%s\n", sqlAjutor);
            sql=sqlAjutor;
             rc = sqlite3_exec(db, sql, callback3, (void*) data, &zErrMsg);
            printf("%s\n", data);
            
       
           if( rc != SQLITE_OK ){
              fprintf(stderr, "SQL error: %s\n", zErrMsg);
              sqlite3_free(zErrMsg);
               
           } else {
              fprintf(stdout, "Records created successfully\n");
           }
         sqlite3_close(db);pthread_mutex_unlock(&block);
        strcpy(Rezultat, data);
        if (data[0]==0)
        {
            strcpy(Rezultat, "EROARE");
            return;
        }
       // char* p=strstr(Rezultat, "USERNAME");
     //   int i=0;
    //    while (p[11+i]!='\0' && p[11+i]!=' ') {Username[i]=p[11+i];i++;}
     //   Username[i-1]=0;
}

void stergere_participant(char* NumeChat, char* Nume, char* Prenume, char* buff, char* Rezultat, char* dataActuala)
{
        sqlite3 *db;
        int i;
       char *zErrMsg = 0;
       int rc;
       char sqlAjutor[5000];
       char *sql;//=(char*)malloc(sizeof(char)*500);
       char* data=(char*)malloc(sizeof(char)*10000);
        data[0]=0;
           rc = sqlite3_open("virtualSoc.db", &db);

           if( rc ) {
              fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
              return;
           } else {
              fprintf(stderr, "Opened database successfully\n");
           }
           data[0]=0;
        strcpy(sqlAjutor, "SELECT username FROM persoane WHERE (nume='");

        strcat(sqlAjutor, Nume);
        strcat(sqlAjutor, "' AND prenume='");
        strcat(sqlAjutor, Prenume);
        strcat(sqlAjutor, "')OR (prenume='");
        strcat(sqlAjutor, Nume);
        strcat(sqlAjutor, "' AND nume='");
        strcat(sqlAjutor, Prenume);
        
        strcat(sqlAjutor, "');");

        printf("\n%s\n", sqlAjutor);
            sql=sqlAjutor;
             rc = sqlite3_exec(db, sql, callback4, (void*) data, &zErrMsg);
            printf("%s|\n", data);
            
       
           if( rc != SQLITE_OK ){
              fprintf(stderr, "SQL error: %s\n", zErrMsg);
              sqlite3_free(zErrMsg);
               
           } else {
              fprintf(stdout, "Records created successfully\n");
           }
       data[strlen(data)-2]=0;

         for (i=1;i<=nrClienti;i++)
         {
                printf("la primul for %s %sceva\n", clienti[i].userNameAlMeu, data);
                 if (strcmp(clienti[i].userNameAlMeu, data)==0 && clienti[i].idConv==atoi(buff))
                        {
                              strcpy(Rezultat, "EROARE1");      
                              sqlite3_close(db);
                              return;
                        }
          }
            int ok=0;

          for (i=1;i<=nrClienti;i++)
         {
                if (strcmp(clienti[i].userNameAlMeu, data)==0)
                {
                    introduc_notificare2(NumeChat, data, dataActuala, Rezultat);
                    if (strcmp(Rezultat, "EROARE")!=0)
                    {
                        strcpy(Rezultat, "Ai fost dat afara din chatul: ");
                        strcat(Rezultat, NumeChat);
                        trimiteMesajul(Rezultat, clienti[i].cl);
                        ok=1;
                        break;
                    }
                } 
        }
        if (ok==0)
             introduc_notificare2(NumeChat, data, dataActuala, Rezultat);

        strcpy(sqlAjutor, "DELETE FROM participanti WHERE idpers='");
        strcat(sqlAjutor, data);
        strcat(sqlAjutor, "' AND idconv='");
         strcat(sqlAjutor, buff);
        strcat(sqlAjutor, "';");

        printf("\n%s\n", sqlAjutor);
            sql=sqlAjutor;
             rc = sqlite3_exec(db, sql, callback3, 0, &zErrMsg);
            printf("%s\n", data);
            
       
           if( rc != SQLITE_OK ){
              fprintf(stderr, "SQL error: %s\n", zErrMsg);
              sqlite3_free(zErrMsg);
               
           } else {
              fprintf(stdout, "Records created successfully\n");
           }

    sqlite3_close(db);
}
void afisare_date_tip(char* Nume, char* Prenume, char* Rezultat, char* Username, char* tip)
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
        if (strcmp(tip, "departat ")==0 || tip[0]==0)
             strcpy(sqlAjutor, "SELECT nume, prenume FROM persoane WHERE (nume='");
        else if (strcmp(tip, "prieten ")==0)
             strcpy(sqlAjutor, "SELECT nume, prenume, data_nastere FROM persoane WHERE (nume='");
        else strcpy(sqlAjutor, "SELECT nume, prenume, data_nastere, username FROM persoane WHERE (nume='");
        strcat(sqlAjutor, Nume);
        strcat(sqlAjutor, "' AND prenume='");
        strcat(sqlAjutor, Prenume);
        strcat(sqlAjutor, "')OR (prenume='");
        strcat(sqlAjutor, Nume);
        strcat(sqlAjutor, "' AND nume='");
        strcat(sqlAjutor, Prenume);
        
        strcat(sqlAjutor, "');");

        printf("\n%s\n", sqlAjutor);
            sql=sqlAjutor;
             rc = sqlite3_exec(db, sql, callback3, (void*) data, &zErrMsg);
            printf("%s\n", data);
            
       
           if( rc != SQLITE_OK ){
              fprintf(stderr, "SQL error: %s\n", zErrMsg);
              sqlite3_free(zErrMsg);
               
           } else {
              fprintf(stdout, "Records created successfully\n");
           }
        




        strcpy(Rezultat, data);
        if (data[0]==0)
        {
            strcpy(Rezultat, "EROARE");sqlite3_close(db);pthread_mutex_unlock(&block);
            return;
        }


        data[0]=0;
        strcpy(sqlAjutor, "SELECT username FROM persoane WHERE (nume='");

        strcat(sqlAjutor, Nume);
        strcat(sqlAjutor, "' AND prenume='");
        strcat(sqlAjutor, Prenume);
        strcat(sqlAjutor, "')OR (prenume='");
        strcat(sqlAjutor, Nume);
        strcat(sqlAjutor, "' AND nume='");
        strcat(sqlAjutor, Prenume);
        
        strcat(sqlAjutor, "');");

        printf("\n%s\n", sqlAjutor);
            sql=sqlAjutor;
             rc = sqlite3_exec(db, sql, callback4, (void*) data, &zErrMsg);
            printf("%s\n", data);
            
       
           if( rc != SQLITE_OK ){
              fprintf(stderr, "SQL error: %s\n", zErrMsg);
              sqlite3_free(zErrMsg);
               
           } else {
              fprintf(stdout, "Records created successfully\n");
           }
    data[strlen(data)-2]=0;

    strcpy(Username, data);

    sqlite3_close(db);pthread_mutex_unlock(&block);
    
}

void afisare_date(char* Nume, char* Prenume, char* Rezultat, char* Username)
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

        strcpy(sqlAjutor, "SELECT * FROM persoane WHERE (nume='");
        strcat(sqlAjutor, Nume);
        strcat(sqlAjutor, "' AND prenume='");
        strcat(sqlAjutor, Prenume);
        strcat(sqlAjutor, "')OR (prenume='");
        strcat(sqlAjutor, Nume);
        strcat(sqlAjutor, "' AND nume='");
        strcat(sqlAjutor, Prenume);
        
        strcat(sqlAjutor, "');");

        printf("\n%s\n", sqlAjutor);
            sql=sqlAjutor;
             rc = sqlite3_exec(db, sql, callback3, (void*) data, &zErrMsg);
            printf("%s\n", data);
            
       
           if( rc != SQLITE_OK ){
              fprintf(stderr, "SQL error: %s\n", zErrMsg);
              sqlite3_free(zErrMsg);
               
           } else {
              fprintf(stdout, "Records created successfully\n");
           }
         sqlite3_close(db);pthread_mutex_unlock(&block);
        strcpy(Rezultat, data);
        if (data[0]==0)
        {
            strcpy(Rezultat, "EROARE");
            return;
        }
        char* p=strstr(Rezultat, "USERNAME");
        int i=0;
        while (p[11+i]!='\0' && p[11+i]!=' ') {Username[i]=p[11+i];i++;}
        Username[i-1]=0;
}

void adauga_prietenie(char* user1, char* user2, char* tip, char* Rezultat)
{
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char sqlAjutor[5000];
   char *sql;//=(char*)malloc(sizeof(char)*500);
pthread_mutex_lock(&block);      
       rc = sqlite3_open("virtualSoc.db", &db);

       if( rc ) {
          fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
          return;
       } else {
          fprintf(stderr, "Opened database successfully\n");
       }

        strcpy(sqlAjutor, "INSERT INTO prieteni (USERNAME1, USERNAME2, TIP, validare) VALUES( '\0");
        strcat(sqlAjutor, user1);
        strcat(sqlAjutor,"','");
        strcat(sqlAjutor, user2);
        strcat(sqlAjutor,"','");
        strcat(sqlAjutor, tip);
        strcat(sqlAjutor, "',0);");

        printf("\n%s\n", sqlAjutor);
        sql=sqlAjutor;
         rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    
   
       if( rc != SQLITE_OK ){
          fprintf(stderr, "SQL error: %s\n", zErrMsg);
          sqlite3_free(zErrMsg);
            strcpy(Rezultat,"Deja sunteti prieteni sau deja ati trimis cerere de prietenie. Consultati comanda 'friends'");
       } else {
          fprintf(stdout, "Records created successfully\n");
       }
     sqlite3_close(db);pthread_mutex_unlock(&block);
}


void sterge_prietenie(char* user1, char* user2, char* Rezultat)
{
    sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char sqlAjutor[5000];
   char *sql;//=(char*)malloc(sizeof(char)*500);
char* data=(char*)malloc(sizeof(char)*10000);

pthread_mutex_lock(&block);   
       rc = sqlite3_open("virtualSoc.db", &db);

       if( rc ) {
          fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
          return;
       } else {
          fprintf(stderr, "Opened database successfully\n");
       }

        strcpy(sqlAjutor, "DELETE FROM prieteni WHERE (username1= '\0");
        strcat(sqlAjutor, user1);
        strcat(sqlAjutor,"' AND username2='");
        strcat(sqlAjutor, user2);
        strcat(sqlAjutor,"') OR (username2='");
        strcat(sqlAjutor, user1);
        strcat(sqlAjutor,"' AND username1='");
        strcat(sqlAjutor, user2);
        strcat(sqlAjutor,"');");    


        printf("\n%s\n", sqlAjutor);
        sql=sqlAjutor;
         rc = sqlite3_exec(db, sql, callback5, data, &zErrMsg);
    
   
       if( rc != SQLITE_OK ){
          fprintf(stderr, "SQL error: %s\n", zErrMsg);
          sqlite3_free(zErrMsg);
       } else {
          fprintf(stdout, "Records created successfully\n");
       }
       strcpy(Rezultat, data);
     sqlite3_close(db);pthread_mutex_unlock(&block);
}


void adaugare_persoana(char* Nume, char* Prenume, char* Data_nastere, char* Parola, char* Tip, char* Username, char* buff)
{
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char sqlAjutor[5000];
   char *sql;//=(char*)malloc(sizeof(char)*500);
pthread_mutex_lock(&block);
       rc = sqlite3_open("virtualSoc.db", &db);

       if( rc ) {
          fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
          return;
       } else {
          fprintf(stderr, "Opened database successfully\n");
       }

        strcpy(sqlAjutor, "INSERT INTO persoane (USERNAME, NUME, PRENUME, DATA_NASTERE, PAROLA, TIP) VALUES( '\0");
        strcat(sqlAjutor, Username);
        strcat(sqlAjutor,"','");
        strcat(sqlAjutor, Nume);
        strcat(sqlAjutor,"','");
        strcat(sqlAjutor, Prenume);
        strcat(sqlAjutor, "','");
        strcat(sqlAjutor, Data_nastere);
        strcat(sqlAjutor, "','");
        strcat(sqlAjutor, Parola);
        strcat(sqlAjutor, "','");
        strcat(sqlAjutor, Tip);
        strcat(sqlAjutor, "');");

        printf("\n%s\n", sqlAjutor);
        sql=sqlAjutor;
         rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   
       if( rc != SQLITE_OK ){
          fprintf(stderr, "SQL error: %s\n", zErrMsg);
          sqlite3_free(zErrMsg);
            strcpy(buff, "EROARE");
       } else {
          fprintf(stdout, "Records created successfully\n");
       }
     sqlite3_close(db);pthread_mutex_unlock(&block);
}


int verificare_persoana(char* Username, char* Parola)
{
     sqlite3 *db;
       char *zErrMsg = 0;
       int rc;
       char sqlAjutor[5000];
       char *sql;//=(char*)malloc(sizeof(char)*500);
       char* data=(char*)malloc(sizeof(char)*100);
data[0]=0;
pthread_mutex_lock(&block);  
         rc = sqlite3_open("virtualSoc.db", &db);

           if( rc ) {
              fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
              return 0;
           } else {
              fprintf(stderr, "Opened database successfully\n");
           }

          strcpy(sqlAjutor, "SELECT parola FROM persoane WHERE username='");
        strcat(sqlAjutor, Username);
        strcat(sqlAjutor, "';");

        printf("\n%s\n", sqlAjutor);
        sql=sqlAjutor;
         rc = sqlite3_exec(db, sql, callback2, (void*) data, &zErrMsg);
        printf("%s\n", data);
        
        data[strlen(data)-1]=0;
       if( rc != SQLITE_OK ){
          fprintf(stderr, "SQL error: %s\n", zErrMsg);
          sqlite3_free(zErrMsg);
       } else {
          fprintf(stdout, "Records created successfully\n");
       }
     sqlite3_close(db);pthread_mutex_unlock(&block);
       printf("%s.\n%s.\n", data, Parola);
    if (strcmp(data, Parola)==0)
            {  printf("AM DA\n");return 1;}
     printf("AM NU\n");
    return 0;

}


void cautare_persoana(char* Nume, char* Rezultat)
{
    sqlite3 *db;
       char *zErrMsg = 0;
       int rc;
       char sqlAjutor[5000];
       char *sql;//=(char*)malloc(sizeof(char)*500);
       char* data=(char*)malloc(sizeof(char)*100);
data[0]=0;
pthread_mutex_lock(&block); 
          rc = sqlite3_open("virtualSoc.db", &db);

           if( rc ) {
              fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
              return;
           } else {
              fprintf(stderr, "Opened database successfully\n");
           }

        strcpy(sqlAjutor, "SELECT nume, prenume FROM persoane WHERE upper(nume)=upper('");
        strcat(sqlAjutor, Nume);
        strcat(sqlAjutor, "') OR upper(prenume)=upper('");
        strcat(sqlAjutor, Nume);
        strcat(sqlAjutor, "');");

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

void cautare_persoana2(char* Nume, char* Prenume, char* Rezultat)
{
    sqlite3 *db;
       char *zErrMsg = 0;
       int rc;
       char sqlAjutor[5000];
       char *sql;//=(char*)malloc(sizeof(char)*500);
       char* data=(char*)malloc(sizeof(char)*100);
data[0]=0;
pthread_mutex_lock(&block);
           rc = sqlite3_open("virtualSoc.db", &db);

           if( rc ) {
              fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
              return;
           } else {
              fprintf(stderr, "Opened database successfully\n");
           }

        strcpy(sqlAjutor, "SELECT nume, prenume FROM persoane WHERE (upper(nume)=upper('");
        strcat(sqlAjutor, Nume);
        strcat(sqlAjutor, "') AND upper(prenume)=upper('");
        strcat(sqlAjutor, Prenume);
        strcat(sqlAjutor, "'))OR (upper(prenume)=upper('");
        strcat(sqlAjutor, Nume);
        strcat(sqlAjutor, "') AND upper(nume)=upper('");
        strcat(sqlAjutor, Prenume);
        
        strcat(sqlAjutor, "'));");

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
void extragereNume(char* userNameAlMeu, char* Rezultat)
{
        sqlite3 *db;
       char *zErrMsg = 0;
       int rc;
       char sqlAjutor[5000];
       char *sql;//=(char*)malloc(sizeof(char)*500);
       char* data=(char*)malloc(sizeof(char)*100);
data[0]=0;
pthread_mutex_lock(&block);
           rc = sqlite3_open("virtualSoc.db", &db);

           if( rc ) {
              fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
              return;
           } else {
              fprintf(stderr, "Opened database successfully\n");
           }

        strcpy(sqlAjutor, "SELECT nume, prenume FROM persoane WHERE username='");
        strcat(sqlAjutor, userNameAlMeu);
        
        strcat(sqlAjutor, "';");

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

void afiseazaReplici(char* idconv, char* data1, char* Rezultat)
{
       
    sqlite3 *db;
       char *zErrMsg = 0;
       int rc;
       char sqlAjutor[5000];
       char *sql;//=(char*)malloc(sizeof(char)*500);
       char* data=(char*)malloc(sizeof(char)*10000);
data[0]=0;
pthread_mutex_lock(&block);
           rc = sqlite3_open("virtualSoc.db", &db);

           if( rc ) {
              fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
              return;
           } else {
              fprintf(stderr, "Opened database successfully\n");
           }

        strcpy(sqlAjutor, "SELECT dat, text FROM Replici WHERE dat>'");
        strcat(sqlAjutor, data1);
        
        strcat(sqlAjutor, "' AND idconv='");
        strcat(sqlAjutor, idconv);
        strcat(sqlAjutor, "';");

        printf("\n%s\n", sqlAjutor);
            sql=sqlAjutor;
             rc = sqlite3_exec(db, sql, callback4, (void*) data, &zErrMsg);
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
void afisare_cerere(char* userNameAlMeu, char* username, char* tip)
{
        sqlite3 *db;
       char *zErrMsg = 0;
       int rc;
       char sqlAjutor[5000];
       char *sql;//=(char*)malloc(sizeof(char)*500);
       char* data=(char*)malloc(sizeof(char)*10000);
data[0]=0;
pthread_mutex_lock(&block);
           rc = sqlite3_open("virtualSoc.db", &db);

           if( rc ) {
              fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
              return;
           } else {
              fprintf(stderr, "Opened database successfully\n");
           }

        strcpy(sqlAjutor, "SELECT username1 FROM PRIETENI WHERE validare=0 AND username2='");
        strcat(sqlAjutor, userNameAlMeu);
        
        strcat(sqlAjutor, "';");

        printf("\n%s\n", sqlAjutor);
            sql=sqlAjutor;
             rc = sqlite3_exec(db, sql, callback5, (void*) data, &zErrMsg);
            printf("%s\n", data);
            
       
           if( rc != SQLITE_OK ){
              fprintf(stderr, "SQL error: %s\n", zErrMsg);
              sqlite3_free(zErrMsg);
           } else {
              fprintf(stdout, "Records created successfully\n");
           }
        printf("%s\n", data);
        strcpy(username, data);

        data[0]=0;
        strcpy(sqlAjutor, "SELECT tip FROM PRIETENI WHERE validare=0 AND username2='");
        strcat(sqlAjutor, userNameAlMeu);
        
        strcat(sqlAjutor, "';");

        printf("\n%s\n", sqlAjutor);
            sql=sqlAjutor;
             rc = sqlite3_exec(db, sql, callback5, (void*) data, &zErrMsg);
            printf("%s\n", data);
            
       
           if( rc != SQLITE_OK ){
              fprintf(stderr, "SQL error: %s\n", zErrMsg);
              sqlite3_free(zErrMsg);
           } else {
              fprintf(stdout, "Records created successfully\n");
           }
        strcpy(tip, data);
         sqlite3_close(db);pthread_mutex_unlock(&block);
}

void stergere_prietenie(char* userNameAlMeu, char* Username)
{
      sqlite3 *db;
       char *zErrMsg = 0;
       int rc;
       char sqlAjutor[5000];
       char *sql;//=(char*)malloc(sizeof(char)*500);
       char* data=(char*)malloc(sizeof(char)*10000);
data[0]=0;
pthread_mutex_lock(&block);
           rc = sqlite3_open("virtualSoc.db", &db);

           if( rc ) {
              fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
              return;
           } else {
              fprintf(stderr, "Opened database successfully\n");
           }

        strcpy(sqlAjutor, "DELETE FROM PRIETENI WHERE username2='");
        strcat(sqlAjutor, userNameAlMeu);
        strcat(sqlAjutor, "'AND username1='");
        strcat(sqlAjutor, Username);
        strcat(sqlAjutor, "';");

        printf("\n%s\n", sqlAjutor);
            sql=sqlAjutor;
             rc = sqlite3_exec(db, sql, callback5, (void*) data, &zErrMsg);
            printf("%s\n", data);
            
       
           if( rc != SQLITE_OK ){
              fprintf(stderr, "SQL error: %s\n", zErrMsg);
              sqlite3_free(zErrMsg);
           } else {
              fprintf(stdout, "Records created successfully\n");
           }
         sqlite3_close(db);pthread_mutex_unlock(&block);
}

void update_prietenie(char* userNameAlMeu, char* Username)
{
         sqlite3 *db;
       char *zErrMsg = 0;
       int rc;
       char sqlAjutor[5000];
       char *sql;//=(char*)malloc(sizeof(char)*500);
       char* data=(char*)malloc(sizeof(char)*10000);
data[0]=0;
pthread_mutex_lock(&block);
           rc = sqlite3_open("virtualSoc.db", &db);

           if( rc ) {
              fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
              return;
           } else {
              fprintf(stderr, "Opened database successfully\n");
           }

        strcpy(sqlAjutor, "UPDATE PRIETENI SET validare=1 WHERE username2='");
        strcat(sqlAjutor, userNameAlMeu);
        strcat(sqlAjutor, "'AND username1='");
        strcat(sqlAjutor, Username);
        strcat(sqlAjutor, "';");

        printf("\n%s\n", sqlAjutor);
            sql=sqlAjutor;
             rc = sqlite3_exec(db, sql, callback5, (void*) data, &zErrMsg);
            printf("%s\n", data);
            
       
           if( rc != SQLITE_OK ){
              fprintf(stderr, "SQL error: %s\n", zErrMsg);
              sqlite3_free(zErrMsg);
           } else {
              fprintf(stdout, "Records created successfully\n");
           }
         sqlite3_close(db);pthread_mutex_unlock(&block);
}
void adauga_postare(char* userNameAlMeu, char* mesajPrimit, char* Tip, char* dataActuala, char* Rezultat)
{
    sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char sqlAjutor[5000];
   char *sql;//=(char*)malloc(sizeof(char)*500);
pthread_mutex_lock(&block);
       rc = sqlite3_open("virtualSoc.db", &db);

       if( rc ) {
          fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
          return;
       } else {
          fprintf(stderr, "Opened database successfully\n");
       }

        strcpy(sqlAjutor, "INSERT INTO POSTARI (username, text, data, TIP) VALUES( '\0");
        strcat(sqlAjutor, userNameAlMeu);
        strcat(sqlAjutor,"','");
        strcat(sqlAjutor, mesajPrimit);
        strcat(sqlAjutor,"','");
        strcat(sqlAjutor, dataActuala);
        strcat(sqlAjutor,"','");
        strcat(sqlAjutor, Tip);
        strcat(sqlAjutor, "');");

        printf("\n%s\n", sqlAjutor);
        sql=sqlAjutor;
         rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    
   
       if( rc != SQLITE_OK ){
          fprintf(stderr, "SQL error: %s\n", zErrMsg);
          sqlite3_free(zErrMsg);
            strcpy(Rezultat,"Nu este permis spamul");
       } else {
          fprintf(stdout, "Records created successfully\n");
       }
     sqlite3_close(db);pthread_mutex_unlock(&block);
}

void afisari_postari_publice(char* Username, char* Rezultat)
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

        strcpy(sqlAjutor, "SELECT postari.data, persoane.nume, persoane.prenume, postari.text FROM postari JOIN persoane ON postari.username=persoane.username WHERE postari.username='");
        strcat(sqlAjutor, Username);
        strcat(sqlAjutor, "' AND postari.tip='public' ORDER BY postari.data;");
        

        printf("\n%s\n", sqlAjutor);
            sql=sqlAjutor;
             rc = sqlite3_exec(db, sql, callback6, (void*) data, &zErrMsg);
            printf("%s\n", data);
            
        data[strlen(data)-2]=0;
           if( rc != SQLITE_OK ){
              fprintf(stderr, "SQL error: %s\n", zErrMsg);
              sqlite3_free(zErrMsg);
               
           } else {
              fprintf(stdout, "Records created successfully\n");
           }
         sqlite3_close(db);pthread_mutex_unlock(&block);
        strcpy(Rezultat, data);
}
void afisare_postari(char* userNameAlMeu, char* Rezultat)
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

        strcpy(sqlAjutor, "SELECT postari.data, persoane.nume, persoane.prenume, postari.text FROM postari JOIN persoane ON postari.username=persoane.username JOIN prieteni ON prieteni.username1=postari.username WHERE username2='");
        strcat(sqlAjutor, userNameAlMeu);
        strcat(sqlAjutor, "' AND validare='1' AND (postari.tip='public' OR postari.tip=prieteni.tip ");
        strcat(sqlAjutor, ")UNION ");
        
         strcat(sqlAjutor, "SELECT postari.data, persoane.nume, persoane.prenume,  postari.text FROM postari JOIN persoane ON postari.username=persoane.username JOIN prieteni ON prieteni.username2=postari.username WHERE username1='");
        strcat(sqlAjutor, userNameAlMeu);
        strcat(sqlAjutor, "' AND validare='1' AND (postari.tip='public' OR postari.tip=prieteni.tip ");
        strcat(sqlAjutor, ") ORDER BY postari.data;");

        printf("\n%s\n", sqlAjutor);
            sql=sqlAjutor;
             rc = sqlite3_exec(db, sql, callback6, (void*) data, &zErrMsg);
            printf("%s\n", data);
            
        data[strlen(data)-2]=0;
           if( rc != SQLITE_OK ){
              fprintf(stderr, "SQL error: %s\n", zErrMsg);
              sqlite3_free(zErrMsg);
               
           } else {
              fprintf(stdout, "Records created successfully\n");
           }
         sqlite3_close(db);pthread_mutex_unlock(&block);
        strcpy(Rezultat, data);
}

void verificare_admin(char* buff, char* Rezultat)
{
      sqlite3 *db;
       char *zErrMsg = 0;
       int rc;
       char sqlAjutor[5000];
       char *sql;//=(char*)malloc(sizeof(char)*500);
       char* data=(char*)malloc(sizeof(char)*10000);
data[0]=0;
pthread_mutex_lock(&block);
           rc = sqlite3_open("virtualSoc.db", &db);

           if( rc ) {
              fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
              return;
           } else {
              fprintf(stderr, "Opened database successfully\n");
           }

        strcpy(sqlAjutor, "SELECT admin FROM conversatii WHERE idconv='");
        strcat(sqlAjutor, buff);
        strcat(sqlAjutor, "';");

        printf("\n%s\n", sqlAjutor);
            sql=sqlAjutor;
             rc = sqlite3_exec(db, sql, callback5, (void*) data, &zErrMsg);
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

void afisare_participanti(char* buff, char* Rezultat, char* userNameAlMeu)
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

        
        strcpy(sqlAjutor, "SELECT persoane.nume, prenume FROM persoane JOIN participanti ON persoane.username=participanti.idpers WHERE participanti.idconv='");
        strcat(sqlAjutor, buff);
        strcat(sqlAjutor, "' AND idpers <> '");
        strcat(sqlAjutor, userNameAlMeu);
        strcat(sqlAjutor, "';"); 

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

void parasire_chat(char* buff, char* userNameAlMeu)
{
      sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char sqlAjutor[5000];
   char *sql;//=(char*)malloc(sizeof(char)*500);
pthread_mutex_lock(&block);
       rc = sqlite3_open("virtualSoc.db", &db);

       if( rc ) {
          fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
          return;
       } else {
          fprintf(stderr, "Opened database successfully\n");
       }

        strcpy(sqlAjutor, "DELETE FROM participanti WHERE idconv= '\0");
        strcat(sqlAjutor, buff);
        strcat(sqlAjutor,"' AND idpers='");
        strcat(sqlAjutor, userNameAlMeu);
        strcat(sqlAjutor,"';");    


        printf("\n%s\n", sqlAjutor);
        sql=sqlAjutor;
         rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    
   
       if( rc != SQLITE_OK ){
          fprintf(stderr, "SQL error: %s\n", zErrMsg);
          sqlite3_free(zErrMsg);
       } else {
          fprintf(stdout, "Records created successfully\n");
       }
     sqlite3_close(db);pthread_mutex_unlock(&block);
}

int esteAdmin(char* userNameAlMeu)
{
     sqlite3 *db;
       char *zErrMsg = 0;
       int rc;
       char sqlAjutor[5000];
       char *sql;//=(char*)malloc(sizeof(char)*500);
       char* data=(char*)malloc(sizeof(char)*10000);
data[0]=0;
pthread_mutex_lock(&block);
           rc = sqlite3_open("virtualSoc.db", &db);

           if( rc ) {
              fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
              return;
           } else {
              fprintf(stderr, "Opened database successfully\n");
           }

        strcpy(sqlAjutor, "SELECT * FROM persoane WHERE username='");
        strcat(sqlAjutor, userNameAlMeu);
        
        strcat(sqlAjutor, "' AND tip='admin';");

        printf("\n%s\n", sqlAjutor);
            sql=sqlAjutor;
             rc = sqlite3_exec(db, sql, callback4, (void*) data, &zErrMsg);
            printf("%s\n", data);
            
       
           if( rc != SQLITE_OK ){
              fprintf(stderr, "SQL error: %s\n", zErrMsg);
              sqlite3_free(zErrMsg);
           } else {
              fprintf(stdout, "Records created successfully\n");
           }
         sqlite3_close(db);pthread_mutex_unlock(&block);
        if (strlen(data)>0) return 1;
        return 0;
}

void users(char* Rezultat)
{
          sqlite3 *db;
       char *zErrMsg = 0;
       int rc;
       char sqlAjutor[5000];
       char *sql;//=(char*)malloc(sizeof(char)*500);
       char* data=(char*)malloc(sizeof(char)*10000);
data[0]=0;
pthread_mutex_lock(&block);
           rc = sqlite3_open("virtualSoc.db", &db);

           if( rc ) {
              fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
              return;
           } else {
              fprintf(stderr, "Opened database successfully\n");
           }

        strcpy(sqlAjutor, "SELECT username FROM persoane;");

        printf("\n%s\n", sqlAjutor);
            sql=sqlAjutor;
             rc = sqlite3_exec(db, sql, callback7, (void*) data, &zErrMsg);
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

void afisare_membrii_id(char* buff, char* Rezultat)
{
            sqlite3 *db;
       char *zErrMsg = 0;
       int rc;
       char sqlAjutor[5000];
       char *sql;//=(char*)malloc(sizeof(char)*500);
       char* data=(char*)malloc(sizeof(char)*10000);
data[0]=0;
pthread_mutex_lock(&block);
           rc = sqlite3_open("virtualSoc.db", &db);

           if( rc ) {
              fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
              return;
           } else {
              fprintf(stderr, "Opened database successfully\n");
           }

        strcpy(sqlAjutor, "SELECT idpers FROM participanti WHERE idconv='");
        strcat(sqlAjutor, buff);    
        strcat(sqlAjutor, "';");


        printf("\n%s\n", sqlAjutor);
            sql=sqlAjutor;
             rc = sqlite3_exec(db, sql, callback4, (void*) data, &zErrMsg);
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
void afisare_mesaje_id(char* buff, char* Rezultat)
{
            sqlite3 *db;
       char *zErrMsg = 0;
       int rc;
       char sqlAjutor[5000];
       char *sql;//=(char*)malloc(sizeof(char)*500);
       char* data=(char*)malloc(sizeof(char)*10000);
data[0]=0;
pthread_mutex_lock(&block);
           rc = sqlite3_open("virtualSoc.db", &db);

           if( rc ) {
              fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
              return;
           } else {
              fprintf(stderr, "Opened database successfully\n");
           }

        strcpy(sqlAjutor, "SELECT dat, '['||username||'] ' ||text FROM replici WHERE idconv='");
        strcat(sqlAjutor, buff);    
        strcat(sqlAjutor, "';");


        printf("\n%s\n", sqlAjutor);
            sql=sqlAjutor;
             rc = sqlite3_exec(db, sql, callback4, (void*) data, &zErrMsg);
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

void conversatii(char* Rezultat)
{
        sqlite3 *db;
       char *zErrMsg = 0;
       int rc;
       char sqlAjutor[5000];
       char *sql;//=(char*)malloc(sizeof(char)*500);
       char* data=(char*)malloc(sizeof(char)*10000);
data[0]=0;
pthread_mutex_lock(&block);
           rc = sqlite3_open("virtualSoc.db", &db);

           if( rc ) {
              fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
              return;
           } else {
              fprintf(stderr, "Opened database successfully\n");
           }

        strcpy(sqlAjutor, "SELECT  'CONV['||idconv||']-[' || nume || '] ADMIN:['|| admin || ']' FROM conversatii;");

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


void afisare_mesaje(char* Nume, char* Rezultat)
{
     sqlite3 *db;
       char *zErrMsg = 0;
       int rc;
       char sqlAjutor[5000];
       char *sql;//=(char*)malloc(sizeof(char)*500);
       char* data=(char*)malloc(sizeof(char)*10000);
data[0]=0;
pthread_mutex_lock(&block);
           rc = sqlite3_open("virtualSoc.db", &db);

           if( rc ) {
              fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
              return;
           } else {
              fprintf(stderr, "Opened database successfully\n");
           }

        strcpy(sqlAjutor, "SELECT  'CONV['||idconv||']', dat, text FROM Replici WHERE username='");
        strcat(sqlAjutor, Nume);
        strcat(sqlAjutor, "' ORDER BY dat;");

        printf("\n%s\n", sqlAjutor);
            sql=sqlAjutor;
             rc = sqlite3_exec(db, sql, callback6, (void*) data, &zErrMsg);
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

void afiseaza_toate_postarile(char* Nume, char* Rezultat)
{
        sqlite3 *db;
       char *zErrMsg = 0;
       int rc;
       char sqlAjutor[5000];
       char *sql;//=(char*)malloc(sizeof(char)*500);
       char* data=(char*)malloc(sizeof(char)*10000);
data[0]=0;
pthread_mutex_lock(&block);
           rc = sqlite3_open("virtualSoc.db", &db);

           if( rc ) {
              fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
              return;
           } else {
              fprintf(stderr, "Opened database successfully\n");
           }

        strcpy(sqlAjutor, "SELECT data, '['|| tip || ']', text FROM postari WHERE username='");
        strcat(sqlAjutor, Nume);
        strcat(sqlAjutor, "' ORDER BY data;");

        printf("\n%s\n", sqlAjutor);
            sql=sqlAjutor;
             rc = sqlite3_exec(db, sql, callback4, (void*) data, &zErrMsg);
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
void schimbareDenumireConv(char* denumire, char* buff)
{
          sqlite3 *db;
       char *zErrMsg = 0;
       int rc;
       char sqlAjutor[5000];
       char *sql;//=(char*)malloc(sizeof(char)*500);
       char* data=(char*)malloc(sizeof(char)*10000);
data[0]=0;
pthread_mutex_lock(&block);
           rc = sqlite3_open("virtualSoc.db", &db);

           if( rc ) {
              fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
              return;
           } else {
              fprintf(stderr, "Opened database successfully\n");
           }

        strcpy(sqlAjutor, "UPDATE conversatii SET nume='");
        strcat(sqlAjutor, denumire);
        
        strcat(sqlAjutor, "' WHERE idconv='");
        strcat(sqlAjutor, buff);
        strcat(sqlAjutor, "';");

        printf("\n%s\n", sqlAjutor);
            sql=sqlAjutor;
             rc = sqlite3_exec(db, sql, callback5, (void*) data, &zErrMsg);
            printf("%s\n", data);
            
       
           if( rc != SQLITE_OK ){
              fprintf(stderr, "SQL error: %s\n", zErrMsg);
              sqlite3_free(zErrMsg);
           } else {
              fprintf(stdout, "Records created successfully\n");
           }
         sqlite3_close(db);pthread_mutex_unlock(&block);
}

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}
static int callback2(void *data, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
        strcat(data, argv[i]);
        strcat(data, " ");
   }
   printf("\n");
   return 0;
}
static int callback8(void *data, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
        if (strcmp(azColName[i], "NUME")==0 || strcmp(azColName[i], "PRENUME")==0) {
            strcat(data, argv[i]);
             strcat(data, " ");
        }
   }
   printf("\n");
   return 0;
}
static int callback6(void *data, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
        strcat(data, argv[i]);
        strcat(data, " ");
   }
     strcat(data, "\n");
   return 0;
}
static int callback7(void *data, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
        strcat(data, argv[i]);
        strcat(data, "  ");
   }

   return 0;
}
static int callback5(void *data, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
        strcpy(data, argv[i]);
   }
   printf("\n");
   return 0;
}
static int callback4(void *data, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
        strcat(data, argv[i]);
        strcat(data, " ");
   }
    strcat(data, "\n");
   printf("\n");
   return 0;
}
static int callback3(void *data, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
        strcat(data, azColName[i]);
         strcat(data, " = ");
        strcat(data, argv[i]);
        strcat(data, "\n"); 
            
   }
   printf("\n");
   return 0;
}



