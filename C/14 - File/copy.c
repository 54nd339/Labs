#include<stdio.h>
int main(){
    FILE *fs, *ft;
    char ch;
    fs = fopen("sum.c","r");
    if(fs == NULL){
        printf("Can't open file");
        return 0;
    }
    ft = fopen("sumt.c","w");
    if(ft == NULL){
        printf("Can't open file");
        fclose(fs);
        return 0;
    }
    while((ch=fgetc(fs)) != EOF)
        fputc(ch,ft);
    fclose(fs);
    fclose(ft);
    return 0;    
}