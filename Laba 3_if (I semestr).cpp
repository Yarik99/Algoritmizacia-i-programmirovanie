#include "stdafx.h"
#include "math.h"
#include "conio.h"
#include "stdio.h"
#include "locale.h"



int _tmain(int argc, _TCHAR* argv[])
{setlocale(0,"rus");
float a,x,b,c,xн,xк,dx,i,F,S;
printf("Введите параметры a,b,c,xн,xк,dx");
scanf("%f %f %f %f %f %f",&a,&b,&c,&xн,&xк,&dx);
S=0;
i=1;
x=xн;
m2:
if (x<=3 && b!=0) F=a*pow(x,2)-(b*x)+c;
else if (x>3 && b==0) if (x-c!=0) F=(x-a)/(x-c);
else {printf("нет решений"); 
goto m1;}
else if (c!=0) F=x/c;
else {printf("нет решений");
goto m1;}
	printf("a=%f\n b=%f\n c=%f\n x=%f\n F=%f\n" ,a,b,c,x,F);
	S=S+log(F/i);
	i++;
	m1:
	x=x+dx;
	if (x<xк) goto m2;
	else printf("S=%f\n" ,S);
	getch();
	return 0;
}
