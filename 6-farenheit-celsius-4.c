#include <stdio.h>

/* Symbolic Constants
    #define NAME replacement_text
    The 'replacement_text' is not limited to numbers.
    No semicolons are required at the end of a '#define' line.
*/

#define LOWER 0
#define UPPER 300
#define STEP 20

int main() {
  for (int fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP) {
    printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
  }
}