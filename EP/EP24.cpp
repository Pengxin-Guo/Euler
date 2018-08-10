/*************************************************************************
	> File Name: EP24.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月01日 星期三 11时22分29秒
 ************************************************************************/

#include <stdio.h>

#define MAX_N 1000000

int dnum[10] = {0};
int jnum[10] = {0};

void init() {
    dnum[0] = jnum[0] = 1;
    for (int i = 1; i < 10; i++) {
        dnum[i] = 1; //dnum[i] = 1 代表第i个数字还没用
        jnum[i] = i * jnum[i - 1]; // junm[i] 存放的时第i个数字的阶乘
    }
    return ;
}

int function(int i, int k) {
    int ind = k / jnum[i] + 1, n = -1;
    while (ind > 0) {
        n += 1;
        ind -= dnum[n];
    }
    dnum[n] = 0;
    return n;
}

int main() {
    init();
    int k = MAX_N - 1;
    for (int i = 9; i >= 0; i--) {
        int num = function(i, k);
        printf("%d", num);
        k %= jnum[i];
    }
    printf("\n");
    return 0;
}
