#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main(int argc, char *argv[])
{
printf("client 2 sending request...\n");
char b[3];
char a[]="45";
write(atoi(argv[2]), a, 2);
sleep(5);
printf("client 2 Waiting for response..\n");
read(atoi(argv[1]), b, 2);
b[2]='\0';
printf("client 2 answer: %s\n", b);
return 0;
}

 
