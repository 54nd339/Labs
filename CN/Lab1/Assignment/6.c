#include<stdio.h>
#include<string.h>
struct pkt {
	char ch[8];
    int num1, num2;
};
struct pkt1 {
    char ch1, ch2;
};

// Extract the 2 bytes of data from pkt and store it in pkt1
int main() {
    struct pkt p;
    printf("Enter the 8 characters: ");
    scanf("%s", p.ch);
    printf("Enter the 2 numbers: ");
    scanf("%d %d", &p.num1, &p.num2);

    struct pkt1 p1;
    while (p.num1 != 0) {
        p1.ch1 = p.num1 % 10;
        p.num1 /= 10;
        p1.ch2 = p.num1 % 10;
        p.num1 /= 10;
        printf("%d %d ", p1.ch2, p1.ch1);
    }
    while (p.num2 != 0) {
        p1.ch1 = p.num2 % 10;
        p.num2 /= 10;
        p1.ch2 = p.num2 % 10;
        p.num2 /= 10;
        printf("%d %d ", p1.ch2, p1.ch1);
    }
    while (p.ch[0] != '\0') {
        p1.ch1 = p.ch[0];
        p1.ch2 = p.ch[1];
        printf("%c %c ", p1.ch2, p1.ch1);
        p.ch[0] = p.ch[2];
        p.ch[1] = p.ch[3];
        p.ch[2] = p.ch[4];
        p.ch[3] = p.ch[5];
        p.ch[4] = p.ch[6];
        p.ch[5] = p.ch[7];
        p.ch[6] = '\0';
        p.ch[7] = '\0';
    }
    
    return 0;
}