#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <locale.h>
#include <malloc.h>

void vvod(int *A,int n,int m)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			*(A+i*m+j)=rand()%10;
	}
}

void pechat(int*A,int n,int m)
{
	int i,j;
	printf("\tКоординаты векторов:\n\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			printf("%6d",*(A+i*m+j));
		printf("\n");
	}
}

float ugol(int *A,int n,int m,int *num_1,int *num_2)
{
int i,j1,j2/*,num_1,num_2*/;
float proizv_modul,proizv,sum_1,sum_2,cos,cos_min;


cos_min=100000;

for(j1=0;j1<m-1;j1++)
{	for(j2=j1+1;j2<m;j2++)
	{sum_1=0;
	 sum_2=0;
	 proizv=0;
	for(i=0;i<n;i++)
		{sum_1=sum_1+pow(*(A+i*m+j1),2.0);
		sum_2=sum_2+pow(*(A+i*m+j2),2.0);
		proizv=proizv+(*(A+i*m+j1))*(*(A+i*m+j2));
		}
	proizv_modul=sqrt(sum_1)*sqrt(sum_2);
	cos=proizv/proizv_modul;
	if(cos<cos_min)
		{cos_min=cos;
		 *num_1=j1;
		 *num_2=j2;
		}
	}
}
/*printf("\n\tcos_min=%.3f \n\n\tnum_1=%d num_2=%d",cos_min,num_1,num_2);*/
/**ugol_min=cos_min;*/
return cos_min;
}

void main()
{
	setlocale(0,"RUS");
	int A[100][100];
	int n,m,modul_x,modul_y,ugol_1,num_1,num_2;
	float cos_min;
	printf("Введите количество координат\n");
	scanf("%d",&n);
	printf("Введите количесство векторов:\n");
	scanf("%d",&m);
	vvod(&A[0][0],n,m);
	pechat(&A[0][0],n,m);
	cos_min=ugol(&A[0][0],n,m,&num_1,&num_2);
	printf("\n\tcos_min=%.3f \n\nnum_1=%d num_2=%d",cos_min,num_1,num_2);
	getch();
}
