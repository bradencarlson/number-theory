// computes all of the prime numbers less than or equal to 
// a given number N.
//
#include <stdio.h>
#include <math.h>

int main( void ) {

    // takes in two integers from standard input.  
	int N1 = 0;
    int N2 = 0;
	printf("%s", "Please enter the first number\n(enter two for all numbers beneath the second number): ");
    scanf("%d", &N1);
    printf("%s", "Please enter the second number: ");	
    scanf("%d", &N2);
    
    // validates that the numbers are both positive.
    if ( N1 <= 0 || N2 <= 0 ) {
        printf("The numbers used cannot be negative.\n");
        return 1;
    }
	unsigned int count = 0;
	for( int i = N1 ; i <= N2 ; i++) {
		_Bool prime = 1;
		for( int j = 2 ; j <= sqrt(N2) ; j++) {
			if (i % j == 0 && i/j != 1 ) {
				prime = 0;
			}
		} // end for loop	
		if ( prime == 1 ) {
			printf("%d ", i);
			count++;
			if ( count % 15 == 0 ) {
				puts("");
			}
		} // end if
	} // end for loop
	puts("");
    if (N1==2) {
        printf("Number of primes under %d: %d\n", N2, count);
    } else {
	    printf("Number of primes between %d and %d: %d\n", N1, N2, count);
    }
} // end main
