// program that can print out all the divisors of a given number and 
// counts the number of divisors of the number, as well as
// the sum of the divisors of the number, and 
// prints the result to the screen.

#include <stdio.h>
#include <stdlib.h>

int main( void ) {
    unsigned long long int n = 12;
    unsigned long int count = 1;
    unsigned long long int sum = 0;
    int answer = 0;    
    
    // get number from the user
    printf("%s", "Please enter the number: ");
    scanf("%llu", &n);

    // determine whether or not to print each divisor to the screen
    printf("%s", "Would you like to have each divisor printed out to the screen? (0/1)  ");
    scanf("%d", &answer);
    
    _Bool print = 0;
    if( answer == 1) {
        print = 1;
    }

    // go through and find all of the divisors and count them
    // printing them to the screen as needed
    unsigned int newline = 0;
    for(unsigned long int i = 1; i< n/2+1 ; i++) {
        if( n % i == 0 ) {
            sum += i;
            count++;
            newline++;
            if(print) {
                printf("%lu ", i);
            }
            if (print && newline %20 == 0) {
                puts("");
            }
        }
    }

    // print out the number itself
    sum += n;
    if(print) {
        printf("%llu ", n);
    }
    puts("");

    // print the results 
    printf("The total number of divisors of %llu is: %lu\n", n, count);
    printf("The sum of the divisors is: %llu\n", sum);
}
