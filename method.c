// Citation: max-min.c from module on arrays and functions for help with finding numbers with the most factors  
// Citation: scanf-example.c from "Reading data values with scanf" for help with implementing simple scanf based UI
// Citation: "http://www.thegeekstuff.com/2011/12/c-arrays/" for help unstanding how to implement arrays to this problem
// Citation: "http://www.programminglogic.com/the-sieve-of-eratosthenes-implemented-in-c/" referenced for help creating a skeleton holding the basic foundation of this program in regards to aspects that calculate the prime numbers
// Citation: "http://www.daniweb.com/software-development/c/threads/94637/printing-arrays" referenced for help with printing arrays recursively
// Citation: "http://www.tutorialspoint.com/cprogramming/c_nested_loops.htm" referenced for help with nested loop statements
// Citation: "http://www.cprogramming.com/tutorial/c/lesson2.html" for help with if statements
// Citation: Referred to my supplement problem #2 for help formatting the output print statements 


/*****************************************************************
 * Henry M. Walker                                               *
 * Box:  Science                                                 *
 * Supplemental Problem 1 for CSC 161                            *
 * Assignment for Friday, February 7                             *
 *****************************************************************/

/* ***************************************************************
 * Academic honesty certification:                               *
 *   Written/online sources used:                                *
 *     [include textbook(s),                                     *
 *       CSC 161 labs or readings;                               *
 *       complete citations for Web or other written sources]    *
 *     [write "none" if no sources used]                         *
 *   Help obtained                                               *
 *     [indicate names of instructor, class mentors              *
 *      or evening lab tutors, consulted                         *
 *      according to class policy]                               *
 *     [write "none" if none of these sources used]              *
 *   My signature below confirms that the above list of sources  *
 *   is complete AND that I have not talked to anyone else       *
 *   [e.g., CSC 161 students] about the solution to this problem *
 *                                                               *
 *   Signature:                                                  *
 *****************************************************************/


// Begin: "A Modified Sieve Method of Eratoshtenes

#include <stdio.h>


#define LIMIT 1500000 /*size of integers array*/
#define PRIMES 100000 /*size of primes array*/

// function for printing

int main ()
{
  int n = 10;
  int m = n-2;
  int numbers [LIMIT];
  int primes[PRIMES];
  int cross[PRIMES];
  int i;
  int j;

  /*fill the array with natural numbers*/
  for (i=0; i <= m; i++)
    {
      numbers[i]=i+2; // Initializing each element seperately
    }

  // sieve the non-primes
  for (i=0; i <= m; i++)
    {
      if (numbers[i] !=-1)
        {
          for (j = 2 * numbers[i]-2; j <= m; j += numbers[i])
            numbers[j]=-1;
        }
    }

  // Make new array for primes
  j = 0;
  for (i=0; i<=m && j < m ;i++)
    if (numbers[i]!=-1)
      primes[j++] = numbers[i];

  // Make new array for crossed out nums

  int crossed[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

  //print
  int l = 0;
  for (i=0; i<=j; printf("%2d:%d  ", numbers[i], cross[i]), i++)
    {
      if (l == 8)
        {
          printf("\n");
          l = 0;
        }
      else 
        {
          l++;
        }
    }

  printf ("\n");
  return 0;

}



/*
  int main()
  {
  int number; //range for Sieve method to be performed on

  printf("Use Sieve Method of Erastoshtenes to calculate prime numbers less than or equal to... \n");

  sleep (3);
  printf("Enter a number: \n");
  scanf("%lf", &number); //  supply address of int variable

    sieve (number);
  return 0;
  }
*/
