#include "stdafx.h" 
#include <stdio.h> 
#include <conio.h> 
#include <math.h> 
#include <stdlib.h> 
#include <locale.h>
int _tmain(int argc, _TCHAR* argv[]) 
{ 
setlocale(0, "rus"); 
int A[100][100]; 
int i,j,n,m,dop;
int max,max_i,max_j; 
printf("Введите количество строк в матрице\n"); 
scanf_s("%d",&m); 
printf("Введите количество столбцов в матрице\n"); 
scanf_s("%d",&n); 
printf("\n\t\t\tИсходная матрица\n\n"); 
for (i=0;i<n;i++) { 
for (j=0;j<n;j++) { 
A[i][j]=rand()%10; 
printf("%6d",A[i][j]); 
} 
printf("\n"); 
} 
max=-100;
max_i=0;
max_j=0;
for (i=n-1,j=0;i>=0,j<n;i--,j++) { 
		if (A[i][j]>max) {max=A[i][j];max_i=i;max_j=j;}
}  
for (i=0;i<m-1;i++) {
 if (A[i][i]>max) {max=A[i][i];max_i=i;max_j=i;} 
}
printf("\n\tmax=%d",max); 
dop=0;
dop=A[n/2][n/2];
A[n/2][n/2]=max;
A[max_i][max_j]=dop;
printf("\n\t\t\tИзменённая матрица\n\n"); 
for (i=0;i<n;i++) { 
for (j=0;j<n;j++) { 
printf("%6d", A[i][j]); 
} 
printf("\n"); }
getch(); 
}
