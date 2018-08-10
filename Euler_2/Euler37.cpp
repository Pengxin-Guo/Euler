/*************************************************************************
	> File Name: Euler37.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月28日 星期六 11时34分54秒
 ************************************************************************/


#include <stdio.h>
#include <math.h>
#define MAX_N 1000000

int prime[MAX_N + 5] = {0};
int is_prime[MAX_N + 5] = {0};

void init() {
    for (int i = 2; i <= MAX_N; i++) {
        if (!is_prime[i]) {
            prime[++prime[0]] = i;
        }
        for (int j = 1; prime[j] * i <= MAX_N && j <= prime[0]; j++) {
            is_prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    } 
}
int digit(int x) {
    return floor(log10(x)) + 1;
}

int is_primes(int x) {
    int temp = x % (int)pow(10,digit(x) - 1);
    while (temp > 10) {
        if (is_prime[temp]) return 0;
        temp = temp % (int)pow(10,digit(temp) - 1);
    }
    if (is_prime[temp]) return 0;


    temp = x / 10;
    while (temp > 10) {
        if (is_prime[temp]) return 0;
        temp /= 10;
    }
    if (is_prime[temp]) return 0;
    return 1;
}

int main() {
    init();
    is_prime[1] = 1;
    int ans = 0;
    for (int i = 5; i <= prime[0]; i++) {
        if (!is_primes(prime[i])) continue;
        printf("%d\n",prime[i]);
        ans += prime[i];
    }
    printf("%d\n",ans);
    return 0;
}
