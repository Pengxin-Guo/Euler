/*************************************************************************
	> File Name: EP50.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月06日 星期一 17时29分16秒
 ************************************************************************/

#include <stdio.h>
#define MAX_N 1000000

int prime[MAX_N + 5] = {0};
int is_prime[MAX_N + 5] = {0};
int sum[MAX_N + 5] = {0};

void init() {
    for (int i = 2; i < MAX_N; i++) {
        if (!is_prime[i]) {
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0] && i * prime[j] <= MAX_N; j++) {
            is_prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    for (int i = 1; i <= prime[0]; i++) {
        sum[i] = sum[i - 1] + prime[i];
    }
    return ;
}

int get_len(int n) {
    for (int i = n; i >= 1; i--) {
        if (sum[i] - sum[i - 1] > n) continue;
        for (int j = 0; j < i; j++) {
            if (sum[i] - sum[j] < n) break;
            if (sum[i] - sum[j] == n) return i - j;
        }
    }
}

int main() {
    init();
    int n, len = 0, ans;
    for (int n = 41; n < MAX_N; n++) {
        if (is_prime[n]) continue;
        int temp = get_len(n);
        if (len < temp) {
            len = temp;
            ans = n;
            printf("%d\n", ans);
        }
    }
    printf("%d\n", ans);
    return 0;
}
