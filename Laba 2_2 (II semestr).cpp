#include "stdafx.h"
#include <math.h>
#include <stdio.h>
#include <conio.h>
#include <locale.h>


int _tmain(int argc, _TCHAR* argv[])
{setlocale (0, "rus");
float a,x,b,c,F;
printf("Введите параметры a, x, b, c");
scanf("%f %f %f %f",&a,&x,&b,&c);
if (x<3 && b!=0) F=a*x*x-b*x+c;
else if (x>3 && b==0) if (x-c!=0) F=(x-a)/(x-c);
else {printf("нет решений"); 
goto m1;}
else if (c!=0) F=pow(-x,2)/(c*c);
else {printf("нет решений");
goto m1;}
	printf("a=%f x=%f b=%f c=%f F=%f" ,a,x,b,c,F);
m1:getch();
           return 0;
}
