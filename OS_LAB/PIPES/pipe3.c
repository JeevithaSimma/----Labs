#include <stdio.h>
#include <unistd.h>

int main(){
	int pipefd1[2],pipefd2[2];
	int return_status1,return_status2;
	char str1[20] = "Operating";
	char str2[20] = "System";
	int pid;
	char rmsg[20];
	return_status1 = pipe(pipefd1);
	return_status2 = pipe(pipefd2);
	pid = fork();
	if(pid != 0){
		close(pipefd1[0]);
		close(pipefd2[1]);
		printf("Writing to pipe1\n");
		write(pipefd1[1],str1,sizeof(str1));
		read(pipefd2[0],rmsg,sizeof(rmsg));
		printf("Read from pipe2 Msg: %s\n",rmsg);
		
	}
	else{
		close(pipefd1[1]);
		close(pipefd2[0]);
		printf("Reading from pipe1\n");
		read(pipefd1[0],rmsg,sizeof(rmsg));
		printf("Read from pipe1 Msg: %s\n",rmsg);
		printf("Write to pipe2\n");
		write(pipefd2[1],str2,sizeof(str2));
	}
	return 0;
}

		

