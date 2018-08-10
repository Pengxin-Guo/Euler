/*************************************************************************
	> File Name: Euler47.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月31日 星期二 21时37分20秒
 ************************************************************************/

#include <stdio.h>
#define MAX_N 1000000

int prime[MAX_N + 5] = {0};

void init() {
    for (int i = 2; i < MAX_N; i++) {
        if (prime[i]) continue;
        for (int j = i; j <= MAX_N; j += i) {
            prime[j] += 1;
        }
    }
}

int main() {
    init();
    int ans = 0;
    for (int i = 1; i; i++) {
        int flag = 1;
        for (int j = 0; j < 4 && flag; j++) {
            if (prime[i + j] != 4) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            ans = i;
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}
