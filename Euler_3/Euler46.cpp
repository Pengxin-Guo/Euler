/*************************************************************************
	> File Name: Euler46.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月31日 星期二 21时26分44秒
 ************************************************************************/

#include <stdio.h>

int is_prime(int n) {
    int x = 2;
    while (x * x < n) {
        if (n % x == 0) return 1;
        x += 1;
    }
    return 0;
}

int main() {
    int ans = 0;
    for (int i = 33; i; i += 2) {
        if (is_prime(i) == 0) continue;
        int flag = 1;
        for (int j = 1; 2 * j * j < i && flag; j++) {
            if (is_prime(i - 2 * j * j) == 0) flag = 0;
        }
        if (flag) {
            ans = i;
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}
