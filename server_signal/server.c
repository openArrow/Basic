#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
	char op,t1[3],t2[3];
	int ret, fd[2], i;
	pipe(fd);
	sprintf(t1, "%d", fd[0]);
	sprintf(t2, "%d", fd[1]);
	printf("Enter the request : ");
	scanf("%c", &op);
	switch(op)
	{
		case '+' : ret=fork();

			   if (ret == 0)
			   {

				   execl("./client1", "client1", t1, t2, NULL);

			   }
			   else
			   {

				   sleep(3);
				   execl("./client4", "client4", t1, t2, NULL);
			   }
			   break;
		default:printf("wrong request");
	}
	return 0;
}
