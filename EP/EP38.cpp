/*************************************************************************
	> File Name: EP38.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年08月01日 星期三 15时28分36秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#include <inttypes.h>

int digit(int n) {
    return floor(log10(n)) + 1;
}

int64_t is_valid(int a) {
    int64_t temp = 0;
    int n = 1;
    int num[10] = {0};
    while(digit(temp) < 9) {
        int x = a * n;
        temp = temp * pow(10, digit(a * n)) + a * n;
        while (x) {
            if (x % 10 == 0) return 0;
            if (num[x % 10]) return 0;
            num[x % 10] = 1;
            x /= 10;
        }
        n++;
    }
    return temp;
}

int main() {
    int64_t ans = 0;
    for (int i = 1; i < 10000; i++) {
        int64_t temp = is_valid(i);
        if (ans < temp) {
            ans = temp;
        }
    }
    printf("%d\n", ans);
    return 0;
}
