/*************************************************************************
	> File Name: EP35.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月01日 星期三 15时05分15秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#define MAX_N 1000000

int digit(int n) {
    return floor(log10(n)) + 1;
}

int is_prime(int x) {
    for (int n = 2; n * n <= x; n++) {
        if (x % n == 0) return 0;
    }
    return 1;
}

int is_valid(int x) {
    int n = digit(x);
    int temp = x / (int)pow(10, n - 1) + (x % (int)pow(10, n - 1)) * 10 ;
    while (temp != x) {
        if (!is_prime(temp)) return 0;
        temp = temp / (int)pow(10, n - 1) + (temp % (int)pow(10, n - 1)) * 10;
    }
    return 1;
}

int main() {
    int ans = 0;
    for (int i = 2; i < MAX_N; i++) {
        if (!is_prime(i)) continue;
        if (!is_valid(i)) continue;
        //printf("%d\n", i);
        ans += 1;
    }
    printf("%d\n", ans);
    return 0;
}
