#include<stdio.h>
#include<string.h>
struct pkt{
	char ch1, ch2[2], ch3;
};

void number_aggregate(struct pkt p) {
	printf("Enter a 4 digit number: ");
	int number; scanf("%d", &number);

	int c = 1;
	while(number != 0 && c <= 4) {
		int r = number % 10;
		if(c == 1)
			p.ch1 = r;
		if(c == 2)
			p.ch2[0] = r;
		if(c == 3)
			p.ch2[1] = r;
		if(c == 4)
			p.ch3 = r;
		c++; number /= 10;
	}
	printf("The aggregated characters are: %d %d %d %d\n", p.ch3, p.ch2[1], p.ch2[0], p.ch1);
	printf("The original number: %d%d%d%d\n", p.ch3, p.ch2[1], p.ch2[0], p.ch1);
}
int main() {
	struct pkt p;
	number_aggregate(p);
}