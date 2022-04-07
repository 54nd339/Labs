#include <stdio.h>
void print(int n){
    if(n%2 != 0)
        for(int i=1; i<=n; i++)
            printf("* ");
    printf("\n");
}

void star(int i){
    for(int j=1; j<=i; j++)
        printf("* ");
}

void mid(int n,int i){
    if(n%2 != 0)
        for(int j=1; j<=n-2*i; j++)
            if(j%2 == 0)
                printf("* ");
            else
                printf("  ");
    else
        for(int j=1; j<=n-2*i; j++)
            if(j <= (n-2*i)/2)
                if(j%2 == 0)
                    printf("* ");
                else
                    printf("  ");
            else
                if(j%2 == 0)
                    printf("  ");
                else
                    printf("* ");
}

int main(){
    printf("Enter no. of rows : ");
    int n; scanf("%d",&n);
    print(n);
    for(int i=n/2; i>=1; i--){
        star(i);
        mid(n,i);
        star(i);
        printf("\n");
    }
    for(int i=n%2?2:1; i<=n/2; i++){
        star(i);
        mid(n,i);
        star(i);
        printf("\n");
    }
    print(n);
    return 0;
}