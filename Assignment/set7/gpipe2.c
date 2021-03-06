#include"solution.h"
void main()
{
    char str[256]="start";
    int fifo_write,fifo_read;
    while(strcmp(str,"end")!=0)
    {
        fifo_write= open("pipeA",O_WRONLY);
        if(fifo_write<0)
            printf("\nError in opening the pipe");
        else
        {
            printf("chat2: ");
            scanf("%s",str);
            write(fifo_write,str,255*sizeof(char));
            close(fifo_write);
        }
        fifo_read=open("pipeB",O_RDONLY);
        if(fifo_read<0)
            printf("\nErrorin opening write pipe");
        else
        {
            read(fifo_read,str,255*sizeof(char));
            close(fifo_read);
            printf("\n%s",str);
        }
    }
}
