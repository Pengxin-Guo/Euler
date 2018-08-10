/*************************************************************************
	> File Name: EP49.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月05日 星期日 10时22分32秒
 ************************************************************************/

#include <stdio.h>
#define MAX_N 10000

int prime[MAX_N + 5] = {0};

void init() {
    for (int i = 2; i * i <= MAX_N; i++) {
        if (prime[i]) continue;
        for (int j = i * i; j <= MAX_N; j += i) {
            prime[j] = 1;
        }
    }
}

int is_valid(int i, int j, int k) {
    int num1[10] = {0}, num2[10] = {0}, num3[10] = {0};
    while (i) {
        num1[i % 10] += 1;
        i /= 10;
    }
    while (j) {
        num2[j % 10] += 1;
        j /= 10;
    }
    while (k) {
        num3[k % 10] += 1;
        k /= 10;
    }
    for (int i = 0; i < 10; i++) {
        if (num1[i] != num2[i]) return 0;
        if (num2[i] != num3[i]) return 0;
    }
    return 1;
}

int main() {
    init();
    for (int i = 1000; i <= MAX_N; i++) {
        if (prime[i]) continue;
        if (i == 1487) continue;
        for (int j = i + 1; j <= MAX_N; j++) {
            if (prime[j]) continue;
            for (int k = j + 1; k <= MAX_N; k++) {
                if (prime[k]) continue;
                if ((k - j) != (j - i)) continue;
                if (!is_valid(i, j, k)) continue;
                printf("%d%d%d\n", i, j, k);
                return 0;
            }
        }
    }
    return 0;
}
