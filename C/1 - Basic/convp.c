#include <stdio.h>
#include <math.h>
int main(){
    printf("Enter amount in paisa : ");
    int p;
    scanf("%d",&p);
    printf("Amount : %d Rupees %d Paisa \n", (p/100), (p%100));
    return 0;
}
