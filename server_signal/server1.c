#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
    char op,t1[3],t2[3],t3[3],t4[3],buff[3];
    int ret, fd[2], fdd[2], i, status;
    pipe(fd);
    pipe(fdd);
    sprintf(t1, "%d", fd[0]);
    sprintf(t2, "%d", fd[1]);
    sprintf(t3, "%d", fdd[0]);
    sprintf(t4, "%d", fdd[1]);

    printf("Enter the request : ");
    scanf("%c", &op);
    switch(op)
    {
	case '+' : ret=fork();

		   if (ret == 0)
		   {
		       printf("1\n");
		       execl("./client1", "client1", t1, t2, NULL);

                   }
		   else
                    {
		       sleep(10);
		       read(fd[1], buff, 2);
		       write(fdd[1], buff, 2);
	               execl("./client4", "client4", t3, t4, NULL);
		       read(fdd[0], buff, 1);
		       write(fd[1], buff, 1);
		   }
		   
		     break;
	default:printf("wrong request");
    }
    return 0;
}
