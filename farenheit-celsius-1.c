#include <stdio.h>

/* print Farenheit-Celsius table
    for fahr = 0, 20, ..., 300; floating-point version.

    'int' is converted to 'float' before the operation is done.

    printf("%[min_width.no_of_digits_after_decimal]f", argument1, argument2,
   ...) For example, %.2f enforces not restrain on width but tells to print 2
   digits after decimal.
*/

int main() {
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  while (fahr <= upper) {
    celsius = (5.0 / 9.0) * (fahr - 32.0);
    printf("%3.0f %6.1f\n", fahr, celsius);
    fahr += step;
  }
}