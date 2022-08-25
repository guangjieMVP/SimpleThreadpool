#include <stdio.h>
#include <stdlib.h>
#include  <pthread.h>
#include <unistd.h>

void *thread_entry(void *arg)
{
    static int count = 0;
    int sec = *(int *)arg;


    printf("%d %p  %d\r\n", sec, &count, ++count);
    sleep(sec);
	
	if (sec == 2)
	{
		printf("thread1 done\r\n");
	}
	else
	{
		printf("thread2 done\r\n");
	}


    return NULL;
}

void *thread_count_time(void *arg)
{
    int i = 0;

    while (1)
    {
        sleep(1);
        printf("sec : %d\r\n", i++);    
    }
}


int main(void)
{
	
    int a = 2;
	int b = 4;

    pthread_t thread1;
    pthread_t thread2;

 	pthread_t threadtime;
	pthread_create(&threadtime, NULL, thread_count_time, NULL);

    pthread_create(&thread1, NULL, thread_entry, &a);
    pthread_create(&thread2, NULL, thread_entry, &b);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    return 0;
}

