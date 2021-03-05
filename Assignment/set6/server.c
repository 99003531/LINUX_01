#include<mqueue.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

int main() {
  int rett, nbytes;
  mqd_t mqid;
  struct mq_attr attr;
  struct stat sb;
  attr.mq_msgsize = 256;
  attr.mq_maxmsg = 10;
  mqid = mq_open("/mque", O_CREAT | O_RDWR, 0666, &attr);
  if (mqid < 0) {
    perror("mq_open");
    exit(1);
  }

  char str[20] = "hello.c";
  rett = mq_send(mqid, str, 20, 5);
  if (rett < 0) {
    perror("mq_send");
    exit(2);
  }

  int maxlen = 256, prio;
  nbytes = mq_receive(mqid, (char *)&sb, 1024, &prio);
  if (nbytes < 0) {
    perror("mq_recv");
    exit(2);
  }

  printf("---File Attributes---\n");
  printf("ID of device containing file    : %ld\n", (long)sb.st_dev);
  printf("Inode number                    : %ld\n", (long)sb.st_ino);
  printf("File type                       : ");
  switch (sb.st_mode & S_IFMT) {
  case S_IFBLK:
    printf("block device\n");
    break;
  case S_IFCHR:
    printf("character device\n");
    break;
  case S_IFDIR:
    printf("directory\n");
    break;
  case S_IFIFO:
    printf("FIFO/pipe\n");
    break;
  case S_IFLNK:
    printf("symlink\n");
    break;
  case S_IFREG:
    printf("regular file\n");
    break;
  case S_IFSOCK:
    printf("socket\n");
    break;
  default:
    printf("unknown\n");
    break;
  }
  printf("Type of mode  : %lo (octal)\n", (unsigned long)sb.st_mode);
  printf("To link count   : %ld\n", (long)sb.st_nlink);
  printf("The user id   : %ld\n" , (long)sb.st_uid);
  printf("Group id     : %ld\n", (long)sb.st_gid);
  printf("blocksize    : %ld bytes\n", (long)sb.st_blksize);
  printf("file size      : %lld bytes\n", (long long)sb.st_size);
  printf("Number of blocks allocated : %lld\n", (long long)sb.st_blocks);
  printf("Last change of status              : %s", ctime(&sb.st_ctime));
  printf("Last file access by server             : %s", ctime(&sb.st_atime));
  printf("Last file modification byserver          : %s", ctime(&sb.st_mtime));
  mq_close(mqid);

  return 0;
}
