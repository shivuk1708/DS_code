#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct link {
	int data;
	struct link* next;
};
struct link * sort( struct link * list)
{
	if( NULL == list)
	{
		return NULL;
	}
	if( NULL == list->next)
	{
		return list;
	}
	struct link *first = list;
	while(NULL != first) 
	{
		
		struct link *last = first;
		while(NULL != last) 
		{
			if(first->data <= last->data)
			{
				int temp = 0;
				temp = first->data;
				first->data = last->data;
				last->data = temp;
			}
			last = last->next;
		}
		first = first->next;
	}
	return list;
}
void print_list( struct link * node)
{
	if( NULL == node)
	{
		printf(" ***** LIST IS EMPTY *****\n");
	}
	else
	{
		while(node != NULL)
		{
			printf("%d--->", node->data);
			node = node->next;
		}
		printf("\n");
	}
}
struct link *create_list( struct link *list, int num)
{
	if( NULL == list)
	{
		struct link * last;
		if(NULL == list)
		{
			struct link * temp = (struct link *)malloc(sizeof(struct link*));
			temp ->data = rand() % 10;
			temp->next = NULL;
			list = temp;
			last = temp;
		}
		while( --num)
		{
			struct link * temp = (struct link *)malloc(sizeof(struct link*));
			temp ->data = rand() % 10;
			temp->next = NULL;
			last->next = temp;
			last = last->next;
		}
		return list;
	}
}
int main ( void )
{
	struct link * list = NULL;
	int op = 0;
	int time;
	srand(time);
	while(1)
	{
	printf("1) create number of nodes\n 2) sort nodes\n 3) printf nodes\n");
	scanf("%d", &op);
	switch(op)
	{
		case 1 :
		{
			int num = 0;
			printf("enter how man list youwant to create\n");
			scanf("%d", &num);
			list = create_list(list, num);
			break;
		}
		case 2 : 
		{
			list = sort(list);
			print_list(list);
			break;
		}
		case 3 :
			print_list(list);
			break;	
	}
	}
	return 0; 	
}
