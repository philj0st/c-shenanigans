#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct Pair Pair;

// Cons Cell containing a Value and a Pointer to another Cell
struct Pair {
  int value;
  Pair* next;
};

// cons(1, cons(2, cons(3, NULL))) -> '(1 2 3)
// creates a Pair with value and pointer to the next Pair under the hood and returns the ptr to the newly created Pair
Pair* cons(int value, Pair* next){
  Pair* pair = malloc(sizeof(Pair));
  pair->value = value;
  pair->next = next;
  return pair;
};

//create list from variable arguments and return ptr to head of the list
Pair* list(int first, ...){
  va_list ap;
  va_start(ap, first);

  int p2 = va_arg(ap, int);
  va_end(ap);

  Pair* pair = malloc(sizeof(Pair));
  pair->value = p2;
  pair->next = NULL;

  return pair;
};

//traverse the list and print every value of every pair
void printl(Pair* head){
  printf("%d\n", head->value);
  if (head->next == NULL){
    //do nothing
  } else {
    printl(head->next);
  }
}

int main(void){

  Pair* head = cons(2, cons(4, cons(12, NULL)));
  // Pair* head = list(1, 2, 3);
  // printf("value is %d", head->value); // 2
  printl(head);
}
