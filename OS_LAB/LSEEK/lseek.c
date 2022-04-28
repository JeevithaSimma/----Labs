#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
int main(){
	int n,f,f1;
	char buff[10];
	f=open("file.txt",O_RDWR);
	lseek(f,6,SEEK_SET);
	read(f,buff,6);
	write(1,buff,6);
}


