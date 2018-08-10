/*************************************************************************
	> File Name: EP4.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月31日 星期二 14时43分31秒
 ************************************************************************/

#include <stdio.h>

int is_palindromic(int n) {
    int temp = n, num = 0;
    while (temp) {
        num = num * 10 + temp % 10;
        temp /= 10;
    }
    return num == n;
}

int main() {
    int ans = 0;
    for (int i = 999; i; i--) {
        for (int j = 999; j; j--) {
            if (!is_palindromic(i * j)) continue;
            if (ans < i * j) ans = i * j;
        }
    }
    printf("%d\n", ans);
    return 0;
}
