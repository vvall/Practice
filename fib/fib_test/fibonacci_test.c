/*=============================================================================
Author: vvall

This source file contains the tests for fibonacci implementation
==============================================================================*/
#include <stdio.h>
#include "fibonacci.h"

int main()
{
  int n = 0;

  /* Get n from stdin */
  printf("Enter a number (n), to generate first 'n' elements in fibonacci series...\n");
  scanf_s("%d", &n);

  fibonacci(n);


  /* These are hardcoded tests */
  fibonacci(0);

  fibonacci(1);

  fibonacci(25);

  /* This just prints a message */
  fibonacci(-2);

  return 0;
}
