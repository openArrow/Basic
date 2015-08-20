#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include "semaphore.c"
int main()
{
 int rd, rd1;
 sem_id = semget((key_t)1234,1,0777|IPC_CREAT);

 char  c[3]="-32",b[1];
  semaphore_p();
 rd = open("fifo_server", O_WRONLY, 0);
 write(rd, c, 3);
 rd1 = open("fifo_server1", O_RDONLY, 0);
 read(rd1, b, 1);
 b[1] = '\0';
 printf("response obtained for client 2:%s\n", b);
  semaphore_v();

 return 0;
}

