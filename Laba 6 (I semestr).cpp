#include "stdafx.h"
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <conio.h>
#include <stdlib.h>

int _tmain(int argc, _TCHAR* argv[])
{setlocale(0,"rus");
int A[100];
int i,j,n,k;
int max,kount;
int num;
printf("Введите размерность массива\n");
scanf("%d",&n);
printf("\t\t\t\tИсходный массив\n\n");
for(i=0;i<n;i++)
{A[i]=rand()%20;
printf("%4d",A[i]);
}
max=A[0];
for(i=1;i<n;i++)
{if (A[i]>max) max=A[i];
}
printf("\nmax=%d",max);
kount=0;
num=0;
for(i=0;i<n;i++)
{if (A[i]==max) {num=i;kount++;}}
printf("num=%d\t",num);
printf("\tkount=%d",kount);

		for(i=num-1;i>0;i--)
			{ 
				if (A[i]==max)	
					 { for(j=i;j<n-1;j++)
						A[j]=A[j+1];
				n--; }
		}


printf("\n\n\t\t\t\tИзменённый массив\n\n");
	for(i=0;i<n;i++)
	{printf("%4d",A[i]);
	}

getch();
	return 0;
}
