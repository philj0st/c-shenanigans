#include <stdio.h>
#include <stdlib.h>
// #include <stdarg.h>

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

Pair* car(Pair* list){
  // create a new pair otherwise the data passed as parameter gets mutated
  Pair* pair = malloc(sizeof(Pair));
  // assignment by copy of by reference?
  pair->value = list->value;
  // cut the rest of the list off
  pair->next = NULL;
  // and return the first element
  return pair;
}

Pair* cdr(Pair* list){
  return list->next;
}

// the first n items from the list will be dropped
Pair* drop(Pair* list, int n){
  if (n == 0){
    return list;
  } else {
    return drop(cdr(list), n-1);
  }
}

// returns the length of the list
// wrapper function to avoid calling with 2 parameters
int length(Pair* list){
  if (list->next == NULL){
    return 1;
  } else {
    return _length(list, 1);
  }
}

// private helper function see length
int _length(Pair* list, int count){
  if (list->next == NULL){
    return count;
  } else {
    return _length(cdr(list), count+1);
  }
}

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

  Pair* newList = cons(2, cons(4, cons(12, cons(24, cons(48, NULL)))));
  // printl(car(cdr(newList)));
  // printl(newList);
  printl(drop(newList, 3));
  printf("the list is %d long", length(newList));
  // Pair* head = list(2, 1 ,2);
  // // printl(head);
  // printf("%d\n", head->value);
}