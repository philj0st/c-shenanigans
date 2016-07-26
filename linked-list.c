#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct Pair Pair;

// Cons Cell containing a Value and a Pointer to another Cell
struct Pair {
  int value;
  Pair* next;
};

// just create the pair out there in memory without linking anything and return a ptr to it
Pair* createPair(int value){
  Pair* pair = malloc(sizeof(Pair));
  pair->value = value;
  return pair;
}

// cons(1, cons(2, cons(3, NULL))) -> '(1 2 3)
// creates a Pair with value and pointer to the next Pair under the hood and returns the ptr to the newly created Pair
Pair* cons(int value, Pair* next){
  Pair* pair = createPair(value);
  pair->next = next;
  return pair;
};

// //create list from variable arguments and return ptr to head of the list
// // pass the length of the list as first parameter. unfortunately there's no
// // cleaner solution in C
// Pair* list(int length, int first, ...){
//
//   // allocate memory for the first Pair which is mandatory
//   Pair* head = malloc(sizeof(Pair));
//   head->value = first;
//
//   //then traverse the rest of the parameters and cons them all together
//   va_list ap;
//   // first is the last known fixed argument being passed to the function (the argument before the ellipsis).
//   va_start(ap, first);
//
//   printf("building tail with %d items \n", length-1);
//
//   // keep a reference to the previous item so we can cons from within the for loop
//   Pair* previous = &first
//   // -1 because the first item is not part of the va_arg
//   for (int i = 0; i < length-1; i++) {
//     // get the next value of the parameters
//     int value = va_arg(ap, int);
//     // allocate memory for the next cell in the list
//     Pair* next = malloc(sizeof(Pair));
//     // and link the new cell to the previous
//     previous->next = next;
//
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

  // Pair* head = list(2, 1 ,2);
  // // printl(head);
  // printf("%d\n", head->value);
}
