// program that implements Eulers totient function

// Braden Carlson
// 10/16/2021

#include <stdio.h>
#include <stdlib.h>

unsigned long long int gcd(unsigned long long int a, unsigned long long int b);

int main( void ) {
    unsigned long long int n = 0;
    unsigned long long int count = 0;

    printf("%s", "Enter the number: ");
    scanf("%llu", &n);    

    for(int i = 1;i<=n;i++) {
        if(gcd(i,n) ==1 ) {
            count++;
        }
    }
    printf("Euler's totient function of %llu: %llu\n", n, count);
}

unsigned long long int gcd(unsigned long long int a, unsigned long long int b) {
    unsigned long long int q = 0;
    unsigned long long int r = 1;
    unsigned long long int temp = 0;

    if (a < b) {
        temp = a;
        a = b;
        b = temp;
    }

    while (r!=0) {
        q = a / b;
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
