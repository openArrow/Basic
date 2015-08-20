#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main(int argc, char *argv[])
{
printf("client 4 processing the request....\n");
char b[3],buff[2]="9";

int a,b1,d;


read(atoi(argv[1]), b, 2);
//b[2]='\0';
//printf("%c", b[1]);
//d=atoi(b[0])+ atoi(b[1]);
//sscanf(b,"%d%d",&a,&b1);
//d=a+b1;
//sprintf(buff,"%d",d);
//printf("%d", d);
write(atoi(argv[2]), buff, 1);
printf("client 4 sending the result...\n");
return 0;
}

