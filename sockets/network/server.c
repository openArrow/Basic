

#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    char s[4],uname[6],un[]="vivek",password[]="123456",auth[]="authenticated",paswd[8];
    char e[]="Enter your username:";
    char p[]="Enter your password:";
    int server_sockfd, client_sockfd, server_len, client_len;
    struct sockaddr_in server_address, client_address;
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl("127.0.0.1");
    server_address.sin_port = htons(9543);

    bind(server_sockfd, (struct sockaddr *)&server_address, sizeof(server_address));
    listen(server_sockfd, 5);
    

    while(1)
    {
	printf("server waiting!!\n");
	client_len = sizeof(client_address);
	sleep(5);
	client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_address, &client_len);
	read(client_sockfd, &s, 3);
	s[3] = '\0';
	printf("client requested %s\n", s);
	write(client_sockfd, &e, strlen(e));
        sleep(5);
	read(client_sockfd, &uname, 5);
	uname[5] = '\0';
	if(strcmp(uname, un))
	    write(client_sockfd, &p, strlen(p));
	else 
	    close(client_sockfd);
	read(client_sockfd, &paswd, 6);
	paswd[7] = '\0';
	if(strcmp(paswd,password))
	    write(client_sockfd, &auth, strlen(auth));

    }
    return 0;
}
