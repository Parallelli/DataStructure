#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>

int main(int argc, char* argv[])
{
    DIR *mydir;
    struct dirent *myfile;
    struct stat mystat;
    mydir = opendir(argv[1]);
    char buf[1024];
    while((myfile = readdir(mydir))!=NULL)
    {
        sprintf(buf,"%s/%s",argv[1],myfile->d_name);
        stat(buf, &mystat);
        printf("%lld ", mystat.st_size);
        printf("%s\n", myfile->d_name);
    }
    closedir(mydir);
    return 0;
}
