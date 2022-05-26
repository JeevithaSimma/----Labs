#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(){
	int pipefds[2];
	int return_status;
	char str1[30];
	char str2[30];
	char rmsg[30];
	return_status = pipe(pipefds);
	if(return_status == -1){
		printf("Unable to create pipe\n");
		return -1;
	}
	printf("Enter Message-1 : ");
	fgets(str1,30,stdin);
	printf("Writing And Reading Message - 1\n");
	write(pipefds[1],str1,sizeof(str1));
	read(pipefds[0],rmsg,sizeof(rmsg));
	printf("Message-1  =   %s\n",rmsg);
	
	printf("Enter Message-2 : ");
	fgets(str2,30,stdin);
	printf("Writing and Reading Message - 2\n");
	write(pipefds[1],str2,sizeof(str2));
	read(pipefds[0],rmsg,sizeof(rmsg));
	printf("Message-2  =   %s\n",rmsg);
	return 0;
}

	
	
	

