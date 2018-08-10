/*************************************************************************
	> File Name: EP47.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月01日 星期三 14时31分31秒
 ************************************************************************/

#include <stdio.h>
#define MAX_N 50000000

int prime[MAX_N + 5] = {0};

void init() {
    for (int i = 2; i < MAX_N; i++) {
        if (prime[i]) continue;
        for (int j = i; j < MAX_N; j += i) {
            prime[j] += 1;
        }
    }
}

int main() {
    init();
    for (int i = 2; i; i++) {
        int flag = 1;
        for (int j = 0; j < 4 && flag; j++) {
            if (prime[i + j] != 4) flag = 0;
        }
        if (flag) {
            printf("%d\n", i);
            return 0;
        }
    }
    return 0;
}
