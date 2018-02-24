
#include <stdio.h>
#include "bst.h"

struct bst *root = NULL;
//Create item
struct bst *create_item(int value)
{
  struct bst * tmp = (struct bst *)malloc(sizeof(struct bst));
  tmp->value=value;
  tmp->left = NULL;
  tmp->right = NULL;
}

struct bst *find_node(int value, struct bst *tmp) {
   printf("Find_node value:%d tmp->value:%d \n ", value, tmp->value);
  if(tmp == NULL) {
    printf("Tree is empty\n");
    return NULL;
  }
  else {
     if (value == tmp->value) {
       printf("Return node %d\n", tmp->value);
       return tmp;
     }
     else if(value < tmp->value) {
       if(tmp->left != NULL)
         find_node(value, tmp->left);
     }
     else if(value > tmp->value) {
        if(tmp->right != NULL)
         find_node(value, tmp->right);
     }
    } 
}

#if 0
struct bst *lowest_right_value(int value, struct bst *tmp) 
{
  if(tmp == NULL)
    printf("Tree is empty\n");
  else {
    if(tmp->right !=NULL) {
       lowest_right_value(value, tmp->right)
    }
    else
      return tmp; 
  }
   return NULL;
  
}
#endif

void add_item(int value, struct bst * tmp)
{
//  printf("Adding %d:\n", value);
  if(root == NULL) {
    root = create_item(value);
  }
  else
  {
    if(value < tmp->value)
     {
       if(tmp->left !=NULL)
         add_item(value, tmp->left);
       else
         tmp->left = create_item(value);
     }
     else if (value > tmp->value)
     {
       if(tmp->right !=NULL)
         add_item(value, tmp->right);
       else
         tmp->right = create_item(value);
     }
     else
       printf("Key is already added to Keyyy \n");
 }
}

void print_in_order(struct bst * tmp)
{
  if(tmp == NULL)
    printf("Tree is empty\n");
  else {
    if(tmp->left != NULL ) 
       print_in_order(tmp->left);

    printf("%d ", tmp->value );
    
   if( tmp->right != NULL) 
    print_in_order(tmp->right);  
  }
}

int main()
{
int values[9]={50, 30, 20, 60, 80,2, 10, 100, 120};
//  int values[5]={50};
  int i=0;
  struct bst * tmp1 =NULL;
  print_in_order(root);
  for( i=0; i<9; i++)
    add_item(values[i], root);

  print_in_order(root);

  tmp1=find_node(12, root);
  if(tmp1 !=NULL)
    printf("tmp1:%d\n", tmp1->value);
  else
    printf("tmp1 couldnt get\n");

}
