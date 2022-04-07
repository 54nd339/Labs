#include<stdio.h>
int main(){
    FILE *fp;
    char ch;
    int noc = 0, nob = 0, not = 0, non = 0;
    fp = fopen("sum.c","r");
    while((ch=fgetc(fp))!=EOF){
        noc++;
        if(ch==' ') nob++;
        if(ch=='\t') not++;
        if(ch=='\n') non++;
    }
    printf("No. of charecter : %d\n",noc);
    printf("No. of blank space : %d\n",nob);
    printf("No. of tabs : %d\n",not);
    printf("No. of new line : %d\n",non);
    fclose(fp);
    return 0;
}