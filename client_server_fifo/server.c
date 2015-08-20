#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
int main()
{
 int  res,res1,res2,rd,rd1,rd2,ret;
 char  c[3],d[3],e[2];
 res=mkfifo("fifo_server",0777);
 res1=mkfifo("fifo_procc",0777);
 res2=mkfifo("fifo_server1",0777);
 if(res == 0 && res1 == 0)
 printf("Pipes created\n");
 rd = open("fifo_server", O_RDONLY, 0);
   rd2 = open("fifo_server1", O_WRONLY, 0);
 read(rd, c, 3);
 c[3]='\0';

 d[0]=c[1];
 d[1]=c[2];

 d[2]='\0';
 switch(c[0])
 {
   case '+':ret=fork();
	    if(ret == 0)
		{
		sleep(2);
		execl("./client4", "client4", NULL);
		}	
	     else	
		{
		rd1 = open("fifo_procc", O_WRONLY, 0);
		write(rd1, d, 2);
		read(rd, e, 1);
		e[1]='\0';
	        write(rd2, e, 1);
		}
          break;
  case '-':ret=fork(); 
            if(ret == 0)
                {
                sleep(2);
                execl("./client5", "client5", NULL);
                }       
             else       
                {
                rd1 = open("fifo_procc", O_WRONLY, 0);
                write(rd1, d, 2);
                read(rd, e, 1);
                e[1]='\0';
		 write(rd2, e, 1);
	
                }
           break;
  case '*':ret=fork(); 
            if(ret == 0)
                {
                sleep(2);
                execl("./client6", "client6", NULL);
                }       
             else       
                {
                rd1 = open("fifo_procc", O_WRONLY, 0);
                write(rd1, d, 2);
                read(rd, e, 1);
                e[1]='\0';
		 write(rd2, e, 1);

                }

		break;
  default: printf("wrong");
} 


return 0;
} 
