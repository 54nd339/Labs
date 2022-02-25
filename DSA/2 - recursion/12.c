#include <stdio.h>
struct distance{
    int km, m;
};
void sum(struct distance d[2]){
    int i;
    struct distance out;
    out.km=d[0].km+d[1].km;
    out.m=d[0].m+d[1].m;
    out.km=out.km+out.m/1000;
    out.m=out.m%1000;
    printf("\nDistance : %d km %d m",out.km,out.m);
}
int main(){
    int i;
    struct distance d[2];
    for(i=0;i<2;i++){
        printf("\nInput %d : \n",i+1);
        printf("Enter kms : ");
        scanf("%d",&d[i].km);
        printf("Enter ms : ");
        scanf("%d",&d[i].m);
    }
    sum(d);
    return 0;
}