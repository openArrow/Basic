#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
int i=1;
void *func(void *msg)
{
printf("in thread\n");
printf("thread id in thread:%d\n", (int)pthread_self());
printf("pid in thread:%d\n",getpid());
printf("%s\n", (char *)msg);
msg="bye";

i=0;
execl("/bin/ps", "ps", NULL);
pthread_exit((void *)msg);
}
int main()
{

pthread_t thread_id;
char *msg="Hello";
pthread_create(&thread_id ,NULL, &func, (void *)msg);
printf("thread id of main:%d\n",(int) thread_id);
printf("pid in main:%d\n",getpid());
//while(i)
//printf("hi\n");
pthread_join(thread_id,(void *)&msg);
printf("%s\n",msg);
return 0;
}
