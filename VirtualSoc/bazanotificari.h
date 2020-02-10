
void extragere_iduri_conv(char* buff, char* Rezultat, char* userNameAlMeu)
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

        
        strcpy(sqlAjutor, "SELECT idpers FROM participanti WHERE participanti.idconv='");
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
         sqlite3_close(db);
        strcpy(Rezultat, data);
        Rezultat[strlen(Rezultat)-1]=0;
        pthread_mutex_unlock(&block);
}

void introduc_notificare(char* NumeChat, char* username, char* dataActuala, char* Rezultat)
{
            sqlite3 *db;
       char *zErrMsg = 0;
       int rc;
       char sqlAjutor[5000];
       char *sql;//=(char*)malloc(sizeof(char)*500);
       char* data=(char*)malloc(sizeof(char)*100000);
        data[0]=0;
           rc = sqlite3_open("virtualSoc.db", &db);

           if( rc ) {
              fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
              return;
           } else {
              fprintf(stderr, "Opened database successfully\n");
           }

         strcpy(sqlAjutor, "INSERT INTO notificari (username, text, dat) VALUES('");
        strcat(sqlAjutor, username);
        strcat(sqlAjutor,"','Ai primit un mesaj nou pe chat-ul ");
        strcat(sqlAjutor, NumeChat);
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
               strcpy(Rezultat, "EROARE");
               
           } else {
              fprintf(stdout, "Records created successfully\n");
           }
         sqlite3_close(db);
}


void introduc_notificare2(char* NumeChat, char* username, char* dataActuala, char* Rezultat)
{
            sqlite3 *db;
       char *zErrMsg = 0;
       int rc;
       char sqlAjutor[5000];
       char *sql;//=(char*)malloc(sizeof(char)*500);
       char* data=(char*)malloc(sizeof(char)*100000);
        data[0]=0;

           rc = sqlite3_open("virtualSoc.db", &db);

           if( rc ) {
              fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
              return;
           } else {
              fprintf(stderr, "Opened database successfully\n");
           }

         strcpy(sqlAjutor, "INSERT INTO notificari (username, text, dat) VALUES('");
        strcat(sqlAjutor, username);
        strcat(sqlAjutor,"','Ai fost dat afara din chat-ul: ");
        strcat(sqlAjutor, NumeChat);
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
               strcpy(Rezultat, "EROARE");
               
           } else {
              fprintf(stdout, "Records created successfully\n");
           }
         sqlite3_close(db);
}

void introduc_notificare_diferita(char* mesajAlternativ, char* username, char* dataActuala, char* Rezultat)
{
              sqlite3 *db;
       char *zErrMsg = 0;
       int rc;
       char sqlAjutor[5000];
       char *sql;//=(char*)malloc(sizeof(char)*500);
       char* data=(char*)malloc(sizeof(char)*100000);
        data[0]=0;
           rc = sqlite3_open("virtualSoc.db", &db);

           if( rc ) {
              fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
              return;
           } else {
              fprintf(stderr, "Opened database successfully\n");
           }

         strcpy(sqlAjutor, "INSERT INTO notificari (username, text, dat) VALUES('");
        strcat(sqlAjutor, username);
        strcat(sqlAjutor,"','");
        strcat(sqlAjutor, mesajAlternativ);
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
               strcpy(Rezultat, "EROARE");
               
           } else {
              fprintf(stdout, "Records created successfully\n");
           }
         sqlite3_close(db);
}

void introduc_notificare_altfel(char* Username, char* userNameAlMeu, char* dataActuala, char* Rezultat, char* mesaj)
{
              sqlite3 *db;
       char *zErrMsg = 0;
       int rc;
       char sqlAjutor[5000];
       char *sql;//=(char*)malloc(sizeof(char)*500);
       char* data=(char*)malloc(sizeof(char)*100000);
        data[0]=0;

           rc = sqlite3_open("virtualSoc.db", &db);

           if( rc ) {
              fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
              return;
           } else {
              fprintf(stderr, "Opened database successfully\n");
           }
          strcpy(sqlAjutor, "SELECT nume, prenume FROM persoane WHERE username='");
        strcat(sqlAjutor, userNameAlMeu);
        strcat(sqlAjutor,"';");

           printf("\n%s\n", sqlAjutor);
            sql=sqlAjutor;
             rc = sqlite3_exec(db, sql, callback2, (void*) data, &zErrMsg);
            printf("%s\n", data);
            
        strcpy(Rezultat, mesaj);
        strcat(Rezultat, data);
        
         strcpy(sqlAjutor, "INSERT INTO notificari (username, text, dat) VALUES('");
        strcat(sqlAjutor, Username);
        strcat(sqlAjutor,"','");
        strcat(sqlAjutor, mesaj);
        strcat(sqlAjutor," ");
        strcat(sqlAjutor, data);
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
               strcpy(Rezultat, "EROARE");
               
           } else {
              fprintf(stdout, "Records created successfully\n");
           }
         sqlite3_close(db);
        
}
void aflare_nume(char* userNameAlMeu, char* Rezultat)
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
          strcpy(sqlAjutor, "SELECT nume, prenume FROM persoane WHERE username='");
        strcat(sqlAjutor, userNameAlMeu);
        strcat(sqlAjutor,"';");

           printf("\n%s\n", sqlAjutor);
            sql=sqlAjutor;
             rc = sqlite3_exec(db, sql, callback2, (void*) data, &zErrMsg);
            printf("%s\n", data);
        strcpy(Rezultat, data);
        sqlite3_close(db);pthread_mutex_unlock(&block);
}
void afiseaza_notificarile_tale(char* userNameAlMeu, char* Rezultat)
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
          strcpy(sqlAjutor, "SELECT dat, text FROM notificari WHERE username='");
        strcat(sqlAjutor, userNameAlMeu);
        strcat(sqlAjutor,"';");

           printf("\n%s\n", sqlAjutor);
            sql=sqlAjutor;
             rc = sqlite3_exec(db, sql, callback6, (void*) data, &zErrMsg);
            printf("%s\n", data);
        strcpy(Rezultat, data);


        strcpy(sqlAjutor, "DELETE FROM notificari WHERE username='");
        strcat(sqlAjutor, userNameAlMeu);
        strcat(sqlAjutor,"';");

           printf("\n%s\n", sqlAjutor);
            sql=sqlAjutor;
             rc = sqlite3_exec(db, sql, callback2, 0, &zErrMsg);
        sqlite3_close(db);pthread_mutex_unlock(&block);
}




void delete_from_participanti(char* Nume)
{
         sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char sqlAjutor[5000];
   char *sql;//=(char*)malloc(sizeof(char)*500);
       rc = sqlite3_open("virtualSoc.db", &db);
pthread_mutex_lock(&block);
       if( rc ) {
          fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
          return;
       } else {
          fprintf(stderr, "Opened database successfully\n");
       }

        strcpy(sqlAjutor, "DELETE FROM participanti WHERE idpers= '");
        strcat(sqlAjutor, Nume);
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
void delete_from_conversatii(char* Nume)
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

        strcpy(sqlAjutor, "DELETE FROM conversatii WHERE admin ='");
        strcat(sqlAjutor, Nume);
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
void delete_from_persoane(char* Nume)
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

        strcpy(sqlAjutor, "DELETE FROM persoane WHERE username= '");
        strcat(sqlAjutor, Nume);
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






