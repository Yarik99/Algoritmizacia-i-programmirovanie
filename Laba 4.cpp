#include "stdafx.h"
#include "math.h"
#include "conio.h"
#include "stdio.h"
#include "locale.h"
int _tmain(int argc, _TCHAR* argv[])
{setlocale(0,"rus");
float a,aн,aк,da,x,b,bн,bк,db,c,xн,xк,dx,i,F;
double S;
printf("Введите значения aн,aк,da\n");
scanf("%f %f %f",&aн,&aк,&da);
printf("Введите значения bн,bк,db\n");
scanf("%f %f %f",&bн,&bк,&db);
printf("Введите значения xн,xк,dx\n");
scanf("%f %f %f",&xн,&xк,&dx);
printf("Введите значение переменной c\n");
scanf("%f",&c);
printf("c=%f",c);
S=0;
i=1;
for(b=bн;b<=bк;b=b+db)
{a=aн;
do{
x=xн;
while(x<=xк){
{if (x<=3 && b!=0) F=a*pow(x,2)-(b*x)+c;
else if (x>3 && b==0) if (x-c!=0) F=(x-a)/(x-c);
else {printf("\n\nx=%f \ta=%f \tb=%f ",x,a,b);printf("\tнет решений");x=x+dx;continue;}
else if (c!=0) F=x/c;
else {printf("\n\nx=%f \ta=%f \tb=%f",x,a,b);printf("\tнет решений");x=x+dx;continue;}
printf("\n\nx=%f \ta=%f \tb=%f \tF=%f" ,x,a,b,F);
S=S+log(F/i);
i++;
x=x+dx;}
}a=a+da;}
while(a<=aк);}	
printf("\n\nS=%f",S);
getch();
return 0;
}
