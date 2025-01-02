#include <stdio.h>

/* count digits, white space, others
    Arrays
    Array subscripts always start at zero in C.

    This particular program relies on the properties of the
    character representation of the digits.
    This approach assumes that:
        1. The character codes for '0' to '9' are consecutive.
        2. The difference between the ASCII value of a digit and
            zero gives its numeric value.
    These properties are guaranteed by standards like ASCII.
    Without these guarantees, c - '0' might not work as intended.
    For example, if 'c' is a digit character '3' with ASCII value 51.
    The program subtracts '0', ASCII value 48 from 'c',
        51 - 48 = 3
    This gives the numeric value 3.
    '0' → 48, '1' → 49, '2' → 50, ..., '9' → 57

    By definition, 'chars' are just small integers.
*/

int main() {
  int c, i, nwhite, nother;
  int ndigit[10];

  nwhite = nother = 0;
  for (i = 0; i < 10; ++i) {
    ndigit[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    if (c >= '0' && c <= '9') {
      ++ndigit[c - '0'];
    } else if (c == ' ' || c == '\n' || c == '\t') {
      ++nwhite;
    } else {
      ++nother;
    }
  }

  printf("digits = ");
  for (i = 0; i < 10; ++i) {
    printf("%d", ndigit[i]);
  }
  printf(", white space = %d, other = %d\n", nwhite, nother);

  return 0;
}