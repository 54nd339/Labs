#include <stdio.h>
#include <math.h>
int main(){
    printf("Enter temp. in Celsius : ");
    float c;
    scanf("%f",&c);
    printf("Temp. in Fahrenheit : %f \n", (((c/5)*9)+32));
    return 0;
}
