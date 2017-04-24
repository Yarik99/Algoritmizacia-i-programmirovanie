#include "stdafx.h" 
#include <stdio.h> 
#include <conio.h> 
#include <math.h> 
#include <stdlib.h> 
#include <locale.h>

int _tmain(int argc, _TCHAR* argv[]) 
{ 
setlocale(0, "rus"); 
int *A; 
int i,j,n,m,k,p,z=0,S,dop;
printf("Введите количество строк в матрице\n"); 
scanf_s("%d",&m); 
printf("Введите количество столбцов в матрице\n"); 
scanf_s("%d",&n); 
A=(int*)malloc(m*n*sizeof(int));
printf("\n\t\t\tИсходная матрица\n\n"); 
for (i=0;i<m;i++) { 
for (j=0;j<n;j++) { 
*(A+i*n+j)=rand()%10-5; 
printf("%6d",*(A+i*n+j)); 
} 
printf("\n\n");
}

for(k=0;k<n;k++)
	{ S=0;  
      for(i=0;i<m;i++)
     	S=S+*(A+i*n+k);
	  printf("S=%d\t",S);

if(S<0)
{	
	dop=0;
for(j=0;j<n;j++)
	for(i=1;i<m;i++)
	{
	if (*(A+i*n+k)<*(A+(i-1)*n+k)) 
{dop=*(A+i*n+k);
*(A+i*n+k)=*(A+(i-1)*n+k);
*(A+(i-1)*n+k)=dop;}
	}
}

	}

printf("\n\n\n");

printf("\t\tОтсортированная матрица\n");
	for(i=0;i<m;i++)
	{for(j=0;j<n;j++)
	   printf("%6d",*(A+i*n+j));
	printf("\n\n");}
getch();
return 0;
}
