#include "ex2_unbuf.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, const char * argv[]) {
    
    int *fd_input, *fd_output;
    char fileName[255] = "";
    char ch[1];
    int c, i;
    
    if (argc != 2) {
    
        fprintf(stderr, "Wrong");
        return 1;
    }
    
    fd_input = open(argv[1], O_RDONLY);
    
    if (fd_input == -1) {
        
        perror("input");
        return 1;
    }
    
    strcpy(fileName, argv[1]); // copy
    strcat(fileName, ".red"); // add
    // fileName = file name + .red
    
    fd_output = open(fileName, O_CREAT | O_TRUNC | O_WRONLY, 0644);
    if (fd_output == -1) {
           
        perror("output");
        return 2;
    }
    
    i = 0;
    while (read(fd_input, &ch, 1) == 1) {
        
        if( (i % 3) == 0) {
            
            if (write(fd_output, &ch, 1) == -1) {
                
                fprintf(stderr, "Eror");
                continue;
            }
        }
        i++;
    }
    
    close (fd_output);
    close (fd_input);
}
