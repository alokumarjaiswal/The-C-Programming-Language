#include <stdio.h>

/* Modify the temperature conversion program to print a heading above the table.
    Write a program to print the corresponding Celsius to Farenheit table.
*/

int main() {
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  printf("Conversion Table: Celsius to Farenheit\n");
  while (fahr <= upper) {
    celsius = (5.0 / 9.0) * (fahr - 32.0);
    printf("%6.1f %3.0f\n", celsius, fahr);
    fahr += step;
  }
}