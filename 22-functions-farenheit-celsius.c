#include <stdio.h>

double temp_converter(double);

/* Rewrite the temperature conversion program of Section 1.2
  to use a function for conversion.
*/

int main() {
  int i;

  for (i = 0; i <= 300; i += 20) {
    printf("%3d %6.1f\n", i, temp_converter(i));
  }

  return 0;
}

double temp_converter(double farenheit) {
  double celsius;

  celsius = (5.0 / 9.0) * (farenheit - 32.0);

  return celsius;
}