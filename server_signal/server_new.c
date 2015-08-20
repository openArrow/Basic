#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
	char op,t1[3],t2[3],t3[3],t4[3];
	int ret, fd[2], fd1[2],i,ret1,ret2;
	pipe(fd);
	pipe(fd1);
	sprintf(t1, "%d", fd[0]);
	sprintf(t2, "%d", fd[1]);
	 sprintf(t3, "%d", fd1[0]);
        sprintf(t4, "%d", fd1[1]);
	printf("Enter y to start the server : ");
	scanf("%c", &op);
	switch(op)
	{
		case 'y' :ret1=fork();
			  if(ret1==0)
			{
			  ret=fork();
                           if (ret == 0)
			   {

				   execl("./client1", "client1", t1, t2, NULL);

			   }
			   else
			   {

				   sleep(3);
				   execl("./client4", "client4", t1, t2, NULL);
			   }
			}
			else
			{
                         ret2=fork();
                           if (ret2 == 0)
                           {

                                   execl("./client2", "client2", t3, t4, NULL);

                           }
                           else
                           {

                                   sleep(3);
                                   execl("./client5", "client5", t3, t4, NULL);
                           }

			} 
			  break;
		default:printf("wrong request");
	}
	return 0;
}
