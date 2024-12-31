#include <stdio.h>

/* print Farenheit-Celsius table
    for fahr = 0, 20, ..., 300; integer version
    printf("format_string", argument1, argument2, ...)

    format_string: %[minimum_width][type_specifier]
    %d specifies an integer argument, examples: %d, %3d, %6d
*/

int main() {
  int fahr, celsius;
  int lower, upper, step;

  lower = 0;   // lower limit of temperature table
  upper = 300; // upper limit
  step = 20;   // step size

  fahr = lower;
  while (fahr <= upper) {
    celsius = 5 * (fahr - 32) / 9;
    printf("%3d %6d\n", fahr, celsius);
    fahr = fahr + step;
  }
}