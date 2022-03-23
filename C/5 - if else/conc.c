#include <stdio.h>
int main(){
    printf("Enter 1. if object is at infinity\n");
    printf("Enter 2. if object is beyond C\n");
    printf("Enter 3. if object is at C\n");
    printf("Enter 4. if object is between C and F\n");
    printf("Enter 5. if object is at F\n");
    printf("Enter your choice : ");
    int ch; scanf("%d",&ch);
    if (ch==1){
        printf("Position of image: At the focus F\n");
        printf("Size of image: Highly Dimnished\n");
        printf("Nature of image: Real and Inverted\n");
    }
    if (ch==2){
        printf("Position of image: Between F and C\n");
        printf("Size of image: Dimnished\n");
        printf("Nature of image: Real and Inverted\n");
    }
    if (ch==3){
        printf("Position of image: At C\n");
        printf("Size of image: same size\n");
        printf("Nature of image: Real and Inverted\n");
    }
    if (ch==4){
        printf("Position of image: Beyond C\n");
        printf("Size of image: Enlarged\n");
        printf("Nature of image: Real and Inverted\n");
    }
    if (ch==5){
        printf("Position of image: At infinity\n");
        printf("Size of image: Highly Enlarged\n");
        printf("Nature of image: Real and Inverted\n");
    }
    return 0;
}