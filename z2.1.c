#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>


int randoRange(int lower, int upper)
{

	int num;
	num = (rand() % (upper - lower +1) + lower);
	return num;

}

int main(int argc, char *argv[])
{
    const int lower = 10, upper = 99;
    int fd, repeats = 0, num[10];
    char buf[40];
    if(argc != 2){
        char filename[20];
        fprintf(stdout,"Wpisz nazwe pliku do stworzenia: ");
        fscanf(stdin, "%s", filename);
        printf("Nazwa pliku to: %s\n", filename);
        fd = open(filename, O_CREAT | O_RDWR, 0644);
        for(;repeats < 10; repeats++){
            num[repeats] = randoRange(lower, upper);
            snprintf(buf, 40, "%d", num[repeats]);
            write(fd,buf,4);
            write(fd, "\n", 2);
        }
        
        close(fd);
    }
    if(argc == 2){
        fd = open(argv[1], O_CREAT | O_RDWR, 0644);
        for(;repeats < 10; repeats++){
            num[repeats] = randoRange(lower, upper);
            printf("%d\n", num[repeats]);
            snprintf(buf, 40, "%d", num[repeats]);
            write(fd,buf,4);
            write(fd, "\n", 2);
        }
    close(fd);
    }
}