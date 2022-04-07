#include <stdio.h>
int main(){
    int n=20, avg, sum=0, count=0;
    /*printf("Enter no. of students:");
    scanf("%d",&n);*/
    int mark[n];
    for(int i=0; i<n; i++){
        printf("Enter the grade of student %d :",(i+1));
        scanf("%d",&mark[i]);
        sum += mark[i];
        count += (mark[i]>89);
    }
    printf("Average: %f\n", (float)sum/n);
    printf("Students scoring O grade: %d\n", count);
}