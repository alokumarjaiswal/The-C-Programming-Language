#include <stdio.h>

int power(int, int); // function prototype

/* A function provides a convenient way
    to encapsulate some computation.
    It is possible to ignore how a job is done;
    knowing what is done is sufficient.
    A single function cannot be split between files.
    A function definition has this form:
        return-type function-name(parameter declarations, if any)
        {
            declarations
            statements
        }
    The first line of 'power' itself,
        int power(int base, int n)
    declares the parameter types and names,
    and the type of the result that the function returns.
    We will generally use parameter(formal argument) for a variable named in
    the parenthesized list in a function definition,
    and argument(actual argument) for the value used in a call of the function.
    The value that 'power' computes is returned to 'main' by the 'return'
   statement. return expression; A function need not return a value.
*/

int main() {
  int i;

  for (i = 0; i < 10; ++i) {
    printf("%d %d %d\n", i, power(2, i), power(-3, i));
  }

  return 0;
}

// power: raise base to n-th power; n >= 0.
int power(int base, int power) {
  int i, p;

  p = 1;
  for (i = 0; i < power; ++i) {
    p *= base;
  }

  return p;
}