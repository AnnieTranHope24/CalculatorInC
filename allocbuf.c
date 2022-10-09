#include <stdio.h>
char *alloc(int n);
int afree(char *p);
void push (char *p);
char *pop(void);
char *peek(void);

#define ALLOCSIZE 16 /* size of available space */

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf; /* next free position */
char *alloc(int n) /* return pointer to n characters */
{
  if (allocbuf + ALLOCSIZE - allocp >= n) { /* it fits */
    allocp +=n; // move allocp forward to its new position
	push(allocp - n);
    return allocp - n; // return allocp's previous position
  } 
  else /* not enough room */{
	printf("not enough room");
    return NULL; /* NULL points to nothing */	  
  }

}

int afree(char *p) /* free up the storage pointed to by p */
{
  // ensure that p is actually pointing to a spot in the buffer
  // if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
    // allocp = p;
	if(p == peek()){
		pop();
		allocp = p;
		return 1;
	}
	else{
		return 0;
	}
}
// Stack implementation


int sp = 0; // "stack pointer" - current index for the spot above the top of stack
#define MAXVAL 100
char *val[MAXVAL];
void push (char *p)
{
  if(sp < MAXVAL)
    val[sp++] = p;
	else
		printf("error: stack full\n");
}

char *pop(void)
{
  if(sp > 0)
    return val[--sp];
  else
    {
      //printf("error: stack empty \n");
      return NULL;
    }
}
char *peek(void){
	  if(sp > 0){
		  return val[sp-1];
	  }
	  else{
		  return NULL;
	  }
    
}
int main()
{

	char *p1 = alloc(8);
  char *p2 = alloc(8);
  // printf("%s\n", peek());
  int rc = afree(p1);
  printf("First call to afree shouldn't work because p2 hasn't been freed: %d\n", rc);
  rc = afree(p2);
  printf("Second call to afree should work because p2 was allocated last: %d\n", rc);
  rc = afree(p1);
  printf("Last call to afree should work because p2 has been freed: %d\n", rc);
}

