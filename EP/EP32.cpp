/*************************************************************************
	> File Name: EP32.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月01日 星期三 14时40分58秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#define MAX_N 100000

int nums[MAX_N + 5] = {0};

int digit(int x) {
    return floor(log10(x)) + 1;
}

int is_valid(int a, int *num) {
    while (a) {
        if (a % 10 == 0) return 0;
        if (num[a % 10]) return 0;
        num[a % 10] = 1;
        a /= 10;
    }
    return 1;
}

int is_pandigital(int a, int b, int c) {
    int num[10] = {0};
    if (!is_valid(a, num)) return 0;
    if (!is_valid(b, num)) return 0;
    if (!is_valid(c, num)) return 0;
    return 1;
}

int main() {
    int ans = 0;
    for (int a = 2; 2 * digit(a) + digit(a * a) <= 9; a++) {
        for (int b = a + 1; digit(a) + digit(b) + digit(a * b) <= 9; b++) {
            if (digit(a) + digit(b) + digit(a * b) < 9) continue;
            if (is_pandigital(a, b, a * b)) {
                printf("%d *  %d = %d\n", a, b, a * b);
                ans += (a * b) * (1 - nums[a * b]);
                nums[a * b] = 1;
            }
        }
    }
    printf("%d\n", ans);
}
