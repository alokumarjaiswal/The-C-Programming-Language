#include <stdio.h>

int power(int, int);

/* Arguments - Call by Value
    In C, all function arguments are passed "by value".
    This means that the called function is given the values
    of its arguments in temporary variables rather than the originals.
    In "call by reference" languages, the called routine has access to
    the original argument, not a local copy.
    The main distinction is that in C the called function cannot directly
    alter a variable in the calling function; it can only alter its private,
    temporary copy.
    Call by value is an asset, however, not a liability.
*/

int main() {
  for (int i = 0; i < 10; ++i) {
    printf("%d %d %d\n", i, power(2, i), power(-3, i));
  }
}

// power: raise base to n-th power; n >= 0; version 2
int power(int base, int power) {
  int p;

  for (p = 1; power > 0; --power) {
    p *= base;
  }

  return p;
}