/*************************************************************************
	> File Name: EP41.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月06日 星期一 16时25分52秒
 ************************************************************************/

#include <stdio.h>
#include <iostream>
#include <algorithm>
#define MAX_N 10000000
using namespace std;

int prime[MAX_N + 5] = {0};
int num[9] = {0};

void init() {
    for (int i = 2; i * i < MAX_N; i++) {
        if (prime[i]) continue;
        for (int j = i * i; j <= MAX_N; j += i) {
            prime[j] = 1;
        }
    }
}

int valid(int *num, int i) {
    int temp = 0;
    for (int j = 0; j < i; j++) {
        temp = temp * 10 + num[j];
    }
    if (prime[temp]) return 0;
    return temp;
}

int main() {
    init();
    int ans = 0;
    for (int i = 7; i > 3 && !ans; i--) {
        for (int j = 0; j < i; j++) {
            num[j] = i - j;
        }
        do {
            ans = valid(num, i);
        } while (!ans && prev_permutation(num, num + i));
    }
    printf("%d\n", ans);
    return 0;
}
