/*************************************************************************
	> File Name: Euler7_3.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月24日 星期二 10时23分08秒
 ************************************************************************/

#include <stdio.h>
#define MAX_N 10000
int prime[MAX_N + 5] = {0};
//int is_prime[MAX_N + 5] = {0};

int main() {
    /*for (int M = 2; M <= MAX_N; M++) {
        if (!is_prime[M]) {
            prime[++prime[0]] = M;
        }
        for (int i = 1, j = prime[i]; i <= prime[0]; i++, j = prime[i]) {
            if (M * j > MAX_N) break;
            is_prime[M * j] = 1;
            if(M % j == 0) break;
        }
    }*/
    for (int i = 2; i <= MAX_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
        }
        for (int j = 1; prime[j] * i <= MAX_N && j <= prime[0]; j++) {
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }

    for (int i = 1; i <= prime[0]; i++) {
        printf("%d ",prime[i]);
    }
    printf("\n");
    return 0;
}
