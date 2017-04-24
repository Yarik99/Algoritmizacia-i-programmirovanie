#include "stdafx.h" 
#include <stdio.h> 
#include <conio.h> 
#include <math.h> 
#include <locale.h> 
#include <stdlib.h> 


int _tmain(int argc, _TCHAR* argv[]) 
{setlocale(0,"rus"); 
int A[100][100]; 
int i,j,n,m;
int max,S=0;;
printf("Введите количество строк в матрице\n"); 
scanf("%d",&m); 
printf("Введите количество столбцов в матрице\n"); 
scanf("%d",&n); 
printf("\t\t\tИсходная матрица\n"); 
for(i=0;i<m;i++) 
for(j=0;j<n;j++) 
A[i][j]=rand()%5; 

for(i=0;i<m;i++) 
{ 
printf("\n"); 
for(j=0;j<n;j++) 
{printf("%6d",A[i][j]);} 
} 
 

for(j=0;j<n;j++) {
	max=-100; 
	for(i=0;i<m;i++) {
		if (A[i][j]>max) max=A[i][j];
	 
} 
	S=S+max;
}

printf("\n\n\t\t\t\tS=%d",S); 
getch(); 
return 0; 
}
