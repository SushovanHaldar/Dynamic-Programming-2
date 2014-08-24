#include <stdio.h>

/*
The address of j and p are the same. So C does not create copy of address
*/

void f(int *j) {
  (*j)++;
}

int main() {
  int i = 20;
  int *p = &i;
  f(p);
  printf("i = %d\n", i);

  return 0;
}