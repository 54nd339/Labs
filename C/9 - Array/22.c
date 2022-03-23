#include<stdio.h>
#include<math.h>
int det(int n, int mat[n][n]){
   if (n==2)
      return ((mat[0][0]*mat[1][1]) - (mat[1][0]*mat[0][1]));
   else{
      int subma[n][n], sum = 0;
      for(int x=0; x<n; x++){
         int subi = 0;
         for (int i=1; i<n; i++){
            int subj = 0;
            for (int j=0; j<n; j++){
               if (j==x) continue;
               subma[subi][subj++] = mat[i][j];
            }
            subi++;
         }
         sum += (pow(-1, x) * mat[0][x] * det(n-1, subma));
      }
      return sum;
   }
}
int main(){
   printf("Enter the size of the matrix : ");
   int n; scanf("%d",&n);
   printf("Enter a %dX%d Matrix:\n",n,n);
   int mat[n][n];
   for(int i=0; i<n; i++)
       for(int j=0; j<n; j++){
           printf("Enter Element %d,%d : ",i+1,j+1);
           scanf("%d",&mat[i][j]);
       }    
   printf("Original Matrix :\n");
   for(int i=0; i<n; i++){
       for(int j=0; j<n; j++)
           printf("%d ",mat[i][j]);
       printf("\n");
   }
   printf("Det of the matrix is : %d",det(n, mat));
   return 0;
}