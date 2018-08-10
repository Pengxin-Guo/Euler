/*************************************************************************
	> File Name: Euler12.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月29日 星期日 11时18分11秒
 ************************************************************************/

#include <stdio.h>
#define MAX_N 100000

int prime[MAX_N + 5] = {0};
int dnum[MAX_N + 5] = {0}; //记录每个数字的因子个数
int mnum[MAX_N + 5] = {0}; //记录每个数字的最小因子的幂次

void init() {
    for (int i = 2; i < MAX_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            dnum[i] = 2;
            mnum[i] = 1;
        }
        for (int j = 1; i * prime[j] <= MAX_N && j <= prime[0]; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                dnum[i * prime[j]] = dnum[i] / (mnum[i] + 1) * (mnum[i] + 2);
                mnum[i * prime[j]] = mnum[i] + 1;
                break;
            }
            dnum[i * prime[j]] = dnum[i] * dnum[prime[j]];
            mnum[i * prime[j]] = 1;
        }
    }
    return ;
}

int factor_nums(int n) {
    if (n & 1) return dnum[n] * dnum[(n + 1) / 2];
    else return dnum[n / 2] * dnum[n + 1];
}

int main() {
    init();
    int n = 1;
    while (factor_nums(n) < 500) n++;
    printf("%d\n", n * (n + 1) / 2);
    return 0;
}
