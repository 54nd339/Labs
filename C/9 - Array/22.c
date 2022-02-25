#include<stdio.h>
#include<math.h>
int det(int mat[10][10],int n){
   int sum=0;
   int subma[10][10];
   if (n==2)
   return ((mat[0][0]*mat[1][1])-(mat[1][0]*mat[0][1]));
   else{
      for(int x=0;x<n;x++){
         int subi=0;
         for (int i=1;i<n;i++){
            int subj = 0;
            for (int j=0;j<n;j++){
               if (j==x)
               continue;
               subma[subi][subj]=mat[i][j];
               subj++;
            }
            subi++;
         }
         sum+=(pow(-1, x) * mat[0][x] * det(subma,n-1));
      }
   }
   return sum;
}
int main(){
   int n,i,j;
   int mat[10][10];
   printf("Enter the size of the matrix : ");
   scanf("%d",&n);
   printf("Enter a %dX%d Matrix:\n",n,n);
   for(i=0;i<n;i++)
       for(j=0;j<n;j++){
           printf("Enter Element %d,%d : ",i+1,j+1);
           scanf("%d",&mat[i][j]);
       }    
   printf("Original Matrix :\n");
   for(i=0;i<n;i++){
       for(j=0;j<n;j++)
           printf("%d ",mat[i][j]);
       printf("\n");
   }
   printf("Det of the matrix is : %d",det(mat,n));
   return 0;
}
