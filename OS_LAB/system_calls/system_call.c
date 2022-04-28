#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
int main(void){
	int fd;
	char buf1[12] = "hello world\n"; 
	fd = open("file1.txt",O_RDWR|O_CREAT,0777);
	write(fd,buf1,strlen(buf1));
	close(fd);
	return 0;
}	
