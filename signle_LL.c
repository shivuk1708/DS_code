#include<stdio.h>
#include<stdlib.h>
struct link{
    int data;
    struct link *next;
};
struct link * create_list( void )
{
       struct link * new_list = (struct link *) malloc (sizeof(struct link *));
       new_list->next = NULL;
       return new_list; 
}
int get_totalnode(struct link* node)
{
    int i = 0;
    if ( NULL == node)
    {
        return i;
    }
    else
    {
        struct link * temp = node;
        do
        {
            i++;
            temp = temp->next;

        }while(NULL != temp);
        return i;
    }
}
struct link * get_nthnode(struct link * node, int n)
{
    struct link * temp = node;
    int count = get_totalnode(node);
    if( n < count)
    {
        
        while(--n)
        {
            temp = temp->next;
        }
        return temp;
    }
    else
    {
        printf("****** invalid count *****\n");
    }
}
struct link * get_last( struct link * node )
{
     if(NULL == node )
         return node;
     struct link * temp = node;
     while(NULL != temp->next)
     {
         temp = temp->next;
     }
     return temp;

}
void add_end(struct link **list, int value)
{
    if(NULL == *list)
    {
        *list = create_list();
        (*list)->data = value;
    }
    else
    {
        struct link * last = get_last(*list);
        struct link * temp = create_list();
        temp->data = value;
        last->next = temp;
    }

}
struct link * add_begin( struct link * list, int value)
{
    if( NULL == list )
    {
            list = create_list();
            list->data = value;
        return list;    
    }
    else
    {
        struct link *temp = create_list();
        temp->data = value;
        temp->next = list;
        return temp;
    }
}
void delete_begin( struct link ** list)
{
    if( NULL == *list)
    {
         printf(" ****** LIST IS EMPTY *****\n");
    }
    else
    {
        struct link* temp = (*list);
        (*list) = (*list)->next;
        temp->next = NULL;
        free (temp);
    }

}
void delete_last(struct link ** node)
{
    if ( NULL == *node)
    {
        printf(" ****** LIST IS EMPTY *****\n");
    }
    else if( NULL == (*node)->next) 
    {
        free(*node);
        *node = NULL;
    }   
    else
    {
        int num = get_totalnode(*node); 
        printf(" total node is %d\n", num);
        struct link * temp = get_nthnode(*node, num-1);
        printf(" total node is %d\n", temp->data);
        struct link * last = temp->next;
        free(last);
        last = NULL;
        temp->next = NULL;
    }
}
void print_list(struct link * node)
{
     if(NULL == node )
     {
         printf(" ****** LIST IS EMPTY *****\n");
     }
     else
     {
         printf("\n******** THE LIST IS *******\n");
             struct link * temp = node;
             do
             {
             printf(" %d-->", temp->data);
             temp = temp->next;
             }while(NULL != temp);
         printf("\n******** END *******\n\n");
     }
}
void print_menu(void)
{
        printf("1) add_begin()\n2) add_end()\n3) delete_begin()\n4) delete_last\n9) print_list()\n0) exit while loop\n");
}
int main ( void )
{
     struct link * list = NULL;
     int op = 0;
     while(1)
     {
    print_menu();
    scanf("%d", &op);
    switch (op)
    {
        case 1 :
            {
                int i = 0;
                printf("enter the value to add at begin\n");
                scanf("%d",&i);
                list = add_begin(list,i);
                break;
            }
        case 2 :
            {
                int i = 0;
                printf("enter the value to add at last\n");
                scanf("%d", &i);
                add_end(&list, i);
                    break;  
            }
        case 3 :
            {
                printf(" deleted the beginingof the node\n");
                delete_begin(&list);
                break;
            }
        case 4 :
            {
                delete_last(&list);
                printf("delete last node\n");
                break;
            }
        case 9 :
            {
                print_list(list);
                break;
            }
        case 0 :
            exit(0);
    }
     } 
     return 0;
}
