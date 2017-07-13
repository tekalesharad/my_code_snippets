#include <stdio.h>
struct ll {
int data;
struct ll *next;
};

typedef struct ll LL;
struct ll **head;


LL* create_node(int value){
 LL * tmp;
 tmp = (LL*)malloc(sizeof(LL));
 tmp->data=value;
 tmp->next=NULL;
}

void add_node( int value, LL * ptr) {
 LL *tmp;
 tmp = *ptr;
 if(ptr == NULL) {
   ptr = create_node(value);
    printf("\nroot %d ", ptr->data);
 }
 else {
  while(tmp->next != NULL)
    tmp= tmp->next;
  tmp->next = create_node(value);
 printf("\nnode %d %d ", tmp->data, tmp->next->data);
 }
}


void print_ll(LL * ptr)
{
  printf("\n--PRINT---------\n");   
  while(ptr !=NULL) {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
  printf("-- END --\n");   
}

void main()
{
//print_ll(head);
add_node(5, head);
print_ll(head);
add_node(6, head);
add_node(7, head);
print_ll(head);
add_node(2, head);
add_node(3, head);
print_ll(head);
}

