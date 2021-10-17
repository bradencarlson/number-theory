// program that uses Fermat's method for factoring large numbers. 
// Note that this method is most successful when the number to be
// factored N=pq, where p and q are prime and relatively similar 
// in size.  

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int inArray(unsigned long long int a, unsigned long long int squares[], unsigned long long int start, unsigned long long int end);
_Bool linearSearch(unsigned long long int a, unsigned long long int array[], unsigned long long int size);

int main( void ) {
    unsigned long long int N = 0;
    unsigned long long int a = 0;
    unsigned long long int b = 0;

    printf("%s", "Enter the number to be factored: ");
    scanf("%llu", &N);
    
    unsigned long long int size = (unsigned long long int) ceil(sqrt(N));
    printf("%llu\n", size);

    unsigned long long int squares[size];
    for(unsigned long long int i = 0; i<size ; i++) {
        squares[i] = pow(i,2);
    }
    _Bool prime = 1;
    for(unsigned long long int i = 0; i<(N+1)/2 ; i++) {
        if ( linearSearch( pow(size+i,2)-N, squares, size) ) {
            a = size+i;
            b = sqrt(pow(size+i,2)-N);
            printf("%llu %llu\n",a,b);
            prime = 0;
            break;
        } 
    }
    if (prime) {
        printf("%llu is prime\n", N);
    } else { 
        printf("%llu = (%llu)(%llu)\n", N, a+b, a-b);
    }
}
/*
int inArray(unsigned long long int a, unsigned long long int array[], unsigned long long int start, unsigned long long int end) {
    if (start==end) {
        if(array[start] == a) {
            return 1;
        } else {
            return 0;
        }
    } else {
        unsigned long long int midpoint = start/2+end/2;
        if (array[midpoint] >= a) {
            return inArray(a, array, start, midpoint+1 );
        } else {
            return inArray(a, array, midpoint-1, end);
        }
    }
}
*/
_Bool linearSearch(unsigned long long int a, unsigned long long int array[], unsigned long long int size) {
    for(int i = 0; i<size; i++) {
        if(array[i]==a) {
            return 1;
        }
    }
    return 0;
}
