#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main(int argc, char *argv[])
{
printf("c1ient 3 sending request...\n");
char b[3];
char a[]="45";
write(atoi(argv[2]), a, 2);
sleep(4);
printf("client 3 Waiting for response..\n");
read(atoi(argv[1]), b, 1);
b[1]='\0';
printf("client 3 answer: %s\n", b);
return 0;
}

