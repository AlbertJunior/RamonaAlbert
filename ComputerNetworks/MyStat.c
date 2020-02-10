#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char* argv[])
{
	struct stat st;
	if (argc!=2)
	{
		printf("Dati un singur argument\n");
        exit(1);
	}
	if (-1==stat(argv[1], &st))
    {
        printf("Nu exista acest fisier in directorul curent\n");
        exit(1);
    }
	printf("Nume fisier: %s\n", argv[1]);
	printf("Dimensiune in bytes: %lld\n", (long long) st.st_size);
    printf("Numar I-node: %ld\n", (long) st.st_ino);
    printf("Mode:  %lo (octal)\n", (unsigned long) st.st_mode);
    printf("Links: %ld\n", (long) st.st_nlink);
    printf("Ownership: UID=%ld  GID=%ld\n",(long) st.st_uid, (long) st.st_gid);
    printf("Preferred I/O block size: %ld bytes\n",(long) st.st_blksize);
    printf("Blocuri alocate: %lld\n", (long long) st.st_blocks);
    

	printf("Tipul fisierului este: ");
	 switch (st.st_mode & S_IFMT) {
           case S_IFBLK:  printf("block device\n");            break;
           case S_IFCHR:  printf("character device\n");        break;
           case S_IFDIR:  printf("directory\n");               break;
           case S_IFIFO:  printf("FIFO/pipe\n");               break;
           case S_IFLNK:  printf("symlink\n");                 break;
           case S_IFREG:  printf("regular file\n");            break;
           case S_IFSOCK: printf("socket\n");                  break;
           default:       printf("unknown?\n");                break;
           }
   printf("Last status change:       %s", ctime(&st.st_ctime));
    printf("Last file access:         %s", ctime(&st.st_atime));
    printf("Last file modification:   %s", ctime(&st.st_mtime));
 



	return 0;
}
