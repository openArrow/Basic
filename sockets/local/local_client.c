#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/un.h>
#include <unistd.h>
int main()
{
int sockfd,r;
struct sockaddr_un addr;
char s='A';
sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
addr.sun_family = AF_UNIX;
strcpy(addr.sun_path, "server_socket");
r=connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
//sleep(3);
if(r == -1)
perror("OOPs!!\n");
write(sockfd, &s, 1);
read(sockfd, &s, 1);
printf("From server:%c\n",s );
close(sockfd);
return 0;
}
