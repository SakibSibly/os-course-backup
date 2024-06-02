#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int  main() {
    
    mode_t mode = S_IRUSR | S_IWUSR;
    creat("any.txt", mode);
    
    return 0;
}