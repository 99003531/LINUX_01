#include"solution.h"
void main() 
{
    int b1;
    b1 = mkfifo("pipeA",0666);
    if(b1<0)
        printf("\npipeA was not created");
    else
        printf("\npipeA created");
    int b2;
    b2 = mkfifo("pipeB",0666);
    if(b2<0)
        printf("\npipeB was not created");
    else
        printf("\npipeB is created\n");
}
