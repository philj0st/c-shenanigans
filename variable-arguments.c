#include <stdio.h>
#include <stdarg.h>

void varArgs(int first, ...){
  va_list ap;
  va_start(ap, first);
  int nextArg;
  // calling va_arg(va_list, int) should return the next argument of the given type
  while (nextArg = va_arg(ap, int)) {
    printf("%d\n", nextArg);
  }
  va_end(ap);
}

int main(int argc, char const *argv[]) {
  varArgs(1,2,3,4,5,6);
  return 0;
}
