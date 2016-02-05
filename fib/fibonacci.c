/*=============================================================================
Author: vvall

This source file contains the implementation of Fibonacci series
==============================================================================*/
#include <stdio.h>
#include "fibonacci.h"

/* Defines used as function return types */
#define TRUE    1
#define FALSE   0

/*============================================================================
DESCRIPTION: This is a utility function that checks if a given input is
prime or not.

RETURN TYPE:
TRUE :  if the input is prime
FALSE : Otherwise
============================================================================ */
static int fibonacci_util_check_prime_number(int number)
{
  if (number <= 1)
  {
    return FALSE;
  }

  /* No need to look for a divisor till number.
     Looking for a divisor till square root of number suffices */
  for (int divisor = 2; (divisor * divisor) <= number; divisor++)
  {
    if (number % divisor == 0)
    {
      return FALSE;
    }
  }

  /* We didn't find a divisor, so it is prime */
  return TRUE;
}


/*============================================================================
DESCRIPTION: This is a utility function that checks if a given input is
divisible by the divisor.

RETURN TYPE:
TRUE :  if the input is divisible by the divisor
FALSE : Otherwise
============================================================================ */
static int fibonacci_util_check_divisible(int number, int divisor)
{
  /* Check for 0 or negative values */
  if (divisor <= 0)
  {
    return FALSE;
  }

  if (number % divisor == 0)
  {
    return TRUE;
  }

  return FALSE;
}


/*============================================================================
DESCRIPTION: This is a utility function that prints,
..."Buzz" when input is divisible by 3.
..."Fizz" when input is divisible by 5.
..."BuzzFizz" when input is prime.
...the value input otherwise.

RETURN TYPE:
None
============================================================================ */
static void fibonacci_util_print(int result)
{
  if (fibonacci_util_check_divisible(result, 3))
  {
    printf("Buzz\n");
  }
  else if (fibonacci_util_check_divisible(result, 5))
  {
    printf("Fizz\n");
  }
  else if (fibonacci_util_check_prime_number(result))
  {
    printf("BuzzFizz\n");
  }
  else
  {
    printf("%d\n", result);
  }
}


/*============================================================================
DESCRIPTION: This function generates the Fibonacci series for a given n

RETURN TYPE:
None
============================================================================ */
void fibonacci(int n)
{
  int first  = 0;
  int next   = 1;
  int result = 0;

  /* Check if n is negative */
  if (n < 0)
  {
    printf("Enter a non-negative integer...\n");
    return;
  }

  /* In case of 0 or 1 */
  if ((n == 0) || (n == 1))
  {
    result = n;

    /* print the result */
    fibonacci_util_print(result);
    return;
  }

  /* print the first two elements in the series */
  fibonacci_util_print(first);
  fibonacci_util_print(next);

  /* The iterative approach of fibonacci
  series has time complexity of O(n), which is
  much better than recursive approach */
  for (int i = 2; i <= n; i++)
  {
    result = first + next;

    /* print the result */
    fibonacci_util_print(result);

    first = next;
    next = result;
  }
}
