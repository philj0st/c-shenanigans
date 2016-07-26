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

// //create list from variable arguments and return ptr to head of the list
// Pair* list(int first, ...){
//
//   Pair* head = malloc(sizeof(Pair));
//   head->value = first;
//
//   va_list ap;
//   // first is the last known fixed argument being passed to the function (the argument before the ellipsis).
//   va_start(ap, first);
//   int i;
//   while (i = va_arg(ap, int)) {
//     printf("%d\n", i);
//   }
//
//   // Expands to the next argument in the paramater list of the function with type int
//   int p2 = va_arg(ap, int);
//
//   // must be called to close the whole macro thingy
//   va_end(ap);
//
//   Pair* second = malloc(sizeof(Pair));
//   second->value = p2;
//   second->next = NULL;
//
//   head->next = second;
//
//   return head;
// };

//traverse the list and print every value of every pair
void printl(Pair* head){
  // print the value of the current cell
  printf("%d\n", head->value);
  if (head->next == NULL){
    //do nothing
  } else {
    // call printl recursively on the rest of the list
    printl(head->next);
  }
}

int main(void){

  Pair* head = cons(2, cons(4, cons(12, NULL)));
  printl(head);
}
