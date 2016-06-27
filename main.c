#include <stdio.h>

typedef struct Pair Pair;

// Cons Cell containing a Value and a Pointer to another Cell
struct Pair {
  int value;
  Pair *next;
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

  printf("value of the second is %d", first.next->value); // 2
}
