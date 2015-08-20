#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/un.h>
#include <unistd.h>
int main()
{
    int server_sockfd,client_sockfd, client_len,i=1;
    struct sockaddr_un server_add,client_add;
    char s;
    unlink("server_socket");
    server_sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
    server_add.sun_family = AF_UNIX;
    strcpy(server_add.sun_path, "server_socket");
    
    bind(server_sockfd, (struct sockaddr *)&server_add, sizeof(server_add) );
    listen(server_sockfd, 5);
    while(1)
    {
	printf("server waiting...\n");
	
	client_len = sizeof(client_add);
        //sleep(5);
	client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_add, &client_len); 
         
	read(client_sockfd, &s, 1);

     //   printf("client wrote:", s);
	s++;
        write(client_sockfd, &s, 1);
	close(client_sockfd);
       i=0;
    }
    return 0;
}
