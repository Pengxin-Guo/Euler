/*************************************************************************
	> File Name: Euler20.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月30日 星期一 15时11分34秒
 ************************************************************************/

#include <stdio.h>
#define MAX_N 10000

int num[MAX_N + 5] = {1, 1};

int sum_digit(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= num[0]; j++) {
            num[j] *= i;
        }
        for (int j = 1; j <= num[0]; j++) {
            if (num[j] < 10) continue;
            num[j + 1] += num[j] / 10;
            num[j] = num[j] % 10;
            num[0] += (j == num[0]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= num[0]; i++) {
        ans += num[i];
    }
    return ans;
}

int main() {
    int n = 100;
    printf("%d\n", sum_digit(n));
    return 0;
}
