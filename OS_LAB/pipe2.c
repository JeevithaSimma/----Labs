#include <stdio.h>
#include <unistd.h>

int main(){
	int pipefd[2];
	char str1[10] = "Hello";
	char str2[10] = "World";
	char rmsg[10];
	int return_status,pid;
	return_status = pipe(pipefd);
	if(return_status == -1){
		printf("Unable to create pipe\n");
		return 1;
	}
	
	pid = fork();
	if(pid == 0){
		read(pipefd[0],rmsg,sizeof(rmsg));
		printf("Child Process - Message 1 - %s\n",rmsg);
		read(pipefd[0],rmsg,sizeof(rmsg));
		printf("Child Process - Message 2 - %s\n",rmsg);
	}
	else{
		printf("Parent Process - Writing Message1\n");
		write(pipefd[1],str1,sizeof(str1));
		printf("Parent Process - Writing Message2\n");
		write(pipefd[1],str2,sizeof(str2));
	}
	return 0;
}
