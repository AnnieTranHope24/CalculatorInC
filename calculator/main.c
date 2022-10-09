#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char[]);
void push(double);
double pop(void);
void swap(void);

main(int argc, char *argv[])
{
  int type; /* is it an operator or an operand or an EOF */
  double op2; /* for division */
  double op1; /*for pow*/
	int i;
  for(i=1; i<argc; i++) {
	  type = getop(argv[i]);
    switch(type) {
    case NUMBER:
      push(atof(argv[i]));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      swap();
      push(pop() - pop());
      break;
    case '/':
      op2 = pop();
      if(op2 != 0.0)
		push(pop() / op2);
      else
		printf("error: zero divisor\n");
      break;
	case '%':
		op2 = pop();	
		if(op2 != 0.0){
			push(fmod(pop(), op2));
		}			
		else{
			printf("error: zero divisor\n");
		}				
	 break;
    default:
      printf("error: unknown command %s\n", argv[i]);
      break;
    }
  }
  printf("\t%.8g\n", pop());
  return 0;
}