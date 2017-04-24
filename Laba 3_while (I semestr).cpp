#include "stdafx.h"
#include "math.h"
#include "conio.h"
#include "stdio.h"
#include "locale.h"



int _tmain(int argc, _TCHAR* argv[])
{setlocale(0,"rus");
float a,x,b,c,xн,xк,dx,F,S,i;
printf("Введите параметры a,b,c,xн,xк,dx");
scanf("%f %f %f %f %f %f",&a,&b,&c,&xн,&xк,&dx);
S=0;
i=1;
x=xн;
 while (x<xк)
{ 
	if (x<3 && b!=0) F=a*x*x-b*x+c;
else if (x>3 && b==0) if (x-c!=0) F=(x-a)/(x-c);
else {printf("нет решений");x=x+dx;continue;}
else if (c!=0) F=pow(-x,2)/(c*c);
else {printf("нет решений");x=x+dx;continue;}
	printf("a=%f\n x=%f\n b=%f\n c=%f\n F=%f\n" ,a,x,b,c,F);
	S=S+log(F/i);
	i++;
	x=x+dx;
}
printf("S=%f\n" ,S);
getch();
	return 0;
}
