/*************************************************************************
	> File Name: Euler10.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月25日 星期三 18时59分44秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#define MAX_N 2000000
int prime[MAX_N + 5] = {0};

int main() {
    for (int i = 2; i < MAX_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
        } 
        for (int j = 1; j <= prime[0]; j++) {
            if(i * prime[j] > MAX_N) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    int64_t ans = 0;
    for (int i = 1; i <= prime[0]; i++) {
        ans += prime[i];
    }
    printf("%" PRId64 "\n",ans);
    return 0;
}
