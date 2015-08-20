#include <stdio.h>
#include <pthread.h>
pthread_mutex_t my_mutex1;
int i;
void *func(void *arg)
{
    int count=0;
    while(count<10000)
    {
	pthread_mutex_lock(&my_mutex1);
	count++;
	i++;
	pthread_mutex_unlock(&my_mutex1);
    }
    pthread_exit("thread 1 exits");
}
void *func1(void *msg)
{
    int count=0;
    while(count<10000)
    {
	pthread_mutex_lock(&my_mutex1);
	i++;
	count++;
 	pthread_mutex_unlock(&my_mutex1);
    }
    pthread_exit("thread 2 exits");
}

int main()
{

    pthread_t thread_id,thread_id1;
    pthread_mutex_init(&my_mutex1, NULL);
    char *msg="Hello";
    pthread_create(&thread_id ,NULL, &func, NULL);
    pthread_create(&thread_id1 ,NULL, &func1, NULL);
    pthread_join(thread_id, (void *)&msg);
    printf("%s\n",msg);
    pthread_join(thread_id1, (void *)&msg);
    printf("%s\n",msg);
    printf("%d\n", i);
    return 0;
}
