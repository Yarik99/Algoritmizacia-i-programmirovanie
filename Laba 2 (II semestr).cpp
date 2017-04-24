#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <locale.h>
#include <malloc.h>

void vvod(int *A,int n)
{
	int i,j;

	for(i=0;i<n;i++)
	{
		*(A+i)=rand()%10-5;
	}
}

void pechat(int *A,int n)
{
	int i,j;

	for(i=0;i<n;i++)
	{
		printf("%d",*(A+i));
		printf("\t");
	}
}

void tochki(int *A,int *n)
{
	int i,j;

	for(i=1;i<(*n)-1;i++)
		{
			if(*(A+(i-1))<*(A+i) && *(A+(i+1))<*(A+i))
				{
					for(j=i;j<(*n)-1;j++)
			{
				*(A+j)=*(A+(j+1));
			}
					(*n)--;
				}
		}
}

void main()
{
	setlocale(0,"RUS");
	int A[7],B[8],C[9];
	int n;

	n=7;
	vvod(&A[0],7);
	printf("\n\t\t\tМассив № 1\n\n");
	pechat(&A[0],7);
	tochki(&A[0],&n);
	printf("\n\n\t\t\tИзменённый массив № 1\n\n");
	pechat(&A[0],n);

	n=8;
	vvod(&B[0],8);
	printf("\n\n\n\t\t\tМассив № 2\n\n");
	pechat(&B[0],8);
	tochki(&B[0],&n);
	printf("\n\n\t\t\tИзменённый массив № 2\n\n");
	pechat(&B[0],n);

	n=9;
	vvod(&C[0],9);
	printf("\n\n\n\t\t\tМассив № 3\n\n");
	pechat(&C[0],9);
	tochki(&C[0],&n);
	printf("\n\n\t\t\tИзменённый массив № 3\n\n");
	pechat(&C[0],n);

	getch();
}
