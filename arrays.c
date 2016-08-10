int main(int argc, char const *argv[]) {
  int ints[3];
  ints[0] = 5;
  ints[1] = 12;
  ints[2] = 22;
  ints[3] = 33;
  ints[4] = 44;

  // length of the array is the total size divided through
  // the size of one element
  printf("length is %d\n", sizeof(ints)/sizeof(int));

  // read value at pointers position which is eqivalent
  // to the first element in the array
  printf("%d\n", *ints);


  // address of second one is sizeof type more
  printf("ints[0] at %lu is %lu\n", &ints[0], ints[0]);
  printf("ints[1] at %lu is %lu\n", &ints[1], ints[1]);
  // todo: get value from manual pointer like *(&ints+8)
  printf("ints[2] at %lu is %lu\n", &ints[1]+4, ints[2]);

  // try to access an index out of range
  printf("ints[3] is %lu\n", ints[3]);
  printf("ints[4] is %lu\n", ints[4]);

  // save address of the third as seperate variable
  int* third = &ints[3];
  printf("%d\n", *third);
  return 0;
}
