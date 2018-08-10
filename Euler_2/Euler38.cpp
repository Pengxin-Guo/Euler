/*************************************************************************
	> File Name: Euler38.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月27日 星期五 15时38分57秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>

int digit(int n) {
    return floor(log10(n)) + 1;
}

int is_valid(int x) {
    int ans_temp = 0, p, num[10] = {0};
    int n = 0, temp_digit = 0;
    do {
        n += 1;
        p = x * n;
        while (p) {
            if (p % 10 == 0) return 0;
            if (num[p % 10]) return 0;
            num[p % 10] = 1;
            temp_digit += 1;
            p /= 10;
        }
        ans_temp = ans_temp * (int)pow(10, digit(x * n)) + x * n;
    } while (temp_digit < 9);
    return ans_temp;
}

int main() {
    int ans = 0;
    for (int i = 1; i < 10000; i++) {
        if (!is_valid(i)) continue;
        if (ans < is_valid(i)) {
            ans = is_valid(i);
        }
        printf("%d %d\n",i, is_valid(i));
    }
    printf("%d\n", ans);
    return 0;
}
