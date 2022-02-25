//write data.in file in gedit before running
#include <stdio.h>
int main(){
    FILE *fp;
    int a[10],i,sum=0;
    fp=fopen("data.in","r");
    for(i=0;i<10;i++){
        fscanf(fp,"%d",&a[i]);
        sum+=a[i];
    }
    printf("Sum = %d",sum);
    for(i=9;i>=0;i--) //i= 1 less than the no. of charecter there in data.in
        printf("\n %d ",a[i]);
    fclose(fp);
    return 0;    
}
