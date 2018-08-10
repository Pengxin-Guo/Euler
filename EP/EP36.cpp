/*************************************************************************
	> File Name: EP36.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月31日 星期二 15时14分59秒
 ************************************************************************/

#include <stdio.h>
#define MAX_N 1000000

int is_decimal(int n, int d) {
    int temp = n, num = 0;
    while (temp) {
        num = d * num + (temp % d);
        temp /= d;
    }
    return num == n;
}

int main() {
    int ans = 0;
    for (int i = 1; i < MAX_N; i++) {
        if (!is_decimal(i, 2)) continue;
        if (!is_decimal(i, 10)) continue;
        ans += i;
    }
    printf("%d\n", ans);
    return 0;
}
