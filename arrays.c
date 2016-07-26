int main(int argc, char const *argv[]) {
  int ints[2];
  ints[0] = 5;
  ints[1] = 12;

  // length of the array is the total size divided through
  // the size of one element
  printf("%d\n", sizeof(ints)/sizeof(int));
  return 0;
}
