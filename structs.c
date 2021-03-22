#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
int main(int argc, char const *argv[]) {
  	const int list[] = {0xFFFE00FC,1,1,1,555};
	typedef struct {
		uint8_t first;
		uint8_t second;
		uint8_t third;
		uint8_t fourth;
	} byt_t;
	printf("basics: \n");

	byt_t oa = {1,2};
	printf("deref struct: %d\n",oa.first);
	printf("same with arrow: %d\n",(&oa)->first);


	byt_t *ARR = ((byt_t *) &list);
	printf("first byte of first array element: %d\n",ARR->first);
	printf("second byte of first array element: %d\n",ARR->second);



	
	return 0;
}
