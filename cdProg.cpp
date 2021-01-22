#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc , char**argv)
{
    if(argc < 3){
        return 1 ;
    }
    int fdSrcFile = open(argv[1] , O_RDONLY) ;
    if(fdSrcFile == -1)
        return 2 ;
    int fdDesFile = open(argv[2] , O_CREAT | O_WRONLY , S_IRUSR) ;
    if(fdDesFile == -1){
        return 3 ;
    }

    char buffer[2] ;
    ssize_t charcounter = 0 ;
    while((charcounter = read(fdSrcFile , buffer , sizeof(buffer))) != 0)
    {
        write(fdDesFile , buffer , charcounter) ;
    }

    return 0;
}

