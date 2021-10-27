

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned long long int getExp(unsigned long long int * N, unsigned long long int d);

int main( void ) {
    unsigned long long int number = 0;

    printf("%s", "Please enter the number to be factored: ");
    scanf("%llu", &number);

    printf("%llu = ", number);
    for( unsigned long long int i=2; i<=sqrt(number); i++) {
        if( number % i == 0 ) {
            unsigned long long int exp = getExp(&number, i);
            if(exp>1) {            
                printf("(%llu^%llu) ", i, exp);
            } else {
                printf("(%llu) ", i);
            }        
        }
    }
    if(number != 1) {
        printf("(%llu)\n", number);
    } else {
        puts("");
    }
}

unsigned long long int getExp(unsigned long long int * N, unsigned long long int d) {
    unsigned long long int exp = 0;
    unsigned long long int remainder = 0;
    while (remainder == 0 ) {
        remainder = *N % d;
        if(remainder == 0) {
            *N = *N / d;
            exp++;
        }
    }
    return exp;
}


