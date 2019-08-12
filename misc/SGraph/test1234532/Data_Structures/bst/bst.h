#ifndef BST_H
#define BST_H

struct bst {
  int value;
  struct bst *left;
  struct bst *right;
};

struct bst *create_item(int value);
void add_item(int value, struct bst * tmp);
void print_in_order(struct bst * tmp);
void remove_item(int value);
void lowest_right_value(int value);



#endif
