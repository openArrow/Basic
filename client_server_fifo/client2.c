#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
int main()
{
 int rd, rd1;
 char  c[3]="-32",b[1];
 rd = open("fifo_server", O_WRONLY, 0);
 write(rd, c, 3);
 rd1 = open("fifo_server1", O_RDONLY, 0);
 read(rd1, b, 1);
 b[1] = '\0';
 printf("response obtained for client 2:%s\n", b);

 return 0;
}

