#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int csum, msum; //global value
void *runner(void *param);

int main(int argc, char *argv[])
{
    int mupper, differential;
    mupper = atoi(argv[1]); //input 5 mupper = 5

	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);

	for (int i = 0; i < 10000000; i++) 
    {
		pthread_create(&tid, &attr, runner, argv[1]);
		msum = 0;
		for (int j = 0; j <= mupper; j++) // mupper = 5 | msum = 1+2+3+4+5
        {
			msum += j;
		}
    }

	//pthread_join(tid, NULL);

    /* Q2.5: ถ้าไม่ join คำตอบที่ได้มี 2 แบบ 
       1.ลูกทำก่อนแม่ differential sum = csum - msum
       2.แม่ทำก่อนลูก differential sum = -msum
    */
	differential = csum - msum; //10 - 15 = -5

	printf("differential sum = %d\n", differential);

	return 0;
}
void *runner(void *param)
{
    int upper = atoi(param); //input 5 upper = 5
	csum = upper * 2; // csum = 5*2 = 10

	pthread_exit(0);
}