#include "stdafx.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

int _tmain(int argc, _TCHAR* argv[])
{setlocale(0,"rus");
int A[2][100],B[2][100];
int x1,y1,x2,y2,n1=2,m1,n2=2,m2,i,j,koor1,koor2,koor3,koor4;
float L,L_min;
printf("Введите количество столбцов первого множества точек:\n");
scanf("%d",&m1);
printf("\n\n\tПервое множество точек\n\n");
for(x1=0;x1<2;x1++)
	{for(y1=0;y1<m1;y1++)
	{A[x1][y1]=rand()%10;
printf("%6d",A[x1][y1]);
	}
printf("\n");}

printf("\nВведите количество столбцов второго множества точек:\n");
scanf("%d",&m2);
printf("\n\n\tВторое множество точек\n\n");
for(x2=0;x2<2;x2++)
	{for(y2=0;y2<m2;y2++)
	{B[x2][y2]=rand()%10;
printf("%6d",B[x2][y2]);
	}
printf("\n");}

L_min=100000;
L=0;

for(y1=0;y1<m1;y1++)
{
for(y2=0;y2<m2;y2++)
	{L=pow(pow((A[0][y1]-B[0][y2]),2.0)+pow((A[1][y1]-B[1][y2]),2.0),1/2.0);printf("\nL=%f",L);
if(L <= L_min) {  L_min=L;   koor1=y1; koor2=y2; } 

}}

/*for(x1=0,y1=0;x1<n1,y1<m1;x1++,y1++)
	{for(x2=0,y2=0;x2<n2,y2<m2;x2++,y2++)
		{L=pow(pow((A[0][y1]-B[0][y2]),2.0)+pow((A[1][y1]-B[1][y2]),2.0),1/2.0);
		if(L<L_min) L_min=L;
		}
	}*/
printf("\n\n\tL_min=%f",L_min);
printf("\n\n\(%d  %d)    (%d  %d)",A[0][koor1],A[1][koor1], B[0][koor2],B[1][koor2]);
getch();
	return 0;
}
