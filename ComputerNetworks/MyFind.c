//SITE SO
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <time.h>

int ok=0;
char sir[100];
void info(char* nume)
{
    struct stat st1;
    char perm[10]="---------"; 
    if (-1==stat(nume, &st1))
    {
        perror("eroarea este:\n");
        printf("Nu exista acest fisier in directorul curent\n");
        exit(1);
    }
    printf("Last status change:       %s", ctime(&st1.st_ctime));
    printf("Last file access:         %s", ctime(&st1.st_atime));
    printf("Last file modification:   %s", ctime(&st1.st_mtime));    
	printf("Dimensiune in bytes: %lld\n", (long long) st1.st_size);
    if(S_IRUSR & st1.st_mode) perm[0]='r';
    if(S_IWUSR & st1.st_mode) perm[1]='w';
    if(S_IXUSR & st1.st_mode) perm[2]='x';
    if(S_IRGRP & st1.st_mode) perm[3]='r';
    if(S_IWGRP & st1.st_mode) perm[4]='w';
    if(S_IXGRP & st1.st_mode) perm[5]='x';
    if(S_IROTH & st1.st_mode) perm[6]='r';
    if(S_IWOTH & st1.st_mode) perm[7]='w';
    if(S_IXOTH & st1.st_mode) perm[8]='x'; 

    printf("Permisiunile acestuia: %s\n",perm);
}


void cautam(char* cale)
{
        char nume[100];
        DIR* dir;
        struct dirent* de;
        struct stat st;

        if (0!=stat(cale, &st))
                return;
        if (S_ISDIR(st.st_mode)!=0)
        {
                if (NULL==(dir=opendir(cale)))
                        return;
                while (NULL!=(de=readdir(dir)))
                {
                        if ((strcmp(de->d_name, ".")!=0) && (strcmp(de->d_name, "..")!=0))
                        {
                                sprintf(nume, "%s/%s", cale, de->d_name);
                                if (strstr(de->d_name, sir)!=NULL)
                                {
                                        ok=1;
                                        printf("%s\n", nume);
                                        info(nume);
                                }
                                cautam(nume);
                        }
                }
                closedir(dir);
        }
}


int main(int argc, char* argv[])
{
        strcpy(sir,argv[1]);
        if (argc<2)
                exit(1);
        cautam(".");
        if (ok==0)
            printf("Nu am gasit niciun fisier\n");
        return 0;
}





