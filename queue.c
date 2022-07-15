#include<stdio.h>
#include<unistd.h>
#include<time.h>
#include<stdlib.h>

#define QUEUE_FULL 10
#define QUEUE_EMPTY 0

void ENQUEUE( int *ptr, int value, int * last)
{
	if( *last != QUEUE_FULL )
	{
		int i = *last - 1;
		for ( i ; i >= QUEUE_EMPTY ; i--)
		{
			ptr[i + 1] = ptr[i];
		}
		ptr[QUEUE_EMPTY] = value;
		(*last)++;
		printf("thhe  pushed value in queue = %d\n", value);
	}
	else
	{
		printf(" ***** QUEUE IS FULL ******\n");
	}
}
int DEQUEUE(int *ptr, int* last)
{
	if ( *last >= QUEUE_EMPTY)
	{
		(*last)--;
		int ret =  ptr[*last];
		ptr[*last] = 0;
		return ret;
	}
	else
	{
		printf(" ***** QUEUE IS EMPTY ****\n");
		return 0xFF;
	}
}
void print( int * ptr, int last)
{
	int i;
	if( last <= QUEUE_EMPTY)
	{
		printf(" ***** QUEUE IS EMPTY ****\n");
		return ;
	}
	printf(" size is = %d\n", last);
	for (i = QUEUE_EMPTY; i < last; i++)
	{
		printf("[%d]",ptr[i]);
	}
	printf("\n");
}
int main ( void )
{
	int arr[5] = {0};
	int last = QUEUE_EMPTY;
	int op = 0;
	while(1)
	{
		printf("Enter the value to perform operation\n\n" "1) ENQUEUE\n" "2) DEQUEUE\n" "3) print\n" "4) count\n" "exit\n");
		scanf("%d", &op);
		switch(op)
		{
			case 1:
			{
				int value = (rand() % 100);
				ENQUEUE(arr, value, &last );
				break;
			}

			case 2:
			{
				int pop = DEQUEUE(arr, &last);
				if( 0xFF == pop)
					break;
				
				printf("pooped value is = %d\n", pop);
				break;
			}

			case 3:
				print(arr, last);
				break;
			case 4 :
			{
				printf("Total count is %d\n", last);
				break;
			}
			default :
			{
				exit(0);
				printf("***** Invalid Operation *****\n");
				break;
			}
		}
	}
	return 0;
}
