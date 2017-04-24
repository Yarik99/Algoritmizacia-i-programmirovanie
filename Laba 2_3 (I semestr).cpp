#include "stdafx.h"
#include <math.h>
#include <conio.h>
#include <stdio.h>
#include <locale.h>


int _tmain(int argc, _TCHAR* argv[])
{setlocale (0,"rus");
float a,b,c,xa,xb,xc,ya,yb,yc,ab,bc,ac,p,S;
printf("введите параметры первой точки : xa,ya\n");
scanf("%f %f",&xa,&ya);
printf("введите параметры второй точки : xb,yb\n");
scanf("%f %f",&xb,&yb);
printf("введите параметры третей точки : xc,yc\n");
scanf("%f %f",&xc,&yc);
ab=sqrt(pow((xb-xa),2)+pow((yb-ya),2));
bc=sqrt(pow((xc-xb),2)+pow((yc-yb),2));
ac=sqrt(pow((xc-xa),2)+pow((yc-ya),2));
p=(ab+bc+ac)/2;
S=sqrt(p*(p-ab)*(p-bc)*(p-ac));
if(S==0) {printf("три точки лежат на одной прямой");
goto m1;}
else printf("ab=%f bc=%f ac=%f p=%f S=%f",ab,bc,ac,p,S);
m1:getch();
	return 0;
}
