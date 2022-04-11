#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main(){
    int x = 10;
    if(fork() == 0){
        printf("Child process : ");
        printf("%d\n",++x);
    }
    else{
        printf("Parent Process : ");
        printf("%d\n",--x);
    }
    return 0;
}