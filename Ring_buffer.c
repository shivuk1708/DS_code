#include<stdio.h>
#define QUEUE_MAX 10
int count = 0;
int head = 0;
int tail = 0;

void enqueue(int * array, int num)
{
	if( count == QUEUE_MAX)
	{
		printf("\n ***** Queue is FULL ***** \n");
		return;
	}
	array[head % QUEUE_MAX] = num;
	head++;
	count++;
}
void dequeue( int * array)
{
	if( count == 0)
	{
		printf("\n ***** Queue is EMPTY ***** \n");
		return;
	}
	int num = array[tail % QUEUE_MAX];
	array[tail % QUEUE_MAX] = 0;
	tail++;
	count--;
	printf(" Dequeue number is = %d \n", num );
}
void print_queue(int * array)
{
	int i =0;
	printf("\n********************\n");
	for(i =0; i< QUEUE_MAX; i++)
	{
		printf("| %d |", array[i]);
	}
	printf("\n********************\n\n");
}
int main( void )
{
	int array[QUEUE_MAX] = {0};

	while(1)
	{
		int ch = 0;
		int num = 0;
		printf("\nEnter the Operation you wnat to do \n");
		printf("1) Insert number in Queue, \n2) Delete queue number, \n3) print queue elements, \n10) Exit\n\n");
		scanf("%d", &ch);
		switch(ch)
		{
		case 1:
			printf("Enter the number to insert in Queue\n");
			scanf("%d", &num);
			enqueue(array, num);
			break;
		case 2: 
			dequeue(array);
			break;
		case 3:
			print_queue(array);
			break;
		case 10:
			return 0;
		default:
		printf("Entered the wrong number\n");
		}
	}
	return 0;
}

