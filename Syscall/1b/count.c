#include "count.h"

int lines, character, words;

void checkfile()
{
int file,nbytes;
char ch[16384];
file=open("alpha.txt",O_RDONLY);
if(file<0)
{
perror("open");
exit(1);
}
words = 0,lines = 0;
while(nbytes=read(file,ch,sizeof(ch)))
{
for(int i=0;i<nbytes;i++)
{

if (ch[i] == '\n')//To check the number of lines
lines++;

if (ch[i] == ' ' || ch[i] == '\t' || ch[i] == '\n')
words++;             //To check the number of words
}
character=nbytes;
}
close(file);           //To close the file
}

int getLines()
{
return lines;
}
int getCharacters()
{
return character;
}
int getWords()
{
return words;
}
