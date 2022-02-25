#include <stdio.h>
  
void towerOfHanoi(int n, char from, char aux, char to){
    if (n > 0){
        towerOfHanoi(n-1, from, to, aux);
        printf("Move disk 1 from rod %c to rod %c\n", from, to);
        towerOfHanoi(n-1, aux, from, to);
    }
}
  
int main(){
    int n;
    printf("Enter No. of disks : ");
    scanf("%d", &n);
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}