#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main(){
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int sumOdd = 0, sumEven = 0, n = fork(), i;
    if (n > 0) {
		for (i = 0; i < 10; i++) {
			if (a[i] % 2 == 0)
				sumEven = sumEven + a[i];
		}
		printf("Parent process \n");
		printf("Sum of even no. is %d\n", sumEven);
	}
    else {
		for (i = 0; i < 10; i++) {
			if (a[i] % 2 != 0)
				sumOdd = sumOdd + a[i];
		}
		printf("Child process \n");
		printf("Sum of odd no. is %d\n", sumOdd);
	}
	return 0;
}