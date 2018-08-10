/*************************************************************************
	> File Name: Euler32.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月27日 星期五 14时29分26秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#define MAX_N 10000

int valid[MAX_N] = {0};

int digit(int x) {
    return floor(log10(x)) + 1;
}

int is_digit(int a, int *num) {
    while (a) {
        if (a % 10 == 0) return 0;
        if (num[a % 10]) return 0;
        num[a % 10] = 1;
        a /= 10;
    }
    return 1;
}

int is_valid(int a, int b, int c) {
    int num[10] = {0};
    if (!is_digit(a, num)) return 0;
    if (!is_digit(b, num)) return 0;
    if (!is_digit(c, num)) return 0;
    return 1;
}

int main() {
    int ans = 0;
    for (int a = 2; 2 * digit(a) + digit(a * a) <= 9; a++) {
        for (int b = a + 1; digit(a) + digit(b) + digit(a * b) <= 9; b++) {
            if (digit(a) + digit(b) + digit(a * b) < 9) continue;
            if (!is_valid(a, b, a * b)) continue;
            ans += a * b * (1 - valid[a * b]);
            valid[a * b] = 1;
            printf("%d * %d = %d\n",a, b, a * b);
        }
    }
    printf("%d\n",ans);
    return 0;
}
