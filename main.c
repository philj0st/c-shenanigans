#include <stdio.h>
#include <stdlib.h>

//todo: add comments

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

int main(void){

  Pair first;
  Pair second;

  // have a first cell holding the value 4 and pointing to the cell second
  first.value = 4;
  first.next = &second;

  // second cell holding 2 and pointing to NULL
  second.value = 2;
  second.next = NULL;

  Pair* head = cons(2, cons(4, cons(12, NULL)));

  printf("value of the second is %d", head->next->next->value); // 2
}
