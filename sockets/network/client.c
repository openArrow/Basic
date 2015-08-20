#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
char g[] = "get",e[26], un[10],e1[26],pas[6],e2[15];
int sockfd,len,result;
struct sockaddr_in address;
sockfd = socket(AF_INET, SOCK_STREAM, 0);
address.sin_family = AF_INET;
address.sin_addr.s_addr = inet_addr("127.0.0.1");
address.sin_port = 9543;
//strcpy(address.sun_path, "server_socket");
result = connect(sockfd, (struct sockaddr *)&address, sizeof(address));
if(result == -1)
perror("unable to connect!!\n");
write(sockfd, &g, strlen(g));
read(sockfd, &e, 25);
printf("server:%s\n", e);
scanf("%s", un);
write(sockfd, &un, strlen(un));
sleep(4);
read(sockfd, &e1, 25);
printf("server:%s\n", e1);
scanf("%s", pas);
write(sockfd, &un, strlen(un));
read(sockfd, &e2, 10);
printf("server:%s\n", e2);
return 0;
}
