#include <stdio.h>
#include <pthread.h>
int i=1;
void *func(void *msg)
{
printf("in thread\n");
printf("%s\n", (char *)msg);
msg="bye";

i=0;
pthread_exit((void *)msg);
}
int main()
{

pthread_t thread_id;
char *msg="Hello";
pthread_create(&thread_id ,NULL, &func, (void *)msg);
printf("%d\n",(int) thread_id);
while(i)
printf("hi\n");
pthread_join(thread_id,(void *)&msg);
printf("%s\n",msg);
return 0;
}
