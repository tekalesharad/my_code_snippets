#ifndef HASH_H
#define HASH_H

#define NO_BUCKETS 10
struct hash_table {
char name[20];
char vehicle[20];
struct  hash_table *next;
};

void init_hash();
int hash_fun(char *name);
int add_item(char *name, char *vehicle);
struct hash_table * createLeaf(char *name, char *vehicle);
int add_item(char *name, char *vehicle);
#endif
