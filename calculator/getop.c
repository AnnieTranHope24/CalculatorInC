#include <stdio.h>
#include "calc.h"
#include <math.h>
#define NUMBER '0'
int getop(char s[])
{
	int i;
	i=0;
	while(s[i] != '\0'){
		i++;
	}
	
   if(isdigit(*s)) {
	   return NUMBER;
   }
   if((i >= 2) && s[0] == '-'){
	   return NUMBER;
   }
   else{
	   return *s;
   }

}