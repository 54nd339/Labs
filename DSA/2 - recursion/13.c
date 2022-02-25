#include <stdio.h>
#include <stdlib.h>
struct distance{
    int km,m;
};
struct distance *sum(struct distance *d){
    int i;
    struct distance *out=malloc(sizeof(struct distance));
    out->km=d[0].km+d[1].km;
    out->m=d[0].m+d[1].m;
    out->km=out->km+out->m/1000;
    out->m=out->m%1000;
    return out;
}
int main(){
    int i;
    struct distance *d=malloc(3*sizeof(struct distance));
    for(i=0;i<2;i++){
        printf("\nInput %d : \n",i+1);
        printf("Enter kms : ");
        scanf("%d",&((d+i)->km));
        printf("Enter ms : ");
        scanf("%d",&((d+i)->m));
    }
    *(d+3)=*sum(d);
    printf("\nDistance : %d km %d m",(d+3)->km,(d+3)->m);
    return 0;
}