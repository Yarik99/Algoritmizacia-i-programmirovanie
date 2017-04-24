#include "stdafx.h"
#include <conio.h>
#include <math.h>
#include <stdio.h>



int _tmain(int argc, _TCHAR* argv[])
{double a,b,c;
a=pow(5.671*sqrt(0.6)+acos(pow(4.0,-1)),1/3.0);
b=cos(1.0/cos(3.0)+atan(2/3.0)-exp(-2/5.0)*sin(log(3.0)));
	if (a<b) c=pow(a,1/5.0)+pow(b,1/5.0);
	else c=pow(a,1/5.0)-pow(b,1/5.0);
	printf("a=%f b=%f c=%f",a,b,c);
getch();
	return 0;
}
