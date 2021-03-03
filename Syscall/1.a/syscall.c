#include<unistd.h>
#include<fcntl.h>

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int fd[2], nbytes_r, nbytes_w;
	
    //open the two files
    fd[0] = open("alpha.txt",O_RDONLY);
    fd[1] = open("beta.txt", O_WRONLY | O_CREAT , 0644); 

    //To check if any errors are there
	if(fd[0]<0)
	{
		perror("open");
		exit(1);
	}
    if(fd[1]<0)
    {
		perror("open");
		exit(2);
	}
	int maxlen=128;
	char buf[maxlen];

    //write from fd[0] to fd[1]
	nbytes_r = read(fd,buf,maxlen);
        nbytes_w = write(fd, nbytes_r, maxlen);

    //checks for errors and exit
	if(nbytes_r<0)
	{
		perror("read");
		exit(2);
	}
       if(nbytes_w<0)
	{
		perror("write");
		exit(3);
	}
    // It shows the output
	write(1,buf,nbytes_r);
        printf("written successfully, nbytes_w = %d\n",nbytes_w);
	close(fd[0]);//closing the files 
        close(fd[1]);
	return 0;
}
