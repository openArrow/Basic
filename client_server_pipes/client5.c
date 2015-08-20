#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main(int argc, char *argv[])
{
printf("client 5 processing the request....\n");
char b[3],buff[]="20";
char d;


read(atoi(argv[1]), b, 2);
//b[2]='\0';
//d=atoi(b[0]) + atoi(b[1]);
//sprintf(buff,"%d",d);
write(atoi(argv[2]), buff, 2);
printf("client 5 sending the result...\n");
return 0;
}

