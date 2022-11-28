#include <stdio.h>
#include <stdlib.h>

int mutex = 1;
int empty, full = 0, x = 0;

void producer() {
    --mutex;
    ++full;
    --empty;
	printf("Producer produces item %d\n",++x);
    ++mutex;
}

void consumer() {
    --mutex;
    --full;
    ++empty;
	printf("Consumer consumes item %d\n",x--);
    ++mutex;
}

int main() {
    printf("Enter Size of buffer : ");
    scanf("%d",&empty);
	printf("\n1. Producer\n2. Consumer\n0. Exit\n");
    
#pragma omp critical

	while(1) {
        printf("\nEnter your choice : ");
		int ch; scanf("%d", &ch);
        if (ch == 1) {
            if (mutex == 1 && empty != 0)
				producer();
            else
				printf("Buffer is full!\n");
        }
		else if (ch == 2) {
            if (mutex == 1 && full != 0)
				consumer();
            else
				printf("Buffer is empty!\n");
        }
		else if (ch == 0) exit(0);
        else
            printf("Wrong choice.");
	}
}
