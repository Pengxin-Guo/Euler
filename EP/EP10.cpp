/*************************************************************************
	> File Name: EP10.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月31日 星期二 15时48分26秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#define MAX_N 2000000

int prime[MAX_N + 5] = {0};

int main() {
    int64_t ans = 0;
    for (int i = 2; i < MAX_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            ans += i;
        }
        for (int j = 1; i * prime[j] <= MAX_N && j <= prime[0]; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    printf("%" PRId64 "\n", ans);
    return 0;
}
