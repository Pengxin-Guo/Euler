/*************************************************************************
	> File Name: EP11.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月31日 星期二 15时53分57秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#define MAX_N 10000

int prime[MAX_N + 5] = {0};
int dnum[MAX_N + 5] = {0};
int mnum[MAX_N + 5] = {0};

void init() {
    for (int i = 2; i <= MAX_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            dnum[i] = i + 1;
            mnum[i] = 1;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] <= MAX_N; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                mnum[i * prime[j]] = mnum[i] + 1;
                dnum[i * prime[j]] = dnum[i] * (1 - (int)pow(prime[j], mnum[i] + 2)) / (1 - (int)pow(prime[j], mnum[i] + 1));
                break;
            }
            dnum[i * prime[j]] = dnum[i] * dnum[prime[j]];
            mnum[i * prime[j]] = 1;
        }
    }
}

int main() {
    init();
    int ans = 0;
    for (int a = 2; a <= MAX_N; a++) {
        int b = dnum[a] - a;
        if (b > MAX_N) continue;
        if (a == b) continue;
        if (a != (dnum[b] - b)) continue;
        ans += a;
    }
    printf("%d\n", dnum[121]);
    printf("%d %d\n", dnum[220] - 220, dnum[284] - 284);
    printf("%d\n", ans);
    return 0;
}

