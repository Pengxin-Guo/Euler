/*************************************************************************
	> File Name: EP39.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月01日 星期三 14时06分02秒
 ************************************************************************/

#include <stdio.h>

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int get_num(int p) {
    int temp = 0;
    for (int i = 2; i < 32; i++) {
        for (int j = i + 1; j < 32; j++) {
            if (gcd(i, j) != 1) continue;
            int a = 2 * i * j;
            int b = j * j - i * i;
            int c = j * j + i * i;
            if (p % (a + b + c) == 0) {
                temp += 1;
            }
        }
    }
    return temp;
}

int main() {
    int ans, num = 0;
    for (int p = 12; p <= 1000; p++) {
        if (num < get_num(p)) {
            num = get_num(p);
            ans = p;
        }
    }
    printf("%d\n", ans);
    return 0;
}
