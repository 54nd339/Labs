#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main() {
    fork();
    fork();
    printf("CSE-13\n");
    return 0;
}