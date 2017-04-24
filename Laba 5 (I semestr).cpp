#include"stdafx.h"
#include"conio.h"
#include"locale.h"
#include"stdio.h"
#include"math.h"
#include "stdlib.h"

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(0,"rus");
	int A[40];
	int i,j,x,n;
	int max,min;
	int dop=0;
	n=40;
	printf("\t\t\t\tИсходный массив\n\n");
	for(i=0;i<n;i++)
	{
		A[i]=rand()%100-50;
		printf("%d",A[i]);
		printf("\t");
	}
	max=A[0];
	min=A[0];
	for(i=1;i<n;i++)
	{
		if(A[i]>max) max=A[i];
		else if(A[i]<min) min=A[i];
		else continue;
	}
	printf("\nmax=%d",max);
	printf("\t\t\tmin=%d",min);
	for(i=0;i<n;i++)
	{if (A[i]%2==0) continue;
	else
		for(j=i+1;j<n;j++)
		{if (A[j]%2==0) continue;
		else A[i]=A[i]+1;A[j]=A[j]-1;i=j; break;}
	}
	printf("\n\n\t\t\t\tИзменённый массив\n\n");
	for(i=0;i<n;i++)
	{printf("%d",A[i]);
	printf("\t");}
	max=A[0];
	min=A[0];
	for(i=1;i<n;i++)
	{
		if(A[i]>max) max=A[i];
		else if(A[i]<min) min=A[i];
		else continue;
	}
	printf("\nmax=%d",max);
	printf("\t\t\tmin=%d",min);
		getch();
	return 0;
}
