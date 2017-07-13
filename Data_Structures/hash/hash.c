#include <stdio.h>
#include "hash.h"
struct hash_table *HASH_TABLE[NO_BUCKETS];

void init_hash()
{
  int i=0;
  for(i=0; i< NO_BUCKETS; i++) {
   HASH_TABLE[i]  = (struct hash_table *)malloc(sizeof(struct hash_table));
   strcpy(HASH_TABLE[i]->name,"empty");
   strcpy(HASH_TABLE[i]->vehicle,"empty");
   HASH_TABLE[i]->next = NULL;
  }
   
}

int hash_fun(char *name)
{
  int i =0;
  int index=0;
  for(i=0;i<strlen(name); i++) {
    index += (int)name[i];
//    printf("%c ", (int)name[i]);
  }
  return index%NO_BUCKETS;
}

struct hash_table * createLeaf(char *name, char *vehicle)
{
  struct hash_table *tmp = (struct hash_table *)malloc(sizeof(struct hash_table));
  strcpy(tmp->name,name);
  strcpy(tmp->vehicle,vehicle);

//  tmp->name=name;
//  tmp->vehicle=vehicle;
  tmp->next=NULL;  
  return tmp;
}

int add_item(char *name, char *vehicle)
{
  int index;
  index = hash_fun(name);
//  printf("name:%s:hash:%d\n", name, index);
  if( strcmp(HASH_TABLE[index]->name, "empty") == 0) {
    strcpy(HASH_TABLE[index]->name,name);
    strcpy(HASH_TABLE[index]->vehicle,vehicle);
    HASH_TABLE[index]->next = NULL;
  }
  else {
    struct hash_table* tmpPtr = HASH_TABLE[index];
    struct hash_table* gen;
    while(tmpPtr->next != NULL)
      tmpPtr =  tmpPtr->next;
    gen = createLeaf(name,vehicle);
    printf("##### tmpPtr->name:%s", tmpPtr->name);
    tmpPtr->next = gen;
    printf("##### tmpPtr->next->name:%s\n", tmpPtr->next->name);
  }
}

void print_hash()
{
  int i=0;
  for(i=0; i<NO_BUCKETS; i++) {
    int more_Items_in_bucket = (HASH_TABLE[i]->next == NULL)? 1: 0;
    printf("index:%d name:%s vehicle:%s moreItensInBucket:%s\n", i, HASH_TABLE[i]->name, HASH_TABLE[i]->vehicle, more_Items_in_bucket? "No": "Yes");
#if 1
    if(!more_Items_in_bucket)  {
       struct hash_table *ptr = HASH_TABLE[i]->next;
       while(ptr !=NULL){
         printf("index:%d, name:%s vehicle:%s moreItensInBucket:%s\n", i, ptr->name, ptr->vehicle, more_Items_in_bucket? "No": "Yes");      
          ptr = ptr->next;
       } 
    }
#endif
   }
}


int main() {
  int index =0;
  init_hash();
  add_item("sharad","i20");
  add_item("sudhi","xylo");
  add_item("ranjith","alto");
  add_item("saurabh","swift");
  print_hash();
}
