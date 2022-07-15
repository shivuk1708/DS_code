#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct link {
	int data;
	struct link* next;
};
struct link * sort( struct link * list, struct link * node)
{
	if( NULL == list)
	{
		list = node;
		list->next = NULL;
		return list;
	}
	struct link * last = list;
	while( (NULL != last->next) && (node->data > last->data))
	{
		last = last->next;
		printf("%p %p \n", last, last->next);
	}
	if( NULL != last->next)
	{
		struct link * temp = last->next;
		last -> next = node;
		node->next = temp;
		printf(" ***** LIST IS EMPTY *****\n");
		return list;
	}
	else
	{
		last->next= node;
		node->next= NULL;
		return list;
	}
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
			struct link * temp = list;
			struct link * sort_list = NULL;
			while(temp ->next != NULL)
			{
				sort_list = sort(sort_list, temp);
				printf("%p %p %p %p\n", temp, temp->next, sort_list, sort_list->next);
				temp = temp->next;
				printf("enter how man list youwant to create\n");
			} 
			list = sort_list;
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
