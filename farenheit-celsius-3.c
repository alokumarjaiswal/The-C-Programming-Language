#include <stdio.h>

/* The 'for' statement is a loop, a generalization of the 'while'.
    Modify the temperature conversion program to print the table in reverse
   order, that is, from 300 degrees to 0.
*/

int main() {
  for (int fahr = 0; fahr <= 300; fahr += 20) {
    printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
  }
  for (int fahr = 300; fahr >= 0; fahr -= 20) {
    printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
  }
}