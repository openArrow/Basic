#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
int main(int argc[], char *argv[])
{
 int rd,res,rd1;
 char  c[3], buff[]="7";
 rd = open("fifo_procc", O_RDONLY, 0);
 rd1=open("fifo_server", O_WRONLY, 0);
 read(rd, c, 2);
 c[3] = '\0';
 res = (c[0]-'0') * (c[1]-'0');
 sprintf(buff, "%d", res);
 write(rd1, buff, 1);
 return 0;
}

