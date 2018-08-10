/*************************************************************************
	> File Name: Euler35.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月28日 星期六 10时05分42秒
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

int is_circular_prime(int x) {
    int temp = 10 * (x % (int)pow(10, digit(x) - 1)) + x / pow(10, digit(x) - 1);
    while (temp != x) {
        if (digit(temp) < digit(x)) return 0;
        if (is_prime[temp]) return 0;
        temp = (temp % (int)pow(10,digit(temp) - 1)) * 10 + temp / pow(10, digit(temp) - 1);
    }
    return 1;
}

int main() {
    init();
    int ans = prime[0];
    for (int i = 1; i <= prime[0]; i++) {
        if (is_circular_prime(prime[i])) continue;
        ans -= 1;
    }
    printf("%d\n",prime[0]);
    printf("%d\n",ans);
    return 0;
}
