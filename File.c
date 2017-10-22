#include<fcntl.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
	int fd,fd1;
	char fname[20];
	char buf[1024];
	system("touch manoj.txt");
	fd = open("manoj.txt", O_WRONLY);
	printf("Enter data: ");
	gets(buf);
	write(fd,buf,strlen(buf));
	close(fd);
	printf("Enter the filename to read");
	scanf("%s",fname);
	
		fd1= open(fname,O_RDONLY);
		if(fd1!=3)
		{
		printf("File does not exist \n");
		exit(0);
		}
		read(fd1,buf,sizeof(buf));
		printf("File contents are: \n");
		printf("%s\n",buf);
		
} 
