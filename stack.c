#include <stdio.h>
#include <stdlib.h>

int const size;

struct
{
	int top;
	int *array;
}typedef stack;

void init(stack *);
void push(stack *, int);
int pop(stack *);

int main()
{
	printf("Enter the size of the stack: ");
	scanf("%d",&size);
	
	int option,number;
	stack s1;
	init(&s1);
	
	do
	{
		puts("1. For Pushing a number");
		puts("2. For Popping a numver");
		puts("3. For Exiting the program");
		scanf("%d",&option);
		
		switch(option)
		{
			case 1:
				printf("Enter the number you want to push: ");
				scanf("%d",&number);
				push(&s1,number);
			break;
			case 2:
				printf("The number popped is: %d\n",pop(&s1));
			break;
			default:
				printf("Enter a valid option\n");
		}
	}while(option != 3);
				
	return 0;

	free(s1.array);
}

void init(stack *s)
{
	s->top = -1;
	s->array = (int *)malloc(size * sizeof(int));
}

void push(stack *s, int num)
{
	if(s->top == size-1)
	{
		printf("The stack has overflowed");
		return;
	}

	s->top++;
	s->array[s->top] = num;
}

int pop(stack *s)
{
	if(s->top == -1)
	{
		printf("The stack has underflowed. ");
		return -9999;
	}
	
	return s->array[s->top--];
}
