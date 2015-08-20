#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
    char op,t1[3],t2[3];
    int ret, fd[2], i, ret1,ret2,ret3,ret4;
    pipe(fd);
    sprintf(t1, "%d", fd[0]);
    sprintf(t2, "%d", fd[1]);
    printf("Enter y to start request : ");
    scanf("%c", &op);
    switch(op)
    {
	case 'y' : ret=fork();
		   switch(ret)
		   {
		       case -1:
			   break;
		       case 0: execl("./client1", "client1", t1, t2, NULL);
			       break;		
		       default:sleep(2);
			       ret1=fork();
			       switch(ret1)
			       {
				   case -1:
				       break;
				   case 0: execl("./client4", "client4", t1, t2, NULL);
					   break;
				   default:sleep(2);
					   ret2=fork();
					   switch(ret2)
					   {
					       case 0: execl("./client2", "client2", t1, t2, NULL);
						       break;
					       default: sleep(2);
							ret3=fork();
							switch(ret3)
							{
							    case 0:execl("./client5", "client5", t1, t2,NULL);
								   break;
							    default:	sleep(2);
									ret4=fork();
									switch(ret4)
									{
									    case 0:execl("./client3", "client3", t1, t2,NULL);
										   break;
									    default:sleep(2);
										    execl("./client6", "client6",t1,t2,NULL);
									}
							}	
					   }

			       }
		   }
		   break;
	default:printf("wrong request");
    }
    return 0;
}
