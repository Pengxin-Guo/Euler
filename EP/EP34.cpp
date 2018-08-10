/*************************************************************************
	> File Name: EP34.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月31日 星期二 15时06分05秒
 ************************************************************************/

#include <stdio.h>
#define MAX_N 2903040

int factorial(int n) {
    int t = 1;
    for (int i = 1; i <= n; i++) {
        t *= i;
    }
    return t;
}

int is_valid(int n) {
    int temp = n, num = 0;
    while (temp) {
        num += factorial(temp % 10);
        temp /= 10;
    }
    return num == n;
}

int main() {
    int ans = 0;
    for (int i = 3; i < MAX_N; i++) {
        if (!is_valid(i)) continue;
        ans += i;
    }
    printf("%d\n", ans);
}
